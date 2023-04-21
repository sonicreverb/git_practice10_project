#include "../Headers/FileReading.h"

#define ABSPATH_TO_DATABASE "C:\\Users\\zaicz\\source\\repos\\Bruh10\\Bruh10\\git_practice10_project\\SourceFiles\\"


void UpdateStudentBase(StudentData* studentdata, int number_of_students)// use this function after every test to save student's progress in file
{
	FILE* file;
	int a = fopen_s(&file, ABSPATH_TO_DATABASE"students_database.txt", "wt");
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
	int a = fopen_s(&file, ABSPATH_TO_DATABASE"teacher_database.txt", "wt");
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
	/*TextEncryption(1);*/
}

int CheckTeacherListNumber()
{
	FILE* file;
	int a = fopen_s(&file, ABSPATH_TO_DATABASE"teacher_database.txt", "rt");
	int number;
	fscanf_s(file, "%d", &number);
	fclose(file);
	return number;
}
int CheckStudentListNumber()
{
	FILE* file;
	int a = fopen_s(&file, ABSPATH_TO_DATABASE"students_database.txt", "rt");
	int number;
	fscanf_s(file, "%d", &number);
	fclose(file);
	return number;
}
TeacherData* CheckTeacherList(TeacherData* teacherdata, int number)
{
	char string[100];
	FILE* file;
	int a = fopen_s(&file, ABSPATH_TO_DATABASE"teacher_database.txt", "rt");
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
}

StudentData* CheckStudentList(StudentData* studentdata, int number)
{
	char string[100];
	FILE* file;
	int a = fopen_s(&file, ABSPATH_TO_DATABASE"students_database.txt", "rt");
	fscanf_s(file, "%d%c", &number, &string[0]);
	for (int i = 0; i < number; i++)
	{
		studentdata = (StudentData*)realloc((void*)studentdata, (i + 1) * sizeof(StudentData));
		fscanf_s(file, "%c", &string[0]);
		fscanf_s(file, "%s", &studentdata[i].login);
		fscanf_s(file, "%s", &studentdata[i].password);
		fscanf_s(file, "%s", &studentdata[i].surname);
		fscanf_s(file, "%s", &studentdata[i].name);
		fscanf_s(file, "%s", &studentdata[i].patronymic);
		for (int j = 0; j < 9; j++)
		{
			fscanf_s(file, "%d", &studentdata[i].marks[j]);
		}
		fscanf_s(file, "%d", &studentdata[i].id);
		fscanf_s(file, "%c", &string[0]);
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
	case 1: a = fopen_s(&file, ABSPATH_TO_DATABASE"students_database.txt", "rt"); break;
	case 2: a = fopen_s(&file, ABSPATH_TO_DATABASE"teacher_database.txt", "rt"); break;
	default: a = fopen_s(&file, "Опыты.txt", "rt");
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
	case 1: a = fopen_s(&file, ABSPATH_TO_DATABASE"students_database.txt", "wt"); break;
	case 2: a = fopen_s(&file, ABSPATH_TO_DATABASE"teacher_database.txt", "wt"); break;
	default: a = fopen_s(&file, "Опыты.txt", "wt");
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
	case 1: a = fopen_s(&file, ABSPATH_TO_DATABASE"students_database.txt", "rt"); break;
	case 2: a = fopen_s(&file, ABSPATH_TO_DATABASE"teacher_database.txt", "rt"); break;
	default: a = fopen_s(&file, "Опыты.txt", "rt");
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
	case 1: a = fopen_s(&file, ABSPATH_TO_DATABASE"students_database.txt", "wt"); break;
	case 2: a = fopen_s(&file, ABSPATH_TO_DATABASE"teacher_database.txt", "wt"); break;
	default: a = fopen_s(&file, "Опыты.txt", "wt");
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
	cout << "Введите фамилию студента: ";
	cin >> studentdata[(*number_of_students) - 1].surname;
	system("cls");
	cout << "Введите имя студента: ";
	cin >> studentdata[(*number_of_students) - 1].name;
	system("cls");
	cout << "Введите отчество студента: ";
	cin >> studentdata[(*number_of_students) - 1].patronymic;
	system("cls");
	cout << "Введите логин студента: ";
	cin >> studentdata[(*number_of_students) - 1].login;
	system("cls");
	for (int i = 0; i < (*number_of_students) - 1; i++)
	{
		if (studentdata[(*number_of_students) - 1].login == studentdata[i].login)
		{
			cout << "Логин занят\nНажмите любую клавишу";
			(*number_of_students)--;
			studentdata = (StudentData*)realloc(studentdata, (*number_of_students) * sizeof(StudentData));
			char key = _getch();
			system("cls");
			return;
		}
	}
	cout << "Введите пароль студента: ";
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
	cout << "Введите логин студента: ";
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
		cout << "Студент с данным логином не найден";
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