include(D:/Projects/Cpp/Design/cmake-build-debug-qt_mingw/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/Design-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE D:/Projects/Cpp/Design/cmake-build-debug-qt_mingw/Design.exe
    GENERATE_QT_CONF
)
