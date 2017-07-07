using System;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using Tanks.Data;
using Tanks.CameraControl;
using Tanks.Shells;
using Tanks.Explosions;
using Tanks.SinglePlayer;






namespace Tanks.TankControllers
{
    /// <summary>
    /// ���������ģʽ
    /// </summary>
	enum SHOOTINGMODE
    {
        Shoot_continued,        // �������
        Shoot_pressUp,          // �ͷ����
        Shoot_pulse,            // ����ʽ����
        Shoot_Rocket,           // �����
    };


    public class TankShooting : MonoBehaviour
	{
        public GameObject       gunobject;
        public GameObject       fireDirection;
        public GameObject       gunHead;

        int                     shootableMask;
        float                   Esplasetimer;
        float                   effectsDisplayTime = 0.2f;

        private SHOOTINGMODE    m_ShootMode = SHOOTINGMODE.Shoot_pulse;
        private bool            m_FireInput;
        public  float           m_curLookatDeg;
        private float           m_TurretHeading;
        private float           m_fOldEulerAngles = 0;


        /// <summary>
        /// Ԥ��Ŀ���ı���
        /// </summary>
        private Ray             m_shootRay = new Ray();
        private RaycastHit      m_shootHit;
        void Awake()
        {
            shootableMask   = LayerMask.GetMask("Shootable");
            fireDirection.SetActive(false);
            m_curLookatDeg  = transform.rotation.eulerAngles.y;
            m_fOldEulerAngles = m_curLookatDeg;
        }


        void Update()
        {
            Esplasetimer += Time.deltaTime;
            if (m_ShootMode == SHOOTINGMODE.Shoot_pulse)
            {
                if (m_FireInput && Esplasetimer >= 1.0f && Time.timeScale != 0)
                {
                    Shoot();
                }
            }
            else
            {
                if (m_FireInput && Esplasetimer >= 0.15f && Time.timeScale != 0)
                {
                    Shoot();
                }
            }
            SmoothFaceDirection();
        }

        /// ----------------------------------------------------------------------------------------------
        /// <summary>
        /// �ж��Ƿ���Թ���
        /// </summary>
        /// ----------------------------------------------------------------------------------------------
        public void BackShootingAngles( float fAngles )
        {
            m_fOldEulerAngles = fAngles;
            m_curLookatDeg    = fAngles;
            m_TurretHeading   = fAngles;
        }

        /// ----------------------------------------------------------------------------------------------
        /// <summary>
        /// �ж��Ƿ��ǳ������
        /// </summary>
        /// ----------------------------------------------------------------------------------------------
        public bool IsShootContinued()
        {
            return m_ShootMode == SHOOTINGMODE.Shoot_continued;
        }

        /// ----------------------------------------------------------------------------------------------
        /// <summary>
        /// �ж��Ƿ���̧�����
        /// </summary>
        /// ----------------------------------------------------------------------------------------------
        public bool IsShootPressup()
        {
            return m_ShootMode == SHOOTINGMODE.Shoot_pressUp || m_ShootMode == SHOOTINGMODE.Shoot_pulse; 
        }

        /// ----------------------------------------------------------------------------------------------
        /// <summary>
        /// �ж��Ƿ���̧�����
        /// </summary>
        /// ----------------------------------------------------------------------------------------------
        public bool IsShootPulse()
        {
            return m_ShootMode == SHOOTINGMODE.Shoot_pulse;
        }

        /// ----------------------------------------------------------------------------------------------
        /// <summary>
        /// ƽ����ת����
        /// </summary>
        /// ----------------------------------------------------------------------------------------------
        void SmoothFaceDirection( )
        {
            if (Mathf.Abs(m_TurretHeading - m_curLookatDeg) < 0.001f)
                return;

            m_curLookatDeg     = Mathf.LerpAngle(m_curLookatDeg, m_TurretHeading, Time.deltaTime * 10);
            transform.rotation = Quaternion.Euler(new Vector3(transform.rotation.eulerAngles.x, m_curLookatDeg, transform.rotation.eulerAngles.z));
        }


        /// ----------------------------------------------------------------------------------------------
        /// <summary>
        /// ����
        /// </summary>
        /// ----------------------------------------------------------------------------------------------
        void Shoot()
        {

            Esplasetimer = 0f;
            {
                m_shootRay.origin       = gunobject.transform.position;
                m_shootRay.direction    = transform.forward;
                if( Physics.Raycast( m_shootRay, out m_shootHit, 100, shootableMask ) )
                {

                }
            }

            if (m_ShootMode == SHOOTINGMODE.Shoot_continued)
            {
                FireEffect1();
            }
            if (m_ShootMode == SHOOTINGMODE.Shoot_pressUp)
            {
                FireEffect2();
                m_FireInput = false;
            }
            if(m_ShootMode == SHOOTINGMODE.Shoot_pulse)
            {
                FireEffect3();
                m_FireInput = false;
            }
            if( m_ShootMode == SHOOTINGMODE.Shoot_Rocket )
            {
                FireEffect4();
                m_FireInput = false;
            }
        }

        public void SetFireIsHeld(bool fireHeld)
        {
            m_FireInput = fireHeld;
        }

        /// ------------------------------------------------------------------------------------------
        /// <summary>
        /// ����ǹ�ڵĳ��򣬼���ɫ������
        /// </summary>
        /// ------------------------------------------------------------------------------------------
        public void SetDesiredFirePosition( float fAngle )
        {
            m_TurretHeading = fAngle + m_fOldEulerAngles;
        }

