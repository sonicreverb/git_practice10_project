#include <iostream>
#include <string>
#include "../Headers/TeacherMode.h"

using namespace std;

void TeacherAuthMenu()
{
	int number_of_teachers = 2;
	TeacherData* teachers = new TeacherData[number_of_teachers];

	teachers[0].login = "kazemir32";
	teachers[0].name = "Каземир";
	teachers[0].patronymic = "Каземирович";

	teachers[1].login = "maxonpolyakov";
	teachers[1].name = "Максим";
	teachers[1].patronymic = "Козельскорожденнович";
	
	string state = "run";

	do
	{
		TeacherData curr_user;
		int curr_user_arr_id_in_database;

		cout << "Добро пожаловать, для продолжения введите свой логин (чтобы вернуться в главное меню введите 0):" << endl;
		getline(cin, curr_user.login);

		// пользователь хочет вернуться в главное меню
		if (curr_user.login == "0") state = "shutdown";

		// пользователь вводит логин
		else
		{
			// проверка на существования логина в базе данных
			bool flag_teacher_exist = false;
			for (int arr_id = 0; arr_id < number_of_teachers; arr_id++)
			{
				if (teachers[arr_id].login == curr_user.login)
				{
					flag_teacher_exist = true;
					curr_user_arr_id_in_database = arr_id;
					break;
				}
			}

			if (!flag_teacher_exist)
			{
				cout << "Извините, пользователь " << curr_user.login << " не найден.\n";
				continue;
			}

			// пользователь существует
			cout << "Вы входите, как " << teachers[curr_user_arr_id_in_database].name << " " << teachers[curr_user_arr_id_in_database].patronymic << ".\n";
			cout << "Для продолжения введите пароль: ";
			getline(cin, curr_user.login);

		}

	
	} while (state != "shutdown");
	

}