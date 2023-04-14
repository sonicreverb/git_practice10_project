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
void TopicTesting(string surname, string name, string patronymic)
{
	int test;
	cout << "������� ����� �����:" << endl;
	cout << "1) �����" << endl << "2) ������� (���������� � ���������)" << endl << "3) ������" << endl << "4) ��������" << endl << "5) ���������" << endl << "6) �����" << endl << "7) ������ � ���������" << endl << "8) ������������ ������" << endl;
	cin >> test;
	switch (test)
	{
	case 1:TestingOnTheme("CircleTest.txt", surname, name, patronymic); break;
	case 2:TestingOnTheme("ArrayTest.txt", surname, name, patronymic); break;
	case 3:TestingOnTheme("StringTest.txt", surname, name, patronymic); break;
	case 4:TestingOnTheme("RekursionTest.txt", surname, name, patronymic); break;
	case 5:TestingOnTheme("StructTest.txt", surname, name, patronymic); break;
	case 6:TestingOnTheme("FilesTest.txt", surname, name, patronymic); break;
	case 7:TestingOnTheme("PointerTest.txt", surname, name, patronymic); break;
	case 8:TestingOnTheme("DinMemory.txt", surname, name, patronymic); break;
	case 0: break;
	}
}


void StudentAuthMenu()
{
	int number_of_students = 2;
	StudentData* students = new StudentData[number_of_students];

	students[0].login = "student32";
	students[0].name = "������";
	students[0].surname = "������";
	students[0].patronymic = "���������";
	students[0].password = "qwerty";

	students[1].login = "demidovlox";
	students[1].name = "����";
	students[1].patronymic = "������������";

	string state = "run";

	do
	{
		StudentData curr_user;
		int curr_user_arr_id_in_database;

		system("cls");
		cout << "����� ����������, ��� ����������� ������� ���� ����� (����� ��������� � ������� ���� ������� 0):" << endl;
		getline(cin, curr_user.login);

		// ������������ ����� ��������� � ������� ����
		if (curr_user.login == "0") state = "shutdown";

		// ������������ ������ �����
		else
		{
			// �������� �� ������������� ������ � ���� ������
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
				cout << "��������, ������������ " << curr_user.login << " �� ������.\n";
				cout << "������� ������� enter, ����� ����������.\n";

				continue;
			}

			// ������������ ����������
			cout << "�� �������, ��� " << students[curr_user_arr_id_in_database].name << " " << students[curr_user_arr_id_in_database].patronymic << ".\n";

			int attemps_left = 3;
			do
			{
				cout << "��� ����������� ������� ������(����� ����� �� ������� ������ ������� 0): ";
				getline(cin, curr_user.password);

				// ����� �� ����� ������, ����� � ���� �����������
				if (curr_user.password == "0") continue;

				if (curr_user.password != students[curr_user_arr_id_in_database].password)
				{
					if (attemps_left - 1 > 0)
					{
						cout << "�� ����� �������� ������, ���������� �����." << "��������(���) " << attemps_left - 1 << " �������(��/��)." << endl;
					}

				}
				attemps_left--;
			} while (curr_user.password != students[curr_user_arr_id_in_database].password && attemps_left > 0);

			if (attemps_left == 0)
			{
				cout << "�� �� ����������������.\n";
				cout << "������� ������� enter, ����� ����������.\n";

				continue;
			}
			curr_user = students[curr_user_arr_id_in_database];
			cout << "�� ����������������, ��� " << curr_user.surname << " " << curr_user.name << " " << curr_user.patronymic << endl;
			int choose;
			do {
				cout << "�������� ��� �������:" << endl << "1) �������� �� ����" << endl << "2) ������������ �� ����" << endl << "3) �������� ����" << endl << "0) ����� �� ������� ������" << endl;
				cin >> choose;
				switch (choose)
				{
				case 1:Training(); getchar();  break;
				case 2:TopicTesting(curr_user.surname, curr_user.name, curr_user.patronymic); getchar(); break;
				case 3:FinalTest(curr_user.surname, curr_user.name, curr_user.patronymic); getchar(); break;
				}
			} while (choose != 0);
			getchar();

		}


	} while (state != "shutdown");

}
