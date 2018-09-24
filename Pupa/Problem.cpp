#include "Problem.h"
#include <fstream>
#include <iostream>

Problem Problem::loadFromFile(std::string path)
{	
	std::ifstream benchmarkFile(path);
	if (benchmarkFile.fail()) {
		std::cout << "Benchmark file does not exist" << std::endl;
		exit(-2);
	}

	std::string line;
	for (int i = 1; i < 5; i++) {
		std::getline(benchmarkFile, line);
	}
	Problem problem;
	problem.name = path.substr(path.find_last_of("\\") + 1);
	benchmarkFile >> problem.vehicleNumbers >> problem.vehicleCapacity;

	for (int i = 1; i < 5; i++) { std::getline(benchmarkFile, line); }

	int previousNumber = -1;
	while (std::getline(benchmarkFile, line))
	{
		Customer customer;
		benchmarkFile >> customer.number >> customer.x >> customer.y >> customer.demand >> customer.readyTime >> customer.dueTime >> customer.serviceTime;;
		while (customer.number != previousNumber) {
			problem.customers.push_back(customer);
			previousNumber = customer.number;
		}
	}
	problem.depot = problem.customers[0];
	return problem;
}