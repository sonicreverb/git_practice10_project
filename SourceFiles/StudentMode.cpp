#include <iostream>
#include <string>
#include "../Headers/StudentMode.h"
using namespace std;




void StudentAuthMenu()
{
	StudentData curr_user;
	cout << "Добро пожаловать, для продолжения введите свой логин:"<<endl;
	

	getline(cin, curr_user.login);
	cout << endl;
	getline(cin, curr_user.password);
	cout << endl;
	cout << "Здравствуйте, " << curr_user.name<<endl;
	


		getchar();
	
}

