#include "MenuWidget.hpp"
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>

MenuWidget::MenuWidget(QWidget *parent) :
		QWidget(parent) {
	QVBoxLayout *layout = new QVBoxLayout();
	setLayout(layout);

	QPushButton *alarms = new QPushButton(tr("Alarms"), this);
	alarms->setMinimumSize(64, 64);
	layout->addWidget(alarms);
	connect(alarms, SIGNAL(clicked()), this, SLOT(alarmPanel()));

	QPushButton *reboot = new QPushButton(tr("Reboot"), this);
	reboot->setMinimumSize(64, 64);
	layout->addWidget(reboot);
	connect(reboot, SIGNAL(clicked()), this, SLOT(reboot()));

	QPushButton *shutdown = new QPushButton(tr("Shutdown"), this);
	shutdown->setMinimumSize(64, 64);
	layout->addWidget(shutdown);
	connect(shutdown, SIGNAL(clicked()), this, SLOT(shutdown()));

	QPushButton *quit = new QPushButton(tr("Quit"), this);
	quit->setMinimumSize(64, 64);
	layout->addWidget(quit);
	connect(quit, SIGNAL(clicked()), QCoreApplication::instance(), SLOT(quit()));
}

MenuWidget::~MenuWidget() {}

void MenuWidget::alarmPanel() {}

void MenuWidget::shutdown() {}

void MenuWidget::reboot() {}
