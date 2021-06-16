NAME         = QtGSL
TARGET       = $${NAME}

QT           = core
QT          -= gui
QT          -= gui
CONFIG(static,static|shared) {
# static version does not support Qt Script now
QT          -= script
} else {
QT          += script
}
QT          += network
QT          += sql
QT          += Essentials
QT          += QtGMP

load(qt_build_config)
load(qt_module)

INCLUDEPATH += $${PWD}/../../include/$${NAME}

HEADERS     += $${PWD}/../../include/$${NAME}/qtgsl.h

include ($${PWD}/Basic/Basic.pri)
include ($${PWD}/Combination/Combination.pri)
include ($${PWD}/Linear/Linear.pri)
include ($${PWD}/Number/Number.pri)
include ($${PWD}/Precision/Precision.pri)
include ($${PWD}/Statistics/Statistics.pri)

OTHER_FILES += $${PWD}/../../include/$${NAME}/headers.pri

include ($${PWD}/../../doc/Qt/Qt.pri)

TRNAME       = $${NAME}
include ($${PWD}/../../Translations.pri)

win32 {
  CONFIG(debug,debug|release) {
    LIBS    += -lgslcblasd
    LIBS    += -lgsld
  } else {
    LIBS    += -lgslcblas
    LIBS    += -lgsl
  }
} else {
  CONFIG(debug,debug|release) {
    LIBS    += -lgslcblasd
    LIBS    += -lgsld
  } else {
    LIBS    += -lgslcblas
    LIBS    += -lgsl
  }
}
