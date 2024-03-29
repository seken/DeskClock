#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "QWeatherModel.hpp"

class ClockWidget : public QWidget {
	Q_OBJECT;

	public:
		ClockWidget(QWeatherModel *mdl, QWidget *parent = NULL);
		~ClockWidget();

	private slots:
		void update();
	
	private:
		QLabel *m_time;
		QLabel *m_date;
		QTimer m_timer;
};
