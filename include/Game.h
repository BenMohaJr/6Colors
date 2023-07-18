#pragma once

#include "Const.h"
#include "Board.h"
#include "ToolBar.h"
#include "DifficultyState.h"
#include <stack>
#include <memory>



// Class game to handle all the game 
class Game{

public:
	Game();
	
	void run(sf::RenderWindow&);
	void setState(STATE state) { m_Board.setState(state); }

private:
	ToolBar m_toolbar;
	Board<Hexagon> m_Board;

	sf::Clock m_clock;
	sf::Sprite m_NewGame;

	void HandleClick(sf::Event::MouseButtonEvent, sf::RenderWindow&);

};

