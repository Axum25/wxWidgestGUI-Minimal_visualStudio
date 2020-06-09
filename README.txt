Using wxWidgets 3.1.2 and Visual Studio 2019

To use wxWidgets,

create a new Win32 project,

then go to (project Properties >> C++ >> General >> "Additional Include Directories")
add

%theLocationOfwxWidgetsFolder%\include
%theLocationOfwxWidgetsFolder%\include\msvc

then go to (Linker >> General >> "Additional Include Directories")
add

%theLocationOfwxWidgetsFolder%\lib\vc_lib

