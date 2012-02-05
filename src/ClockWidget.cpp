#include "ClockWidget.hpp"
#include <QGridLayout>
#include <QDateTime>

ClockWidget::ClockWidget(QWeatherModel *mdl, QWidget *parent) :
		QWidget(parent),
		m_time(new QLabel(tr("time"), this)),
		m_date(new QLabel(tr("date"), this)),
		m_timer(this) {
	QGridLayout *layout = new QGridLayout();
	setLayout(layout);
	m_time->setAlignment(Qt::AlignHCenter);
	m_time->setStyleSheet("QLabel{font-size:105pt;}");
	layout->addWidget(m_time, 1, 0, 1, 4);
	layout->addWidget(m_date, 0, 3);
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(update()));
	update();
	m_timer.start(2500);
}

ClockWidget::~ClockWidget() {}

void ClockWidget::update() {
	QDateTime time = QDateTime::currentDateTime();
	m_time->setText(time.toString("h:mm ap"));
	m_date->setText(time.toString("ddd MMMM d yyyy"));
}
