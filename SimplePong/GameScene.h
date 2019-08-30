#pragma once
#include <qgraphicsscene.h>
#include <qtimer.h>
#include <qlabel.h>
#include <qdebug.h>


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

	Ball* m_PongBall;	
	PlayerPaddle* m_PlayerPaddle;
	ComputerPaddle* m_ComputerPaddle;
	QLabel* m_TopScoreLabel;
	int m_TopScore;
	QLabel* m_BottomScoreLabel;
	int m_BottomScore;
	QGraphicsRectItem m_DividingLine;
	Difficulty m_Difficulty;

	void SetScene();
public:

	Ball* GetGameBall() { return m_PongBall; }

	GameScene();
	virtual ~GameScene();

	void AddTopScore() { 
		m_TopScore++;
		QString TopScore = std::to_string(m_TopScore).c_str();
		m_TopScoreLabel->setText(TopScore);
	}
	void AddBottomScore() { 
		m_BottomScore++; 
		QString BottomScore = std::to_string(m_BottomScore).c_str();
		m_BottomScoreLabel->setText(BottomScore);
	}
	void SetDifficulty(Difficulty Diff) { m_Difficulty = Diff; }
	void Initialize();

public slots:
	void ResetBall();

};

