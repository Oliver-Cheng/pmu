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
    pmuIHM/GuessULikeWidget.cpp \
    pmuIHM/HottipsWidget.cpp \
    pmuIHM/InstitutionWidget.cpp \
    pmuIHM/PrivilegeWidget.cpp \
    pmuIHM/RegAndSignPage.cpp \
    pmuIHM/PmuHomeTabPage.cpp \
    pmuIHM/PmuMainPage.cpp \
    pmuIHM/PmuEnterPage.cpp \
    pmuIHM/SearchWidget.cpp \
    pmuIHM/LanguageWidget.cpp

HEADERS  += \
    pmuIHM/GuessULikeWidget.h \
    pmuIHM/HottipsWidget.h \
    pmuIHM/InstitutionWidget.h \
    pmuIHM/PrivilegeWidget.h \
    pmuIHM/RegAndSignPage.h \
    pmuIHM/PmuHomeTabPage.h \
    pmuIHM/PmuEnterPage.h \
    pmuIHM/PmuMainPage.h \
    pmuIHM/SearchWidget.h \
    pmuIHM/LanguageWidget.h

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

