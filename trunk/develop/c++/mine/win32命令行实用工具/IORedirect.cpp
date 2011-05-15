#include <stdio.h>
#include <string>

int g_argc;
char** g_argv;

std::string getProgramName(const char* argv0);
void usage();

int main(int argc, char* argv[])
{
	g_argc = argc;
	g_argv = argv;	
	if (argc == 2)		
	{
		if (strcmp(argv[1], "--help") || 
			strcmp(argv[1], "-h") || 
			strcmp(argv[1], "/?"))
		{
			usage();
			exit(0);
		}
	}
	int c;
	while ((c = fgetc(stdin)) != EOF)
	{
		fputc(c, stdout);
		fputc(c, stderr);
	}
	return 0;
}

void usage()
{
	printf("Redirect from stdin to stdout & stderr.\n");
	printf("Usage: %s\n", getProgramName(g_argv[0]).c_str());
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
