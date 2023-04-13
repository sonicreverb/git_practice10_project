#include "../Headers/TestMenuLib.h"

int TrainingOnTheme(string Theme) {
    setlocale(LC_ALL, "ru_RU.UTF-8"); 
    system("cls");

    ifstream fileInp(Theme);
    if (!fileInp.is_open()) {
        cout << "Failed to open file" << endl;
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
        cout << endl << "CORRECT" << endl;
        system("pause");
    }

    system("cls");
    setlocale(LC_ALL, "rus");
    return 0;
}

int TestingOnTheme(string Theme)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    system("cls");

    ifstream fileInp(Theme);
    if (!fileInp.is_open()) {
        cout << "Failed to open file" << endl;
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
            cout << "CORRECT" << endl;
        }
        else {
            string wrongAnswerStr = str.substr(0, str.size());
            wrongAnswers.push_back(wrongAnswerStr);
            cout << "WRONG ANSWER" << endl;
            mistakes++;
        }
        system("pause");
    }
    system("cls");
    if (mistakes > 6) {
        cout << endl << "Mark: 2 (" << 10 - mistakes << "/10)" << endl;
    }
    else if (mistakes > 4) {
        cout << endl << "Mark: 3 (" << 10 - mistakes << "/10)" << endl;
    }
    else if (mistakes > 2) {
        cout << endl << "Mark: 4 (" << 10 - mistakes << "/10)" << endl;
    }
    else {
        cout << endl << "Mark: 5 (" << 10 - mistakes << "/10)" << endl;
    }

    cout << "WRONG ANSWERED QESTIONS:" << endl;
    for (string wrongAnswer : wrongAnswers) {
        cout << endl << wrongAnswer << endl;
    }

    system("pause");
    system("cls");
    setlocale(LC_ALL, "rus");
    return 0;
}

int FinalTest() {
    const int FILE_COUNT = 8;
    setlocale(LC_ALL, "ru_RU.UTF-8");
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
        &cirFile, &arrFile, &strFile, &recFile, &structFile, &filFile, &poiFile, &dinFile
    };

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
        if (answer == correctAnswer) cout << "CORRECT" << endl; else { cout << "WRONG ANSWER" << endl; mistakes++; }
        system("pause");
    }
    system("cls");
    if (mistakes > 15) cout << endl << endl << "Mark: 2(" << 40 - mistakes << "/40)" << endl;
    else if (mistakes > 10) cout << endl << endl << "Mark: 3(" << 40 - mistakes << "/40)" << endl;
    else if (mistakes > 5) cout << endl << endl << "Mark: 4(" << 40 - mistakes << "/40)" << endl;
    else cout << endl << endl << "Mark: 5(" << 40 - mistakes << "/40)" << endl;

    system("pause");
    system("cls");
    setlocale(LC_ALL, "rus");
    return 0;
}