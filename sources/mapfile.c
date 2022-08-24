/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:46:59 by keokim            #+#    #+#             */
/*   Updated: 2022/08/24 09:07:11 by hyopark          ###   ########.fr       */
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

unsigned char	*load_bitmap_file(t_file_header *file_header,
	t_info_header *info_header, char *filename)
{
	FILE			*fp;
	unsigned char	*image;

	fp = fopen(filename, "rb");
	if (!fp)
	{
		fprintf(stderr, "error: fail to open image file\n");
		return (NULL);
	}
	fread(file_header, sizeof(t_file_header), 1, fp);
	fread(info_header, sizeof(t_info_header), 1, fp);
	print_file_header(file_header);
	print_info_header(info_header);
	fseek(fp, file_header->bf_off_bits, SEEK_SET);
	image = (unsigned char *)malloc(sizeof(unsigned char)
			* info_header->bi_size_image);
	if (!image)
	{
		fclose(fp);
		return (NULL);
	}
	fread(image, sizeof(unsigned char), info_header->bi_size_image, fp);
	fclose(fp);
	return (image);
}

void	write_bitmap_file(t_file_header *file_header,
	t_info_header *info_header, unsigned char *image, char *filename)
{
	FILE	*fp;

	fp = fopen(filename, "wb");
	if (!fp)
	{
		fprintf(stderr, "error: fail to open file\n");
		free(image);
		exit(EXIT_FAILURE);
	}
	fwrite(file_header, sizeof(t_file_header), 1, fp);
	fwrite(info_header, sizeof(t_info_header), 1, fp);
	fseek(fp, file_header->bf_off_bits, SEEK_SET);
	fwrite(image, sizeof(unsigned char), info_header->bi_size_image, fp);
	fclose(fp);
}
