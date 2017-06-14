/*
----------------------------------------------------------------------------------------------------------------------------
		file name : db_interface.h
		desc      : ����mysql���ݽӿڵķ�װ
		author    : ljp

		log		  : by ljp create 2017-06-13
----------------------------------------------------------------------------------------------------------------------------
*/

#include "db_interface_mysql.h"
#include "entity_table_mysql.h"
#include "db_exception.h"
#include "thread/threadguard.hpp"
#include "server/serverconfig.hpp"








namespace KBEngine { 

	KBEngine::thread::ThreadMutex logMutex;
	size_t DBInterfaceMysql::sql_max_allowed_packet_ = 0;
	//-------------------------------------------------------------------------------------
	DBInterfaceMysql::DBInterfaceMysql(std::string characterSet, std::string collation) :
	DBInterface(),
	pMysql_(NULL),
	hasLostConnection_(false),
	inTransaction_(false),
	lock_(NULL, false),
	characterSet_(characterSet),
	collation_(collation)
	{
		lock_.pdbi(this);
	}

	//-------------------------------------------------------------------------------------
	DBInterfaceMysql::~DBInterfaceMysql()
	{

	}

	//-------------------------------------------------------------------------------------
	bool DBInterfaceMysql::attach(const char* databaseName)
	{
		if(db_port_ == 0)
			db_port_ = 3306;
	
		if(databaseName != NULL)
			kbe_snprintf(db_name_, MAX_BUF, "%s", databaseName);

		hasLostConnection_ = false;
		try
		{
			pMysql_ = mysql_init(0);
			if(pMysql_ == NULL)
			{
				ERROR_MSG("DBInterfaceMysql::attach: mysql_init is error!\n");
				return false;
			}
		
			DEBUG_MSG(fmt::format("DBInterfaceMysql::attach: connect: {}:{} starting...\n", db_ip_, db_port_));

			int ntry = 0;
	__RECONNECT:
			if(mysql_real_connect( mysql(), db_ip_, db_username_, 
    							   db_password_, db_name_, db_port_, NULL, 0)) // CLIENT_MULTI_STATEMENTS  
			{
				if(mysql_select_db(mysql(), db_name_) != 0)
				{
					ERROR_MSG(fmt::format("DBInterfaceMysql::attach: Could not set active db[{}]\n",db_name_));
					detach();
					return false;
				}
			}
			else
			{
				if (mysql_errno(pMysql_) == 1049 && ntry++ == 0)
				{
					if (mysql())
					{
						::mysql_close(mysql());
						pMysql_ = NULL;
					}

					pMysql_ = mysql_init(0);
					if (pMysql_ == NULL)
					{
						ERROR_MSG("DBInterfaceMysql::attach: mysql_init is error!\n");
						return false;
					}

					if (mysql_real_connect( mysql(), db_ip_, db_username_,
											db_password_, NULL, db_port_, NULL, 0)) // CLIENT_MULTI_STATEMENTS  
					{
						this->createDatabaseIfNotExist();
						if (mysql_select_db(mysql(), db_name_) != 0)
						{
							goto __RECONNECT;
						}
					}
					else
					{
						goto __RECONNECT;
					}
				}
				else
				{
					ERROR_MSG(fmt::format("DBInterfaceMysql::attach: mysql_errno={}, mysql_error={}\n",
						mysql_errno(pMysql_), mysql_error(pMysql_)));

					detach();
					return false;
				}
			}

			if (mysql_set_character_set(mysql(), "utf8") != 0)
			{
				ERROR_MSG("DBInterfaceMysql::attach: Could not set client connection character set to UTF-8\n" );
				return false;
			}

			// ����Ҫ�ر��Զ��ύ���ײ��START TRANSACTION֮����COMMIT
			// mysql_autocommit(mysql(), 0);
			char characterset_sql[MAX_BUF];
			kbe_snprintf( characterset_sql, MAX_BUF, "ALTER DATABASE CHARACTER SET %s COLLATE %s", 
						  characterSet_.c_str(), collation_.c_str());

			query(&characterset_sql[0], strlen(characterset_sql), false);
		}
		catch (std::exception& e)
		{
			ERROR_MSG(fmt::format("DBInterfaceMysql::attach: {}\n", e.what()));
			hasLostConnection_ = true;
			detach();
			return false;
		}

		bool ret = mysql() != NULL && ping();
		if(ret)
		{
			DEBUG_MSG(fmt::format("DBInterfaceMysql::attach: successfully! addr: {}:{}\n", db_ip_, db_port_));
		}

		return ret;
	}

