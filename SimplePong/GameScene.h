// 
// Damon Schafer
// 8/27/2019
//

#pragma once
#include <qgraphicsscene.h>
#include <qtimer.h>
#include <qlabel.h>
#include <qdebug.h>
#include <qgraphicsproxywidget.h>


#include "Ball.h"
#include "PlayerPaddle.h"
#include "ComputerPaddle.h"

#include <qdebug.h>
#include <qlabel.h>

enum class Difficulty;

//
// The game scene that contains all of the essential game objects and data
// and manages the game itself.
//

class GameScene : public QGraphicsScene
{
	Q_OBJECT // all QObjects need this here
private:

	Ball* m_PongBall;					// The game ball
	PlayerPaddle* m_PlayerPaddle;		// The player paddle (bottom)
	ComputerPaddle* m_ComputerPaddle;	// The computer paddle (top)
	QLabel* m_TopScoreLabel;			// QLabel for top players score
	int m_TopScore;						// Top players score
	QLabel* m_BottomScoreLabel;			// QLabel for the bottom players score
	int m_BottomScore;					// Bottom players score
	QGraphicsRectItem m_DividingLine;	// Rect acting as a single line dividing the screen
	Difficulty m_Difficulty;			// Current set difficulty
	QLabel* m_WinLabel;					// QLabel for the win message
	bool m_Win;							// Flag indicating win status
	QGraphicsProxyWidget* m_Widget;		// Ptr used to remove the wind message from the scene
	QTimer *m_WinTimer;					// Timer used to remove the win message after a while

	void SetScene();
	void Win();
public:

	Ball* GetGameBall() { return m_PongBall; }

	GameScene();
	virtual ~GameScene();

	void AddTopScore() { 
		m_TopScore++;
		QString TopScore = std::to_string(m_TopScore).c_str();
		m_TopScoreLabel->setText(TopScore);
		if (m_TopScore == 10) Win();
	}
	void AddBottomScore() { 
		m_BottomScore++; 
		QString BottomScore = std::to_string(m_BottomScore).c_str();
		m_BottomScoreLabel->setText(BottomScore);
		if (m_BottomScore == 10) Win();
	}
	void SetDifficulty(Difficulty Diff) { m_Difficulty = Diff; }
	void Initialize();

public slots:
	void ResetBall();
	void ResetWin();

};

