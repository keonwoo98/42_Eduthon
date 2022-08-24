/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:49:37 by hyopark           #+#    #+#             */
/*   Updated: 2022/08/24 09:06:44 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

void	image_zoom(t_info_header info_header, unsigned char **image, int n)
{
	unsigned char	*tmp;
	int				y;
	int				x;

	tmp = malloc(info_header.bi_size_image);
	up_down_inversion(info_header, image, 0, 0);
	y = 0;
	while (y < info_header.bi_height)
	{
		x = 0;
		while (x < info_header.bi_width * 3)
		{
			tmp[y * info_header.bi_width * 3 + x] = (*image)[y
				/ n * info_header.bi_width * 3 + x / n];
			tmp[y * info_header.bi_width * 3 + x + 1] = (*image)[y
				/ n * info_header.bi_width * 3 + x / n + 1];
			tmp[y * info_header.bi_width * 3 + x + 2] = (*image)[y
				/ n * info_header.bi_width * 3 + x / n + 2];
			x++;
		}
		y++;
	}
	free(*image);
	*image = tmp;
	up_down_inversion(info_header, image, 0, 0);
}
