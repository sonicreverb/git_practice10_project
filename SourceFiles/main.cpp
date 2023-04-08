//Realised by Machehin Grigory Alexandrovich

#include <iostream>
#include <conio.h>
#include <locale>

#include "../Headers/TeacherMode.h"
#include "../Headers/StudentMode.h"


using namespace std;

void MainMenu(int switcher)
{
    int key;
    system("cls");

    switch (switcher)
    {
    case 1:
        cout << "\r\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tнасвючые-реярхпсчыюъ яхярелю\n\n\n\n\n\n\n                  \t\t\t\t<< бнирх йюй опеондюбюрекэ >>\n\n             \t\t\t\t\t      бнирх йюй ярсдемр\n\n                            \t\t\t\t    бшунд\n\n";
        break;
    case 2:
        cout << "\r\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tнасвючые-реярхпсчыюъ яхярелю\n\n\n\n\n\n\n                  \t\t\t\t   бнирх йюй опеондюбюрекэ\n\n             \t\t\t\t\t   << бнирх йюй ярсдемр >>\n\n                            \t\t\t\t    бшунд\n\n";
        break;
    case 3:
        cout << "\r\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tнасвючые-реярхпсчыюъ яхярелю\n\n\n\n\n\n\n                  \t\t\t\t   бнирх йюй опеондюбюрекэ\n\n             \t\t\t\t\t      бнирх йюй ярсдемр\n\n                            \t\t\t\t << бшунд >>\n\n";
        break;
    default: MainMenu(1);
    }

    key = _getch();
    if (key == 27)
    {
        _exit(0);
    }
    if (key == 72)
        if (switcher != 1)
            MainMenu(switcher - 1);
        else
            MainMenu(3);
    if (key == 80)
    {
        if (switcher != 3)
            MainMenu(switcher + 1);
        else
            MainMenu(1);
    }
    if (key == 13 || key == 32)
    {
        if (switcher == 1) { system("cls");  TeacherAuthMenu(); MainMenu(1); }
        if (switcher == 2) { system("cls");  StudentAuthMenu();  MainMenu(1); }
        if (switcher == 3) {}
        {
            _exit(0);
        }
    }
    else MainMenu(switcher);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");
    MainMenu(1);
    return 0;
}