#include "bitmap.h"

void imageZoom(t_info_header info_header, unsigned char **image, int n) {
	UpDownInversion(info_header, *image);
	unsigned char *tmp = malloc(info_header.biSizeImage);
	for (int y = 0 ; y < info_header.biHeight ; y++) {
		for (int x = 0 ; x < info_header.biWidth * 3 ; x++) {
			tmp[y * info_header.biWidth * 3 + x] = (*image)[y / n * info_header.biWidth * 3 + x / n];
			tmp[y * info_header.biWidth * 3 + x + 1] = (*image)[y / n * info_header.biWidth * 3 + x / n + 1];
			tmp[y * info_header.biWidth * 3 + x + 2] = (*image)[y  / n * info_header.biWidth * 3 + x / n + 2];
		}
	}
	free(*image);
	*image = tmp;
	UpDownInversion(info_header, *image);
}
