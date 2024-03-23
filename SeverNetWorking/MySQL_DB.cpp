#include "pch.h"
#include "MySQL_DB.h"

std::pair<std::string, bool> Ini_File::Read_Ini(std::string IpApp, std::string IpKey)
{
	char value[readIniSize];
	bool result = false;
	Crypto* _crypto = new Crypto();

	GetPrivateProfileString(IpApp.c_str(), IpKey.c_str(), DontFind, value, readIniSize, IniFileName);

	if (value[0] == '-')
		result = false;
	else
		result = true;

	std::string str(value);
	std::string decValue = _crypto->Decrypt(str); //복호화
	
	return std::pair<std::string, bool>(decValue, result);

}

std::pair<std::string, bool> Ini_File::Read_Ini(char* IpApp, char* IpKey)
{
	char value[readIniSize];
	bool result = false;
	Crypto* _crypto = new Crypto();

	GetPrivateProfileString(IpApp, IpKey, DontFind, value, readIniSize, IniFileName);

	if (value[0] == '-')
		result = false;
	else
		result = true;

	std::string str(value);
	std::string decValue = _crypto->Decrypt(str); //복호화

	return std::pair<std::string, bool>(decValue, result);

}

bool Ini_File::Write_ini(std::string IpApp, std::string IpKey, std::string value)
{
	Crypto* _crypto = new Crypto();
	std::string encValue = _crypto->Encrypt(value); //암호화
	return WritePrivateProfileString(IpApp.c_str(), IpKey.c_str(), encValue.c_str(), IniFileName);
}

//DBData
bool DBData::Init()
{
	std::pair<std::string, bool> IniResult;

	IniResult = Ini_File::Read_Ini("DB", "Host");

	if (IniResult.second == false)
	{
		GetError(DontReadINI);
		return false;
	}
	_host = IniResult.first;

	IniResult = Ini_File::Read_Ini("DB", "ID");

	if (IniResult.second == false)
	{
		GetError(DontReadINI);
		return false;
	}
	_id = IniResult.first;

	IniResult = Ini_File::Read_Ini("DB", "PW");

	if (IniResult.second == false)
	{
		GetError(DontReadINI);
		return false;
	}
	_pw = IniResult.first;

	IniResult = Ini_File::Read_Ini("DB", "DB");

	if (IniResult.second == false)
	{
		GetError(DontReadINI);
		return false;
	}
	_db = IniResult.first;

	IniResult = Ini_File::Read_Ini("DB", "Port");

	if (IniResult.second == false)
	{
		GetError(DontReadINI);
		return false;
	}
	_port = IniResult.first;

	return true;
}

void DBData::SetData()
{
	std::cin >> _host >> _id >> _pw >> _db >> _port;
}

void DBData::GetError(int16 errorcode)
{
	std::cout << "INI Error : " << errorcode << std::endl;
}


//MySQL

bool MySQL_DB::Login(std::string id, std::string pw)
{
	if (_ConnPtr == NULL)
	{
		GetError(FalseConnectDB);
		return false;
	}
	
	std::string login_query = "SELECT Login_Accept(";
	login_query += str_rep + id + str_rep + ", " + str_rep + pw + str_rep + ");";
	
	{
		LockGuard lg(_sqlLock);
		if (SendQuery(login_query, Query_Type::FUNC) == false)
			return false;

		if (std::stoi(_Row[0]) == Query_Result::Q_SUCESS)
		{
			std::cout << "로그인 성공" << std::endl;
			return true;
		}
		else
		{
			std::cout << "로그인 실패" << std::endl;
			return false;
		}
	}

}

bool MySQL_DB::SignUp(std::string id, std::string pw)
{
	if (_ConnPtr == NULL)
	{
		GetError(FalseConnectDB);
		return false;
	}

	std::string signUp_query = "SELECT Create_ID(";
	signUp_query += str_rep + id + str_rep + ", " + str_rep + pw + str_rep + ");";

	{
		LockGuard lg(_sqlLock);

		if (SendQuery(signUp_query, Query_Type::FUNC) == false)
			return false;

		if (std::stoi(_Row[0]) == Query_Result::Q_SUCESS)
		{
			std::cout << "ID 생성되었습니다." << std::endl;
			SaveLog(id, "SignUp");
			return true;
		}
		else
		{
			std::cout << "ID 생성에 실패하였습니다." << std::endl;
			return false;
		}
	}
	
}

bool MySQL_DB::SaveLog(std::string id, std::string log)
{
	if (_ConnPtr == NULL)
	{
		GetError(FalseConnectDB);
		return false;
	}

	std::string log_query = "CALL Save_Log(";
	log_query += str_rep + id + str_rep + ", " + str_rep + log + str_rep + ");";

	{
		LockGuard lg(_sqlLock);

		if (SendQuery(log_query, Query_Type::PROC) == false)
			return false;
	}

}

bool MySQL_DB::SendQuery(std::string query, Query_Type type)
{
	_Stat = mysql_query(_ConnPtr, query.c_str());
	if (_Stat != 0)
	{
		GetError(FalseQuery);
		return false;
	}

	if (type == Query_Type::PROC)
		return true;

	_Result = mysql_store_result(_ConnPtr);
	_Row = mysql_fetch_row(_Result);

	return true;
}

bool MySQL_DB::MakeFile()
{
	std::ofstream outfile(IniFileName);
	outfile.close();

	_dbData.SetData();

	if (Ini_File::Write_ini("DB", "Host", _dbData.GetHost()) == false)
	{
		GetError(DontWriteINI);
		return false;
	}
	if(Ini_File::Write_ini("DB", "ID", _dbData.GetID()) == false)
	{
		GetError(DontWriteINI);
		return false;
	}
	if(Ini_File::Write_ini("DB", "PW", _dbData.GetPW()) == false)
	{
		GetError(DontWriteINI);
		return false;
	}
	if(Ini_File::Write_ini("DB", "DB", _dbData.GetDB()) == false)
	{
		GetError(DontWriteINI);
		return false;
	}
	if(Ini_File::Write_ini("DB", "Port", _dbData.GetStrPort()) == false)
	{
		GetError(DontWriteINI);
		return false;
	}
}

bool MySQL_DB::FindFile()
{
	char filename[256] = IniFileName;

	if ((_access(filename, 00) != ENOENT))
		return true;
	else
	{
		MakeFile();
		return false;
	}
}

bool MySQL_DB::Init()
{
   	if (FindFile() == false)
		return false;

	if (_dbData.Init() == false)
		return false;

	mysql_init(&_Conn);

	_ConnPtr = mysql_real_connect(
		&_Conn, /*_dbData.GetHost()*/ NULL, _dbData.GetID(), _dbData.GetPW()
		, _dbData.GetDB(), _dbData.GetIntPort(), NULL, 0);

	if (_ConnPtr == NULL)
	{
		GetError(FalseConnectDB);
		return false;
	}

	return true;
}

void MySQL_DB::Close()
{
	mysql_close(&_Conn);
}

void MySQL_DB::GetError(int16 errorcode)
{
	std::cout << "MySQL Error : " << errorcode << std::endl;
}
