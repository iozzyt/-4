#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

class Number		//����� number ��� �������� ���������� ����� 
{
private:
	float fracpart, numb, res;
	int intpart;
public:

	Number()		//����������� �� ���������
	{
			numb = 0;
			fracpart = 0;
			intpart = 0;
			res = 0;
	}

	Number(float num)		//����������� �������������
	{
		setNumber(num);
	}

	Number(const Number& obj)		//copy constructor
	{
		fracpart = obj.fracpart;
		intpart = obj.intpart;
		res = obj.res;
		numb = obj.numb;
	}


	void setNumber(float num)		//��������� ������
	{
		numb = num;
		fracpart = num - (int)num;
		intpart = (int)num;
	}
	void getNumber()	//����� ��������� ������ �����
	{
		cout << "Number: " << numb << endl;
	}
	void invNumber()		//����� �������������� �����
	{
		res = numb*(-1);
		cout << "invNumber: " << res << endl;

	}
	void getlastres()		//����� ������ ���������� ����������
	{
		cout << "last res: " << res << endl;
	}
	void getfracpart()		//output frac part
	{
		cout << "fracpart: " << fracpart << endl;
	}
	void getintpart()		//output int part
	{
		cout << "intpart: " << intpart << endl;
	}
	void powerNumber(int power)
	{
		res = pow(numb,power);
		cout << "powerNumber: " << res << endl;
	}
	void xNumber(float x)
	{
		res = x*numb;
		cout << "xNumber: " << res << endl;
	}

	void plusNumber(float x)
	{
		res = numb + x;
		cout << "plusNumber: " << res << endl;
	}
	
	~Number()		//����������
	{

	}
};

class Tree
{

};

int main()
{	
	Number obj, obj1;
	obj1 = 12.7;
	obj.getNumber();
	obj1.getNumber();
	obj1.getintpart();
	obj1.getfracpart();
	obj1.powerNumber(2);
	cout << "press enter for close" << endl;
	getchar();
	//system("pause");
	return 0;
}