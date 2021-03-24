/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:45:40 by honlee            #+#    #+#             */
/*   Updated: 2021/03/24 13:15:26 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *str_trim_free(char **tg)
{
    char    trim_value;
    char    *ret;
    int     idx1;
    int     idx2;

    if (!((*tg)[0] == ' ' || (*tg)[0] == '\'' || (*tg)[0] == '\"'))
        return (*tg);
    trim_value = (*tg)[0];
    ft_salloc((void**)&ret, 1, ft_strlen(*tg) - 1);
    idx1 = 0;
    idx2 = -1;
    while ((*tg)[++idx2] != 0)
    {
        if ((*tg)[idx2] != trim_value)
        {
            ret[idx1] = (*tg)[idx2];
            idx1++;
        }
    }
    ret[idx1] = 0;
    free(*tg);
    *tg = ret;
    return (ret);
}