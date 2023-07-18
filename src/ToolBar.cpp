
#include "ToolBar.h"


// Contructor to intialize the cubes and place them
ToolBar::ToolBar()
{
	int InstanceWidth = (WindowLen - 4 * BlankSpace) / Shape::sfmlColors.size();
	// Create cubes and place them on the board
	for (int i = 0; i < Shape::sfmlColors.size(); i++) {
		auto temp = sf::RectangleShape(sf::Vector2f(InstanceWidth / 2 , InstanceWidth / 2));
		temp.setOrigin(InstanceWidth / 4, InstanceWidth / 4);
		temp.setPosition(sf::Vector2f((3 * BlankSpace) + (i * InstanceWidth) - 50, WindowHighet - BlankSpace));
		auto it = Shape::sfmlColors.begin();
		std::advance(it, i);
		sf::Color current = it->second;
		temp.setFillColor(current);
		temp.setOutlineColor(sf::Color::White);
		temp.setOutlineThickness(1.5);
		m_buttons.push_back(temp);
	}
}

// Draw func to draw all the cubes
void ToolBar::draw(sf::RenderWindow & window, struct ColorToShine Active, struct Percentage percent) {
	for (auto& object : m_buttons) {
		object.setScale(sf::Vector2f(1, 1));
		if (object.getFillColor() == Active.Enemy || object.getFillColor() == Active.PLayer)
			object.setScale(sf::Vector2f(1.5, 1.5));
	}

	for (auto& object : m_buttons)
		window.draw(object);

	// Print the percent on the board
	PrintPercent(percent.playerPercent, window, "Player: ");
	PrintPercent(percent.enemyPercent, window, "Enemy: ");
}


// Print the precent itself, build the text and print on board
void ToolBar::PrintPercent(float PercentToPrint, sf::RenderWindow & window, std::string str) {
	sf::Text text;
	
	Resources& r = Resources::instance();
	PercentToPrint *= 100;
	text.setString(str + std::to_string(PercentToPrint));
	text.setFont(r.ReturnFont());
	text.setCharacterSize(50);
	if (str == "Player: ")
		text.setPosition(100, 20);
	else
		text.setPosition(800, 20);
	
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Green);
	text.setOutlineColor(sf::Color::Cyan);
	text.setOutlineThickness(1.5);
	window.draw(text);
}

// Return cube by certain index
sf::RectangleShape & ToolBar::returnRecrangle(int i) {
	return m_buttons[i];
}

//-------------- NEW FUNCTION --------------
void ToolBar::GameOverFunc(sf::RenderWindow & window) {
	sf::Text text;
	text.setString("Game Over \n See You At The Project");
	Resources& r = Resources::instance();
	text.setFont(r.ReturnFont());
	text.setCharacterSize(80);
	text.setPosition(30, 500);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Green);
	text.setOutlineColor(sf::Color::Cyan);
	text.setOutlineThickness(1.5);
	window.clear();
	window.draw(text);
	window.display();
	std::this_thread::sleep_for(std::chrono::seconds(10));
}