	//-------------------------------------------------------------------------------------
	bool DBInterfaceMysql::checkEnvironment()
	{
		std::string querycmd = "SHOW VARIABLES";
		if(!query(querycmd.c_str(), querycmd.size(), true))
		{
			ERROR_MSG(fmt::format("DBInterfaceMysql::checkEnvironment: {}, query is error!\n", querycmd));
			return false;
		}

		bool lower_case_table_names = false;
		MYSQL_RES * pResult = mysql_store_result(mysql());
		if(pResult)
		{
			MYSQL_ROW arow;
			while((arow = mysql_fetch_row(pResult)) != NULL)
			{
				std::string s = arow[0];
				std::string v = arow[1];
			
				if(s == "lower_case_table_names")
				{
					if(v == "1")
					{
						lower_case_table_names = true;
					}
					else
					{
					
					}
				}
				else if(s == "max_allowed_packet")
				{
					uint64 size;
					KBEngine::StringConv::str2value(size, v.c_str());
					sql_max_allowed_packet_ = (size_t)size;
				}
			}

			mysql_free_result(pResult);
		}
	
		return lower_case_table_names;
	}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::createDatabaseIfNotExist()
{
	std::string querycmd = fmt::format("create database {}", DBUtil::dbname());
	query(querycmd.c_str(), querycmd.size(), false);
	return true;
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::checkErrors()
{
	std::string querycmd = fmt::format("SHOW TABLES LIKE \"tbl_{}\"", DBUtil::accountScriptName());
	if(!query(querycmd.c_str(), querycmd.size(), true))
	{
		ERROR_MSG(fmt::format("DBInterfaceMysql::checkErrors: {}, query is error!\n", querycmd));
		return false;
	}

	bool foundAccountTable = false;
	MYSQL_RES * pResult = mysql_store_result(mysql());
	if(pResult)
	{
		foundAccountTable = mysql_num_rows(pResult) > 0;
		mysql_free_result(pResult);
	}

	return true;
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::reattach()
{
	detach();

	bool ret = false;

	try
	{
		ret = attach();
	}
	catch (...)
	{
		return false;
	}

	return ret;
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::detach()
{
	if(mysql())
	{
		::mysql_close(mysql());
		pMysql_ = NULL;
	}

	return true;
}

//-------------------------------------------------------------------------------------
EntityTable* DBInterfaceMysql::createEntityTable()
{
	return new EntityTableMysql();
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::dropEntityTableFromDB(const char* tablename)
{
	KBE_ASSERT(tablename != NULL);
  
	DEBUG_MSG(fmt::format("DBInterfaceMysql::dropEntityTableFromDB: {}.\n", tablename));

	char sql_str[MAX_BUF];
	kbe_snprintf(sql_str, MAX_BUF, "Drop table if exists %s;", tablename);
	return query(sql_str, strlen(sql_str));
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::dropEntityTableItemFromDB(const char* tablename, const char* tableItemName)
{
	KBE_ASSERT(tablename != NULL && tableItemName != NULL);
  
	DEBUG_MSG(fmt::format("DBInterfaceMysql::dropEntityTableItemFromDB: {} {}.\n", 
		tablename, tableItemName));

	char sql_str[MAX_BUF];
	kbe_snprintf(sql_str, MAX_BUF, "alter table %s drop column %s;", tablename, tableItemName);
	return query(sql_str, strlen(sql_str));
}

//-------------------------------------------------------------------------------------
void DBInterfaceMysql::throwError()
{
	DBException e( this );

	if (e.isLostConnection())
	{
		this->hasLostConnection(true);
	}

	throw e;
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::query(const char* strCommand, uint32 size, bool showexecinfo)
{
	if(pMysql_ == NULL)
	{
		if(showexecinfo)
		{
			ERROR_MSG(fmt::format("DBInterfaceMysql::query: has no attach(db).sql:({})\n", lastquery_));
		}

		return false;
	}

	
	lastquery_ = strCommand;


    int nResult = mysql_real_query(pMysql_, strCommand, size);  
    if(nResult != 0)  
    {  
		if(showexecinfo)
		{
			ERROR_MSG(fmt::format("DBInterfaceMysql::query: is error({}:{})!\nsql:({})\n", 
				mysql_errno(pMysql_), mysql_error(pMysql_), lastquery_)); 
		}

		this->throwError();
        return false;
    }  
    else
    {
		if(showexecinfo)
		{
			INFO_MSG("DBInterfaceMysql::query: successfully!\n"); 
		}
    }
    
    return true;
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::execute(const char* strCommand, uint32 size, MemoryStream * resdata)
{
	bool result = this->query(strCommand, size);
	if (!result)
	{
		return false;
	}

	if(resdata == NULL)
	{
		return true;
	}

	MYSQL_RES * pResult = mysql_store_result(mysql());
	if(pResult)
	{
		if (resdata != NULL)
		{
			uint32 nrows	= (uint32)mysql_num_rows(pResult);
			uint32 nfields	= (uint32)mysql_num_fields(pResult);

			(*resdata) << nfields << nrows;

			MYSQL_ROW arow;
			while((arow = mysql_fetch_row(pResult)) != NULL)
			{
				unsigned long *lengths = mysql_fetch_lengths(pResult);

				for (uint32 i = 0; i < nfields; ++i)
				{
					if (arow[i] == NULL)
					{
						std::string null = "NULL";
						resdata->appendBlob(null.c_str(), null.size());
					}
					else
					{
						resdata->appendBlob(arow[i], lengths[i]);
					}
				}
			}
		}

		mysql_free_result(pResult);
	}
	else
	{
		uint32 nfields = 0;
		uint64 affectedRows = mysql()->affected_rows;
		(*resdata) << ""; // errormsg
		(*resdata) << nfields;
		(*resdata) << affectedRows;
	}

	return true;
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::getTableNames(std::vector<std::string>& tableNames, const char * pattern)
{
	if(pMysql_ == NULL)
	{
		ERROR_MSG("DBInterfaceMysql::query: has no attach(db).\n");
		return false;
	}

	tableNames.clear();

	MYSQL_RES * pResult = mysql_list_tables(pMysql_, pattern);

	if(pResult)
	{
		tableNames.reserve((unsigned int)mysql_num_rows(pResult));

		MYSQL_ROW row;
		while((row = mysql_fetch_row(pResult)) != NULL)
		{
			unsigned long *lengths = mysql_fetch_lengths(pResult);
			tableNames.push_back(std::string(row[0], lengths[0]));
		}

		mysql_free_result(pResult);
	}

	return true;
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::getTableItemNames(const char* tablename, std::vector<std::string>& itemNames)
{
	MYSQL_RES*	result = mysql_list_fields(mysql(), tablename, NULL);
	if(result)
	{
		unsigned int numFields = mysql_num_fields(result);
		MYSQL_FIELD* fields = mysql_fetch_fields(result);

		for(unsigned int i = 0; i < numFields; ++i)
		{
			itemNames.push_back(fields[i].name);
		}
	}
	else
		return false;

	mysql_free_result(result);
	return true;
}

//-------------------------------------------------------------------------------------
const char* DBInterfaceMysql::c_str()
{
	static char strdescr[MAX_BUF];
	kbe_snprintf(strdescr, MAX_BUF, "dbtype=mysql, ip=%s, port=%u, currdatabase=%s, username=%s, connected=%s.\n", 
		db_ip_, db_port_, db_name_, db_username_, pMysql_ == NULL ? "no" : "yes");

	return strdescr;
}

//-------------------------------------------------------------------------------------
const char* DBInterfaceMysql::getstrerror()
{
	return mysql_error(pMysql_);
}

//-------------------------------------------------------------------------------------
int DBInterfaceMysql::getlasterror()
{
	return mysql_errno(pMysql_);
}

//-------------------------------------------------------------------------------------
void DBInterfaceMysql::getFields(TABLE_FIELDS& outs, const char* tablename)
{
	std::string sqlname = ENTITY_TABLE_PERFIX"_";
	sqlname += tablename;

	MYSQL_RES*	result = mysql_list_fields(mysql(), sqlname.c_str(), NULL);
	if(result == NULL)
	{
		ERROR_MSG(fmt::format("EntityTableMysql::loadFields:{}\n", getstrerror()));
		return;
	}

	unsigned int numFields;
	MYSQL_FIELD* fields;

	numFields = mysql_num_fields(result);
	fields = mysql_fetch_fields(result);

	for(unsigned int i=0; i<numFields; ++i)
	{
		TABLE_FIELD& info = outs[fields[i].name];
		info.name = fields[i].name;
		info.length = fields[i].length;
		info.maxlength = fields[i].max_length;
		info.flags = fields[i].flags;
		info.type = fields[i].type;
	}

	mysql_free_result(result);
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::lock()
{
	lock_.start();
	return true;
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::unlock()
{
	lock_.commit();
	lock_.end();
	return true;
}

//-------------------------------------------------------------------------------------
bool DBInterfaceMysql::processException(std::exception & e)
{
	DBException* dbe = static_cast<DBException*>(&e);
	bool retry = false;

	if (dbe->isLostConnection())
	{
		INFO_MSG(fmt::format("DBInterfaceMysql::processException: "
				"Thread {:p} lost connection to database. Exception: {}. "
				"Attempting to reconnect.\n",
			(void*)this,
			dbe->what()));

		int attempts = 1;

		while (!this->reattach())
		{
			ERROR_MSG(fmt::format("DBInterfaceMysql::processException: "
							"Thread {:p} reconnect({}) attempt {} failed({}).\n",
						(void*)this,
						db_name_,
						attempts,
						getLastError()));

			KBEngine::sleep(30);
			++attempts;
		}

		INFO_MSG(fmt::format("DBInterfaceMysql::processException: "
					"Thread {:p} reconnected({}). Attempts = {}\n",
				(void*)this,
				db_name_,
				attempts));

		retry = true;
	}
	else if (dbe->shouldRetry())
	{
		WARNING_MSG(fmt::format("DBInterfaceMysql::processException: Retrying {:p}\nException:{}\nnlastquery={}\n",
				(void*)this, dbe->what(), lastquery_));

		retry = true;
	}
	else
	{
		WARNING_MSG(fmt::format("DBInterfaceMysql::processException: "
				"Exception: {}\nlastquery={}\n",
			dbe->what(), lastquery_));
	}

	return retry;
}

//-------------------------------------------------------------------------------------
}
