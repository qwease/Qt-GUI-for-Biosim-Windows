cmake_minimum_required(VERSION 3.5)

project(biosim4Win VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(OpenCV_DIR "C:/opencv/install")
# set(OpenCV_INSTALL_PATH "C:/opencv/install")

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}
)

set(CMAKE_CXX_FLAGS "-g -Wall -fopenmp -LC:/opencv/install/x64/mingw/lib -lopencv_core490 -lopencv_video490 -lopencv_videoio490 -lpthread -lz")

# Create backup folder for original biosim4.ini
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bak)
configure_file(./biosim4.ini ${CMAKE_BINARY_DIR}/bak/biosim4.ini COPYONLY)

# Copy the configuration file to the build directory
configure_file(./biosim4.ini ${CMAKE_BINARY_DIR}/biosim4.ini COPYONLY)

# application.ini
configure_file(./application.ini ${CMAKE_BINARY_DIR}/application.ini COPYONLY)

# Copy the contents of the tools directory to the build directory
file(COPY ./tools/ DESTINATION ${CMAKE_BINARY_DIR}/tools)

# Copy the saves of generations directory to the build directory
file(COPY ./states/ DESTINATION ${CMAKE_BINARY_DIR}/states)

# Create the logs directory in the build directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/logs)

# Create the images directory in the build directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/images)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set(ZLIB_INCLUDE_DIR "C:/Program Files (x86)/GnuWin32/include")
find_package(ZLIB REQUIRED)
set(ZLIB_LIBRARY "C:/zlib-1.3.1/libz.a")
# set(ZLIB_LIBRARY "C:/Program Files (x86)/GnuWin32/lib")


message(STATUS "ZLIB_LIBRARY = ${ZLIB_LIBRARY}")
# set(ZLIB_LIBRARY "C:/zlib-1.3.1/libz.a")
# include_directories(${ZLIB_INCLUDE_DIRS})
# include_directories("C:/Program Files (x86)/GnuWin32/include")

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(biosim4Win
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        biosim4/basicTypes.h biosim4/genome-neurons.h biosim4/grid.h biosim4/imageWriter.h biosim4/indiv.h biosim4/params.h biosim4/peeps.h biosim4/random.h biosim4/sensors-actions.h biosim4/signals.h biosim4/simulator.h mainwindow.h
        biosim4/analysis.cpp biosim4/basicTypes.cpp biosim4/createBarrier.cpp biosim4/endOfGeneration.cpp biosim4/endOfSimStep.cpp biosim4/executeActions.cpp biosim4/feedForward.cpp biosim4/genome-compare.cpp biosim4/genome.cpp biosim4/getSensor.cpp biosim4/grid.cpp biosim4/imageWriter.cpp biosim4/indiv.cpp  biosim4/params.cpp biosim4/peeps.cpp biosim4/random.cpp biosim4/signals.cpp biosim4/simulator.cpp biosim4/spawnNewGeneration.cpp biosim4/survival-criteria.cpp biosim4/unitTestBasicTypes.cpp biosim4/unitTestConnectNeuralNetWiringFromGenome.cpp biosim4/unitTestGridVisitNeighborhood.cpp main.cpp mainwindow.cpp
        AgentGraphicsView.cpp biosimparser.cpp biosimrunner.cpp biosimwidget.cpp main.cpp mainwindow.cpp paramControllers.cpp
        AgentGraphicsView.h biosimparser.h biosimrunner.h biosimwidget.h mainwindow.h
        biosim4/CImg.h
        assets.qrc
        DoubleClickableGraphicsView.h

        SimulationGraphicsView.h
        SimulationGraphicsView.cpp
        NewWindowGraphicsView.h
    )

    # Find OpenCV after defining the target
    # list(APPEND CMAKE_MODULE_PATH "C:/opencv/build/x64/vc16/lib/")
    # INCLUDE_DIRECTORIES("C:/opencv/install/include")
    # set(OpenCV_INCLUDE_DIRS "C:/opencv/install/include")
    find_package(OpenCV REQUIRED)
    include_directories( ${OpenCV_INCLUDE_DIRS} )
    include_directories( "C:/opencv/install/include/x64/mingw/bin" )
    # message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
    # message(STATUS "OpenCV_LIBS = ${OpenCV_LIBS}")
    # include_directories( ${OpenCV_INCLUDE_DIRS} )

    find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia MultimediaWidgets)
    target_link_libraries(biosim4Win PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Multimedia Qt6::MultimediaWidgets)

    # Link OpenCV libraries to the target
    target_link_libraries(biosim4Win PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${OpenCV_LIBS})


    find_package(OpenMP REQUIRED)

    # Link ZLib
    target_link_libraries(biosim4Win PRIVATE ${ZLIB_LIBRARY})

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET biosim4Win APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(biosim4Win SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(biosim4Win
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(biosim4Win PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(biosim4Win PRIVATE Qt${QT_VERSION_MAJOR}::Core)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.biosim4Win)
endif()
set_target_properties(biosim4Win PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS biosim4Win
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(biosim4Win)
endif()
