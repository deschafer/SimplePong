// 
// Damon Schafer
// 8/27/2019
//

#pragma once
#include <qgraphicsscene.h>
#include <qlabel.h>
#include <QPushButton>

enum class Difficulty;

// 
// The start menu scene of the game,
// contains buttons to select difficulty, start the game,
// and get help
//

class StartScene : public QGraphicsScene
{
	Q_OBJECT
private:

	QLabel m_Name;					// Game name
	QPushButton m_PlayButton;		// Press to play the game
	QPushButton m_EasyButton;		// Diff buttons
	QPushButton m_MediumButton;
	QPushButton m_HardButton;	
	QPushButton m_HelpButton;		// navigates to the help screen

public:
	StartScene();
	virtual ~StartScene();

	void SetDifficulty(Difficulty Diff);

public slots:

	void Play();
	void SetEasy();
	void SetMedium();
	void SetHard();
	void SetHelpScene();
};

