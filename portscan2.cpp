// portscan2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "conio.h"
#include "Scanner.h"
#define TRUE 1

int main()
{
	CScanner scanner;
	printf("Port Scanner\n");
	printf("欢迎使用成都东软学院信息安全实验室专用多线程扫描器 \n");
	while (TRUE) {
		printf("i输入ip p 端口 s开始\n");
		char  cmd = _getch();
		if (cmd == 'i' || cmd == 'I') {
			printf("输入ip段");
			char szIP[128];
			scanf_s("%s", szIP, 128);
			//ip处理
			scanner.Addip(szIP);
		}
		else if (cmd == 'p' || cmd == 'P') {
			printf("请输入端口");
			char szPort[128];
			scanf_s("%s", szPort, 128);
			//端口处理
			if (strstr(szPort, "-") == 0) {
				if (atoi(szPort) != 0) {
					scanner.AddPort(atoi(szPort));
				}
			}
			else
			{
				char * szStartPort = szPort;
				char * szEndPort = strstr(szPort, "-") + 1;
				*(szEndPort - 1) = 0;
				scanner.AddPort(atoi(szStartPort), atoi(szEndPort));
			}
		}
		else if (cmd == 's' || cmd == 'S') {
			//开始扫描 
			scanner.Start();
			break;
		}
	}
	_getch();
	scanner.PrintfResult();
	printf("Press any key to exit...\n");
	_getch(); //等待结束
    return 0;
}

