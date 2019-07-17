#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>



/*
void main(){
printf("hello world\n");
system("pause");
}
*/
//1.基本数据类型
//int short long float double char
/*
int %d
short %d
long %ld
float %f
double %lf
char %c
%x 十六进制
%o 八进制
%s 字符串
*/
/*
void main(){
int i = 1;
printf("%d\n",i);

float f = 23.3;
printf("%f\n",f);

//基本数据类型所占的字节数
printf("int占%d字节\n",sizeof(int));
printf("char占%d字节\n", sizeof(char));
printf("float占%d字节\n", sizeof(float));

//循环
int n = 0;
for (; n < 10; n++){
printf("%d\n",n);
}

//等待输入
system("pause");
}
*/

//2.输入输出函数
/*
void main(){
int i;
printf("请输入一个整数：");
//赋值
scanf("%d",&i);  //控制台输入，&取地址符
//打印
printf("i的值为：%d\n",i);

system("pause");
}
*/

//指针
//指针存储的是变量的内存地址
//内存地址，系统给数据分配的编号（门牌号）
/*void main(){
int i = 90;
//指针变量，创建一个int类型的指针
int* p = &i; //p的值就是i这个变量的内存地址
printf("%#x\n",p);

float f = 89.5f;
//创建一个float类型的指针
float *fp = &f;
printf("%#x\n", fp);

system("pause");
}*/

/*
void change(int* p){
*p = 300;
}

//变量名，对内存空间上的一段数据的抽象
void main(){
int i = 90;
//i = 89;
//创建一个int类型的指针
int *p = &i;
//输出地址
printf("p的地址：%#x\n",&p);
printf("i的地址：%#x\n",&i);

printf("i的值为：%d\n", i);
//间接赋值 i = 200;

//对p存的地址指向的变量进行操作
//*p = 200;
//change(p);
change(&i);  // int *p = &i;
printf("i的值为：%d\n",i);

system("pause");
}
*/

//-----------------------------------------------------------------------------------------------------------------------------------
//1.指针为什么要有类型？
//指针有类型，地址没有类型
//地址只是开始的位置，类型读取到什么位置结束
/*
void main(){
int i = 89;
//int 类型的指针
int *p = &i;
double j = 78.9;
//赋值为double类型变量的地址
p = &j;
printf("double size:%d\n", sizeof(double));
printf("%#x,%lf\n",p,*p); //想通过4字节读取8字节变量的值，是不行的

getchar();
}
*/

//2.NULL空指针
/*
void main(){
int i = 9;
int *p = NULL;
//p = &i;

//空指针的默认值为0
printf("%#x\n",p);
//访问内存地址0x000000操作系统不允许
//p = 100; //操作系统不允许访问
printf("%d\n",*p);
getchar();
}
*/

//3.多级指针（二级指针）
//指针保存的是变量的地址，保存的这个变量还可以是一个指针变量
//动态内存分配给二维数组
/*
void main(){
int a = 50;
//p1上保存的a的地址
int* p1 = &a;

//p2上保存的p1的地址
int** p2 = &p1;

//int*** p3 = &p2;

printf("p1:%#x,p2:%#x\n",p1,p2);
**p2 = 90;

printf("%d\n",a);

getchar();
}
*/

//4.指针的运算
//指针的运算，一般在数组遍历时才有意义，基于数组在内存中线性排列的方式
/*
void main(){
//数组在内存中连续存储
int ids[] = { 78, 90, 23, 65, 19 };
//数组变量名：ids就是数组的首地址
printf("%#x\n",ids);
printf("%#x\n",&ids);
printf("%#x\n",&ids[0]);
//指针变量
int *p = ids;
printf("%d\n",*p);
//指针的加法
p++; //p++向前移动sizeof(数据类型)个字节
printf("p的值:%#x\n", p);
//p--;
printf("%d\n", *p);
getchar();
}
*/
//5.通过指针给数组赋值
/*
void main(){
int uids[5];
//高级写法
//int i = 0;
//for (; i < 5; i++){
//	uids[i] = i;
//}
//早些版本的写法
int* p = uids;
printf("%#x\n",p);
int i = 0; //i是数组元素的值
for (; p < uids + 5; p++){
*p = i;
i++;
}

getchar();
}
*/

