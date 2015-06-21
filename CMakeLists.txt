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




############
cmake_minimum_required(VERSION 2.8.11)

project(SeqTruan)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11 -fpermissive")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -s -std=c++11 -fpermissive")
# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5OpenGL)
#find_package(OpenGL)
find_package(Qt5Multimedia REQUIRED)
# Tell CMake to create the helloworld executable
qt5_add_resources(RESOURCES qrc/rc.qrc)
add_executable(SeqTruan WIN32 main.cpp ${RESOURCES}
events/Event.hpp
events/TrackModelEvent.hpp
events/ActionEvent.hpp
events/PlaybackEvent.hpp
utils/Singleton.hpp
model/TrackModel.hpp
model/App.hpp
utils/Linker.hpp
view/UI.hpp
view/Theme.hpp
view/OverWidget.hpp
view/SeqTruanWin.hpp
view/viewport/ViewPort.hpp
view/timeline/Timeline.hpp
view/timeline/trackPanel/TrackToolBar.hpp
view/timeline/trackPanel/TrackPanelArea.hpp
view/timeline/trackPanel/TrackPanel.hpp
view/timeline/FrameCursor.hpp
view/timeline/TrackArea.hpp
view/timeline/TimestampBar.hpp
view/timeline/Track.hpp
view/timeline/TimelineToolBar.hpp
view/viewport/Transport.hpp
view/timeline/TrackFrame.hpp
model/playback/SequencePlayback.hpp
model/playback/AudioPlayback.hpp
events/SequencePlaybackEvent.hpp
model/TrackInfo.hpp
model/TrackFrameInfo.hpp
view/viewport/ComCanvas.hpp
utils/Sh1tMacro.hpp)

# Use the Widgets module from Qt 5.
target_link_libraries(SeqTruan Qt5::Widgets Qt5::OpenGL Qt5::Multimedia ${OPENGL_LIBRARIES})
#target_link_libraries(SeqTruan Qt5::Widgets Qt5::OpenGL Qt5::Multimedia ${OPENGL_LIBRARIES})

#######################