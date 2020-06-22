#include	<iostream>
using namespace	std;

template<class	T>
class	A{
public:
	A(T	a) {
		this->a = a;
	}
protected:
	T	a;
};
//模板类派⽣普通类
//结论:	⼦类从模板类继承的时候,需要让编译器知道 ⽗类的数据类型具体是什么
//(数据类型的本质:固定⼤⼩内存块的别名)A<int>
class	B : public	A<int>{
public:
	B(int	a, int	b) : A<int>(a)
	{
		this->b = b;
	}
	void	printB()
	{
		cout << "b:		" << b << endl;
	}
private:
	int	b;
};


//模板类派⽣模板类
template	<class	T>
class	C :public	A<T>	//普通类会具体写清楚类型，但是这里是模板类，所以就没有写清楚了
{
public:
	C(T c,T a):A<T>(a) {	//构造函数
		this->c = c;
	}
	void	printC()
	{
		cout << "C	:	" << c << endl;
	}
private:
	T	c;
};

int main(void) {
	C<int> d(100,200);
	d.printC();
	return 0;
}
