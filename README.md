**FDF**\
Example of input
![GitHub Screen_Shot](screen_shots/example_input.png)\
Appropriate output\
![GitHub Screen_Shot](screen_shots/example_output.png)\
This is a simple 3D rendering of a height map.\
To create were used MiniLibX (library of a simple graphical interface) and matrix multiplication.
  
**Features:**\
Simple file format definition (array of space-separated integers).\
Easy 3D manipulations(zoom, move, rotations, change the height by keys and mouse)\
Camera controls (zoom, translate).\
Reading colors from the map.\
Pretty color gradients depend on height.

**Compiling and running:**\
Run make. An executable will compile. Currently only tested on OS X.\
Run it with ./fdf [map]. A bunch of sample maps are provided in the maps directory. The one in the screenshot above is elem-col.fdf

