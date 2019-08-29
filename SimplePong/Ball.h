#pragma once
#include <qobject.h>
#include <qgraphicsitem.h>
#include <qvector2d.h>
#include <qtimer.h>



class Ball : public QObject, public QGraphicsEllipseItem
{
	Q_OBJECT

private:

	QVector2D m_Velocity;	// The current ball velocity and direction
	QTimer* m_BallTimer;
	QTimer* m_ResetTimer;
	bool m_OffTheMap;

public:
	Ball();
	Ball(int X, int Y, int W, int H, QVector2D Velocity);

	void Reset();
	virtual ~Ball();

public slots:

	void Update();
};

