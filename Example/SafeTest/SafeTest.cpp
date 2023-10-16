
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <OVERPointer.h>
#include <string>


OVERPTR CreateInt(int *num) {
	OVERPTR ptr = num;
	return ptr;
}

OVERPTR CreateChars(char* text) {
	OVERPTR ptr = text;
	return ptr;
}

void FuncPrintInt(OVERPTR pt) {
	if (pt.Is<int*>()) {
		std::cout << *pt.Get<int*>() << std::endl;
	}
}

void FuncPrintChars(OVERPTR pt) {
	if (pt.Is<char*>()) {
		std::cout << pt.Get<char*>() << std::endl;
	}
}




int main(int argc, char** argv)
{

	int num = 42;
	char* text = "Hello world";

	OVERPTR point1 = CreateInt(&num);
	OVERPTR point2 = CreateChars(text);


	std::cout << "Legal" << std::endl;
	FuncPrintInt(point1);
	FuncPrintChars(point2);
	std::cout << std::endl << "No legal" << std::endl;
	FuncPrintInt(point2);
	FuncPrintChars(point1);
	std::cout << "The program didn't crash :-)" << std::endl;


	return 0;
}





