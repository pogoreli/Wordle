include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

SOURCES += \
        main.cpp         tst_test1.cpp

unix:!macx: LIBS += -L$$PWD/../Lab_4_5/Wordle/build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/ -lWordleLibrary

INCLUDEPATH += $$PWD/../Lab_4_5/Wordle/build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug
DEPENDPATH += $$PWD/../Lab_4_5/Wordle/build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug

unix:!macx: PRE_TARGETDEPS += $$PWD/../Lab_4_5/Wordle/build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/libWordleLibrary.a

HEADERS += \
    ../Lab_4_5/Wordle/WordleLibrary/wordlelibrary.h
