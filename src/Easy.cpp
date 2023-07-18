#include "Easy.h"



// Class to handle the color been chosen by computer
sf::Color Easy::Choose(Vector& Grid, struct ColorToShine ActiveColors)
{
	// Random color
	sf::Color color;
	do
	{
		color = Shape::ChooseColor();
	} while (color == ActiveColors.Enemy || color == ActiveColors.PLayer);
    return color;
}
