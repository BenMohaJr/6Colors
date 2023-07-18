#pragma once
#include "DifficultyState.h"




// Normal class that represent the level difficulty
class Normal : public DifficultyState
{
public:
	Normal() = default;
	sf::Color Choose(Vector& Grid, struct ColorToShine) override;

private:

};

