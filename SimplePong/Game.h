//
// Damon E Schafer
// 8/27/2019
// 
// Damon Schafer
// 8/27/2019
//
#pragma once

#include <qgraphicsview.h>
#include <qobject.h>

#include "StartScene.h"
#include "GameScene.h"
#include "HelpScene.h"

enum class Difficulty { Easy, Medium, Impossible};

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
	GameScene* m_GameScene;		// Scene where the actual game of pong takes place
	StartScene* m_StartScene;	// First menu scene on game startup
	HelpScene* m_HelpScene;		// Scene with all help contents
	int m_WndWidth;				// Window dimensions
	int m_WndHeight;			// ..
	Difficulty m_GameDifficulty;// The current challenge setting

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
	void SetGameScene();
	void SetHelpScene() { m_View->setScene(m_HelpScene); }
	void SetStartScene() { m_View->setScene(m_StartScene); }
	void SetDifficulty(Difficulty Diff) { m_GameDifficulty = Diff; }
	Difficulty GetDifficulty() { return m_GameDifficulty; }

	virtual ~Game();
};

