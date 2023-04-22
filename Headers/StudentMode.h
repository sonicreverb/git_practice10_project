#pragma once
#include <string>
#include <Windows.h>

using namespace std;

struct StudentData
{
	string login;
	string password;
	string name;
	string surname;
	string patronymic;

	int id;
	int numbers_of_marks;
	int marks[256];
	
	double avg_mark;
};


void StudentAuthMenu();

void Training();
void TopicTesting(string surname, string name, string patronymic);