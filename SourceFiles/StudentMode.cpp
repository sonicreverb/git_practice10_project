#include <iostream>	
#include <string>
#include "../Headers/StudentMode.h"
using namespace std;

void Trainig() {
	int test;
	cout << "������� ����� �����:" << endl;
	cout << "1) �����" << endl << "2) ������� (���������� � ���������)" << endl << "3) ������" << endl << "4) ��������" << endl << "5) �����" << endl << "6) ������ � ���������" << endl << "7) ������������ ������" << endl;
	cin >> test;
	switch (test)
	{
	case 1:; break;
	case 2:; break;
	case 3:; break;
	case 4:; break;
	case 5:; break;
	case 6:; break;
	case 7:; break;
	case 0:; break;
	}
}


void StudentAuthMenu()
{
	StudentData curr_user;
	int choose;
	cout << "����� ����������, ��� ����������� ������� ���� �����:" << endl;
	getline(cin, curr_user.login);
	cout << endl;
	getline(cin, curr_user.password);
	cout << endl;
	cout << "������������, " << curr_user.name << endl;
	cout << "�������� ��� �������:" << endl << "1) �������� �� ����" << endl << "2) ������������ �� ����" << endl << "3) �������� ����" << endl;
	cin >> choose;
	switch (choose)
	{
	case 1:Trainig(); break;
	case 2:; break;
	case 3:; break;
	}
	getchar();
}


