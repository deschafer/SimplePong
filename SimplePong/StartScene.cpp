#include "StartScene.h"
#include "Game.h"

#include <qfont.h>

static const int ButtonBasePositionWidth = Game::Instance()->GetWndWidth() / 3;
static const int ButtonWidth = ButtonBasePositionWidth;
static const int ButtonBasePositionHeight = Game::Instance()->GetWndHeight() / 2;
static const int ButtonHeight = 50;
static const int ButtonVerticalSpacing = 10 + ButtonHeight;
static const int DiffButtonsBaseHeight = ButtonBasePositionHeight + 150;


StartScene::StartScene()
{
	

	// Setting up the game name
	QFont Font = QFont("Sans", 40, 1);
	m_Name.setStyleSheet("QLabel { background-color : black; color : white; border-radius : 0px }");
	m_Name.setFrameStyle(QFrame::Panel);
	m_Name.setText("SimplePong");
	m_Name.setAlignment(Qt::AlignBottom | Qt::AlignCenter);
	m_Name.setGeometry(QRect(0, 0, Game::Instance()->GetWndWidth(), 200));
	m_Name.setFont(Font);
	addWidget(&m_Name);

	// Draw the play button
	Font = QFont("Sans", 20, 1);
	m_PlayButton.setGeometry(QRect(ButtonBasePositionWidth, ButtonBasePositionHeight, ButtonWidth, ButtonHeight));
	m_PlayButton.setStyleSheet("QPushButton { background-color : black; color : white; border-radius : 0px }");
	m_PlayButton.setText("Play");
	m_PlayButton.setFont(Font);
	addWidget(&m_PlayButton);

	// Connecting the play button
	connect(&m_PlayButton, SIGNAL(released()), this, SLOT(Play()));

	// Draw the difficulty buttons
	Font = QFont("Sans", 15, 1);
	m_EasyButton.setGeometry(QRect(ButtonBasePositionWidth, DiffButtonsBaseHeight, ButtonWidth, 40));
	m_EasyButton.setStyleSheet("QPushButton { background-color : black; color : white; border-radius : 0px }");
	m_EasyButton.setText("Easy");
	m_EasyButton.setFont(Font);
	addWidget(&m_EasyButton);
	m_MediumButton.setGeometry(QRect(ButtonBasePositionWidth, DiffButtonsBaseHeight + ButtonVerticalSpacing, ButtonWidth, 40));
	m_MediumButton.setStyleSheet("QPushButton { background-color : black; color : white; border-radius : 0px }");
	m_MediumButton.setText("Medium");
	m_MediumButton.setFont(Font);
	addWidget(&m_MediumButton);
	m_HardButton.setGeometry(QRect(ButtonBasePositionWidth, DiffButtonsBaseHeight + 2*ButtonVerticalSpacing, ButtonWidth, 40));
	m_HardButton.setStyleSheet("QPushButton { background-color : black; color : white; border-radius : 0px }");
	m_HardButton.setText("Hard");
	m_HardButton.setFont(Font);
	addWidget(&m_HardButton);

	// Connecting the difficulty buttons
	connect(&m_EasyButton, SIGNAL(released()), this, SLOT(SetEasy()));
	connect(&m_MediumButton, SIGNAL(released()), this, SLOT(SetMedium()));
	connect(&m_HardButton, SIGNAL(released()), this, SLOT(SetHard()));

	// Coloring the background
	setBackgroundBrush(Qt::black);

}

StartScene::~StartScene()
{
}

void StartScene::Play()
{
	Game::Instance()->SetGameScene();
	//delete this;
}

void StartScene::SetDifficulty(Difficulty Diff)
{
	QFont Font("Sans", 15, 1);
	
	m_EasyButton.setFont(Font);
	m_MediumButton.setFont(Font);
	m_HardButton.setFont(Font);

	Font.setBold(true);

	switch (Diff)
	{
	case Difficulty::Easy:
		Game::Instance()->SetDifficulty(Difficulty::Easy);
		m_EasyButton.setFont(Font);
		break;
	case Difficulty::Medium:
		Game::Instance()->SetDifficulty(Difficulty::Easy);
		m_MediumButton.setFont(Font);
		break;
	case Difficulty::Impossible:
		Game::Instance()->SetDifficulty(Difficulty::Impossible);
		m_HardButton.setFont(Font);
		break;
	default:
		break;
	}
}

void StartScene::SetEasy()
{
	SetDifficulty(Difficulty::Easy);
}

void StartScene::SetMedium()
{
	SetDifficulty(Difficulty::Medium);
}

void StartScene::SetHard()
{
	SetDifficulty(Difficulty::Impossible);
}