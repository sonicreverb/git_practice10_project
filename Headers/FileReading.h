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

TeacherData* CheckTeacherList(TeacherData* teacherdata, int number);
StudentData* CheckStudentList(StudentData* studentdata, int number);
void TextDecryption(int number_of_text);//1 - student 2 - teacher 3 - test
void TextEncryption(int number_of_text);//1 - student 2 - teacher 3 - test
void AddStudent(StudentData* studentdata, int* number_of_students, TeacherData* teacherdata, int number_of_teachers, int current_teacher_number);//Just let me create these functions
void DeleteStudent(StudentData* studentdata, int* number_of_students, TeacherData* teacherdata, int number_of_teachers, int current_teacher_number);
void UpdateStudentBase(StudentData* studentdata, int number_of_students);//Use this function after every test to save student's progress in file
