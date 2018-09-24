#include "Problem.h"
#include <fstream>
#include <iostream>

Problem Problem::loadFromFile(std::string path)
{	
	std::ifstream benchmark(path);
	if (benchmark.fail()) {
		std::cout << "Benchmark file does not exist" << std::endl;
		exit(-2);
	}

	std::string line;
	for (int i = 1; i < 5; i++) {
		std::getline(benchmark, line);
	}
	Problem problem;
	benchmark >> problem.vehicleNumbers >> problem.vehicleCapacity;

	for (int i = 1; i < 5; i++) { std::getline(benchmark, line); }

	int previousNumber = -1;
	while (std::getline(benchmark, line))
	{
		Customer customer;
		benchmark >> customer.number >> customer.x >> customer.y >> customer.demand >> customer.readyTime >> customer.dueTime >> customer.serviceTime;;
		while (customer.number != previousNumber) {
			problem.customers.push_back(customer);
			previousNumber = customer.number;
		}
	}
	problem.depot = problem.customers[0];
	return problem;
}