// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MXBYPASS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MXBYPASS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MXBYPASS_EXPORTS
#define MXBYPASS_API __declspec(dllexport)
#else
#define MXBYPASS_API __declspec(dllimport)
#endif
#pragma comment(lib,"MXBYPASS.lib")

#ifdef __cplusplus
extern "C" {
#endif

MXBYPASS_API void init_map_driver(void);
MXBYPASS_API bool is_tool_ready(void);
MXBYPASS_API bool tool_push_affinity_rule(const CHAR* process_name, INT set_dwAffinity, INT get_dwAffinity);
MXBYPASS_API bool tool_pop_affinity_rule(void);
MXBYPASS_API int tool_get_affinity_rules_cnt(void);
MXBYPASS_API bool tool_clear_affinity_rules(void);
MXBYPASS_API int tool_get_process_pid(LPCWSTR name);
MXBYPASS_API bool tool_push_prochide_rule(INT pid);
MXBYPASS_API bool tool_pop_prochide_rule(void);
MXBYPASS_API int tool_get_prochide_rules_cnt(void);
MXBYPASS_API bool tool_clear_prochide_rules(void);

#ifdef __cplusplus
}
#endif