#include "../Headers/TestMenuLib.h"


int TrainingOnTheme(string Theme)
{

    setlocale(LC_ALL, "en_US.UTF-8");
    system("cls");

    ifstream input(Theme);
    if (!input.is_open()) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(input, line)) {
        lines.push_back(line);
    }

    int correctAnswer, answer;
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i) {
        int index = rand() % lines.size();
        string& str = lines[index];

        if (!str.empty()) {
            correctAnswer = str.back() - '0';
        }
        do
        {
            system("cls");
            if (!str.empty()) {
                cout << str.substr(0, str.size() - 1) << endl;
            }
            cout << " --> ";
            cin >> answer;
        } while (answer != correctAnswer);
        cout << endl << "CORRECT!" << endl;
        system("pause");
    }

    input.close();
    return 0;

}
int TestingOnTheme(string Theme)
{
    setlocale(LC_ALL, "en_US.UTF-8");
    system("cls");

    ifstream input("CircleTest.txt");
    if (!input.is_open()) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(input, line)) {
        lines.push_back(line);
    }

    int correctAnswer, answer, mistakes = 0;
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i) {
        int index = rand() % lines.size();
        string& str = lines[index];

        if (!str.empty()) {
            correctAnswer = str.back() - '0';
        }
        system("cls");
        if (!str.empty()) {
            cout << str.substr(0, str.size() - 1) << endl;
        }
        cout << " --> ";
        cin >> answer;
        if (answer == correctAnswer) cout << "CORRECT" << endl; else { cout << "WRONG ANSWER" << endl; mistakes++; }
        system("pause");
    }
    system("cls");
    if (mistakes > 6) cout << endl << endl << "Mark: 2";
    else if (mistakes > 4) cout << endl << endl << "Mark: 3";
    else if (mistakes > 2) cout << endl << endl << "Mark: 4";
    else cout << endl << endl << "Mark: 5";

    input.close();
    return 0;
}