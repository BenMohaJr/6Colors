#pragma once
#include "DifficultyState.h"




// Easy class that represent the level difficulty
class Easy : public DifficultyState
{
public:
	Easy() = default;
	sf::Color Choose(Vector& Grid, struct ColorToShine) override;

private:

};