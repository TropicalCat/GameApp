using UnityEngine;
using System.Collections;
using System;
using System.Xml;
using System.Collections.Generic;



public class CityMainFrame : GUIFrame 
{

	
	UnityEngine.GameObject			m_BasePanel;
	UnityEngine.GameObject			m_BasePane2;
	UnityEngine.GameObject			m_btnRole;
	UnityEngine.GameObject			m_btnBag;
	UnityEngine.GameObject			m_btnEquip;
	UnityEngine.GameObject			m_btnQuest;
	UnityEngine.GameObject			m_btnMatrix;		

	UnityEngine.GameObject			m_btnSwitch;		
	UnityEngine.GameObject			m_btnEveryone;		

	public Transform 				m_Chapter;	
	public Transform 				m_QuestTalkFrame;
	public Transform				m_CharacterBag;	
	public Transform				m_MainQuest;
	public Transform				m_WelComeFrame;

    private bool                    m_IsShowCharacterFrame = false;
    public override bool ReloadUI()
    {
        base.ReloadUI();

		
		m_BasePanel		= UnityEngine.GameObject.Find("Bottom");
		m_BasePane2		= UnityEngine.GameObject.Find("BottomRight");
		m_btnSwitch 	= UnityEngine.GameObject.Find("Switch");
		m_btnRole	  	= UnityEngine.GameObject.Find("btn01");
		m_btnBag	  	= UnityEngine.GameObject.Find("btn02");
		m_btnEquip	  	= UnityEngine.GameObject.Find("btn03");
		m_btnQuest	  	= UnityEngine.GameObject.Find("btn04");
		m_btnMatrix	  	= UnityEngine.GameObject.Find("btn05");

		m_btnEveryone	= UnityEngine.GameObject.Find("btn06");

        UIEventListener.Get(m_btnRole).onClick      = onBaseBtnClick;
        UIEventListener.Get(m_btnBag).onClick       = onBaseBtnClick;
        UIEventListener.Get(m_btnEquip).onClick     = onBaseBtnClick;
        UIEventListener.Get(m_btnQuest).onClick     = onBaseBtnClick;
        UIEventListener.Get(m_btnMatrix).onClick    = onBaseBtnClick;
        UIEventListener.Get( m_btnEveryone ).onPress = onFuntionClick;  
		UIEventListener.Get( m_btnSwitch ).onClick  = onSwitchClick; 
		
        return true;
	}
	
	// Use this for initialization
	void Start () 
	{
		if (CNGUISys.Inst != null) 
		{
			
			CNGUISys.Inst.m_CharacterUI		= m_CharacterBag;
			
		}

        CHeroEntity pHero = CFightTeamMgr.Instance.m_pBattleHero;
		if( pHero != null && m_WelComeFrame != null )
		{
			if( pHero.m_nLevel == 1 )
			{
				m_WelComeFrame.gameObject.SetActive( true );
			}
		}
	}
	
	
	//---------------------------------------------------------------------------------
	// 基础按钮单机事件
	//---------------------------------------------------------------------------------
	void onBaseBtnClick( UnityEngine.GameObject item )
	{

		if (item == m_btnRole ) 
		{
            if (!m_IsShowCharacterFrame)
            {
                m_IsShowCharacterFrame = true;
                GameUIManager.Instance().ShowFrame(GUIDefine.UIF_CHARACTERFRAME);
                GameUIManager.Instance().ShowFrame(GUIDefine.UIF_BAGFRAME);
            }
            else
            {
                m_IsShowCharacterFrame = false;
                GameUIManager.Instance().HideFrame(GUIDefine.UIF_CHARACTERFRAME);
                GameUIManager.Instance().HideFrame(GUIDefine.UIF_BAGFRAME);
            }
		}

		if( item == m_btnQuest && m_MainQuest != null )
		{
			if( m_MainQuest.gameObject.activeSelf )
			{
				OnShowBasePanel( true );
				m_MainQuest.gameObject.SetActive( false );
			}
			else
			{
				OnShowBasePanel( false );
				m_MainQuest.gameObject.SetActive( true );
			}
		}

		if( m_btnMatrix == item && m_Chapter != null )
		{
			if( m_Chapter.gameObject.activeSelf )
			{
				m_Chapter.gameObject.SetActive( false );
			}
			else
			{
				m_Chapter.gameObject.SetActive( true );
			}
		}
	}


	private void OnShowBasePanel( bool bShow )
	{
		if( !bShow )
		{
			m_BasePanel.SetActive( false );
			m_BasePane2.SetActive( false );
		}
		else
		{
			m_BasePanel.SetActive( true );
			m_BasePane2.SetActive( true );
		}
	}


	//---------------------------------------------------------------------------------
	// 特殊功能按钮单机事件
	//---------------------------------------------------------------------------------
	void onFuntionClick( UnityEngine.GameObject item, bool state )
	{
		
		
	}

	//---------------------------------------------------------------------------------
	// 进入关卡选择界面
	//---------------------------------------------------------------------------------
	void onFightClick( UnityEngine.GameObject item )
	{

	}


	void onSwitchClick( UnityEngine.GameObject item )
	{
			
	}

	public IEnumerator CloseMainQuestEvent( )
	{
		if( m_MainQuest != null )
		{
			OnShowBasePanel( true );
			m_MainQuest.gameObject.SetActive( false );
		}
		yield return new WaitForSeconds(0.1f);
	}

    /// ---------------------------------------------------------------------------
    /// <summary>
    /// 释放本UIFrame 所用到的资源
    /// </summary>
    /// --------------------------------------------------------------------------
    public override void Destroy()
    {
        m_BasePanel     = null;
        m_BasePane2     = null;
        m_btnSwitch     = null;
        m_btnRole       = null;
        m_btnBag        = null;
        m_btnEquip      = null;
        m_btnQuest      = null;
        m_btnMatrix     = null;
        m_btnEveryone   = null;
        base.Destroy();
    }
}
 