//6.函数指针
/*
int msg(char* msg,char* title){
MessageBox(0,msg,title,0);
return 0;
}
void main(){
//msg();
printf("%#x\n",msg);
printf("%#x\n",&msg);
//函数指针
//函数返回值类型，函数指针的名称，函数的参数列表
int(*fun_p)(char* msg, char* title) = msg;
fun_p("消息内容","标题");

getchar();
}
*/

int add(int a, int b){
	return a + b;
}

int minus(int a, int b){
	return a - b;
}

/*int div(int a, int b){
return a - b;
}*/

//msg函数需要传递一个函数指针参数
//类似于我们Java中的回调函数
/*
void msg(int(*func_p)(int a, int b), int m, int n){
printf("执行一段代码...\n");
printf("执行回调函数...\n");
int r = func_p(m, n);
printf("执行结果：%d\n",r);
}

void main(){
//加法
//int(*func_p)(int a, int b) = add;
msg(div, 10, 20);
//减法
//msg(minus,50,10);
getchar();
}
*/

/*
//案例：用随机数生成一个数组，写一个函数查找最小的值，并返回最小数的地址，在主函数中打印出来
int* getMinPointer(int ids[], int len){
int i = 0;
int* p = &ids[0];
for (; i < len; i++){
if (ids[i] < *p){
p = &ids[i];
}
}
return p;
}

void main(){
int ids[10];
int i = 0;
//初始化随机数发生器，设置种子，种子不一样，随机数才不一样
//当前时间作为种子 有符号 int -xx - > +xx
srand((unsigned)time(NULL));
for (; i < 10; i++){
//100范围内
ids[i] = rand() % 100;
printf("%d\n", ids[i]);
}

int* p = getMinPointer(ids, sizeof(ids) / sizeof(int));
printf("%#x,%d\n",p,*p);
getchar();
}
*/

//-----------------------------------------------------------------------------------------------------------------------------------

//动态内存分配
/*
void main(){
//40M
//stack overflow错误，栈溢出
//静态内存分配
int a[1024 * 1024 * 10];
//栈内存

//C语言内存分配：
//1.栈区(stack)
//windows下，栈内存分配2M（确定的常数），超出了限制，提示stack overflow错误
//自动分配，释放
//2.堆区(heap)
//程序员手动分配释放，操作系统80%内存
//3.全局区或静态区
//4.字符常量区
//5.程序代码区

getchar();
}
*/

/*
//栈内存
void stackFun(){
int a[1024];
//栈内存自动释放
}

//堆内存
void heapFun(){
//40M内存
//字节
//void *任意类型的指针
int* p = malloc(1024 * 1024 * 10 * sizeof(int));

//释放
free(p);
}

void main(){
//在堆内存上，分配40M的内存
while (1){
Sleep(1000);
stackFun();
}

getchar();
}
*/

//创建一个数组，动态指定数组的大小
//（在程序运行过长中，可以随意的开辟指定大小的内存，以供使用，相当于Java中的集合）
//静态内存分配，分配内存大小的是固定，问题：1.很容易超出栈内存的最大值 2.为了防止内存不够用会开辟更多的内存，容易浪费内存
//动态内存分配，在程序运行过程中，动态指定需要使用的内存大小，手动释放，释放之后这些内存还可以被重新使用（活水）
/*
void main(){
//静态内存分配创建数组，数组的大小是固定的
//int i = 10;
//int a[i];

int len;
printf("输入数组的长度：");
scanf("%d",&len);

//开辟内存，大小len*4字节
int* p = malloc(len * sizeof(int));
//p是数组的首地址，p就是数组的名称
//给数组元素赋值（使用这一块刚刚开辟出来的内存区域）
int i = 0;
for (; i < len - 1; i++){
p[i] = rand() % 100;
printf("%d,%#x\n", p[i], &p[i]);
}

//手动释放内存
free(p);

getchar();
}
*/

