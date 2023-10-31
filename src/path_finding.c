#include "path_finding.h"
#include <stdio.h>

int shortest_path(char **maze, int *visited, size_t w, size_t h, int x, int y) {
  /* check if position is out of bounds */
  if (x >= w || x < 0 || y >= h || y < 0)
    return -1;

  /* check if field has been visited */
  if (visited[w * y + x])
    return -1;

  visited[w * y + x] = 1;

  if (maze[y][x] == '#')
    return -1;

  if (maze[y][x] == 'E') {
    return 0;
  }

  int res = -1;
  int res_tmp = shortest_path(maze, visited, w, h, x + 1, y);
  if ((res_tmp >= 0 && res > res_tmp) || res == -1) {
    res = res_tmp;
  }
  res_tmp = shortest_path(maze, visited, w, h, x - 1, y);
  if ((res_tmp >= 0 && res > res_tmp) || res == -1) {
    res = res_tmp;
  }
  res_tmp = shortest_path(maze, visited, w, h, x, y + 1);
  if ((res_tmp >= 0 && res > res_tmp) || res == -1) {
    res = res_tmp;
  }
  res_tmp = shortest_path(maze, visited, w, h, x, y - 1);
  if ((res_tmp >= 0 && res > res_tmp) || res == -1) {
    res = res_tmp;
  }

  return res < 0 ? -1 : res + 1;
}

int find_path(char **maze, size_t w, size_t h) {
  /* visited array */
  /* putting 1 in array's cell at specified coordinates means cell has been
   * visited */
  int *visited = calloc(w * h, sizeof(int));

  /* find start */
  int x, y;
  for (int i = 0; i < w * h; i++) {
    if (maze[i / w][i % w] == 'S') {
      x = i % w;
      y = i / w;
    }
  }

  /* start recursion */
  return shortest_path(maze, visited, w, h, x, y);
}
