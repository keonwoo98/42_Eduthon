/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:39:37 by keokim            #+#    #+#             */
/*   Updated: 2022/08/24 09:18:05 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h> 

# pragma pack(push, 1)

typedef struct s_file_header
{
	unsigned short		bf_type;
	unsigned int		bf_size;
	unsigned short		bf_reserved1;
	unsigned short		bf_reserved2;
	unsigned int		bf_off_bits;
}				t_file_header;

typedef struct s_info_header
{
	unsigned int		bi_size;
	int					bi_width;
	int					bi_height;
	unsigned short		bi_planes;
	unsigned short		bi_bit_count;
	unsigned int		bi_compression;
	unsigned int		bi_size_image;
	int					bi_x_pels_per_meter;
	int					bi_y_pels_per_meter;
	unsigned int		bi_clr_used;
	unsigned int		bi_clr_important;
}				t_info_header;

# pragma pack(pop)

unsigned char	*load_bitmap_file(FILE **img, t_file_header *fileHeader,
					t_info_header *infoHeader, char *filename);
void			write_bitmap_file(FILE **img, t_file_header *fileHeader,
					t_info_header *infoHeader,
					unsigned char *output, char *filename);
void			left_right_inversion(t_info_header infoHeader,
					unsigned char *image, int x, int y);
void			up_down_inversion(t_info_header infoHeader,
					unsigned char *image, int x, int y);
void			cvt_color(unsigned char *image, t_info_header info_header);
void			image_zoom(t_info_header info_header,
					unsigned char **image, int n);
#endif
