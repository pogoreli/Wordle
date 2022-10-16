QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gameover.cpp \
    incorrect.cpp \
    main.cpp \
    won.cpp \
    wordlegui.cpp

HEADERS += \
    ../WordleLibrary/wordlelibrary.h \
    gameover.h \
    incorrect.h \
    won.h \
    wordlegui.h

FORMS += \
    gameover.ui \
    incorrect.ui \
    won.ui \
    wordlegui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Release/ -lWordleLibrary

INCLUDEPATH += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Release
DEPENDPATH += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Release

unix:!macx: PRE_TARGETDEPS += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Release/libWordleLibrary.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/release/ -lWordleLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/debug/ -lWordleLibrary
else:unix: LIBS += -L$$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/ -lWordleLibrary

INCLUDEPATH += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug
DEPENDPATH += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/release/libWordleLibrary.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/debug/libWordleLibrary.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/release/WordleLibrary.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/debug/WordleLibrary.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-WordleLibrary-Desktop_Qt_5_15_2_GCC_64bit-Debug/libWordleLibrary.a
