#include "ClockWindow.hpp"
#include "MainWidget.hpp"

ClockWindow::ClockWindow(QWidget *parent, Qt::WindowFlags flags) :
		QMainWindow(parent, flags) {
	setWindowTitle(tr("Desk Clock"));
	setCentralWidget(new MainWidget(this));
}

ClockWindow::~ClockWindow() {}
