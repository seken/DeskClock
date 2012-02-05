#include "QWeather.hpp"
#include <QDebug>

QWeather::QWeather(const QDomDocument &data, QObject *parent) :
		QObject(parent) {
// TODO
	QDomNodeList list = data.elementsByTagName("current_conditions");
	if (list.length() != 1) {
		qDebug() << "Couldn't parse weather.";
	}
	QDomNode curWeather = list.at(0);
	QDomNode n = curWeather.firstChild();
	while (!n.isNull()) {
		if (n.isElement()) {
			QDomElement e = n.toElement();
			if (e.tagName() == tr("condition")) {
				setCondition(e.text());
			} else if (e.tagName() == tr("temp_c")) {
				setTemperature(e.text().toDouble());
			}
		}
		n = n.nextSibling();
	}
}

QWeather::~QWeather() {}

QWeather::QWeather() :
		QObject(NULL),
		m_temp(0),
		m_hTemp(0),
		m_lTemp(0),
		m_condition() {}

QWeather::QWeather(const QWeather &other) :
		QObject(other.parent()),
		m_temp(other.temperature()),
		m_hTemp(other.highTemperature()),
		m_lTemp(other.lowTemperature()),
		m_condition(other.condition()) {}

QWeather& QWeather::operator=(const QWeather &other) {
	setTemperature(other.temperature());
	setHighTemperature(other.highTemperature());
	setLowTemperature(other.lowTemperature());
	setCondition(other.condition());
	return *this;
}

double QWeather::temperature() const {return m_temp;}

double QWeather::highTemperature() const {return m_hTemp;}

double QWeather::lowTemperature() const {return m_lTemp;}

QString QWeather::condition() const {return m_condition;}

void QWeather::setTemperature(const double &t) {m_temp = t;}

void QWeather::setHighTemperature(const double &t) {m_hTemp = t;}

void QWeather::setLowTemperature(const double &t) {m_lTemp = t;}

void QWeather::setCondition(const QString &c) {m_condition = c;}
