#include <stdio.h>
#include "lib_ppm.h"
#include "zoom.h"

int main(){
    struct image_s data;
    struct image_s *image = &data;
    struct image_s zoomed_image;
    struct image_s *zoomed = &zoomed_image;
    
    read_ppm("lena.ppm", image);

    printf("Image width: %d \n", image->width);
    printf("Image height: %d \n", image->height);

    int zoomWidth = image->width * 3;
    int zoomHeight = image->height * 3;

    new_ppm(zoomed, zoomWidth, zoomHeight);

    zoomed->width = zoomWidth;
    zoomed->height = zoomHeight;
    printf("TESTE1 \n");
    populate_zoomed_image(image, zoomed);

    free_ppm(image);
    free_ppm(zoomed);
    
    return 0;
};

void populate_zoomed_image(struct image_s *image, struct image_s *zoomed){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            
            int old_image_position = i * image->width + j;
            
            for(int r = 0; r < 3; r++){
                
            }

        }
    }

    write_ppm("lena_zoom.ppm", zoomed);
}


// void verify_color(int r, int g, int b){
//     for(int m = 0; m < 3; m++){
//         if(m == 0){
           
//         }
//     }
// }
    
