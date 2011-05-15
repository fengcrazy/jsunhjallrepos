#include <stdio.h>
#include <string>
#include <Windows.h>

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

int g_argc;
char** g_argv;

std::string getProgramName(const char* argv0);
void usage();

int main(int argc, char* argv[])
{
	g_argc = argc;
	g_argv = argv;
	const char* content = "";
	const char* caption = "";
	UINT type = MB_OK;
	if (argc < 2)
	{
		usage();
		return -1;
	}
	if (argc >= 2)
	{		
		content = argv[1];
		if (!strcmp(content, "--help")||
			!strcmp(content, "-h")||
			!strcmp(content, "/?"))
		{
			usage();
			return -1;
		}
	}
	if (argc >= 3)
	{
		caption = argv[2];
	}
	if (argc >= 4)
	{
		type = atoi(argv[3]);
	}
	return MessageBoxA(NULL, content, caption, type);	
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

void usage()
{
	char buf[4096];
	sprintf(buf, 
		"Popup a message box.\n"
		"Usage: %s [Content] [Caption] [Type]\n"
		"\tType:\n"
		"\t#define MB_OK                       0x00000000L\n"
		"\t#define MB_OKCANCEL                 0x00000001L\n"
		"\t#define MB_ABORTRETRYIGNORE         0x00000002L\n"
		"\t#define MB_YESNOCANCEL              0x00000003L\n"
		"\t#define MB_YESNO                    0x00000004L\n"
		"\t#define MB_RETRYCANCEL              0x00000005L\n"
		"\t#if(WINVER >= 0x0500)\n"
		"\t#define MB_CANCELTRYCONTINUE        0x00000006L\n"
		"\t#endif /* WINVER >= 0x0500 */\n"
		"\t\n"
		"\t#define MB_ICONHAND                 0x00000010L\n"
		"\t#define MB_ICONQUESTION             0x00000020L\n"
		"\t#define MB_ICONEXCLAMATION          0x00000030L\n"
		"\t#define MB_ICONASTERISK             0x00000040L\n"
		"\t\n"
		"\t#if(WINVER >= 0x0400)\n"
		"\t#define MB_USERICON                 0x00000080L\n"
		"\t#define MB_ICONWARNING              MB_ICONEXCLAMATION\n"
		"\t#define MB_ICONERROR                MB_ICONHAND\n"
		"\t#endif /* WINVER >= 0x0400 */\n"
		"\t\n"
		"\t#define MB_ICONINFORMATION          MB_ICONASTERISK"
		"\t#define MB_ICONSTOP                 MB_ICONHAND"
		"\t\n"
		"\t#define MB_DEFBUTTON1               0x00000000L\n"
		"\t#define MB_DEFBUTTON2               0x00000100L\n"
		"\t#define MB_DEFBUTTON3               0x00000200L\n"
		"\t#if(WINVER >= 0x0400)\n"
		"\t#define MB_DEFBUTTON4               0x00000300L\n"
		"\t#endif /* WINVER >= 0x0400 */\n"
		"\t\n"
		"\t#define MB_APPLMODAL                0x00000000L\n"
		"\t#define MB_SYSTEMMODAL              0x00001000L\n"
		"\t#define MB_TASKMODAL                0x00002000L\n"
		"\t#if(WINVER >= 0x0400)\n"
		"\t#define MB_HELP                     0x00004000L // Help Button"
		"\t#endif /* WINVER >= 0x0400 */\n"
		"\t\n"
		"\t#define MB_NOFOCUS                  0x00008000L\n"
		"\t#define MB_SETFOREGROUND            0x00010000L\n"
		"\t#define MB_DEFAULT_DESKTOP_ONLY     0x00020000L\n"
		"\t\n"
		"\t#if(WINVER >= 0x0400)\n"
		"\t#define MB_TOPMOST                  0x00040000L\n"
		"\t#define MB_RIGHT                    0x00080000L\n"
		"\t#define MB_RTLREADING               0x00100000L\n"
		"\t\n"
		"\t#endif /* WINVER >= 0x0400 */\n"
		"\t\n"
		"\t#ifdef _WIN32_WINNT\n"
		"\t#if (_WIN32_WINNT >= 0x0400)\n"
		"\t#define MB_SERVICE_NOTIFICATION          0x00200000L\n"
		"\t#else\n"
		"\t#define MB_SERVICE_NOTIFICATION          0x00040000L\n"
		"\t#endif\n"
		"\t#define MB_SERVICE_NOTIFICATION_NT3X     0x00040000L\n"
		"\t#endif\n"
		"\t\n"
		"\t#define MB_TYPEMASK                 0x0000000FL\n"
		"\t#define MB_ICONMASK                 0x000000F0L\n"
		"\t#define MB_DEFMASK                  0x00000F00L\n"
		"\t#define MB_MODEMASK                 0x00003000L\n"
		"\t#define MB_MISCMASK                 0x0000C000L\n"
		, getProgramName(g_argv[0]).c_str());
	MessageBoxA(NULL, buf, "Usage", MB_OK);
}
