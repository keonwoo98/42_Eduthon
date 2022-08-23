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
	t_file_header file_header;
	t_info_header info_header;

	unsigned char *image = LoadBitmapFile(&file_header, &info_header, "sample.bmp");

	// RotatingImage(image, output, in.bi.biWidth, in.bi.biHeight, 180);
	// cvtColor(image, output, in.bi.biWidth, in.bi.biHeight);
	WriteBitmapFile(&file_header, &info_header, image, "output.bmp");
	free(image);
}
