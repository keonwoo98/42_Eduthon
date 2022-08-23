/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:39:37 by keokim            #+#    #+#             */
/*   Updated: 2022/08/23 22:18:18 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma pack(push, 1)			 // 구조체를 1바이트 크기로 정렬

typedef struct _BITMAPFILEHEADER // BMP 비트맵 파일 헤더 구조체
{
	unsigned short bfType;		// BMP 파일 매직 넘버
	unsigned int bfSize;		// 파일 크기
	unsigned short bfReserved1; // 예약
	unsigned short bfReserved2; // 예약
	unsigned int bfOffBits;		// 비트맵 데이터의 시작 위치
} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER // BMP 비트맵 정보 헤더 구조체(DIB 헤더)
{
	unsigned int biSize;		 // 현재 구조체의 크기
	int biWidth;				 // 비트맵 이미지의 가로 크기
	int biHeight;				 // 비트맵 이미지의 세로 크기
	unsigned short biPlanes;	 // 사용하는 색상판의 수
	unsigned short biBitCount;	 // 픽셀 하나를 표현하는 비트 수
	unsigned int biCompression;	 // 압축 방식
	unsigned int biSizeImage;	 // 비트맵 이미지의 픽셀 데이터 크기
	int biXPelsPerMeter;		 // 그림의 가로 해상도(미터당 픽셀)
	int biYPelsPerMeter;		 // 그림의 세로 해상도(미터당 픽셀)
	unsigned int biClrUsed;		 // 색상 테이블에서 실제 사용되는 색상 수
	unsigned int biClrImportant; // 비트맵을 표현하기 위해 필요한 색상 인덱스 수
} BITMAPINFOHEADER;

typedef struct _RGBTRIPLE // 24비트 비트맵 이미지의 픽셀 구조체
{
	unsigned char rgbtBlue;	 // 파랑
	unsigned char rgbtGreen; // 초록
	unsigned char rgbtRed;	 // 빨강
} RGBTRIPLE;

typedef struct struct_RGBQUAD
{
	unsigned char rgbBlue;	// 파랑
	unsigned char rgbGreen; // 초록
	unsigned char rgbRed;	// 빨강
	unsigned char rgbReserved;
} RGBQUAD;

typedef struct tagBITMAPHEADER //비트맵 헤더를 한묶음으로
{
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;
	RGBTRIPLE hRGB[256];
} BITMAPHEADER;

#pragma pack(pop)

unsigned char* LoadBitmapFile(BITMAPHEADER* bitmapHeader, int* imgSize, char* filename);
void WriteBitmapFile(BITMAPHEADER out, unsigned char* output, int imgSize, char* filename);
void CalculatePosition(int *source_x, int *source_y, int output_x, int output_y, int width, int height, double angle_rad);
void RotatingImage(unsigned char *image, unsigned char *output, int img_width, int img_height, int angle);

#endif
