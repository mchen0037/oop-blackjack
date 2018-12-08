FREEGLUTAPP
-----------

This is a demo project to start implementing OpenGL applications
using freeglut. 

Linux:
 - Type make to compile the application
 - The makefile will compile all .cpp files in the folder
 - Edit the makefile to change the name of the executable

Windows:
 - Visual Studio 2015 is required 
 - Simply open the solution (glutapp.sln) in visualc15
 
macOS:
 - Use the glutapp.xcodeproj file to open the project in XCode
 - It has been tested with XCode 8 on macOS Sierra 10.12


Notes:
 - The provided freeglut library is only used in Windows; 
   in Linux and OS X the compiler will seek for the header
   files and libraries in the default development folders.
   
 - On macOS, you can compile in the command line, so you don't
   have to use XCode. Simply follow the Linux instructions. 
   XCode should still be installed so that you have the OpenGL
   and GLUT libraries. To get started with XCode, download it
   from the App Store. Open it and let it set itself up. Then
   in the terminal type: xcode-select -install
   This will install the command line compiler tools on your Mac