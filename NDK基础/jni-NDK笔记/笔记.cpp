#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <stdarg.h>

//标准命名空间(包含很多标准的定义)
//standard
using namespace std;
//命名空间类似于Java中包（归类）

/*
//自定义命名空间
namespace NSP_A{
int a = 9;
struct Teacher{
char name[20];
int age;
};
struct Student{
char name[20];
int age;
};

}

namespace NSP_B{
int a = 12;
//命名空间嵌套
namespace NSP_C{
int c = 90;
}
}

void main(){
//运算符重载
//std::cout << "this is c plus plus" << std::endl;
cout << "this is c plus plus" << endl;
//使用命名空间
//::访问修饰符
cout << NSP_A::a << endl;
cout << NSP_B::a << endl;

cout << NSP_B::NSP_C::c << endl;

//使用命名空间中的结构体
using NSP_A::Student;
Student t;
t.age = 90;

system("pause");
}
*/

/*
#define PI 3.14
//圆
class MyCircle{
//属性（共用权限访问修饰符）
private:
double r;
double s;
public:
void setR(double r){
this->r = r;
}
//获取面积
double getS(){
return PI * r * r;
}
};

void main(){
MyCircle c1;
c1.setR(4);

cout << "圆的面积：" << c1.getS() << endl;

system("pause");
}
*/
//结构体
/*
struct MyTeacher{
public:
char name[20];
int age;
public:
void say(){
cout << this->age << "岁" << endl;
}
};
void main(){
MyTeacher t1;
t1.age = 10;
t1.say();
system("pause");
}
*/

//布尔类型
/*
void main(){
//bool isSingle = true;
bool isSingle = 17;
//false -17

if (isSingle){
cout << "单身" << endl;
cout << sizeof(bool) << endl;
}
else{
cout << "有对象" << endl;
}

int a = 10, b = 20;
((a > b) ? a : b) = 30;
cout << b << endl;

system("pause");
}
*/

//引用
/*
void main(){
//变量名-门牌号(内存空间0x00001的别名，可不可以有多个名字？)
int a = 10;
//b就这个内存空间另外一个别名\
//& C++中的引用
int &b = a;
cout << b << endl;

system("pause");
}
*/

/*
//指针值交换
void swap_1(int *a, int *b){
int c = 0;
c = *a;
*a = *b;
*b = c;
}

//引用值交换
void swap_2(int &a, int &b){
int c = 0;
c = a;
a = b;
b = c;
}

void main(){
int x = 10;
int y = 20;

printf("%d,%d\n",x,y);
//swap_1(&x, &y);
//a成了x的别名
swap_2(x,y);
printf("%d,%d\n", x, y);

system("pause");
}
*/

//-----------------------------------------------------------------------------------------------------------------

// OOP 面向对象

/*
struct Teacher{
char* name;
int age;
};

void myprint(Teacher &t){
cout << t.name << "," << t.age << endl;
t.age = 21;
}

void myprint2(Teacher *t){
cout << t->name << "," << t->age << endl;
//(*t).name
}

//引用的主要功能：作为函数的参数或返回值
void main(){
Teacher t;
t.name = "jcy";
t.age = 20;
myprint(t);

myprint2(&t);

system("pause");
}
*/

//指针的引用，代替二级指针
/*
struct Teacher{
char* name;
int age;
};

void getTeacher(Teacher **p){
Teacher *tmp = (Teacher*)malloc(sizeof(Teacher));
tmp->age = 20;
*p = tmp;
}

//指针的引用，代替二级指针
//Teacher* &p = (Teacher * *p)
void getTeacher(Teacher* &p){
p = (Teacher*)malloc(sizeof(Teacher));
p->age = 20;
}

void main(){
Teacher *t = NULL;

getTeacher(&t);

system("pause");
}
*/

//指针常量与常量指针
/*
void main(){
//指针常量，指针的常量，不改变地址的指针，但是可以修改它指向的内容
int a = 2, b = 3;
int *const p1 = &a;
//p1 = &b;  //NO
*p1 = 4;

//常量指针，指向常量的指针，内容不能修改
const int *p2 = &a;
p2 = &b;
//*p2 = 9;  //NO
}
*/

