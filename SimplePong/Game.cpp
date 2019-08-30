#include "Game.h"

Game* Game::m_Instance = nullptr;

const static int WndWidth = 500;
const static int WndHeight = 700;

Game::Game() : 
	m_WndWidth(WndWidth),
	m_WndHeight(WndHeight)
{
}

Game::~Game()
{
}

//
// Initialize()
// 
//
void Game::Initialize()
{
	// Creating our views and scenes
	m_View = new QGraphicsView;
	m_StartScene = new StartScene;
	m_GameScene = new GameScene;
	
	// Setting up the view
	m_View->setScene(m_StartScene);	// Add the current scene to the view
	m_View->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);	// Disable all scrolling
	m_View->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);		// ..
	m_View->setFixedSize(WndWidth, WndHeight);	// Set the view size
	m_View->setSceneRect(0, 0, WndWidth, WndHeight);

	// Finally showing it
	m_View->show();

	// Setting the difficulty before hand
	SetDifficulty(Difficulty::Medium);
}

//
//
//
//
void Game::SetGameScene()
{
	m_GameScene->Initialize();
	m_View->setScene(m_GameScene);
}