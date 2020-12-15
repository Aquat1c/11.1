
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;

void create(char* FileName, int N, int min, int max)
{
    ofstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "Помилка при спробі відкрити файл" << endl;
        exit(1);
    }

    int a;
    double test = 0;
    for (int i = 0; i < N; i++)
    {
        a = min + rand() % (max - min + 1);
        f.write((char*)&a, sizeof(int));
    }
    cout << endl;
}
double minpluus(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "Помилка при спробі відкрити файл" << endl;
        exit(1);
    }
    int a = 0;
    double minplus = 0;
    while (f.read((char*)&a, sizeof(int)))
    {

        if (a > 0 && minplus > a)
        {
            minplus = a;
            return minplus;

        }
    }
}

double maxminus(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "Помилка при спробі відкрити файл" << endl;
        exit(1);
    }
    int a, l = 0;
    int maxnegative = 0;
    while (f.read((char*)&a, sizeof(int)))
    {
        if (a < 0 && maxnegative < a)
            maxnegative = a;
        return maxnegative;

    }
}
void print(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "Помилка при спробі відкрити файл" << endl;
        exit(1);
    }
    int a;
    while (f.read((char*)&a, sizeof(int)))
        cout << a << "   ";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    int N, min, max, menu;
    double minplus, maxnegative;
    char FileName[] = "t.txt";
    cout << "Виберіть опцію " << endl;
    do {
        cout << endl;
        cout << "[0] - Записати числа в бінарному файлі: " << endl;
        cout << "[1] - Завантажити число з бінарного файлу та вивести значення найбільшої від'ємної компоненти і найменшої додатної компоненти" << endl;
        cout << "[2] - Завантажити числа з бінарного файлу та відобразити їх" << endl;
        cout << "[інше значення] - Вийти з програми" << endl;
        cout << "Введіть значення для вибору елемента в меню:"; cin >> menu;
        switch (menu)
        {
        case 0:
            cout << endl;
            cout << "Введіть кількість чисел: "; cin >> N;
            cout << "Введіть мінімальне значення:"; cin >> min;
            cout << "Введіть максимальне значення:"; cin >> max;
            create(FileName, N, min, max);
            break;
        case 1:
            cout << endl;
            cout << "Найбільше від'ємне значення: " << maxminus(FileName) << endl;
            cout << "Найменше додатнє значення:" << minpluus(FileName) << endl;
            break;
        case 2:
            print(FileName);
        default:
            break;
        }
    } while (menu == 0 || menu == 1 || menu == 2);
}