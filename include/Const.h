#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

const int WindowLen = 1280;
const int WindowHighet = 900;
const int BlankSpace = 100;
const int AmountInRow = 50;
const int AmountInCol = 30;



// Enum to represent level difficulty
enum STATE {EASY, NORMAL, HARD};


// struct to know which color is on right now
struct ColorToShine{
	sf::Color PLayer;
	sf::Color Enemy;
};


// struct to know percantege on the board 
struct Percentage {
	float playerPercent ;
	float enemyPercent ;
};