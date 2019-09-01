// 
// Damon Schafer
// 8/27/2019
//

#pragma once
#include <qobject.h>
#include <qgraphicsitem.h>
#include <qvector2d.h>
#include <qtimer.h>

//
// The class for the game ball
//

class Ball : public QObject, public QGraphicsEllipseItem
{
	Q_OBJECT

private:

	QVector2D m_Velocity;	// The current ball velocity and direction
	QTimer* m_BallTimer;	// Timer for the ball update cycle
	QTimer* m_ResetTimer;	// Timer for the ball reset cycle
	bool m_OffTheMap;		// Flag that checks if the ball is off the map
	bool m_PaddleHit;		// Flag indicating if last object hit was a paddle

public:
	Ball();
	Ball(int X, int Y, int W, int H, QVector2D Velocity);

	void Reset();
	virtual ~Ball();

public slots:

	void Update();
};

