#include "../Headers/TeacherMode.h"
#include "../Headers/FileReading.h"

#define DATABASE_LOCATION_VOLUME_NAME "D:"
#define ABSPATH_TO_DATABASE "D:\\БГТУ\\Программирование\\Practice10_GroupProject\\git_practice10_project\\SourceFiles\\"

int FileOutput(vector<string> lines)
{
	int i = 1;
	for (auto& str : lines) {
		if (!str.empty()) {
			cout << "QUESTION #" << i << "  ";
			cout << str.substr(0, str.size()) << endl;
			i++;
		}
	}
	cout << endl;
	return 0;
}

int QuestionDel(string Theme, vector<string> lines)
{
	FileOutput(lines);
	int lineNumber;
	cout << "Выберите номер вопроса для удаления(0 - выход): ";
	cin >> lineNumber;
	lineNumber--;
	if (lineNumber >= 0 && lineNumber < lines.size()) {
		lines.erase(lines.begin() + lineNumber);
		ofstream fileOut(Theme);
		if (fileOut.is_open()) {
			for (int i = 0; i < lines.size(); i++) {
				fileOut << lines[i] << endl;
			}
			fileOut.close();
		}
		else {
			cout << "Ошибка при открытии файла." << endl;
			return 1;
		}
		cout << "Готово." << endl;
	}
	else {
		cout << "Неверный номер вопроса." << endl;
		return 1;
	}
	return 0;
}

int QuestionEdit(string Theme, vector<string> lines)
{
	FileOutput(lines);

	int LineNumber;
	cout << "Выберите номер вопроса для редактирования(0 - выход): ";
	cin >> LineNumber;
	LineNumber--;
	if (LineNumber >= 0 && LineNumber < lines.size()) {
		string editedLine;
		cout << "Новый вариант вопроса: ";
		if (!isdigit(editedLine.back())) {
			cout << "Последний символ нового варианта вопроса должен быть его ответом, то есть, цифрой." << endl;
			return 1;
		}
		lines[LineNumber] = editedLine;
		ofstream fileOut(Theme);
		if (fileOut.is_open()) {
			for (int i = 0; i < lines.size(); i++) {
				fileOut << lines[i] << endl;
			}
			fileOut.close();
		}
		else {
			cout << "Ошибка при открытии файла." << endl;
			system("pause");
			return 1;
		}
		cout << "Готово." << endl;
	}
	else {
		cout << "Неверный номер вопроса." << endl;
		return 1;
	}
	return 0;
}

int QuestionAdd(string Theme, vector<string> lines)
{
	FileOutput(lines);

	string newLine;
	cout << "Новый вопрос: ";

	cin.ignore();
	getline(cin, newLine);

	if (!isdigit(newLine.back())) {
		cout << "Последний символ нового вопроса должен быть его ответом, то есть, цифрой." << endl;
		return 1;
	}

	lines.push_back(newLine);

	ofstream fileOut(Theme);
	if (fileOut.is_open()) {
		for (int i = 0; i < lines.size(); i++) {
			fileOut << lines[i] << endl;
		}
		fileOut.close();
	}
	else {
		cout << "Ошибка при открытии файла." << endl;
		return 1;
	}
	cout << "Готово." << endl;
	return 0;
}

vector<string> fileParse(string Theme)
{
	string line;
	vector<string> lines;

	ifstream fileInp(Theme);
	if (!fileInp.is_open()) {
		cout << "Ошибка при открытии файла" << endl;
		system("pause");
		return lines;
	}

	while (getline(fileInp, line)) {
		lines.push_back(line);
	}
	fileInp.close();
	return lines;
}

int QestionEditorPlace(string Theme)
{
	vector<string> lines = fileParse(Theme);

	int switcher;

	do
	{
		system("cls");
		cout << "Выберите действие: " << endl << "1 - Удалить вопрос" << endl << "2 - Редактировать вопрос" << endl << "3 - Добавить вопрос" << endl << "4 - Вывести перечень вопросов" << endl << "0 - Выйти в меню выбора темы" << endl;
		cin >> switcher;
		switch (switcher) {
		case 1: system("cls"); QuestionDel(Theme, lines); system("pause"); system("cls"); lines = fileParse(Theme); break;
		case 2: system("cls"); QuestionEdit(Theme, lines); system("pause"); system("cls"); lines = fileParse(Theme); break;
		case 3: system("cls"); QuestionAdd(Theme, lines); system("pause"); system("cls"); lines = fileParse(Theme); break;
		case 4: system("cls"); FileOutput(lines); system("pause"); system("cls"); break;
		case 0: break;
		default: cout << "Несуществующий вариат." << endl;
		}
	} while (switcher != 0);
	return 0;
}

