#include "../Headers/TestMenuLib.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

void Training(string Theme)
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