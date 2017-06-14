/*
----------------------------------------------------------------------------------------------------------------------------
		file name : db_exception.h
		desc      : ���ݿ��ֶεķ�װ
		author    : ljp

		log		  : by ljp create 2017-06-13
----------------------------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "common/common.hpp"






namespace KBEngine {

	//----------------------------------------------------------------------------------------------------
	/**	Filed�� - �ṩ���ݿ�ṹ���е�ǰĳһ��ĳһ�еĵ�ǰ����
		1. �����еĵ�ǰֵ����char*�洢�����ṩ���ض�������ȡ���ݵĹ��ܣ���BOLB�ֶ�����������
		2. �ṩ�ⲿ��ѯ�������ԣ������̶ȣ���ǰ�е�ǰ�еĳ��ȣ��Ƿ�ΪNULL���ֶ����͵ȵ�
		3. ��Unicode�ַ����ṩ֧�֣�ֻ�������ݱ��д洢utf8���͵��ַ���������m_szValue��char*��ʾ
	*/
	//----------------------------------------------------------------------------------------------------
	class Field
	{
	public:
		typedef enum						// ����ö��
		{
			EDBT_UNKNOWN	= 0,			// δ֪
			EDBT_INTEGER	= 1,			// ����
			EDBT_STRING		= 2,			// �ַ�����
			EDBT_FLOAT		= 3,			// ������
			EDBT_BLOB		= 4				// ����������
		} DataTypes;

	public:
		Field();
		Field(char* szValue, char* szName, ulong uLen, ulong uMaxLen, DataTypes eType);
		Field(Field& field);
	
		~Field() {}

		inline void			SetValue(char* szValue)			{ m_szValue = szValue; }
		inline void			SetName(char* szName)			{ m_szName = szName; }
		inline void			SetType(DataTypes eType)		{ m_eType = eType; }
		inline void			SetLen(ulong uLen)				{ m_uLen = uLen; }
		inline void			SetMaxLen(ulong uMaxLen)		{ m_uMaxLen = uMaxLen; }
		inline void			SetALL(char* szName, DataTypes eType, ulong uMaxLen)
		{
			SetName(szName); SetType(eType); SetMaxLen(uMaxLen);
		}

		inline bool			IsNull() const					{ return m_szValue == NULL; }

		inline const char*	GetName()	const				{ return m_szName; }
		inline DataTypes	GetType() const					{ return m_eType; }
		inline ulong GetLen() const							{ return m_uLen; }
		inline ulong GetMaxLen() const						{ return m_uMaxLen; }

		inline const char*	GetString() const 				{ return m_szValue; }
		inline bool			GetBool()	const				{ return m_szValue ? atol(m_szValue) : 0; }
		inline int32		GetInt() const					{ return m_szValue ? static_cast<int32>(atoi(m_szValue)) : 0; }
		inline uint32		GetDword() const				{ return m_szValue ? static_cast<uint32>(_atoi64(m_szValue)) : 0; }
		inline int64		GetLong() const					{ return m_szValue ? static_cast<long64>(_atoi64(m_szValue)) : 0; }
		inline BYTE			GetByte() const					{ return m_szValue ? static_cast<BYTE>(_atoi64(m_szValue)) : 0; }
		inline int16		GetShort() const				{ return m_szValue ? static_cast<int16>(_atoi64(m_szValue)) : 0; }
		inline float		GetFloat() const				{ return m_szValue ? static_cast<float>(atof(m_szValue)) : 0.0f; }
		inline double		GetDouble() const				{ return m_szValue ? static_cast<double>(atof(m_szValue)) : 0.0; }

		int32				GetTCHAR(TCHAR* szValue, int32 nLen) const;
		bool				GetBlob(void* buffer, ulong nLen) const;
		std::string			GetUnicodeString() const;

	private:
		char*				m_szValue;				// ���е�ֵ
		char*				m_szName;				// ���е�����
		uint32				m_dwNameCrc;			// ���е�����CRC
		DataTypes			m_eType;				// �ֶ�����
		ulong				m_uLen;					// ��ǰĳ�и��еĳ��ȣ���ҪΪblog�ֶ�ʹ��
		ulong				m_uMaxLen;				// ���е����̶�
	};


	//------------------------------------------------------------------------------------------------------
	// ���캯��
	//------------------------------------------------------------------------------------------------------
	inline Field::Field() 
	: m_szValue(NULL), m_szName(NULL), m_eType(EDBT_UNKNOWN), m_uLen(0), m_uMaxLen(0)
	{

	}

	inline Field::Field(Field& field) 
	:m_szValue(field.m_szValue), m_szName(field.m_szName), m_eType(field.m_eType), m_uLen(field.m_uLen), m_uMaxLen(field.m_uMaxLen)
	{

	}

	inline Field::Field(char* szValue, char* szName, ulong uLen, ulong uMaxLen, DataTypes eType)
	: m_szValue(szValue), m_szName(szName), m_eType(eType), m_uLen(uLen), m_uMaxLen(uMaxLen)
	{

	}

} // namespace Beton

