//
// Created by Lior Ben moha on 07/05/2023.
//

#include "Controller.h"
#include <memory>


// Constructor to reser the window
Controller::Controller() : m_Window(sf::RenderWindow(sf::VideoMode
                        (WindowLen, WindowHighet), "6 Colors", sf::Style::Close | sf::Style::Titlebar)){
    Resources& r = Resources::instance();

}


// Main func to run the window in first stage
void Controller::runWindow() {
    m_Window.display();
    m_Menu.Play();
    while (m_Window.isOpen())
    {   // window color

        if (auto event = sf::Event{}; m_Window.waitEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed: { // if someone wants to quit
                    m_Window.close();
                    break;
                }// if any-other key is pressed
                case sf::Event::MouseButtonReleased: {
                    HandleFirstStageClick(event.mouseButton);
                    break;
                }
            }
        }
        m_Window.clear();
        drawMenu();
        m_Window.display();

    }
}


// Draws menu
void Controller::drawMenu() {
    for(int i = 0; i<3; i++)
        m_Window.draw(m_Menu.getMainMenuSprite(i));
}


// Handle Menu Buttons
void Controller::HandleFirstStageClick(sf::Event::MouseButtonEvent event) {
    for (int i = 1; i < MainMenu; i++) {
        if (m_Menu.getMainMenuSprite(i).getGlobalBounds().contains
        (m_Window.mapPixelToCoords({ event.x, event.y }))) {
            switch (i)
            {
            case NewGameButton:
                ChooseDifficulty();
                break;

            case ExitButton:
                m_Window.close();
                break;
            }
        }
    }
}


// Choose difficulty function
void Controller::ChooseDifficulty() {
    bool Esc = false;
    while (m_Window.isOpen() && !Esc)
    {   // window color

        if (auto event = sf::Event{}; m_Window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: { // if someone wants to quit
                m_Window.close();
                break;
            }// if any-other key is pressed
            case sf::Event::MouseButtonReleased: {
                HandleSecondStageClick(event.mouseButton);
                break;
            }
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    Esc = true;
                break;
            }
        }
        m_Window.clear();
        m_Window.draw(m_Menu.getMainMenuSprite(BackGround));
        drawDifficultyMenu();
        m_Window.display();

    }
}


// Main func to handle second stage window, where a difficulty has been pressed
void Controller::HandleSecondStageClick(sf::Event::MouseButtonEvent event) {

    for (int i = 0; i < MainMenu; i++) {
        if (m_Menu.getDifficultySprite(i).getGlobalBounds().contains
        (m_Window.mapPixelToCoords({ event.x, event.y }))) {
            switch (i)
            {
            case EASY:
                m_game.setState(EASY);
                m_game.run(m_Window);
                break;

            case NORMAL:
                m_game.setState(NORMAL);
                m_game.run(m_Window);
                break;

            case HARD:
                m_game.setState(HARD);
                m_game.run(m_Window);
                break;
            }
        }
    }
}


// Draw function
void Controller::drawDifficultyMenu() {
    for (int i = 0; i < MainMenu; i++)
        m_Window.draw(m_Menu.getDifficultySprite(i));
}




