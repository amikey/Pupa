#pragma once

#include <string>
#include <vector>				

class Customer
{
	friend class Problem;
public:
	int number;
	int x;
	int y;
	int demand;
	int readyTime;
	int dueTime;
	int serviceTime;
};

class Problem
{
private:
	int vehicleNumbers;
	int vehicleCapacity;
	std::vector<Customer> customers;
	Customer depot;
	Problem() = default;
public:
	static Problem loadFromFile(std::string path);

};