//realloc 重新分配内存
/*
void main(){
int len;
printf("第一次输入数组的长度：");
scanf("%d", &len);

//int* p = malloc(len * sizeof(int));
int* p = calloc(len, sizeof(int));
int i = 0;
for (; i < len; i++){
p[i] = rand() % 100;
printf("%d,%#x\n", p[i], &p[i]);
}

int addLen;
printf("输入数组增加的长度：");
scanf("%d", &addLen);
//内存不够用，扩大刚刚分配的内存空间
//1.原来内存的指针 2.内存扩大之后的总大小
int* p2 = realloc(p, sizeof(int) * (len + addLen));
if (p2 == NULL){
printf("重新分配失败，世界那么大，容不下我。。。");
}
//重新分配内存的两种情况：
//缩小，缩小的那一部分数据会丢失
//扩大，（连续的）
//1.如果当前内存段后面有需要的内存空间，直接扩展这段内存空间，realloc返回原指针
//2.如果当前内存段后面的空闲字节不够，那么就使用堆中的第一个能够满足这一要求的内存块，将目前的数据复制到新的位置，并将原来的数据库释放掉，返回新的内存地址
//3.如果申请失败，返回NULL，原来的指针仍然有效

//重新赋值
i = 0;
printf("--------------------------\n");
for (; i < len + addLen; i++){
p2[i] = rand() % 200;
printf("%d,%#x\n", p2[i], &p2[i]);
}

//手动释放内存
if (p != NULL){
free(p);
p = NULL;
}
if (p2 != NULL){
free(p2);
p2 = NULL;
}

getchar();
}
*/

//内存分配的几个注意细节
//1.不能多次释放
//2.释放完之后（指针仍然有值），给指针置NULL，标志释放完成
//3.内存泄露（p重新赋值之后，再free，并没有真正释放内存）
/*
void main(){
int len;
printf("输入数组的长度：");
scanf("%d", &len);

int* p = malloc(len * sizeof(int));
int i = 0;
for (; i < len; i++){
p[i] = rand() % 100;
printf("%d,%#x\n", p[i], &p[i]);
}

if (p != NULL){
free(p);
p = NULL;
}

getchar();
}
*/
void main(){
	//40M
	int* p1 = malloc(1024 * 1024 * 10 * sizeof(int));
	free(p1);
	p1 = NULL;
	printf("%#x\n", p1);

	//80M
	p1 = malloc(1024 * 1024 * 10 * sizeof(int)* 2);

	free(p1);
	p1 = NULL;

	getchar();
}

//-----------------------------------------------------------------------------------------------------------------------------------

//使用字符数组存储字符串
/*
void main(){
//char str[] = {'c','h','i','n','a','\0'};
//char str[6] = { 'c', 'h', 'i', 'n', 'a' };
char str[10] = "china";
//可以修改
str[0] = 's';

printf("%s\n",str);
printf("%#x\n", str);
getchar();
}
*/

//字符指针
/*
void main(){
//内存连续排列
char *str = "how are you?";

//不可以修改
//str += 1;
//*str = 'y';
printf("%s\n", str);
printf("%#x\n", str);

//使用指针加法，截取字符串
str += 3;
while (*str){
printf("%c",*str);
str++;
}
printf("\n结束了");
getchar();
}
*/

//strcat字符串拼接函数
//在线API文档：
//http://www.kuqin.com/clib/string/strcpy.html
/*
void main(void){
char dest[50];
char *a = "china";
char *b = " is powerful!";
strcpy(dest, a);
strcat(dest, b);
printf("%s\n", dest);

system("pause");
}
*/


//strchr在一个串中查找给定字符的第一个匹配之处
/*
void main(void){
char *str = "I want go to USA!";
printf("%#x\n", str);
//U元素的指针
//str+3
char* p = strchr(str, 'w');
if (p){
printf("索引位置：%d\n", p - str);
}
else{
printf("没有找到");
}

system("pause");
}
*/

