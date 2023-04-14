#pragma once
#include <string>

using namespace std;

struct StudentData
{
	string login;
	string password;
	string name;
	string surname;
	string patronymic;
	int id;
	int marks[11];
};


void StudentAuthMenu();

void Training();
void TopicTesting(string surname, string name, string patronymic);