/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:46:59 by keokim            #+#    #+#             */
/*   Updated: 2022/08/23 21:47:00 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

unsigned char* LoadBitmapFile(BITMAPHEADER* bitmapHeader, int* imgSize, char* filename)
{
	FILE* fp = fopen(filename, "rb");	//파일을 이진읽기모드로 열기
	if (fp == NULL)
	{
		printf("파일로딩에 실패했습니다.\n");	//fopen에 실패하면 NULL값을 리턴
		return NULL;
	}
	else
	{
		fread(&bitmapHeader->bf, sizeof(BITMAPFILEHEADER), 1, fp);	//비트맵파일헤더 읽기
		fread(&bitmapHeader->bi, sizeof(BITMAPINFOHEADER), 1, fp);	//비트맵인포헤더 읽기
		fread(&bitmapHeader->hRGB, sizeof(RGBQUAD), 256, fp);	//색상팔렛트 읽기

		int imgSizeTemp = bitmapHeader->bi.biWidth * bitmapHeader->bi.biHeight;	//이미지 사이즈 계산
		*imgSize = imgSizeTemp;	// 이미지 사이즈를 상위 변수에 할당

		unsigned char* image = (unsigned char*)malloc(sizeof(unsigned char) * imgSizeTemp);	//이미지크기만큼 메모리할당
		fread(image, sizeof(unsigned char), imgSizeTemp, fp);//이미지 크기만큼 파일에서 읽어오기
		fclose(fp);
		return image;
	}
}

void WriteBitmapFile(BITMAPHEADER out, unsigned char* output, int imgSize, char* filename)
{
	FILE* fp = fopen(filename, "wb");

	fwrite(&out.bf, sizeof(BITMAPFILEHEADER), 1, fp);
	fwrite(&out.bi, sizeof(BITMAPINFOHEADER), 1, fp);
	fwrite(&out.hRGB, sizeof(RGBQUAD), 256, fp);
	fwrite(output, sizeof(unsigned char), imgSize, fp);
	fclose(fp);
}
