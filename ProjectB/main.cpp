/**
 * Alejandro Hahn
 * 
 * Proyecto B
 **/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<int>> mat;


int traditionalCount = 0;

void multiply(mat A, mat B, mat &C)
{
    vector<int> v(A.size(), 0);
    C.resize(A.size(), v);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < A.size(); k++)
            {
                C[i][j] += A[i][k] * B[k][j];
                traditionalCount++;
            }
        }
    }
}

/**
 * Basic operations
 **/

void sum(mat &A, mat &B, mat &C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void substract(mat &A, mat &B, mat &C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

/**
 * Strassen matrix multiplication
 **/

int strassenCount = 0;

void strassenR(mat &A, mat &B, mat &C, int n)
{
    if (n <= 2)
    {
        vector<int> v(A.size(), 0);
        C.resize(A.size(), v);
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < A.size(); k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                    strassenCount++;
                }
            }
        }
        return;
    }

    else
    {
        int newTam = n / 2;
        vector<int> inner(newTam);
        mat
            a11(newTam, inner), a12(newTam, inner), a21(newTam, inner), a22(newTam, inner),
            b11(newTam, inner), b12(newTam, inner), b21(newTam, inner), b22(newTam, inner),
            c11(newTam, inner), c12(newTam, inner), c21(newTam, inner), c22(newTam, inner),
            p1(newTam, inner), p2(newTam, inner), p3(newTam, inner), p4(newTam, inner),
            p5(newTam, inner), p6(newTam, inner), p7(newTam, inner),
            aResult(newTam, inner), bResult(newTam, inner);

        int i, j;

        for (i = 0; i < newTam; i++)
        {
            for (j = 0; j < newTam; j++)
            {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + newTam];
                a21[i][j] = A[i + newTam][j];
                a22[i][j] = A[i + newTam][j + newTam];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + newTam];
                b21[i][j] = B[i + newTam][j];
                b22[i][j] = B[i + newTam][j + newTam];
            }
        }

        sum(a11, a22, aResult, newTam);
        sum(b11, b22, bResult, newTam);
        strassenR(aResult, bResult, p1, newTam);

        sum(a21, a22, aResult, newTam);
        strassenR(aResult, b11, p2, newTam);

        substract(b12, b22, bResult, newTam);
        strassenR(a11, bResult, p3, newTam);

        substract(b21, b11, bResult, newTam);
        strassenR(a22, bResult, p4, newTam);

        sum(a11, a12, aResult, newTam);
        strassenR(aResult, b22, p5, newTam);

        substract(a21, a11, aResult, newTam);
        sum(b11, b12, bResult, newTam);
        strassenR(aResult, bResult, p6, newTam);

        substract(a12, a22, aResult, newTam);
        sum(b21, b22, bResult, newTam);
        strassenR(aResult, bResult, p7, newTam);

        sum(p3, p5, c12, newTam);
        sum(p2, p4, c21, newTam);

        sum(p1, p4, aResult, newTam);
        sum(aResult, p7, bResult, newTam);
        substract(bResult, p5, c11, newTam);

        sum(p1, p3, aResult, newTam);
        sum(aResult, p6, bResult, newTam);
        substract(bResult, p2, c22, newTam);

        for (i = 0; i < newTam; i++)
        {
            for (j = 0; j < newTam; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + newTam] = c12[i][j];
                C[i + newTam][j] = c21[i][j];
                C[i + newTam][j + newTam] = c22[i][j];
            }
        }
    }
}

void strassen(mat A, mat B, mat &C, int n)
{
    int m = pow(2, int(ceil(log2(n))));
    vector<int> v(m, 0);
    mat AA(m, v), BB(m, v), CC(m, v);

    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            AA[i][j] = A[i][j];
            BB[i][j] = B[i][j];
        }
    }

    strassenR(AA, BB, CC, m);
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            C[i][j] = CC[i][j];
        }
    }
}

int main()
{
    int size;
    cin >> size;
    vector<int> v(size, 0);
    mat A;
    A.resize(size, v);
    mat B;
    B.resize(size, v);
    mat C;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> B[i][j];
        }
    }
    multiply(A, B, C);
    strassen(A, B, C, size);
    cout << "Traditional Scalar Multiplications: " << traditionalCount << endl << endl;
    cout << "Strassen Scalar Multiplications: " << strassenCount << endl;

    cout << endl;
    cout << "Strassen Result Matrix:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}