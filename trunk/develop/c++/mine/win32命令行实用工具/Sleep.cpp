#include <stdio.h>
#include <string>
#include <Windows.h>

int g_argc;
char** g_argv;

std::string getProgramName(const char* argv0);
void usage();

int main(int argc, char* argv[])
{
	g_argc = argc;
	g_argv = argv;
	if (argc != 2)
	{
		usage();
		return 1;
	}
	int nSeconds = atoi(argv[1]);
	if (nSeconds < 0)
	{
		usage();
		return 2;
	}
	Sleep(nSeconds*1000);
	return 0;
}

void usage()
{
	printf("Sleep seconds.\n");
	printf("Usage: %s <Seconds>\n", getProgramName(g_argv[0]).c_str());
}

std::string getProgramName(const char* argv0)
{
	std::string s = argv0;
	std::string::size_type pos = s.find_last_of("\\/");
	if (pos != std::string::npos)
	{
		return s.substr(pos+1);
	}
	return s;
}
