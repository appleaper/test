#include	<iostream>
using namespace	std;
template	<typename	T>
void	myswap(T& a, T& b)
{
	T	t;
	t = a;
	a = b;
	b = t;
	cout << "myswap	模板函数do" << endl;
}
void	myswap(char& a, int& b)
{
	int	t;
	t = a;
	a = b;
	b = t;
	cout << "myswap	普通函数do" << endl;
}
int	main()
{
	char	cData = 'a';
	int		iData = 2;

	myswap(cData, iData);		//普通函数会进⾏隐⼠的数据类型转换
	//myswap(iData, cData);		//函数模板不提供隐式的数据类型转换,必须是严格的匹配
	
	//myswap<int>(cData, iData);
	

	return 0;
}