//1.单纯给变量取别名没有任何意义，作为函数参数传递，能保证参数传递过程中不产生副本
//2.引用可以直接操作变量，指针要通过取值(*p)，间接操作变量，指针的可读性差

/*
//常引用类似于java中final
void myprintf(const int &a){
cout << a << endl;
}

void main(){
//const int a;
//引用必须要有值，不能为空
//int &a = NULL;

//常引用
int a = 10, b = 9;
const int &c = a;

//字面量
const int &d = 70;

//c = b;
myprintf(c);

system("pause");
}
*/


//引用的大小
/*
struct Teacher{
char name[20];
int age;
};

void main(){
Teacher t;

Teacher &t1 = t;
Teacher *p = &t;

cout << sizeof(t1) << endl;
cout << sizeof(p) << endl;
system("pause");
}
*/

/*
struct Teacher{
char name[20];
int age;
};

void myprint(Teacher *t){
cout << t->name << "," << t->age << endl;
}

void myprint2(Teacher &t){
cout << t.name << "," << t.age << endl;
t.age = 21;
}

void main(){
Teacher t;

Teacher *p = NULL;
//报错，防止不报错，进行非空判断
myprint(p);

//引用不能为空，没法传进去
Teacher &t2 = NULL;
myprint2(t2);

system("pause");
}
*/


//函数默认参数
/*
void myprint(int x, int y = 9, int z = 8){
cout << x << endl;
}
//重载
void myprint(int x,bool ret){
cout << x << endl;
}

void main(){
myprint(20);

system("pause");
}
*/

//可变参数
//int...
/*
void func(int i,...)
{
//可变参数指针
va_list args_p;
//开始读取可变参数，i是最后一个固定参数
va_start(args_p,i);
int a = va_arg(args_p,int);
char b = va_arg(args_p, char);
int c = va_arg(args_p, int);
cout << a << endl;
cout << b << endl;
cout << c << endl;
//结束
va_end(args_p);
}


void main(){
func(9,20,'b',30);

system("pause");
}
*/

//循环读取
/*
void func(int i,...)
{
//可变参数指针
va_list args_p;
//开始读取可变参数，i是最后一个固定参数
va_start(args_p,i);
int value;
while (1){
value = va_arg(args_p,int);
if (value <= 0){
break;
}
cout << value << endl;
}

//结束
va_end(args_p);
}

void main(){
func(9, 20, 40, 30);

system("pause");
}
*/

//C++类的普遍写法
/*
#include "MyTeacher.h"

void main(){
MyTeacher t1;
t1.name = "Jack";
t1.age = 20;

cout << t1.getName() << endl;

system("pause");
}
*/

//构造函数、析构函数、拷贝构造函数
/*
class Teacher{
private:
char *name;
int age;
public:
//无参构造函数（写了，就会覆盖默认的无参构造函数）
Teacher(){
cout << "无参构造函数" << endl;
}
//有参构造函数会覆盖默认的构造函数
Teacher(char *name, int age){
this->name = name;
this->age = age;
cout << "有参构造函数" << endl;
}
};


void main(){
//Teacher t1;
Teacher t2("yuehan",20);

//另外一种调用方式
Teacher t3 = Teacher("jack",21);

system("pause");
}
*/

/*
//析构函数
class Teacher{
private:
char *name;
int age;
public:
//无参构造函数赋默认值
Teacher(){
this->name = (char*)malloc(100);
strcpy(name,"jack walson");
age = 20;
cout << "无参构造函数" << endl;
}
//析构函数
//当对象要被系统释放时，析构函数被调用
//作用：善后处理
~Teacher(){
cout << "析构" << endl;
//释放内存
free(this->name);
}
};

void func(){
Teacher t1;
}

void main(){
func();

system("pause");
}
*/

