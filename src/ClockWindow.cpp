#include "ClockWindow.hpp"
#include "ClockWidget.hpp"

ClockWindow::ClockWindow(QWidget *parent, Qt::WindowFlags flags) :
		QMainWindow(parent, flags) {
	setWindowTitle(tr("Desk Clock"));
	setCentralWidget(new ClockWidget(this));
}

ClockWindow::~ClockWindow() {}
