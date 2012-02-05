#include "MainWidget.hpp"
#include <QVBoxLayout>
#include "ClockWidget.hpp"
#include "MenuWidget.hpp"
#include <QPushButton>
#include "QWeatherModel.hpp"

MainWidget::MainWidget(QWidget *parent) :
		QWidget(parent),
		m_layout(new QStackedLayout()) {
	QVBoxLayout *layout = new QVBoxLayout();
	setLayout(layout);
	layout->addLayout(m_layout);

	QWeatherModel *wm = new QWeatherModel("filton,uk", 30, this);

	m_layout->addWidget(new ClockWidget(wm, this));
	m_layout->addWidget(new MenuWidget(this));

	QPushButton *menuButton = new QPushButton(tr("Menu"), this);
	connect(menuButton, SIGNAL(clicked()), this, SLOT(menuButtonPressed()));
	menuButton->setMinimumSize(64, 64);
	layout->addWidget(menuButton);
}

MainWidget::~MainWidget() {}

void MainWidget::menuButtonPressed() {
	const int i = m_layout->currentIndex();
	switch (i) {
		case C_MENU:
			m_layout->setCurrentIndex(C_CLOCK);
			break;
		case C_CLOCK:
		default:
			m_layout->setCurrentIndex(C_MENU);
			break;
	}
}
