#pragma once

#include <mysql.h>
#include <stdio.h>
#include <io.h>
#include <fstream>  
#include "CryptoPP.h"

#define IniFileName "../bin/config.ini"
#define DontFind "-"
const int readIniSize = 256;
const char str_rep = '\'';

enum Query_Result
{
	Q_FALSE = -1,
	Q_SUCESS = 1,
	Q_ERROR,
};
enum class Query_Type
{
	QUERY,
	FUNC,
	PROC,
};



class Ini_File
{
public:
	static std::pair<std::string, bool> Read_Ini(std::string IpApp, std::string IpKey);
	static std::pair<std::string, bool> Read_Ini(char* IpApp, char* IpKey);
	static bool Write_ini(std::string IpApp, std::string IpKey, std::string value);
};

class DBData
{
public:
	bool Init();
	const char* GetHost() { return _host.c_str(); }
	const char* GetID() { return _id.c_str(); }
	const char* GetPW() { return _pw.c_str(); }
	const char* GetDB() { return _db.c_str(); }
	int GetIntPort() { return std::stoi(_port); }
	const char* GetStrPort() { return _port.c_str(); }

	void SetData();

private:
	void GetError(int16 errorcode);

private:
	std::string _host, _id, _pw, _db, _port;
};

class MySQL_DB
{
public:
	MySQL_DB() {}
	~MySQL_DB() { Close(); }

public:
	bool Init();
	void Close();
	bool Login(std::string id, std::string pw);
	bool SignUp(std::string id, std::string pw);
	bool SaveLog(std::string id, std::string log);
	bool SendQuery(std::string query, Query_Type type);

private:
	bool MakeFile();
	bool FindFile();
	void GetError(int16 errorcode);

private:
	Mutex _sqlLock;
	MYSQL _Conn;
	MYSQL* _ConnPtr = nullptr;
	MYSQL_RES* _Result;
	MYSQL_ROW _Row;
	int _Stat;
	DBData _dbData;
};

