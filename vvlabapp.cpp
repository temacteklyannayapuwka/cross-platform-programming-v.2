#include <stdio.h> //библиотека ввода-вывода
#include <stdlib.h> //использование динамической памяти
#include <locale.h> //подключение файла русского языка
#include <math.h> //вычисление корня
#include <iostream> //использование потоков

using namespace std;
int** input(int n, int m)//ввод матрицы
{
	int i, j;
	int** a;
	a = (int**)malloc(m * sizeof(int*));
	for (i = 0; i < m; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int*));
		for (j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("Введите элемент матрицы A[%d] [%d]: ", i + 1, j + 1);
			scanf_s("%d", &a[i][j]);
		}
	}
	return a;
}

int** input2(int n, int m, int r)//создание псевдослучайных элементов матрицы
{
	int i, j;
	int** a;
	a = (int**)malloc(m * sizeof(int*));
	for (i = 0; i < m; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int*));
		for (j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = rand() % r;
		}
	}
	return a;
}
void output(int** z, int m, int n)//функция вывода матрицы
{
	int i, j;
	printf("Результирующая матрица:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf(" %8d", z[i][j]);
		printf("\n");
	}
}
int umnojenie(int** z, int m, int n)//умножение на число
{
	int i, j;
	int number=0;
	float otvet1;
	cout << "Введите число, на которое нужно умножить матрицу: ";
	cin >> number; // число
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> z[i][j];
			z[i][j] = z[i][j] * number;
		}
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << z[i][j] << " \t"; // Вывести элементы на консольку
		}
		cout << endl; // Двумерный массив. Строка кончилась, переводим строку и на консоли
        }
	}

	otvet1 = z[i][j];
	printf("Умноженная матрица: %d\n", otvet1);
	}
int menu()//функция меню для взаимодействия с пользователем
{
	setlocale(LC_ALL, "Russian");
	int m, n, r, k, i, j, number;
	r = 100;
	printf("Введите размер исходной матрицы\n");
	printf("Число строк = ");
	scanf_s("%d", &m);
	printf("Число столбцов = ");
	scanf_s("%d", &n);
        
	int** p;
	p = input2(m, n, r);//нужно как нибудь инициализировать переменную р до оператора switch
	int** A;//создаем еще какой нибудь массив, чтобы потом сохранить массив перед вычислением нормы для транспонирования начальной матрицы
	A = input2(m, n, r);
	char t;
	for (k = 1; k == 1; k++)
	{
		printf("Желаете заполнить матрицу автоматически?\nЧтобы заполнить матрицу автоматически введите Y, чтобы заполнить вручную введите N - \n");
		cin >> t;
		switch (t)
		{
		case 'n':
			p = input(m, n);
			break;
		case 'N':
			p = input(m, n);
			break;
		case 'y':
			p = input2(m, n, r);
			break;
		case 'Y':
			p = input2(m, n, r);
			break;
		default:
			cout << "Вы неверно указали тип заполнения массива, попробуйте еще раз.\n";
			k--;
			break;
		}
	}
	//сохраняем массив в переменной А
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			A[i][j] = p[i][j];
		}
	}
	output(p, m, n);

}
//added some trash string
//hello
//stavropol
