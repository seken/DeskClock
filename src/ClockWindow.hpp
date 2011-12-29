#pragma once
#include <QMainWindow>

class ClockWindow : public QMainWindow {
	Q_OBJECT;

	public:
		ClockWindow(QWidget *parent = NULL, Qt::WindowFlags flags = 0);
		~ClockWindow();
};
