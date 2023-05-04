#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/FileReading.h"


void UpdateStudentBase(StudentData* studentdata, int number_of_students)// use this function after every test to save student's progress in file
{
	ofstream file("students_database.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла students_database.txt" << endl;
		system("pause");
		return;
	}
	file << number_of_students;
	for (int i = 0; i < number_of_students; i++)
	{
		file << studentdata[i].login;
		file << studentdata[i].password;
		file << studentdata[i].surname;
		file << studentdata[i].name;
		file << studentdata[i].patronymic;
		for (int j = 0; j < 9; j++)file << studentdata[i].marks[j];
		file << "\n";
		file << studentdata[i].id << "\n";
	}
	file.close();

	/*TextEncryption(1);*/
}
void UpdateTeacherBase(TeacherData* teacherdata, int number_of_teachers)// use this function after every test to save student's progress in file
{
	ofstream file("teacher_database.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла teacher_database.txt" << endl;
		system("pause");
		return;
	}
	file << number_of_teachers;
	for (int i = 0; i < number_of_teachers; i++)
	{
		file << teacherdata[i].login;
		file << teacherdata[i].password;
		file << teacherdata[i].surname;
		file << teacherdata[i].name;
		file << teacherdata[i].patronymic;
		file << teacherdata[i].numbers_of_students;
		for (int j = 0; j < teacherdata[i].numbers_of_students; j++)file << teacherdata[i].id_students_arr[j];
		file << "\n";
	}
	file.close();
	/*TextEncryption(2);*/
}

int CheckTeacherListNumber()
{
	/*TextDecryption(2);*/
	ifstream file("teacher_database.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла teacher_database.txt" << endl;
		system("pause");
		return 0;
	}
	int number;
	file >> number;
	file.close();
	return number;
	/*TextEncryption(2);*/
}
int CheckStudentListNumber()
{
	/*TextDecryption(1);*/
	ifstream file("students_database.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла students_database.txt" << endl;
		system("pause");
		return 0;
	}
	int number;
	file >> number;
	file.close();
	return number;
	/*TextEncryption(1);*/
}
TeacherData* CheckTeacherList(TeacherData* teacherdata, int number)
{
	/*TextDecryption(2);*/
	char string;
	ifstream file("teacher_database.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла teacher_database.txt" << endl;
		system("pause");
		return NULL;
	}
	file >> number >> string;

	for (int i = 0; i < number; i++)
	{
		teacherdata = (TeacherData*)realloc((void*)teacherdata, (i + 1) * sizeof(TeacherData));
		file >> string;
		file >> teacherdata[i].login;
		file >> teacherdata[i].password;
		file >> teacherdata[i].surname;
		file >> teacherdata[i].name;
		file >> teacherdata[i].patronymic;
		file >> teacherdata[i].numbers_of_students;
		teacherdata[i].id_students_arr = (int*)malloc(teacherdata[i].numbers_of_students * sizeof(int));
		for (int j = 0; j < teacherdata[i].numbers_of_students; j++)
		{
			file >> teacherdata[i].id_students_arr[j];
		}
		file >> string;
	}
	file.close();
	return teacherdata;
	/*TextEncryption(2);*/
}

