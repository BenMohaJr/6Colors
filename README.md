# 6 Colors

## Description

This project is a game developed as part of a college project using C++ and the SFML (Simple and Fast Multimedia Library) graphic library. The game features a customizable board filled with various shapes, including hexagons, and involves a strategic color dominance concept. The objective is to reach 50 percent color ownership on the board to win the game.

## Features

- Customizable board: The game allows the addition of various shapes, not limited to hexagons, through the use of templates. This provides flexibility in expanding the game with different shapes in the future.

- Color dominance gameplay: Players take turns selecting colors to gain control over regions on the board. The goal is to achieve 50 percent color ownership before the opponent does.

- State design pattern: The State design pattern is implemented to manage the game's different states, such as menu, gameplay, and game over screens. This ensures a clean separation of concerns and improves code maintainability.

## Dependencies

- SFML: The game utilizes the SFML graphic library for rendering graphics, handling user input, and managing audio. Make sure to have SFML properly installed and configured.

## Installation

1. Clone the repository or download the project files to your local machine.
```
git clone https://github.com/your_username/your_repository.git
```

2. Ensure that SFML is installed on your system. You can find SFML installation instructions at: [SFML Installation](https://www.sfml-dev.org/download.php)

3. Build the project using your preferred C++ compiler. Here's an example using g++:
```
g++ -o game main.cpp -lsfml-graphics -lsfml-window -lsfml-system
```

4. Run the executable file to start the game.
```
./game
```

## Usage

- Upon launching the game, the main menu will be displayed.

- Use the arrow keys or mouse to navigate through the menu options.

- Select the desired game mode or any other available options.

- During gameplay, players take turns selecting colors to dominate regions on the board.

- The game continues until one player reaches 50 percent color ownership, resulting in a victory.

- After the game ends, the final score and an option to play again or quit will be displayed.
ur project.
