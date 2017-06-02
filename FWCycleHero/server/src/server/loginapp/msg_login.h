#pragma once
#include "msg_cl.h"
#include "network/net_define.h"







namespace KBEngine
{
		#define MAX_MD5_ARRAY	36
		#pragma pack(push, 1)

		//--------------------------------------------------------------------------------------------
		// Login �������
		//--------------------------------------------------------------------------------------------
		enum
		{
			E_ProofResult_Account_Ok = 0,
			E_ProofResult_Account_No_Match = 1,				//���ʺŷǷ�(�ʻ������ڻ������벻��,�ܱ�����)
			E_ProofResult_Account_In_Use = 2,				//���ʺŵ�ǰ�Ѿ���ʹ��
			E_ProofResult_Account_Freezed = 3,				//���ʺű�ͣ��
			E_ProofResult_Wrong_Build_Number = 4,			//�汾�Ų���
			E_ProofResult_Disabled = 5,						//���ʺ��Ѿ�����ͣ
			E_ProofResult_Queue = 6,						//��ʼ�Ŷ�	
			E_ProofResult_Mibao_Error = 7,					//�ܱ�����
			E_ProofResult_Wrong_Type = 8,					//�Ƿ���֤����
			E_ProofResult_Proofing = 9,						//������֤���Ѿ���֤���

			E_SelectWorld_Server_Full = 11,					//�÷�������ǰӵ��
			E_SelectWorld_Server_Suspended = 12,			//�÷�������ǰ����
			E_SelectWorld_Server_Maintenance = 13,			//�÷�������ǰά��
			E_SelectWorld_Failed = 14,						//�����쳣��ѡ��ʧ��
			E_SelectWorld_Short_Time = 15,					//���ʱ��̫��,���Ժ�����
			E_SelectWorld_No_Select = 16,					//���Ѿ�ѡ��ɹ�,������ѡ
			E_SelectWorld_GameWorldName_Wrong = 17,			//�Ƿ�����Ϸ������


			E_ProofResult_Forbid_MemberCenter = 18,			//���Ļ�Ա�����˺��ѱ���ͣ������ϵ�ͷ�
			E_ProofResult_Forbid_GMTool = 19,				//������Ϸ�˺��ѱ���ͣ������ϵ�ͷ�	
			E_ProofResult_Forbid_CellPhone = 20,			//�����˺��ѱ�����������ϵ�ͷ�
			E_ProofResult_Forbid_MiBao = 21,				//�����˺��Ѿ���ʧ�ܱ���������ɽ����¼
			E_SelecWordSystemError = 22,					// �������쳣
		};

		//---------------------------------------------------------------------------------------------
		// �Ŷ�ʱ��10����
		//---------------------------------------------------------------------------------------------
		#define QUEUE_TIME	10*60

		//-----------------------------------------------------------------------------
		// ��֤��Ϣ
		//-----------------------------------------------------------------------------
		class MemoryStream;
		class CProofAccountNetCmd : public tagNetCmd
		{
		public:
			 CProofAccountNetCmd( );
			~CProofAccountNetCmd();

			virtual void	Serialize( MemoryStream* pNetStream );
			virtual void	UnSerialize(MemoryStream* pNetStream );
		public:
			char			szUserName[X_SHORT_NAME];		// �û���
			char			szPsd[MAX_MD5_ARRAY];			// ����
		
		};

		CMD_START(LC_ProofAccountRespond)
			uint32	errorCode;		// ������
		CMD_END


		class CProofAccountRespond : public tagNetCmd
		{
		public:
			 CProofAccountRespond();
			~CProofAccountRespond();

			virtual void	Serialize(MemoryStream* pNetStream);
			virtual void	UnSerialize(MemoryStream* pNetStream);
		public:
			uint32			errorCode;
		};

		class CLoginAppNetCmd : public tagNetCmd
		{
		public:
			CLoginAppNetCmd( );
			~CLoginAppNetCmd();

			virtual void	Serialize(MemoryStream* pNetStream);
			virtual void	UnSerialize(MemoryStream* pNetStream);
		public:
			uint32			dwErrorCode;					// ������
			uint32			dwAccountID;					// �ʺ�ID
			uint32			dwIP;							// ZoneServer IP ��ַ
			uint32			dwPort;							// ZoneServer �˿ں�
		};


		class CHeartbestNetCmd : public tagNetCmd
		{
		public:
			 CHeartbestNetCmd();
			~CHeartbestNetCmd();

			virtual void	Serialize(MemoryStream* pNetStream);
			virtual void	UnSerialize(MemoryStream* pNetStream);
		
		};

		
		
	#pragma pack(pop)
}

