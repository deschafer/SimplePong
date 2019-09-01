// 
// Damon Schafer
// 8/27/2019
//

#pragma once

#include <qgraphicsitem.h>
#include <qobject.h>
#include <qtimer.h>
#include <qgraphicsscene.h>

#include "PaddleRect.h"

//
// The paddle consists of three PaddleRects that are the three
// parts of the paddle with their own collision properties.
// This is set up so if a ball hits the left side of the paddle
// it will bounce off the left side.
//

class Paddle : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
protected:

	QTimer* m_UpdateTimer;	// Timer that singals Update()

	PaddleRect m_LeftRect;	// Rect of the left part of this paddle
	PaddleRect m_MiddleRect;// Middle part of the paddle
	PaddleRect m_RightRect;	// Right part of the paddle

	bool m_MovingLeft;		// Flags indicating movement of the paddle
	bool m_MovingRight;

public:
	Paddle();
	Paddle(QRect Rect);

	virtual ~Paddle();

	void AddItemsToScene(QGraphicsScene* Scene);
	bool IsMoving() { return m_MovingLeft || m_MovingRight; }

public slots:
	virtual void Update() = 0;	// This will be implemented differently by each inheriting paddle
};

