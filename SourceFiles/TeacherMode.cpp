#include "../Headers/TeacherMode.h"
#include "../Headers/FileReading.h"

int FileOutput(vector<string> lines)
{
	int i = 1;
	for (auto& str : lines) {
		if (!str.empty()) {
			cout << "QESTION #" << i << "  ";
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
	return 0;
}

//TODO ILIAS
void DelAndRegStudents()
{

}

//TODO VLADIS
void EditStudentsProgress()
{

}

//TODO VLADIS
void ShowStudensList()
{

}

//TODO VLADIS
void Filter()
{

}

//TODO VLADIS
void ShowSortList()
{

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
				cout << "Нажмите любую клавишу, чтобы продолжить.\n";
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
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						break;
					case 8:
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
					cout << "Вы ввели некорректное значение. Для продолжения нажмите любую клавишу" << endl;

					break;
				}
				}
			} while (teacher_section_choose != 0);
			
			
		}

	
	} while (state != "shutdown");
	

}