/*
--------------------------------------------------------------------------------------------------
		file name	:
		desc		: ���������ݿ��ά��
		author		: ljp

		log			:
--------------------------------------------------------------------------------------------------
*/
#pragma once
#include "common/common.hpp"
#include "common/singleton.hpp"
#include "helper/debug_helper.hpp"
#include "thread/threadmutex.hpp"





namespace KBEngine { 

	class DBUtil;
	class DBInterface;
	class DataType;
	class PropertyDescription;
	class EntityTable;
	class MemoryStream;

	#define TABLE_ITEM_TYPE_UNKONWN		0
	#define TABLE_ITEM_TYPE_FIXEDARRAY	1
	#define TABLE_ITEM_TYPE_FIXEDDICT	2
	#define TABLE_ITEM_TYPE_STRING		3
	#define TABLE_ITEM_TYPE_DIGIT		4
	#define TABLE_ITEM_TYPE_BLOB		5
	#define TABLE_ITEM_TYPE_VECTOR2		6
	#define TABLE_ITEM_TYPE_VECTOR3		7
	#define TABLE_ITEM_TYPE_VECTOR4		8
	#define TABLE_ITEM_TYPE_UNICODE		9
	#define TABLE_ITEM_TYPE_MAILBOX		10
	#define TABLE_ITEM_TYPE_PYTHON		11

	#define ENTITY_TABLE_PERFIX						"tbl"
	#define TABLE_ID_CONST_STR						"id"
	#define TABLE_PARENTID_CONST_STR				"parentID"
	#define TABLE_ITEM_PERFIX						"sm"
	#define TABLE_ARRAY_ITEM_VALUE_CONST_STR		"value"
	#define TABLE_ARRAY_ITEM_VALUES_CONST_STR		"values"
	#define TABLE_AUTOLOAD_CONST_STR				"autoLoad"

	/**
		db�����
	*/
	enum DB_TABLE_OP
	{
		TABLE_OP_INSERT = 1,
		TABLE_OP_UPDATE = 2,
		TABLE_OP_DELETE = 3
	};


	/// �˺���Ϣ
	struct ACCOUNT_INFOS
	{
		ACCOUNT_INFOS(): name()
						,password()
						,datas()
						,dbid(0)
						,flags(0)
						,deadline(0)
		{

		}

		std::string name, password, datas, email;
		DBID		dbid;
		uint32		flags;
		uint64		deadline;
	};

/**
	ά��entity�����ݿ��еı��е�һ���ֶ�
*/
class EntityTableItem
{
public:
	EntityTableItem(std::string itemDBType, uint32 datalength, uint32 flags):
		itemName_(),
		tableName_(),
		utype_(0),
		pParentTable_(NULL),
		pParentTableItem_(NULL),
		pDataType_(NULL),
		pPropertyDescription_(NULL),
		itemDBType_(itemDBType),
		datalength_(datalength),
		flags_(flags),
		indexType_()
	{

	};

	virtual ~EntityTableItem(){};

	virtual bool			isSameKey(std::string key){ return itemName() == key; }

	virtual uint8			type() const{ return TABLE_ITEM_TYPE_UNKONWN; }

	void					itemName(std::string name){ itemName_ = name; }
	const char*				itemName(){ return itemName_.c_str(); }

	void					indexType(std::string index){ indexType_ = index; }
	const char*				indexType(){ return indexType_.c_str(); }
	
	const char*				itemDBType(){ return itemDBType_.c_str(); }

	void					utype(int32/*ENTITY_PROPERTY_UID*/ utype){ utype_ = utype; }
	int32					utype(){ return utype_; }

	void					flags(uint32 f){ flags_ = f; }
	uint32					flags(){ return flags_; }

	void					pParentTable(EntityTable* v){ pParentTable_ = v; }
	EntityTable*			pParentTable(){ return pParentTable_; }

	void					pParentTableItem(EntityTableItem* v){ pParentTableItem_ = v; }
	EntityTableItem*		pParentTableItem(){ return pParentTableItem_; }

	const DataType*			pDataType(){ return pDataType_; }

