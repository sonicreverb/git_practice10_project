#pragma once
#include <string>

using namespace std;

struct StudentAuthData
{
	string login;
	string password;
	string name_surname;
};

void StudentAuthMenu();