#include <stdbool.h>
#include <stdio.h>
#define M   12
#define N   15
#define MAX_STACK_SIZE 100
#define EXIT_ROW 12
#define EXIT_COL 15
#define true 1
#define false 0

bool maze[M+2][N+2] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
                        {1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
                        {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1},
                        {1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1},
                        {1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1},
                        {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
                        {1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
                        {1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
                        {1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

bool mark[M + 2][N + 2] = { false, };

typedef struct _offset {
    char name[3];
    short int vert;
    short int horiz;
} offset;

typedef enum direction { North = 0, NorthEast, East, SouthEast, South, SouthWest, West, NorthWest } direction;

const offset move[8] = {
    [North] = {" N", -1,  0 },
    [NorthEast] = {"NE", -1,  1 },
    [East] = {" E",  0,  1 },
    [SouthEast] = {"SE",  1,  1 },
    [South] = {" S",  1,  0 },
    [SouthWest] = {"SW",  1, -1 },
    [West] = {" W",  0, -1 },
    [NorthWest] = {"NW", -1, -1 }
};

typedef struct _element {
    short int row;
    short int col;
    direction dir;
} element;

element stack[MAX_STACK_SIZE];

int top = -1;

void printStack() {
    for (int i = top; i >= 0; i--) {
        printf("[Row %2d Col %2d Dir %s ]\n", stack[i].row, stack[i].col, move[stack[i].dir].name);
    }
}

void printStackRev() {
    for (int i = 0; i <= top; i++) {
        printf("[Row %2d Col %2d Dir %s ]\n", stack[i].row, stack[i].col, move[stack[i].dir].name);
    }
}

void push(element position); element pop();

void path(void)
{
    int i, row, col, nextRow, nextCol, dir, found = false;
    element position;
    mark[1][1] = 1;
    top = 0;
    stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;

    while (top > -1 && !found) {
        position = pop();
        row = position.row; col = position.col; dir = position.dir;

        while (dir < 8 && !found) {
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;

            if (nextRow == EXIT_ROW-1 && nextCol == EXIT_COL-1) {
                found = true;
            }
            else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
                mark[nextRow][nextCol] = 1;
                position.row = row; position.col = col; position.dir = dir++;
                push(position);
                row = nextRow; col = nextCol; dir = 0;
            }
            else ++dir;
        }
    }

    if (found) {
        printf("The path is:\n");
        printStackRev();
    }
    else
        printf("The maze does not have a path\n");
}

element pop() {

    if (top < 0) {

        element pop;

        pop.col = 0; pop.row = 0; pop.dir = 0;

        return pop;

    }
    return stack[(top)--];
}

void IsFull() {
    printf("stack is full");
    return;
}

void push(element position) {

    if (top > MAX_STACK_SIZE - 1) {
        IsFull();
        return;
    }
    stack[++(top)] = position;
    return;
}

int main() {
    path(&top);

    return 0;
}