// 
// Damon Schafer
// 8/27/2019
//

#include "Paddle.h"
#include "Game.h"

#include <QKeyEvent>


Paddle::Paddle()
{
}

//
//
//
//
Paddle::Paddle(QRect Rect) :
	m_LeftRect(PaddleRectPart::Left, QRect(Rect.topLeft().rx(), Rect.topLeft().ry(), ceil(Rect.width() / 3), Rect.height())),
	m_MiddleRect(PaddleRectPart::Middle, QRect(Rect.topLeft().rx() + Rect.width() / 3, Rect.topLeft().ry(), ceil(Rect.width() / 3), Rect.height())),
	m_RightRect(PaddleRectPart::Right, QRect(Rect.topLeft().rx() + 2*Rect.width() / 3, Rect.topLeft().ry(), ceil(Rect.width() / 3), Rect.height())),
	m_MovingLeft(false),
	m_MovingRight(false)
{
	setFlag(QGraphicsItem::ItemIsFocusable);

	// connecting slot and signal
	m_UpdateTimer = new QTimer();
	connect(m_UpdateTimer, SIGNAL(timeout()), this, SLOT(Update()));
	m_UpdateTimer->start(10);

	// Set the reflection angles for each of the respective paddle parts
	m_LeftRect.SetReflectionAngle(QVector2D(-0.5, 0));
	m_MiddleRect.SetReflectionAngle(QVector2D(0, 0));
	m_RightRect.SetReflectionAngle(QVector2D(0.5, 0));

	m_LeftRect.SetParentPaddle(this);
	m_MiddleRect.SetParentPaddle(this);
	m_RightRect.SetParentPaddle(this);
}

Paddle::~Paddle()
{
}

//
// AddItemsToScene()
// Adds all of the paddle parts to the screen so they can 
// be seen
//
void Paddle::AddItemsToScene(QGraphicsScene* Scene)
{
	Scene->addItem(&m_LeftRect);
	Scene->addItem(&m_MiddleRect);
	Scene->addItem(&m_RightRect);
}
