#pragma once
#include "DifficultyState.h"



// Hard class that represent the level difficulty
class Hard : public DifficultyState
{
public:
	Hard() = default;
	sf::Color Choose(Vector& Grid, struct ColorToShine ) override;

private:

};

