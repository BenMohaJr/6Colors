#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>


const int MainMenu = 3;
const int Music = 1;


// Menu class to draw and handle the menu
class Menu {
public:
    Menu();
    void CreateMainMenu();
    void CreateDifficultyMenu();
    sf::Sprite & getMainMenuSprite(int);
    sf::Sprite& getDifficultySprite(int index);
    void Play();
    void Stop();


private:
    sf::Sprite m_MainMenuSprite[MainMenu];

    sf::Sprite m_DifficultyMenu[MainMenu];

    sf::Sound m_Sound[Music];

};