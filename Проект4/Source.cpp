#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

class Number		//����� number ��� �������� ���������� ����� 
{
private:
	float fracpart, numb;
	int intpart;
public:
	float res;
	Number()		//����������� �� ���������
	{
		numb = 0;
		fracpart = 0;
		intpart = 0;
		res = 0;
	}
	bool operator<(Number num)		//������������� ���������
	{
		return numb < num.numb;
	}
	friend std::ostream& operator<<(std::ostream& os, Number num)
	{
		return os << num.numb;
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
	float getNumber()	//����� ��������� ������ �����
	{
		return numb;
	}
	float invNumber()		//����� �������������� �����
	{
		res = numb*(-1);
		return res;

	}
	float getlastres()		//����� ������ ���������� ����������
	{
		return res;
	}
	float getfracpart()		//output frac part
	{
		return fracpart;
	}
	int getintpart()		//output int part
	{
		return intpart;
	}
	float powerNumber(int power)		//���������� ������� � �������
	{
		res = pow(numb, power);
		return res;
	}
	float xNumber(float x)		//��������� ������� �� �����
	{
		res = x*numb;
		return res;
	}

	float plusNumber(float x)		//����������� ����� � �������
	{
		res = numb + x;
		return res;
	}

	~Number()		//����������
	{

	}
};

//������ ��������� ������

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

		static void clear(node*&curr)		//��������
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
	tree operator=(tree t)		//���������� ��������� ������������
	{
		head = node::deepcopy(t.head);
		return t;
	}
	friend std::ostream& operator<<(std::ostream& os, tree t)		
	{
		node::print(t.head, os);
		return os;
	}

	void add(Item item = Item())		//���������� ��������
	{
		node::add(head, item);
	}
	void clear()
	{
		node::clear(head);
		head = nullptr;
	}
	~tree()		//����������
	{
		clear();
	}


};

int main()
{	
	Number obj1;
	obj1 = 12.7;
	cout << obj1.getNumber() << endl;
	cout << obj1.getNumber() << endl;
	cout << obj1.getintpart() << endl;
	cout << obj1.getfracpart() << endl;	
	cout << obj1.powerNumber(2) << endl;	
	tree<Number> obj;
	int n;
	float a;

	cout << "write n elements of tree ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{	
		cin >> a;
		obj.add(a);
	}
	tree<Number> tr = obj;
	/*obj.add(10);
	obj.add(9);
	obj.add(15);
	obj.add(10);
	obj.add(9);
	obj.add(15);*/
	cout << obj;
	cout << tr;
	cout << "press enter for close" << endl;
	getchar();
	getchar();
//	system("pause");
	return 0;
}