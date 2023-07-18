#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"
#include <unordered_set>
#include "Shape.h"


enum colorMap {Red, Green, Blue, Yellow, Magenta, Cyan};


// Abstract class to handle level difficulty
class DifficultyState
{
public:
	using Vector = std::vector<std::shared_ptr<Shape>>;

	DifficultyState() = default;
	sf::Color virtual Choose(Vector& Grid, struct ColorToShine) = 0;
	
protected:
    const std::map<enum colorMap, sf::Color> Colors = {
               {Red, sf::Color::Red},
               {Green, sf::Color::Green},
               {Blue, sf::Color::Blue},
               {Yellow, sf::Color::Yellow},
               {Magenta, sf::Color::Magenta},
               {Cyan, sf::Color::Cyan},
    };
};

