/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:47:02 by keokim            #+#    #+#             */
/*   Updated: 2022/08/23 21:47:51 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

//출력이미지의 좌표를 기준으로 원본의 좌표를 찾아주는 함수
void CalculatePosition(int *source_x, int *source_y, int output_x, int output_y, int width, int height, double angle_rad)
{
	//이미지 회전 중심을 이미지의 중심으로 놓기 위해 평행이동
	output_x -= (width / 2);
	output_y -= (height / 2);

	//회전된 좌표를 가지고 원본에서 가져와야할 좌료를 구함.
	double _x = cos(angle_rad) * output_x + sin(angle_rad) * output_y;
	double _y = -1 * sin(angle_rad) * output_x + cos(angle_rad) * output_y;

	//평행이동을 원래대로 복구
	*source_x = (int)_x + (width / 2);
	*source_y = (int)_y + (height / 2);
}

//이미지를 회전시키는 함수
void RotatingImage(unsigned char *image, unsigned char *output, int img_width, int img_height, int angle)
{
	int source_x = 0;
	int source_y = 0;

	//입력된 각도를 라디안 값으로 바꿈 (파이값은 근삿값으로 3.141592)
	double angle_rad = (double)angle / 180.0 * 3.141592 * -1;

	for (int y = 0; y < img_height; y++)
	{
		for (int x = 0; x < img_width; x++)
		{
			CalculatePosition(&source_x, &source_y, x, y, img_width, img_height, angle_rad);

			//만약 가져오려는 좌표가 캔버스를 벗어나면, 그냥 검정색으로 처리
			if ((source_y < img_width && source_x < img_height))
				output[y * img_height + x] = image[source_y * img_width + source_x];
			else
				output[y * img_height + x] = 0;
		}
	}
}
