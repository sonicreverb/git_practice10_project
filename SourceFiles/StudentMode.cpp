#include <iostream>
#include <string>
#include "../Headers/StudentMode.h"
using namespace std;




void StudentAuthMenu()
{
	StudentData curr_user;
	cout << "����� ����������, ��� ����������� ������� ���� �����:"<<endl;
	

	getline(cin, curr_user.login);
	cout << endl;
	getline(cin, curr_user.password);
	cout << endl;
	cout << "������������, " << curr_user.name<<endl;
	


		getchar();
	
}

