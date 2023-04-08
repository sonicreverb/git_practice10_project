#include <iostream>	
#include <string>
#include "../Headers/StudentMode.h"
#include <random>
using namespace std;

void Trainig() {
	int test;
	cout << "Введите номер теста:" << endl;
	cout << "1) Циклы" << endl << "2) Массивы (одномерные и двумерные)" << endl << "3) Строки" << endl << "4) Рекурсия" << endl << "5) Файлы" << endl << "6) Адреса и указатели" << endl << "7) Динамическая память" << endl;
	cin >> test;
	switch (test)
	{
	case 1:; break;
	case 2:; break;
	case 3:; break;
	case 4:; break;
	case 5:; break;
	case 6:; break;
	case 7:; break;
	case 0:; break;
	}
}
void TopicTesting()
{
	}

void FinalTest()
{

}

void StudentAuthMenu()
{
	int number_of_students = 2;
	StudentData* students = new StudentData[number_of_students];

	students[0].login = "student32";
	students[0].name = "Владимир";
	students[0].surname = "Кулебяка";
	students[0].patronymic = "Иванович";
	students[0].password = "qwerty";

	students[1].login = "demidovlox";
	students[1].name = "Илья";
	students[1].patronymic = "Владимирович";

	string state = "run";

	do
	{
		StudentData curr_user;
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
			bool flag_student_exist = false;
			for (int arr_id = 0; arr_id < number_of_students; arr_id++)
			{
				if (students[arr_id].login == curr_user.login)
				{
					flag_student_exist = true;
					curr_user_arr_id_in_database = arr_id;
					break;
				}
			}

			if (!flag_student_exist)
			{
				cout << "Извините, пользователь " << curr_user.login << " не найден.\n";
				cout << "Нажмите клавишу enter, чтобы продолжить.\n";
				
				continue;
			}

			// пользователь существует
			cout << "Вы входите, как " << students[curr_user_arr_id_in_database].name << " " << students[curr_user_arr_id_in_database].patronymic << ".\n";

			int attemps_left = 3;
			do
			{
				cout << "Для продолжения введите пароль(чтобы выйти из учётной записи введите 0): ";
				getline(cin, curr_user.password);

				// отказ от ввода пароля, выход в меню авторизации
				if (curr_user.password == "0") continue;

				if (curr_user.password != students[curr_user_arr_id_in_database].password)
				{
					if (attemps_left - 1 > 0)
					{
						cout << "Вы ввели неверный пароль, попробуйте снова." << "Осталось(ась) " << attemps_left - 1 << " попытки(ок/ка)." << endl;
					}

				}
				attemps_left--;
			} while (curr_user.password != students[curr_user_arr_id_in_database].password && attemps_left > 0);

			if (attemps_left == 0)
			{
				cout << "Вы не авторизировались.\n";
				cout << "Нажмите клавишу enter, чтобы продолжить.\n";
				
				continue;
			}
			curr_user = students[curr_user_arr_id_in_database];
			cout << "Вы авторизировались, как " << curr_user.surname << " " << curr_user.name << " " << curr_user.patronymic << endl;
			
			int choose;
			do{cout << "Выберите род задания:" << endl << "1) Треннинг по теме" << endl << "2) Тестирование по теме" << endl << "3) Итоговый тест" << endl << "0) Выход из учётной записи" << endl;
			cin >> choose;
			switch (choose)
			{
			case 1:Trainig(); getchar();  break;
			case 2:TopicTesting(); getchar(); break;
			case 3:FinalTest(); getchar(); break;
			}
			} while (choose != 0);
			getchar();

		}
		

	} while (state != "shutdown");
	
}


