#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/FileReading.h"


void UpdateStudentBase(StudentData* studentdata, int number_of_students)// use this function after every test to save student's progress in file
{
	FILE* file;
	file = fopen("students_database.txt", "w");
	fprintf(file, "%d\n", number_of_students);
	for (int i = 0; i < number_of_students; i++)
	{
		fprintf(file, "\n%s\n", studentdata[i].login);
		fprintf(file, "%s\n", studentdata[i].password);
		fprintf(file, "%s\n", studentdata[i].surname);
		fprintf(file, "%s\n", studentdata[i].name);
		fprintf(file, "%s\n", studentdata[i].patronymic);
		for (int j = 0; j < 9; j++)fprintf(file, "%d ", studentdata[i].marks[j]);
		fprintf(file, "\n");
		fprintf(file, "%d\n", studentdata[i].id);
	}
	fclose(file);

	/*TextEncryption(1);*/
}
void UpdateTeacherBase(TeacherData* teacherdata, int number_of_teachers)// use this function after every test to save student's progress in file
{
	FILE* file;
	file = fopen("teacher_database.txt", "w");
	fprintf(file, "%d\n", number_of_teachers);
	for (int i = 0; i < number_of_teachers; i++)
	{
		fprintf(file, "\n%s\n", teacherdata[i].login);
		fprintf(file, "%s\n", teacherdata[i].password);
		fprintf(file, "%s\n", teacherdata[i].surname);
		fprintf(file, "%s\n", teacherdata[i].name);
		fprintf(file, "%s\n", teacherdata[i].patronymic);
		fprintf(file, "%d\n", teacherdata[i].numbers_of_students);
		for (int j = 0; j < teacherdata[i].numbers_of_students; j++)fprintf(file, "%d ", teacherdata[i].id_students_arr[j]);
		fprintf(file, "\n");
	}
	fclose(file);
	/*TextEncryption(2);*/
}

int CheckTeacherListNumber()
{
	/*TextDecryption(2);*/
	FILE* file;
	file = fopen("teacher_database.txt", "r");
	int number;
	fscanf_s(file, "%d", &number);
	fclose(file);
	return number;
	/*TextEncryption(2);*/
}
int CheckStudentListNumber()
{
	/*TextDecryption(1);*/
	FILE* file;
	file = fopen("students_database.txt", "r");
	int number;
	fscanf_s(file, "%d", &number);
	fclose(file);
	return number;
	/*TextEncryption(1);*/
}
TeacherData* CheckTeacherList(TeacherData* teacherdata, int number)
{
	/*TextDecryption(2);*/
	char string[100];
	FILE* file;
	file = fopen("teacher_database.txt", "r");
	fscanf_s(file, "%d%c", &number, &string[0]);
	for (int i = 0; i < number; i++)
	{
		teacherdata = (TeacherData*)realloc((void*)teacherdata, (i + 1) * sizeof(TeacherData));
		fscanf_s(file, "%c", &string[0]);
		fscanf_s(file, "%s", &teacherdata[i].login);
		fscanf_s(file, "%s", &teacherdata[i].password);
		fscanf_s(file, "%s", &teacherdata[i].surname);
		fscanf_s(file, "%s", &teacherdata[i].name);
		fscanf_s(file, "%s", &teacherdata[i].patronymic);
		fscanf_s(file, "%d", &teacherdata[i].numbers_of_students);
		teacherdata[i].id_students_arr = (int*)malloc(teacherdata[i].numbers_of_students * sizeof(int));
		for (int j = 0; j < teacherdata[i].numbers_of_students; j++)
		{
			fscanf_s(file, "%d", &teacherdata[i].id_students_arr[j]);
		}
		fscanf_s(file, "%c", &string[0]);
	}
	fclose(file);
	return teacherdata;
	/*TextEncryption(2);*/
}

