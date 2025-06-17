/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_murmur_hash.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 07:33:30 by codespace         #+#    #+#             */
/*   Updated: 2025/06/17 14:44:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	_daft_hash(t_daft_list *file, char *key)
{
	int	len;

	len = sub_strlen(key, file->field_sep, EXCLUDE);
	return (murmurhash2(key, len, SEED) % (file->size + 1));
}
