
#include <iostream>
#include <windows.h>
#include <cstdlib>

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
	tool_clear_draw_commands();

	std::vector<std::wstring> outVector;
	get_desktops_list(outVector);
	for (int i = 0; i < outVector.size(); i++)
	{
		printf("desktop:%ws\n", outVector[i].c_str());
		if (!wcscmp(outVector[i].c_str(), L"Default"))
		{
			init_drawing_thread(outVector[i].c_str());
		}
	}

	//Sleep(1000);
	//init_drawing_thread(L"MyExplorerDesktop");

	int size = 20;
	tool_push_draw_command(100, 100, size, 5000, 255, 0, 0, 255, L"hello world 1 !", false);
	tool_push_draw_command(100, 100, size, 4000, 255, 0, 0, 255, L"hello world 2 !", false);
	tool_push_draw_command(100, 100, size, 3000, 255, 0, 0, 255, L"hello world 3 !", true);
	tool_push_draw_command(100, 100, size, 2000, 255, 0, 0, 255, L"hello world 4 !", true, 0, 0, 255, 255);
	tool_push_draw_command(100, 100, size, 1000, 255, 0, 0, 255, L"hello world 5 !", true,0, 255,0, 255);
	tool_push_draw_command(100, 100, size, 10000, 255, 0, 0, 255, L"你好世界ا", true, 255, 255,0, 255);
	tool_push_draw_command(100, 100, size, 99999999, 255, 0, 0, 255, L"مرحبا ايها العالم", true,255,255,255,255);


	printf("tool_push_affinity_rule\n ");

	if (!tool_push_affinity_rule("wda_monitor.exe", WDA_NONE, WDA_MONITOR))
	{
		printf("faild to add affinity rule !");
		exit(0);
	}

	printf("tool_push_prochide_rule GetCurrentProcessId\n ");

	if (!tool_push_prochide_rule(GetCurrentProcessId()))
	{
		printf("faild to add PROCHIDE rule !");
		exit(0);
	}

	printf("all good !\n");
	getchar();
	getchar();
	

	return 0;
}

