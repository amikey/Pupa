#include <iostream>
#include "Problem.h"

int main()
{
	std::string problemsFolder = "C:\\Users\\Piotr\\source\\repos\\\Pupa\\Benchmarks\\Problems\\homberger_200_customer_instances";
	auto problemC121 = Problem::loadFromFile(problemsFolder + "\\C1_2_1.txt");
	std::cout << "End of the world. At least your tiny one." << std::endl;
}