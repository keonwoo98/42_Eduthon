/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:46:52 by hyopark           #+#    #+#             */
/*   Updated: 2022/08/24 08:59:26 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

void	cvt_color(unsigned char *image, t_info_header info_header)
{
	unsigned char	tmp;
	unsigned int	image_idx;

	image_idx = 0;
	while (image_idx < info_header.bi_size_image)
	{
		tmp = image[image_idx];
		image[image_idx] = image[image_idx + 2];
		image[image_idx + 2] = tmp;
		image_idx += 3;
	}
}
