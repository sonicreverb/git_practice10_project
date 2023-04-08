#include <iostream>
#include <string>
#include "../Headers/TeacherMode.h"

using namespace std;

void TeacherAuthMenu()
{
	int number_of_teachers = 2;
	TeacherData* teachers = new TeacherData[number_of_teachers];

	teachers[0].login = "kazemir32";
	teachers[1].login = "maxonpolyakov";
	
	TeacherData curr_user;
	cout << "Добро пожаловать, для продолжения введите свой логин:" << endl;
	getline(cin, curr_user.login);
	
	// проверка на существования логина в базе данных

	bool flag_teacher_exist = false;
	for (int arr_id = 0; arr_id < number_of_teachers; arr_id++)
	{
		if (teachers[arr_id].login == curr_user.login)
		{

		}
	}

	getchar();

}