cmake_minimum_required(VERSION 3.10)
project(irrational-synth-software )
include(ExternalProject)
set(CMAKE_CXX_STANDARD 17)



option(CompilePi "CompilePi" OFF)




include_directories(
        irrational-synth-software
        ./libpd/* ./libpd/libpd_wrapper ./libpd/libpd_wrapper/util
        ./Backend ./Backend/PureData ./FrontEnd
        ./raylib/src
        ./raygui/src
        ./rtaudio

        )


add_subdirectory(rtaudio)
add_subdirectory(raylib)
add_executable(irrational-synth-software
        main.cpp
        Backend/AudioBackend.cpp
        Backend/PureData/PureData_AudioProcessorDevice.cpp
        Backend/PureData/PDObject.cpp
        FrontEnd/Window.cpp)
if(CompilePi)
    target_link_libraries(irrational-synth-software rtaudio -lpd -lraylib  -lbcm_host  -lbrcmGLESv2 -lbrcmEGL -lm -lpthread -ldl -lrt -lX11 -L/opt/vc/lib -L/usr/local/lib)
else()
    target_link_libraries(
            irrational-synth-software  rtaudio -lpd raylib  -lGL -lm -lpthread -ldl -lrt -lX11)
   endif()