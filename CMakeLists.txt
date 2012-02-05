cmake_minimum_required(VERSION 2.8)

project(DeskClock)

set(QT_USE_QTNETWORK TRUE)
set(QT_USE_QTOPENGL TRUE)
set(QT_USE_QTWEBKIT TRUE)
set(QT_USE_QTDBUS TRUE)
set(QT_USE_PHONON TRUE)
set(QT_USE_QTXML TRUE)

find_package(Qt4 REQUIRED)

add_subdirectory(src bin)
