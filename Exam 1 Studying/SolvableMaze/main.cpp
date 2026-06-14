#include <iostream>
using namespace std;

bool validSpace(int x, int y, int maze[][4], int n, int m)
{
    if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] != 0)
    {
        return false;
    }
    return true;
}

bool solvableMaze(int x, int y, int maze[][4], int n, int m)
{
    if (x == n - 1 && y == m - 1)
    {
        return true;
    }
    else if (!validSpace(x, y, maze, n, m))
    {
        return false;
    }
    maze[x][y] = 1;
    return (solvableMaze(x, y + 1, maze, n, m) || solvableMaze(x + 1, y, maze, n, m) ||
            solvableMaze(x, y - 1, maze, n, m) || solvableMaze(x - 1, y, maze, n, m));
}

int main()
{

    int maze[4][4] = {
        {0, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 1, 0}};

    if (solvableMaze(0, 0, maze, 4, 4))
    {
        cout << "Maze is solvable." << endl;
    }
    else
    {
        cout << "Maze is not solvable." << endl;
    }

    return 0;
}