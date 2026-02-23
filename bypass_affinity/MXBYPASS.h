// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MXBYPASS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MXBYPASS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#ifdef MXBYPASS_EXPORTS
#define MXBYPASS_API extern "C" __declspec(dllexport)
#else
#define MXBYPASS_API extern "C" __declspec(dllimport)
#endif
#pragma comment(lib,"MXBYPASS.lib")

#include <Windows.h>
#include <vector>
#include <string>


MXBYPASS_API void init_map_driver();
MXBYPASS_API bool is_tool_ready(void);
MXBYPASS_API bool tool_push_affinity_rule(const CHAR* process_name, INT set_dwAffinity, INT get_dwAffinity);
MXBYPASS_API bool tool_pop_affinity_rule();
MXBYPASS_API int tool_get_affinity_rules_cnt();
MXBYPASS_API bool tool_clear_affinity_rules();
MXBYPASS_API int tool_get_process_pid(LPCWSTR name);
MXBYPASS_API bool tool_push_prochide_rule(INT pid);
MXBYPASS_API bool tool_pop_prochide_rule();
MXBYPASS_API int tool_get_prochide_rules_cnt();
MXBYPASS_API bool tool_clear_prochide_rules();



MXBYPASS_API void get_desktops_list(std::vector<std::wstring>& outVector);
MXBYPASS_API void init_drawing_thread(const wchar_t* desktop_name);
MXBYPASS_API void tool_push_draw_command(int x, int y, int size, int timeout, float r, float g, float b, float a, const wchar_t* message, bool have_bg = false, float r2 = 255, float g2 = 255, float b2 = 255, float a2 = 255);
MXBYPASS_API void tool_pop_last_draw_command();
MXBYPASS_API void tool_clear_draw_commands();
