
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
        cerr << "������� ��� ����� ������� ����" << endl;
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
        cerr << "������� ��� ����� ������� ����" << endl;
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
        cerr << "������� ��� ����� ������� ����" << endl;
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
        cerr << "������� ��� ����� ������� ����" << endl;
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
    cout << "������� ����� " << endl;
    do {
        cout << endl;
        cout << "[0] - �������� ����� � �������� ����: " << endl;
        cout << "[1] - ����������� ����� � �������� ����� �� ������� �������� �������� ��'���� ���������� � �������� ������� ����������" << endl;
        cout << "[2] - ����������� ����� � �������� ����� �� ���������� ��" << endl;
        cout << "[���� ��������] - ����� � ��������" << endl;
        cout << "������ �������� ��� ������ �������� � ����:"; cin >> menu;
        switch (menu)
        {
        case 0:
            cout << endl;
            cout << "������ ������� �����: "; cin >> N;
            cout << "������ �������� ��������:"; cin >> min;
            cout << "������ ����������� ��������:"; cin >> max;
            create(FileName, N, min, max);
            break;
        case 1:
            cout << endl;
            cout << "�������� ��'���� ��������: " << maxminus(FileName) << endl;
            cout << "�������� ������ ��������:" << minpluus(FileName) << endl;
            break;
        case 2:
            print(FileName);
        default:
            break;
        }
    } while (menu == 0 || menu == 1 || menu == 2);
}