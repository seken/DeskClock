#pragma once

#include <QObject>
#include <QXmlSimpleReader>
#include <QNetworkAccessManager>
#include "QWeather.hpp"

class QWeatherModel : public QObject {
	Q_OBJECT;

	public:
		QWeatherModel(const QString &location, const unsigned int &minutes = 30, QObject *parent = NULL);
		~QWeatherModel();

	signals:
		void weatherUpdate(QWeather weather);

	public slots:
		void updateNow();
		void updateFinished(QNetworkReply* reply);

	private:
		const QString m_location;
		QNetworkAccessManager *m_manager;
};
