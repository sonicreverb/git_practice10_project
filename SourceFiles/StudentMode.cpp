#include <iostream>
#include <string>
#include "../Headers/StudentMode.h"
using namespace std;




void StudentAuthMenu()
{
	StudentData curr_user;
	cout << "Добро пожаловать, для продолжения введите свой логин:"<<endl;
	

	getline(cin, curr_user.login);
	cout << curr_user.login;
	getline(cin, curr_user.password);
	cout << curr_user.password;
	cout << "Здравствуйте, " << curr_user.name;

		getchar();
	
}

