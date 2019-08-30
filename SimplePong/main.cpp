//
// Damon Schafer
// 8/28/2019
//


#include "Game.h"
#include <QtWidgets/QApplication>
#include <time.h>

int main(int argc, char *argv[])
{
	// Random time seed generation
	srand(time(nullptr));

	QApplication a(argc, argv);
	
	// The game class manages the program
	Game::Instance()->Initialize();
	Game::Instance()->GetView()->show();

	return a.exec();
}
