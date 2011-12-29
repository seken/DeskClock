#pragma once

#include <QWidget>
#include <QPushButton>

class MenuWidget : public QWidget {
	Q_OBJECT;

	public:
		MenuWidget(QWidget *parent = NULL);
		~MenuWidget();

	private slots:
		void alarmPanel();
		void shutdown();
		void reboot();
};
