
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <OVERPointer.h>
#include <string>

class Vector3 {
public:
	double x, y, z;
	Vector3(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {}
	double length() const { return sqrt(x * x + y * y + z * z); }
	void print() const { std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl; }
};




int main(int argc, char** argv)
{

	char* text = new char[256];

	std::cin >> text;

	OVERPTR point = text;

	point.Print();


	//delete[] text;

	point.Delete<char*>();

	point.Print();

	std::cout<< (point.Is<char*>() ? "True" : "False") << std::endl;

	if (point.Is<char*>()) {

		char* tmp = NULL;

		if ((tmp=point.Get<char*>())!=NULL) {

			std::cout << "exist" << std::endl;
			std::cout << point.Get<char*>() << std::endl;
		}

	}

	std::cout << "test2" << std::endl;

	return 0;
}





