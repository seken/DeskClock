set(DeskClock_SRCS
	main.cpp
	ClockWindow.cpp
	ClockWidget.cpp
	MainWidget.cpp
	MenuWidget.cpp
	QWeatherModel.cpp
	QWeather.cpp
)

set(DeskClock_HDRS
	ClockWindow.hpp
	ClockWidget.hpp
	MainWidget.hpp
	MenuWidget.hpp
	QWeather.hpp
	QWeatherModel.hpp
)

qt4_wrap_cpp(DeskClock_HDRS_MOC ${DeskClock_HDRS})

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

add_executable(DeskClock ${DeskClock_SRCS} ${DeskClock_HDRS_MOC})
target_link_libraries(DeskClock ${QT_LIBRARIES})
