/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:47:04 by keokim            #+#    #+#             */
/*   Updated: 2022/08/23 21:48:29 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

int main(void)
{
	BITMAPHEADER in;
	int imgSize;
	unsigned char *image = LoadBitmapFile(&in, &imgSize, "boat_heq.bmp");

	unsigned char *output = malloc(sizeof(unsigned char) * imgSize);

	RotatingImage(image, output, in.bi.biWidth, in.bi.biHeight, 180);

	WriteBitmapFile(in, output, imgSize, "output.bmp");
	
	free(image);
	free(output);
}
