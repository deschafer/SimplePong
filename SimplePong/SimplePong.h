#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SimplePong.h"

class SimplePong : public QMainWindow
{
	Q_OBJECT

public:
	SimplePong(QWidget *parent = Q_NULLPTR);

private:
	Ui::SimplePongClass ui;
};
