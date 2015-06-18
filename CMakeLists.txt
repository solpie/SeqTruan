#cmake_minimum_required(VERSION 3.2)
#project(SeqTruan)
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows -DWINVER=0x502 -D_WIN32_IE=0x600 -D_WIN32_WINNT=0x502 ")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=gnu++0x")
#set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} -lQt5Widgets")
#set(SOURCE_FILES main.cpp)
#set(QT_INCLUDE_DIR C:/Qt/Qt5.4.2/5.4/mingw491_32/include)
#include_directories(${QT_INCLUDE_DIR})
#
#set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -static-libgcc -static-libstdc++")
#set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} C:/Qt/Qt5.4.2/Tools/mingw491_32_merge/lib/gcc/i686-w64-mingw32/4.9.1/libstdc++.dll.a")#size 35k
#set(SOURCE_FILES main.cpp)
#add_executable(SeqTruan ${SOURCE_FILES} model/TrackModel.h model/TrackModel.cpp view/SeqTruanWin.h view/SeqTruanWin.cpp view/viewport/ViewPort.h view/viewport/ViewPort.cpp)




############
cmake_minimum_required(VERSION 2.8.11)

project(SeqTruan)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=gnu++11")
# Find the QtWidgets library
find_package(Qt5Widgets)
#set(SRC view/viewport/ViewPort.cpp)
# Tell CMake to create the helloworld executable
qt5_add_resources(RESOURCES qrc/rc.qrc)
add_executable(SeqTruan WIN32 main.cpp ${RESOURCES}
view/UI.h
events/Event.h
model/Singleton.h
model/TrackModel.cpp
view/SeqTruanWin.cpp
view/viewport/ViewPort.cpp
view/timeline/Timeline.h
view/timeline/Timeline.cpp
view/timeline/TrackToolBar.h
view/timeline/TrackToolBar.cpp
view/timeline/TrackPanelArea.cpp
view/timeline/TrackPanelArea.h
view/timeline/TrackCursor.h
view/timeline/TrackCursor.cpp
view/timeline/TrackArea.cpp view/timeline/TrackArea.h)

# Use the Widgets module from Qt 5.
target_link_libraries(SeqTruan Qt5::Widgets)

#######################