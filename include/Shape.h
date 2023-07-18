#pragma once

#include <vector>
#include <iostream>
#include "Const.h"




// Abstract class to represent all of the shapes
class Shape {
public:


    using Dev = std::vector<std::vector<std::shared_ptr<Shape>>>;
    using Vec = std::vector<std::shared_ptr<Shape>>;

    Shape(int x, int y) : m_row(x), m_col(y) { }

    sf::CircleShape get() const;
    static const std::map<std::string, sf::Color> sfmlColors;
    void add(std::shared_ptr<Shape>);
    sf::Color getColor() const;
    void Paint(sf::Color);
    int NeighborSize() const;
    std::shared_ptr<Shape> GetNeighbor(int);
    void virtual CheckForNeighbors(Dev) = 0;
    int getRow() const { return m_row; }
    int getCol() const { return m_col; }
    void setTaken() { Taken = true; }
    bool getTaken() { return Taken; }
    void changeOpacity(sf::Color, float);
    static sf::Color ChooseColor();


protected:
    
    sf::CircleShape m_Myself;
    Vec m_Neighbor;
    int m_row, m_col;
    float m_radius;
    bool Taken{ false };

    
};



bool operator==(const Shape& lhs, const Shape& rhs);