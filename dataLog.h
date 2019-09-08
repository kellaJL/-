#ifndef DATALOG_H
#define DATALOG_H

#include <fstream>
#include <string>

#include "datalog_global.h"
class DATALOGSHARED_EXPORT DataLog
{

private:
	DataLog();
	DataLog(const DataLog&) {}
	DataLog operator=(const DataLog&) { return*this; }
	
	FILE* file;
public:
	static DataLog& Instance()
	{
		static DataLog logger;
		return logger;
	 }
	void info(const char* format,...);
	void warn(const char* format, ...);
	void error(const char* format, ...);
	~DataLog();
};

#define Log_Info(...)\
    DataLog::Instance().info(__VA_ARGS__);

#define Log_Warn(...)\
    DataLog::Instance()->warn(__VA_ARGS__);

#define Log_Error(...)\
    DataLog::Instance().error(__VA_ARGS__);




#endif // DATALOG_H
