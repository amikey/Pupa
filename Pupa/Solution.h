#pragma once

#include <vector>


class Solution
{
private:
	std::vector<std::vector<int>> routes;
public:
	static Solution loadFromFile(std::string path);
};