#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

int mouve();
void drow(int x, int y, int z, int x2, int y2, int z2, int score_1, int score_2,
          int ball_pos_x, int ball_pos_y);
int ball_mouve_x(int ball_pos_x, int round);
void ball_mouve_y(int *ball_pos_y, int round2, int *check);
void checkGoal(int *ball_pos_x, int *ball_pos_y, int *x, int *y, int *z,
               int *x2, int *y2, int *z2, int *score_1, int *round, int *round2,
               int *score_2, int *flag);
void checkWin(int score_1, int score_2);
void checkMouve(int move, int *x, int *y, int *z, int *x2, int *y2, int *z2);

int main() {
  int check = 1;
  int round = 1;
  int round2 = 1;
  int flag = 0;
  int ball_pos_x = 40;
  int ball_pos_y = 12;
  int move = 0;
  int score_1 = 0;
  int score_2 = 0;
  int x, y, z, x2, y2, z2;
  x = 11;
  y = 12;
  z = 13;
  x2 = 11;
  y2 = 12;
  z2 = 13;
  initscr();
  while (flag != -1) {
    nodelay(stdscr, true);
    noecho();
    clear();
    drow(x, y, z, x2, y2, z2, score_1, score_2, ball_pos_x, ball_pos_y);
    move = mouve();
    checkMouve(move, &x, &y, &z, &x2, &y2, &z2);

    ball_pos_x = ball_mouve_x(ball_pos_x, round);
    checkGoal(&ball_pos_x, &ball_pos_y, &x, &y, &z, &x2, &y2, &z2, &score_1,
              &round, &round2, &score_2, &flag);

    ball_mouve_y(&ball_pos_y, round2, &check);
    usleep(40 * 1000);
  }
  endwin();
  checkWin(score_1, score_2);

  return 0;
}

int mouve() {
  char touch = 0;
  int flag = 0;
  touch = getch();
  switch (touch) {
  case 'a':
  case 'A':
    flag = 1;
    break;
  case 'z':
  case 'Z':
    flag = -1;
    break;
  case 'k':
  case 'K':
    flag = 2;
    break;
  case 'm':
  case 'M':
    flag = -2;
    break;
  default:
    flag = -666;
  }
  return flag;
}

void drow(int x, int y, int z, int x2, int y2, int z2, int score_1, int score_2,
          int ball_pos_x, int ball_pos_y) {
  for (int i = 0; i < 80; i++) {
    printw("-");
  }
  printw("\n");
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 80; j++) {
      if (((i == x && j == 0) || (i == x2 && j == 79)) ||
          ((i == y && j == 0) || (i == y2 && j == 79)) ||
          ((i == z && j == 0) || (i == z2 && j == 79)) ||
          ((j == 39 && (j != ball_pos_x || i != ball_pos_y)) ||
           (j == 41 && (j != ball_pos_x || i != ball_pos_y)))) {
        printw("|");
      } else {
        if (i == 3 && j == 20) {
          printw("%d", score_1 / 10);
        } else {
          if (i == 3 && j == 21) {
            printw("%d", score_1 % 10);
          } else {
            if (i == 3 && j == 60)
              printw("%d", score_2 / 10);
            else {
              if (i == 3 && j == 61) {
                printw("%d", score_2 % 10);
              } else {
                if (i == ball_pos_y && j == ball_pos_x) {
                  printw("@");
                } else {
                  printw(" ");
                }
              }
            }
          }
        }
      }
    }
    printw("\n");
  }
  for (int i = 0; i < 80; i++) {
    printw("-");
  }
  printw("\n");
}

int ball_mouve_x(int ball_pos_x, int round) {
  if (round % 2 == 0) {
    if (ball_pos_x > 0) {
      ball_pos_x--;
    }
  }

  if (round % 2 != 0) {
    if (ball_pos_x < 79) {
      ball_pos_x++;
    }
  }
  return ball_pos_x;
}

void ball_mouve_y(int *ball_pos_y, int round2, int *check) {
  if (round2 % 2 != 0) {
    *ball_pos_y = *ball_pos_y - *check;
    if (*ball_pos_y == -1) {
      *check = -*check;
      *ball_pos_y = 1;
    }
    if (*ball_pos_y == 25) {
      *check = -*check;
      *ball_pos_y = 23;
    }
  }

  if (round2 % 2 == 0) {
    *ball_pos_y = *ball_pos_y + *check;
    if (*ball_pos_y == -1) {
      *check = -*check;
      *ball_pos_y = 1;
    }
    if (*ball_pos_y == 25) {
      *check = -*check;
      *ball_pos_y = 23;
    }
  }
}
void checkGoal(int *ball_pos_x, int *ball_pos_y, int *x, int *y, int *z,
               int *x2, int *y2, int *z2, int *score_1, int *round, int *round2,
               int *score_2, int *flag) {

  if (*ball_pos_x == 79 &&
      (*ball_pos_y != *x2 && *ball_pos_y != *y2 && *ball_pos_y != *z2)) {
    (*score_1)++;
    (*round)++;
    (*round2)++;
    *x = 11;
    *y = 12;
    *z = 13;
    *x2 = 11;
    *y2 = 12;
    *z2 = 13;
    *ball_pos_x = 40;
    *ball_pos_y = 12;
  } else {
    if (*ball_pos_x == 79 &&
        (*ball_pos_y == *x2 || *ball_pos_y == *y2 || *ball_pos_y == *z2)) {
      (*round)++;
      *ball_pos_x = 77;
    }
  }

  if (*ball_pos_x == 0 &&
      (*ball_pos_y != *x && *ball_pos_y != *y && *ball_pos_y != *z)) {
    (*score_2)++;
    (*round)++;
    (*round2)++;
    *x = 11;
    *y = 12;
    *z = 13;
    *x2 = 11;
    *y2 = 12;
    *z2 = 13;
    *ball_pos_x = 40;
    *ball_pos_y = 12;
  } else {
    if (*ball_pos_x == 0 &&
        (*ball_pos_y == *x || *ball_pos_y == *y || *ball_pos_y == *z)) {
      (*round)++;
      *ball_pos_x = 1;
    }
  }

  if (*score_1 == 21 || *score_2 == 21) {
      clear();
      *flag = -1;
    }
}
void checkMouve(int move, int *x, int *y, int *z, int *x2, int *y2, int *z2) {
  if (move == 1 && *x > 0) {
    (*x)--;
    (*y)--;
    (*z)--;
  } else if (move == -1 && *z < 24) {
    (*x)++;
    (*y)++;
    (*z)++;
  } else if (move == 2 && *x2 > 0) {
    (*x2)--;
    (*y2)--;
    (*z2)--;
  } else if (move == -2 && *z2 < 24) {
    (*x2)++;
    (*y2)++;
    (*z2)++;
  }
}

void checkWin(int score_1, int score_2) {
  if (score_1 == 21) {
    printf("\033[0d\033[2J");
    printf("WIN FIERST");
  }

  if (score_2 == 21) {
    printf("\033[0d\033[2J");
    printf("WIN SECOND");
  }
}
