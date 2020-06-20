#include <iostream>
#include <string>
using namespace std;

template<class T1,class T2>
class Animal {
public:
	Animal(T1 name, T2 age) {
		this->mName = name;
		this->mAge = age;
	}
	void show() {
		cout << "Name:"<<this->mName << " Age:" << this->mAge <<endl;
	}
public:
	T1 mName;
	T2 mAge;
};


int main(void) {
	Animal<string, int> cat("tong", 20);
	cat.show();
	return 0;
}
