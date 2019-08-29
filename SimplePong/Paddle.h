#pragma once

#include <qgraphicsitem.h>
#include <qobject.h>
#include <qtimer.h>
#include <qgraphicsscene.h>

#include "PaddleRect.h"

class Paddle : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
protected:

	QTimer* m_UpdateTimer;

	PaddleRect m_LeftRect;
	PaddleRect m_MiddleRect;
	PaddleRect m_RightRect;

	bool m_MovingLeft;
	bool m_MovingRight;

public:
	Paddle();
	Paddle(QRect Rect);

	virtual ~Paddle();

	void AddItemsToScene(QGraphicsScene* Scene);
	bool IsMoving() { return m_MovingLeft || m_MovingRight; }

public slots:
	virtual void Update() = 0;
	
};

