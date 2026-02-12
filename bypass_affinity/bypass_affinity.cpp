
#include <iostream>
#include <windows.h>

#include "MXBYPASS.h"


int main()
{
	printf("started\n");

	init_map_driver();

	if (!is_tool_ready())
	{
		printf("faild to load the driver ,wtf?\n");
		exit(0);

	}

	tool_clear_affinity_rules();
	tool_clear_prochide_rules();

	if (!tool_push_affinity_rule("wda_monitor.exe", WDA_NONE, WDA_MONITOR))
	{
		printf("faild to add affinity rule !");
		exit(0);
	}

	printf("waiting for wda_monitor.exe to get pid\n");

	while (true)
	{
		int pid = tool_get_process_pid(L"wda_monitor.exe");
		if (pid != 0)
		{
			if (!tool_push_prochide_rule(pid))
			{
				printf("faild to add PROCHIDE rule !");
				exit(0);
			}
			printf("wda_monitor pid:%d hided ok\n", pid);
			break;
		}
		Sleep(500);
	}
	printf("all good !\n");
	getchar();
	getchar();

	return 0;
}

