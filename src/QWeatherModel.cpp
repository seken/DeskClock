#include "QWeatherModel.hpp"
#include <QTimer>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <iostream>

QWeatherModel::QWeatherModel(const QString &location, const unsigned int &minutes, QObject *parent) : 
		QObject(parent),
		m_location(location),
		m_manager(new QNetworkAccessManager(this)) {

	QTimer *upd = new QTimer(this);
	connect(upd, SIGNAL(timeout()), this, SLOT(updateNow()));
	upd->start(minutes * 60 * 1000);

	connect(m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateFinished(QNetworkReply*)));
	updateNow();
}

QWeatherModel::~QWeatherModel() {}

void QWeatherModel::updateNow() {
	m_manager->get(QNetworkRequest(QUrl(QString("http://www.google.com/ig/api?weather=%1").arg(m_location))));
}

void QWeatherModel::updateFinished(QNetworkReply *reply) {
	QDomDocument result;
	if (result.setContent(reply)) {
		emit weatherUpdate(QWeather(result, this));
	}
	reply->deleteLater();
}
