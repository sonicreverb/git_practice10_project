#pragma once
#include <string>

using namespace std;

struct TeacherData
{
	string login;
	string password;

	string name;
	string surname;
	string patronymic;

	int* id_students_arr;
	int numbers_of_students;
};

void TeacherAuthMenu();