#include <criterion/criterion.h>

#include "../src/path_finding.h"

Test(path_finding, should_find_path_in_simple_maze) {
  size_t h = 3;
  size_t w = 9;
  char **maze = malloc(sizeof(char *) * h);
  for (int i = 0; i < h; i++) {
    maze[i] = malloc(sizeof(char) * w);
  }
  memcpy(maze[0], "#######E#", w);
  memcpy(maze[1], "#       #", w);
  memcpy(maze[2], "#S#######", w);

  cr_expect(find_path(maze, w, h) == 8);
}

Test(path_finding, should_find_path_in_more_complex_maze) {
  size_t h = 5;
  size_t w = 12;
  char **maze = malloc(sizeof(char *) * h);
  for (int i = 0; i < h; i++) {
    maze[i] = malloc(sizeof(char) * w);
  }
  memcpy(maze[0], "#######E####", w);
  memcpy(maze[1], "#   #      #", w);
  memcpy(maze[2], "# # ###### #", w);
  memcpy(maze[3], "# #        #", w);
  memcpy(maze[4], "#S##########", w);

  cr_expect(find_path(maze, w, h) == 20);
}