int QestionEditorMenu()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string Theme;
	int switcher;
	do
	{
		system("cls");
		cout << "Выберите тему для редактирования перечня вопросов:" << endl << endl << "1 - Циклы\n2 - Массивы\n3 - Строки\n4 - Рекурсия\n5 - Структуры\n6 - Файлы\n7 - Адреса и указатели\n8 - Динамическая память\n0 - Выйти из редактора вопросов\n--> ";
		cin >> switcher;
		switch (switcher)
		{
		case 1: QestionEditorPlace("CircleTest.txt"); break;
		case 2: QestionEditorPlace("ArrayTest.txt"); break;
		case 3: QestionEditorPlace("StringTest.txt"); break;
		case 4: QestionEditorPlace("RekursionTest.txt"); break;
		case 5: QestionEditorPlace("StructTest.txt"); break;
		case 6: QestionEditorPlace("FilesTest.txt"); break;
		case 7: QestionEditorPlace("PointerTest.txt"); break;
		case 8: QestionEditorPlace("DinMemory.txt"); break;
		case 0: break;
		default: cout << "Несуществующий вариант";
		}
	} while (switcher != 0);

	setlocale(LC_ALL, "Rus");
	return 0;
}

//TODO ILIAS
void DelAndRegStudents()
{

}

void EditStudentsProgress()
{
	system("cls");
	system(DATABASE_LOCATION_VOLUME_NAME);
	system("cd " ABSPATH_TO_DATABASE "students_database.txt");
}

void ShowStudensList(int mode_id, StudentData* student_data, int students_quantity)
{
	system("cls");

	switch (mode_id)
	{
	case(1):
		// по всем темам
		for (int student_num = 0; student_num < students_quantity; student_num++)
		{
			cout << "Пользователь #" << student_data[student_num].id << " " << student_data[student_num].login << endl;
			cout << student_data[student_num].surname << " " << student_data[student_num].name << " " << student_data[student_num].patronymic << endl;
			cout << "Оценки по всем темам:" << endl;

			for (int mark_id = 0; mark_id < student_data[student_num].numbers_of_marks; mark_id++)
			{
				cout << student_data[student_num].marks[mark_id] << endl;
			}
			cout << "\n";
		}
		break;

	case(2):
		// определённый тест

		int s_test_id;
		double test_id;

		cout << "Введите номер п/п теста:" << endl;
		cin >> test_id;

		while (test_id != round(test_id) || test_id <= 0)
		{
			cout << "Некорретное значение, повторите ввод:" << endl;
			cin >> test_id;
		} s_test_id = (int)test_id;

		for (int student_num = 0; student_num < students_quantity; student_num++)
		{
			cout << "Пользователь #" << student_data[student_num].id << " " << student_data[student_num].login << endl;
			cout << student_data[student_num].surname << " " << student_data[student_num].name << " " << student_data[student_num].patronymic << endl;
			cout << "Тест #" << s_test_id << ":" << endl;

			if (s_test_id > student_data->numbers_of_marks) 
			{
				cout << "Студент не выполнял тест #" << s_test_id << ".\n";
			}
			else
			{
				if (student_data[student_num].marks[s_test_id - 1] == 0) cout << "Студент не выполнял тест #" << s_test_id << ".\n";
				else
				{
					cout << student_data[student_num].marks[s_test_id - 1] << endl;
				}
			}
			cout << "\n";
		}
		break;

	case(3):
		// итоговый тест

		for (int student_num = 0; student_num < students_quantity; student_num++)
		{
			cout << "Пользователь #" << student_data[student_num].id << " " << student_data[student_num].login << endl;
			cout << student_data[student_num].surname << " " << student_data[student_num].name << " " << student_data[student_num].patronymic << endl;
			cout << "Итоговый тест:" << endl;

			if (student_data[student_num].marks[student_data[student_num].numbers_of_marks - 1] == 0) cout << "Студент не выполнял итоговый тест.\n";
			else
			{
				cout << student_data[student_num].marks[student_data[student_num].numbers_of_marks - 1] << endl;
			} 			
			cout << "\n";
		}
		break;

	case(4):
		// средний бал

		for (int student_num = 0; student_num < students_quantity; student_num++)
		{
			cout << "Пользователь #" << student_data[student_num].id << " " << student_data[student_num].login << endl;
			cout << student_data[student_num].surname << " " << student_data[student_num].name << " " << student_data[student_num].patronymic << endl;
			cout << "Средний бал:" << endl;
			
			double avg_mark = 0;
			for (int mark_id = 0; mark_id < student_data[student_num].numbers_of_marks; mark_id++)
			{
				avg_mark += student_data[student_num].marks[mark_id];
			} avg_mark = avg_mark / student_data[student_num].numbers_of_marks;

			cout << avg_mark << endl;
			cout << "\n";
		}
		break;
	default:
		break;
	}

}

