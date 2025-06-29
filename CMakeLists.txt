cmake_minimum_required(VERSION 3.20)
project(ChatApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output binary to build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Enable static wxWidgets
add_definitions(-DwxUSE_UNICODE -D_UNICODE -DwxMSW -DwxUSE_GUI=1 -DwxUSE_RC_MANIFEST=1 -DwxSTATIC)

# Path to wxWidgets
set(wxWidgets_ROOT_DIR "C:/C++ Libraries/wxWidgets")
set(wxWidgets_LIB_DIR "${wxWidgets_ROOT_DIR}/lib/vc_lib")

# Include folders
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external            # for <asio/asio.hpp>
    "${wxWidgets_ROOT_DIR}/include"
    "${wxWidgets_ROOT_DIR}/include/msvc"
)

# Linker path
link_directories("${wxWidgets_LIB_DIR}")

# Static wxWidgets libs
set(WX_LIBS
    wxbase32u
    wxmsw32u_core
    wxpng
    wxjpeg
    wxzlib
    wxregexu
    wxexpat
    comctl32
    rpcrt4
    oleacc
    winmm
    shell32
    uuid
    oleaut32
    version
    uxtheme
    imm32
    setupapi
    wsock32
    winspool
    gdi32
    user32
    comdlg32
    advapi32
    kernel32
)

# Source files
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Build executable
add_executable(chat_app ${SRC_FILES})

# Link libraries
target_link_libraries(chat_app PRIVATE ${WX_LIBS})