//strstr 从字符串haystack中寻找needle第一次出现的位置

void main(void){
	char *haystack = "I want go to USA!";
	char *needle = "to";
	//U元素的指针

	char* p = strstr(haystack, needle);
	if (p){
		printf("索引位置：%d\n", p - haystack);
	}
	else{
		printf("没有找到");
	}

	system("pause");
}

//-----------------------------------------------------------------------------------------------------------------------------------

//结构体是一种构造数据类型
//把不同的数据类型整合起来成为一个自定义的数据类型
/*
struct Man{
//成员
char name[20];
int age;
//int(*func)();
};

void main(){
//初始化结构体的变量
//1.
//struct Man m1 = {"Jack", 21};
//2.
struct Man m1;
m1.age = 23;
//m1.name = "Rose";
strcpy(m1.name,"rose");
sprintf(m1.name,"jcy");

//类似JavaScript字面量赋值，只能在变量声明时赋值
//m1 = {};
struct Man m2 = m1;

printf("%s,%d\n",m1.name,m1.age);

getchar();
}
*/

//结构体的几种写法
/*
struct Man{
char name[20];
int age;
} m1, m2 = {"jack",20}; //m1结构体变量名

//typedef int Age;

void main(){

strcpy(m1.name,"Jack");
m1.age = 10;

printf("%s,%d\n", m2.name, m2.age);

getchar();
}
*/

//匿名结构体
//控制结构体变量的个数（限量版），相当于单例
/*
struct{
char name[20];
int age;
}m1;
*/

//结构体嵌套
/*
struct Teacher{
char name[20];
};

struct Student{
char name[20];
int age;
struct Teacher t;
};

void main(){
//字面量的方式
//struct Student s1 = { "jack", 21, {"jcy"} };
struct Student s1;
s1.age = 10;
strcpy(s1.t.name, "jcy");
system("pause");
}
*/

//结构体嵌套2
/*
struct Student{
char name[20];
int age;
struct Teacher{
char name[20];
} t;
};

void main(){
struct Student s1;
strcpy(s1.t.name, "jcy");
//struct Teacher t;


system("pause");
}
*/

//结构体与指针
/*
struct Man{
char name[20];
int age;
};
void main(){
struct Man m1 = {"Jack",30};
//结构体指针
struct Man *p = &m1;
printf("%s,%d\n", m1.name, m1.age);
printf("%s,%d\n",(*p).name,(*p).age);
//“->”（箭头）是“(*p).”简写形式
printf("%s,%d\n", p->name, p->age);
//(*env)->

system("pause");
}
*/

//指针与结构体数组
/*
struct Man{
char name[20];
int age;
};
void main(){
struct Man mans[] = { {"Jack",20}, {"Rose", 19} };
//遍历结构体数组
//1.
struct Man *p = mans;
for (; p < mans + 2; p++){
printf("%s,%d\n", p->name, p->age);
}

//2.
int i = 0;
for (; i < sizeof(mans) / sizeof(struct Man); i++){
printf("%s,%d\n", mans[i].name, mans[i].age);
}

//(*env)->

system("pause");
}
*/

//结构体的大小（字节对齐）
/*
struct Man{
int age;
double weight;
};

void main(){
//结构体变量的大小，必须是最宽基本数据类型的整数倍
//提升读取的效率
struct Man m1 = {20,89.0};
printf("%#x,%d\n", &m1,sizeof(m1));
getchar();
}
*/

struct Man{
	char *name;
	int age;
};
//结构体与动态内存分配
/*
void main(){
struct Man *m_p = (struct Man*)malloc(sizeof(struct Man) * 10);
struct Man *p = m_p;
//赋值
p->name = "Jack";
p->age = 20;
p++;
p->name = "Rose";
p->age = 20;

struct Man *loop_p = m_p;
for (; loop_p < m_p + 2; loop_p++){
printf("%s,%d\n", loop_p->name, loop_p->age);
}

free(m_p);
getchar();
}
*/

