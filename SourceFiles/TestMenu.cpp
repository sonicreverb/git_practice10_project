#include "../Headers/TestMenuLib.h"


int TrainingOnTheme(string Theme) {
    setlocale(LC_ALL, "ru_RU.UTF-8"); system("cls");

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


int FinalTest()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    system("cls");
    //
    //
    system("cls");
    setlocale(LC_ALL, "rus");
    return 0;
}