/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:12:27 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 19:35:41 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUATION_H
# define EQUATION_H

# include "vector3.h"

double	closest_point_on_skew_lines(const t_vector3 a1, const t_vector3 b1,
			const t_vector3 a2, const t_vector3 b2);

#endif
