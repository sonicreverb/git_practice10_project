#pragma once
#include <stdio.h>

#include "../Headers/TeacherMode.h"
#include "../Headers/StudentMode.h"
//#include "../Headers/FileReading.h"


int CheckTeacherListNumber();
int CheckStudentListNumber();

TeacherData* CheckTeacherList(TeacherData* teacherdata, int number);
StudentData* CheckStudentList(StudentData* studentdata, int number);
void TextDecryption(int number_of_text);//1 - student 2 - teacher 3 - test
void TextEncryption(int number_of_text);//1 - student 2 - teacher 3 - test
void AddStudent(StudentData* studentdata);//Just let me create these functions
void DeleteStudent();
void UpdateStudentBase(StudentData* studentdata);//Use this function after every test to save student's progress in file