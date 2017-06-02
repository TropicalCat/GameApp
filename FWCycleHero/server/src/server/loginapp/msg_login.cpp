#include "msg_login.h"
#include "common/memorystream.hpp"









namespace KBEngine
{
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// �˺���֤��Ϣ
	CProofAccountNetCmd::CProofAccountNetCmd() : tagNetCmd(CL_ProofAccount)
	{
		memset(this, 0, sizeof(*this));
	}

	CProofAccountNetCmd::~CProofAccountNetCmd()
	{

	}

	void CProofAccountNetCmd::Serialize( MemoryStream* pNetStream )
	{
		(*pNetStream) << dwID;
		(*pNetStream) << dwSize;

		(*pNetStream) << szUserName;
		(*pNetStream) << szPsd;
		
	}

	void CProofAccountNetCmd::UnSerialize(MemoryStream* pNetStream)
	{
		(*pNetStream) >> dwID;
		(*pNetStream) >> dwSize;

		(*pNetStream) >> szUserName;
		(*pNetStream) >> szPsd;
		
	}

	/// �˺���֤����
	CProofAccountRespond::CProofAccountRespond() : tagNetCmd(LC_ProofAccountRespond)
	{
		
	}

	CProofAccountRespond::~CProofAccountRespond()
	{

	}

	void CProofAccountRespond::Serialize(MemoryStream* pNetStream)
	{
		(*pNetStream) << dwID;
		(*pNetStream) << dwSize;

		(*pNetStream) << errorCode;

	}

	void CProofAccountRespond::UnSerialize(MemoryStream* pNetStream)
	{
		(*pNetStream) >> dwID;
		(*pNetStream) >> dwSize;

		(*pNetStream) >> errorCode;
	}

	/// ��¼��Ϣ
	CLoginAppNetCmd::CLoginAppNetCmd() : tagNetCmd(CL_LoginApp)
	{
		
	}

	CLoginAppNetCmd::~CLoginAppNetCmd()
	{

	}

	void CLoginAppNetCmd::Serialize(MemoryStream* pNetStream)
	{
		(*pNetStream) << dwID;
		(*pNetStream) << dwSize;

		(*pNetStream) << dwErrorCode;
		(*pNetStream) << dwAccountID;
		(*pNetStream) << dwIP;
		(*pNetStream) << dwPort;
	}

	void CLoginAppNetCmd::UnSerialize(MemoryStream* pNetStream)
	{
		(*pNetStream) >> dwID;
		(*pNetStream) >> dwSize;

		(*pNetStream) >> dwErrorCode;
		(*pNetStream) >> dwAccountID;
		(*pNetStream) >> dwIP;
		(*pNetStream) >> dwPort;
	}

	/// ������Ϣ
	CHeartbestNetCmd::CHeartbestNetCmd() : tagNetCmd(CL_Heartbest)
	{
		
	}

	CHeartbestNetCmd::~CHeartbestNetCmd()
	{

	}

	void CHeartbestNetCmd::Serialize(MemoryStream* pNetStream)
	{
		(*pNetStream) << dwID;
		(*pNetStream) << dwSize;
	}

	void CHeartbestNetCmd::UnSerialize(MemoryStream* pNetStream)
	{
		(*pNetStream) >> dwID;
		(*pNetStream) >> dwSize;
	}
}