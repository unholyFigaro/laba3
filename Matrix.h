#pragma once
#include <cstdlib>
#include <iostream>

using namespace std;

class Matrix
{
private:
    int n, m;
    int** arr;
public:
    Matrix() {
        n = m = 1; arr = new int* [n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[m];
        }
    }

    Matrix(int n_size, int m_size)
    {
        n = n_size; m = m_size; arr = new int* [n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[m];
        };
    }

    Matrix(const Matrix& other)
    {
        this->m = other.m;
        this->n = other.n;
        this->arr = new int* [other.n];
        for (int i = 0; i < other.n; i++)
        {
            this->arr[i] = new int[m];
        };
        for (int i = 0; i < other.n; i++)
        {
            for (int j = 0; j < other.m; j++)
            {
                this->arr[i][j] = other.arr[i][j];
            }
        }
    }

    void setMatrix(int n, int m, int** mtr)
    {
        this->m = m;
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                this->arr[i][j] = mtr[i][j];
            }
        }
    }
    // std::cout - это объект std::ostream 
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

    //~Matrix() {
    //    for (int i = 0; i < n; i++)
    //        delete[]arr[i];
    //    delete[]arr;
    //}

    void show()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator&(const Matrix second)
    {
        if (m != second.n || n != second.m)
        {
            cout << "Raznyj razmer" << endl;
            return Matrix();
        }
        else {
            Matrix rezult(*this);
            int sum = 0;
            int r = 0;
            int temp = 0;
            for (int i = 0; i < this->n; i++)
            {
                for (int j = 0; j < second.m; j++)
                {
                    rezult.arr[i][j] = 0;
                    for (int k = 0; k < this->m; k++)
                        rezult.arr[i][j] += this->arr[i][k] * second.arr[k][j];
                }
            }

            return rezult;
        }
    }


    int& operator()(int str1, int stb1)
    {
        return arr[str1][stb1];
    }
};

ostream& operator<<(ostream& out, const Matrix& matrix)
{
    for (int i = 0; i < matrix.n; i++)
    {
        for (int j = 0; j < matrix.m; j++)
        {
            out << matrix.arr[i][j] << " ";
        }
        out << endl;
    }
    return out;
}