        /// ------------------------------------------------------------------------------------------
        /// <summary>
        /// ������ʱ����ôʵ�ָ����ӵ����ӵ�1�����Ч��
        /// </summary>
        /// ------------------------------------------------------------------------------------------
        private void FireEffect1()
        {
            Vector3 position     = gunHead.transform.position;
            Vector3 shotVector   = gunHead.transform.forward;

            GameObject shellInstance = null;
            if (ExplosionManager.s_InstanceExists)
            {
                shellInstance = ExplosionManager.s_Instance.CreateVisualBullet(position, shotVector, 0, BulletClass.FiringExplosion);
            }

            shellInstance.SetActive(true);
            shellInstance.transform.localScale = Vector3.one;
            shellInstance.transform.position = position;
            shellInstance.transform.forward = shotVector;

            // �������������ײ
            Physics.IgnoreCollision(shellInstance.GetComponent<Collider>(), GetComponentInChildren<Collider>(), true);
            InstantBullet shell = shellInstance.GetComponent<InstantBullet>();
            shell.Setup(0, null, 100);
            shell.transform.rotation = Quaternion.Euler(new Vector3(transform.rotation.eulerAngles.x, m_curLookatDeg, transform.rotation.eulerAngles.z));
        }

        /// ------------------------------------------------------------------------------------------
        /// <summary>
        /// ������ʱ����ôʵ�ָ����ӵ����ӵ�2�����Ч��
        /// </summary>
        /// ------------------------------------------------------------------------------------------
        private void FireEffect2()
        {

            Vector3 position = gunobject.transform.position;
            Vector3 shotVector = transform.forward;

            int randSeed = UnityEngine.Random.Range(int.MinValue, int.MaxValue);
            GameObject shellInstance = null;
            if (ExplosionManager.s_InstanceExists)
            {
                shellInstance = ExplosionManager.s_Instance.CreateVisualBullet(position, shotVector, 0, BulletClass.ClusterExplosion );
            }

            shellInstance.SetActive(true);
            shellInstance.transform.localScale = Vector3.one;
            shellInstance.transform.position = position;
            shellInstance.transform.forward = shotVector;

            // �������������ײ
            Physics.IgnoreCollision(shellInstance.GetComponent<Collider>(), GetComponentInChildren<Collider>(), true);
            ScatteringBullet shell = shellInstance.GetComponent<ScatteringBullet>();
            shell.Setup(0, null, 100);
            shell.transform.rotation = Quaternion.Euler(new Vector3(transform.rotation.eulerAngles.x, m_curLookatDeg, transform.rotation.eulerAngles.z));
        }

        /// ------------------------------------------------------------------------------------------
        /// <summary>
        /// ������ʱ����ôʵ�ָ����ӵ����ӵ�2�����Ч��
        /// </summary>
        /// ------------------------------------------------------------------------------------------
        private void FireEffect3()
        {

            Vector3 position = gunobject.transform.position;
            Vector3 shotVector = transform.forward;

            int randSeed = UnityEngine.Random.Range(int.MinValue, int.MaxValue);
            GameObject shellInstance = null;
            if (ExplosionManager.s_InstanceExists)
            {
                shellInstance = ExplosionManager.s_Instance.CreateVisualBullet(position, shotVector, 0, BulletClass.PulseExplosion);
            }

            shellInstance.SetActive(true);
            shellInstance.transform.localScale = Vector3.one;
            shellInstance.transform.position = position;
            shellInstance.transform.forward = shotVector;

            // �������������ײ
            Physics.IgnoreCollision(shellInstance.GetComponent<Collider>(), GetComponentInChildren<Collider>(), true);
            PulseBullet shell = shellInstance.GetComponent<PulseBullet>();
            shell.Setup(0, null, 100);
            shell.transform.rotation = Quaternion.Euler(new Vector3(transform.rotation.eulerAngles.x, m_curLookatDeg, transform.rotation.eulerAngles.z));
        }

        /// ------------------------------------------------------------------------------------------
        /// <summary>
        /// ������ʱ����ôʵ�ָ����ӵ����ӵ�2�����Ч��
        /// </summary>
        /// ------------------------------------------------------------------------------------------
        private void FireEffect4()
        {

            Vector3 position = gunobject.transform.position;
            Vector3 shotVector = transform.forward;

            int randSeed = UnityEngine.Random.Range(int.MinValue, int.MaxValue);
            GameObject shellInstance = null;
            if (ExplosionManager.s_InstanceExists)
            {
                shellInstance = ExplosionManager.s_Instance.CreateVisualBullet(position, shotVector, 0, BulletClass.RocketExplosion);
            }

            shellInstance.SetActive(true);
            shellInstance.transform.localScale = Vector3.one;
            shellInstance.transform.position = position;
            shellInstance.transform.forward = shotVector;

            // �������������ײ
            Physics.IgnoreCollision(shellInstance.GetComponent<Collider>(), GetComponentInChildren<Collider>(), true);
            Shell shell = shellInstance.GetComponent<Shell>();
            shell.Setup(0, null, 100);
            shell.transform.rotation = Quaternion.Euler(new Vector3(transform.rotation.eulerAngles.x, m_curLookatDeg, transform.rotation.eulerAngles.z));
        }
	}
}