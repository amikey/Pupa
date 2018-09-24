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
	std::string name;
	Problem() = default;
public:
	static Problem loadFromFile(std::string path);
	std::string getName() { return name; }
	std::vector<Customer> getCustomers() { return customers; }
};