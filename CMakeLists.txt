cmake_minimum_required(VERSION 3.16.0)
project(cluster VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(INSTALL_DIRECTORY "/opt/apps")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

if (CMAKE_CROSSCOMPILING)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(CLUSTERAPI REQUIRED cluster-api-systemd)
endif()

set(SOURCES
    Application/main.cpp
    Application/cluster-service.cpp
    Application/cluster-service.hxx
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt6 COMPONENTS ShaderTools)

    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${SOURCES}
        GUIModel/GUIModel.qrc
        Assets/Common/3DModelData.qrc
        Assets/Common/3DModelTexture.qrc
        Assets/Common/Fonts.qrc
        Assets/Common/Images.qrc
        Assets/Common/Shaders.qrc
        GUIModel/MeterEffect/Effect.qrc
    )
    qt6_add_shaders(${PROJECT_NAME} "${PROJECT_NAME}"
        PREFIX
            "/"
        FILES
            "Assets/Common/Shaders/Qt6/guageMask.frag"
            "Assets/Common/Shaders/Qt6/guageMask.vert"
    )
else()
    qt5_add_resources(RESOURCES
        GUIModel/GUIModel.qrc
        Assets/Common/3DModelData.qrc
        Assets/Common/3DModelTexture.qrc
        Assets/Common/Fonts.qrc
        Assets/Common/Images.qrc
        Assets/Common/Shaders.qrc
        GUIModel/MeterEffect/Qt5/Effect.qrc
    )

    add_executable(
        ${PROJECT_NAME}
        ${SOURCES}
        ${RESOURCES}
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Gui
    ${CLUSTERAPI_LIBRARIES}
)

if(CMAKE_CROSSCOMPILING)
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        ENABLE_CLUSTER_BACKEND=1 CROSSCOMPILING=1
    )
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        ENABLE_CLUSTER_BACKEND=0
    )
endif()

link_directories( ${CLUSTERAPI_LIBRARY_DIRS} )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CLUSTERAPI_CXX_FLAGS} ${CLUSTERAPI_C_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CLUSTERAPI_C_FLAGS}")

if(NOT DEFINED APPS_INST_DIR)
    set(APPS_INST_DIR /opt/apps)
endif()

file(GLOB VIDEOS ${CMAKE_CURRENT_SOURCE_DIR}/Assets/Common/Videos/*)
install(FILES ${VIDEOS} DESTINATION ${APPS_INST_DIR})
install(TARGETS ${PROJECT_NAME} DESTINATION ${APPS_INST_DIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(${PROJECT_NAME})
    qt_finalize_executable(${PROJECT_NAME})
endif()
