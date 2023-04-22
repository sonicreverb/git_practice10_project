#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <set>
#include <Windows.h>
#include <sstream>

using namespace std;
int TrainingOnTheme(string Theme);
int TestingOnTheme(string Theme, string surname, string name, string patronymic, int id);
int FinalTest(string surname, string name, string patronymic, int id);
int MarkToBase(string Theme, int mark, string surname, string name, string patronymic, int* marks, int id);