void MarksFilter(StudentData* student_data, int students_quanity)
{
	system("cls");

	int* excellent_students_id = new int[students_quanity];
	int excellent_students_quanity = 0;

	int* good_students_id = new int[students_quanity];
	int good_students_quanity = 0;

	int* not_certified_students_id = new int[students_quanity];
	int not_certified_quanity = 0;

	for (int student_num = 0; student_num < students_quanity; student_num++)
	{
		bool is_excellent = true;
		bool is_good = true;
		bool is_not_certified = false;

		for (int mark_id = 0; mark_id < student_data[student_num].numbers_of_marks; mark_id++)
		{
			if (student_data[student_num].marks[mark_id] == 4)
			{
				is_excellent = false;
			};

			if (student_data[student_num].marks[mark_id] == 3)
			{
				is_excellent = false;
				is_good = false;
			};

			if (student_data[student_num].marks[mark_id] == 2)
			{
				is_excellent = false;
				is_good = false;
				is_not_certified = true;
			};
		}

		if (is_not_certified) 
		{
			not_certified_students_id[not_certified_quanity] = student_num;
			not_certified_quanity++;
			continue;
		}

		if (is_excellent)
		{
			excellent_students_id[excellent_students_quanity] = student_num;
			excellent_students_quanity++;
			continue;
		}

		if (is_good)
		{
			good_students_id[good_students_quanity] = student_num;
			good_students_quanity++;
			continue;
		}
	}

	cout << "Список отличников:" << endl;
	if (excellent_students_quanity == 0) cout << "К сожалению, отличников не найдено...\n" << endl;
	else
	{
		for (int student_num = 0; student_num < excellent_students_quanity; student_num++)
		{
			cout << student_data[excellent_students_id[student_num]].surname << " " << student_data[excellent_students_id[student_num]].name << " " << student_data[excellent_students_id[student_num]].patronymic << endl;
			cout << "\n";
		}
	}
	cout << "\n";

	cout << "Список хорошистов:" << endl;
	if (good_students_quanity == 0) cout << "К сожалению, хорошистов не найдено...\n" << endl;
	else
	{
		for (int student_num = 0; student_num < good_students_quanity; student_num++)
		{
			cout << student_data[good_students_id[student_num]].surname << " " << student_data[good_students_id[student_num]].name << " " << student_data[good_students_id[student_num]].patronymic << endl;
			cout << "\n";
		}
	}
	cout << "\n";

	cout << "Список неаттестованных студентов:" << endl;
	if (good_students_quanity == 0) cout << "К счастью, неаттестованных студентов не найдено :).\n" << endl;
	else
	{
		for (int student_num = 0; student_num < not_certified_quanity; student_num++)
		{
			cout << student_data[not_certified_students_id[student_num]].surname << " " << student_data[not_certified_students_id[student_num]].name << " " << student_data[not_certified_students_id[student_num]].patronymic << endl;
			cout << "\n";
		}
	}
	cout << "\n";


	delete[] excellent_students_id;
	delete[] good_students_id;
	delete[] not_certified_students_id;
}

