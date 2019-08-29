#include "Game.h"
#include <QtWidgets/QApplication>
#include <time.h>

int main(int argc, char *argv[])
{

	srand(time(nullptr));

	QApplication a(argc, argv);
	
	Game::Instance()->Initialize();
	Game::Instance()->GetView()->show();


	return a.exec();
}
