#ifndef LOG_H
#define LOG_H
#include <ostream>

class logger:public std::ostream
{
public:
	logger( std::ostream& stream)
		:std::ostream(stream.rdbuf())
	{}
};

#endif // LOG_H
