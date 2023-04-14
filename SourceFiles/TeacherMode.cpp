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
	cout << "�������� ����� ������� ��� ��������(0 - �����): ";
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
			cout << "������ ��� �������� �����." << endl;
			return 1;
		}
		cout << "������." << endl;
	}
	else {
		cout << "�������� ����� �������." << endl;
		return 1;
	}
	return 0;
}

int QuestionEdit(string Theme, vector<string> lines)
{
	FileOutput(lines);

	int LineNumber;
	cout << "�������� ����� ������� ��� ��������������(0 - �����): ";
	cin >> LineNumber;
	LineNumber--;
	if (LineNumber >= 0 && LineNumber < lines.size()) {
		string editedLine;
		cout << "����� ������� �������: ";
		if (!isdigit(editedLine.back())) {
			cout << "��������� ������ ������ �������� ������� ������ ���� ��� �������, �� ����, ������." << endl;
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
			cout << "������ ��� �������� �����." << endl;
			system("pause");
			return 1;
		}
		cout << "������." << endl;
	}
	else {
		cout << "�������� ����� �������." << endl;
		return 1;
	}
	return 0;
}

int QuestionAdd(string Theme, vector<string> lines)
{
	FileOutput(lines);

	string newLine;
	cout << "����� ������: ";

	cin.ignore();
	getline(cin, newLine);

	if (!isdigit(newLine.back())) {
		cout << "��������� ������ ������ ������� ������ ���� ��� �������, �� ����, ������." << endl;
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
		cout << "������ ��� �������� �����." << endl;
		return 1;
	}
	cout << "������." << endl;
	return 0;
}

vector<string> fileParse(string Theme)
{
	string line;
	vector<string> lines;

	ifstream fileInp(Theme);
	if (!fileInp.is_open()) {
		cout << "������ ��� �������� �����" << endl;
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
		cout << "�������� ��������: " << endl << "1 - ������� ������" << endl << "2 - ������������� ������" << endl << "3 - �������� ������" << endl << "4 - ������� �������� ��������" << endl << "0 - ����� � ���� ������ ����" << endl;
		cin >> switcher;
		switch (switcher) {
		case 1: system("cls"); QuestionDel(Theme, lines); system("pause"); system("cls"); lines = fileParse(Theme); break;
		case 2: system("cls"); QuestionEdit(Theme, lines); system("pause"); system("cls"); lines = fileParse(Theme); break;
		case 3: system("cls"); QuestionAdd(Theme, lines); system("pause"); system("cls"); lines = fileParse(Theme); break;
		case 4: system("cls"); FileOutput(lines); system("pause"); system("cls"); break;
		case 0: break;
		default: cout << "�������������� ������." << endl;
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
		cout << "�������� ���� ��� �������������� ������� ��������:" << endl << endl << "1 - �����\n2 - �������\n3 - ������\n4 - ��������\n5 - ���������\n6 - �����\n7 - ������ � ���������\n8 - ������������ ������\n0 - ����� �� ��������� ��������\n--> ";
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
		default: cout << "�������������� �������";
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
	teachers[0].name = "�������";
	teachers[0].surname = "���������";
	teachers[0].patronymic = "�����������";
	teachers[0].password = "qwerty";

	teachers[1].login = "maxonpolyakov";
	teachers[1].name = "������";
	teachers[1].surname = "�������";
	teachers[1].patronymic = "�����������";
	teachers[1].password = "bobus2";
	
	string state = "run";

	do
	{
		TeacherData curr_user;
		int curr_user_arr_id_in_database;

		system("cls");
		cout << "����� ����������, ��� ����������� ������� ���� ����� (����� ��������� � ������� ���� ������� 0):" << endl;
		getline(cin, curr_user.login);

		// ������������ ����� ��������� � ������� ����
		if (curr_user.login == "0") state = "shutdown";

		// ������������ ������ �����
		else
		{
			// �������� �� ������������� ������ � ���� ������
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
				cout << "��������, ������������ " << curr_user.login << " �� ������.\n";
				cout << "������� ����� �������, ����� ����������.\n";
				getchar();
				continue;
			}

			// ������������ ����������
			cout << "�� �������, ��� " << teachers[curr_user_arr_id_in_database].name << " " << teachers[curr_user_arr_id_in_database].patronymic << ".\n";

			int attemps_left = 3;
			do
			{
				cout << "��� ����������� ������� ������(����� ����� �� ������� ������ ������� 0): ";
				getline(cin, curr_user.password);
				
				// ����� �� ����� ������, ����� � ���� �����������
				if (curr_user.password == "0") continue;

				if (curr_user.password != teachers[curr_user_arr_id_in_database].password)
				{
					if (attemps_left - 1 > 0) 
					{
						cout << "�� ����� �������� ������, ���������� �����." << "��������(���) " << attemps_left - 1 << " �������(��/��)." << endl;
					}
					
				}
				attemps_left--;
			} while (curr_user.password != teachers[curr_user_arr_id_in_database].password && attemps_left > 0);

			if (attemps_left == 0)
			{
				cout << "�� �� ����������������.\n";
				cout << "������� ����� �������, ����� ����������.\n";
				getchar();
				continue;
			}

			int teacher_section_choose;
			int teacher_task_choose;
			// ���� ��������������� �������

			do
			{

				system("cls");
				curr_user = teachers[curr_user_arr_id_in_database];
				cout << "�� ��������������, ��� " << curr_user.surname << " " << curr_user.name << " " << curr_user.patronymic << endl;
				cout << "1. �������������� ��������." << endl << "2. ������ �� ������� ���������." << endl << "0. ����� �� ������� ������" << endl;

				cout << "�������� ������ ����: ";
				cin >> teacher_section_choose;


				switch (teacher_section_choose)
				{
				case 1:
				{
					// �������������� ��������
					QestionEditorMenu(); break;
				}
				case 2:
				{
					// ������ �� ������� ���������
					cout << "1. �������� � ����������� ���������.\n2. ��������� ��������� ���������.\n-- ����� ������ ��������� � �������� \n3. -�� ���� �����\n4. -�� ���������� ����\n";
					cout << "5. -������ �������� ����\n6. -������ ������� ���\n7. ���������� (�� ���������� �������).\n8. ���������� �� ���������� �������.";
					cout << "�������� ������: ";
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
						cout << "�� ����� ������������ ��������. ��� ����������� ������� ENTER.";
						getchar();
						break;
					}
					}
				}
				default:
				{
					cout << "�� ����� ������������ ��������. ��� ����������� ������� ����� �������" << endl;

					break;
				}
				}
			} while (teacher_section_choose != 0);
			
			
		}

	
	} while (state != "shutdown");
	

}