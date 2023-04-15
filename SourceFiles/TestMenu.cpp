//realized by G.Machehin & E. Zhurow
#include "../Headers/TestMenuLib.h"

int MarkToBase(string Theme, int mark, string surname, string name, string patronymic, int* marks)
{
    string line;
    ifstream fileStudents("students_database.txt");
    if (!fileStudents.is_open()) {
        cout << "Îøèáêà îòêðûòèÿ ôàéëà students_database.txt" << endl;
        system("pause");
        return 1;
    }

    vector<string> studentLines;
    while (getline(fileStudents, line)) {
        studentLines.push_back(line);
    }
    fileStudents.close();

    ofstream fileStudentsOut("students_database.txt");
    if (!fileStudentsOut.is_open()) {
        cout << "Îøèáêà îòêðûòèÿ ôàéëà students_database.txt" << endl;
        system("pause");
        return 1;
    }

    bool studentFound = false;
    for (size_t i = 0; i < studentLines.size(); ++i) {
        if (studentLines[i] == surname && studentLines[i + 1] == name && studentLines[i + 2] == patronymic) {
            studentFound = true;

            size_t marksPos = i + 3;
            stringstream marks_stream(studentLines[marksPos]);
            int index = 0;
            int temp_mark;
            while (marks_stream >> temp_mark) {
                marks[index++] = temp_mark;
            }

            if (index > 0) {
                if (Theme == "CircleTest.txt") marks[0] = mark;
                else if (Theme == "ArrayTest.txt") marks[1] = mark;
                else if (Theme == "StringTest.txt") marks[2] = mark;
                else if (Theme == "RekursionTest.txt") marks[3] = mark;
                else if (Theme == "StructTest.txt") marks[4] = mark;
                else if (Theme == "FilesTest.txt") marks[5] = mark;
                else if (Theme == "PointerTest.txt") marks[6] = mark;
                else if (Theme == "DinMemory.txt") marks[7] = mark;
                else if (Theme == "Final") marks[8] = mark;

                studentLines[marksPos] = "";
                for (int j = 0; j < index; ++j) {
                    studentLines[marksPos] += to_string(marks[j]) + " ";
                }
                studentLines[marksPos].pop_back();
            }
            break;
        }
    }

    if (!studentFound) {
        cout << "Ñòóäåíò íå íàéäåí â áàçå äàííûõ." << endl;
        system("pause");
    }

    for (const auto& line : studentLines) {
        fileStudentsOut << line << endl;
    }
    fileStudentsOut.close();

    return 0;
}
int TrainingOnTheme(string Theme) {
    system("cls");

    ifstream fileInp(Theme);
    if (!fileInp.is_open()) {
        cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
        system("pause");
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(fileInp, line)) {
        lines.push_back(line);
    }
    fileInp.close();

    int correctAnswer = 0, answer = 0;
    srand(time(nullptr));
    set<int> chosenPositions;

    for (int i = 0; i < 10; ++i) {
        int pos;
        do {
            pos = rand() % lines.size();
        } while (chosenPositions.count(pos));
        chosenPositions.insert(pos);
        string& str = lines[pos];

        if (!str.empty()) {
            correctAnswer = str.back() - '0';
        }
        do
        {
            system("cls");
            if (!str.empty()) {
                cout << "QUESTION #" << i + 1 << "  ";
                cout << str.substr(0, str.size() - 1) << endl;
            }
            cout << " --> ";
            cin >> answer;
        } while (answer != correctAnswer);
        cout << endl << "ÂÅÐÍÎ" << endl;
        system("pause");
    }

    system("cls");
    setlocale(LC_ALL, "rus");
    return 0;
}


