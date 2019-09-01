// 
// Damon Schafer
// 8/27/2019
//

#include "GameScene.h"
#include "Game.h"

#include <qpen.h>
#include <qfont.h>

// Static dimension variables
const static int BallWidth = 10;
const static int BallHeight = 10;
const static int BallSpeed = 5;
const static int PaddleHeight = 5;
const static int PaddleWidth = 90;
const static int TextBoxSize = 50;

//
// CTOR for the game scene object that should be used
// It does not initialize the object entirely, and the 
// initialize function should be called after this object is
// created.
//
GameScene::GameScene() : 
	m_DividingLine(0, Game::Instance()->GetWndHeight() / 2,
		Game::Instance()->GetWndWidth(), 0.5),
	m_TopScore(0),
	m_BottomScore(0),
	m_Win(false),
	m_TopScoreLabel(new QLabel()),
	m_BottomScoreLabel(new QLabel())
{
}

GameScene::~GameScene()
{
	delete m_PongBall;
	delete m_PlayerPaddle;
	delete m_ComputerPaddle;
	delete m_TopScoreLabel;
	delete m_BottomScoreLabel;
	delete m_Widget;
	delete m_WinLabel;
}

//
// Initialize()
// This function initializes the object properly.
//
void GameScene::Initialize()
{
	// Setting the computer speed based off 
	// the selected difficulty
	int ComputerSpeed = 0;
	switch (m_Difficulty)
	{
	case Difficulty::Easy:
		ComputerSpeed = 1;
		break;
	case Difficulty::Medium:
		ComputerSpeed = 2;
		break;
	case Difficulty::Impossible:
		ComputerSpeed = 10;
		break;
	default:
		ComputerSpeed = 1;
		break;
	}

	SetScene();	// Color the Scene

	// Creating the initial ball
	m_PongBall = new Ball(
		Game::Instance()->GetWndWidth() / 2,
		Game::Instance()->GetWndHeight() / 2,
		BallWidth,
		BallHeight,
		QVector2D(0, (rand() % 2 == 0) ? -BallSpeed : BallSpeed));
	addItem(m_PongBall);	// Add this item to this scene

	// Creating the players paddle
	m_PlayerPaddle = new PlayerPaddle(
		QRect((Game::Instance()->GetWndWidth() / 2) - (PaddleWidth / 2),
			Game::Instance()->GetWndHeight() * 0.9,
			PaddleWidth,
			PaddleHeight));
	addItem(m_PlayerPaddle);

	// Creating the computer paddle
	m_ComputerPaddle = new ComputerPaddle(
		QRect((Game::Instance()->GetWndWidth() / 2) - (PaddleWidth / 2),
			Game::Instance()->GetWndHeight() * 0.1 - PaddleHeight,
			PaddleWidth,
			PaddleHeight));
	addItem(m_ComputerPaddle);

	// Initilizing the player paddle
	m_PlayerPaddle->AddItemsToScene(this);
	m_PlayerPaddle->setFocus();

	// Initiliazing the computer paddle
	m_ComputerPaddle->AddItemsToScene(this);
	m_ComputerPaddle->SetPaddleMovementSpeed(ComputerSpeed);
}

//
// SetScene()
// Draws the dividing line and colors in the scene appropriately
//
void GameScene::SetScene()
{
	// Drawing and coloring the dividing line
	QPen Pen;
	Pen.setColor(QColor(Qt::white));
	m_DividingLine.setPen(Pen);
	addItem(&m_DividingLine);

	// Coloring the background
	setBackgroundBrush(Qt::black);

	QString TopScore = std::to_string(m_TopScore).c_str();
	QString BottomScore = std::to_string(m_BottomScore).c_str();
	QFont Font = QFont("Sans", 12, 1);

	// Setting up the score for the top player
	m_TopScoreLabel->setStyleSheet("QLabel { background-color : black; color : white; border-radius : 0px }");
	m_TopScoreLabel->setFrameStyle(QFrame::Panel);
	m_TopScoreLabel->setText(TopScore);
	m_TopScoreLabel->setAlignment(Qt::AlignBottom | Qt::AlignCenter);
	m_TopScoreLabel->setGeometry(QRect(0, Game::Instance()->GetWndHeight() / 2 - TextBoxSize - 10, TextBoxSize, TextBoxSize));
	m_TopScoreLabel->setFont(QFont("Sans", 30, 1));
	addWidget(m_TopScoreLabel);

	// Setting up the score for the bottom player
	m_BottomScoreLabel->setStyleSheet("QLabel { background-color : black; color : white; border-radius : 0px }");
	m_BottomScoreLabel->setFrameStyle(QFrame::Panel);
	m_BottomScoreLabel->setText(BottomScore);
	m_BottomScoreLabel->setAlignment(Qt::AlignBottom | Qt::AlignCenter);
	m_BottomScoreLabel->setGeometry(QRect(0, Game::Instance()->GetWndHeight() / 2 + 10, TextBoxSize, TextBoxSize));
	m_BottomScoreLabel->setFont(QFont("Sans", 30, 1));
	addWidget(m_BottomScoreLabel);
}

//
// Win()
// Adds the win message to the screen and resets the score
// after a QTimer executes.
//
void GameScene::Win()
{
	m_Win = true;
	m_WinLabel = new QLabel();
	QString Winner;

	// Finding the winner
	if (m_TopScore > m_BottomScore)
	{
		Winner = "Computer Wins";
	}
	else
	{
		Winner = "You Win!";
	}

	// Setting up the win label
	m_WinLabel->setStyleSheet("QLabel { background-color : black; color : white; border-radius : 0px }");
	m_WinLabel->setFrameStyle(QFrame::Panel);
	m_WinLabel->setText(Winner);
	m_WinLabel->setAlignment(Qt::AlignBottom | Qt::AlignCenter);
	m_WinLabel->setGeometry(QRect(0, 0, Game::Instance()->GetWndWidth(), Game::Instance()->GetWndHeight() / 2 - 100));
	m_WinLabel->setFont(QFont("Sans", 30, 1));
	m_Widget = addWidget(m_WinLabel);

	// Creating the score reset timer so that 
	// there will be a delay before the game is reset
	m_WinTimer = new QTimer();
	// Connecting the slot
	connect(m_WinTimer, SIGNAL(timeout()), this, SLOT(ResetWin()));
	m_WinTimer->start(2000);	
}

//
// ResetBall()
// Resets the ball in the center of the screen
//
void GameScene::ResetBall()
{
	// If we are displaying the win message, do 
	// not spawn a new ball
	if (m_Win) return;

	// Delete the old ball
	removeItem(m_PongBall);
	delete m_PongBall;

	// Creating the new ball
	m_PongBall = new Ball(
		Game::Instance()->GetWndWidth() / 2,
		Game::Instance()->GetWndHeight() / 2,
		BallWidth,
		BallHeight,
		QVector2D(0, (rand() % 2 == 0) ? -BallSpeed : BallSpeed));
	addItem(m_PongBall);	// Add this item to this scene
}

//
// ResetWin()
// Resets the win screen and 
//
void GameScene::ResetWin()
{
	// Reset scores
	m_BottomScore = -1;
	m_TopScore = -1;
	AddTopScore();
	AddBottomScore();

	// Reset the indicator flag
	m_Win = false;

	// Remove the win text
	removeItem(m_Widget);

	// Delete the time so it does not
	// keep signalling the slot
	delete m_WinTimer;
	m_WinTimer = nullptr;
}