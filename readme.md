run the configuration command again if you do one of these things:
    Add a brand new .cpp file to your project.
    Delete a .cpp file.
    Change the CMakeLists.txt file itself.
    
terminal:
    cmake -S . -B build -G "MinGW Makefiles"
    cmake --build build

-----
if no file was deleted created 
terminal:
    cmake --build build