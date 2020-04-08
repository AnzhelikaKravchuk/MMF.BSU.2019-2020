#ifndef GenericMatrix_h
#define GenericMatrix_h

#define size 5
#define length 10
#define accurancy 0.000001

#include <iostream>

using namespace std;

//класс для работы с обобщенными прямоугольными матрицами
template<typename T = double>
class GenericMatrix
{
public:
    GenericMatrix(int = size, int = size);
    GenericMatrix(T**, int, int);
    GenericMatrix(const GenericMatrix&);
    ~GenericMatrix();
    int getRows() const;
    int getColumns() const;
    void identityMatrix();
    GenericMatrix& operator = (const GenericMatrix&);
    double norm() const;
    GenericMatrix operator + (const GenericMatrix&) const;
    GenericMatrix operator += (const GenericMatrix&);
    GenericMatrix operator - () const;
    GenericMatrix operator - (const GenericMatrix&) const;
    GenericMatrix operator -= (const GenericMatrix&);
    GenericMatrix operator * (const GenericMatrix&) const;
    GenericMatrix operator *= (const GenericMatrix&);
    GenericMatrix power(int) const;
    T sumElementsInColumn(int) const;
    T sumElementsInRow(int) const;
    T* minValueColumnArrayGeneration();
    bool operator == (const GenericMatrix&) const;
    bool operator != (const GenericMatrix&) const;
    T* const operator [] (int) const;
    GenericMatrix operator * (T) const;
    GenericMatrix operator / (T) const;
    T findMax() const;
    T findMin() const;
    int getIdentity() const;
    template<typename U>
    friend ostream& operator << (ostream& stream, const GenericMatrix<U>& mtrx);
    template<typename U>
    friend istream& operator >> (istream& stream, const GenericMatrix<U>& mtrx);
private:
    T** matrix;
    int n, m;
    int identity;
    static int nextId;
    void setRows(int);
    void setColumns(int);
    static T** allocateMemory(int, int);
    static void freeMemory(T**, int);
    static void randomMatrix(T**, int, int);
    T** copyToMatrix() const;
};
#endif /* GenericMatrix_h */

template<typename T>
int GenericMatrix<T>::nextId = 0;

template<typename T>
ostream& operator << (ostream& stream, const GenericMatrix<T>& mtrx)
{
    int n = mtrx.getRows(), m = mtrx.getColumns();
    for (int i = 0; i < m * length + length; i++)
    {
        stream << "-";
    }
    stream << endl;
    stream << "Matrix # " << mtrx.getIdentity()
        << " (" << mtrx.getRows() << " x " << mtrx.getColumns() << ") :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            stream.width(length);
            stream << mtrx.matrix[i][j];
        }
        stream << endl;
    }
    for (int i = 0; i < m * length + length; i++)
    {
        stream << "-";
    }
    stream << endl;
    return stream;
}

template<typename T>
istream& operator >> (istream& stream, const GenericMatrix<T>& mtrx)
{
    int n = mtrx.getRows(), m = mtrx.getColumns();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            stream >> mtrx.matrix[i][j];
        }
    }
    return stream;
}

//конструктор для инициализации объекта-матрицы, с n-строкам и m-столбцами
//и нулевыми элементами
template<typename T>
GenericMatrix<T>::GenericMatrix(int n, int m)
{
    setRows(n);
    setColumns(m);

    matrix = allocateMemory(this->n, this->m);
    identity = ++nextId;
}

//конструктор для инициализации объекта-матрицы, с n-строками и m-столбцами
//и элементами из маcсива array
template<typename T>
GenericMatrix<T>::GenericMatrix(T** array, int n, int m)
{
    setRows(n);
    setColumns(m);

    matrix = allocateMemory(this->n, this->m);
    identity = ++nextId;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = array[i][j];
        }
    };
}

template<typename T>
void GenericMatrix<T>::identityMatrix()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 1;
        }
    };
}

//Set-аксессор  для строк
template<typename T>
void GenericMatrix<T>::setRows(int n)
{
    this->n = n > 0 ? n : throw "Size can not be negative";
}

//Set-аксессор  для столбцов
template<typename T>
void GenericMatrix<T>::setColumns(int m)
{
    this->m = m > 0 ? m : throw "Size can not be negative";
}

template<typename T>
T* const GenericMatrix<T>::operator [] (int i) const
{
    if (i >= 0 && i <= n)
    {
        return matrix[i];
    }
    else
    {
        throw "Index out of range!";
    }
}

//конструктор копирования
template<typename T>
GenericMatrix<T>::GenericMatrix(const GenericMatrix<T>& other)
{
    n = other.getRows();
    m = other.getColumns();

    setRows(n);
    setColumns(m);
    matrix = other.copyToMatrix();
    identity = ++nextId;
}

