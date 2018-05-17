
#ifndef netsdk_demo_global_macro_define_h
#define netsdk_demo_global_macro_define_h

#include <iostream>
#include <limits>
#include <sstream>
#include "dhnetsdk.h"
#include "dhconfigsdk.h"


#define FIRST_OF(first, ...) first
#define REST_OF(first, ...) __VA_ARGS__

template<typename T> inline void _mem_zero(T& stu) { memset(&stu, 0, sizeof(stu)); }
template<typename T, size_t N> inline size_t _count_of(const T(&)[N]) { return N; };

template<typename T> 
inline std::ostream& print(const std::string& prefix, const T& v)
{ return std::cout << prefix << v; }

#define PRINT(v) (print(#v" = ", (v)) << std::endl)

#undef max
template<typename T>
void input(const std::string& prompt, T& v)
{
	do {
		std::cout << prompt;
		if (!(std::cin >> v))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input value!" << std::endl;
			continue;
		}
		else break;
	} while(1);
}

#define INPUT(v) input("Input "#v": ", (v))

inline void press_to_continue()
{
#if defined(WIN32) || defined(WIN64)
	system("pause");
#else
	system("read");
#endif
}

inline bool prompt(const std::string& message = "")
{
	static std::string s_promptYes = "? (y for yes, others for no): ";
	char answer;
	input(message + s_promptYes, answer);
	return answer == 'y';
}

inline void section_mark(const std::string& taskName = "") { std::cout << "####\n#### " << taskName << " ####\n####"<< std::endl; }

inline void section_mark_channel(int channel, const std::string& taskName = "")
{
	std::ostringstream ossChannel;
	ossChannel << channel;
	section_mark(taskName + " - channel " + ossChannel.str());
}

#define NETSDK_ERROR(funcName) std::cerr << #funcName" failed: ERROR = " << (0x7fffffff&CLIENT_GetLastError()) << std::endl

#define __NET_RUN(errHandle, func, ...)\
if (func(__VA_ARGS__)) {\
	std::cout << #func" succeeded" << std::endl;\
}\
else do {\
NETSDK_ERROR(func);\
errHandle;\
} while(0)

#define NET_RUN(func, ...) __NET_RUN(press_to_continue(); return EXIT_FAILURE, func, __VA_ARGS__)

#endif
