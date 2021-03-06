//객체_UpCasting.cpp
#include<iostream>
using namespace std;

class Person
{
public:
	void Sleep()
	{
		cout << "Sleep()" << endl;
	}

};

class Student :public Person
{

public:
	void study()
	{
		cout << "Study()" << endl;
	}
};

class partTimeStd : public Student
{
private:
	int  ptNum;
public:
	partTimeStd() : ptNum(100)
	{

	}

	void Work()
	{
		cout << "Work() :" << ptNum << endl;
	}
};

int main()
{
	Person t1;
	Student t2;
	partTimeStd t3;

	t1.Sleep();
	t2.Sleep();
	t2.study();
	t3.Sleep();
	t3.study();
	t3.Work();
	cout << "====================" << endl;

	//부모클래스 포인터는 자식클래스 포인터를 저장할 수 있다.
	//Person* p1; // 부모클래스의 객체포인터는 자신 뿐만아니라 파생클래스의 주소도 받을 수 있다.  => 다향성

	Person* p1 = new Person();
	//Person* p1 = new partTimeStd();
	Person* p2 = new Student(); // UpCast
	Person* p3 = new partTimeStd();

	//기반클래스의 객체 포인터는 가르키는 대상에 상관없이 
	//기반클래스 내에 선언된 멤버에 접근한다.
	p1->Sleep();
	p2->Sleep();
	//p2->Study(); // Error : 상속은 받았지만 객체포인터가 기반클래스 타입이므로 접근 불가
	p3->Sleep();
	//p3->PartTimeStd::Work(); // Error : 상속은 받았지만 객체포인터가 기반클래스 타입이므로 접근 불가

	Student* s1 = new partTimeStd();
	s1->Sleep();
	s1->study();
	cout << "====================" << endl;

	//파생클래스 객체포인터는 기반클래스 주소를 저장할 수 없다.
	//partTimeStd *pt1 = new Person; //Down Cast
	//partTimeStd* pt1 = p1;

	//partTimeStd* pt1 = (partTimeStd*)p1; // 명시적 형변환, C Style ==> 다운 캐스트라서 기본적으로 안쓴다.
	partTimeStd* pt1 = (static_cast<partTimeStd*>(p1)); // 명시적 형변환, C++ Style ==> 다운 캐스트라서 기본적으로 안쓴다.
	pt1->Sleep();
	pt1->study();
	pt1->Work();

	cout << "======================" << endl;


	return 0;
}
/*
	업캐스팅 : 부모클래스 객체 포인터 = 자식클래스 객체(포인터)or 주소
			: 아무리 자식 클래스 객체를 가리켜도 어차피 접근 가능한 것은 부모클래스 멤버들 뿐이다.


	다운 캐스팅 : 자식클래스 객체 포인터 = (자식클래스 *)부모클래스 객체 포인터(주소)
				: 다운캐스팅 하려면 업캐스팅을 한 부모클래스 객체 포인터 를 (자식클래스 *)우측에 넣어야지만
				 정상적으로 값이 출력이 된다.
				 만약 그냥 부모클래스 객체 포인터에 부모 객체 주소 담아버리면 쓰레기 값뜸 == 오류!!!!!!
*/