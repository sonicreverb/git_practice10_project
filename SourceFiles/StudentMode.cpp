#include <iostream>
#include <string>
#include "../Headers/StudentMode.h"
using namespace std;




void StudentAuthMenu()
{
	StudentData curr_user;
	cout << "����� ����������, ��� ����������� ������� ���� �����:"<<endl;
	

	getline(cin, curr_user.login);
	cout << curr_user.login;
	getline(cin, curr_user.password);
	cout << curr_user.password;
	cout << "������������, " << curr_user.name;

		getchar();
	
}

