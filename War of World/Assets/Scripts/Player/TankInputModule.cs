using UnityEngine;
using UnityEngine.Networking;
using System;

namespace Tanks.TankControllers
{
	/// <summary>
	/// Tank input module - base class for all input systems
	/// </summary>
	[RequireComponent(typeof(TankShooting))]
	[RequireComponent(typeof(TankMovement))]
    public abstract class TankInputModule : MonoBehaviour
	{
		protected TankShooting  m_Shooting;
		protected TankMovement  m_Movement;


        protected bool          m_bJoystickInputR= false;
        protected bool          m_bJoystickInputL= false;
		protected int           m_GroundLayerMask;
		protected Plane         m_FloorPlane;

		/// <summary>
		/// Occurs when input method changed.
		/// </summary>
		public static event Action<bool> s_InputMethodChanged;

		protected virtual void Awake()
		{
			m_Shooting          = GetComponent<TankShooting>();
			m_Movement          = GetComponent<TankMovement>();
			m_FloorPlane        = new Plane(Vector3.up, 0);
			m_GroundLayerMask   = LayerMask.GetMask("Ground");
		}


        //On enable, restore our rigidbody's range of movement.
        void OnEnable()
        {

            EasyJoystick.On_JoystickMove      += OnJoystickMove;
            EasyJoystick.On_JoystickMoveStart += OnJoystickMoveStart;
            EasyJoystick.On_JoystickMoveEnd   += OnJoystickMoveEnd;
            EasyJoystick.On_JoystickTouchStart+= OnJoystickTouchStart;
            EasyJoystick.On_JoystickTouchUp   += OnJoystickTouchEnd;
        }


        protected virtual void OnDisable()
        {
            SetFireIsHeld(false);
            EasyJoystick.On_JoystickMove      -= OnJoystickMove;
            EasyJoystick.On_JoystickMoveStart -= OnJoystickMoveStart;
            EasyJoystick.On_JoystickMoveEnd   -= OnJoystickMoveEnd;
            EasyJoystick.On_JoystickTouchStart-= OnJoystickTouchStart;
            EasyJoystick.On_JoystickTouchUp   -= OnJoystickTouchEnd;
        }

		protected virtual void Update()
		{
			DoMovementInput();
			DoFiringInput();
		}


		protected abstract bool DoMovementInput();

		protected abstract bool DoFiringInput();

		protected void SetDesiredMovementDirection(Vector3 moveDir)
		{
			m_Movement.SetDesiredMovementDirection(moveDir);
		}


        protected void DisableMovement()
        {
            m_Movement.SetDefaults();
        }


		protected void SetDesiredFirePosition(Vector3 target)
		{
			m_Shooting.SetDesiredFirePosition(target);
		}


        protected void SetMovementTarget( Vector3 target )
        {
            m_Movement.SetTargetPosition(target);
        }


		public void SetFireIsHeld(bool fireHeld)
		{
			m_Shooting.SetFireIsHeld(fireHeld);
		}

		protected void OnInputMethodChanged(bool isTouch)
		{
			if (s_InputMethodChanged != null)
			{
				s_InputMethodChanged(isTouch);
			}
		}

        /// <summary>
        /// �ж��Ƿ�����ң�п���
        /// </summary>
        /// <returns></returns>
        protected bool IsJoystickMoving()
        {
            return (m_bJoystickInputL || m_bJoystickInputR);
        }


        private float fTouchAndUpTime = 0f;
        protected void OnJoystickTouchStart(MovingJoystick move)
        {
            if (move.joystickName == "Right_Joystick")
            {
                fTouchAndUpTime = Time.realtimeSinceStartup;
            }
        }

        protected void OnJoystickTouchEnd(MovingJoystick move)
        {
            if (move.joystickName == "Right_Joystick")
            {
                if( Time.realtimeSinceStartup - fTouchAndUpTime < 0.2f )
                {
                    SetFireIsHeld(true);
                }
            }

            else if (move.joystickName == "Left_Joystick")
            {
                m_Shooting.fireDirection.SetActive(false);
            }
        }
        /// <summary>
        /// �ƶ�ҡ�˿�ʼ
        /// </summary>
        protected void OnJoystickMoveStart( MovingJoystick move )
        {
            if( m_Shooting == null || m_Shooting.fireDirection == null )
                return;

            if (move.joystickName == "Right_Joystick")
            {
                m_bJoystickInputR = true;
                m_Shooting.fireDirection.SetActive(true);
            }

            else if (move.joystickName == "Left_Joystick")
            {
                m_bJoystickInputL = true;
                m_Shooting.fireDirection.SetActive(false);
            }
        }


        //�ƶ�ҡ�˽���
        protected void OnJoystickMoveEnd(MovingJoystick move)
        {
            if (move.joystickName == "Right_Joystick")
            {
                m_bJoystickInputR = false;
                m_Shooting.fireDirection.SetActive(false);
                SetFireIsHeld(false);
            }

            if (move.joystickName == "Left_Joystick")
            {
                m_bJoystickInputL = false;
                DisableMovement();
                SetDesiredMovementDirection(Vector3.zero);
            }
        }

        //�ƶ�ҡ����
        protected void OnJoystickMove(MovingJoystick move)
        {
            if (move.joystickName == "Left_Joystick" )
            {
                //��ȡҡ������ƫ�Ƶ�����
                m_bJoystickInputL = true;
                float x = move.joystickAxis.x;
                float y = move.joystickAxis.y;

                //���ý�ɫ�ĳ��򣨳���ǰ����+ҡ��ƫ������  
                if( !m_bJoystickInputR )
                    SetDesiredFirePosition(new Vector3(transform.position.x + x, transform.position.y, transform.position.z + y));
                
                Vector3 movedir = new Vector3(x, y, 0);
                if (movedir.sqrMagnitude > 0.01f)
                {
                    Vector3 worldUp = Camera.main.transform.TransformDirection(Vector3.up);
                    worldUp.y       = 0;
                    worldUp.Normalize();
                    Vector3 worldRight = Camera.main.transform.TransformDirection(Vector3.right);
                    worldRight.y    = 0;
                    worldRight.Normalize();

                    Vector3 worldDirection = worldUp * y + worldRight * x;
                    if (worldDirection.magnitude > 1)
                    {
                        worldDirection.Normalize();
                    }
                    SetDesiredMovementDirection(worldDirection);
                }
            }

            if (move.joystickName == "Right_Joystick" )
            {

                float x = move.joystickAxis.x;
                float y = move.joystickAxis.y;

                //���ý�ɫ�ĳ��򣨳���ǰ����+ҡ��ƫ������  
                SetDesiredFirePosition(new Vector3(transform.position.x + x, transform.position.y, transform.position.z + y));
                SetFireIsHeld(true);
            }
        }
	}
}