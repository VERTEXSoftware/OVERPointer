
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <OVERPointer.h>
#include <string>


void PrintFunc() {
	std::cout << "Hello world!!!" << std::endl;
}

void PrintText(char* arg) {
	std::cout << arg << std::endl;
}

void PrintInt(int arg) {
	std::cout << std::to_string(arg) << std::endl;
}

int main(int argc, char** argv)
{


	OVERPTR point1 = &PrintFunc;
	OVERPTR point2 = &PrintText;
	OVERPTR point3 = &PrintInt;

	point1.Print();
	point2.Print();
	point3.Print();

	point1.Get<void(*)()>()();
	point2.Get<void(*)(char*)>()("test text");
	point3.Get<void(*)(int)>()(42);

	return 0;
}





