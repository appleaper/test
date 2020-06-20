//根据半精计算圆的周长和面积
#include <iostream>
using namespace std;
const float PI = 3.1416;
float fCir_L(float);	//声明
float fCir_S(float);

int main(void) {
	float r, l, s;
	cout << "R=";
	cin >> r;
	l = fCir_L(r);
	s = fCir_S(r);
	cout << "周长=" << l;
	cout << "\n面积=" << s;
}

float fCir_L(float x) {
	float z = -1.0;
	if (x > 0.0) {
		z = 2 * PI * x;
	}
	return(z);
}

float fCir_S(float x) {
	float z = -1.0;
	if (x >= 0.0) {
		z = PI * x * x;
	}
	return(z);
}
