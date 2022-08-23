#include "bitmap.h"

void cvtColor(unsigned char *image, t_info_header *info_header) {
	unsigned char tmp;

	for (unsigned int imageIdx = 0 ; imageIdx < info_header->biSizeImage ; imageIdx += 3)
    {
        tmp = image[imageIdx];
        image[imageIdx] = image[imageIdx + 2];
        image[imageIdx + 2] = tmp;
    }
}
