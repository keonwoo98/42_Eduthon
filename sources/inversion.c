/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:47:02 by keokim            #+#    #+#             */
/*   Updated: 2022/08/24 09:08:13 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

void	left_right_inversion(t_info_header info_header,
	unsigned char **image, int x, int y)
{
	int				w;
	int				h;
	unsigned char	*copy;

	copy = (unsigned char *)malloc(sizeof(unsigned char)
			* info_header.bi_size_image);
	w = info_header.bi_width * 3;
	h = info_header.bi_height;
	memcpy(copy, *image, info_header.bi_size_image);
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			(*image)[y * w + x] = copy[y * w + w - x - 3];
			(*image)[y * w + x + 1] = copy[y * w + w - x - 2];
			(*image)[y * w + x + 2] = copy[y * w + w - x - 1];
			x += 3;
		}
		y++;
	}
	free(copy);
}

void	up_down_inversion(t_info_header info_header,
	unsigned char **image, int x, int y)
{
	int				w;
	int				h;
	unsigned char	*copy;

	w = info_header.bi_width * 3;
	h = info_header.bi_height;
	copy = (unsigned char *)malloc(sizeof(unsigned char)
			* info_header.bi_size_image);
	memcpy(copy, *image, info_header.bi_size_image);
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			(*image)[y * w + x] = copy[(h - y - 1) * w + x];
			(*image)[y * w + x + 1] = copy[(h - y - 1) * w + x + 1];
			x += 3;
			(*image)[y * w + x + 2] = copy[(h - y - 1) * w + x + 2];
		}
		y++;
	}
	free(copy);
}
