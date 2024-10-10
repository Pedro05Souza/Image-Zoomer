#include "lib_ppm.h"


void populate_zoomed_image(struct image_s *image, struct image_s *zoomed);

void fill_sp(struct image_s *zoomed, int i, int j, int color, int color_channel);

void set_sub_pixel(struct image_s *zoomed, int i, int j, int r, int g, int b);

void set_sub_pixel_with_channel(struct image_s *zoomed, int i, int j, int color, int color_channel);