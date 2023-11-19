//ИВТ-22 Жук Никита
//Задача 136з  https://ivtipm.github.io/Programming/Glava06/index06.htm#z136
//Даны натуральное число n, действительные числа a1,..., an. Вычислить:
//  (-1)^n*a[n]/n!

#include <cassert>
#include <iostream>
#include <vector>
#include "mod136z.h"

using namespace std;
using namespace z136;

int main(int argc, char* argv[])
{
	string arg1 = "null";

	{
	vector<double> v1 = {1,1,1};						//Проверка assert
	assert((zad136z(v1) < -0.66) && (zad136z(v1) > -0.67));
	}
	{
	vector<double> v2 = {3,3,3};
	assert(zad136z(v2)== -2);
	}
	{
	vector<double> v3 = {1,2,3};
	assert(zad136z(v3)== -0.5);
	}

	unsigned answer = -1;								//Для выбора заполнения								
	unsigned n;											//Размер
	float max;										    //Макс. граница рандома
	float min;											//Мин. граница рандома
	string fileName;									//Имена файлов
	vector<double> a;									//Рабочий вектор



	if (arg1 != "help")
	{
		srand(time(nullptr));										//Настройка рандома

		if ((arg1 != "rand")&&(arg1 != "help")&&(arg1 != "load"))	//(Если y аргументы командной строки, то использовать их)
		{ 
			cout << "To load from file type 1, to random array`s build enter -1:" << endl;			//Выбор вида заполнения массива:
			cin >> answer;
		}

		if ((answer == 1)||(arg1 == "load"))						//1:Заполнение из файла
		{
			if (arg1 == "load")										//(Если есть аргументы командной строки, то использовать их)
			{
				fileName = argv[2];
			}
			else
			{
			cout << "Enter file name (with .txt):" << endl;			//Ввод имени файла для ввода данных	
			cin >> fileName;
			}

			try{													//Проверка открытия файла и проверка наличия чисел в файле
			n = FileSize(fileName);									
			}
			catch(char const* error)
			{
				cout << error << endl;		
			}

			try{													//Проверка открытия файла
			GetArrayF(a, n, fileName);
			}
			catch(char const* error)
			{
				cout << error << endl;		
			}
		}
		else														//2:Заполнение случайно
		{
			if (arg1 == "rand")										//(Если есть аргументы командной строки, то использовать их)
			{
				n = stoi(argv[2]);
				a.resize(n);
				max = stod(argv[3]);
				min = stod(argv[4]);
			}
			else
			{
			cout << "Set size:" << endl;							//Ввод данных если нет аргументов строки
			cin >> n;
			a.resize(n);
			cout << "Set min rand:" << endl;
			cin >> max;
			cout << "Set max rand:" << endl;
			cin >> min;
			}

			FillRand(a, max, min);

		}

		cout << "Array A:" << endl;								//Вывод массива на экран
		PrintArray(a);
		cout << endl;

		cout << "Total sum: " << zad136z(a) << endl;   			//Вывод итоговой суммы

		cout << "To save array in write 1:" << endl; 			//Сохранение массива в файл по выбору
		cin >> answer;
		if (answer == 1)									
		{
			cout << "Enter file name (with .txt):" << endl;		//Ввод имени файла для сохранения
			cin >> fileName;

			try{												//Проверка открытия файла
				WriteArrayF(a, fileName);
			}
			catch(char const* error)
			{
				cout << error << endl;
			}
		}
	}
}
