#include "Solution.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>

Solution Solution::loadFromFile(std::string path)
{
	std::ifstream solutionFile(path);
	if (solutionFile.fail()) {
		std::cout << "Solution file does not exist" << std::endl;
		exit(-2);
	}

	std::string line;
	for (int i = 1; i <= 5; i++) {
		std::getline(solutionFile, line);
	}
	Solution solution;
	while (std::getline(solutionFile, line))
	{
		auto semiPos = line.find(":");
		line = line.substr(semiPos + 1);
		boost::trim(line);
		std::vector<std::string> tokens;
		boost::split(tokens, line, boost::is_any_of(" "));
		std::vector<int> route;
		std::for_each(tokens.begin(), tokens.end(),
			[&route](std::string &ns) {
			route.push_back(std::stoi(ns)); 
		});
		solution.routes.push_back(route);		
	}
	return solution;
}