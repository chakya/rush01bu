/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwijaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:52:53 by cwijaya           #+#    #+#             */
/*   Updated: 2023/08/06 13:52:55 by cwijaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_double(int tab[4][4], int pos, int num)
{
	int i;

	i = -1;
	while (++i < pos / 4)
		if (tab[i][pos % 4] == num)
			return (1);
	i = -1;
	while (++i < pos % 4)
		if (tab[pos / 4][i] == num)
			return (1);
	return (0);
}

int check_col_up(int tab[4][4], int pos, int view[16])
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
			i++;
		}
		if (view[pos % 4] != count)
			return (1);
	}
	return (0);
}

int check_row_right(int tab[4][4], int pos, int view[16])
{
	int i;
	int max_size;
	int visible_towers;

	i = 4;
	max_size = 0;
	visible_towers = 0;
	if (pos % 4 == 3)
	{
		while (--i >= 0)
		{
			if (tab[pos / 4][i] > max_size)
			{
				max_size = tab[pos / 4][i];
				visible_towers++;
			}
		}
		if (view[12 + pos / 4] != visible_towers)
			return (1);
	}
	return (0);
}

int check_col_down(int tab[4][4], int pos, int view[16])
{
	int i;
	int max;
	int count;

	i = 3;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i >= 0)
		{
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
			i--;
		}
		if (view[4 + pos % 4] != count)
			return (1);
	}
	return (0);
}

int check_row_left(int tab[4][4], int pos, int view[16])
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (tab[pos / 4][i] > max)
			{
				max = tab[pos / 4][i];
				count++;
			}
			i++;
		}
		if (view[8 + pos / 4] != count)
			return (1);
	}
	return (0);
}

int check_case(int tab[4][4], int pos, int view[16])
{
	if (check_row_left(tab, pos, view) == 1)
		return (1);
	if (check_row_right(tab, pos, view) == 1)
		return (1);
	if (check_col_down(tab, pos, view) == 1)
		return (1);
	if (check_col_up(tab, pos, view) == 1)
		return (1);
	return (0);
}
