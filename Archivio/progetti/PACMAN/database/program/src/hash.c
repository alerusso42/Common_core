/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:50:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/04 20:57:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_abs(int n)
{
	if (n == INT_MIN)
		return (INT_MAX);
	if (n < 0)
		n *= -1;
	return (n);
}

uint32_t	mur_switch(uint32_t h, unsigned char *data, int len, uint32_t m)
{
	if (len == 3)
		h ^= data[2] << 16;
	if (len >= 2)
		h ^= data[1] << 8;
	if (len >= 1)
	{
		h ^= data[0];
		h *= m;
	}
	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;
	return (h);
}

uint32_t	murmurhash2(const void *key, int len, uint32_t seed)
{
	uint32_t		m;
	uint32_t		h;
	uint32_t		k;
	unsigned char	*data;

	m = 0x5bd1e995;
	h = seed ^ len;
	data = (unsigned char *)key;
	while (len >= 4)
	{
		k = *(uint32_t *)data;
		k *= m;
		k ^= k >> 24;
		k *= m;
		h *= m;
		h ^= k;
		data += 4;
		len -= 4;
	}
	return (mur_switch(h, data, len, m));
}

int	ft_hash(t_data *data, char *key)
{
	int	len;

	len = sub_strlen(key, data->separator, EXCLUDE);
	return (ft_abs(murmurhash2(key, len, SEED)) % data->hash_size + 1);
}