//拷贝构造函数
/*
class Teacher{
private:
char *name;
int age;
public:
Teacher(char *name, int age){
this->name = name;
this->age = age;
cout << "有参构造函数" << endl;
}
//拷贝构造函数（值拷贝）
//默认拷贝构造函数，就是值拷贝
Teacher(const Teacher &obj){
this->name = obj.name;
this->age = obj.age;
cout << "拷贝构造函数" << endl;
}
void myprint(){
cout << name << "," << age << endl;
}
};

Teacher func1(Teacher t){
t.myprint();
return t;
}

void main(){
Teacher t1("rose",20);

//拷贝构造函数被调用的场景
//1.声明时赋值
//Teacher t2 = t1;
//t2.myprint();
//2.作为参数传入，实参给形参赋值
func1(t1);
//3.作为函数返回值返回，给变量初始化赋值
//Teacher t3 = func1(t1);

//这里不会被调用
//Teacher t1 ;
//Teacher t2;
//t1 = t2;

system("pause");
}
*/

//浅拷贝（值拷贝）问题
/*
class Teacher{
private:
char *name;
int age;
public:
Teacher(char *name, int age){
this->name = (char*)malloc(100);
strcpy(this->name,name);
this->age = age;
cout << "有参构造函数" << endl;
}
~Teacher(){
cout << "析构" << endl;
//释放内存
free(this->name);
}
void myprint(){
cout << name << "," << age << endl;
}
};

void func(){
Teacher t1("rose", 20);

Teacher t2 = t1;
t2.myprint();
}

void main(){
func();

system("pause");
}
*/

//深拷贝
/*
class Teacher{
private:
char *name;
int age;
public:
Teacher(char *name, int age){
int len = strlen(name);
this->name = (char*)malloc(len+1);
strcpy(this->name, name);
this->age = age;
cout << "有参构造函数" << endl;
}
~Teacher(){
cout << "析构" << endl;
//释放内存
free(this->name);
}
//深拷贝
Teacher(const Teacher &obj){
//复制name属性
int len = strlen(obj.name);
this->name = (char*)malloc(len+1);
strcpy(this->name,obj.name);
this->age = obj.age;
}
void myprint(){
cout << name << "," << age << endl;
}
};

void func(){
Teacher t1("rose", 20);

Teacher t2 = t1;
t2.myprint();
}

void main(){
func();

system("pause");
}
*/

//-----------------------------------------------------------------------------------------------------------------

//构造函数的属性初始化列表
/*
class Teacher{
private:
char* name;
public:
Teacher(char* name){
this->name = name;
cout << "Teacher有参构造函数" << endl;
}
~Teacher(){
cout << "Teacher析构函数" << endl;
}
char* getName(){
return this->name;
}

};

class Student{
private:
int id;
//属性对象
//Teacher t = Teacher("miss cang");
Teacher t1;
Teacher t2;
public:
Student(int id,char *t1_n, char* t2_n) : t1(t1_n), t2(t2_n){
this->id = id;
cout << "Student有参构造函数" << endl;
}
void myprint(){
cout << id << "," << t1.getName() <<"," << t2.getName() << endl;
}
~Student(){
cout << "Student析构函数" << endl;
}
};

void func(){
Student s1(10, "miss bo", "mrs liu");
//Student s2(20, "miss cang", "jcy");
s1.myprint();
//s2.myprint();
}

void main(){
func();

system("pause");
}
*/

//C++ 通过new(delete)动态内存分配
//C	  malloc(free)
/*
class Teacher{
private:
char* name;
public:
Teacher(char* name){
this->name = name;
cout << "Teacher有参构造函数" << endl;
}
~Teacher(){
cout << "Teacher析构函数" << endl;
}
void setName(char* name){
this->name = name;
}
char* getName(){
return this->name;
}
};

void func(){
//C++
//会调用构造和析构函数
Teacher *t1 = new Teacher("jack");
cout << t1->getName() << endl;
//释放
delete t1;

//C
//Teacher *t2 = (Teacher*)malloc(sizeof(Teacher));
//t2->setName("jack");
//free(t2);

}

void main(){
func();
//数组类型
//C
//int *p1 = (int*)malloc(sizeof(int) * 10);
//p1[0] = 9;
//free(p1);

//C++
int *p2 = new int[10];
p2[0] = 2;
//释放数组 []
delete[] p2;

system("pause");
}
*/

