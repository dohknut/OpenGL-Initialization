@echo off

SET CompilerFlags=-Od -GR- -EHa- -FC -Zi -MT -W4 -WX -nologo -DOPENGL_INITIALIZATION_DEV=1 -wd4100 -wd4127 -wd4189 -wd4334 -wd4505
SET LinkerFlags=Opengl32.lib User32.lib Gdi32.lib Winmm.lib Kernel32.lib

IF NOT EXIST ..\..\.build\opengl_initialization MKDIR ..\..\..\.build\opengl_initialization
PUSHD ..\..\..\.build\opengl_initialization

cl %CompilerFlags% ..\..\projects\OpenGL-Initialization\code\opengl_initialization.cpp -Fmwin32_opengl_initialization.map /link %LinkerFlags% 
POPD
