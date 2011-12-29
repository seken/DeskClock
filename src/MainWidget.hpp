#pragma once

#include <QStackedLayout>
#include <QPushButton>

#define C_MENU 1
#define C_CLOCK 0

class MainWidget : public QWidget {
	Q_OBJECT;

	public:
		MainWidget(QWidget *parent = NULL);
		~MainWidget();
	
	private slots:
		void menuButtonPressed();
	
	private:
		QStackedLayout *m_layout;
};
