
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <OVERPointer.h>
#include <string>


int main(int argc, char** argv)
{

	int input1;
	int input2;

	std::cin >> input1;
	std::cin >> input2;

	OVERPTR point1 = &input1;
	OVERPTR point2 = &input2;

	std::cout << std::endl << "DATA:" << std::endl;
	std::cout << *point1.Get<int*>() << std::endl;
	std::cout << *point2.Get<int*>() << std::endl;

	point1.Print();
	point2.Print();


	return 0;
}





