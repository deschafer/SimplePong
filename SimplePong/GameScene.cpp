#include "GameScene.h"
#include "Game.h"

#include <qpen.h>

const static int BallWidth = 10;
const static int BallHeight = 10;
const static int PaddleHeight = 90;
const static int PaddleWidth = 90;


GameScene::GameScene() : 
	m_DividingLine(0, Game::Instance()->GetWndHeight() / 2,
		Game::Instance()->GetWndWidth(), 0.5)
{
	SetScene();	// Color the Scene

	// Creating the initial ball
	m_PongBall = new Ball(
		Game::Instance()->GetWndWidth() / 2, 
		Game::Instance()->GetWndHeight() / 2,
		BallWidth,
		BallHeight,
		QVector2D(0, (rand() % 2 == 0) ? -3 : 3));
	addItem(m_PongBall);	// Add this item to this scene

	// Creating the players paddle
	m_PlayerPaddle = new PlayerPaddle(
		QRect((Game::Instance()->GetWndWidth() / 2) - (PaddleWidth / 2),
			Game::Instance()->GetWndHeight() * 0.9, 
			PaddleWidth, 
			PaddleHeight));
	addItem(m_PlayerPaddle);

	// Creating the players paddle
	m_ComputerPaddle = new ComputerPaddle(
		QRect((Game::Instance()->GetWndWidth() / 2) - (PaddleWidth / 2),
			Game::Instance()->GetWndHeight() * 0.1,
			PaddleWidth,
			PaddleHeight));
	addItem(m_ComputerPaddle);

	// Initilizing the player paddle
	m_PlayerPaddle->AddItemsToScene(this);
	m_PlayerPaddle->setFocus();

	m_ComputerPaddle->AddItemsToScene(this);
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
}

GameScene::~GameScene()
{
}

//
// ResetBall()
// Resets the ball in the center of the screen
//
void GameScene::ResetBall()
{
	// Delete the old ball
	removeItem(m_PongBall);
	delete m_PongBall;

	// Creating the new ball
	m_PongBall = new Ball(
		Game::Instance()->GetWndWidth() / 2,
		Game::Instance()->GetWndHeight() / 2,
		BallWidth,
		BallHeight,
		QVector2D(0, (rand() % 2 == 0) ? -3 : 3));
	addItem(m_PongBall);	// Add this item to this scene
}