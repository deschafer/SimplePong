// 
// Damon Schafer
// 8/27/2019
//

#pragma once
#include <qgraphicsscene.h>
#include <qlabel.h>
#include <qpushbutton.h>

class HelpScene : public QGraphicsScene
{
	Q_OBJECT
private:

	QLabel m_HowToPlay;			// Title of this scene
	QLabel m_Description;		// Describes how to play
	QPushButton m_BackButton;	// Button to go back to the game

public:
	HelpScene();
	virtual ~HelpScene();

public slots:
	void HandleBackButton();
};

