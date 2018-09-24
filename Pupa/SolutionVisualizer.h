#pragma once

#include "Solution.h"
#include "Problem.h"
#include <SFML/Graphics.hpp>

struct Boundaries
{
public:
	int xMax, xMin;
	int yMax, yMin;
};

class SolutionVisualizer
{
private:
	Problem problem;
	Solution solution;
	std::string windowName;
public:
	SolutionVisualizer(Problem problem_a, Solution solution_a, std::string name = "") : problem(problem_a), solution(solution_a) 
	{
		if (name.empty()) {
			windowName = problem.getName();
		}
		else {
			windowName = name;
		}
	}
	void show();
	std::vector<sf::CircleShape> getCustomersShapes(int width, int height);
	Boundaries calculateBoundaries();
};