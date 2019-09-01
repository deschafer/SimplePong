// 
// Damon Schafer
// 8/27/2019
//

#include "Ball.h"
#include "Game.h"

#include <qlist.h>
#include <qgraphicsproxywidget.h>

Ball::Ball()
{
}

//
//
//
//
Ball::Ball(int X, int Y, int Width, int Height, QVector2D Velocity) :
	QGraphicsEllipseItem(X, Y, Width, Height),
	m_Velocity(Velocity),
	m_OffTheMap(false)
{
	// Setting the position and dimensions
	setRect(0, 0, Width, Height);
	setX(X);
	setY(Y);

	// Setting up the ball slot connection
	// First create the timer for the polling
	m_BallTimer = new QTimer();
	// Connecting the slot
	connect(m_BallTimer, SIGNAL(timeout()), this, SLOT(Update()));
	m_BallTimer->start(10);

	// Setting the brush so the internal color is white
	setBrush(Qt::white);
}

Ball::~Ball()
{
	delete m_BallTimer;
	delete m_ResetTimer;
}

//
// Update()
// This is a slot function. Called periodically to check the position 
// of the ball and whether it has any pending collisions
//
void Ball::Update()
{
	// Checking if we are of the map and should return immediately
	if (m_OffTheMap) return;

	// Checking the west wall
	if (x() < 0)
	{
		// Then we flip the x velocity
		m_Velocity.setX(-m_Velocity.x());
	}
	// Checking the north wall -- will be a goal zone
	if (y() < (0 - rect().height()))
	{
		Game::Instance()->GetGameScene()->AddBottomScore();
		Reset();
	}
	// Checking the east wall
	if (x() > Game::Instance()->GetWndWidth() - rect().width())
	{
		// Then we flip the x velocity
		m_Velocity.setX(-m_Velocity.x());
	}
	// Checking the south wall -- will be a goal zone
	if (y() > Game::Instance()->GetWndHeight())
	{
		Game::Instance()->GetGameScene()->AddTopScore();
		Reset();
	}

	// Check for collisions with a paddle

	PaddleRect* CollidingPaddle;								// The paddle that has been hit
	QList<QGraphicsItem *> CollidingItems = collidingItems();	// The list of items being hit

	// Check if we have collided with the QLabel score labels
	// If we have, just remove these collisions altogether
	for (int i = 0; i < CollidingItems.size(); i++)
	{
		if (typeid(*(CollidingItems[i])) == typeid(QGraphicsProxyWidget))
		{
			CollidingItems.clear();
		}
	}

	// If we have hit more than one, just reflect in order to reset the ball
	// Handles the case if more than one part of the paddle was hit
	if (CollidingItems.size() > 1)
	{
		m_Velocity.setY(-m_Velocity.y());
	}
	else if(CollidingItems.size() == 1)
	{
		// Check if we have hit the paddle
		if (typeid(*(CollidingItems[0])) == typeid(PaddleRect))
		{
			CollidingPaddle = static_cast<PaddleRect*>(CollidingItems[0]);

			// Flip the Y component
			m_Velocity.setY(-m_Velocity.y());

			// Then set the x component based on where it was hit
			if (CollidingPaddle->GetPaddlePart() != PaddleRectPart::Middle)
			{
				m_Velocity.setX(m_Velocity.x() + CollidingPaddle->GetReflectionAngle().x());
			}

			// If the paddle is moving, move the ball as well to prevent
			// successive collisions
			if (CollidingPaddle->GetParentPaddle()->IsMoving())
			{
				if (CollidingPaddle->GetPaddlePart() == PaddleRectPart::Left)
				{
					setPos(x() - 3, y());
				}
				else if (CollidingPaddle->GetPaddlePart() == PaddleRectPart::Right)
				{
					setPos(x() + 3, y());
				}
			}
		}
	}

	//m_Velocity.normalize();
	setPos(x() + m_Velocity.x(), y() + m_Velocity.y());

	// Finally check if the ball has moved out of the field for some reason
	if (x() < -rect().width() || x() > Game::Instance()->GetWndWidth()) Reset();
}

//
// Reset()
// Signals the game to reset the ball after two seconds 
// of it leaving the screen
//
void Ball::Reset()
{
	if (!m_OffTheMap)
	{
		m_OffTheMap = true;
		m_ResetTimer = new QTimer;
		connect(m_ResetTimer, SIGNAL(timeout()), Game::Instance()->GetGameScene(), SLOT(ResetBall()));
		m_ResetTimer->start(2000);
	}
}