#pragma once

#include <QDomDocument>
#include <QObject>

class QWeather : public QObject {
	Q_OBJECT;
	Q_PROPERTY(double temperature READ temperature WRITE setTemperature);
	Q_PROPERTY(double high READ highTemperature WRITE setHighTemperature);
	Q_PROPERTY(double low READ lowTemperature WRITE setLowTemperature);
	Q_PROPERTY(QString condition READ condition WRITE setCondition);

	public:
		QWeather();
		QWeather(const QDomDocument &data, QObject *parent = NULL);
		QWeather(const QWeather&);
		QWeather& operator=(const QWeather&);
		~QWeather();

		double temperature() const;
		double highTemperature() const;
		double lowTemperature() const;
		QString condition() const;

	protected:
		void setTemperature(const double &t);
		void setHighTemperature(const double &t);
		void setLowTemperature(const double &t);
		void setCondition(const QString &c);

	private:
		double m_temp;
		double m_hTemp;
		double m_lTemp;
		QString m_condition;
};
