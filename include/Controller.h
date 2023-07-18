#pragma once

#include "Game.h"
#include <iostream>
#include "Const.h"
#include "Menu.h"
#include "Resources.h"
#include "Easy.h"
#include "Normal.h"
#include "Hard.h"


#include <memory>


// Controller class to handle the game
class Controller {
public:
    Controller();
    void runWindow();

    void ChooseDifficulty();

    void HandleSecondStageClick(sf::Event::MouseButtonEvent event);

    void drawDifficultyMenu();

private:
    sf::RenderWindow m_Window;
    Game m_game;
    Menu m_Menu;

    void HandleFirstStageClick(sf::Event::MouseButtonEvent event);

    void drawMenu();
};