/*
//typedef 类型取别名
//1.不同名称代表在干不同的事情typedef int jint;
//2.不同情况下，使用不同的别名
//#if defined(__cplusplus)
//typedef _JNIEnv JNIEnv;
//typedef _JavaVM JavaVM;
//3.书写简洁

struct Man{
char name[20];
int age;
};

//Age int类型的别名
typedef int Age;
//Age int类型指针的别名
typedef int* Ap;

typedef struct Man JavaMan;
typedef struct Man* JM;

//结构体取别名
//typedef struct Woman W;
//typedef struct Woman* WP;
//简写
typedef struct Woman{
char name[20];
int age;
} W, *WP;  //W 是woman结构体的别名, WP 是woman结构体指针的别名

void main(){
int i = 5;
Ap p = &i;

//结构体变量
W w1 = {"Rose",20};
//结构体指针
WP wp1 = &w1;
printf("%s,%d\n", w1.name, w1.age);
printf("%s,%d\n", wp1->name, wp1->age);

getchar();
}
*/

//结构体函数指针成员
/*
struct Girl{
char *name;
int age;
//函数指针
void(*sayHi)(char*);
};
//Girl结构体类似于Java中的类，name和age类似于属性，sayHi类似于方法

void sayHi(char* text){
MessageBoxA(0, text, "title", 0);
}

void main(){
struct Girl g1;
g1.name = "Lucy";
g1.age = 18;
g1.sayHi = sayHi;

g1.sayHi("hello");

getchar();
}
*/

typedef struct Girl{
	char *name;
	int age;
	//函数指针
	void(*sayHi)(char*);
}Girl;

//Girl结构体指针取别名GirlP
typedef Girl* GirlP;

void sayHi(char* text){
	MessageBoxA(0, text, "title", 0);
}

//改名
void rename(GirlP gp1){
	gp1->name = "Lily";
}

void main(){
	Girl g1 = { "Lucy", 18, sayHi };
	GirlP gp1 = &g1;
	gp1->sayHi("Byebye!");
	//传递指针，改名
	rename(gp1);

	getchar();
}

//-----------------------------------------------------------------------------------------------------------------------------------

//联合体（共用体）
//不同类型的变量共同占用一段内存（相互覆盖），联合变量任何时刻只有一个成员存在，节省内存
//联合体变量的大小=最大的成员所占的字节数
//比喻：同穿一条裤子
/*
union  MyValue{
int x;
int y;
double z;
};

void main(){
union MyValue d1;
d1.x = 90;
d1.y = 100; //最后一次赋值有效
//d1.z = 23.8;

printf("%d,%d,%lf\n",d1.x,d1.y,d1.z);
system("pause");
}
*/

/*
typedef union jvalue {
jboolean    z;
jbyte       b;
jchar       c;
jshort      s;
jint        i;
jlong       j;
jfloat      f;
jdouble     d;
jobject     l;
} jvalue;
*/

//枚举（列举所有的情况）
//限定值，保证取值的安全性
//enumeration
//enum Day
//{
//	Monday = 0,
//	Tuesday = 1,
//	Wednesday = 2,
//	Thursday = 3,
//	Friday = 4,
//	Saturday = 5,
//	Sunday = 6
//};
/*
enum Day
{
Monday,
Tuesday,
Wednesday,
Thursday,
Friday,
Saturday,
Sunday
};


void main(){
//枚举的值，必须是括号中的值
enum Day d = Monday;
printf("%#x,%d\n",&d,d);

getchar();
}
*/

//-----------------------------------------------------------------------------------------------------------------------------------

//读取文本文件
/*
void main(){
char *path = "E:\\jcy\\vip\\ndk\\08_08_C_05\\files\\friends.txt";
//打开
FILE *fp = fopen(path,"r");
if (fp == NULL){
printf("文件打开失败...");
return;
}
//读取
char buff[50]; //缓冲
while (fgets(buff,50,fp)){
printf("%s",buff);
}
//关闭
fclose(fp);
system("pause");

getchar();
}
*/

