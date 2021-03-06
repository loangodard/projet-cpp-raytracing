#include "writing_png.h"


png_structp initImage(char *filename, int width, int height, char *title, FILE *fp, png_structp &png_ptr, png_infop &info_ptr)
{
	int code = 0;

	// Open file for writing (binary mode)
	fp = fopen(filename, "wb");
	if (fp == NULL)
	{
		throw("Could not open file %s for writing\n");
	}

	// Initialize write structure
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL)
	{
		throw("Could not allocate write struct\n");
	}

	// Initialize info structure
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL)
	{
		throw("Could not allocate info struct\n");
	}

	// Setup Exception handling
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		throw("Error during png creation\n");
	}

	png_init_io(png_ptr, fp);

	// Write header (8 bit colour depth)
	png_set_IHDR(png_ptr, info_ptr, width, height,
				 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
				 PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	// Set title
	if (title != NULL)
	{
		png_text title_text;
		title_text.compression = PNG_TEXT_COMPRESSION_NONE;
		title_text.key = strdup("Title");
		title_text.text = title;
		png_set_text(png_ptr, info_ptr, &title_text, 1);
	}

	png_write_info(png_ptr, info_ptr);

	// Allocate memory for one row (3 bytes per pixel - RGB)

	return png_ptr;
}

void writeImage(png_structp &png_ptr, float* R,float* G,float* B, int width, int height, FILE *fp, png_infop &info_ptr)
{
	png_bytep row = NULL;
	// Write image data
	int x, y;
	row = (png_bytep)malloc(3 * width * sizeof(png_byte));
	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
				(&row[3*x])[0] = R[y * width + x];
				(&row[3*x])[1] = G[y * width + x];
				(&row[3*x])[2] = B[y * width + x];

		}
		png_write_row(png_ptr, row);
	}

	// End write
	png_write_end(png_ptr, NULL);

	if (fp != NULL)
		fclose(fp);
	if (info_ptr != NULL)
		png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
	if (png_ptr != NULL)
		png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
	if (row != NULL)
		free(row);

	return;
}

void write_pixel(float* R,float* G,float* B, int i, int j, int r, int g, int b, int width)
{
	R[i * width + j] = (r < 0) ? 0 : r;
	G[i * width + j] = (g < 0) ? 0 : g;
	B[i * width + j] = (b < 0) ? 0 : b;
}