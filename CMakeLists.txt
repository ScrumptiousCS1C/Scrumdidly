cmake_minimum_required(VERSION 3.5)

project(loginWINDOW VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        loginwindow.cpp
        loginwindow.h
        loginwindow.ui
        renderscreen.cpp
        renderscreen.h
        renderscreen.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(loginWINDOW
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        renderscreen.h renderscreen.cpp renderscreen.ui
        images/logo.qrc
        vector.h
        Ellipse.h Line.h Polygon.h Polyline.h Rectangle.h Shape.h Text.h
        shapeeditor.h shapeeditor.cpp shapeeditor.ui
        Ellispe.cpp Line.cpp loginwindow.cpp Polygon.cpp Polyline.cpp Rectangle.cpp Text.cpp
        aboutus.cpp
        aboutus.h
        aboutus.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET loginWINDOW APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(loginWINDOW SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(loginWINDOW
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(loginWINDOW PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.loginWINDOW)
endif()
set_target_properties(loginWINDOW PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS loginWINDOW
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(loginWINDOW)
endif()
