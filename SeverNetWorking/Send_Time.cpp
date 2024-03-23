#include "pch.h"
#include "Send_Time.h"

time_t Send_Time::_time;
tm Send_Time::_stime;

std::string Send_Time::GetDateTime()
{
	_time = time(NULL);
	errno_t t_error = localtime_s(&_stime, &_time);

	int n_zero = 2;
	auto t_hour = std::string(n_zero - min(n_zero, std::to_string(_stime.tm_hour).length()), '0') + std::to_string(_stime.tm_hour);
	auto t_min = std::string(n_zero - min(n_zero, std::to_string(_stime.tm_min).length()), '0') + std::to_string(_stime.tm_min);
	auto t_sec = std::string(n_zero - min(n_zero, std::to_string(_stime.tm_sec).length()), '0') + std::to_string(_stime.tm_sec);

	return t_hour + ":" + t_min + ":" + t_sec;
}
