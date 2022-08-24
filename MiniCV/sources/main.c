/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:47:04 by keokim            #+#    #+#             */
/*   Updated: 2022/08/24 14:07:37 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

int	main(void)
{
	t_file_header	file_header;
	t_info_header	info_header;
	unsigned char	*image;
	FILE			*img;

	img = NULL;
	image = load_bitmap_file(&img, &file_header, &info_header, "img/castle.bmp");
	if (!image)
	{
		return (EXIT_FAILURE);
	}
	cvt_color(image, info_header);
	left_right_inversion(info_header, &image, 0, 0);
	up_down_inversion(info_header, &image, 0, 0);
	// image_zoom(info_header, &image, 2);
	write_bitmap_file(&img, &file_header, &info_header, image);
	free(image);
}
