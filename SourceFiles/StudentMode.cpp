#include <iostream>	
#include <string>
#include "../Headers/StudentMode.h"
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


void StudentAuthMenu()
{
	StudentData curr_user;
	int choose;
	cout << "Добро пожаловать, для продолжения введите свой логин:" << endl;
	getline(cin, curr_user.login);
	cout << endl;
	getline(cin, curr_user.password);
	cout << endl;
	cout << "Здравствуйте, " << curr_user.name << endl;
	cout << "Выберите род задания:" << endl << "1) Треннинг по теме" << endl << "2) Тестирование по теме" << endl << "3) Итоговый тест" << endl;
	cin >> choose;
	switch (choose)
	{
	case 1:Trainig(); break;
	case 2:; break;
	case 3:; break;
	}
	getchar();
}


