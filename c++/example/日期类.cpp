//定义日期类
#include <iostream>
using namespace std;
class Date {
	friend istream& operator>>(istream& input, Date& dt);
	friend ostream& operator<<(ostream& output, Date& dt);
	int mo, da, yr;
public:
	Date(void) {
		yr = 0;
		mo = 0;
		da = 0;
	}
	Date(int y, int m, int d) {
		yr = y;
		mo = m;
		da = d;
	}

};

istream& operator>>(istream& input, Date& dt) {		//输入流，date类型
	cout << "Year\n";
	input >> dt.yr;
	cout << "Month\n";
	input >> dt.mo;
	cout << "day\n";
	input >> dt.da;
	return input;
}

ostream& operator<<(ostream& output, Date& dt) {
	output << dt.yr << "/" << dt.mo << "/" << dt.da << endl;
	return output;
}

void main() {
	Date dt1(2002, 5, 1), dt2;
	cout << dt1;
	cin >> dt2;
	cout << dt2;
}
