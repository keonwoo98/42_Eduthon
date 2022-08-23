/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:46:59 by keokim            #+#    #+#             */
/*   Updated: 2022/08/24 03:13:34 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

void printFileHeader(t_file_header *fileHeader) {
	printf("bitmap type : %u\n", fileHeader->bfType);
	printf("bitmap size : %u\n", fileHeader->bfSize);
	printf("bitmap offset : %u\n", fileHeader->bfOffBits);
}

void printInfoHeader(t_info_header *infoHeader) {
	printf("header size : %u\n", infoHeader->biSize);
	printf("image width : %i\n", infoHeader->biWidth);
	printf("image height : %i\n", infoHeader->biHeight);
	printf("color planes : %u\n", infoHeader->biPlanes);
	printf("pixel bits : %u\n", infoHeader->biBitCount);
	printf("compression : %u\n", infoHeader->biCompression);
	printf("pixel data size : %u\n", infoHeader->biSizeImage);
	printf("pixels per meter X : %i\n", infoHeader->biXPelsPerMeter);
	printf("pixels per meter Y : %i\n", infoHeader->biYPelsPerMeter);
}

unsigned char *LoadBitmapFile(t_file_header *fileHeader, t_info_header *infoHeader, char *filename)
{
	FILE *fp = NULL;

	fp = fopen(filename, "rb");
	if (!fp)
	{
		fprintf(stderr, "error: fail to open image file\n");
		return NULL;
	}
	fread(fileHeader, sizeof(t_file_header), 1, fp);	// 비트맵파일헤더 읽기
	fread(infoHeader, sizeof(t_info_header), 1, fp);	// 비트맵인포헤더 읽기
	printFileHeader(fileHeader);
	fseek(fp, fileHeader->bfOffBits, SEEK_SET); // image 데이터 시작 지점으로 이동
	unsigned char *image = (unsigned char *)malloc(sizeof(unsigned char) * infoHeader->biSizeImage); // 이미지크기만큼 메모리할당
	fread(image, sizeof(unsigned char), infoHeader->biSizeImage, fp); //이미지 크기만큼 파일에서 읽어오기
	fclose(fp);
	return image;
}

void WriteBitmapFile(t_file_header *fileHeader, t_info_header *infoHeader, unsigned char *image, char *filename)
{
	FILE *fp = fopen(filename, "wb");
	if (!fp)
	{
		fprintf(stderr, "error: fail to open file\n");
		free(image);
		exit(EXIT_FAILURE);
	}
	fwrite(fileHeader, sizeof(t_file_header), 1, fp);
	fwrite(infoHeader, sizeof(t_info_header), 1, fp);
	fseek(fp, fileHeader->bfOffBits, SEEK_SET);
	fwrite(image, sizeof(unsigned char), infoHeader->biSizeImage, fp);
	fclose(fp);
}
