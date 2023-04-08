#pragma once
#include <stdio.h>

#include "../Headers/TeacherMode.h"
#include "../Headers/StudentMode.h"
#include "../Headers/FileReading.h"


int CheckTeacherListNumber();
int CheckStudentListNumber();

TeacherData* CheckTeacherList(TeacherData* teacherdata, int number);
StudentData* CheckStudentList(StudentData* studentdata, int number);