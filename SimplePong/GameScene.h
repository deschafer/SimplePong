#pragma once
#include <qgraphicsscene.h>
#include <qtimer.h>
#include <qlabel.h>
#include <qdebug.h>


#include "Ball.h"
#include "PlayerPaddle.h"
#include "ComputerPaddle.h"

#include <qdebug.h>


//
//
//
//

class GameScene : public QGraphicsScene
{
	Q_OBJECT
private:

	Ball* m_PongBall;	
	PlayerPaddle* m_PlayerPaddle;
	ComputerPaddle* m_ComputerPaddle;
	QLabel* m_TopScore;
	QLabel* m_BottomScore;
	QGraphicsRectItem m_DividingLine;

	void SetScene();
public:

	Ball* GetGameBall() { return m_PongBall; }

	GameScene();
	virtual ~GameScene();

	void AddTopScore() { 
		qDebug("Top Score Added");
		m_TopScore++; 
	}
	void AddBottomScore() { 
		qDebug("Bottom Score Added");
		m_TopScore++; 
	}

public slots:
	void ResetBall();

};