StudentData* CheckStudentList(StudentData* studentdata, int number)
{
	/*TextDecryption(1);*/
	char string[100];
	FILE* file;
	file = fopen("students_database.txt", "r");
	fscanf(file, "%d%c", &number, &string[0]);
	for (int i = 0; i < number; i++)
	{
		studentdata = (StudentData*)realloc((void*)studentdata, (i + 1) * sizeof(StudentData));
		fscanf(file, "%c", &string[0]);
		fscanf(file, "%s", studentdata[i].login);
		fscanf(file, "%s", studentdata[i].password);
		fscanf(file, "%s", studentdata[i].surname);
		fscanf(file, "%s", studentdata[i].name);
		fscanf(file, "%s", studentdata[i].patronymic);
		for (int j = 0; j < 9; j++)
		{
			fscanf(file, "%d", &studentdata[i].marks[j]);
		}
		fscanf(file, "%d", &studentdata[i].id);
		fscanf(file, "%c", &string[0]);
	}
	fclose(file);
	return studentdata;
	/*TextEncryption(1);*/
}

void TextDecryption(int number_of_text)//1 - student 2 - teacher 3 - circle 4 - array 5 - string 6 - rekursion 7 - struct 8 - files 9 - pointer 10 - dinmemory
{
	FILE* file;
	switch (number_of_text)
	{
	case 1: file = fopen("students_database.txt", "r"); break;
	case 2: file = fopen("teacher_database.txt", "r"); break;
	case 3: file = fopen("CircleTest.txt", "r"); break;
	case 4: file = fopen("ArrayTest.txt", "r"); break;
	case 5: file = fopen("StringTest.txt", "r"); break;
	case 6: file = fopen("RekursionTest.txt", "r"); break;
	case 7: file = fopen("StructTest.txt", "r"); break;
	case 8: file = fopen("FilesTest.txt", "r"); break;
	case 9: file = fopen("PointerTest.txt", "r"); break;
	default: file = fopen("DinMemory.txt", "r");
	}
	char* string = (char*)malloc(sizeof(char));
	int i = 0;
	do
	{
		string = (char*)realloc(string, (i + 1) * sizeof(char));
		fscanf_s(file, "%c", &string[i]);
		i++;
	} while (string[i - 1] != '\0');
	fclose(file);
	for (int j = 0; j < i - 1; j++)
	{
		string[j]++;
	}
	switch (number_of_text)
	{
	case 1: file = fopen("students_database.txt", "w"); break;
	case 2: file = fopen("teacher_database.txt", "w"); break;
	case 3: file = fopen("CircleTest.txt", "w"); break;
	case 4: file = fopen("ArrayTest.txt", "w"); break;
	case 5: file = fopen("StringTest.txt", "w"); break;
	case 6: file = fopen("RekursionTest.txt", "w"); break;
	case 7: file = fopen("StructTest.txt", "w"); break;
	case 8: file = fopen("FilesTest.txt", "w"); break;
	case 9: file = fopen("PointerTest.txt", "w"); break;
	default: file = fopen("DinMemory.txt", "w");
	}
	for (int j = 0; j < i; j++)
	{
		fprintf(file, "%c", string[j]);
	}
	fclose(file);
}

void TextEncryption(int number_of_text)//1 - student 2 - teacher 3 - test
{
	FILE* file;
	int a;
	switch (number_of_text)
	{
	case 1: file = fopen("students_database.txt", "r"); break;
	case 2: file = fopen("teacher_database.txt", "r"); break;
	case 3: file = fopen("CircleTest.txt", "r"); break;
	case 4: file = fopen("ArrayTest.txt", "r"); break;
	case 5: file = fopen("StringTest.txt", "r"); break;
	case 6: file = fopen("RekursionTest.txt", "r"); break;
	case 7: file = fopen("StructTest.txt", "r"); break;
	case 8: file = fopen("FilesTest.txt", "r"); break;
	case 9: file = fopen("PointerTest.txt", "r"); break;
	default: file = fopen("DinMemory.txt", "r");
	}
	char* string = (char*)malloc(sizeof(char));
	int i = 0;
	do
	{
		string = (char*)realloc(string, (i + 1) * sizeof(char));
		fscanf_s(file, "%c", &string[i]);
		i++;
	} while (string[i - 1] != '\0');
	fclose(file);
	for (int j = 0; j < i - 1; j++)
	{
		string[j]--;
	}
	switch (number_of_text)
	{
	case 1: file = fopen("students_database.txt", "w"); break;
	case 2: file = fopen("teacher_database.txt", "w"); break;
	case 3: file = fopen("CircleTest.txt", "w"); break;
	case 4: file = fopen("ArrayTest.txt", "w"); break;
	case 5: file = fopen("StringTest.txt", "w"); break;
	case 6: file = fopen("RekursionTest.txt", "w"); break;
	case 7: file = fopen("StructTest.txt", "w"); break;
	case 8: file = fopen("FilesTest.txt", "w"); break;
	case 9: file = fopen("PointerTest.txt", "w"); break;
	default: file = fopen("DinMemory.txt", "w");
	}
	for (int j = 0; j < i; j++)
	{
		fprintf(file, "%c", string[j]);
	}
	fclose(file);
}

