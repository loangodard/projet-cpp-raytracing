#ifndef WRITING_PNG_H
#define WRITING_PNG_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <png.h>
// g++ writing_png.cpp -lpng -lz

// Creates a test image for saving. Creates a Mandelbrot Set fractal of size width x height
float *createMandelbrotImage(int width, int height);

// This takes the float value 'val', converts it to red, green & blue values, then 
// sets those values into the image memory buffer location pointed to by 'ptr'
inline void setRGB(png_byte *ptr, float val);

// This function actually writes out the PNG image file. The string 'title' is
// also written into the image file
png_structp initImage(char* filename, int width, int height, char* title,FILE* fp,png_structp &png_ptr,png_infop &info_ptr);
void writeImage(png_structp &png_ptr, float *buffer, int width, int height, FILE *fp, png_infop &info_ptr);
void write_pixel(float *buffer, int i, int j, int r, int g, int b, int width);


#endif