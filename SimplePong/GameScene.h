#pragma once
#include <qgraphicsscene.h>
#include <qtimer.h>
#include <qlabel.h>


#include "Ball.h"
#include "PlayerPaddle.h"
#include "ComputerPaddle.h"

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

	GameScene();
	virtual ~GameScene();

public slots:
	void ResetBall();

};

