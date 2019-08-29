#include "ComputerPaddle.h"
#include "Game.h"


ComputerPaddle::ComputerPaddle()
{
}

ComputerPaddle::ComputerPaddle(QRect Rect) : 
	Paddle(Rect)
{
}

ComputerPaddle::~ComputerPaddle()
{
}

void ComputerPaddle::Update()
{
	// Get the ball position
	Ball* GameBall = Game::Instance()->GetGameScene()->GetGameBall();
	if (!GameBall) return;
	QPointF Point = GameBall->pos();
	int TempMovement = m_PaddleMovementSpeed;

	// Then move an increment towards the ball
	if (m_MiddleRect.x() < Point.rx() && ((m_RightRect.rect().width() + m_RightRect.x()) < Game::Instance()->GetWndWidth()))
	{
		int Difference = Point.rx() - m_MiddleRect.x();
		if (Difference < m_PaddleMovementSpeed)
		{
			TempMovement = Difference;
		}

		m_LeftRect.setPos(m_LeftRect.x() + TempMovement, m_LeftRect.y());
		m_MiddleRect.setPos(m_MiddleRect.x() + TempMovement, m_MiddleRect.y());
		m_RightRect.setPos(m_RightRect.x() + TempMovement, m_RightRect.y());

	}
	// Then move an increment towards the ball
	else if (m_MiddleRect.x() > Point.rx() && (m_LeftRect.x() > 0))
	{
		int Difference = m_MiddleRect.x() - Point.rx();
		if (Difference < m_PaddleMovementSpeed)
		{
			TempMovement = Difference;
		}

		m_LeftRect.setPos(m_LeftRect.x() - TempMovement, m_LeftRect.y());
		m_MiddleRect.setPos(m_MiddleRect.x() - TempMovement, m_MiddleRect.y());
		m_RightRect.setPos(m_RightRect.x() - TempMovement, m_RightRect.y());
	}
}
