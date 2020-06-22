#include	<iostream>
using namespace	std;
int	main(void)
{
	double	dPi = 3.1415926;
	int	num1 = (int)dPi;																//c语⾔的 旧式类型转换
	int	num2 = dPi;																					//隐式类型转换
	//	静态的类型转换:		
	//	在编译的时 进⾏基本类型的转换 能替代c⻛格的类型转换 可以进⾏⼀部分检查
	int	num3 = static_cast<int>	(dPi);	//c++的新式的类型转换运算符		
	cout << "num1:" << num1 << "	num2:" << num2 << "	num3:" << num3 << endl;
	return 0;
}
