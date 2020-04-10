/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 02:35:07 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/17 02:35:08 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			check_valid_token_4(int code, char *tmp)
{
	if (code == 4)
	{
		if (*tmp == '-' || ft_isdigit(*tmp))
		{
			if (*tmp == '-')
				tmp++;
			while (*tmp)
			{
				if (!ft_isdigit(*tmp))
					return (0);
				tmp++;
			}
			return (1);
		}
	}
	return (0);
}

static int			check_valid_token_3(int code, char *tmp)
{
	if (code == 3)
	{
		if (label_char_correct(*tmp))
		{
			while (*tmp)
			{
				if (!label_char_correct(*tmp))
					return (0);
				tmp++;
			}
			return (1);
		}
	}
	else if (check_valid_token_4(code, tmp) == 1)
		return (1);
	return (0);
}

static int			check_valid_token_2(int code, char *tmp)
{
	if (code == 2)
	{
		if (*tmp == DIRECT_CHAR && (ft_isdigit(*(tmp + 1)) ||
			(*(tmp + 1) == '-' && ft_isdigit(*(tmp + 2)))))
		{
			while (!ft_isdigit(*tmp))
				tmp++;
			while (*tmp)
			{
				if (!ft_isdigit(*tmp))
					return (0);
				tmp++;
			}
			return (1);
		}
	}
	else if (check_valid_token_3(code, tmp) == 1)
		return (1);
	return (0);
}

static int			check_valid_token_1(int code, char *tmp)
{
	if (code == 1)
	{
		if (label_char_correct(*tmp))
		{
			tmp++;
			while (*tmp)
			{
				if (!label_char_correct(*tmp))
					return (0);
				tmp++;
			}
			return (1);
		}
	}
	else if (check_valid_token_2(code, tmp) == 1)
		return (1);
	return (0);
}

int					check_valid_token(t_token_node *token, int code)
{
	char			*tmp;

	tmp = token->content;
	code += 0;
	if (code == 0)
	{
		if (*tmp == REGISTER_CHAR && ft_isdigit(*(tmp + 1)))
		{
			tmp++;
			while (*tmp)
			{
				if (!ft_isdigit(*tmp))
					return (0);
				++tmp;
			}
			return (1);
		}
	}
	else if (check_valid_token_1(code, tmp) == 1)
		return (1);
	return (0);
}
