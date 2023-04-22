#include <iostream>	
#include <string>
#include "../Headers/StudentMode.h"
#include "../Headers/TestMenuLib.h"
#include <random>
using namespace std;

void Training() {
	int test;
	cout << "������� ����� ��������:" << endl;
	cout << "1) �����" << endl << "2) ������� (���������� � ���������)" << endl << "3) ������" << endl << "4) ��������" << endl << "5) ���������" << endl << "6) �����" << endl << "7) ������ � ���������" << endl << "8) ������������ ������" << endl;
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
	cout << "������� ����� �����:" << endl;
	cout << "1) �����" << endl << "2) ������� (���������� � ���������)" << endl << "3) ������" << endl << "4) ��������" << endl << "5) ���������" << endl << "6) �����" << endl << "7) ������ � ���������" << endl << "8) ������������ ������" << endl;
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
		cout << "����� ����������, ��� ����������� ������� ���� ����� (����� ��������� � ������� ���� ������� 0):" << endl;
		getline(cin, curr_user.login);
		// ������������ ����� ��������� � ������� ����
		if (curr_user.login == "0") return;/*state = "shutdown"*/;

		string line;
		ifstream fileStudents("students_database.txt");
		if (!fileStudents.is_open()) {
			cout << "������ �������� ����� students_database.txt" << endl;
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
			cout << "������� �� ������ � ���� ������." << endl;
			system("pause");
		}

		// ������������ ������ �����
		else
		{
			// ������������ ����������
			cout << "�� �������, ��� " << curr_user.name << " " << curr_user.patronymic << ".\n";

			string passw;
			int attemps_left = 3;
			do
			{
				cout << "��� ����������� ������� ������(����� ����� �� ������� ������ ������� 0): ";
				getline(cin, passw);

				// ����� �� ����� ������, ����� � ���� �����������
				if (passw == "0") StudentAuthMenu();
				;

				if (curr_user.password != passw)
				{
					attemps_left--;
					if (attemps_left)
					{
						cout << "�� ����� �������� ������, ���������� �����." << "��������(���) " << attemps_left << " �������(��/��)." << endl;
					}

				}
			} while (curr_user.password != passw && attemps_left > 0);

			if (attemps_left == 0)
			{
				cout << "�� �� ����������������.\n";
				system("pause");
				StudentAuthMenu();
				continue;
			}
			cout << "�� ����������������, ��� " << curr_user.surname << " " << curr_user.name << " " << curr_user.patronymic << endl;
			int choose;
			do {
				system("cls");
				cout << "�������� ��� �������:" << endl << "1) �������� �� ����" << endl << "2) ������������ �� ����" << endl << "3) �������� ����" << endl << "0) ����� �� ������� ������" << endl;
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
