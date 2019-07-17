Linux环境下：gdb调试

编译加上-g参数
gcc test1.c -g -o test1

进入调试
gdb test1

开始调试
start

显示代码
list-简写l
list 函数名称(查看函数内容)
list 行数（查看某行代码）

执行下一步
next-简写n

查看变量
print 变量名-简写p

进入到某个函数
step-简写s

设置断点
break 行号(gdb中的行号)-简写b

全速运行
continue-遇到断点会停止-简写b

查看断点信息
info breakpoints

删除断点
delete breakpoints 断点编号

修改变量的值
set var 变量=值

程序调用堆栈
当前函数之前的所有已调用函数列表，每一个都分配一个“帧”，最近调用的函数在0号帧里
backtrace-简写bt

切换栈帧
frame 1（查看指定栈帧的变量）

自动显示
display 变量名
取消自动显示
undisplay 行号（自动显示的行号）

查看内存布局
x /20 地址（数组名称）
x /20 buff-查看buff数组的前20个元素

***** 程序非正常退出，如何查看错误？
1.ulimit -a 查看core文件是否分配大小
2.ulimit -c 1024 创建的core文件大小为1024字节
3.gcc test2.c -g -o test2 编译链接得到带有-g选项的可执行程序
4../test2 执行程序，会生成core日志文件
5.gdb test2 core 打开日志文件，定位错误信息到具体的代码行数