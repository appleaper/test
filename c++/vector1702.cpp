#include <vector>
#include <iostream>
using namespace std;

int main(void)
{

	//构造函数,复制构造函数(元素类型要一致),
	vector<int> A;	//创建一个空的的容器
	vector<int> B(10, 100); //创建一个10个元素,每个元素值为100
	vector<int> C(B.begin(), B.end()); //使用迭代器,可以取部分元素创建一个新的容器
	vector<int> D(C); //复制构造函数,创建一个完全一样的容器

		  //重载=
	vector<int> E;
	E = B;

	//vector::begin()，返回的是迭代器

	vector<int> F(10); //创建一个有10个元素的容器
	for (int i = 0; i < 10; i++)
	{
		F[i] = i;
	}

	vector<int>::iterator BeginIter = F.begin();
	cout << *BeginIter << endl; //输出0

	//vector::end() 返回迭代器
	vector<int>::iterator EndIter = F.end();
	
	EndIter--; //向后移一个位置
	cout << *EndIter << endl; //输出9

	//vector::rbegin() 返回倒序的第一个元素，相当于最后一个元素
	vector<int>::reverse_iterator ReverBeIter = F.rbegin();
	cout << *ReverBeIter << endl; //输出9

	//vector::rend() 反序的最后一个元素下一个位置，也相当于正序的第一个元素前一个位置
	vector<int>::reverse_iterator ReverEnIter = F.rend();
	ReverEnIter--;
	cout << *ReverEnIter << endl; //输出0

	//vector::size() 返回元素的个数
	cout << F.size() << endl; //输出10

	//vector::max_size()
	cout << F.max_size() << endl; //输出1073741823，这个是极限元素个数

	//vector::resize()
	cout << F.size() << endl; //输出10
	F.resize(5);
	for (int k = 0; k < F.size(); k++)
		cout << F[k] << "  "; //输出 0 1 2 3 4
	cout << endl;

	//vector::capacity()
	cout << F.size() << endl; //5
	cout << F.capacity() << endl; //10	返回vector的实际存储空间的大小，这个一般大于或等于vector元素个数，注意与size()函数的区别

	//vector::empty()
	B.resize(0);
	cout << B.size() << endl; //0
	cout << B.capacity() << endl; //10
	cout << B.empty() << endl; //true

	//vector::reserve() //重新分配存储空间大小
	cout << C.capacity() << endl; //10
	C.reserve(4);
	cout << C.capacity() << endl; //10
	C.reserve(14);
	cout << C.capacity() << endl; //14

	//vector::operator []
	cout << F[0] << endl; //第一个元素是0

	//vector::at()
	try
	{
		cout << "F.size = " << F.size() << endl; //5
		cout << F.at(6) << endl; //抛出异常
	}
	catch (out_of_range)
	{
		cout << "at()访问越界" << endl;
	}

	//vector::front() 返回第一个元素的值
	cout << F.front() << endl; //0

//vector::back()	返回最后一个元素的值
	cout << F.back() << endl; //4

	//vector::assign()
	cout << A.size() << endl; //0	空容器
	vector<int>::iterator First = C.begin();		//C.size()=10
	vector<int>::iterator End = C.end() - 2;
	A.assign(First, End);
	cout << A.size() << endl; //8
	cout << A.capacity() << endl; //8

	A.assign(5, 3); //将丢弃原来的所有元素然后重新赋值
	cout << A.size() << endl; //5	前5个值都赋值为3
	cout << A.capacity() << endl; //8

	//vector::push_back()
	cout << *(F.end() - 1) << endl; //4		显示最后位置的值
	F.push_back(100);	//在容器的最后一个位置插入元素x,如果size值大于capacity值，则将重新分配空间
	cout << *(F.end() - 1) << endl; //100	最后位置插入了100

	//vector::pop_back()
	cout << *(F.end() - 1) << endl; //100
	F.pop_back();	// 删除最后一个元素
	cout << *(F.end() - 1) << endl; //4

	//vector::swap()
	F.swap(D); //交换这两个容器的内容
	for (int f = 0; f < F.size(); f++)
		cout << F[f] << " ";
	cout << endl;
	for (int d = 0; d < D.size(); d++)
		cout << D[d] << " ";
	cout << endl;
	//vector::clear()
	F.clear();		//将容器里的内容清空
	cout << F.size() << endl;	 //0
	cout << F.capacity() << endl; //10

	return 0;
}


