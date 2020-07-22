 这个函数在socket中多用于清空数组.如:原型是memset(buffer, 0, sizeof(buffer))

Memset 用来对一段内存空间全部设置为某个字符，一般用在对定义的字符串进行初始化为‘ ’或‘/0’；例:char a[100];memset(a, '/0', sizeof(a));

### strcmp的使用

```c++
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[15];
    char str2[15];
    int ret;


    strcpy(str1, "abcdef");
    strcpy(str2, "ABCDEF");

    ret = strcmp(str1, str2);

    if (ret < 0)
    {
        printf("str1 小于 str2");
    }
    else if (ret > 0)
    {
        printf("str1 大于 str2");
    }
    else
    {
        printf("str1 等于 str2");
    }

    return(0);
}
```



extern int b;//这里声明了一个变量，extern的意思是这个变量是个全局的，已经在其他文件中定义了，这里只是声明后使用而已



### 堆栈缓存方式

栈使用的是[一级缓存](https://baike.baidu.com/item/一级缓存)， 他们通常都是被调用时处于存储空间中，调用完毕立即释放。

堆则是存放在[二级缓存](https://baike.baidu.com/item/二级缓存)中，生命周期由虚拟机的垃圾回收算法来决定（并不是一旦成为孤儿对象就能被回收）。所以调用这些对象的速度要相对来得低一些。


### getchar用法


C 库函数 **int getchar(void)** 从标准输入 stdin 获取一个字符（一个无符号字符）。

该函数以无符号 char 强制转换为 int 的形式返回读取的字符，如果到达文件末尾或发生读错误，则返回 EOF。

```c++

#include <stdio.h>

int main()
{
	char c;

	printf("请输入字符：");
	c = getchar();

	printf("输入的字符：");
	putchar(c);

	return(0);
}
```



### strcpy()

C 库函数 **char \*strcpy(char \*dest, const char \*src)** 把 **src** 所指向的字符串复制到 **dest**。

需要注意的是如果目标数组 dest 不够大，而源字符串的长度又太长，可能会造成缓冲溢出的情况。

返回值：

该函数返回一个指向最终的目标字符串 dest 的指针。

```c++
#include <stdio.h>
#include <string.h>
 
int main()
{
   char src[40];
   char dest[100];
  
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is runoob.com");
   strcpy(dest, src);
 
   printf("最终的目标字符串： %s\n", dest);
   
   return(0);
}
```

### strcat()

C 库函数 **char \*strcat(char \*dest, const char \*src)** 把 **src** 所指向的字符串追加到 **dest** 所指向的字符串的结尾。

返回值：该函数返回一个指向最终的目标字符串 dest 的指针。

```c++
#include <stdio.h>
#include <string.h>
 
int main ()
{
   char src[50], dest[50];
 
   strcpy(src,  "This is source");
   strcpy(dest, "This is destination");
 
   strcat(dest, src);
 
   printf("最终的目标字符串： |%s|", dest);
   
   return(0);
}
```



### auto自动变量

auto （自动）是一个修饰存储类型的关键字，表明它之后建立的是自动变量。
在上面这条语句中，auto 关键字声明了一个 datatype （类型名）为 name(name) 的自动变量，使 name 具有以下特性：

1、name 为自动变量，可自动申请内存，自动释放内存；
2、name 具有块作用域，即 name 在程序执行到它所在的块(由两个花括号构成)时自动创建，name 在程序执行完它所在的块之后自动消失。
auto 这个关键词不常用，是由于我们经常使用的 datatype name ; 默认就等同于 auto datatype name;也就是说，在C语言里，语句前加不加 auto 效果都是一样的，有时候为了明示变量为自动变量才加 auto 关键字。

```c++
#include <stdio.h>
int main(void)
{
auto int i ;   	  	 //声明自动变量 i
i = 5;         	  	 //给 i 赋值为5
// 以上两条语句也可以简写为 auto int i = 5;     等同于 int i = 5;
printf("i = %d\n",i);      //打印 i 值
return 0;
}
```

结果：

```
i=5
```



### calloc 

C 库函数 **void \*calloc(size_t nitems, size_t size)** 分配所需的内存空间，并返回一个指向它的指针。**malloc** 和 **calloc** 之间的不同点是，malloc 不会设置内存为零，而 calloc 会设置分配的内存为零。

返回值：该函数返回一个指针，指向已分配的内存。如果请求失败，则返回 NULL。

```c++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    int* a;

    printf("要输入的元素个数：");
    scanf("%d", &n);

    a = (int*)calloc(n, sizeof(int));
    printf("输入 %d 个数字：\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("输入的数字为：");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    free(a);  // 释放内存
    return(0);
}
```



### typedef

typedef为C语言的关键字，作用是为一种数据类型定义一个新名字，这里的数据类型包括内部数据类型（int，char等）和自定义的数据类型（struct等）。

int a; ———— 传统变量声明表达式
int myint_t; ———— 使用新的类型名myint_t替换变量名a
typedef int myint_t; ———— 在语句开头加上typedef关键字，myint_t就是我们定义的新类型



typedef和define的区别

```
typedef　char*　pStr1;
#define　pStr2　char*　
pStr1　s1, s2;
pStr2　s3, s4;
```



### 读取文件

fopen() 函数打开一个文件或 URL。

语法：fopen(filename,mode,include_path,context)

- filename	

- - 必需。
  - 规定要打开的文件或 URL。

- mode	

- - 必需。
  - 规定您请求到该文件/流的访问类型。
  - 可能的值：

- - - "r" （只读方式打开，将文件指针指向文件头）
    - "r+" （读写方式打开，将文件指针指向文件头）
    - "w" （写入方式打开，清除文件内容，如果文件不存在则尝试创建之）
    - "w+" （读写方式打开，清除文件内容，如果文件不存在则尝试创建之）
    - "a" （写入方式打开，将文件指针指向文件末尾进行写入，如果文件不存在则尝试创建之）
    - "a+" （读写方式打开，通过将文件指针指向文件末尾进行写入来保存文件内容）
    - "x" （创建一个新的文件并以写入方式打开，如果文件已存在则返回 FALSE 和一个错误）
    - "x+" （创建一个新的文件并以读写方式打开，如果文件已存在则返回 FALSE 和一个错误）

```c#

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()//读文件
{
	FILE* p = fopen("C:\\Users\\Administrator\\Desktop\\opencv\\1.txt", "r");
	//p这个指针程序员一般是不用来计算的，主要的用处是给c语言库函数做为参数使用的
	if (p == NULL)
	{
		printf("失败\n");
	}
	else
	{
		printf("成功\n");
		//char c = getc(p);//fopen返回的指针，是不能自己计算的，一定是要给c语言文件操作的库函数操作的
		//printf("%c\n", c);
		//c = getc(p);//第二次调用getc的时候，getc会自动从第二个BYTE开始读取文件的内容，这个是不需要我们通过代码干预的
		//printf("%c\n", c);

		//c = getc(p);
		//printf("%c\n", c);

		char c = 0;
		while (c != EOF)//只要不是文件结尾，那么就一直循环
		{
			c = getc(p);
			printf("%c", c);
		}
		fclose(p);//fopen成功返回的指针
	}
	return 0;
}
```


### 往文件里面写东西

```
int main()//写文件
{
	FILE *p = fopen("D:\\temp\\a.txt", "w");//用只写的方式打开文件
	if (p)
	{
		printf("成功\n");
		char a[100] = "hello world";
		int len = strlen(a);
		int i;
		for (i = 0; i < len; i++)
			putc(a[i], p);//每次调用putc的时候，putc都会自动维护p这个指针指向的内存
		fclose(p);
	}
	return 0;
}
```

### 文件拷贝

```c#
int main03()//文件拷贝的代码
{
	FILE *p1 = fopen("D:\\temp\\a.txt", "r");//用读的方式打开a.txt
	FILE *p2 = fopen("D:\\temp\\b.txt", "w");//用写的方式打开b.txt

	if (p1 && p2)
	{
		//读取p1，将读到的内容写入p2，就实现了文件的拷贝
		
		while (1)
		{
			char c = getc(p1);//从p1中读一个字节
			if (c == EOF)
				break;
			c++;
			putc(c, p2);//将p1中读到的字节写入p2
		}
		fclose(p1);
		fclose(p2);
	}
	return 0;
}
```



### fgets()

C 库函数 **char \*fgets(char \*str, int n, FILE \*stream)** 从指定的流 stream 读取一行，并把它存储在 **str** 所指向的字符串内。当读取 **(n-1)** 个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定

返回值：

如果成功，该函数返回相同的 str 参数。如果到达文件末尾或者没有读取到任何字符，str 的内容保持不变，并返回一个空指针。

如果发生错误，返回一个空指针。

```C#
#include <stdio.h>

int main()
{
   FILE *fp;
   char str[60];

   /* 打开用于读取的文件 */
   fp = fopen("file.txt" , "r");
   if(fp == NULL) {
      perror("打开文件时发生错误");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL ) {
      /* 向标准输出 stdout 写入内容 */
      puts(str);
   }
   fclose(fp);
   
   return(0);
}
```

假设我们有一个文本文件 **file.txt**，它的内容如下。文件将作为实例中的输入：

```
We are in 2014
```

让我们编译并运行上面的程序，这将产生以下结果：

```
We are in 2014
```



### feof()

feof()是检测流上的文件结束符的函数，如果文件结束，则返回非0值，否则返回0

EOF是一个计算机术语，为End Of File的缩写，在操作系统中表示资料源无更多的资料可读取。资料源通常称为档案或串流。通常在文本的最后存在此字符表示资料结束。

```c#
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()//行读文件
{
	FILE* p = fopen("C:\\Users\\Administrator\\Desktop\\opencv\\1.txt", "r");
	if (p)
	{
		//while (1)
		//{
		//	char a[100] = { 0 };
		//	fgets(a, sizeof(a), p);//从p中读一行，包括行尾的回车
		//	if (feof(p))//如果p已经到了文件最后，feof返回true
		//		break;
		//	printf("%s", a);
		//}

		while (!feof(p))
		{
			char a[100] = { 0 };
			fgets(a, sizeof(a), p);//从p中读一行，包括行尾的回车
			printf("%s", a);
		}
		fclose(p);
	}
	return 0;
}
```



### 计算文件内容表达式的结果

```c#
#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int func(int a, int b, char c)
{
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;//暂时不考虑除数为0的情况
	default:
		return 0;
	}
}
int main()//计算文件内容表达式的结果
{
	FILE *p = fopen("D:\\temp\\a.txt", "r");
	if (p)
	{
		char content[100][100] = { 0 };
		//while (!feof(p))
		int index = 0;
		while (1)
		{
			char array[100] = { 0 };
			if (fgets(array, sizeof(array), p) == NULL)//读取一行
				break;
			//fgets读到最后一行的时候，并不是文件结尾，是到了最后一行之后再读一次才是文件结尾
			//这样的调用，可以避免最后多循环一次
			int a, b;
			char c;
			sscanf(array, "%d%c%d=", &a, &c, &b);
			sprintf(content[index], "%d%c%d=%d\n", a, c, b, func(a, b, c));
			index++;
		}
		fclose(p);
		
		//这里是保存结果
		p = fopen("D:\\temp\\a.txt", "w");
		int i;
		for (i = 0; i < index; i++)
		{
			fputs(content[i], p);
			//printf("%s", content[i]);
		}
		fclose(p);
		
	}
	return 0;
}
```



### sscanf()

C 库函数 **int sscanf(const char \*str, const char \*format, ...)** 从字符串读取格式化输入。

返回值：如果成功，该函数返回成功匹配和赋值的个数。如果到达文件末尾或发生读错误，则返回 EOF。

```c#
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int day, year;
   char weekday[20], month[20], dtm[100];

   strcpy( dtm, "Saturday March 25 1989" );
   sscanf( dtm, "%s %s %d  %d", weekday, month, &day, &year );

   printf("%s %d, %d = %s\n", month, day, year, weekday );
    
   return(0);
}
```

结果：

```
March 25, 1989 = Saturday
```


