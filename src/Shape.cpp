//
// Created by Lior Ben moha on 07/05/2023.
//

#include "Shape.h"
#include <ctime>

//  Colors map 
const std::map<std::string, sf::Color> Shape::sfmlColors = {
               {"Red", sf::Color::Red},
               {"Green", sf::Color::Green},
               {"Blue", sf::Color::Blue},
               {"Yellow", sf::Color::Yellow},
               {"Magenta", sf::Color::Magenta},
               {"Cyan", sf::Color::Cyan},
};


// Get the object itself
sf::CircleShape Shape::get() const {
    return m_Myself;
}


// Add object to neighbor array
void Shape::add(std::shared_ptr<Shape> Neighbor){
    m_Neighbor.push_back(Neighbor);
}


// Get color for object
sf::Color Shape::getColor() const{
    return m_Myself.getFillColor();
}


// Paint object
void Shape::Paint(sf::Color color){
    m_Myself.setFillColor(color);
}

// Get func for neighbor size
int Shape::NeighborSize() const {
    return m_Neighbor.size();
}


// Get neighbor in certain place
std::shared_ptr<Shape> Shape::GetNeighbor(int i) {
    return m_Neighbor[i];
}

// Chnage opacity for myself
void Shape::changeOpacity(sf::Color Active, float FlickerSpeed){

    if (m_Myself.getFillColor() == sf::Color::White)
        m_Myself.setFillColor(Active);
    else
        m_Myself.setFillColor(sf::Color::White);
}


// Choose random color
sf::Color Shape::ChooseColor() {
    int randomIndex = rand();
    randomIndex %= sfmlColors.size();
    auto it = sfmlColors.begin();
    std::advance(it, randomIndex);
    sf::Color randomColor = it->second;
    return randomColor;
}


// Check for duplicates func
bool operator==(const Shape& lhs, const Shape& rhs) {
    return ((lhs.getCol() == rhs.getCol()) && (lhs.getRow() == rhs.getRow()));
}

