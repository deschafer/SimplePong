// 
// Damon Schafer
// 8/27/2019
//

#pragma once
#include "Paddle.h"

class ComputerPaddle : public Paddle
{
	Q_OBJECT

private:
	int m_PaddleMovementSpeed;	// Speed of the paddle

public:
	ComputerPaddle();
	ComputerPaddle(QRect Rect);

	virtual ~ComputerPaddle();

	void SetPaddleMovementSpeed(int Speed) { m_PaddleMovementSpeed = Speed; }

public slots:

	void Update();
};

