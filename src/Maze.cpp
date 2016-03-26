int path_exists_recursion(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (x1 == x2&&y1 == y2){
		if (*((maze + x2*columns) + y2) == 1)
			return 1;
		else
			return 0;
	}
	if (*((maze + x1*columns) + y1) == 1 && x1 <rows && y1 < columns){
		if (*((maze + x1*columns) + (y1 + 1)) == 1 && (y1 + 1)<columns)
			return path_exists_recursion(maze, rows, columns, x1, y1 + 1, x2, y2);
		if (*((maze + (x1 + 1)*columns) + y1) == 1 && (x1 + 1)<rows)
			return path_exists_recursion(maze, rows, columns, x1 + 1, y1, x2, y2);
		if (*((maze + (x1 - 1)*columns) + y1) == 1 && (x1 - 1) >= 0 && (x1 - 1) >= x2)
			return path_exists_recursion(maze, rows, columns, x1 - 1, y1, x2, y2);
		else
			return 0;
	}

}
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int i;
	if (rows <= 0 || columns <= 0 || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || y1 >= columns || y2 >= columns)
		return 0;
	if (*((maze + x2*columns) + y2) == 1)
		return path_exists_recursion(maze, rows, columns, x1, y1, x2, y2);

	return 0;
}
