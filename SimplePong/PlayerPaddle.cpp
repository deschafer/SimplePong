#include "PlayerPaddle.h"

#include <qevent.h>

const static int PaddleSpeed = 2;


PlayerPaddle::PlayerPaddle()
{
}

PlayerPaddle::~PlayerPaddle()
{
}

PlayerPaddle::PlayerPaddle(QRect Rect) : 
	Paddle(Rect)
{
}

//
//
//
//
void PlayerPaddle::keyPressEvent(QKeyEvent* Event)
{
	if (Event->key() == Qt::Key_Left)
	{
		m_MovingLeft = true;
	}
	if (Event->key() == Qt::Key_Right)
	{
		m_MovingRight = true;
	}
}

//
//
//
//
void PlayerPaddle::keyReleaseEvent(QKeyEvent* Event)
{
	if (Event->key() == Qt::Key_Left)
	{
		m_MovingLeft = false;
	}
	if (Event->key() == Qt::Key_Right)
	{
		m_MovingRight = false;
	}
}

void PlayerPaddle::Update()
{
	// Make sure this is always in focus
	setFocus();

	if (m_MovingLeft)
	{
		m_LeftRect.setPos(m_LeftRect.x() - PaddleSpeed, m_LeftRect.y());
		m_MiddleRect.setPos(m_MiddleRect.x() - PaddleSpeed, m_MiddleRect.y());
		m_RightRect.setPos(m_RightRect.x() - PaddleSpeed, m_RightRect.y());
	}
	else if (m_MovingRight)
	{
		m_LeftRect.setPos(m_LeftRect.x() + PaddleSpeed, m_LeftRect.y());
		m_MiddleRect.setPos(m_MiddleRect.x() + PaddleSpeed, m_MiddleRect.y());
		m_RightRect.setPos(m_RightRect.x() + PaddleSpeed, m_RightRect.y());
	}
}
