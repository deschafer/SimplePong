#pragma once
#include <qgraphicsscene.h>
#include <qlabel.h>
#include <QPushButton>

enum class Difficulty;

// 
// 
//
//

class StartScene : public QGraphicsScene
{
	Q_OBJECT
private:

	QLabel m_Name;
	QPushButton m_PlayButton;
	QPushButton m_EasyButton;
	QPushButton m_MediumButton;
	QPushButton m_HardButton;

public:
	StartScene();
	virtual ~StartScene();


	void SetDifficulty(Difficulty Diff);


public slots:

	void Play();
	void SetEasy();
	void SetMedium();
	void SetHard();


};

