#-------------------------------------------------
#
# Project created by QtCreator 2015-11-08T08:30:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pmu
TEMPLATE = app

INCLUDEPATH += pmuIHM

SOURCES += main.cpp\
           pmuIHM/pmuEnterPage.cpp \
    pmuIHM/pmuMainPage.cpp \
    pmuIHM/GuessULikeWidget.cpp \
    pmuIHM/HottipsWidget.cpp \
    pmuIHM/InstitutionWidget.cpp \
    pmuIHM/PrivilegeWidget.cpp

HEADERS  += pmuIHM/pmuEnterPage.h \
    pmuIHM/pmuMainPage.h \
    pmuIHM/GuessULikeWidget.h \
    pmuIHM/HottipsWidget.h \
    pmuIHM/InstitutionWidget.h \
    pmuIHM/PrivilegeWidget.h

RESOURCES += \
    imageresources.qrc

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

