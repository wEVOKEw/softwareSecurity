#include <stdio.h>
#include <windows.h>
#include <string.h>

typedef void(*ptrtarget)(char*);
HMODULE hMod = LoadLibrary(L"F:\\softwareSecurity\\TestInitialNullForStudent\\InjectDll\\Debug\\InnjectDll.dll");
ptrtarget  GetTarget = (ptrtarget)GetProcAddress(hMod, "GetTarget");

int main()
{
	char inputPath[256];
	int num;

	printf("--------------------------------Here are the files for testing--------------------------------\n");
	printf("1¡¢TestApp.exe\n");
	printf("\nPlease select the number of the file that you want to inject : ");
	scanf_s("%d", &num);

	switch(num)
	{
		case 1:
			strcpy_s(inputPath, 256, "F:\\softwareSecurity\\TestInitialNullForStudent\\InjectDll\\Debug\\TestApp.exe");
			GetTarget(inputPath);
			break;
	}

	return 0;
}