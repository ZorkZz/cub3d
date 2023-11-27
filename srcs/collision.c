#include "../headers/cub3d.h"

static int	circle_square(float cx, float cy, int rx, int ry)
{
	float	edgex;
	float	edgey;
	float	dist;

	edgex = cx;
	edgey = cy;
	if (cx < rx)
		edgex = rx;
	else if (cx > rx + 1)
		edgex = rx + 1;
	if (cy < ry)
		edgey = ry;
	else if (cy > ry + 1)
		edgey = ry + 1;
	dist = sqrt(pow(cx - edgex, 2) + pow(cy - edgey, 2));
	return (dist <= PLAYER_SIZE);
}

int	can_moov(char **map, float x, float y)
{
    int row;
    int	col;
    int i;
    int j;

    i = -1;
    while (i <= 1)
    {
        j = -1;
        while (j <= 1)
        {
			row = round(x) + i;
			col = round(y) + j;
			if (row >= 0 && row < ft_strslen(map) && col >= 0 && (float)col < ft_strlen(map[(int) x]))
			{
				if (map[row][col] == '1' || map[row][col] == ' ' || map[row][col] == ' ')
					if (circle_square(x, y, row, col) == 1)
						return (0);
			}
            j++;
		}
        i++;
	}
	return (1);
}
