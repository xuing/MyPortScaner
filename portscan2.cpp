// portscan2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "conio.h"
#include "Scanner.h"
#define TRUE 1

int main()
{
	CScanner scanner;
	printf("Port Scanner\n");
	printf("��ӭʹ�óɶ�����ѧԺ��Ϣ��ȫʵ����ר�ö��߳�ɨ���� \n");
	while (TRUE) {
		printf("i����ip p �˿� s��ʼ\n");
		char  cmd = _getch();
		if (cmd == 'i' || cmd == 'I') {
			printf("����ip��");
			char szIP[128];
			scanf_s("%s", szIP, 128);
			//ip����
			scanner.Addip(szIP);
		}
		else if (cmd == 'p' || cmd == 'P') {
			printf("������˿�");
			char szPort[128];
			scanf_s("%s", szPort, 128);
			//�˿ڴ���
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
			//��ʼɨ�� 
			scanner.Start();
			break;
		}
	}
	_getch();
	scanner.PrintfResult();
	printf("Press any key to exit...\n");
	_getch(); //�ȴ�����
    return 0;
}