//static 静态属性和方法
/*
class Teacher{
public:
char* name;
//计数器
static int total;
public:
Teacher(char* name){
this->name = name;
cout << "Teacher有参构造函数" << endl;
}
~Teacher(){
cout << "Teacher析构函数" << endl;
}
void setName(char* name){
this->name = name;
}
char* getName(){
return this->name;
}
//计数，静态函数
static void count(){
total++;
cout << total << endl;
}
};

//静态属性初始化赋值
int Teacher::total = 9;

void main(){
Teacher::total++;
cout << Teacher::total << endl;
//直接通过类名访问
Teacher::count();

//也可以通过对象名访问
Teacher t1("yuehang");
t1.count();

system("pause");
}
*/

//类的大小
/*
class A{
public:
int i;
int j;
int k;
static int m;
};

class B{
public:
int i;
int j;
int k;
void myprintf(){
cout << "打印" << endl;
}
};


void main(){
cout << sizeof(A) << endl;
cout << sizeof(B) << endl;

//C/C++ 内存分区：栈、堆、全局（静态、全局）、常量区（字符串）、程序代码区
//普通属性与结构体相同的内存布局

//JVM Stack（基本数据类型、对象引用）
//Native Method Stack（本地方法栈）
//方法区


system("pause");
}
*/

//this，当前对象的指针
//函数是共享的，必须要有能够标识当前对象是谁的办法
/*
class Teacher{
private:
char* name;
int age;
public:
Teacher(char* name,int age){
this->name = name;
this->age = age;
cout << "Teacher有参构造函数" << endl;
}
~Teacher(){
cout << "Teacher析构函数" << endl;
}
//常函数，修饰的是this
//既不能改变指针的值，又不能改变指针指向的内容
//const Teacher* const this
void myprint() const{
printf("%#x\n",this);
//改变属性的值
//this->name = "yuehang";
//改变this指针的值
//this = (Teacher*)0x00009;
cout << this->name << "," << this->age << endl;
}
void myprint2(){
cout << this->name << "," << this->age << endl;
}
};

void main(){
Teacher t1("jack",20);
const Teacher t2("rose", 18);
//t2.myprint2(); 常量对象只能调用常量函数，不能调用非常量函数
//常函数，当前对象不能被修改，防止数据成员被非法访问
printf("%#x\n", &t1);
t1.myprint();

printf("%#x\n", &t2);
t2.myprint();

system("pause");
}
*/

//友元函数
/*
class A{
//友元函数
friend void modify_i(A *p, int a);
private:
int i;
public:
A(int i){
this->i = i;
}
void myprint(){
cout << i << endl;
}

};

//友元函数的实现，在友元函数中可以访问私有的属性
void modify_i(A *p, int a){
p->i = a;
}

void main(){
A* a = new A(10);
a->myprint();

modify_i(a,20);
a->myprint();

system("pause");
}
*/

/*
//友元类
class A{
//友元类
friend class B;
private:
int i;
public:
A(int i){
this->i = i;
}
void myprint(){
cout << i << endl;
}
};

class B{
public:
//B这个友元类可以访问A类的任何成员
void accessAny(){
a.i = 30;
}
private:
A a;
};
*/

//运算符重载
/*
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
Point operator+(Point &p1, Point &p2){
Point tmp(p1.x + p2.x, p1.y + p2.y);
return tmp;
}

//重载-号
Point operator-(Point &p1, Point &p2){
Point tmp(p1.x - p2.x, p1.y - p2.y);
return tmp;
}

void main(){
Point p1(10,20);
Point p2(20,10);

Point p3 = p1 + p2;

p3.myprint();

system("pause");
}
*/

