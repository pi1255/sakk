cmake_minimum_required( VERSION 3.13 )

project( sakk )
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
#set(CMAKE_EXE_LINKER_FLAGS "-static")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")



find_package( SDL2 REQUIRED )


link_libraries (
  SDL2
  SDL2_ttf
)

add_library( graphics graphics.cpp )
# //include_directories(SYSTEM )
#add_subdirectory(widgets/)
#add_library(widgets widgets/widgets.cpp widgets/numberwidget.cpp widgets/dropdownwidget.cpp)




add_executable(sakk main.cpp app.cpp Figures/figure.cpp)

target_link_libraries(sakk graphics )

