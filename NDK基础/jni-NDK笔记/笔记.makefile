
Maven、ANT、Gradle构建工具

Makefile 构建工具，只需通过make一句命令就可以构建一个可执行程序

在很多C/C++开源项目中，configrue文件用来检查系统配置生成配置文件（这些配置文件会在接下来的Makefile文件中被使用到）
Makefile文件用来生成我们需要的动态库文件

.o文件：.o文件就是对象文件,是可重定向文件的一种,通常以ELF格式保存，
    里面包含了对各个函数的入口标记，描述，当程序要执行时还需要链接(link).链接就是把多个.o文件链成一个可执行文件。
如何手动生成c语言的目标文件 .o文件？
    gcc -c xxx.c   ==》 gcc 等同于Java中的 javac命令
如何通过.o文件得到一个二进制可执行文件？
    gcc -c name xxx.c  ==》name为自定义名称，可通过 ./name 执行
如何将一系列.o文件手动打包成一个可执行程序？
    gcc 1.o 2.o 3.o ... -o myapp  ==》 myapp即为可执行程序


为什么要写Makefile文件？
1.当项目非常庞大时，让构建过程，自动化，简单
2.依赖文件比目标更新，会重建目标文件

plus.c
minus.c
multi.c
divi.c
main.c

.c -> .o目标文件
.o -> 打包myapp，可执行文件

直接make，构建的是终极目标
构建非终极目标，make main.o


调用my-dir函数，返回Android.mk文件所在的目录
LOCAL_PATH := $(call my-dir) 放在第一行，地址当前所在目录
include file Makefile可以引入其他的Makefile文件
include $(CLEAR_VARS) include代表引入文件，CLEAR_VARS代表编译模块时，清空LOCAL_MODULE等参数
LOCAL_MODULE 模块名称
LOCAL_SRC_FILES 编译需要的源文件
LOCAL_C_INCLUDES 需要的头文件
LOCAL_SHARED_LIBRARIES 编译需要的动态库

//编写Makefile文件：
    #三要素
    #目标，依赖，命令

    #myapp目标（最终目标，第一行是最终目标）
    #:后的文件，这些都是依赖
    #命令TAB键开头，如何由依赖文件得到目标
    #step 1
    #myapp:main.o plus.o minus.o multi.o divi.o
    #	gcc main.o plus.o minus.o multi.o divi.o -o myapp

    #目标：main.o
    #依赖：main.c
    #命令：gcc -c main.c
    #main.o:main.c
    #	gcc -c main.c
    #plus.o:plus.c
    #	gcc -c plus.c
    #minus.o:minus.c
    #	gcc -c minus.c
    #multi.o:multi.c
    #	gcc -c multi.c
    #divi.o:divi.c
    #	gcc -c divi.c

    #step 2
    #变量
    #OBJECTS=main.o plus.o minus.o multi.o divi.o

    #step 3
    #所有.c源文件
    SOURCES=$(wildcard *.c)
    #把.c后缀，替换成.o后缀
    OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

    myapp:$(OBJECTS)
    #自动化变量 $^表示所有依赖，$@表示目标
    	gcc $^ -o $@

    #通配符
    #main.o:main.c
    %.o:%.c
    #gcc -c main.c -o main.o
    	gcc -c $^ -o $@


    #没有依赖
    #clean清除所有的.o中间文件
    #伪目标
    .PHONY:clean

    clean:
    	rm -f *.o
    	rm -f myapp

    #递归展开式
    #可以引用还没有定义的变量，展开是引用时展开
    str2=$(str1)
    str1=hello

    #直接展开式
    #必须引用定义好了的变量，定义之后就会展开
    str3 := android
    str4 := $(str3)
    str5 := $(str1) world

    #变量的值追加
    str5 += hello

    #自定义函数
    myfun=$2 $1
    #变量等于函数的执行结构
    myfun_ret=$(call myfun,20,10)

    test:
    	@echo $(SOURCES)
    	@echo $(OBJECTS)
    	@echo $(str2)
    	@echo $(str4)
    	@echo $(str5)
    	@echo $(myfun_ret)
    	@echo $(call myfun,30,40)
