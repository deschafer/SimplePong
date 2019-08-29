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
//
//
//
void Game::Initialize()
{
	m_View = new QGraphicsView;
	m_StartScene = new StartScene;
	m_GameScene = new GameScene;

	// Setting up the view
	m_View->setScene(m_GameScene);	// Add the current scene to the view
	m_View->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);	// Disable all scrolling
	m_View->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);		// ..
	m_View->setFixedSize(WndWidth, WndHeight);	// Set the view size
	m_View->setSceneRect(0, 0, WndWidth, WndHeight);

	m_View->show();
}