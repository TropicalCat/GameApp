/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/



#ifndef KBE_BASE_HPP
#define KBE_BASE_HPP
	
// common include	
#include "profile.hpp"
#include "common/common.hpp"
#include "helper/debug_helper.hpp"
	

//#define NDEBUG
// windows include	
#if KBE_PLATFORM == PLATFORM_WIN32
#else
// linux include
#include <errno.h>
#endif
	
namespace KBEngine{

class EntityMailbox;
class Channel;



class Base 
{
	
public:
	Base(ENTITY_ID id,  bool isInitialised = true);
	~Base();

	/** 
		�Ƿ�洢���ݿ� 
	*/
	INLINE bool hasDB()const;
	INLINE void hasDB(bool has);

	/** 
		���ݿ����ID
	*/
	INLINE DBID dbid()const;
	INLINE void dbid(DBID id);
	
	/** 
		����cell���ֵ�ʵ�� 
	*/
	bool destroyCellEntity(void);

	EntityMailbox* cellMailbox(void)const;

	void cellMailbox(EntityMailbox* mailbox);
	
	

	/**
		�Ƿ񴴽���space
	*/
	INLINE bool isCreatedSpace();

	/** 
		cellData���� 
	*/
	
	void createCellData(void);

	void destroyCellData(void);

	void addPersistentsDataToStream(uint32 flags, MemoryStream* s);

	
	INLINE bool creatingCell(void)const;

	/**
		����cell���ֽ�entity��celldata����һ�ݹ���
	*/
	void reqBackupCellData();
	
	/** 
		д������Ϣ����
	*/
	void writeBackupData(MemoryStream* s);
	void onBackup();

	/** 
		д�浵��Ϣ����
	*/
	void writeArchiveData(MemoryStream* s);

	/** 
		��Ҫ���浽���ݿ�֮ǰ��֪ͨ 
	*/
	void onWriteToDB();
	void onCellWriteToDBCompleted(CALLBACK_ID callbackID);
	void onWriteToDBCallback(ENTITY_ID eid, DBID entityDBID, 
		CALLBACK_ID callbackID, bool success);

	/** ����ӿ�
		entity��һ��д���ݿ���dbmgr���ص�dbid
	*/
	void onGetDBID(Channel* pChannel, DBID dbid);

	/** 
		����cellʧ�ܻص� 
	*/
	void onCreateCellFailure(void);

	/** 
		����cell�ɹ��ص� 
	*/
	void onGetCell(Channel* pChannel, COMPONENT_ID componentID);

	/** 
		��ʧcell�˵�֪ͨ 
	*/
	void onLoseCell(Channel* pChannel, MemoryStream& s);

	/** 
		��cellapp������ֹ�� baseapp������ҵ����ʵ�cellapp����ָ���
		����ô˷���
	*/
	void onRestore();

	/** 
		����cell����
	*/
	void onBackupCellData(Channel* pChannel, MemoryStream& s);

	/** 
		�ͻ��˶�ʧ 
	*/
	void onClientDeath();

	/** ����ӿ�
		Զ�̺��б�entity�ķ��� 
	*/
	void onRemoteMethodCall(Channel* pChannel, MemoryStream& s);

	/** 
		�������entity 
	*/
	void onDestroy(bool callScript);

	/**
		����base�ڲ�֪ͨ
	*/
	void onDestroyEntity(bool deleteFromDB, bool writeToDB);



	INLINE bool inRestore();

	
	/** ����ӿ�
		�ͻ���ֱ�ӷ�����Ϣ��cellʵ��
	*/
	void forwardEntityMessageToCellappFromClient(Channel* pChannel, MemoryStream& s);
	
	/**
		������Ϣ��cellapp��
	*/
	void sendToCellapp(Bundle* pBundle);
	void sendToCellapp(Channel* pChannel, Bundle* pBundle);

	
	/**
		���ͻص�
	*/
	void onTeleportCB(Channel* pChannel, SPACE_ID spaceID, bool fromCellTeleport);  
	void onTeleportFailure();  
	void onTeleportSuccess(SPACE_ID spaceID);

	/** ����ӿ�
		ĳ��entity����teleport�����entity��space�ϡ�
	*/
	void reqTeleportOther(Channel* pChannel, ENTITY_ID reqTeleportEntityID, 
		COMPONENT_ID reqTeleportEntityCellAppID, COMPONENT_ID reqTeleportEntityBaseAppID);

	/** ����ӿ�
		entity����Ǩ�Ƶ���һ��cellapp�ϵĹ��̿�ʼ�ͽ�����
	*/
	void onMigrationCellappStart(Channel* pChannel, COMPONENT_ID cellappID);
	void onMigrationCellappEnd(Channel* pChannel, COMPONENT_ID cellappID);

	/**
		���û�ȡ�Ƿ��Զ��浵
	*/
	INLINE int8 shouldAutoArchive()const;
	INLINE void shouldAutoArchive(int8 v);
	
	/**
		���û�ȡ�Ƿ��Զ�����
	*/
	INLINE int8 shouldAutoBackup()const;
	INLINE void shouldAutoBackup(int8 v);
	
	/**
		cellapp���
	*/
	void onCellAppDeath();

	/** 
		ת����Ϣ��� 
	*/
	void onBufferedForwardToCellappMessagesOver();

protected:
	
	/**
		��db��������log
	*/
	void eraseEntityLog();

protected:
	// ���entity�Ŀͻ���mailbox cellapp mailbox
	EntityMailbox*							clientMailbox_;			
	EntityMailbox*							cellMailbox_;


	// �Ƿ��Ǵ洢�����ݿ��е�entity
	bool									hasDB_;					
	DBID									DBID_;

	// �Ƿ����ڻ�ȡcelldata��
	bool									isGetingCellData_;

	// �Ƿ����ڴ浵��
	bool									isArchiveing_;

	// �Ƿ�����Զ��浵 <= 0Ϊfalse, 1Ϊtrue, KBE_NEXT_ONLYΪִ��һ�κ��Զ�Ϊfalse
	int8									shouldAutoArchive_;
	
	// �Ƿ�����Զ����� <= 0Ϊfalse, 1Ϊtrue, KBE_NEXT_ONLYΪִ��һ�κ��Զ�Ϊfalse
	int8									shouldAutoBackup_;

	// �Ƿ����ڴ���cell��
	bool									creatingCell_;

	// �Ƿ��Ѿ�������һ��space
	bool									createdSpace_;

	// �Ƿ����ڻָ�
	bool									inRestore_;

	//// ��һЩ״̬��(���͹�����)������cellapp�����ݰ���Ҫ������, ���ʵ�״̬��Ҫ����ת��
	//BaseMessagesForwardHandler*				pBufferedSendToCellappMessages_;
};

}


#ifdef CODE_INLINE
#include "base.ipp"
#endif

#endif // KBE_BASE_HPP
