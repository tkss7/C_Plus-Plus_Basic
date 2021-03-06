//526p_07.cpp
#include<iostream>
using namespace std;

class Comparable {
public:
	virtual bool operator>(Circle& op2) = 0;
	virtual bool operator<(Circle& op2) = 0;
	virtual bool operator==(Circle& op2) = 0;
};


class Circle :public Comparable {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }

	bool operator>(Circle& op2);
	bool operator<(Circle& op2);
	bool operator==(Circle& op2);
};

bool Circle::operator>(Circle& op2)
{
	if (this->getRadius() > op2)
		return true;
	else
		return false;
}

bool Circle::operator<(Circle& op2)
{
	if (*this < op2)
		return true;
	else
		return false;
}


bool Circle::operator==(Circle& op2)
{
	if (*this== op2)
		return true;
	else
		return false;
}

template <class T>
T bigger(T a, T b)
{
	if (a > b) return a;
	else return b;
}

//Circle& bigger(Circle& ref1, Circle& ref2)
//{
//	if (ref1.getRadius() > ref2.getRadius())
//		return ref1;
//	else
//		return ref2;
//}

int main()
{
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;

}