template<typename T>
T GenericMatrix<T>::findMax() const
{
    T max = matrix[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (comparer(matrix[i][j], max) > 0)
            {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

template<typename T>
T GenericMatrix<T>::findMin() const
{
    T min = matrix[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (comparer(matrix[i][j], min) < 0)
            {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

template<typename T>
GenericMatrix<T> GenericMatrix<T>::power(int n) const
{
    if (n <= 1)
    {
        throw "Value of degree can not be less than 1.";
    }
    GenericMatrix result(*this);
    for (int i = 2; i <= n; i++)
    {
        result *= *this;
    }
    return result;
}

//деструктор
template<typename T>
GenericMatrix<T>::~GenericMatrix()
{
    try
    {
        freeMemory(matrix, n);
    }
    catch (runtime_error& ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
}

//get-аксессор для строк
template<typename T>
int GenericMatrix<T>::getRows() const
{
    return n;
}

//get-аксессор для столбцов
template<typename T>
int GenericMatrix<T>::getColumns() const
{
    return m;
}

//перегрузка операции присваивания
//не побитовое копирование полей, а глубокое поэлементное копирование
template<typename T>
GenericMatrix<T>& GenericMatrix<T>::operator = (const GenericMatrix<T>& other)
{
    if (&other == this)
        return *this;
    n = other.n;
    m = other.m;
    matrix = other.copyToMatrix();//!
    return *this;
}

template<typename T>
bool GenericMatrix<T>::operator == (const GenericMatrix<T>& other) const
{
    if (this->n != other.n || this->m != other.m)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fabs(matrix[i][j] - other.matrix[i][j]) > accurancy)
            {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
bool GenericMatrix<T>::operator != (const GenericMatrix& other) const
{
    return !(*this == other);
}

//функция вычисления нормы матрицы как максимума по
//строкам суммы модулей по столбцам
template<typename T>
double GenericMatrix<T>::norm() const
{
    double nrm = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < m; j++)
        {
            temp += fabs(matrix[i][j]);
        }
        if (nrm < temp)
        {
            nrm = temp;
        }
    }
    return nrm;
}

template<typename T>
T* GenericMatrix<T>::minValueColumnArrayGeneration()
{
    T* minArray = new T[m];
    for (int j = 0; j < m; j++)
    {
        T min = matrix[0][j];
        for (int i = 1; i < n; i++)
        {
            if (min > matrix[i][j])
            {
                min = matrix[i][j];
            }
        }
        minArray[j] = min;
    }
    return minArray;
}

//перегрузка операции сложения для двух матриц
template<typename T>
GenericMatrix<T> GenericMatrix<T>::operator + (const GenericMatrix<T>& other) const
{
    if (this->n != other.n && this->m != other.m)
    {
        throw "Невозможно вычислить сумму или разность матриц, для которых количество строк и столбцов не совпадают!";
    }

    GenericMatrix<T> result(*this);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result.matrix[i][j] += other.matrix[i][j];
        }
    }
    return result;
}

//перегрузка операции вычитания для двух матриц
template<typename T>
GenericMatrix<T> GenericMatrix<T>::operator - (const GenericMatrix<T>& other) const
{
    return *this + (-other);
}

//перегрузка унарной операции минус (для упрощения реализации перегрузки вычитания)
template<typename T>
GenericMatrix<T> GenericMatrix<T>::operator - () const
{
    GenericMatrix<T> result(*this);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result.matrix[i][j] = -result.matrix[i][j];
        }
    }
    return result;
}

//перегрузка операции умножения для двух матриц
template<typename T>
GenericMatrix<T> GenericMatrix<T>::operator * (const GenericMatrix<T>& other) const
{
    int n = this->n, m = this->m, k = other.n, l = other.m;
    if (m != k)
    {
        throw "Невозможно вычислить произведение матриц, для которых количество строк первой не совпадает с количеством столбцов второй!";
    }

    GenericMatrix<T> result(n, l);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            double tmp = 0;
            for (int ii = 0; ii < m; ii++)
            {
                tmp += matrix[i][ii] * other.matrix[ii][j];
            }
            result.matrix[i][j] = tmp;
        }
    }
    return result;
}

//перегрузка операции присваивания после вычитания для двух матриц
template<typename T>
GenericMatrix<T> GenericMatrix<T>::operator -= (const GenericMatrix<T>& other)
{
    *this = *this - other;
    return *this;
}

//перегрузка операции присваивания после сложения для двух матриц
template<typename T>
GenericMatrix<T> GenericMatrix<T>::operator += (const GenericMatrix<T>& other)
{
    *this = *this + other;
    return *this;
}

//перегрузка операции присваивания после умножения для двух матриц
template<typename T>
GenericMatrix<T> GenericMatrix<T>::operator *= (const GenericMatrix<T>& other)
{
    *this = *this * other;
    return *this;
}

//перегрузка операции умножения матрицы на число
template<typename T>
GenericMatrix<T> GenericMatrix<T>::operator * (T number) const
{
    int n = this->n, m = this->m;

    GenericMatrix<T> result(*this);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result.matrix[i][j] = number * result.matrix[i][j];
        }
    }
    return result;
}

//перегрузка операции деления матрицы на число
template<typename T>
GenericMatrix<T> GenericMatrix<T>::operator / (T number) const
{
    return *this * (1. / number);
}

//protected функция получения на основе объекта динамического двумерного массива
template<typename T>
T** GenericMatrix<T>::copyToMatrix() const
{
    int n = getRows(), m = getColumns();

    T** mtrx = allocateMemory(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mtrx[i][j] = this->matrix[i][j];
        }
    }
    return mtrx;
}

template<typename T>
T GenericMatrix<T>::sumElementsInColumn(int columnIndex) const
{
    T result = matrix[0][columnIndex];
    for (int i = 1; i < n; i++)
    {
        result += matrix[i][columnIndex];
    }
    return result;
}

template<typename T>
T GenericMatrix<T>::sumElementsInRow(int rowIndex) const
{
    T result = matrix[rowIndex][0];
    for (int j = 1; j < m; j++)
    {
        result += matrix[rowIndex][j];
    }
    return result;
}

template<typename T>
int GenericMatrix<T>::getIdentity() const
{
    return identity;
}

//private функции-утилиты для работы с динамическими массивами
//существует ли стандартный тип исключения для delete ?
template<typename T>
void GenericMatrix<T>::freeMemory(T** array, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

template<typename T>
T** GenericMatrix<T>::allocateMemory(int n, int m)
{
    T** matrix = new T * [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new T[m];

        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

template<typename T>
void GenericMatrix<T>::randomMatrix(T** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}