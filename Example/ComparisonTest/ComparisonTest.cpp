
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <vector>
#include <OVERPointer.h>


class Vector3 {
public:
	double x, y, z;
	Vector3(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {}
	double length() const {return sqrt(x * x + y * y + z * z);}
	void print() const {std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;}
};

int main(int argc, char** argv)
{
	char* text = "Hello world";
	int num = 10;
	std::vector<float> arr{ 10.0f, 1.2f, 2.5f, 2.2f };
	Vector3* newvec3 = new Vector3(12.5,5.1,7.2);
	uint64_t num64 = std::numeric_limits<uint64_t>::max();

	std::cout << "ORIGINAL:" << std::endl;
	std::cout << text << std::endl;
	std::cout << num << std::endl;

	for (float element : arr) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
	std::cout << num64 << std::endl;
	newvec3->print();
	std::cout << std::endl;

	OVERPTR point1 = text;
	OVERPTR point2 = &num;
	OVERPTR point3 = &arr;
	OVERPTR point4 = newvec3;
	OVERPTR point5 = &num64;
	OVERPTR point1b = text;

	std::cout << "POINTER:" << std::endl;
	std::cout << point1.Get<char*>() << std::endl;
	std::cout << *point2.Get<int*>() << std::endl;

	std::vector<float> arrtmp = *point3.Get<std::vector<float>*>();

	for (float element : arrtmp) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
	std::cout << *point5.Get<uint64_t*>() << std::endl;
	point4.Get<Vector3*>()->print();

	std::cout << std::endl <<"TEST:"<<std::endl;

	std::cout << "point1 == text: " << std::fixed << std::setw(10) << ((point1 == text) ? "True": "False" ) << std::endl;
	std::cout << "point1 == point2: " << std::fixed << std::setw(9) << ((point1 == point2) ? "True" : "False") << std::endl;
	std::cout << "point3 == arr: " << std::fixed << std::setw(11) << ((point3 == &arr) ? "True" : "False") << std::endl;
	std::cout << "point1 == point1b: "<<std::fixed << std::setw(7) << ((point1 == point1b) ? "True" : "False") << std::endl;
	std::cout << "point4 == newvec3: " << std::fixed << std::setw(7) << ((point4 == newvec3) ? "True" : "False") << std::endl;
	std::cout << "point5 == num64: " << std::fixed << std::setw(9) << ((point5 == &num64) ? "True" : "False") << std::endl;

	return 0;
}





