#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
	�����ࣺ���д��麯�������Ϊ�����࣬����ʵ����
	���麯�������麯����һ���ڻ������������麯�������ڸû�����û�ж������Ĳ������ݣ�Ҫ������������ʵ����Ҫ�����Լ��İ汾
			virtual <int/void/string/...> function(target1,target2...)=0��//����0��ʾû�к�����

	ע�⣺������̳г��������Ҫ�����麯��ʵ�֣����ܽ��ж���ʵ����

	demo����ʾ��:
			Base2 b;
			derived c;
			example d;
			fun(&b);
			fun(&c);
			system("Pause");
*/

class Base1
{
public:
	virtual void display() = 0;//����Ҫ�ٻ����и��������ĺ�����

};

class Base2 :public Base1
{
public:
	virtual void display()
	{
		cout << "Base2::display()" << endl;
	}
};

class derived :public Base2
{
public:
	virtual void display()
	{
		cout << "derived::display()" << endl;
	}
};


void fun(Base1* pt)
{
	pt->display();
}
