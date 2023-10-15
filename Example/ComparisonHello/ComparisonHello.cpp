
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <OVERPointer.h>



int main(int argc, char** argv)
{

	OVERPTR point1 = (char*)"Hello world";
	OVERPTR point2 = (char*)"Hello world";
	OVERPTR point3 = (char*)"Hello";
	OVERPTR point4 = point2;


	std::cout  << "DATA:" << std::endl;
	std::cout << "point1: " << point1.Get<char*>() << std::endl;
	std::cout << "point2: " << point2.Get<char*>() << std::endl;
	std::cout << "point3: " << point3.Get<char*>() << std::endl;
	std::cout << "point4: " << point4.Get<char*>() << std::endl;



	std::cout << std::endl << "COMPARISON:" << std::endl;
	std::cout << "point1 == point2: " << std::fixed << std::setw(10) << ((point1 == point2) ? "True" : "False") << std::endl;
	std::cout << "point2 == point1: " << std::fixed << std::setw(10) << ((point2 == point1) ? "True" : "False") << std::endl;
	std::cout << "point1 == point3: " << std::fixed << std::setw(10) << ((point1 == point3) ? "True" : "False") << std::endl;
	std::cout << "point4 == point2: " << std::fixed << std::setw(10) << ((point4 == point2) ? "True" : "False") << std::endl;
	std::cout << "point4 == point1: " << std::fixed << std::setw(10) << ((point4 == point1) ? "True" : "False") << std::endl;


	return 0;
}





