#include	<iostream>
using namespace	std;
class	Animal
{
public:
	virtual void		cry() = 0;
};
class	Dog : public	Animal
{
public:
	virtual void		cry()
	{
		cout << "旺旺~	" << endl;
	}
	void	doHome()
	{
		cout << "看家" << endl;
	}
};
class	Cat : public	Animal
{
public:
	virtual void		cry()
	{
		cout << "喵喵~	" << endl;
	}
	void	doHome()
	{
		cout << "抓⽼⿏" << endl;
	}
};
class	Book
{
public:
	void	printP()
	{
		cout << "book" << endl;
	}
};
int	main(void)
{
	Animal* base = NULL;
	//1	可以把⼦类指针赋给 ⽗类指针 但是反过来是不可以的 需要 如下转换
	//Dog	*pdog	=	base;		
	Dog* pDog = static_cast<Dog*>	(base);
	pDog->doHome();
	//2	把base转换成其他 ⾮动物相关的	err
	//Book	*book=	static_cast<Book	*>	(base);
	//3		reinterpret_cast	可以强制类型转换
	Book* book = reinterpret_cast<Book*>	(base);
	book->printP();
	return 0;
}
