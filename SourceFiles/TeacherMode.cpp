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
	cout << "����� ����������, ��� ����������� ������� ���� �����:" << endl;
	getline(cin, curr_user.login);
	
	// �������� �� ������������� ������ � ���� ������

	bool flag_teacher_exist = false;
	for (int arr_id = 0; arr_id < number_of_teachers; arr_id++)
	{
		if (teachers[arr_id].login == curr_user.login)
		{

		}
	}

	getchar();

}