//TODO SOMEONE GUYS PLEASE HELP!!!!!!!!!
void ShowSortList(StudentData* student_data, int students_quantity)
{
	for (int student_num = 0; student_num < students_quantity; student_num++)
	{
		cout << "Пользователь #" << student_data[student_num].id << " " << student_data[student_num].login << endl;
		cout << student_data[student_num].surname << " " << student_data[student_num].name << " " << student_data[student_num].patronymic << endl;
		cout << "Средний бал:" << endl;

		double avg_mark = 0;
		for (int mark_id = 0; mark_id < student_data[student_num].numbers_of_marks; mark_id++)
		{
			avg_mark += student_data[student_num].marks[mark_id];
		} avg_mark = avg_mark / student_data[student_num].numbers_of_marks;

		student_data[student_num].avg_mark = avg_mark;
	}


	// ДОБАВИТЬ ВЫВОД ОТСОРТИРОВАННЫХ УЧЕНИКОВ ОТ БОЛЬШЕГО СРЕДНЕГО БАЛА К МЕНЬШЕМУ
}

void TeacherAuthMenu()
{

	//TODO ILIAS READING FROM DATABASE

	/*int number_of_teachers = CheckTeacherListNumber();
	cout << number_of_teachers;

	TeacherData* teachers = (TeacherData*)malloc(sizeof(TeacherData) * number_of_teachers);
	CheckTeacherList(teachers, number_of_teachers);

	cout << teachers;
	getchar();*/

	int number_of_teachers = 2;
	TeacherData* teachers = new TeacherData[number_of_teachers];

	teachers[0].login = "kazemir32";
	teachers[0].name = "Каземир";
	teachers[0].surname = "Каземиров";
	teachers[0].patronymic = "Каземирович";
	teachers[0].password = "qwerty";

	teachers[1].login = "maxonpolyakov";
	teachers[1].name = "Максим";
	teachers[1].surname = "Поляков";
	teachers[1].patronymic = "Фенибутович";
	teachers[1].password = "bobus2";
	
	int number_of_students = 4;
	StudentData* students = new StudentData[number_of_students];

	students[0].login = "student32";
	students[0].name = "Максим";
	students[0].surname = "Козлек";
	students[0].patronymic = "Абрамович";
	students[0].password = "qwerty";
	students[0].id = 0;
	students[0].numbers_of_marks = 6;
	students[0].marks[0] = 2;
	students[0].marks[1] = 3;
	students[0].marks[2] = 4;
	students[0].marks[3] = 5;
	students[0].marks[4] = 0;
	students[0].marks[5] = 2;


	students[1].login = "demidovlox";
	students[1].name = "Илья";
	students[1].surname = "Зайцев";
	students[1].patronymic = "Владимирович";
	students[1].password = "qwerty";
	students[1].id = 1;
	students[1].numbers_of_marks = 6;
	students[1].marks[0] = 5;
	students[1].marks[1] = 5;
	students[1].marks[2] = 5;
	students[1].marks[3] = 5;
	students[1].marks[4] = 5;
	students[1].marks[5] = 5;

	students[2].login = "robertorick";
	students[2].name = "Ильяc";
	students[2].surname = "Зайцев2";
	students[2].patronymic = "Владимирович2";
	students[2].password = "qwerty";
	students[2].id = 1;
	students[2].numbers_of_marks = 6;
	students[2].marks[0] = 4;
	students[2].marks[1] = 5;
	students[2].marks[2] = 5;
	students[2].marks[3] = 4;
	students[2].marks[4] = 5;
	students[2].marks[5] = 5;

	students[3].login = "robertorickoooo";
	students[3].name = "Ильяcsdsd";
	students[3].surname = "Зайцев23";
	students[3].patronymic = "Владимирович2";
	students[3].password = "qwerty";
	students[3].id = 1;
	students[3].numbers_of_marks = 6;
	students[3].marks[0] = 4;
	students[3].marks[1] = 3;
	students[3].marks[2] = 5;
	students[3].marks[3] = 4;
	students[3].marks[4] = 5;
	students[3].marks[5] = 5;


	string state = "run";

	do
	{
		TeacherData curr_user;
		int curr_user_arr_id_in_database;

		system("cls");
		cout << "Добро пожаловать, для продолжения введите свой логин (чтобы вернуться в главное меню введите 0):" << endl;
		getline(cin, curr_user.login);

		// пользователь хочет вернуться в главное меню
		if (curr_user.login == "0") state = "shutdown";

		// пользователь вводит логин
		else
		{
			// проверка на существования логина в базе данных
			bool flag_teacher_exist = false;
			for (int arr_id = 0; arr_id < number_of_teachers; arr_id++)
			{
				if (teachers[arr_id].login == curr_user.login)
				{
					flag_teacher_exist = true;
					curr_user_arr_id_in_database = arr_id;
					break;
				}
			}

			if (!flag_teacher_exist)
			{
				cout << "Извините, пользователь " << curr_user.login << " не найден.\n";
				cout << "Нажмите любую клавишу, чтобы продолжить.\n";
				getchar();
				continue;
			}

			// пользователь существует
			cout << "Вы входите, как " << teachers[curr_user_arr_id_in_database].name << " " << teachers[curr_user_arr_id_in_database].patronymic << ".\n";

			int attemps_left = 3;
			do
			{
				cout << "Для продолжения введите пароль(чтобы выйти из учётной записи введите 0): ";
				getline(cin, curr_user.password);
				
				// отказ от ввода пароля, выход в меню авторизации
				if (curr_user.password == "0") continue;

				if (curr_user.password != teachers[curr_user_arr_id_in_database].password)
				{
					if (attemps_left - 1 > 0) 
					{
						cout << "Вы ввели неверный пароль, попробуйте снова." << "Осталось(ась) " << attemps_left - 1 << " попытки(ок/ка)." << endl;
					}
					
				}
				attemps_left--;
			} while (curr_user.password != teachers[curr_user_arr_id_in_database].password && attemps_left > 0);

			if (attemps_left == 0)
			{
				cout << "Вы не авторизировались.\n";
				cout << "Нажмите клавишу ENTER, чтобы продолжить.\n";
				getchar();
				continue;
			}

			int teacher_section_choose;
			int teacher_task_choose;
			// меню авторизованного учителя

			do
			{
				system("cls");
				curr_user = teachers[curr_user_arr_id_in_database];
				cout << "Вы авторизированы, как " << curr_user.surname << " " << curr_user.name << " " << curr_user.patronymic << endl;
				cout << "1. Редактирование вопросов." << endl << "2. Работа со списком студентов." << endl << "0. Выход из учётной записи" << endl;

				cout << "Выберите раздел меню: ";
				cin >> teacher_section_choose;


				switch (teacher_section_choose)
				{
				case 1:
				{
					// редактирование вопросов
					QestionEditorMenu(); break;
				}
				case 2:
				{
					// работа со списком студентов
					cout << "1. Удаление и регистрация студентов.\n2. Изменение прогресса студентов.\n-- Вывод списка студентов с оценками \n3. -по всем темам\n4. -по конкретной теме\n";
					cout << "5. -только итоговый тест\n6. -только средний бал\n7. Фильтрация (по конкретным оценкам).\n8. Сортировка по конректным оценкам.";
					cout << "Выберите задачу: ";
					cin >> teacher_task_choose;

					switch (teacher_task_choose)
					{
					case 1:
						DelAndRegStudents();
						cout << "Нажмите клавишу ENTER, чтобы продолжить.\n";
						getchar();
						getchar();
						break;
					case 2:
						EditStudentsProgress();
						cout << "Нажмите клавишу ENTER, чтобы продолжить.\n";
						getchar();
						getchar();
						break;
					case 3:
						ShowStudensList(1, students, number_of_students);
						cout << "Нажмите клавишу ENTER, чтобы продолжить.\n";
						getchar();
						getchar();
						break;
					case 4:
						ShowStudensList(2, students, number_of_students);
						cout << "Нажмите клавишу ENTER, чтобы продолжить.\n";
						getchar();
						getchar();
						break;
					case 5:
						ShowStudensList(3, students, number_of_students);
						cout << "Нажмите клавишу ENTER, чтобы продолжить.\n";
						getchar();
						getchar();
						break;
					case 6:
						ShowStudensList(4, students, number_of_students);
						cout << "Нажмите клавишу ENTER, чтобы продолжить.\n";
						getchar();
						getchar();
					case 7:
						MarksFilter(students, number_of_students);
						cout << "Нажмите клавишу ENTER, чтобы продолжить.\n";
						getchar();
						getchar();
						break;
					case 8:
						ShowSortList(students, number_of_students);
						cout << "Нажмите клавишу ENTER, чтобы продолжить.\n";
						getchar();
						getchar();
						break;
						break;

					default:
					{
						cout << "Вы ввели некорректное значение. Для продолжения нажмите ENTER.";
						getchar();
						break;
					}
					}
				}
				default:
				{
					cout << "Вы ввели некорректное значение. Для продолжения нажмите клавишу ENTER." << endl;
					break;
				}
				}
			} while (teacher_section_choose != 0);

		}
			
	} while (state != "shutdown");
	
}