//ИВТ-22 Жук Никита
#ifndef MOD136Z_H
#define MOD136Z_H
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

namespace z136								
{
///Заполнение массива случайными числами от Min_rand до Max_rand
void FillRand(vector<double>& array, float Max_rand, float Min_rand);

///Вычисляет сумму по условиям задачи 136з
double zad136z(const vector<double>& array);

///Вывод массива в файл
void WriteArrayF(const vector<double>& array, const string &file_name);

///Ищет размер файла в виде числа строк
int FileSize(const string &file_name);

///Загрузка массива из файла
void GetArrayF(vector<double>& array, unsigned size, const string &file_name);

///Вывод массива на экран
template<typename T> // шаблонный тип
void PrintArray(const vector<T>& array)
{
	for(unsigned i=0; i<array.size(); i++)
	{
		cout << array[i] << " ";
	}
}

}

#endif