#pragma once
#include <ctime>

class Send_Time
{
public:
	static std::string GetDateTime();

public:
	static time_t _time;
	static tm _stime;
};

