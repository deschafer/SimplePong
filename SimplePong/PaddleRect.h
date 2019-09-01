// 
// Damon Schafer
// 8/27/2019
//

#pragma once
#include <qgraphicsitem.h>
#include <qvector2d.h>

enum class PaddleRectPart{Left, Middle, Right};

class Paddle; // Forward declaration

class PaddleRect : public QGraphicsRectItem
{
private:

	PaddleRectPart m_Part;		// Tells which part this paddle is
	QVector2D m_ReflectionAngle;// Angle that will affect the collisions of this object
	Paddle* m_ParentPaddle;		// The paddle object

public:
	PaddleRect();
	PaddleRect(PaddleRectPart Part, QRect Rect);
		
	PaddleRectPart GetPaddlePart() { return m_Part; }
	void SetReflectionAngle(QVector2D Reflection) { m_ReflectionAngle = Reflection; }
	QVector2D GetReflectionAngle() { return m_ReflectionAngle; }
	void SetParentPaddle(Paddle* paddle) { m_ParentPaddle = paddle; }
	Paddle* GetParentPaddle() { return m_ParentPaddle; }

	virtual ~PaddleRect();
};

