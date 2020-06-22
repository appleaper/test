#include <iostream>
#include <string>
using namespace std;

template<class T>
class Person {
public:
	static int a;
};

template<class T>int Person<T>::a = 0;	//实例化具体模板类的静态变量

int main(void) {
	Person<int> p1, p2;		//int类型的static值
	Person<char> pp1, pp2;	//char类型的static值
	p1.a = 10;
	pp1.a = 100;
	cout << p1.a << " " << p2.a << endl;
	cout << pp1.a << " " << pp2.a << endl;
	return 0;
}
