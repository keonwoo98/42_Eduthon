/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:47:04 by keokim            #+#    #+#             */
/*   Updated: 2022/08/24 09:36:59 by hyopark          ###   ########.fr       */
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
	image = load_bitmap_file(&img, &file_header, &info_header, "sample.bmp");
	if (!image)
	{
		return (EXIT_FAILURE);
	}
	cvt_color(image, info_header);
	left_right_inversion(info_header, image, 0, 0);
	image_zoom(info_header, &image, 2);
	write_bitmap_file(&img, &file_header, &info_header, image, "output.bmp");
	free(image);
}
