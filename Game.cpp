#include "Game.h"

void Game::init()
{
	system("cls");
	drawBorders();
	boards[0].draw();
	boards[1].draw();
}

void Game::menu()
{
	cout << "WELCOME !" << endl;
	cout << "enter your choice and press return :" << endl;
	cout << "(1) Start a new game" << endl;
	//	(2) Continue a paused game
	cout <<	"(8) Present instructions and keys" << endl;
	cout <<	"(9) EXIT" << endl;
		

	int userInput = 0;
	cin >> userInput;

	switch (userInput)
	{
	case 1: //start the game
		this->init();
		this->run();
		break;
	case 8: 
		cout << "888"; 
		break;
	case 9: 
		cout << "GOOD BYE !";
		break;
	default: 
		cout << "no";
		userInput = 0;
		break;
	}
}

void Game::run()
{
	char key = 0;
	int stepsCounter = 0;
	bool dropRight = false;
	bool dropLeft = false;

	do {
		if (_kbhit())
		{
			key = _getch();
			//left player commands
			if (key == 'W' || key == 'w') {
				boards[0].rotateCounterClockwise();
			}
			else if (key == 'S' || key == 's') {
				boards[0].rotateClockwise();
			}
			else if (key == 'D' || key == 'd') {
				boards[0].moveRight();
			}
			else if (key == 'A' || key == 'a') {
				boards[0].moveLeft();
			}
			else if (key == 'X' || key == 'x') {
				dropLeft = true;
			}
			//right player commands
			else if (key == 'I' || key == 'i') {
				boards[1].rotateCounterClockwise();
			}
			else if (key == 'K' || key == 'k') {
				boards[1].rotateClockwise();
			}
			else if (key == 'L' || key == 'l') {
				boards[1].moveRight();
			}
			else if (key == 'J' || key == 'j') {
				boards[1].moveLeft();
			}
			else if (key == 'M' || key == 'm') {
				dropRight = true;
			}

		}

		if (!stepsCounter) {
			boards[0].step(dropLeft);
			boards[1].step(dropRight);
			dropLeft = false;
			dropRight = false;
		}
		stepsCounter = (++stepsCounter) % 20;
		Sleep(GAME_SPEED);
	} while (key != ESC && !boards[0].isLost() && !boards[1].isLost());

	setTextColor(Color::WHITE);
	clear_screen();

	if (!boards[0].isLost() && boards[1].isLost()) {
		cout << "Left Player Wins" << endl;
	}

	if (boards[0].isLost() && !boards[1].isLost()) {
		cout << "Right Player Wins" << endl;
	}
}

void Game::drawBorders()
{
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j <= 18; j++) {
			if (j == 18 || i == 0 || i == 13 || i == 26) {
				gotoxy(i, j);
				cout << '*' << endl;
			} 
		}
	}
}