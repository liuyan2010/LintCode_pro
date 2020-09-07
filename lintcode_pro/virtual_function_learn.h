#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
	抽象类：带有纯虚函数的类称为抽象类，不可实例化
	纯虚函数：纯虚函数是一个在基类中声明的虚函数，它在该基类中没有定义具体的操作内容，要求各派生类根据实际需要定义自己的版本
			virtual <int/void/string/...> function(target1,target2...)=0；//等于0表示没有函数体

	注意：派生类继承抽象类后，需要将纯虚函数实现，才能进行对象实例化

	demo测试示例:
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
	virtual void display() = 0;//不需要再基类中给出函数的函数体

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
