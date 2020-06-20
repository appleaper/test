#include<iostream>
using namespace std;
struct student{
	char name[10];
	float grade;
};

void change(student& x, float grade) {
	x.grade = grade;
}

void change1(student* p, float grade) {
	p->grade = grade;
}

void change2(student x, float grade) {	//因为这里不是引用类型，所以什么都没有改变
	x.grade = grade;
}

void show(student& x) {
	cout << x.name << " " << x.grade << endl;
}

void main() {
	student a = { "zhanghua",351.5 };
	show(a);

	cout << " change" << endl;
	change(a, 365.5);
	show(a);

	cout << "change1" << endl;
	change1(&a, 375);
	show(a);

	cout << "change2" << endl;
	change2(a, 380.5);
	show(a);
}
