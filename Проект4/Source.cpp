#include <stdio.h>
#include <iostream>

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



	void setNumber(int num)		//��������� ������
	{
		cin >> num;
		numb = num;
		fracpart = num - (int)num;
		intpart = (int)num;
	}
	void getNumber()	//����� ��������� ������ �����
	{
		cout << numb;
	}
	void invNumber(float numb)		//����� �������������� �����
	{
		float r;
		res = numb*(-1);

	}
	void getres()		//����� ������ ����������
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
	~Number()		//����������
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