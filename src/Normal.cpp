#include "Normal.h"


// Func to check for which color to choose
sf::Color Normal::Choose(Vector& Grid, struct ColorToShine ActiveColors)
{	
	std::unordered_set<std::shared_ptr<Shape>> Neighbor[6];

	// Go over my neighbors and see which color dominates
	for (auto& object : Grid) {
		for (int i = 0; i < object->NeighborSize(); i++) {
			auto color = object->GetNeighbor(i)->getColor();
			for (auto it = Colors.begin(); it != Colors.end(); ++it) {
				if (it->second == color && it->second != ActiveColors.Enemy && it->second != ActiveColors.PLayer)
					Neighbor[it->first].insert(object->GetNeighbor(i));
				}
		}
	}
	
	// After knowing the colors set, select the max one
	int MaxIndex = 0;
	int Amount = 0;
	for (int i = 0; i < 6; i++)
		if (Amount < Neighbor[i].size()) {
			Amount = Neighbor[i].size();
			MaxIndex = i;
		}


	// return the max one
	auto it = Colors.begin();
	std::advance(it, MaxIndex);
	sf::Color randomColor = it->second;
	return randomColor;
}
