QT += quick

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Company/companycomponent.cpp \
        Company/companyhandler.cpp \
        Company/companylist.cpp \
        Company/companymodel.cpp \
        Login/logincomponent.cpp \
        Login/loginhandler.cpp \
        HourRegistration/hourregistrationcomponent.cpp \
        HourRegistration/hourregistrationhandler.cpp \
        HourRegistration/hourregistrationlist.cpp \
        HourRegistration/hourregistrationmodel.cpp \
        Projects/projectcomponent.cpp \
        Projects/projecthandler.cpp \
        Projects/projectlist.cpp \
        Projects/projectmodel.cpp \
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
    Company/companycomponent.h \
    Company/companyhandler.h \
    Company/companylist.h \
    Company/companymodel.h \
    Login/logincomponent.h \
    Login/loginhandler.h \
    HourRegistration/hourregistrationcomponent.h \
    HourRegistration/hourregistrationhandler.h \
    HourRegistration/hourregistrationlist.h \
    HourRegistration/hourregistrationmodel.h \
    Projects/projectcomponent.h \
    Projects/projecthandler.h \
    Projects/projectlist.h \
    Projects/projectmodel.h \
    Structs/CompanyStruct.h \
    Structs/HourRegistrationStruct.h \
    Structs/LoginStruct.h \
    Structs/ProjectStruct.h \
    Structs/UserStruct.h
