#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

class Number		//класс number для хранения десятичных чисел 
{
private:
	float fracpart, numb;
	int intpart;
public:
	float res;
	Number()		//конструктор по умолчанию
	{
		numb = 0;
		fracpart = 0;
		intpart = 0;
		res = 0;
	}
	bool operator<(Number num)
	{
		return numb < num.numb;
	}
	friend std::ostream& operator<<(std::ostream& os, Number num)
	{
		return os << num.numb;
	}

	Number(float num)		//конструктор инициализации
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


	void setNumber(float num)		//установка класса
	{
		numb = num;
		fracpart = num - (int)num;
		intpart = (int)num;
	}
	void getNumber()	//вывод перменной класса номер
	{
		cout << "Number: " << numb << endl;
	}
	void invNumber()		//метод инвертирования знака
	{
		res = numb*(-1);
		cout << "invNumber: " << res << endl;

	}
	void getlastres()		//метод вывода последнего результата
	{
		return res;
	}
	void getfracpart()		//output frac part
	{
		return fracpart;
	}
	void getintpart()		//output int part
	{
		return intpart;
	}
	void powerNumber(int power)		//возведение объекта в степень
	{
		res = pow(numb, power);
		return res;
	}
	void xNumber(float x)		//умножение объекта на число
	{
		res = x*numb;
		return res;
	}

	void plusNumber(float x)		//прибавление числа к объекту
	{
		res = numb + x;
		return res;
	}

	~Number()		//деструктор
	{

	}
};

template<class Item>
class tree
{
private:
	struct node
	{
		Item item;
		node * left, *right;
		node(Item item = Item()) :item(item)
		{
			left = right = nullptr;
		}

		static void add(node*& curr, Item &item)
		{
			if (!curr)
			{
				curr = new node(item);

			}
			else if (curr->item<item)
				add(curr->left, item);
			else
				add(curr->right, item);
		}
		static node* deepcopy(node* from)
		{
			if (!from)return nullptr;
			node * res = new node(from->item);
			res->left = deepcopy(from->left);
			res->right = deepcopy(from->right);
			return res;
		}
		static void print(node*curr, std::ostream& os, std::string spacer = "")
		{
			if (curr)
			{
				print(curr->left, os, spacer + "   ");
				os << &spacer[0];
				os << curr->item << "\n";
				print(curr->right, os, spacer + "   ");
			}
		}

		static void clear(node*&curr)
		{
			if (curr)
			{
				clear(curr->left);
				clear(curr->right);
				delete curr;
			}
		}
	}*head;
public:
	tree()
	{
		head = nullptr;
	}
	tree(const tree& t)
	{
		head = node::deepcopy(t.head);
	}
	tree operator=(tree t)
	{
		head = node::deepcopy(t.head);
		return t;
	}
	friend std::ostream& operator<<(std::ostream& os, tree t)
	{
		node::print(t.head, os);
		return os;
	}

	void add(Item item = Item())
	{
		node::add(head, item);
	}
	void clear()
	{
		node::clear(head);
		head = nullptr;
	}
	~tree()
	{
		clear();
	}


};

int main()
{	
	Number obj1;
	obj1 = 12.7;
	obj1.getNumber();
	obj1.getNumber();
	obj1.getintpart();
	obj1.getfracpart();
	obj1.powerNumber(2);
	tree<Number> obj;
	obj.add(10);
	obj.add(9);
	obj.add(15);
	obj.add(10);
	obj.add(9);
	obj.add(15);
	cout << obj;
	cout << "press enter for close" << endl;
	getchar();
	//system("pause");
	return 0;
}