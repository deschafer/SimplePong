#include "PaddleRect.h"

#include <qbrush.h>
#include <qpen.h>

PaddleRect::PaddleRect()
{
}

PaddleRect::PaddleRect(PaddleRectPart Part, QRect Rect) :
	m_Part(Part)
{
	QPen Pen;

	setRect(0, 0, Rect.width(), Rect.height());
	setX(Rect.x());
	setY(Rect.y());

	setBrush(Qt::white);
	Pen.setColor(QColor(Qt::white));
	setPen(Pen);
}


PaddleRect::~PaddleRect()
{
}
