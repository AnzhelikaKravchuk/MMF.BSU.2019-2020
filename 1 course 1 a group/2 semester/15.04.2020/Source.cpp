//Разработать шаблонный класс «матрица»
//Обеспечить представление матрицы произвольного размера (по умолчанию  50x50)
//и типа (по умолчанию double)  с помощью шаблона класса.
//Выполнить перегрузку арифметических операций, операций присваивания,
//ввода с клавиатуры, вывода на экран, индексирования[].
//Реализовать в конструкторе автоматическое генерирование имени матрицы («матрица 1», «матрица 2» и т.д.),
//используя для этого статическое поле – счетчик объектов класса. Реализовать метод вывода матрицы на
//экран с одновременным выводом ее имени. В основном модуле программы (файл main.cpp) определить массив
//указателей (проинициализировав его адресами объявленных матриц-объектов, требуемых по условию задания)
//и функцию Show(), которой передаются данный массив и количество матриц (для вывода на
//экран перечня всех матриц с их значениями).
//
//Реализовать следующие операции над матрицами:
//•	сложения, вычитания;
//•	умножения и деления на число;
//•	присваивания (+=, -=, *=, /=);
//•	сравнения на равенство/неравенство;
//•	нахождения наименьшего/наибольшего элемента матрицы;
//•	вычисления суммы элементов, расположенных в заданном столбце/строке;
//•	получения вектора из минимальных значений элементов столбцов матрицы;
//•	ввода/вывода в стандартные потоки матрицы;
//•	возведения в степень;
//При необходимости добавить в класс другие методы.
//Создать 3 матрицы и присвоить одной из них произведение двух других.

#include <cmath>
#include <fstream>
#include "GenericMatrix.h"

template <typename T>
void init(istream& in, GenericMatrix<T>** matrixs, int n)
{
    cout << "Filling matrixes from stream" << endl;
    for (int i = 0; i < n; i++)
    {
        in >> *matrixs[i];
    }
    return;
}

template <typename T>
void show(ostream& out, GenericMatrix<T>** matrixs, int n)
{
    cout << "Saving matrixes in stream" << endl;
    for (int i = 0; i < n; i++)
    {
        out << *matrixs[i] << endl;
    }
}

template <typename T>
void work(ostream& out, GenericMatrix<T>** matrixs, int n)
{
    out << "Min columns formation " << endl;
    for (int i = 0; i < n; i++)
    {
        out << *matrixs[i];
        out << "--->";
        T* mins = matrixs[i]->minValueColumnArrayGeneration();
        for (int j = 0; j < matrixs[i]->getColumns(); j++)
        {
            out << mins[j] << " ";
        }
        out << endl;
        delete[] mins;
    }
}

int main()
{
    const char* pathin = "matrixs.txt";
    ifstream in(pathin);
    if (!in.is_open())
    {
        cout << "Can not open file " << pathin << " to read!" << endl;
        return 0;
    }
    const char* pathout = "result.txt";
    ofstream out(pathout);
    if (!out.is_open())
    {
        cout << "Can not open file " << pathout << " ro write!" << endl;
        return 0;
    }
    int countMatrixs = 6;
    GenericMatrix<>** matrixs;
    try
    {
        matrixs = new GenericMatrix<> * [countMatrixs];
        for (int i = 0; i < countMatrixs; i++)
        {
            int rows = rand() % 5 + 1;
            int columns = rand() % 7 + 1;
            matrixs[i] = new GenericMatrix<>(rows, columns);
        }
    }
    catch (const char* result)
    {
        cout << result << endl;
        exit(1);
    }
    catch (bad_alloc& ex)
    {
        cout << "Allocation error " << ex.what() << endl;
        exit(1);
    }

    init(in, matrixs, countMatrixs);
    show(out, matrixs, countMatrixs);

    try
    {
        GenericMatrix<> mtrx1(5, 6), mtrx2(6, 4), mtrx3(5, 6);
        in >> mtrx1 >> mtrx2 >> mtrx3;
        mtrx3 = mtrx1 * mtrx2;
        out << "Matrix- product" << endl;
        out << mtrx1 << endl;
        out << mtrx2 << endl;
        out << mtrx3 << endl;
        out << "Set after addition" << endl;
        mtrx3 += mtrx2;
        out << mtrx3 << endl;
        int power = 3;
        GenericMatrix<> mtrx4(4, 4), mtrx5(4, 4);
        mtrx4.identityMatrix();
        out << "Calculate matrix in degree" << power << endl;
        out << mtrx4 << endl;
        mtrx5 = mtrx4.power(power);
        out << mtrx5 << endl;
        out << "Devide by number" << power << endl;
        out << mtrx4 << endl;
        mtrx5 = mtrx4 / 3.;
        out << mtrx5 << endl;
    }
    catch (const char* result)
    {
        out << result << endl;
    }
    catch (bad_alloc& ex)
    {
        cout << "Allocation error " << ex.what() << endl;
        exit(1);
    }
    work(out, matrixs, countMatrixs);
    return 0;
}