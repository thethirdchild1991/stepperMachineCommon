VPATH += $$PWD/src
DEPENDPATH += $$PWD/src
INCLUDEPATH += $$PWD/src



HEADERS += \
    $$PWD/src/cmdnames.h \
    $$PWD/src/cmdtype.h \
    $$PWD/src/cmdabstract.h \
    $$PWD/src/cmdhelper.h \
    $$PWD/src/CMDs.h \
    $$PWD/src/Configs.h \
    $$PWD/src/confighelper.h \
    $$PWD/src/confignames.h \

#    $$PWD/src/LineSearching.h \
#    $$PWD/src/amath_common.h \
#    $$PWD/src/DataStorage.hpp \
#    $$PWD/src/DataStorageDefs.h \
#    $$PWD/src/linalg.h \
#    $$PWD/src/ProfileMath.hpp \
#    $$PWD/src/Profile.h \
#    $$PWD/src/Point.hpp \
#    $$PWD/src/ArithUtil.hpp \
#    $$PWD/src/Line2d.h

SOURCES += \
        $$PWD/src/CMDs.cpp \
        $$PWD/src/Configs.cpp \
#    $$PWD/src/Rect.cpp \
#    $$PWD/src/AnMath.cpp \
#    $$PWD/src/AnMathUtil.cpp \
#    $$PWD/src/LineSearching.cpp
