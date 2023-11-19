//ИВТ-22 Жук Никита

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <string>
#include <vector>

using namespace std;
namespace z136 {
///Заполнение массива случайными числами от Min_rand до Max_rand
void FillRand(vector<double>& array, float Max_rand, float Min_rand)
{
	unsigned n = array.size();
	int DRand = Max_rand - Min_rand; 				//Диапазон рандома	
	for(unsigned i = 0; i < n; i ++)
	{
		//(float)rand()/RAND_MAX выдает значение от 0 до 1
		//*DRand превращает значение в число из диапазона
		//+Down_board задаёт нач. значение
		array[i] = ((float)rand()/RAND_MAX*DRand+Min_rand);
	}
}

///Вычисляет сумму по условиям задачи 136(з)
double zad136z(const vector<double>& array)
{
	int negative = 1, factorial = 1;					//знакопеременность и факториал
	float result = -1*array[0];
	for(unsigned i = 1; i < array.size(); i ++)
	{
		factorial = factorial * (i+1);
		result=result+(negative*array[i]/factorial);
		negative = -negative;
	}
	return result;
}

///Вывод массива в файл
void WriteArrayF(const vector<double>& array, const string &file_name)
{
	ofstream file(file_name, ios::binary);
    if (!file.is_open())								//Проверка открытия файла
	{
		throw runtime_error("File opening error") ;

	}
	else
	{
    	for (unsigned long int i = 0; i < array.size(); i++)
        {
            file << array[i] << endl;
        }
        file.close();
	}
};

///Ищет размер файла file_name в виде числа строк
int FileSize(const string &file_name)
{
	string empty_line;									//Пустая строка для подсчёта
	unsigned result = 0;
	ifstream file(file_name);

	if (!file.is_open())								//Проверка открытия файла
	{
		throw runtime_error("File opening error");
	}

	while (getline(file, empty_line))
	{
		result++;
	}

	if (result == 0)									
	{
		throw invalid_argument("File is empty");
	}

	file.close();
	return (result);
};

///Загрузка массива размера n из файла
void GetArrayF(vector<double>& array, unsigned size, const string &file_name)
{
    ifstream file(file_name, ios::binary);
    if (!file.is_open())								//Проверка открытия файла
    {
        throw runtime_error("File opening error");
    }
    else
    {
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        array.resize(size);
        file.read(reinterpret_cast<char*>(array.data()), sizeof(double) * size);
        file.close();
    }

}
}



