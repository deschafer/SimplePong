// 
// Damon Schafer
// 8/27/2019
//

#include "HelpScene.h"
#include "Game.h"


HelpScene::HelpScene()
{
	// Coloring the background
	setBackgroundBrush(Qt::black);

	// Setting up the main title
	QFont Font = QFont("Sans", 35, 1);
	m_HowToPlay.setStyleSheet("QLabel { background-color : black; color : white; border-radius : 0px }");
	m_HowToPlay.setFrameStyle(QFrame::Panel);
	m_HowToPlay.setText("How To Play");
	m_HowToPlay.setAlignment(Qt::AlignBottom | Qt::AlignCenter);
	m_HowToPlay.setGeometry(QRect(0, 0, Game::Instance()->GetWndWidth(), 100));
	m_HowToPlay.setFont(Font);
	addWidget(&m_HowToPlay);

	// Setting up the description
	Font = QFont("Sans", 14, 1);
	m_Description.setStyleSheet("QLabel { background-color : black; color : white; border-radius : 0px }");
	m_Description.setFrameStyle(QFrame::Panel);
	m_Description.setText("Inspired by the original Pong Game. \nYou control the bottom paddle. \nMove left and right with the arrow keys. \nScore 10 points to win.");
	m_Description.setAlignment(Qt::AlignTop | Qt::AlignCenter);
	m_Description.setGeometry(QRect(0, 200, Game::Instance()->GetWndWidth(), 200));
	m_Description.setFont(Font);
	addWidget(&m_Description);

	// Setting up the back button
	Font = QFont("Sans", 14, 1);
	m_BackButton.setGeometry(QRect(Game::Instance()->GetWndWidth() / 3, 5 * Game::Instance()->GetWndHeight() / 6, Game::Instance()->GetWndWidth() / 3, 30));
	m_BackButton.setStyleSheet("QPushButton { background-color : black; color : white; border-radius : 0px }");
	m_BackButton.setText("Back To Start Menu");
	m_BackButton.setFont(Font);
	addWidget(&m_BackButton);

	// Connecting the back button
	connect(&m_BackButton, SIGNAL(released()), this, SLOT(HandleBackButton()));
}

HelpScene::~HelpScene()
{
}

void HelpScene::HandleBackButton()
{
	Game::Instance()->SetStartScene();
}