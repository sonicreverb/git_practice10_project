#include <stdio.h>

#include "../Headers/TeacherMode.h"
#include "../Headers/StudentMode.h"
#include "../Headers/FileReading.h"

#define ABSPATH_TO_DATABASE "D:\\БГТУ\\Программирование\\Practice10_GroupProject\\git_practice10_project\\SourceFiles\\"


int CheckTeacherListNumber()
{
	FILE* file;
	int a = fopen_s(&file, ABSPATH_TO_DATABASE "teacher_database.txt", "rt");
	int number;
	fscanf_s(file, "%d", &number);
	fclose(file);
	return number;
}
int CheckStudentListNumber()
{
	FILE* file;
	int a = fopen_s(&file, ABSPATH_TO_DATABASE "students_database.txt", "rt");
	int number;
	fscanf_s(file, "%d", &number);
	fclose(file);
	return number;
}
TeacherData* CheckTeacherList(TeacherData* teacherdata, int number)
{
	char string[100];
	FILE* file;
	int a = fopen_s(&file, ABSPATH_TO_DATABASE "teacher_database.txt", "rt");
	fgets(string, 100, file);
	for (int i = 0; i < number; i++)
	{
		teacherdata = (TeacherData*)realloc((void*)teacherdata, (i + 1) * sizeof(TeacherData));
		fgets(string, 100, file);
		fscanf_s(file, "%s", &teacherdata[i].login);
		fscanf_s(file, "%s", &teacherdata[i].password);
		fscanf_s(file, "%s", &teacherdata[i].name);
		fscanf_s(file, "%s", &teacherdata[i].surname);
		fscanf_s(file, "%s", &teacherdata[i].patronymic);
		fscanf_s(file, "%d", &teacherdata[i].numbers_of_students);
		teacherdata[i].id_students_arr = (int*)malloc(teacherdata[i].numbers_of_students * sizeof(int));
		for (int j = 0; j < teacherdata[i].numbers_of_students; j++)
		{
			fscanf_s(file, "%d", &teacherdata[i].id_students_arr[j]);
		}
		fgets(string, 100, file);
	}
	fclose(file);
	return teacherdata;
}

StudentData* CheckStudentList(StudentData* studentdata, int number)
{
	char string[100];
	FILE* file;
	int a = fopen_s(&file, ABSPATH_TO_DATABASE "students_database.txt", "rt");
	fgets(string, 100, file);
	for (int i = 0; i < number; i++)
	{
		studentdata = (StudentData*)realloc((void*)studentdata, (i + 1) * sizeof(StudentData));
		fgets(string, 100, file);
		fscanf_s(file, "%s", &studentdata[i].login);
		fscanf_s(file, "%s", &studentdata[i].password);
		fscanf_s(file, "%s", &studentdata[i].name);
		fscanf_s(file, "%s", &studentdata[i].surname);
		fscanf_s(file, "%s", &studentdata[i].patronymic);
		fscanf_s(file, "%d", &studentdata[i].id);
		for (int j = 0; j < 11; j++)
		{
			fscanf_s(file, "%d", &studentdata[i].marks[j]);
		}
		fgets(string, 100, file);
	}
	fclose(file);
	return studentdata;
}

void TextDecryption(int number_of_text)//1 - student 2 - teacher 3 - test
{
	FILE* file;
	int a;
	switch (number_of_text)
	{
	case 1: a = fopen_s(&file, ABSPATH_TO_DATABASE "students_database.txt", "rt"); break;
	case 2: a = fopen_s(&file, ABSPATH_TO_DATABASE "teacher_database.txt", "rt"); break;
	default: a = fopen_s(&file, ABSPATH_TO_DATABASE "test_database.txt", "rt");
	}
	fclose(file);
}

void TextEncryption(int number_of_text)//1 - student 2 - teacher 3 - test
{
	FILE* file;
	int a;
	switch (number_of_text)
	{
	case 1: a = fopen_s(&file, ABSPATH_TO_DATABASE "students_database.txt", "rt"); break;
	case 2: a = fopen_s(&file, ABSPATH_TO_DATABASE "teacher_database.txt", "rt"); break;
	default: a = fopen_s(&file, ABSPATH_TO_DATABASE "test_database.txt", "rt");
	}
	fclose(file);
}

void AddStudent(StudentData* studentdata)//Just let me create these functions
{

}

void DeleteStudent()
{

}

void UpdateStudentBase(StudentData* studentdata)// use this function after every test to save student's progress in file
{

}