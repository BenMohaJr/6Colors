#include "Hexagon.h"


// Contructor to reset the shape
Hexagon::Hexagon(int row, int col, float k ) : Shape(row,col) {
    m_Myself = sf::CircleShape(k / 2, 6);
    // On even and odd rows move a bit to make to board look cool
    if (col % 2 == 0)
        m_Myself.setPosition(BlankSpace + row * k, BlankSpace + col * k);
    else
        m_Myself.setPosition(BlankSpace + (row * k) + k / 2, BlankSpace + col * k);
    m_Myself.setFillColor(ChooseColor());
}

//  Check for neighbors for hexagon
void Hexagon::CheckForNeighbors(Dev Grid) {

    // All of the conditions to check for hexagon neighbors
    if (m_col % 2 == 0) {
        if (m_col > 0)
        {
            m_Neighbor.push_back(Grid[m_row][m_col - 1]);
            if (m_row > 0)
                m_Neighbor.push_back(Grid[m_row - 1][m_col - 1]);
        }
        if (m_col < AmountInCol - 1)
        {
            m_Neighbor.push_back(Grid[m_row][m_col + 1]);
            if (m_row > 0)
                m_Neighbor.push_back(Grid[m_row - 1][m_col + 1]);
        }
    }
    else {
        if (m_col > 0)
        {
            m_Neighbor.push_back(Grid[m_row][m_col - 1]);
            if (m_row < AmountInRow - 1)
                m_Neighbor.push_back(Grid[m_row + 1][m_col - 1]);
        }
        if (m_col < AmountInCol - 1)
        {
            m_Neighbor.push_back(Grid[m_row][m_col + 1]);
            if (m_row < AmountInRow - 1)
                m_Neighbor.push_back(Grid[m_row + 1][m_col + 1]);
        }
    }
    if (m_row > 0)
        m_Neighbor.push_back(Grid[m_row - 1][m_col]);
    if (m_row < AmountInRow - 1)
        m_Neighbor.push_back(Grid[m_row + 1][m_col]);
}
