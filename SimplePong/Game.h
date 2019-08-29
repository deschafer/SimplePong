//
// Damon E Schafer
// 8/27/2019
// 
#pragma once

#include <qgraphicsview.h>
#include <qobject.h>

#include "StartScene.h"
#include "GameScene.h"

// Main class for the game that handles scene and view management
// and storage.

// Singleton class structure as there is only one game
// and should therefore be only one instance running.
class Game
{
private:
	Game();	// Enforces singleton class

	static Game* m_Instance;	// Pointer to active class instance
	QGraphicsView* m_View;		// The main view of the application
	GameScene* m_GameScene;
	StartScene* m_StartScene;

	int m_WndWidth;
	int m_WndHeight;

public:

	static Game* Instance()		// Returns pointer to active class
	{
		if (!m_Instance)
			return (m_Instance = new Game);
		else return m_Instance;
	}

	int GetWndWidth() { return m_WndWidth; }
	int GetWndHeight() { return m_WndHeight; }
	void Initialize();

	QGraphicsView* GetView() { return m_View; }
	GameScene* GetGameScene() { return m_GameScene; }
	

	virtual ~Game();
};

