#include <stdio.h>
#include <stdlib.h>
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

Image::~Image()
{
    if (data)
        free(data);
}


void Image::read(const char *filename)
{
    if (data != NULL)
    {
        free(data);
    }
    char buff[16];

    FILE *fp;
    int c, rgb_comp_color;
    //open PPM file for reading
    fp = fopen(filename, "rb");
    if (!fp) 
    {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    //read image format
    if (!fgets(buff, sizeof(buff), fp)) 
    {
        perror(filename);
        exit(1);
    }

    //check the image format
    if (buff[0] != 'P' || buff[1] != '6') 
    {
         fprintf(stderr, "Invalid image format (must be 'P6')\n");
         exit(1);
    }

    //check for comments
    c = getc(fp);
    while (c == '#') 
    {
        while (getc(fp) != '\n') ;
            c = getc(fp);
    }

    ungetc(c, fp);
    //read image size information
    if (fscanf(fp, "%d %d", &x, &y) != 2) 
    {
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
    data = (Pixel*)malloc(x * y * sizeof(Pixel));

    //read pixel data from file
    if (fread(data, 3 * x, y, fp) != y) 
    {
         fprintf(stderr, "Error loading image '%s'\n", filename);
         exit(1);
    }

    fclose(fp);
}

void Image::write(const char *filename)
{
    FILE *fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp) 
    {
         fprintf(stderr, "Unable to open file '%s'\n", filename);
         exit(1);
    }

    //write the header file
    //image format
    fprintf(fp, "P6\n");

    //image size
    fprintf(fp, "%d %d\n", x, y);

    // rgb component depth
    fprintf(fp, "%d\n", 255);

    // pixel data
    fwrite(data, 3 * x, y, fp);
    fclose(fp);
}


void Image::reverse_colors()
{
    int i;
    if(data)
    {
         for(i=0; i< x*y; i++)
         {
              data[i].red = 255 - data[i].red;
              data[i].green = 255 - data[i].green;
              data[i].blue = 255 - data[i].blue;
         }
    }
}   


