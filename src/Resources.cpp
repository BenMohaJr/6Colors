#include "Resources.h"


//-------------- NEW FUNCTION --------------
// load all of the images from the namefile constructor
Resources::Resources(){
    const char * path = "Texture.txt";
    m_PngNamesFile.open(path);
    std::string line;
    while(getline(m_PngNamesFile,line)){
        m_ImagesNames.push_back(line);
    }
    Load();
}


//-------------- NEW FUNCTION --------------
// Create the instance
Resources &Resources::instance() {
    static Resources resource;
    return resource;
}

//-------------- NEW FUNCTION --------------
// Load textures by names
void Resources::Load(){
    for(int i = 0; i<m_ImagesNames.size(); i++) {
        m_ImagesTextures[i].loadFromFile(m_ImagesNames[i]);
    }
    m_SoundBuffer[0].loadFromFile("BackgroundMusic.wav");
}

//-------------- NEW FUNCTION --------------
// Get func for operator []
sf::Texture& Resources::operator[](Utilities type) {
    return m_ImagesTextures[type];
}

//-------------- NEW FUNCTION --------------
// Get func fr operator ()
sf::SoundBuffer& Resources::operator()(int index){
    return m_SoundBuffer[index];
}


// Get func for font
sf::Font& Resources::ReturnFont() {
    const std::string name = "Inkfree.ttf";
    TextFont.loadFromFile(name);
    return TextFont;
}