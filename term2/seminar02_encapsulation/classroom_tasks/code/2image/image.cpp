#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "image.h"

Image::Image() 
{
    data = NULL;
}

Image::Image(const char* filename) 
{
    data = NULL;
    read(filename);
}

Image::Image(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY) 
{
    data = (Pixel*)calloc(sizeX * sizeY, sizeof(Pixel));
}



Image::~Image() 
{
    if (data)
        free(data);
}

int Image::getSizeX() 
{
    return sizeX;
}

int Image::getSizeY() 
{
    return sizeY;
}

void Image::read(const char *filename) 
{
    if (data != NULL) {
        free(data);
    }
    char buff[16];

    FILE *fp;
    int c, rgb_comp_color;
    //open PPM file for reading
    fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    //read image format
    if (!fgets(buff, sizeof(buff), fp)) {
        perror(filename);
        exit(1);
    }

    //check the image format
    if (buff[0] != 'P' || buff[1] != '6') {
         fprintf(stderr, "Invalid image format (must be 'P6')\n");
         exit(1);
    }

    //check for comments
    c = getc(fp);
    while (c == '#') {
        while (getc(fp) != '\n') ;
            c = getc(fp);
    }

    ungetc(c, fp);
    //read image size information
    if (fscanf(fp, "%d %d", &sizeX, &sizeY) != 2) {
         fprintf(stderr, "Invalid image size (error loading '%s')\n", filename);
         exit(1);
    }

    //read rgb component
    if (fscanf(fp, "%d", &rgb_comp_color) != 1) {
         fprintf(stderr, "Invalid rgb component (error loading '%s')\n", filename);
         exit(1);
    }

    //check rgb component depth
    if (rgb_comp_color!= 255) {
         fprintf(stderr, "'%s' does not have 8-bits components\n", filename);
         exit(1);
    }

    while (fgetc(fp) != '\n') ;
    //memory allocation for pixel data
    data = (Pixel*)malloc(sizeX * sizeY * sizeof(Pixel));

    //read pixel data from file
    if (fread(data, 3 * sizeX, sizeY, fp) != sizeY) {
         fprintf(stderr, "Error loading image '%s'\n", filename);
         exit(1);
    }

    fclose(fp);
}

void Image::write(const char *filename) {
    FILE *fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp) {
         fprintf(stderr, "Unable to open file '%s'\n", filename);
         exit(1);
    }

    //write the header file
    //image format
    fprintf(fp, "P6\n");

    //image size
    fprintf(fp, "%d %d\n", sizeX, sizeY);

    // rgb component depth
    fprintf(fp, "%d\n", 255);

    // pixel data
    fwrite(data, 3 * sizeX, sizeY, fp);
    fclose(fp);
}


void Image::reverseColors() 
{
    if(!data) {
        return;
    }
    for(int i = 0; i < sizeX * sizeY; i++) {
        data[i].r = 255 - data[i].r;
        data[i].g = 255 - data[i].g;
        data[i].b = 255 - data[i].b;
    }
}   


void Image::flipVertically() 
{
    if(!data) {
        return;
    }
    Pixel temp;
    for(int j = 0; j < sizeY / 2; j++) {
        for(int i = 0; i < sizeX; i++) {  
            temp = data[i + j * sizeX];
            data[i + j * sizeX] = data[i + (sizeY - j - 1) * sizeX];
            data[i + (sizeY - j - 1) * sizeX] = temp;
        }
    }
}


void Image::setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    data[x + y * sizeX] = Pixel(r, g, b);
}

void Image::setPixel(int x, int y, const Pixel& p) 
{
    data[x + y * sizeX] = p;
}

Pixel Image::getPixel(int x, int y) 
{
    return data[x + y * sizeX];
}

