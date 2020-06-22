#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class Test {
public:
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "Test(int, int)...." << a << ", " << b << endl;
	}
	~Test() {
		cout << "a = " << a << ", b = " << b << ",  ~Test()..." << endl;
	}
private:
	int a;
	int b;
};

void divide(int x, int y) throw(int, char, char*)
{
	Test t1(1, 2);
	Test t2(10, 20);

	if (y == 0)
	{
		throw x; //所有在throw之前在栈上开辟的空间，都会被释放掉。
	}

	cout << "x/y = " << x / y << endl;

	return;
}


void test1() {
	try {
		divide(10,0);
	}
	catch (int e)
	{
		cout << "捕获到了异常 e= " << e << endl;
	}
}

int main(void)
{
	test1();
	return 0;
}
