#ifndef WRITING_PNG_H
#define WRITING_PNG_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <png.h>
#include "utils.h"
// g++ writing_png.cpp -lpng -lz

/**
 * @brief Initialise la structure de l'image produite par le programme et renvoi la structure de l'image
 * 
 * @param filename Nom de l'image produite
 * @param width Largeur de l'image en pixel
 * @param height Hauteur de l'image en pixel
 * @param title titre de l'image (différent du nom du fichier)
 * @param fp Pointeur vers le fichier de sortie
 * @param png_ptr Référence à la structure de l'image
 * @param info_ptr Référence aux informations de l'image
 * @return png_structp 
 */
png_structp initImage(char* filename, int width, int height, char* title,FILE* fp,png_structp &png_ptr,png_infop &info_ptr);

/**
 * @brief Écrit et génére les 
 * 
 * @param png_ptr Référence à la structure de l'image
 * @param R Pointeur vers le buffer contenant les données des pixel pour la couleur Rouge
 * @param G Pointeur vers le buffer contenant les données des pixel pour la couleur Verte
 * @param B Pointeur vers le buffer contenant les données des pixel pour la couleur Bleue
 * @param width Largeur de l'image en pixel
 * @param height Hauteur de l'image en pixel
 * @param fp Pointeur vers le fichier de sortie
 * @param info_ptr Référence aux informations de l'image
 */
void writeImage(png_structp &png_ptr, float* R,float* G,float* B, int width, int height, FILE *fp, png_infop &info_ptr);

/**
 * @brief Écriture des cases i,j des buffers de couleurs 
 * 
 * @param R Pointeur vers le buffer contenant les données des pixel pour la couleur Rouge
 * @param G Pointeur vers le buffer contenant les données des pixel pour la couleur Verte
 * @param B Pointeur vers le buffer contenant les données des pixel pour la couleur Bleue
 * @param i Index de la ligne de la case à remplir
 * @param j Index de la colonne de la case à remplir
 * @param r Valeur de la couleur Rouge
 * @param g Valeur de la couleur Verte
 * @param b Valeur de la couleur Bleue
 * @param width Largeur de l'image en pixel
 */
void write_pixel(float* R,float* G,float* B, int i, int j, int r, int g, int b, int width);


#endif