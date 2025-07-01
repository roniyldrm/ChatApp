cmake_minimum_required(VERSION 3.20)
project(ChatApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Output binary to build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Use static wxWidgets
add_definitions(-DwxUSE_UNICODE -D_UNICODE -DwxMSW -DwxUSE_GUI=1 -DwxUSE_RC_MANIFEST=1 -DwxSTATIC -D__WXMSW__)

# wxWidgets paths
set(wxWidgets_ROOT_DIR "C:/CppLibraries/wxWidgets-3.2.8")
set(wxWidgets_LIB_DIR "${wxWidgets_ROOT_DIR}/lib/gcc_lib")

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external
    "${wxWidgets_ROOT_DIR}/include"
    "${wxWidgets_LIB_DIR}/mswu"         # ✅ This is the correct path now
)

# Linker search path
link_directories("${wxWidgets_LIB_DIR}")

# Link libraries (Monolithic build)
set(WX_LIBS
    wxmsw32u
    comctl32 rpcrt4 oleacc winmm shell32 uuid oleaut32
    version uxtheme imm32 setupapi wsock32 winspool
    gdi32 user32 comdlg32 advapi32 kernel32
)

# Source files
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Build executable
add_executable(chat_app ${SRC_FILES})

# Link libraries
target_link_libraries(chat_app
    wxmsw32u
    wxpng
    wxzlib
    wxjpeg
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
    shlwapi           #Needed for PathMatchSpecW
)
