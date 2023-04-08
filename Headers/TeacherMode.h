#pragma once
#include <string>

using namespace std;

struct TeacherAuthData
{
	string login;
	string password;
	string name_surname;
};

void TeacherAuthMenu();