void AddStudent(StudentData* studentdata, int* number_of_students, TeacherData* teacherdata, int number_of_teachers, int current_teacher_number)//Just let me create these functions
{
	(*number_of_students)++;
	studentdata = (StudentData*)realloc(studentdata, (*number_of_students) * sizeof(StudentData));
	system("cls");
	cout << "������� ������� ��������: ";
	cin >> studentdata[(*number_of_students) - 1].surname;
	system("cls");
	cout << "������� ��� ��������: ";
	cin >> studentdata[(*number_of_students) - 1].name;
	system("cls");
	cout << "������� �������� ��������: ";
	cin >> studentdata[(*number_of_students) - 1].patronymic;
	system("cls");
	cout << "������� ����� ��������: ";
	cin >> studentdata[(*number_of_students) - 1].login;
	system("cls");
	for (int i = 0; i < (*number_of_students) - 1; i++)
	{
		if (studentdata[(*number_of_students) - 1].login == studentdata[i].login)
		{
			cout << "����� �����\n������� ����� �������";
			(*number_of_students)--;
			studentdata = (StudentData*)realloc(studentdata, (*number_of_students) * sizeof(StudentData));
			char key = _getch();
			system("cls");
			return;
		}
	}
	cout << "������� ������ ��������: ";
	cin >> studentdata[(*number_of_students) - 1].password;
	for (int i = 0; i < 9; i++)studentdata[(*number_of_students) - 1].marks[i] = 0;
	studentdata[(*number_of_students) - 1].id = studentdata[(*number_of_students) - 2].id + 1;
	UpdateStudentBase(studentdata, *number_of_students);
	teacherdata[current_teacher_number].numbers_of_students++;
	teacherdata[current_teacher_number].id_students_arr = (int*)realloc(teacherdata[current_teacher_number].id_students_arr, (teacherdata[current_teacher_number].numbers_of_students) * sizeof(int));
	teacherdata[current_teacher_number].id_students_arr[teacherdata[current_teacher_number].numbers_of_students - 1] = studentdata[(*number_of_students) - 1].id;
	UpdateTeacherBase(teacherdata, number_of_teachers);
	system("cls");
	return;
}

void DeleteStudent(StudentData* studentdata, int* number_of_students, TeacherData* teacherdata, int number_of_teachers, int current_teacher_number)
{
	string login;
	system("cls");
	cout << "������� ����� ��������: ";
	cin >> login;
	int t = 0;
	int delited_number;
	for (int i = 0; i < (*number_of_students); i++)if (login == studentdata[i].login)
	{

		t++;
		delited_number = i;
	}
	if (!t)
	{
		system("cls");
		cout << "������� � ������ ������� �� ������";
		char key = _getch();
		return;
	}
	int d_id = studentdata[delited_number].id;
	int i = 0;
	do
	{
		i++;
	} while (teacherdata[current_teacher_number].id_students_arr[i] != d_id);
	teacherdata[current_teacher_number].numbers_of_students--;
	for (int j = i; i < teacherdata[current_teacher_number].numbers_of_students; j++)
	{
		teacherdata[current_teacher_number].id_students_arr[j] = teacherdata[current_teacher_number].id_students_arr[j + 1];
	}
	for (int i = delited_number; i < (*number_of_students) - 1; i++)studentdata[i] = studentdata[i + 1];
	(*number_of_students)--;
	studentdata = (StudentData*)realloc(studentdata, (*number_of_students) * sizeof(StudentData));
	UpdateStudentBase(studentdata, *number_of_students);
	UpdateTeacherBase(teacherdata, number_of_teachers);
	system("cls");
	return;
}