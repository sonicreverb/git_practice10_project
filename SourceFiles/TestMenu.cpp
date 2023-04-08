#include "../Headers/TestMenuLib.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

void TestTraining(string Theme)
{
    setlocale(LC_ALL, "en_US.UTF-8");
    ifstream file(Theme);

    if (!file.is_open()) {
        cout << "Îøèáêà îòêðûòèÿ ôàéëà." << endl;
        return;
    }

    srand(time(0));

    int lines[10], range;
    range = 30;
    for (int i = 1; i < 11; i++)
    {
        lines[i] = rand() % range;
    }
    string line;
    int digit, answer;
    for (int i = 0; i < 10; i++) {
        system("cls");
        for (int j = 0; j < lines[i] - 1; j++) {
            getline(file, line);
        }
        getline(file, line);
        digit = line[line.length() - 1] - '0';
        do
        {
            system("cls");
            cout << line.substr(0, line.length() - 1) << endl;
            cin >> answer;
        } while (answer != digit);
        cout << "ÂÅÐÍÎ!";
        system("pause");
    }

    file.close();

    return;
}

void TestinOnTheme(string Theme)
{
    setlocale(LC_ALL, "en_US.UTF-8");
    ifstream file(Theme);

    if (!file.is_open()) {
        cout << "Îøèáêà îòêðûòèÿ ôàéëà." << endl;
        return;
    }

    srand(time(0));

    int lines[10], range;
    range = 30;
    for (int i = 1; i < 11; i++)
    {
        lines[i] = rand() % range;
    }
    string line;
    int digit, answer, mark, mistakes;
    for (int i = 0; i < 10; i++) {
        system("cls");
        for (int j = 0; j < lines[i] - 1; j++) {
            getline(file, line);
        }
        getline(file, line);
        digit = line[line.length() - 1] - '0';
        system("cls");
        cout << line.substr(0, line.length() - 1) << endl;
        cin >> answer;
        if (answer == digit) cout << "ÂÅÐÍÎ"; else { cout << "ÍÅÂÅÐÍÎ"; mistakes++; }
        system("pause");
    }
    if (mistakes < 2) cout << "5";
    if (mistakes < 3) cout << "4";
    if (mistakes < 5) cout << "3";
    if (mistakes < 6) cout << "2";



    file.close();

    return;
}