#include "Game.h"


// Contructor to set newgame button at the top
Game::Game() {
    Resources& r = Resources::instance();
    m_NewGame.setTexture(r[NewGameButton]);
    m_NewGame.setScale({ float(0.1), float(0.075) });
    m_NewGame.setPosition(sf::Vector2f({ float(5.5 * BlankSpace) , float(-20) }));
}


// Main func to run the game
void Game::run(sf::RenderWindow & window)
{
    bool stop = false;
    sf::Clock clock;
    auto flickerSpeed = 0.7f;
    float flickerAmount = 0;
    sf::Clock ControlClock;
    while (window.isOpen() && m_Board.PercentOnBoard().enemyPercent < 0.5 && m_Board.PercentOnBoard().playerPercent < 0.5 && !stop)
    {   // window color
        
        sf::Time elapsed = ControlClock.getElapsedTime();
        // Flicker every k seconds, k = 0.8
        if (elapsed.asSeconds() > 0.8) {
            elapsed = ControlClock.restart();
            float flickerAmount = std::sin(elapsed.asSeconds() * flickerSpeed) + 0.5f;
            m_Board.Flicker(flickerAmount);
        }        

        // Handle clicks
        for (auto event = sf::Event(); window.pollEvent(event);) {
            
            switch (event.type){

            case sf::Event::Closed: { // if someone wants to quit
                window.close();
                break;

            }// if any-other key is pressed
            case sf::Event::MouseButtonReleased: {
                if (m_NewGame.getGlobalBounds().contains
                (window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
                    stop = true;
                HandleClick(event.mouseButton, window);
                break;
                }
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    stop = true;
                break;
            }
        }
        // Draw
        window.clear();
        m_toolbar.draw(window, m_Board.ColorIsAllowed(), m_Board.PercentOnBoard());
        m_Board.DrawShapes(window);
        window.draw(m_NewGame);
        window.display();
    }
    // Build grid and print message after end
    if (m_Board.PercentOnBoard().enemyPercent > 0.5 || m_Board.PercentOnBoard().playerPercent > 0.5)
        m_toolbar.GameOverFunc(window);
    m_Board.buildGrid();
}


// Handle click func
void Game::HandleClick(sf::Event::MouseButtonEvent buttonPressed, sf::RenderWindow & window) {
    struct ColorToShine ActiveColors = m_Board.ColorIsAllowed();
    for (int i = 0; i < Shape::sfmlColors.size(); i++) {
        if (m_toolbar.returnRecrangle(i).getGlobalBounds().contains
        (window.mapPixelToCoords({ buttonPressed.x, buttonPressed.y }))) {

            // Check which color is pressed on
            if (m_toolbar.returnRecrangle(i).getFillColor() != ActiveColors.Enemy &&
                m_toolbar.returnRecrangle(i).getFillColor() != ActiveColors.PLayer ) {
                m_Board.HandleColor(m_toolbar.returnRecrangle(i).getFillColor());

                sf::Clock ControlClock;
                sf::Clock Clock;
                auto flickerSpeed = 0.7f;
                sf::Time elapsed = ControlClock.restart();
                sf::Time RunTime = Clock.restart();

                // Let the computer think a bit, and flicker
                while (RunTime.asSeconds() < 2.0f) {
                    elapsed = ControlClock.getElapsedTime();
                    if (elapsed.asSeconds() > 0.8) {
                        elapsed = ControlClock.restart();
                        float flickerAmount = std::sin(elapsed.asSeconds() * flickerSpeed) + 0.5f;
                        m_Board.FlickerEnemy(flickerAmount);
                    }

                    // Now after the thought print his decision
                    RunTime = Clock.getElapsedTime();
                    window.clear();
                    m_toolbar.draw(window, m_Board.ColorIsAllowed(), m_Board.PercentOnBoard());
                    m_Board.DrawShapes(window);
                    window.draw(m_NewGame);
                    window.display();
                }
                m_Board.HandleEnemy();
            }
        }
    }
}


