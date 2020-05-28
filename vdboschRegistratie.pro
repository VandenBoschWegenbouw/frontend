QT += quick widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# QXlsx code for Application Qt project
QXLSX_PARENTPATH=./         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=./header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=./source/  # current QXlsx source path is ./source/
include(./QXlsx.pri)

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        AmountType/amounttypecomponent.cpp \
        AmountType/amounttypehandler.cpp \
        AmountType/amounttypelist.cpp \
        AmountType/amounttypemodel.cpp \
        Company/companycomponent.cpp \
        Company/companyhandler.cpp \
        Company/companylist.cpp \
        Company/companymodel.cpp \
        HourRegistration/hourregistrationmodel.cpp \
        Login/logincomponent.cpp \
        Login/loginhandler.cpp \
        HourRegistration/hourregistrationcomponent.cpp \
        HourRegistration/hourregistrationhandler.cpp \
        HourRegistration/hourregistrationlist.cpp \
        PartType/parttypecomponent.cpp \
        PartType/parttypehandler.cpp \
        PartType/parttypelist.cpp \
        PartType/parttypemodel.cpp \
        Projects/Export/exportcomponent.cpp \
        Projects/projectcomponent.cpp \
        Projects/projecthandler.cpp \
        Projects/projectlist.cpp \
        Projects/projectmodel.cpp \
        UsedParts/usedpartscomponent.cpp \
        UsedParts/usedpartshandler.cpp \
        UsedParts/usedpartslist.cpp \
        UsedParts/usedpartsmodel.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml \
    images/Logo.png

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

HEADERS += \
    AmountType/amounttypecomponent.h \
    AmountType/amounttypehandler.h \
    AmountType/amounttypelist.h \
    AmountType/amounttypemodel.h \
    Company/companycomponent.h \
    Company/companyhandler.h \
    Company/companylist.h \
    Company/companymodel.h \
    HourRegistration/hourregistrationmodel.h \
    Login/logincomponent.h \
    Login/loginhandler.h \
    HourRegistration/hourregistrationcomponent.h \
    HourRegistration/hourregistrationhandler.h \
    HourRegistration/hourregistrationlist.h \
    PartType/parttypecomponent.h \
    PartType/parttypehandler.h \
    PartType/parttypelist.h \
    PartType/parttypemodel.h \
    Projects/Export/exportcomponent.h \
    Projects/projectcomponent.h \
    Projects/projecthandler.h \
    Projects/projectlist.h \
    Projects/projectmodel.h \
    Structs/AmountTypeStruct.h \
    Structs/CompanyStruct.h \
    Structs/HourRegistrationStruct.h \
    Structs/LoginStruct.h \
    Structs/PartTypeStruct.h \
    Structs/ProjectStruct.h \
    Structs/UsedPartsStruct.h \
    Structs/UserStruct.h \
    UsedParts/usedpartscomponent.h \
    UsedParts/usedpartshandler.h \
    UsedParts/usedpartslist.h \
    UsedParts/usedpartsmodel.h
