#include <QApplication>
#include <QDesktopWidget>
#include "ClockWindow.hpp"

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	ClockWindow window;

	app.setApplicationName("DeskClock");
	app.setApplicationVersion("1.0");
	app.setOrganizationDomain("http://seken.co.uk");
	app.setOrganizationName("Markit");

	if (QApplication::desktop()->width() <= 1024) {
		window.showFullScreen();
	} else {
		window.resize(1024, 600);
		window.show();
	}

	return app.exec();
}
