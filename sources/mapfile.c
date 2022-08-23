/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:46:59 by keokim            #+#    #+#             */
/*   Updated: 2022/08/23 22:18:08 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

void printFileHeader(t_file_header *bitmapFileHeader) {
	printf("bitmap type : %u\n", bitmapFileHeader->bfType);
	printf("bitmap size : %u\n", bitmapFileHeader->bfSize);
	printf("bitmap offset : %u\n", bitmapFileHeader->bfOffBits);
}

unsigned char *LoadBitmapFile(t_file_header *fileHeader, t_info_header *infoHeader, char *filename)
{
	FILE *fp = fopen(filename, "rb");
	if (!fp)
	{
		printf("파일로딩에 실패했습니다.\n");
		return NULL;
	}
	fread(&fileHeader, sizeof(t_file_header), 1, fp);	// 비트맵파일헤더 읽기
	fread(&infoHeader, sizeof(t_info_header), 1, fp);	// 비트맵인포헤더 읽기
	printFileHeader(fileHeader);
	fseek(fp, fileHeader->bfOffBits, SEEK_SET); // image 데이터 시작 지점으로 이동
	unsigned char *image = (unsigned char *)malloc(sizeof(unsigned char) * infoHeader->biSizeImage); // 이미지크기만큼 메모리할당
	fread(image, sizeof(unsigned char), infoHeader->biSizeImage, fp); //이미지 크기만큼 파일에서 읽어오기
	fclose(fp);
	return image;
}

void WriteBitmapFile(t_file_header *fileHeader, t_info_header *infoHeader, unsigned char *output, char *filename)
{
	FILE *fp = fopen(filename, "wb");
	
	fwrite(fileHeader, sizeof(t_file_header), 1, fp);
	fwrite(infoHeader, sizeof(t_info_header), 1, fp);
	fseek(fp, fileHeader->bfOffBits, SEEK_SET);
	fwrite(output, sizeof(unsigned char), infoHeader->biSizeImage, fp);
	fclose(fp);
}
