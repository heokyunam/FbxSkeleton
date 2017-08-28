cmake_minimum_required(VERSION 2.8)
project( GP )

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")

set(SOURCES
  src/FBXLoader.cpp
  src/main.cpp
  src/targa.cxx
  src/FBXSkeleton.cpp
)

set(TEST
  src/FBXLoader.cpp
  src/test.cpp
  src/targa.cxx
  src/FBXSkeleton.cpp
)

find_package( OpenCV REQUIRED )

include_directories( ${CMAKE_INCLUDE_PATH} )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( "../fbxsdk/include" )
include_directories( "include/" )
LIST( APPEND LIBRARIES ${OpenCV_LIBS} )

find_package( PkgConfig REQUIRED )
find_package( GLFW3 REQUIRED )
find_package( OpenGL REQUIRED )

include_directories( ${GLFW3_INCLUDE_DIRS} )

LIST( APPEND LIBRARIES ${GLFW3_LIBRARIES} )
LIST( APPEND LIBRARIES ${OPENGL_gl_LIBRARY} )
LIST( APPEND LIBRARIES "~/GP/fbxsdk/libfbxsdk.so" )

find_package( OpenNI2 REQUIRED )
find_package( Openni-nite REQUIRED )

find_package( GLUT REQUIRED )
LIST( APPEND LIBRARIES ${GLUT_glut_LIBRARY} )
LIST( APPEND LIBRARIES "/usr/lib/x86_64-linux-gnu/libGLU.so.1.3.1" )
LIST( APPEND LIBRARIES "/usr/lib/x86_64-linux-gnu/libGLEW.so.1.13.0" )

add_definitions(-DEXAMPLES_WITH_OPENGL_SUPPORT=1)

add_executable( Result ${SOURCES} )
target_link_libraries( Result ${LIBRARIES} ) 

add_executable( Test ${TEST} )
target_link_libraries( Test ${LIBRARIES} ) 