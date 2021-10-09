#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "image.h"

Image::Image() {
    data = NULL;
}

Image::Image(const char* filename) {
    data = NULL;
    read(filename);
}

Image::Image(int size_x, int size_y) : size_x(size_x), size_y(size_y) {
    data = (Pixel*)calloc(size_x * size_y, sizeof(Pixel));
}



Image::~Image() {
    if (data)
        free(data);
}

int Image::get_size_x() {
    return size_x;
}

int Image::get_size_y() {
    return size_y;
}

void Image::read(const char *filename) {
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
    if (fscanf(fp, "%d %d", &size_x, &size_y) != 2) {
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
    data = (Pixel*)malloc(size_x * size_y * sizeof(Pixel));

    //read pixel data from file
    if (fread(data, 3 * size_x, size_y, fp) != size_y) {
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
    fprintf(fp, "%d %d\n", size_x, size_y);

    // rgb component depth
    fprintf(fp, "%d\n", 255);

    // pixel data
    fwrite(data, 3 * size_x, size_y, fp);
    fclose(fp);
}


void Image::reverse_colors() {
    if(!data) {
        return;
    }
    for(int i = 0; i < size_x * size_y; i++) {
        data[i].r = 255 - data[i].r;
        data[i].g = 255 - data[i].g;
        data[i].b = 255 - data[i].b;
    }
}   


void Image::flip_vertically() {
    if(!data) {
        return;
    }
    Pixel temp;
    for(int j = 0; j < size_y / 2; j++) {
        for(int i = 0; i < size_x; i++) {  
            temp = data[i + j * size_x];
            data[i + j * size_x] = data[i + (size_y - j - 1) * size_x];
            data[i + (size_y - j - 1) * size_x] = temp;
        }
    }
}


void Image::set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    data[x + y * size_x] = Pixel(r, g, b);
}

void Image::set_pixel(int x, int y, const Pixel& p) {
    data[x + y * size_x] = p;
}

Pixel Image::get_pixel(int x, int y) {
    return data[x + y * size_x];
}

