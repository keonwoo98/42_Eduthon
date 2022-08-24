/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:46:59 by keokim            #+#    #+#             */
/*   Updated: 2022/08/24 09:37:27 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

void	print_file_header(t_file_header *file_header)
{
	printf("bitmap type : %u\n", file_header->bf_type);
	printf("bitmap size : %u\n", file_header->bf_size);
	printf("bitmap offset : %u\n", file_header->bf_off_bits);
}

void	print_info_header(t_info_header *info_header)
{
	printf("header size : %u\n", info_header->bi_size);
	printf("image width : %i\n", info_header->bi_width);
	printf("image height : %i\n", info_header->bi_height);
	printf("color planes : %u\n", info_header->bi_planes);
	printf("pixel bits : %u\n", info_header->bi_bit_count);
	printf("compression : %u\n", info_header->bi_compression);
	printf("pixel data size : %u\n", info_header->bi_size_image);
	printf("pixels per meter X : %i\n", info_header->bi_x_pels_per_meter);
	printf("pixels per meter Y : %i\n", info_header->bi_y_pels_per_meter);
}

unsigned char	*load_bitmap_file(FILE **img, t_file_header *file_header,
	t_info_header *info_header, char *filename)
{
	unsigned char	*image;

	*img = fopen(filename, "rb");
	if (!*img)
	{
		fprintf(stderr, "error: fail to open image file\n");
		return (NULL);
	}
	fread(file_header, sizeof(t_file_header), 1, *img);
	fread(info_header, sizeof(t_info_header), 1, *img);
	fseek(*img, file_header->bf_off_bits, SEEK_SET);
	image = (unsigned char *)malloc(sizeof(unsigned char)
			* info_header->bi_size_image);
	if (!image)
	{
		fclose(*img);
		return (NULL);
	}
	fread(image, sizeof(unsigned char), info_header->bi_size_image, *img);
	return (image);
}

void	write_bitmap_file(FILE **img, t_file_header *file_header,
	t_info_header *info_header, unsigned char *image)
{
	FILE	*fp;
	char	*buffer;

	fp = fopen("zoom.bmp", "wb");
	if (!fp)
	{
		fprintf(stderr, "error: fail to open file\n");
		free(image);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(file_header->bf_off_bits);
	if (!buffer)
	{
		fprintf(stderr, "error: memory error!\n");
		exit(EXIT_FAILURE);
	}
	fseek(*img, 0, SEEK_SET);
	fread(buffer, file_header->bf_off_bits, 1, *img);
	fseek(fp, 0, SEEK_SET);
	fwrite(buffer, file_header->bf_off_bits, 1, fp);
	fwrite(image, sizeof(unsigned char), info_header->bi_size_image, fp);
	free(buffer);
	fclose(*img);
	fclose(fp);
}