StudentData* CheckStudentList(StudentData* studentdata, int number)
{
	/*TextDecryption(1);*/
	char string;
	ifstream file("students_database.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла students_database.txt" << endl;
		system("pause");
		return NULL;
	}
	file >> number >> string;
	for (int i = 0; i < number; i++)
	{
		studentdata = (StudentData*)realloc((void*)studentdata, (i + 1) * sizeof(StudentData));
		file >> string;
		file >> studentdata[i].login;
		file >> studentdata[i].password;
		file >> studentdata[i].surname;
		file >> studentdata[i].name;
		file >> studentdata[i].patronymic;
		for (int j = 0; j < 9; j++)
		{
			file >> studentdata[i].marks[j];
		}
		file >> studentdata[i].id;
		file >> string;
	}
	file.close();
	return studentdata;
	/*TextEncryption(1);*/
}
//1 - student
//2 - teacher 
//3 - circle 
//4 - array 
//5 - string 
//6 - rekursion 
//7 - struct 
//8 - files 
//9 - pointer 
//10 - dinmemory
void TextDecryption(int number_of_text)
{
	vector <char> symbol;
	char sym;
	int i = 0;
	switch (number_of_text)
	{
	case 1:
	{
		ifstream file("students_database.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла students_database.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 2:
	{
		ifstream file("teacher_database.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла teacher_database.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 3:
	{
		ifstream file("CircleTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла CircleTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 4:
	{
		ifstream file("ArrayTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла ArrayTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 5:
	{
		ifstream file("StringTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла StringTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 6:
	{
		ifstream file("RekursionTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла RekursionTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 7:
	{
		ifstream file("StructTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла StructTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 8:
	{
		ifstream file("FilesTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла FilesTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 9:
	{
		ifstream file("PointerTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла PointerTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	default:
	{
		ifstream file("DinMemory.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла DinMemory.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}
	}
	for (int j = 0; j < i - 1; j++)
	{
		symbol[j]--;
	}
	switch (number_of_text)
	{
	case 1:
	{
		ofstream file("students_database.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла students_database.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 2:
	{
		ofstream file("teacher_database.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла teacher_database.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 3:
	{
		ofstream file("CircleTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла CircleTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 4:
	{
		ofstream file("ArrayTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла ArrayTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 5:
	{
		ofstream file("StringTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла StringTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 6:
	{
		ofstream file("RekursionTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла RekursionTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 7:
	{
		ofstream file("StructTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла StructTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 8:
	{
		ofstream file("FilesTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла FilesTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 9:
	{
		ofstream file("PointerTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла PointerTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	default:
	{
		ofstream file("DinMemory.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла DinMemory.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}
	}
	return;
}

//1 - student
//2 - teacher 
//3 - circle 
//4 - array 
//5 - string 
//6 - rekursion 
//7 - struct 
//8 - files 
//9 - pointer 
//10 - dinmemory
void TextEncryption(int number_of_text)//1 - student 2 - teacher 3 - circle 4 - array 5 - string 6 - rekursion 7 - struct 8 - files 9 - pointer 10 - dinmemory
{
	vector <char> symbol;
	char sym;
	int i = 0;
	switch (number_of_text)
	{
	case 1:
	{
		ifstream file("students_database.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла students_database.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 2:
	{
		ifstream file("teacher_database.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла teacher_database.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 3:
	{
		ifstream file("CircleTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла CircleTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 4:
	{
		ifstream file("ArrayTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла ArrayTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 5:
	{
		ifstream file("StringTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла StringTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 6:
	{
		ifstream file("RekursionTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла RekursionTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 7:
	{
		ifstream file("StructTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла StructTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 8:
	{
		ifstream file("FilesTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла FilesTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	case 9:
	{
		ifstream file("PointerTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла PointerTest.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}break;
	default:
	{
		ifstream file("DinMemory.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла DinMemory.txt" << endl;
			system("pause");
			return;
		}
		file >> sym;
		while (sym)
		{
			symbol.push_back(sym);
			i++;
		}
		file.close();
	}
	}
	for (int j = 0; j < i - 1; j++)
	{
		symbol[j]++;
	}
	switch (number_of_text)
	{
	case 1:
	{
		ofstream file("students_database.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла students_database.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 2:
	{
		ofstream file("teacher_database.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла teacher_database.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 3:
	{
		ofstream file("CircleTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла CircleTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 4:
	{
		ofstream file("ArrayTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла ArrayTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 5:
	{
		ofstream file("StringTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла StringTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 6:
	{
		ofstream file("RekursionTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла RekursionTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 7:
	{
		ofstream file("StructTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла StructTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 8:
	{
		ofstream file("FilesTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла FilesTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	case 9:
	{
		ofstream file("PointerTest.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла PointerTest.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}break;
	default:
	{
		ofstream file("DinMemory.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла DinMemory.txt" << endl;
			system("pause");
			return;
		}
		for (int j = 0; j < i; j++)
		{
			file << symbol[j];
		}
		file.close();
	}
	}
	return;
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