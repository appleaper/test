#include	<iostream>
using namespace	std;

template	<class	T>
class	A {
public:
	static	T	s_value;
};


//静态变量需要在类的外部初始化
template	<class	T>
T	A<T>::s_value = 0;


/*
			当编译器看⻅	A<int>	被调⽤， 将执⾏⼆次编译， ⽣成如下的类A
			class	A
			{
			public:
			static	int	s_value;
			};
			int	A::s_value	=	0;
	*/
	/*
				当编译器看⻅	A<char>	被调⽤， 将执⾏⼆次编译， ⽣成如下的类A
				class	A
				{
				public:
				static	char	s_value;	};
			char	A::s_value	=	0;
	*/

int	main(void)
{
	A<int>	a1, a2, a3;	//class	A		<int>家族的 对象
	A<char>	b1, b2, b3;	//	class	A	<char>家族的 对象
	a1.s_value = 10;
	b1.s_value = 'a';
	cout << a1.s_value << endl;
	cout << b1.s_value << endl;
	//打印出		a1.s_value	=	10,		b1.s_value	=	'a'	说明 两个s_value	在两个类中是不同的
	a1.s_value++;
	cout << a2.s_value << endl;//	11
	cout << a3.s_value << endl;//	11
	b1.s_value++;
	cout << b2.s_value << endl;		//'b'
	cout << b3.s_value << endl;		//'b'
	//通过以上结果，说明	a1，a2,	a3	是属于A<int>家族的他们共享A<int>::s_value;
	//																														b1,	b2,	b3	是属于A<char>家族的他们共享
	A<char>::s_value;
	return 0;
}
