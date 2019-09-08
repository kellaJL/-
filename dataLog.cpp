#include "datalog.h"
#include <time.h>
#include <ios>
#include <direct.h>
#include <io.h>
#include <cstdarg>


DataLog::DataLog()
{
	std::string folderPath = "../Log";
	if (0 != _access(folderPath.c_str(), 0))
	{

		if (_mkdir(folderPath.c_str()))  // 返回 0 表示创建成功，-1 表示失败
		{
			folderPath = "C:\\Log";
			_mkdir(folderPath.c_str());
		}
	}
	time_t rawtime;
	struct tm * timeinfo = nullptr;
	const int buffer_size = 256;//
	char buffer[buffer_size];
	time(&rawtime);
	localtime_s(timeinfo, &rawtime);
	asctime_s(buffer, buffer_size, timeinfo);
	char* p = buffer;
	while (p)
	{
		if ((*p) == ' ')
		{
			*p = '-';
		}
		p++;
	}
	std::string fileName = "../Log/Log_" + std::string(buffer) + ".txt";
	/*fout = new std::ofstream();
	fout->open(fileName.c_str(), std::ios_base::out);*/
	file = fopen(fileName.data(), "wt");
}

void DataLog::info(const char* format,...)
{
	if (file == nullptr)
	{

	}
	va_list args;
	va_start(args, format);
	fprintf(file, "Info -- ");
	vfprintf(file, format, args);
	fprintf(file, "\n");
	va_end(args);
}

void DataLog::warn(const char* format, ...)
{
	if (file == nullptr)
	{

	}
	va_list args;
	va_start(args, format);
	fprintf(file, "Warn -- ");
	vfprintf(file, format, args);
	fprintf(file, "\n");
	va_end(args);
}

void DataLog::error(const char* format, ...)
{
	if (file == nullptr)
	{

	}
	va_list args;
	va_start(args, format);
	fprintf(file, "Error -- ");
	vfprintf(file, format, args);
	fprintf(file, "\n");
	va_end(args);
}


DataLog::~DataLog()
{
	if (file)
	{
		auto flag = fclose(file);
		if (flag)
		{
			error("the log close failed\n");
		}
	}
}













