#pragma once

#include "ToolBar.h"
#include "DifficultyState.h"
#include "Normal.h"
#include "Easy.h"
#include "Hard.h"
#include "Hexagon.h"
#include "Const.h"


#include <memory>
#include <thread>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <set>


//Tempolate class to represent the generic data structure
template <class T>
class Board {
public:
    Board();
    void buildGrid();
    void DrawShapes(sf::RenderWindow &);
    void HandleColor(sf::Color Color);
    void HandleEnemy();

    struct ColorToShine ColorIsAllowed() { return m_ActiveColors; }
    struct Percentage PercentOnBoard() { return m_playersPercent; }

    void Flicker(float);
    void FlickerEnemy(float);

    void setState(STATE state);

private:
    using Grid = std::vector<std::vector<std::shared_ptr<Shape>>>;
    using Map = std::vector<std::shared_ptr<Shape>>;
    using State = std::unique_ptr<DifficultyState>;

    void CheckForDuplicates(Map& vector, std::shared_ptr<Shape> object);
    void MyNeighbor(Map & vector, std::shared_ptr<Shape> canidate, sf::Color color);

    float m_radius{(WindowLen - 2 * BlankSpace) / AmountInRow};
    
    struct ColorToShine m_ActiveColors;
    struct Percentage m_playersPercent;

    Grid m_Grid;

    Map m_Player;
    Map m_Enemy;

    State m_Difficulty;
};


// Contructor
template<class T>
Board<T>::Board() {
    // run untill my tile is different in color than your tile
    do
    {
        buildGrid();
    } while (m_ActiveColors.PLayer == m_ActiveColors.Enemy);
}


// Build the grid and reset all the vectors
template<class T>
void Board<T>::buildGrid() {
    m_Grid.clear();
    m_Enemy.clear();
    m_Player.clear();


    // Build grid
    for (int i = 0; i < AmountInRow; i++) {
        Map temp;
        for (int j = 0; j < AmountInCol; j++)
            temp.push_back(std::make_shared<T>(i, j, m_radius));
        m_Grid.push_back(temp);
    } 


    // Build neighbors
    for (int i = 0; i < AmountInRow; i++)
        for (int j = 0; j < AmountInCol; j++)
            m_Grid[i][j]->CheckForNeighbors(m_Grid);
    

    // push different tiles to player and enemy
    m_Enemy.push_back(m_Grid[AmountInRow - 1][0]);
    m_ActiveColors.Enemy = m_Enemy[0]->getColor();
    m_Player.push_back(m_Grid[0][AmountInCol - 1]);
    m_ActiveColors.PLayer = m_Player[0]->getColor();


    // reset percantage
    m_playersPercent.playerPercent = m_Player.size() / (AmountInRow * AmountInCol);
    m_playersPercent.enemyPercent = m_Enemy.size() / (AmountInRow * AmountInCol);
}


// Draw the board
template<class T>
void Board<T>::DrawShapes(sf::RenderWindow & window) {
    for (auto & object : m_Grid){
        for (auto& cell : object)
            window.draw(cell->get());
    }

}


// Change the opacity of the player
template<class T>
void Board<T>::Flicker(float FlickerSpeed) {
    for (auto& object : m_Player)
        object->changeOpacity(m_ActiveColors.PLayer, FlickerSpeed);
}


// Change the opacity of the enemy
template<class T>
void Board<T>::FlickerEnemy(float FlickerSpeed) {
    for (auto& object : m_Enemy)
        object->changeOpacity(m_ActiveColors.Enemy, FlickerSpeed);
}


// Handle player color and neighbors func
template<class T>
void Board<T>::HandleColor(sf::Color Color) {

    // Add neighbors in the same color
    for (int i = 0; i < m_Player.size(); i++)
        MyNeighbor(m_Player, m_Player[i], Color);


    // Paint the neighbors you added
    for (auto& object : m_Player)
        object->Paint(Color);
    m_ActiveColors.PLayer = Color;


    // update percent as follows
    m_playersPercent.playerPercent = ((float)m_Player.size()) / (AmountInCol * AmountInRow);
}

template<class T>
void Board<T>::HandleEnemy() {
    sf::Color color = (m_Difficulty->Choose(m_Enemy, m_ActiveColors));


    // Add neighbors in the same color
    for (int i = 0; i < m_Enemy.size(); i++)
        MyNeighbor(m_Enemy, m_Enemy[i], color);


    // Paint the neighbors you added
    for (auto& object : m_Enemy)
        object->Paint(color);
    m_ActiveColors.Enemy = color;


    // update percent as follows
    m_playersPercent.enemyPercent = ((float)(m_Enemy.size()) / (AmountInCol * AmountInRow));
}


// Enum class to create the level difficulty
template<class T>
void Board<T>::setState(STATE state){
    switch (state)
    {
    case EASY:      m_Difficulty.reset(new Easy);               break;

    case NORMAL:    m_Difficulty.reset(new Normal);             break;

    case HARD:      m_Difficulty.reset(new Hard);               break;
    }
}

// Add neighbors func
template<class T>
void Board<T>::MyNeighbor(Map & vector, std::shared_ptr<Shape> canidate, sf::Color color) {
    for(int i = 0; i < canidate->NeighborSize(); i++) {
        if (canidate->GetNeighbor(i)->getColor() == color && !canidate->GetNeighbor(i)->getTaken())
            CheckForDuplicates(vector, canidate->GetNeighbor(i));
    }
}


// Check forf every neighbors func if exists already or not
template<class T>
void Board<T>::CheckForDuplicates(Map & vector, std::shared_ptr<Shape> canidate) {
    for (auto& object : vector)
        if (object == canidate)
            return; 

    // Set neighbors as taken so no one else can add him
    canidate->setTaken();
    vector.push_back(canidate);
}
