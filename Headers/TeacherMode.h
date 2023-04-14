#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <locale>
#include <windows.h>
#include <set>

using namespace std;

struct TeacherData
{
	string login;
	string password;

	string name;
	string surname;
	string patronymic;

	int* id_students_arr;
	int numbers_of_students;
};

int FileOutput(vector<string> lines);
int QuestionDel(string Theme, vector<string> lines);
int QuestionEdit(string Theme, vector<string> lines);
int QuestionAdd(string Theme, vector<string> lines);
vector<string> fileParse(string Theme);
int QestionEditorPlace(string Theme);
int QestionEditorMenu();

void TeacherAuthMenu();