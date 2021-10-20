//1. Сумма элементов матрицы
//2. Произведение элементов матрицы
//3. Максимальный элемент матрицы
//4. Минимальный элемент матрицы
//5. Сумма элементов главной диагонали матрицы
//6. Произведение элементов главной диагонали матрицы
//7. Максимальный элемент, расположенный на главной диагонали матрицы
//8. Минимальный элемент, расположенный на главной диагонали матрицы
//9. Сумма элементов побочной диагонали матрицы
//10. Произведение элементов побочной диагонали матрицы
//11. Максимальный элемент, расположенный на побочной диагонали матрицы
//12. Минимальный элемент, расположенный на побочной диагонали матрицы
//13. Поиска минимального из максимальных элементов матрицы, то есть найти максимальный элемент в каждой из строк матрицы и из них выбрать минимальный
//14. Транспонирование для квадратной матрицы, то есть переворот матрицы относительно главной диагонали( про это можно прочитать тут https://ru.wikipedia.org/wiki/%D0%A2%D1%80%D0%B0%D0%BD%D1%81%D0%BF%D0%BE%D0%BD%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%BD%D0%B0%D1%8F_%D0%BC%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B0 )
//15. Сумма двух матриц одинаковых размерностей.
//16. Печать матрицы на экран
//Все эти функции необходимо корректно вызвать внутри функции main и показать их корректную работу, то есть после ввода матрицы необходимо напечатать матрицу и ответы функций, после выполнения функций, печатающих матрицу на экран, необходимо печатать матрицу на экран.

#include <iostream>
using namespace std;
#include <ctime>

void FulFill(int matrix[3][3])
{
    srand(time(NULL));
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            matrix[i][j] = rand() % 100 - 10;
        }
    }
}
void outputMatrix(const int matrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int Sum(int matrix[3][3])
{
    int sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}
unsigned long long MulMatrix(int matrix[3][3])
{
    unsigned long long mul = 1;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            mul *= matrix[i][j];
        }
    }
    return mul;
}

int MaxElement(int matrix[3][3])
{
    int max = matrix[0][0];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if(max < matrix[i][j])
                max = matrix[i][j];
        }
    }
    return max;
}
int MinElement(int matrix[3][3])
{
    int min = matrix[0][0];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if(min > matrix[i][j])
                min = matrix[i][j];
        }
    }
    return min;
}

int SumMainDiagonal(int matrix[3][3])
{
    int sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        sum += matrix[i][i];
    }
    return sum;
}
unsigned long long MulMainDiagonal(int matrix[3][3])
{
    unsigned long long mul = 1;
    for (int i = 0; i < 3; ++i)
    {
        mul *= matrix[i][i];
    }
    return mul;
}

int MaxMainDiagonal(int matrix[3][3])
{
    int max = matrix[0][0];
    for (int i = 0; i < 3; ++i)
    {
        if (max < matrix[i][i])
            max = matrix[i][i];
    }
    return max;
}
int MinMainDiagonal(int matrix[3][3])
{
    int min = matrix[0][0];
    for (int i = 0; i < 3; ++i)
    {
        if (min > matrix[i][i])
            min = matrix[i][i];
    }
    return min;
}

int SumSideDiagonal(int matrix[3][3])
{
    int sum = 0;
    int n = 3;
    for (int i = 0; i < n; ++i)
    {
        sum += matrix[i][n - 1 - i];
    }
    return sum;
}
int MulSideDiagonal(int matrix[3][3])
{
    int mul = 1;
    int n = 3;
    for (int i = 0; i < n; ++i)
    {
        mul *= matrix[i][n - 1 - i];
    }
    return mul;
}

int MaxSideDiagonal(int matrix[3][3])
{
    int max = matrix[0][0];
    int n = 3;
    for (int i = 0; i < n; ++i)
    {
        if(max < matrix[i][n - 1 - i])
         max = matrix[i][n - 1 - i];
    }
    return max;
}
int MinSideDiagonal(int matrix[3][3])
{
    int min = matrix[0][0];
    int n = 3;
    for (int i = 0; i < n; ++i)
    {
        if(min > matrix[i][n - 1 - i])
            min = matrix[i][n - 1 - i];
    }
    return min;
}

int MinMaxElement(int matrix[3][3])
{
    int MaxArray[3];
    for (int i = 0; i < 3; ++i)
    {
        int max = matrix[i][0];
        for (int j = 0; j < 3; ++j)
        {
            if(max < matrix[i][j])
                max = matrix[i][j];
        }
        MaxArray[i] = max;
    }
    int result = MaxArray[0];
    for (int i = 0; i < 3; ++i)
    {
        if (MaxArray[i] < result)
            result = MaxArray[i];
    }
    return result;
}


void Transposition(int matrix[3][3], int Tmatrix[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            Tmatrix[i][j] = matrix[j][i];
        }
    }
}

void outputTmatrix(int Tmatrix[3][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
        {
            cout << Tmatrix[i][j] << " ";
        }
        cout << endl;
    }
}
void SumofTwoMatrix(int matrix[3][3], int Tmatrix[3][3], int SummMatrix[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            SummMatrix[i][j] = matrix[i][j] + Tmatrix[i][j];
        }
    }
}
void outputSumMatrix(int SummMatrix[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << SummMatrix[i][j] << " ";
        }
        cout << endl;
    }
}



int main()
{
    const size_t ROW = 3;
    const size_t COL = 3;

    int matrix[ROW][COL];
    int Tmatrix[ROW][COL];
    int SummMatrix[ROW]{COL};

    FulFill(matrix);
    outputMatrix(matrix);
    cout << endl;

    cout << "Sum elements of matrix: " << Sum(matrix) << endl;
    cout << "Multiplication elements of matrix: " << MulMatrix(matrix) << endl;
    cout << "Max element of matrix: " << MaxElement(matrix) << endl;
    cout << "Min element of matrix: " << MinElement(matrix) << endl;
    cout << "Sum elements of the matrix's main diagonal: " << SumMainDiagonal(matrix) << endl;
    cout << "Multiplication of the matrix's main diagonal: " << MulMainDiagonal(matrix) << endl;
    cout << "Max element of the matrix's main diagonal: " << MaxMainDiagonal(matrix) << endl;
    cout << "Min element of the matrix's main diagonal: " << MinMainDiagonal(matrix) << endl;
    cout << "Sum elements of the matrix's side diagonal: " << SumSideDiagonal(matrix) << endl;
    cout << "Multiplication of the matrix's side diagonal: " << MulSideDiagonal(matrix) << endl;
    cout << "Max element of the matrix's side diagonal: " << MaxSideDiagonal(matrix) << endl;
    cout << "Min element of the matrix's side diagonal: " << MinSideDiagonal(matrix) << endl;
    cout << "Minimal element among max: " << MinMaxElement(matrix) << endl;
    cout << endl;

    Transposition(matrix, Tmatrix);
    outputTmatrix(Tmatrix);

    SumofTwoMatrix(matrix, Tmatrix, &SummMatrix);
    outputSumMatrix(&SummMatrix);


    return 0;

}
