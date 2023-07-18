#include "Hard.h"


// Func the decide which color to choose
sf::Color Hard::Choose(Vector& Grid, struct ColorToShine ActiveColors)
{
	std::unordered_set<std::shared_ptr<Shape>> Neighbor[6];

	// Go over all the neighbors of my neghbors, and count them
	for (auto& object : Grid) {
		for (int i = 0; i < object->NeighborSize(); i++) {
			auto color = object->GetNeighbor(i)->getColor();
			for (auto it = Colors.begin(); it != Colors.end(); ++it) {
				if (it->second == color && it->second != ActiveColors.Enemy && it->second != ActiveColors.PLayer) {
					Neighbor[it->first].insert(object->GetNeighbor(i));
					for (int j = 0; j < object->GetNeighbor(i)->NeighborSize(); j++)
						if (object->GetNeighbor(i)->GetNeighbor(j)->getColor() == color)
							Neighbor[it->first].insert(object->GetNeighbor(i)->GetNeighbor(j));
				}
			}
		}
	}

	// Which color i "see" the most, choose
	int MaxIndex = 0;
	int Amount = 0;
	for (int i = 0; i < 6; i++)
		if (Amount < Neighbor[i].size()) {
			Amount = Neighbor[i].size();
			MaxIndex = i;
		}

	// Take if from the map
	auto it = Colors.begin();
	std::advance(it, MaxIndex);
	sf::Color randomColor = it->second;
	return randomColor;
}
