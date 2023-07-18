#pragma once
#include "fstream"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include <string>
#include "Const.h"



enum Utilities{BackGround, NewGameButton, ExitButton, EasyButton, MediumButton, HardButton };


const int SIZE = 6;
const int MUSIC = 1;

// Singleton class to handle all of the resources
class Resources{
public:
    ~Resources() = default;
    static Resources& instance();
    sf::Texture& operator[](Utilities);
    sf::SoundBuffer& operator()(int);
    sf::Font& ReturnFont();


private:
    Resources();
    Resources(const Resources&) = delete;
    Resources& operator=(const Resources&) = delete;


    sf::Texture m_ImagesTextures[SIZE];
    std::vector<std::string> m_ImagesNames;
    std::ifstream m_PngNamesFile;

    sf::SoundBuffer m_SoundBuffer[MUSIC];

    sf::Font TextFont;

    void Load();
};