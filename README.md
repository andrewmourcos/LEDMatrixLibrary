# LEDMatrixLibrary

A simple library for the Arduino platform (or other similar MCUs).

Allows the user to instantiate "matrix" objects of any size. Allows for rapid use/testing with LED matrices. 

Features:
- Multiplexing
- Display any 2d array directly on the LED matrix
- Scrolling items on screen
- Avoids necessity of decade counter + shift register circuits

Note: this is made specifically for single-color matrices (no RGB support)

## Files
```
.
├── LEDMatrixLibrary.ino 	# An example script using the matrix class (scrolling arrow)
├── LICENSE	
├── Matrix.cpp 				# Class definition
├── Matrix.h 				# Class declaration (you need to #include this file)
└── README.md
```