/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:39:22 by nsouchal          #+#    #+#             */
/*   Updated: 2024/05/28 12:04:52 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_a(t_data *data)
{
	if (data->map.map[(int)(data->pos_y - data->plane_y * data->move_speed)] \
	[(int)(data->pos_x - data->plane_x * data->move_speed)] != '1')
	{
		data->pos_x -= data->plane_x * data->move_speed;
		data->pos_y -= data->plane_y * data->move_speed;
	}
}

void	move_w(t_data *data)
{
	if (data->map.map[(int)(data->pos_y + data->dir_y * data->move_speed)] \
	[(int)(data->pos_x + data->dir_x * data->move_speed)] != '1')
	{
		data->pos_y += data->dir_y * data->move_speed;
		data->pos_x += data->dir_x * data->move_speed;
	}
}

void	move_d(t_data *data)
{
	if (data->map.map[(int)(data->pos_y + data->plane_y * data->move_speed)] \
	[(int)(data->pos_x + data->plane_x * data->move_speed)] != '1')
	{
		data->pos_x += data->plane_x * data->move_speed;
		data->pos_y += data->plane_y * data->move_speed;
	}
}

void	move_s(t_data *data)
{
	if (data->map.map[(int)(data->pos_y - data->dir_y * data->move_speed)] \
	[(int)(data->pos_x - data->dir_x * data->move_speed)] != '1')
	{
		data->pos_y -= data->dir_y * data->move_speed;
		data->pos_x -= data->dir_x * data->move_speed;
	}
}

void	turn_camera_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * data->cos_rot_speed - data->dir_y * \
	data->sin_rot_speed;
	data->dir_y = old_dir_x * data->sin_rot_speed + data->dir_y * \
	data->cos_rot_speed;
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * data->cos_rot_speed - data->plane_y * \
	data->sin_rot_speed;
	data->plane_y = old_plane_x * data->sin_rot_speed + data->plane_y * \
	data->cos_rot_speed;
}
