cmake_minimum_required(VERSION 3.28)
project(projectQt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Находим необходимые компоненты Qt5
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

# Указываем пути к исходным, заголовочным файлам и файлам UI
set(SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/GameFieldLabel.cpp
        src/Attack.cpp
        src/Pass.cpp

)

set(HEADERS
        include/mainwindow.h
        include/GameFieldLabel.h
        include/Attack.h
        include/Pass.h
)

qt5_add_resources(RESOURCES resource_file.qrc)

set(UI_FILES include/mainwindow.ui)

# Генерация заголовочных файлов из .ui
qt5_wrap_ui(UI_HEADERS ${UI_FILES})

# Создание исполняемого файла
add_executable(projectQt ${SOURCES} ${HEADERS} ${UI_HEADERS} ${RESOURCES})

# Связываем с нужными библиотеками Qt5
target_link_libraries(projectQt
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
