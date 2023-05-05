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
	file << number_of_students << "\n";
	for (int i = 0; i < number_of_students; i++)
	{
		file << "\n" << studentdata[i].login << "\n";
		file << studentdata[i].password << "\n";
		file << studentdata[i].surname << "\n";
		file << studentdata[i].name << "\n";
		file << studentdata[i].patronymic << "\n";
		for (int j = 0; j < 9; j++)file << studentdata[i].marks[j] << " ";
		file << "\n";
		file << studentdata[i].id << "\n";
	}
	file.close();

	/*TextEncryption(1);*/
}
void UpdateTeacherBase(TeacherData* teacherdata, int number_of_teachers, int id)// use this function after every test to save student's progress in file
{

	ofstream file("teacher_database.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла teacher_database.txt" << endl;
		system("pause");
		return;
	}
	file << number_of_teachers << "\n";
	for (int i = 0; i < number_of_teachers; i++)
	{
		file << "\n" << teacherdata[i].login << "\n";
		file << teacherdata[i].password << "\n";
		file << teacherdata[i].surname << "\n";
		file << teacherdata[i].name << "\n";
		file << teacherdata[i].patronymic << "\n";
		file << teacherdata[i].numbers_of_students << "\n";
		for (int j = 0; j < teacherdata[i].numbers_of_students; j++)
		{
			if (teacherdata[i].id_students_arr[j] > 0)file << teacherdata[i].id_students_arr[j] << " ";
			else file << id << " ";
		}
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
int CheckTeacherList(TeacherData* teacherdata, int number)
{
	/*TextDecryption(2);*/
	char str;
	int n;
	int f;
	int s;
	ifstream file("teacher_database.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла teacher_database.txt" << endl;
		system("pause");
		return NULL;
	}
	string line;
	vector <string> lines;
	while (getline(file, line)) {
		lines.push_back(line);
	}
	file.close();
	for (int i = 0; i < number; i++)
	{
		s = 0;

		teacherdata[i].login = lines[i * 8 + 2];
		teacherdata[i].password = lines[i * 8 + 3];
		teacherdata[i].surname = lines[i * 8 + 4];
		teacherdata[i].name = lines[i * 8 + 5];
		teacherdata[i].patronymic = lines[i * 8 + 6];
		for (int j = 0; j < lines[i * 8 + 7].size(); j++)s = s * 10 + int(lines[i * 8 + 7][j]) - 48;
		teacherdata[i].numbers_of_students = s;
		f = 0;
		for (int j = 0; j < s; j++)
		{
			n = 0;
			for (int k = f; lines[i * 8 + 8][k] != ' ' && lines[i * 8 + 8][k] != '\0'; k++)
			{
				n = n * 10 + int(lines[i * 8 + 8][k]) - 48;
				f++;
			}
			teacherdata[i].id_students_arr[j] = n;
			f++;
		}
	}
	return 1;
	/*TextEncryption(2);*/
}

int CheckStudentList(StudentData* studentdata, int number)
{
	/*TextDecryption(1);*/
	char str;
	int s;
	ifstream file("students_database.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла students_database.txt" << endl;
		system("pause");
		return NULL;
	}
	string line;
	vector <string> lines;
	while (getline(file, line)) {
		lines.push_back(line);
	}
	file.close();
	for (int i = 0; i < number; i++)
	{
		s = 0;

		studentdata[i].login = lines[i * 8 + 2];
		studentdata[i].password = lines[i * 8 + 3];
		studentdata[i].surname = lines[i * 8 + 4];
		studentdata[i].name = lines[i * 8 + 5];
		studentdata[i].patronymic = lines[i * 8 + 6];
		for (int j = 0; j < 17; j += 2)studentdata[i].marks[j % 2] = int(lines[i * 8 + 7][j]) - 48;
		for (int j = 0; j < lines[i * 8 + 8].size(); j++)s = s * 10 + int(lines[i * 8 + 8][j]) - 48;
		studentdata[i].id = s;
	}
	return 1;
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
	vector <string> lines;
	string line;
	char sym;
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
		}
		file.close();
	}
	}
	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = 0; j < lines[i].size(); j++)
		{
			lines[i][j]--;
		}
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
	vector <string> lines;
	string line;
	char sym;
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
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
		while (getline(file, line)) {
			lines.push_back(line);
		}
		file.close();
	}
	}
	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = 0; j < lines[i].size(); j++)
		{
			lines[i][j]++;
		}
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
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
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i];
			file << "\n";
		}
		file.close();
	}
	}
	return;
}