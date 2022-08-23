/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:39:37 by keokim            #+#    #+#             */
/*   Updated: 2022/08/24 03:16:06 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)

typedef struct s_file_header
{
	unsigned short		bfType;
	unsigned int		bfSize;
	unsigned short		bfReserved1;
	unsigned short		bfReserved2;
	unsigned int		bfOffBits;
} t_file_header;

typedef struct s_info_header
{
	unsigned int		biSize;
	int					biWidth;
	int					biHeight;
	unsigned short		biPlanes;
	unsigned short		biBitCount;
	unsigned int		biCompression;
	unsigned int		biSizeImage;
	int					biXPelsPerMeter;
	int					biYPelsPerMeter;
	unsigned int		biClrUsed;
	unsigned int		biClrImportant;
} t_info_header;

#pragma pack(pop)

unsigned char *LoadBitmapFile(FILE **img, t_file_header *fileHeader, t_info_header *infoHeader, char *filename);
void WriteBitmapFile(FILE **img, t_file_header *fileHeader, t_info_header *infoHeader, unsigned char *image, char *filename);
void LeftRightInversion(t_info_header infoHeader, unsigned char *image);
void UpDownInversion(t_info_header infoHeader, unsigned char *image);
void cvtColor(unsigned char *image, t_info_header info_header);
void imageZoom(t_info_header info_header, unsigned char **image, int n);
#endif
