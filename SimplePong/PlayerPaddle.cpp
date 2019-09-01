// 
// Damon Schafer
// 8/27/2019
//

#include "PlayerPaddle.h"
#include "Game.h"

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
// keyPressEvent()
// Overriden function that handles the keypresses
// to move the paddle accordingly
// We mark when we have pressed a key, and keep movement until
// it is released
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
// keyReleaseEvent()
// Stop movement when the key is released.
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

//
// Update()
// Called by a qtimer signal to constantly 
// set the position of the paddle based off the
// last recorded key events
//
void PlayerPaddle::Update()
{
	// Make sure this is always in focus
	setFocus();

	if (m_MovingLeft && (m_LeftRect.x() > 0))
	{
		m_LeftRect.setPos(m_LeftRect.x() - PaddleSpeed, m_LeftRect.y());
		m_MiddleRect.setPos(m_MiddleRect.x() - PaddleSpeed, m_MiddleRect.y());
		m_RightRect.setPos(m_RightRect.x() - PaddleSpeed, m_RightRect.y());
	}
	else if (m_MovingRight && ((m_RightRect.rect().width() + m_RightRect.x()) < Game::Instance()->GetWndWidth()))
	{
		m_LeftRect.setPos(m_LeftRect.x() + PaddleSpeed, m_LeftRect.y());
		m_MiddleRect.setPos(m_MiddleRect.x() + PaddleSpeed, m_MiddleRect.y());
		m_RightRect.setPos(m_RightRect.x() + PaddleSpeed, m_RightRect.y());
	}
}
