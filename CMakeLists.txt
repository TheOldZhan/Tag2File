cmake_minimum_required(VERSION 3.16)
project(Design VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} OPTIONAL_COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(Design WIN32 MACOSX_BUNDLE
        fileTools.cpp fileTools.h
        main.cpp
        mainwindow.cpp mainwindow.h mainwindow.ui
)
target_link_libraries(Design PRIVATE
        Qt::Core
        Qt::Gui
)

if ((QT_VERSION_MAJOR GREATER 4))
    target_link_libraries(Design PRIVATE
            Qt::Widgets
    )
endif ()

install(TARGETS Design
        BUNDLE DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
        TARGET Design
        FILENAME_VARIABLE deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

add_executable(main main.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)