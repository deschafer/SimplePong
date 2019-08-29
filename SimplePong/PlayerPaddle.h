#pragma once
#include "Paddle.h"


class PlayerPaddle : public Paddle
{
	Q_OBJECT
public:
	PlayerPaddle();
	PlayerPaddle(QRect Rect);
	virtual ~PlayerPaddle();

	void keyPressEvent(QKeyEvent* Event);
	void keyReleaseEvent(QKeyEvent* Event);

public slots:
	virtual void Update();
};