//写入文本文件
/*
void main(){
char *path = "E:\\jcy\\vip\\ndk\\08_08_C_05\\files\\friends_new.txt";
//打开
FILE *fp = fopen(path, "w");
char *text = "hchmily@sina.com,程华才,学清路 8\n号科技财富中心 A";
fputs(text,fp);

//关闭流
fclose(fp);
getchar();
}
*/

//计算机的文件存储在物理上都是二进制
//文本文件和二进制之分，其实是一个逻辑之分
//C读写文本文件与二进制文件的差别仅仅体现在回车换行符
//写文本时，每遇到一个'\n'，会将其转换成'\r\n'(回车换行)
//读文本时，每遇到一个'\r\n'，会将其转换成'\n'

//文件复制
/*
void main(){
char *read_path = "E:\\jcy\\vip\\ndk\\08_08_C_05\\files\\liuyan.png";
char *write_path = "E:\\jcy\\vip\\ndk\\08_08_C_05\\files\\liuyan_new.png";
//读的文件 b字符表示操作二进制文件binary
FILE *read_fp = fopen(read_path, "rb");
//写的文件
FILE *write_fp = fopen(write_path, "wb");

//复制
int buff[50]; //缓冲区域
int len = 0; //每次读到的数据长度
while ((len = fread(buff, sizeof(int), 50, read_fp)) != 0){
//将读到的内容写入新的文件
fwrite(buff,sizeof(int),len,write_fp);
}
//关闭流
fclose(read_fp);
fclose(write_fp);
getchar();
}
*/

//获取文件的大小
/*
void main(){
char *read_path = "E:\\jcy\\vip\\ndk\\08_08_C_05\\files\\liuyan.png";
FILE *fp = fopen(read_path, "r");
//重新定位文件指针
//SEEK_END文件末尾，0偏移量
fseek(fp,0,SEEK_END);
//返回当前的文件指针，相对于文件开头的位移量
long filesize = ftell(fp);
printf("%d\n",filesize);

getchar();
}
*/

//练习：文本文件加解密
/*
//异或
//规则：1^1=0, 0^0=0, 1^0=1, 0^1=1 同为0，不同为1
//加密
void crpypt(char normal_path[],char crypt_path[]){
//打开文件
FILE *normal_fp = fopen(normal_path, "r");
FILE *crypt_fp = fopen(crypt_path, "w");
//一次读取一个字符
int ch;
while ((ch = fgetc(normal_fp)) != EOF){ //End of File
//写入（异或运算）
fputc(ch ^ 9,crypt_fp);
}
//关闭
fclose(crypt_fp);
fclose(normal_fp);
}

//解密
void decrpypt(char crypt_path[], char decrypt_path[]){
//打开文件
FILE *normal_fp = fopen(crypt_path, "r");
FILE *crypt_fp = fopen(decrypt_path, "w");
//一次读取一个字符
int ch;
while ((ch = fgetc(normal_fp)) != EOF){ //End of File
//写入（异或运算）
fputc(ch ^ 9, crypt_fp);
}
//关闭
fclose(crypt_fp);
fclose(normal_fp);

}

void main(){
char *normal_path = "E:\\jcy\\vip\\ndk\\08_08_C_05\\files\\friends.txt";
char *crypt_path = "E:\\jcy\\vip\\ndk\\08_08_C_05\\files\\friends_crypt.txt";
char *decrypt_path = "E:\\jcy\\vip\\ndk\\08_08_C_05\\files\\friends_decrypt.txt";

//crpypt(normal_path, crypt_path);
//解密
decrpypt(crypt_path, decrypt_path);

getchar();
}
*/

