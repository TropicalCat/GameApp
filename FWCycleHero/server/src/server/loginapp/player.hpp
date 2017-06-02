/*
----------------------------------------------------------------------------
		file name : player.hpp
		desc	  : ��¼����������ĵ�¼���˺�
		author    : LJP

		log		  : [ 2016-02-27 ]
----------------------------------------------------------------------------
*/
#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_
#include <string>
#include "common/platform.hpp"
#include "fplayer_mgr.hpp"






namespace KBEngine
{

	//------------------------------------------------------------------------------
	// ��ҷ�ͣ����  ��Ա���ķ�ͣ0x01��GM���߷�ͣ0x02���ֻ���0x04���ܱ���0x08
	//------------------------------------------------------------------------------
	enum  EPlayerFrobidMask
	{
		EPLM_MemberCenter	= 0x01,		// ��Ա����
		EPLM_GMTool			= 0x02,		// GM����
		EPLM_CellPhone		= 0x04,		// �ֻ���
		EPLM_MiBao			= 0x08,		// �ܱ�����ͣ
		EPLM_WaiGua			= 0x10		// ������Զ���ͣ
	};

	//----------------------------------------------------------------
	// ��¼��һ�����Ϣ sizeof = 396
	//----------------------------------------------------------------
	struct tagPlayerInfo
	{
		uint32				dwClientID;							// �ͻ���ID
		uint32				dwCDIndex;							// ����ID
		uint32				dwAccountID;						// �ʺ�ID
		uchar				szAccountName[32];					// �ʺ�����
		uint32				dwMibaoCrc;							// ����
		uint32				dwFrobidMask;						// ��ͣ���� ÿ1λ��Ӧһ�ַ�ͣ����
		uint32				dwIP;								// �ͻ���IP
		uint32				dwWorldNameCrc;						// ��Ϸ��������CRCֵ
		bool				bGuard;								// �������û�
		int32				nAccOLSec;							// �ۼƵ�¼ʱ��

		uchar				byPrivilege;						// Ȩ��
	
		tagPlayerInfo()		{ memset(this, 0, sizeof(*this)); }
	};

	
	//-----------------------------------------------------------------------------
	// �����
	//-----------------------------------------------------------------------------
	class Player
	{
	public:
		//-------------------------------------------------------------------------
		// ���캯��
		//-------------------------------------------------------------------------
		Player(uint32 dwClientID, uint32 dwCDIndex, uint32 dwIP, uint32 dwWorldID);
		~Player();

		//-------------------------------------------------------------------------
		// ����Get
		//-------------------------------------------------------------------------
		uint32				GetAccountID()				{ return m_Data.dwAccountID;	}
		uint32				GetClientID()				{ return m_Data.dwClientID;		}
		uint32				GetCDIndex()				{ return m_Data.dwCDIndex;		}
		uint32				GetLoginWorldNameCrc()		{ return m_Data.dwWorldNameCrc; }
		
		//uint32				GetPreLoginTime()			{ return m_dwPreLoginTime;	}
		uint32				GetPreLoginIP()				{ return m_dwPreLoginIP;		}

		int32				GetVerifyCode()				{ return m_nVerifyCode;			}
		uchar				GetPrivilege()				{ return m_Data.byPrivilege;	}
		uchar*				GetAccoutName()				{ return m_Data.szAccountName;	}
		tagPlayerInfo&		GetPlayerData()				{ return m_Data;				}

		BOOL				GetForbidMask()				{ return m_Data.dwFrobidMask;	}
		BOOL				IsGuard()					{ return m_Data.bGuard;			}
		
		//-------------------------------------------------------------------------
		// �����Ϣ���
		//-------------------------------------------------------------------------
		void				ProofReturn(tagProofResult* pResult);

		//-------------------------------------------------------------------------
		// �������
		//-------------------------------------------------------------------------
		void				SetConnLost()				{ InterlockedExchange((LPLONG)(&m_bConnLost), TRUE); }
		bool				IsConnLost()				{ return m_bConnLost; }

		//-------------------------------------------------------------------------
		// ������Ϣ���
		//-------------------------------------------------------------------------
		static void			RegisterPlayerMsg();
		static void			UnRegisterPlayerMsg();

		INT32				HandleMessage();
		
		//-------------------------------------------------------------------------
		// ��֤���
		//-------------------------------------------------------------------------
		void				SetPreLoginIP(DWORD dwIP)		{ m_dwPreLoginIP = dwIP; }


		bool				IsNeedMibao()					{ return m_bNeedMibao; }
		bool				IsProofing()					{ return m_bProofing; }
		bool				IsProofEnd()					{ return m_bProofEnd; }
		void				SetProofing()					{ m_bProofing = TRUE; m_bProofEnd = FALSE; }
		void				SetProofEnd()					{ m_bProofEnd = TRUE; m_bProofing = FALSE; }

		bool				IsSelectWorldOk()				{ return m_bSelectWorldOk; }
		void				SetSelectWorldOK()				{ m_bSelectWorldOk = TRUE; }

	private:
		//-----------------------------------------------------------------------
		// ��Ϣ������
		//-----------------------------------------------------------------------
		UINT32				HandleProof(tagNetCmd* pCmd);
		
		//-----------------------------------------------------------------------
		// ��Ϣ���
		//-----------------------------------------------------------------------
		void	            SendMsg(uchar* pMsg, uint32 dwSize);

		//-----------------------------------------------------------------------
		// ��������
		//-----------------------------------------------------------------------
		bool				CheckName(std::string& str);
	private:
		
		tagPlayerInfo		m_Data;

		int32				m_nVerifyCode;			// ��֤��
		bool				m_bNeedMibao;			// �Ƿ���Ҫ�ܱ���֤
		bool				m_bProofing;			// �Ƿ����ڽ�����֤
		bool				m_bProofEnd;			// �Ƿ��Ѿ���֤���
		bool				m_bSelectWorldOk;		// �Ƿ��Ѿ�ѡ����Ϸ����ɹ�

		volatile bool		m_bConnLost;			// �����Ƿ��Ѿ��Ͽ�
		uint32				m_dwPreLoginIP;			//�ϴε�¼ip

	};
	
}
#endif




