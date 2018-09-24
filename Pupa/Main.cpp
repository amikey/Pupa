#include <iostream>
#include "Problem.h"
#include "Solution.h"
#include "SolutionVisualizer.h"
#include <thread>

int main()
{
	std::string problemsFolder = "C:\\Users\\Piotr\\source\\repos\\\Pupa\\Benchmarks\\Problems";
	auto problemC121 = Problem::loadFromFile(problemsFolder + "\\C1_2_1.txt");

	std::string solutionsFolder = "C:\\Users\\Piotr\\source\\repos\\\Pupa\\Benchmarks\\Solutions";
	auto solutionC121 = Solution::loadFromFile(solutionsFolder + "\\C1_2_1.txt");

	auto solutionVisualizer = SolutionVisualizer(problemC121, solutionC121);
	solutionVisualizer.show();

	std::cout << "End of the world. At least your tiny one." << std::endl;
}