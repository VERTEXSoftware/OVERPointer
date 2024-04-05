
#include <cstdio>
#include <iostream>
#include <OVERPointer.h>


class MyClass {
public:

	MyClass(int nm) {
		this->num = nm;
	}
	~MyClass() {
		this->num = 0;
	}

	int GetNum() {return this->num;}
	void SetNum(int nm) { this->num =nm; }

private:
	int num;


};


int main(int argc, char** argv)
{

	MyClass test(12);


	OVERPTR pointA = &test;

	OVERPTR pointB = new MyClass(10);

	std::cout << pointA.Get<MyClass*>()->GetNum() << std::endl;
	std::cout << pointB.Get<MyClass*>()->GetNum() << std::endl;


	return 0;
}





