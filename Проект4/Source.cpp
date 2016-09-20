#include <stdio.h>
#include <iostream>

using namespace std;

class Number		//класс number для хранения десятичных чисел 
{
private:
	float fracpart, numb, res;
	int intpart;
public:

	Number()		//конструктор по умолчанию
	{
			numb = 0;
			fracpart = 0;
			intpart = 0;
			res = 0;
	}

	Number(float num)		//конструктор инициализации
	{
		setNumber(num);
	}



	void setNumber(int num)		//установка класса
	{
		cin >> num;
		numb = num;
		fracpart = num - (int)num;
		intpart = (int)num;
	}
	void getNumber()	//вывод перменной класса номер
	{
		cout << numb;
	}
	void invNumber(float numb)		//метод инвертирования знака
	{
		float r;
		res = numb*(-1);

	}
	void getres()		//метод вывода результата
	{

	}
	void getfracpart()
	{
		cout << fracpart;
	}
	void getintpart()
	{
		cout << intpart;
	}
	~Number()		//деструктор
	{

	}
};

class Tree
{

};

int main()
{	
	Number obj;
	obj.getNumber();
	std::cout << "hello word" <<std::endl;
	cout << "press enter for close" << endl;
	getchar();
	return 0;
}