int TestingOnTheme(string Theme, string surname, string name, string patronymic/*, int *marcs*/)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");

    ifstream fileInp(Theme);
    if (!fileInp.is_open()) {
        cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(fileInp, line)) {
        lines.push_back(line);
    }
    fileInp.close();

    int correctAnswer = 0, answer = 0, mistakes = 0;
    vector<string> wrongAnswers;

    srand(time(nullptr));
    set<int> chosenPositions;

    for (int i = 0; i < 10; ++i) {
        int pos;
        do {
            pos = rand() % lines.size();
        } while (chosenPositions.count(pos));
        chosenPositions.insert(pos);

        string& str = lines[pos];

        if (!str.empty()) {
            correctAnswer = str.back() - '0';
        }

        system("cls");
        if (!str.empty()) {
            cout << "QESTION #" << i + 1 << "  ";
            cout << str.substr(0, str.size() - 1) << endl;
        }
        cout << " --> ";
        cin >> answer;
        if (answer == correctAnswer) {
            cout << "ÂÅÐÍÎ" << endl;
        }
        else {
            string wrongAnswerStr = str.substr(0, str.size());
            wrongAnswers.push_back(wrongAnswerStr);
            cout << "ÍÅÂÅÐÍÎ" << endl;
            mistakes++;
        }
        system("pause");
    }

    int mark;
    system("cls");
    if (mistakes > 6) {
        cout << "ÎÖÅÍÊÀ: 2 (" << 10 - mistakes << "/10)" << endl; mark = 2;
    }
    else if (mistakes > 4) {
        cout << "ÎÖÅÍÊÀ: 3 (" << 10 - mistakes << "/10)" << endl; mark = 3;
    }
    else if (mistakes > 2) {
        cout << "ÎÖÅÍÊÀ: 4 (" << 10 - mistakes << "/10)" << endl; mark = 4;
    }
    else {
        cout << "ÎÖÅÍÊÀ: 5 (" << 10 - mistakes << "/10)" << endl; mark = 5;
    }

    cout << "ÍÅÏÐÀÂÈËÜÍÎ ÎÒÂÅ×ÅÍÍÛÅ ÂÎÏÐÎÑÛ:" << endl;
    for (string wrongAnswer : wrongAnswers) {
        cout << endl << wrongAnswer << endl;
    }
    system("pause");
    int marks[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    MarkToBase(Theme, mark, surname, name, patronymic, marks);
    system("cls");
    setlocale(LC_ALL, "Rus");
    return 0;
}

int FinalTest(string surname, string name, string patronymic/*, int * marks*/) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int FILE_COUNT = 8;
    system("cls");

    ifstream cirFile("CircleTest.txt");
    ifstream arrFile("ArrayTest.txt");
    ifstream strFile("StringTest.txt");
    ifstream recFile("RekursionTest.txt");
    ifstream structFile("StructTest.txt");
    ifstream filFile("FilesTest.txt");
    ifstream poiFile("PointerTest.txt");
    ifstream dinFile("DinMemory.txt");

    vector<vector<string>> files = {
        {},{},{},{},{},{},{},{}
    };

    vector<ifstream*> ifs = {
        &cirFile,&arrFile,&strFile,&recFile,&structFile,&filFile,&poiFile,&dinFile
    };

    for (int i = 0; i < FILE_COUNT; i++) {
        if (!*ifs[i]) {
            cerr << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
            return 1;
        }
    }

    for (int i = 0; i < FILE_COUNT; i++) {
        string line;
        while (getline(*ifs[i], line)) {
            files[i].push_back(line);
        }
        ifs[i]->close();
    }

    int correctAnswer = 0, answer = 0, mistakes = 0;
    srand(time(nullptr));
    set<int> chosenPositions;

    for (int i = 0; i < 40; ++i) {
        int fileNo = rand() % FILE_COUNT;
        int pos;
        do {
            pos = rand() % files[fileNo].size();
        } while (pos > 0 && files[fileNo][pos - 1].substr(0, 5) == files[fileNo][pos].substr(0, 5));

        string& str = files[fileNo][pos];

        if (!str.empty()) {
            correctAnswer = str.back() - '0';
        }
        system("cls");
        if (!str.empty()) {
            cout << "QESTION #" << i + 1 << "  ";
            cout << str.substr(0, str.size() - 1) << endl;
        }
        cout << " --> ";
        cin >> answer;
        if (answer == correctAnswer) cout << "ÂÅÐÍÎ" << endl; else { cout << "ÍÅÂÅÐÍÎ" << endl; mistakes++; }
        system("pause");
    }
    int mark;
    system("cls");
    if (mistakes > 15) { cout << "ÎÖÅÍÊÀ: 2(" << 40 - mistakes << "/40)" << endl; mark = 2; }
    else if (mistakes > 10) { cout << "ÎÖÅÍÊÀ: 3(" << 40 - mistakes << "/40)" << endl; mark = 3; }
    else if (mistakes > 5) { cout << "ÎÖÅÍÊÀ: 4(" << 40 - mistakes << "/40)" << endl; mark = 4; }
    else { cout << "ÎÖÅÍÊÀ: 5(" << 40 - mistakes << "/40)" << endl; mark = 5; }


    system("pause");

    string Theme = "Final";
    int marks[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    MarkToBase(Theme, mark, surname, name, patronymic, marks);
    system("cls");
    return 0;
}