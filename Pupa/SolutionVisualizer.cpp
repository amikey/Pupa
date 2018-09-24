#include "SolutionVisualizer.h"
#include <limits>

void SolutionVisualizer::show() {
	sf::RenderWindow window(sf::VideoMode(1000, 600), windowName, sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(30);
	sf::RectangleShape background(sf::Vector2f(600, 600));
	background.setFillColor(sf::Color::White);
	auto customers = getCustomersShapes(600, 600);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(background);
		window.display();
	}
}

std::vector<sf::CircleShape> SolutionVisualizer::getCustomersShapes(int width, int height)
{
	std::vector<sf::CircleShape> shapes;
	auto boundaries = calculateBoundaries();


	return shapes;
}

Boundaries SolutionVisualizer::calculateBoundaries()
{
	Boundaries boundaries;
	int maxX = 0, minX = 9999, maxY = 0, minY = 9999;
	for (auto& customer : problem.getCustomers())
	{
		if (customer.x > maxX) {
			maxX = customer.x;
		}
		if (customer.x < minX) {
			minX = customer.x;
		}
		if (customer.y > maxY) {
			maxY = customer.y;
		}
		if (customer.y < minY) {
			minY = customer.y;
		}
	}
	boundaries.xMax = maxX;
	boundaries.xMin = minX;
	boundaries.yMax = maxY;
	boundaries.yMin = minY;
	return boundaries;
}