//成员函数，运算符重载
/*
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

void main(){
Point p1(10, 20);
Point p2(20, 10);

//运算符的重载，本质还是函数调用
//p1.operator+(p2)
Point p3 = p1 + p2;

p3.myprint();

system("pause");
}
*/

//当属性私有时，通过友元函数完成运算符重载
class Point{
	friend Point operator+(Point &p1, Point &p2);
private:
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

Point operator+(Point &p1, Point &p2){
	Point tmp(p1.x + p2.x, p1.y + p2.y);
	return tmp;
}

/*void main(){
	Point p1(10, 20);
	Point p2(20, 10);

	//运算符的重载，本质还是函数调用
	//p1.operator+(p2)
	Point p3 = p1 + p2;

	p3.myprint();

	system("pause");
}*/

//-----------------------------------------------------------------------------------------------------------------

//继承
//代码的重用性
using namespace std;

/*
//人类
class Human{
public:
void say(){
cout << "说话" << endl;
}
protected:
char* name;
int age;
};

//男人
class Man : public Human{
public:
//泡妞
void chasing(){
cout << "泡妞" << endl;
}
private:
//兄弟
char* brother;
};

void work(Human& h){
h.say();
}

void main(){
Man m1;
m1.say();

//1.父类类型的引用或指针
Human* h_p = &m1;
h_p->say();

Human &h1 = m1;
h1.say();

//子类对象初始化父类类型的对象
Human h2 = m1;

system("pause");
}
*/

//向父类构造方法传参
//人类
/*
class Human{
public:
Human(char* name, int age){
this->name = name;
this->age = age;
}
void say(){
cout << "说话" << endl;
}
protected:
char* name;
int age;
};

//男人
class Man : public Human{
public:
//给父类构造函数传参，同时给属性对象赋值
Man(char *brother, char *s_name, int s_age, char *h_name, int h_age) : Human(s_name, s_age), h(h_name,h_age){
this->brother = brother;
}
//泡妞
void chasing(){
cout << "泡妞" << endl;
}
private:
//兄弟
char* brother;
Human h;
};

void main(){
Man m1("danny","jack",18,"jcy",18);

system("pause");
}
*/


//构造函数与析构函数调用的顺序
/*
class Human{
public:
Human(char* name, int age){
this->name = name;
this->age = age;
cout << "Human 构造函数" << endl;
}
~Human(){
cout << "Human 析构函数" << endl;
}
void say(){
cout << "说话" << endl;
}
protected:
char* name;
int age;
};

//男人
class Man : public Human{
public:
//给父类构造函数传参，同时给属性对象赋值
Man(char *brother, char *s_name,int s_age) : Human(s_name, s_age){
this->brother = brother;
cout << "Man 构造函数" << endl;
}
~Man(){
cout << "Man 析构函数" << endl;
}
//泡妞
void chasing(){
cout << "泡妞" << endl;
}
private:
//兄弟
char* brother;
};

void func(){
//父类构造函数先调用
//子类的析构函数先调用
Man m1("danny", "jack", 18);
}

void main(){
func();

system("pause");
}
*/


//子类对象调用父类的成员
/*
class Human{
public:
Human(char* name, int age){
this->name = name;
this->age = age;
cout << "Human 构造函数" << endl;
}
~Human(){
cout << "Human 析构函数" << endl;
}
void say(){
cout << "说话" << endl;
}
public:
char* name;
int age;
};

//男人
class Man : public Human{
public:
//给父类构造函数传参，同时给属性对象赋值
Man(char *brother, char *s_name, int s_age) : Human(s_name, s_age){
this->brother = brother;
cout << "Man 构造函数" << endl;
}
~Man(){
cout << "Man 析构函数" << endl;
}
//泡妞
void chasing(){
cout << "泡妞" << endl;
}
void say(){
cout << "男人喜欢装逼" << endl;
}
private:
//兄弟
char* brother;
};

void main(){
//是覆盖，并非动态
Man m1("alan","john",18);
m1.say();
m1.Human::say();

m1.Human::age = 10;

system("pause");
}
*/

//多继承
/*
//人
class Person{

};

//公民
class Citizen{

};

//学生，既是人，又是公民
class Student : public Person, public Citizen{

};
*/

//继承的访问修饰
//基类中      继承方式             子类中
//public     ＆ public继承 = > public
//public     ＆ protected继承 = > protected
//public     ＆ private继承 = > private
//
//protected  ＆ public继承 = > protected
//protected  ＆ protected继承 = > protected
//protected  ＆ private继承 = > private
//
//private    ＆ public继承 = > 子类无权访问
//private    ＆ protected继承 = > 子类无权访问
//private    ＆ private继承 = > 子类无权访问
//人类
/*
class Human{
public:
void say(){
cout << "说话" << endl;
}
private:
char* name;
int age;
};

//男人
class Man : protected Human{
public:
//泡妞
void chasing(){
cout << "泡妞" << endl;
}
private:
//兄弟
char* brother;
};
*/

//继承的二义性
//虚继承，不同路径继承来的同名成员只有一份拷贝，解决不明确的问题
/*
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
B b;
b.name = "jcy";
//指定父类显示调用
//b.A1::name = "jcy";
//b.A2::name = "jcy";
system("pause");
}
*/

/*
//虚函数
//多态（程序的扩展性）
//动态多态：程序运行过程中，觉得哪一个函数被调用（重写）
//静态多态：重载

//发生动态的条件：
//1.继承
//2.父类的引用或者指针指向子类的对象
//3.函数的重写

#include "Plane.h"
#include "Jet.h"
#include "Copter.h"
//业务函数
void bizPlay(Plane& p){
p.fly();
p.land();
}

void main(){
Plane p1;
bizPlay(p1);

//直升飞机
Jet p2;
bizPlay(p2);

Copter p3;
bizPlay(p3);

system("pause");
}
*/

//纯虚函数(抽象类)
//1.当一个类具有一个纯虚函数，这个类就是抽象类
//2.抽象类不能实例化对象
//3.子类继承抽象类，必须要实现纯虚函数，如果没有，子类也是抽象类
//抽象类的作用：为了继承约束，根本不知道未来的实现
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

//圆
class Circle : public Shape{
public:
Circle(int r){
this->r = r;
}
void sayArea(){
cout << "圆的面积：" << (3.14 * r * r) << endl;
}
private:
int r;
};

void main(){
//Shape s;
Circle c(10);

system("pause");
}

*/

//接口（只是逻辑上的划分，语法上跟抽象类的写法没有区别）
//可以当做一个接口
/*
class Drawble{
virtual void draw();
};
*/

//-----------------------------------------------------------------------------------------------------------------

//模板函数（泛型）
/*
void myswap(int& a,int& b){
int tmp = 0;
tmp = a;
a = b;
b = tmp;
}

void myswap(char& a, char& b){
char tmp = 0;
tmp = a;
a = b;
b = tmp;
}
*/

/*
//发现：这两个函数业务逻辑一样，数据类型不一样
template <typename T>
void myswap(T& a, T& b){
T tmp = 0;
tmp = a;
a = b;
b = tmp;
}

void main(){
//根据实际类型，自动推导
int a = 10, b = 20;
myswap<int>(a,b);
cout << a << "," << b << endl;

char x = 'v', y = 'w';
myswap(x, y);
cout << x << "," << y << endl;

system("pause");
}
*/

//模板类
template<class T>
class A{
public:
	A(T a){
		this->a = a;
	}
protected:
	T a;
};

//普通类继承模板类
class B : public A<int>{
public:
	B(int a, int b) : A<int>(a){
		this->b = b;
	}
private:
	int b;
};

//模板类继承模板类
template <class T>
class C : public A<T>{
public:
	C(T c, T a) : A<T>(a){
		this->c = c;
	}
protected:
	T c;
};

void main(){
	//实例化模板类对象
	//List<String> list;
	A<int> a(6);
	system("pause");
}

//-----------------------------------------------------------------------------------------------------------------

//C++ 异常处理，根据抛出的异常数据类型，进入到相应的catch块中
/*
void main(){
try{
int age = 300;
if (age > 200){
throw 9.8;
}
}
catch (int a){
cout << "int异常" << endl;
}
catch (char* b){
cout << b << endl;
}
catch (...){
cout << "未知异常" << endl;
}
system("pause");
}
*/

//throw 抛出函数外
/*
void mydiv(int a, int b){
if (b == 0){
throw "除数为零";
}
}

void func(){
try{
mydiv(8, 0);
}
catch (char* a){
throw a;
}
}

void main(){
try{
func();
}
catch (char* a){
cout << a << endl;
}
system("pause");
}
*/

//抛出对象
//异常类
/*
class MyException{

};

void mydiv(int a, int b){
if (b == 0){
throw MyException();
//throw new MyException; //不要抛出异常指针
}
}

void main(){
try{
mydiv(8,0);
}
catch (MyException& e2){
cout << "MyException引用" << endl;
}
//会产生对象的副本
//catch (MyException e){
//	cout << "MyException" << endl;
//}
catch (MyException* e1){
cout << "MyException指针" << endl;
delete e1;
}

system("pause");
}
*/

//throw 声明函数会抛出的异常类型
/*
void mydiv(int a, int b) throw (char*, int) {
if (b == 0){
throw "除数为零";
}
}
*/

/*
//标准异常（类似于JavaNullPointerException）
class NullPointerException : public exception{
public:
NullPointerException(char* msg) : exception(msg){

}
};

void mydiv(int a, int b){
if (b > 10){
throw out_of_range("超出范围");
}
else if (b == NULL){
throw NullPointerException("为空");
}
else if (b == 0){
throw invalid_argument("参数不合法");
}
}

void main(){
try{
mydiv(8,NULL);
}
catch (out_of_range e1){
cout << e1.what() << endl;
}
catch (NullPointerException& e2){
cout << e2.what() << endl;
}
catch (...){

}

system("pause");
}

*/

//外部类异常
/*
class Err{
public:
class MyException{
public:MyException(){

}
};
};

void mydiv(int a, int b){
if (b > 10){
throw Err::MyException();
}

}
*/

//-----------------------------------------------------------------------------------------------------------------

using namespace std;

//C++类型转换
//static_cast 普遍情况
//const_cast 去常量
//dynamic_cast 子类类型转为父类类型
//reinterpret_cast 函数指针转型，不具备移植性

//原始类型转换，所有情况都是一种写法，可读性不高，有可能有潜在的风险

/*
void* func(int type){
	switch (type){
	case 1:	{
				int i = 9;
				return &i;
	}
	case 2:	{
				int a = 'X';
				return &a;
	}
	default:{
				return NULL;
	}

	}
}

void func2(char* c_p){
	cout << *c_p << endl;
}

void main(){
	//int i = 0;
	//自动转换
	//double d = i;
	//double d = 9.5;
	//int i = d;

	//int i = 8;
	//double d = 9.5;
	//i = static_cast<int>(d);

	//void* -> char*
	//char* c_p = (char*)func(2);
	//char* c_p = static_cast<char*>(func(2));

	//C++ 意图明显
	func2(static_cast<char*>(func(2)));
	//C
	func2((char*)(func(2)));

	system("pause");
}
*/


/*
void func(const char c[]){
	//c[1] = 'a';
	//通过指针间接赋值
	//其他人并不知道，这次转型是为了去常量
	//char* c_p = (char*)c;
	//c_p[1] = 'X';
	//提高了可读性
	char* c_p = const_cast<char*>(c);
	c_p[1] = 'Y';

	cout << c << endl;
}

void main(){
	char c[] = "hello";
	func(c);

	system("pause");
}
*/

/*
class Person{
public:
	virtual void print(){
		cout << "人" << endl;
	}
};

class Man : public Person{
public:
	void print(){
		cout << "男人" << endl;
	}

	void chasing(){
		cout << "泡妞" << endl;
	}
};


class Woman : public Person{
public:
	void print(){
		cout << "女人" << endl;
	}

	void carebaby(){
		cout << "生孩子" << endl;
	}
};

void func(Person* obj){

	//调用子类的特有的函数，转为实际类型
	//并不知道转型失败
	//Man* m = (Man*)obj;
	//m->print();

	//转型失败，返回NULL
	Man* m = dynamic_cast<Man*>(obj);
	if (m != NULL){
		m->chasing();
	}

	Woman* w = dynamic_cast<Woman*>(obj);
	if (w != NULL){
		w->carebaby();
	}
}

void main(){

	//Woman w1;
	//Person *p1 = &w1;

	//func(p1);

	Woman w1;
	Woman* w_p = &w1;


	system("pause");
}
*/

/*
void func1(){
	cout << "func1" << endl;
}

char* func2(){
	cout << "func2" << endl;
	return "abc";
}

typedef void(*f_p)();

void main(){
	//函数指针数组
	f_p f_array[6];
	//赋值
	f_array[0] = func1;

	//C方式
	//f_array[1] = (f_p)(func2);
	//C++方式
	f_array[1] = reinterpret_cast<f_p>(func2);

	f_array[1]();

	system("pause");
}

*/

#include <fstream>

//IO流
//文本文件操作
/*
void main(){
	char* fname = "c://dest.txt";
	//输出流
	ofstream fout(fname);
	//创建失败
	if (fout.bad()){
		return;
	}

	fout << "jack" << endl;
	fout << "rose" << endl;

	//关闭
	fout.close();

	//读取
	ifstream fin(fname);
	if (fin.bad()){
		return;
	}
	char ch;
	while (fin.get(ch)){
		//输出
		cout << ch;
	}
	fin.close();

	system("pause");
}
*/

//二进制文件
/*
void main(){
	char* src = "c://src.jpg";
	char* dest = "c://dest.jpg";

	//输入流
	ifstream fin(src, ios::binary);
	//输出流
	ofstream fout(dest, ios::binary);

	if (fin.bad() || fout.bad()){
		return;
	}

	while (!fin.eof()){
		//读取
		char buff[1024] = {0};
		fin.read(buff,1024);

		//写入
		fout.write(buff,1024);
	}

	//关闭
	fin.close();
	fout.close();

	system("pause");
}
*/

/*
//C++对象的持久化
class Person
{
public:
	Person()
	{

	}
	Person(char * name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void print()
	{
		cout << name << "," << age << endl;
	}
private:
	char * name;
	int age;
};


void main()
{
	Person p1("柳岩", 22);
	Person p2("rose", 18);
	//输出流
	ofstream fout("c://c_obj.data", ios::binary);
	fout.write((char*)(&p1), sizeof(Person)); //指针能够读取到正确的数据，读取内存区的长度
	fout.write((char*)(&p2), sizeof(Person));
	fout.close();

	//输入流
	ifstream fin("c://c_obj.data", ios::binary);
	Person tmp;
	fin.read((char*)(&tmp), sizeof(Person));
	tmp.print();

	fin.read((char*)(&tmp), sizeof(Person));
	tmp.print();

	system("pause");

}
*/


//stl standard template library 标准模板库
//util
//c++ 集合-> java 集合

#include <string>

/*
void main()
{
	string s1 = "craig david";
	string s2(" 7 days");
	string s3 = s1 + s2;

	cout << s3 << endl;

	//转c字符串
	const char* c_str = s3.c_str();
	cout << c_str << endl;

	//s1.at(2);


	system("pause");
}
*/

//容器
#include <vector>

void main()
{
	//动态数组
	//不需要使用动态内存分配，就可以使用动态数组
	vector<int> v;
	v.push_back(12);
	v.push_back(10);
	v.push_back(5);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	system("pause");
}
// 详情 c++/stl sti_2