//二进制文件加解密
//读取二进制文件中的数据时，一个一个字符读取
//密码：ilovely
/*
void crpypt(char normal_path[], char crypt_path[],char password[]){
//打开文件
FILE *normal_fp = fopen(normal_path, "rb");
FILE *crypt_fp = fopen(crypt_path, "wb");
//一次读取一个字符
int ch;
int i = 0; //循环使用密码中的字母进行异或运算
int pwd_len = strlen(password); //密码的长度
while ((ch = fgetc(normal_fp)) != EOF){ //End of File
//写入（异或运算）
fputc(ch ^ password[i % pwd_len], crypt_fp);
i++;
}
//关闭
fclose(crypt_fp);
fclose(normal_fp);
}

//解密
void decrpypt(char crypt_path[], char decrypt_path[],char password[]){
//打开文件
FILE *normal_fp = fopen(crypt_path, "rb");
FILE *crypt_fp = fopen(decrypt_path, "wb");
//一次读取一个字符
int ch;
int i = 0; //循环使用密码中的字母进行异或运算
int pwd_len = strlen(password); //密码的长度
while ((ch = fgetc(normal_fp)) != EOF){ //End of File
//写入（异或运算）
fputc(ch ^ password[i % pwd_len], crypt_fp);
i++;
}
//关闭
fclose(crypt_fp);
fclose(normal_fp);

}

void main(){
char *normal_path = "E:\\jcy\\vip\\ndk\\08_08_C_05\\files\\liuyan.png";
char *crypt_path = "E:\\jcy\\vip\\ndk\\08_08_C_05\\files\\liuyan_crypt.png";
char *decrypt_path = "E:\\jcy\\vip\\ndk\\08_08_C_05\\files\\liuyan_decrypt.png";

//crpypt(normal_path, crypt_path,"iloveqq");
//解密
decrpypt(crypt_path, decrypt_path,"iloveqq");

getchar();
}
*/

//-----------------------------------------------------------------------------------------------------------------------------------

//C语言执行的流程
//编译：形成目标代码(.obj)
//连接：将目标代码与C函数库连接合并，形成最终的可执行文件
//执行

//预编译（预处理），为编译做准备工作，完成代码文本的替换工作
//C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\include
//C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\crt\src

//头文件告诉编译器有这样一个函数，连接器负责找到这个函数的实现

//宏定义、宏替换、预编译指令
//define指令
//1.定义标示
//#ifdef __cplusplus 标识支持C++语法
//防止文件重复引入
//2.定义常数（便于修改与阅读）
#define MAX 100
//int MIN = 40;

//3.定义“宏函数”
void com_jni_read(){
	printf("read\n");
}

void com_jni_write(){
	printf("write\n");
}
//NAME是参数
#define jni(NAME) com_jni_##NAME();
//webrtc JNI函数名称很长，也是JOW宏函数缩短函数名称

//日志输出
//__VA_ARGS__可变参数
//#define LOG(FORMAT,...) printf(##FORMAT,__VA_ARGS__);
////日志会有级别
//#define LOG_I(FORMAT,...) printf("INFO:"); printf(##FORMAT,__VA_ARGS__);
//#define LOG_E(FORMAT,...) printf("ERRO:"); printf(##FORMAT,__VA_ARGS__);

//升级版本
#define LOG(LEVEL,FORMAT,...) printf(##LEVEL); printf(##FORMAT,__VA_ARGS__);
#define LOG_I(FORMAT,...) LOG("INFO:",##FORMAT,__VA_ARGS__);
#define LOG_E(FORMAT,...) LOG("ERROR:",##FORMAT,__VA_ARGS__);
#define LOG_W(FORMAT,...) LOG("WARN:",##FORMAT,__VA_ARGS__);

//Android
//#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"jcy",FORMAT,##__VA_ARGS__);
//LOGI("%s","fix");
//替换
//__android_log_print(ANDROID_LOG_INFO, "jcy", "%s", "fix");

void main(){
	//#include "my.txt"
	//printf("%s\n", "I am a little boy!");

	//printfA();
	int i = 90;
	if (i < MAX){
		printf("比MAX小..");
	}

	jni(write);//替换：com_jni_write();

	LOG_E("%s%d", "大小：", 89);
	//替换成：printf("INFO:"); printf("%s%d","大小：",89);
	//LOG_I
	getchar();
}
