#pragma once
#include <thread>
#include "Const.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"
#include <iomanip>
#include <sstream>
#include "Resources.h"



// Toolbar class to handle the color the is pressed on 
class ToolBar
{
public:

	ToolBar();
	void draw(sf::RenderWindow&, struct ColorToShine, struct Percentage);
	sf::RectangleShape& returnRecrangle(int);

	void GameOverFunc(sf::RenderWindow& window);


private:

	void PrintPercent(float, sf::RenderWindow&, std::string);
	std::vector<sf::RectangleShape> m_buttons;

};
