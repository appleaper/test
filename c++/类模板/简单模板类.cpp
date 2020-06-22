#include	<iostream>
using namespace	std;
//template<typename T>				//定义类模板 要在类的头部之前加⼊template<typename	T>	或者

template<class T>
class A{
public:
	A(T	t)
	{
		this->t = t;
	}
	T& getT()
	{
		return	t;
	}
public:
	T	t;
};
int	main(void)
{
	//在定义⼀个对象的时候，要明确此类所泛化的具体类型
	A<int>	a(100);
	A<char> b('a');
	cout << a.getT() << endl;
	cout << b.getT() << endl;
	return 0;
}
