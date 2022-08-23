/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:47:04 by keokim            #+#    #+#             */
/*   Updated: 2022/08/24 03:15:07 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

int main(void)
{
	t_file_header file_header;
	t_info_header info_header;
	FILE *img = NULL;

	unsigned char *image = LoadBitmapFile(&img, &file_header, &info_header, "../img/castle.bmp");
	if (!image) {
		return (EXIT_FAILURE);
	}
	// cvtColor(image, info_header);
	// LeftRightInversion(info_header, image);
	// imageZoom(info_header, &image, 2);
	WriteBitmapFile(&img, &file_header, &info_header, image, "output.bmp");
	free(image);
}
