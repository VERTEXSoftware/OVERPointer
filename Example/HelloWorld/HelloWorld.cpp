
#include <cstdio>
#include <iostream>
#include <OVERPointer.h>


int main(int argc, char** argv)
{

	char* data = "Hello world";

	OVERPTR point = data;

	std::cout << point.Get<char*>() << std::endl;

	return 0;
}





