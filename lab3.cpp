// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Matrix.h"
#include <cstdlib>

using namespace std;

int main()
{
    int str, stb;
    int** mtr;
    cout << "Vvedite kol-vo strok matrizy" << endl;
    cin >> str;
    cout << "Vvedite kol-vo stolbcov matrizy" << endl;
    cin >> stb;
    mtr = new int* [str];
    for (int i = 0; i < str; i++)
    {
        mtr[i] = new int[stb];
    }
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < stb; j++)
        {
            cout << "Vvedite element matrizy" << endl;
            cin >> mtr[i][j];
        }
    }

    Matrix squar(str, stb);
    squar.setMatrix(str, stb, mtr);
    squar.show();

    cout << squar.operator()(1, 2) << "\n";
    Matrix secondSquar(squar);
    cout << secondSquar;

    Matrix thirdSquar(str,stb);

    for (int i = 0; i < str; i++)
    {
    }
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < stb; j++)
        {
            cout << "Vvedite element matrizy" << endl;
            cin >> mtr[i][j];
        }
    }
    thirdSquar.setMatrix(str, stb, mtr);
    cout << thirdSquar;
    Matrix rezult(str, stb);
    rezult=squar&thirdSquar;

    cout << rezult;

    std::cout << "Hello World!\n";
}


