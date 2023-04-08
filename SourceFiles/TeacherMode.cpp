#include <iostream>
#include <string>

#include "../Headers/TeacherMode.h"
#include "../Headers/FileReading.h"

using namespace std;

void TeacherAuthMenu()
{
	int number_of_teachers = 2;
	TeacherData* teachers = new TeacherData[number_of_teachers];

	teachers[0].login = "kazemir32";
	teachers[0].name = "Каземир";
	teachers[0].surname = "Каземиров";
	teachers[0].patronymic = "Каземирович";
	teachers[0].password = "qwerty";

	teachers[1].login = "maxonpolyakov";
	teachers[1].name = "Максим";
	teachers[1].surname = "Поляков";
	teachers[1].patronymic = "Фенибутович";
	teachers[1].password = "bobus2";
	
	string state = "run";

	do
	{
		TeacherData curr_user;
		int curr_user_arr_id_in_database;

		system("cls");
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
				cout << "Нажмите любую клавишу, чтобы продолжить.\n";
				getchar();
				continue;
			}

			// пользователь существует
			cout << "Вы входите, как " << teachers[curr_user_arr_id_in_database].name << " " << teachers[curr_user_arr_id_in_database].patronymic << ".\n";

			int attemps_left = 3;
			do
			{
				cout << "Для продолжения введите пароль(чтобы выйти из учётной записи введите 0): ";
				getline(cin, curr_user.password);
				
				// отказ от ввода пароля, выход в меню авторизации
				if (curr_user.password == "0") continue;

				if (curr_user.password != teachers[curr_user_arr_id_in_database].password)
				{
					if (attemps_left - 1 > 0) 
					{
						cout << "Вы ввели неверный пароль, попробуйте снова." << "Осталось(ась) " << attemps_left - 1 << " попытки(ок/ка)." << endl;
					}
					
				}
				attemps_left--;
			} while (curr_user.password != teachers[curr_user_arr_id_in_database].password && attemps_left > 0);

			if (attemps_left == 0)
			{
				cout << "Вы не авторизировались.\n";
				cout << "Нажмите любую клавишу, чтобы продолжить.\n";
				getchar();
				continue;
			}

			int teacher_section_choose;
			int teacher_task_choose;
			// меню авторизованного учителя

			do
			{

				system("cls");
				curr_user = teachers[curr_user_arr_id_in_database];
				cout << "Вы авторизированы, как " << curr_user.surname << " " << curr_user.name << " " << curr_user.patronymic << endl;
				cout << "1. Редактирование вопросов." << endl << "2. Работа со списком студентов." << endl << "0. Выход из учётной записи" << endl;

				cout << "Выберите раздел меню: ";
				cin >> teacher_section_choose;


				switch (teacher_section_choose)
				{
				case 1:
					// редактирование вопросов
					cout << "1. Удаление." << endl << "2. Добавление." << endl << "3. Изменение.";
					cout << "Выберите задачу: ";
					cin >> teacher_task_choose;
					getchar();
					break;
				case 2:
					// работа со списком студентов
					cout << "1. Работа со списком студентов.\n2. Удаление и регистрация студентов.\n3. Изменение прогресса студентов.\n-- Вывод списка студентов с оценками \n4. -по всем темам\n5. -по конкретной теме\n";
					cout << "6. -только итоговый тест\n7. -только средний бал\n8. Фильтрация (по конкретным оценкам).\n9. Сортировка по конректным оценкам.";
					cout << "Выберите задачу: ";
					cin >> teacher_task_choose;
					getchar();
					break;
				default:
					cout << "Вы ввели некорректное значение. Для продолжения нажмите любую клавишу" << endl;
					getchar();
					break;
				}
			} while (teacher_section_choose != 0);
			
			
		}

	
	} while (state != "shutdown");
	

}