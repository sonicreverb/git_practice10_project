#pragma once
#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

#include "../Headers/TeacherMode.h"
#include "../Headers/StudentMode.h"
using namespace std;

int CheckTeacherListNumber();
int CheckStudentListNumber();

int CheckTeacherList(TeacherData* teacherdata, int number);
int CheckStudentList(StudentData* studentdata, int number);
void TextDecryption(int number_of_text);//1 - student 2 - teacher 3 - test
void TextEncryption(int number_of_text);//1 - student 2 - teacher 3 - test
void UpdateStudentBase(StudentData* studentdata, int number_of_students);//Use this function after every test to save student's progress in file
void UpdateTeacherBase(TeacherData* teacherdata, int number_of_teachers);
