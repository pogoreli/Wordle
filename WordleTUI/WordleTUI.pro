TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        rungame.cpp

unix:!macx: LIBS += -L$$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/ -lWordleLibrary

INCLUDEPATH += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug
DEPENDPATH += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug

unix:!macx: PRE_TARGETDEPS += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/libWordleLibrary.a

HEADERS += \
    ../WordleLibrary/dictionaryuploader.h \
    ../WordleLibrary/wordlelibrary.h \
    rungame.h