	uint32					datalength() const{ return datalength_; }

	const PropertyDescription* pPropertyDescription() const{ return pPropertyDescription_; }

	/**
		��ʼ��
	*/
	virtual bool			initialize(const PropertyDescription* pPropertyDescription, 
										const DataType* pDataType, std::string itemName) = 0;

	void					tableName(std::string name){ tableName_ = name; }
	const char*				tableName(){ return tableName_.c_str(); }

	/**
		ͬ��entity�����ݿ���
	*/
	virtual bool			syncToDB(DBInterface* dbi, void* pData = NULL) = 0;

protected:
	// �ֶ�����
	std::string				itemName_;
	std::string				tableName_;
	int32					utype_;

	EntityTable*			pParentTable_;
	EntityTableItem*		pParentTableItem_;

	const DataType*			pDataType_;
	const PropertyDescription* pPropertyDescription_;

	std::string				itemDBType_;
	uint32					datalength_;
	uint32					flags_;

	std::string				indexType_;
};

/*
	ά��entity�����ݿ��еı�
*/
class EntityTable
{
public:
	typedef std::map<int32/*ENTITY_PROPERTY_UID*/, SHARED_PTR<EntityTableItem> > TABLEITEM_MAP;

	EntityTable():
	tableName_(),
	tableItems_(),
	tableFixedOrderItems_(),
	isChild_(false),
	sync_(false)
	{

	}

	virtual ~EntityTable(){};
	
	void				tableName(std::string name){ tableName_ = name; }
	const char*			tableName(){ return tableName_.c_str(); }

	/**
		��ʼ��
	*/
	virtual bool		initialize( std::string name) { return true; }

	/**
		ͬ��entity�����ݿ���
	*/
	virtual bool		syncToDB(DBInterface* dbi) = 0;

	/**
		ͬ��entity�����������ݿ���
	*/
	virtual bool		syncIndexToDB(DBInterface* dbi) = 0;

	/** 
		����һ����item
	*/
	virtual EntityTableItem* createItem(std::string type) { return NULL; }

	/** 
		������б��ֶ�
	*/
	const EntityTable::TABLEITEM_MAP& tableItems() const { return tableItems_; }
	const std::vector<EntityTableItem*>& tableFixedOrderItems() const{ return tableFixedOrderItems_; }

	void addItem(EntityTableItem* pItem);

	bool isChild() const{ return isChild_; }
	void isChild(bool b){ isChild_ = b; }

	EntityTableItem* findItem(int32/*ENTITY_PROPERTY_UID*/ utype);

	/**
		�����Ƿ��Զ�����
	*/
	virtual void entityShouldAutoLoad(DBInterface* dbi, DBID dbid, bool shouldAutoLoad){};

	bool hasSync() const { return sync_; }

protected:

	// ������
	std::string tableName_;

	// ���е��ֶ�
	TABLEITEM_MAP tableItems_;

	// ��ScriptDefModule�б���һ�������item����
	std::vector<EntityTableItem*> tableFixedOrderItems_; 

	// �Ƿ�Ϊ�ӱ�
	bool isChild_; 

	bool sync_;
};

class EntityTables : public Singleton<EntityTables>
{
public:
	typedef UNORDERED_MAP<std::string, SHARED_PTR<EntityTable> > TABLES_MAP;
	EntityTables();
	virtual ~EntityTables();
	
	bool load(DBInterface* dbi);

	bool syncToDB(DBInterface* dbi);

	/** 
		������б�
	*/
	const EntityTables::TABLES_MAP& tables() const { return tables_; }

	void addTable(EntityTable* pTable);

	EntityTable* findTable(std::string name);

	void addKBETable(EntityTable* pTable);

	EntityTable* findKBETable(std::string name);

	void onTableSyncSuccessfully(SHARED_PTR<EntityTable> pEntityTable, bool error);

protected:
	// ���еı�
	TABLES_MAP			tables_;
	TABLES_MAP			kbe_tables_;

	int					numSyncTables_;
	bool				syncTablesError_;
};

}

