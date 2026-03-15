cmake_minimum_required(VERSION 3.16)

project(Car_Dashboard VERSION 0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appCar_Dashboard
    src/main.cpp

    src/backend/include/Engine.h
    src/backend/include/CarPhysics.h
    src/backend/include/Simulator.h
    src/backend/include/DashboardController.h

    src/backend/src/Engine.cpp
    src/backend/src/CarPhysics.cpp
    src/backend/src/Simulator.cpp
    src/backend/src/DashboardController.cpp
)

target_include_directories(appCar_Dashboard PRIVATE src/backend/include)

qt_add_qml_module(appCar_Dashboard
    URI Car_Dashboard
    QML_FILES
        src/frontend/Main.qml
        src/frontend/CustomGauge.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appCar_Dashboard PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appCar_Dashboard
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCar_Dashboard
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appCar_Dashboard
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
