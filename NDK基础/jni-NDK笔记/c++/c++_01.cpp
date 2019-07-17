#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>

//标准命名空间(包含很多标准的定义)
//standard
using namespace std;
//命名空间类似于Java中包（归类）

class User{
public:
	void setName(char *name){
		this->name = name;
	}
	char* getName(){
		return name;
	}
	void setAge(int age){
		this->age = age;
	}
	int getAge(){
		return age;
	}

	User(){
		cout << "无参构造" << endl;
	}
	User(char* name){
		cout << "有参构造" << endl;
	}

private:
	char *name;
	int age;
};

class Student{
private:
	char *name;
	int age;
	User user;
public:
	Student(){
		cout << "无参构造" << endl;
	}

	Student(char *name,int age = 16){// 第二个参数存在默认值
		cout << "有参构造" << endl;
	}

	Student(char *name, char* user_name) : user(user_name){// 对象属性，类内初始化方式，参数二
		cout << "有参构造" << endl;
	}

	~Student(){
		cout << "析构函数，对象被销毁时调用，可用来释放资源" << endl;
	}

	Student(const Student &stu){
		this->name = stu.name;
		this->age = stu.age;
		cout << "拷贝构造函数" <<  endl;
	}
};

void func(){
	Student s1;
	Student s2("小明");
	Student s3("小将", 24);
}

//C++ 通过new(delete)动态内存分配
//C	  malloc(free)

class Friend_A{
	// 友元类
	friend class Friend_B;
private:
	int i;
public:
	char *name;
	friend void shared_func(Friend_A*fa, int a);

};

// 友元函数，共享，类之间的共享
void shared_func(Friend_A*fa, int a){
	// 友元函数内部可以访问对象私有成员
	fa->i = a;
}

class Friend_B{
private:
	Friend_A fa;
public:
	void accessF_a(){
		fa.i = 5;
	}
};

//运算符重载
class Point{
public:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0){
		this->x = x;
		this->y = y;
	}
	void myprint(){
		cout << x << "," << y << endl;
	}
};

//重载+号
/*Point operator+(Point &p1, Point &p2){
	Point tmp(p1.x + p2.x, p1.y + p2.y);
	return tmp;
}

//重载-号
Point operator-(Point &p1, Point &p2){
	Point tmp(p1.x - p2.x, p1.y - p2.y);
	return tmp;
}*/

//成员函数，运算符重载
class Point{
public:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0){
		this->x = x;
		this->y = y;
	}
	//成员函数，运算符重载
	Point operator+(Point &p2){
		Point tmp(this->x + p2.x, this->y + p2.y);
		return tmp;
	}
	void myprint(){
		cout << x << "," << y << endl;
	}
};


// 继承
class Human{
public:
	char*name;
	int age;
	Human(char *name, int age){
		this->age = age;
		this->name = name;
	}
	void say(){
		cout << "说话" << endl;
	}
};

class Person{
public:
	char*name;
	int age;
};

class Man : public Human,public Person{// 多继承，public作用域
public:
	Man(char*name, int age) :Human(name, age){

	}
	void say(){
		cout << "说话1" << endl;
	}
};

//继承的二义性
//虚继承，不同路径继承来的同名成员只有一份拷贝，解决不明确的问题
class A{
public:
	char* name;
};

class A1 : virtual public A{

};

class A2 : virtual public A{

};

class B : public A1, public A2{

};

void main(){
	User user;
	user.setName("程序员");
	user.setAge(25);
	cout << "名字是：" << user.getName() << "年龄：" << user.getAge() << endl;

	func();

	Point p1(10, 20);
	Point p2(20, 10);

	//运算符的重载，本质还是函数调用
	//p1.operator+(p2)
	Point p3 = p1 + p2;

	p3.myprint();

	Man m1("",18);
	m1.Human::say();// 向上转型

	B b;
	b.name = "jcy";
	//指定父类显示调用
	//b.A1::name = "jcy";
	//b.A2::name = "jcy";

	system("pause");
}
// 虚函数
// 多态（程序的扩展性）
// 动态多态：程序运行过程中，觉得哪一个函数被调用（重写）
// 静态多态：重载
// virtual void fly();
// 纯虚函数(抽象类)
//	1.当一个类具有一个纯虚函数，这个类就是抽象类
//	2.抽象类不能实例化对象
//	3.子类继承抽象类，必须要实现纯虚函数，如果没有，子类也是抽象类
// 抽象类的作用：为了继承约束，根本不知道未来的实现
//形状
/*
class Shape{
public:
//纯虚函数
virtual void sayArea() = 0;
void print(){
cout << "hi" << endl;
}
};

//接口（只是逻辑上的划分，语法上跟抽象类的写法没有区别）
//可以当做一个接口
class Drawble{
virtual void draw();
};
*/