/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:47:02 by keokim            #+#    #+#             */
/*   Updated: 2022/08/24 03:16:13 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

void LeftRightInversion(t_info_header infoHeader, unsigned char *image)
{
	int w = infoHeader.biWidth * 3;
	int h = infoHeader.biHeight;
	unsigned char *copy = (unsigned char *)malloc(sizeof(unsigned char) * infoHeader.biSizeImage);
	memcpy(copy, image, infoHeader.biSizeImage);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x += 3)
		{
			image[y * w + x] = copy[y * w + w - x - 3];
			image[y * w + x + 1] = copy[y * w + w - x - 2];
			image[y * w + x + 2] = copy[y * w + w - x - 1];
		}
	}
	free(copy);
}

void UpDownInversion(t_info_header infoHeader, unsigned char *image)
{
	int w = infoHeader.biWidth * 3;
	int h = infoHeader.biHeight;
	unsigned char *copy = (unsigned char *)malloc(sizeof(unsigned char) * infoHeader.biSizeImage);
	memcpy(copy, image, infoHeader.biSizeImage);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x += 3)
		{
			image[y * w + x] = copy[(h - y - 1) * w + x];
			image[y * w + x + 1] = copy[(h - y - 1) * w + x + 1];
			image[y * w + x + 2] = copy[(h - y - 1) * w + x + 2];
		}
	}
	free(copy);
}
