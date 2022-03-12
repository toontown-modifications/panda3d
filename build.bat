@echo off
title - Panda3D Builder
color 2
:main
makepanda\makepanda.bat --everything --installer --msvc-version=14.3 --windows-sdk=10 --no-eigen --threads=4
echo Done!
pause
goto :main