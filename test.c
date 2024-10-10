#include <stdio.h>
#include "lib_ppm.h"
#include "zoom.h"

int main(){
    struct image_s data;
    struct image_s *image = &data;
    struct image_s zoomed_image;
    struct image_s *zoomed = &zoomed_image;
    
    read_ppm("lena.ppm", image);

    int zoomWidth = image->width * 3;
    int zoomHeight = image->height * 3;

    new_ppm(zoomed, zoomWidth, zoomHeight);

    zoomed->width = zoomWidth;
    zoomed->height = zoomHeight;

    populate_zoomed_image(image, zoomed);

    free_ppm(image);
    free_ppm(zoomed);
    
    return 0;
};

void populate_zoomed_image(struct image_s *image, struct image_s *zoomed){
    for(int i = 0; i < image->height; i++){
        for(int j = 0; j < image->width; j++){
            
            int old_image_position = i * image->width + j;

            int red = image->pix[old_image_position].r;
            int green = image->pix[old_image_position].g;
            int blue = image->pix[old_image_position].b;

            int new_i = i * 3;
            int new_j = j * 3;

            fill_sp(zoomed, new_i, new_j, red, 0);

            fill_sp(zoomed, new_i, new_j + 1, green, 1);

            fill_sp(zoomed, new_i, new_j + 2, blue, 2);

        }
    }

    write_ppm("lena_zoom.ppm", zoomed);
}


void fill_sp(struct image_s *zoomed, int i, int j, int color, int color_channel) {
    if (color <= 74) {
        set_sub_pixel(zoomed, i, j, 0, 0, 0);
        set_sub_pixel(zoomed, i + 1, j, 0, 0, 0);
        set_sub_pixel(zoomed, i + 2, j, 0, 0, 0);
    } else if (color <= 134) {
        set_sub_pixel(zoomed, i, j, 0, 0, 0);
        set_sub_pixel_with_channel(zoomed, i + 1, j, color, color_channel);
        set_sub_pixel(zoomed, i + 2, j, 0, 0, 0);
    } else if (color <= 179) {
        set_sub_pixel_with_channel(zoomed, i, j, color, color_channel); 
        set_sub_pixel(zoomed, i + 1, j, 0, 0, 0);
        set_sub_pixel_with_channel(zoomed, i + 2, j, color, color_channel);
    } else {
        set_sub_pixel_with_channel(zoomed, i, j, color, color_channel);  
        set_sub_pixel_with_channel(zoomed, i + 1, j, color, color_channel);
        set_sub_pixel_with_channel(zoomed, i + 2, j, color, color_channel);
    }
}

void set_sub_pixel_with_channel(struct image_s *zoomed, int i, int j, int color, int color_channel) {
    int r = 0, g = 0, b = 0;

    if (color_channel == 0) {
        r = color;
    } else if (color_channel == 1) {
        g = color;
    } else if (color_channel == 2) {
        b = color;
    }

    set_sub_pixel(zoomed, i, j, r, g, b);
}

void set_sub_pixel(struct image_s *zoomed, int i, int j, int r, int g, int b) {
    int position = i * zoomed->width + j;
    zoomed->pix[position].r = r;
    zoomed->pix[position].g = g;
    zoomed->pix[position].b = b;
}