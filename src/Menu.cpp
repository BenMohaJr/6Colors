#include "Menu.h"
#include "Resources.h"

// Consturctor to load all
Menu::Menu(){
    CreateMainMenu();
    CreateDifficultyMenu();
}


// Create the menu function, load sprites and and set them where needed
void Menu::CreateMainMenu(){
    Resources & r = Resources::instance();
    m_MainMenuSprite[0].setTexture(r[BackGround]);
    m_MainMenuSprite[1].setTexture(r[NewGameButton]);
    m_MainMenuSprite[2].setTexture(r[ExitButton]);


    // Set scale and position
    for (int i = 1; i < MainMenu; i++) {
        m_MainMenuSprite[i].setScale({ float(0.2), float(0.15) });
        m_MainMenuSprite[i].setPosition(sf::Vector2f({ float(4.5 * BlankSpace) , float((2 * BlankSpace) + (BlankSpace * (i*2))) }));
    }

    m_MainMenuSprite[BackGround].setScale({ float(0.7), float(1) });
    m_MainMenuSprite[BackGround].setPosition(sf::Vector2f({ float(0) , float(0) }));


    // Set sound
    m_Sound[0].setBuffer(r(0));

}


// load difficulty sprites and place them on screen
void Menu::CreateDifficultyMenu() {
    Resources& r = Resources::instance();

    m_DifficultyMenu[0].setTexture(r[EasyButton]);
    m_DifficultyMenu[1].setTexture(r[MediumButton]);
    m_DifficultyMenu[2].setTexture(r[HardButton]);


    // Set scale and position
    for (int i = 0; i < MainMenu; i++) {
        m_DifficultyMenu[i].setScale({ float(0.3), float(0.25) });
        m_DifficultyMenu[i].setPosition(sf::Vector2f({ float(5 * BlankSpace) , float(( 4 * BlankSpace) + (BlankSpace * (i + 1))) }));
    }



}


// Get fuinc for sprite to draw
sf::Sprite & Menu::getMainMenuSprite(int index){
    return m_MainMenuSprite[index];
}


// Get fuinc for sprite to draw
sf::Sprite& Menu::getDifficultySprite(int index) {
    return m_DifficultyMenu[index];
}


// Get fuinc for sprite to draw
void Menu::Play(){
    m_Sound[0].play();
}


// Get fuinc for sprite to draw
void Menu::Stop() {
    m_Sound[0].stop();
}
