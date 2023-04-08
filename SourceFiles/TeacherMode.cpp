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
	teachers[0].name = "�������";
	teachers[0].surname = "���������";
	teachers[0].patronymic = "�����������";
	teachers[0].password = "qwerty";

	teachers[1].login = "maxonpolyakov";
	teachers[1].name = "������";
	teachers[1].surname = "�������";
	teachers[1].patronymic = "�����������";
	teachers[1].password = "bobus2";
	
	string state = "run";

	do
	{
		TeacherData curr_user;
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
				cout << "��������, ������������ " << curr_user.login << " �� ������.\n";
				cout << "������� ����� �������, ����� ����������.\n";
				getchar();
				continue;
			}

			// ������������ ����������
			cout << "�� �������, ��� " << teachers[curr_user_arr_id_in_database].name << " " << teachers[curr_user_arr_id_in_database].patronymic << ".\n";

			int attemps_left = 3;
			do
			{
				cout << "��� ����������� ������� ������(����� ����� �� ������� ������ ������� 0): ";
				getline(cin, curr_user.password);
				
				// ����� �� ����� ������, ����� � ���� �����������
				if (curr_user.password == "0") continue;

				if (curr_user.password != teachers[curr_user_arr_id_in_database].password)
				{
					if (attemps_left - 1 > 0) 
					{
						cout << "�� ����� �������� ������, ���������� �����." << "��������(���) " << attemps_left - 1 << " �������(��/��)." << endl;
					}
					
				}
				attemps_left--;
			} while (curr_user.password != teachers[curr_user_arr_id_in_database].password && attemps_left > 0);

			if (attemps_left == 0)
			{
				cout << "�� �� ����������������.\n";
				cout << "������� ����� �������, ����� ����������.\n";
				getchar();
				continue;
			}

			int teacher_section_choose;
			int teacher_task_choose;
			// ���� ��������������� �������

			do
			{

				system("cls");
				curr_user = teachers[curr_user_arr_id_in_database];
				cout << "�� ��������������, ��� " << curr_user.surname << " " << curr_user.name << " " << curr_user.patronymic << endl;
				cout << "1. �������������� ��������." << endl << "2. ������ �� ������� ���������." << endl << "0. ����� �� ������� ������" << endl;

				cout << "�������� ������ ����: ";
				cin >> teacher_section_choose;


				switch (teacher_section_choose)
				{
				case 1:
					// �������������� ��������
					cout << "1. ��������." << endl << "2. ����������." << endl << "3. ���������.";
					cout << "�������� ������: ";
					cin >> teacher_task_choose;
					getchar();
					break;
				case 2:
					// ������ �� ������� ���������
					cout << "1. ������ �� ������� ���������.\n2. �������� � ����������� ���������.\n3. ��������� ��������� ���������.\n-- ����� ������ ��������� � �������� \n4. -�� ���� �����\n5. -�� ���������� ����\n";
					cout << "6. -������ �������� ����\n7. -������ ������� ���\n8. ���������� (�� ���������� �������).\n9. ���������� �� ���������� �������.";
					cout << "�������� ������: ";
					cin >> teacher_task_choose;
					getchar();
					break;
				default:
					cout << "�� ����� ������������ ��������. ��� ����������� ������� ����� �������" << endl;
					getchar();
					break;
				}
			} while (teacher_section_choose != 0);
			
			
		}

	
	} while (state != "shutdown");
	

}