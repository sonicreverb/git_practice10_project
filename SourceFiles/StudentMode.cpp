#include <iostream>	
#include <string>
#include "../Headers/StudentMode.h"
#include "../Headers/TestMenuLib.h"
#include <random>
using namespace std;

void Training() {
	int test;
	cout << "Введите номер тренинга:" << endl;
	cout << "1) Циклы" << endl << "2) Массивы (одномерные и двумерные)" << endl << "3) Строки" << endl << "4) Рекурсия" << endl << "5) Структуры" << endl << "6) Файлы" << endl << "7) Адреса и указатели" << endl << "8) Динамическая память" << endl;
	cin >> test;
	switch (test)
	{
	case 1:TrainingOnTheme("CircleTest.txt"); break;
	case 2:TrainingOnTheme("ArrayTest.txt"); break;
	case 3:TrainingOnTheme("StringTest.txt"); break;
	case 4:TrainingOnTheme("RekursionTest.txt"); break;
	case 5:TrainingOnTheme("StructTest.txt"); break;
	case 6:TrainingOnTheme("FilesTest.txt"); break;
	case 7:TrainingOnTheme("PointerTest.txt"); break;
	case 8:TrainingOnTheme("DinMemory.txt"); break;
	case 0: break;
	}
}
void TopicTesting(string surname, string name, string patronymic, int id)
{
	int test;
	system("cls");
	cout << "Введите номер теста:" << endl;
	cout << "1) Циклы" << endl << "2) Массивы (одномерные и двумерные)" << endl << "3) Строки" << endl << "4) Рекурсия" << endl << "5) Структуры" << endl << "6) Файлы" << endl << "7) Адреса и указатели" << endl << "8) Динамическая память" << endl;
	cin >> test;
	switch (test)
	{
	case 1:TestingOnTheme("CircleTest.txt", surname, name, patronymic, id); break;
	case 2:TestingOnTheme("ArrayTest.txt", surname, name, patronymic, id); break;
	case 3:TestingOnTheme("StringTest.txt", surname, name, patronymic, id); break;
	case 4:TestingOnTheme("RekursionTest.txt", surname, name, patronymic, id); break;
	case 5:TestingOnTheme("StructTest.txt", surname, name, patronymic, id); break;
	case 6:TestingOnTheme("FilesTest.txt", surname, name, patronymic, id); break;
	case 7:TestingOnTheme("PointerTest.txt", surname, name, patronymic, id); break;
	case 8:TestingOnTheme("DinMemory.txt", surname, name, patronymic, id); break;
	case 0: break;
	}
}


void StudentAuthMenu()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number_of_students = 2;
	StudentData* students = new StudentData[number_of_students];

	students[0].login;
	students[0].name;
	students[0].surname;
	students[0].patronymic;
	students[0].password;
	students[0].id;

	string state = "run";

	do
	{
		StudentData curr_user;
		int curr_user_arr_id_in_database;

		system("cls");
		cout << "Добро пожаловать, для продолжения введите свой логин (чтобы вернуться в главное меню введите 0):" << endl;
		getline(cin, curr_user.login);
		// пользователь хочет вернуться в главное меню
		if (curr_user.login == "0") return;/*state = "shutdown"*/;

		string line;
		ifstream fileStudents("students_database.txt");
		if (!fileStudents.is_open()) {
			cout << "Ошибка открытия файла students_database.txt" << endl;
			system("pause");
			return;
		}

		vector<string> studentLines;
		while (getline(fileStudents, line)) {
			studentLines.push_back(line);
		}
		fileStudents.close();


		bool studentFound = false;
		for (size_t i = 0; i < studentLines.size(); ++i) {
			if (studentLines[i] == curr_user.login) {
				studentFound = true;
				curr_user.login = studentLines[i];
				curr_user.password = studentLines[i + 1];
				curr_user.surname = studentLines[i + 2];
				curr_user.name = studentLines[i + 3];
				curr_user.patronymic = studentLines[i + 4];
				curr_user.id = stoi(studentLines[i + 6]);
				break;
			}
		}

		if (!studentFound) {
			cout << "Студент не найден в базе данных." << endl;
			system("pause");
		}

		// пользователь вводит логин
		else
		{
			// пользователь существует
			cout << "Вы входите, как " << curr_user.name << " " << curr_user.patronymic << ".\n";

			string passw;
			int attemps_left = 3;
			do
			{
				cout << "Для продолжения введите пароль(чтобы выйти из учётной записи введите 0): ";
				getline(cin, passw);

				// отказ от ввода пароля, выход в меню авторизации
				if (passw == "0") StudentAuthMenu();
				;

				if (curr_user.password != passw)
				{
					attemps_left--;
					if (attemps_left)
					{
						cout << "Вы ввели неверный пароль, попробуйте снова." << "Осталось(ась) " << attemps_left << " попытки(ок/ка)." << endl;
					}

				}
			} while (curr_user.password != passw && attemps_left > 0);

			if (attemps_left == 0)
			{
				cout << "Вы не авторизировались.\n";
				system("pause");
				StudentAuthMenu();
				continue;
			}
			cout << "Вы авторизировались, как " << curr_user.surname << " " << curr_user.name << " " << curr_user.patronymic << endl;
			int choose;
			do {
				system("cls");
				cout << "Выберите род задания:" << endl << "1) Треннинг по теме" << endl << "2) Тестирование по теме" << endl << "3) Итоговый тест" << endl << "0) Выход из учётной записи" << endl;
				cin >> choose;
				switch (choose)
				{
				case 1:Training(); getchar();  break;
				case 2:TopicTesting(curr_user.surname, curr_user.name, curr_user.patronymic, curr_user.id); getchar(); break;
				case 3:FinalTest(curr_user.surname, curr_user.name, curr_user.patronymic, curr_user.id); getchar(); break;
				}
			} while (choose != 0);
			getchar();

		}


	} while (state != "shutdown");

}
