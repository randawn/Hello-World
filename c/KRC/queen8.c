#include <stdio.h>
#include <stdlib.h>
#define ROW 4
#define COL 4
#define NUM 4

int total;

typedef struct queen {
    int x;
    int y;
    int num;
} t_queen;

typedef struct node {
    int x;
    int y;
    int stat;
    int num;
} t_node;

void queens_init(t_queen *queens)
{
    int i;
    for(i=0; i<NUM; i++) {
        (queens+i)->x = -1;
        (queens+i)->y = -1;
        (queens+i)->num = i;
    }
}

void print_queens(t_queen *queens)
{
    int i;
    for(i=0; i<NUM; i++) {
        printf("queen %x\n", (queens+i)->num);
        printf("    x %x\n", (queens+i)->x);
        printf("    y %x\n", (queens+i)->y);
    }
}

void board_init(t_node *board)
{
    int i, j;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            (board+COL*i+j)->x = i;
            (board+COL*i+j)->y = j;
            (board+COL*i+j)->stat = 0;
            (board+COL*i+j)->num  = -1;
        }
    }
}

void print_board(t_node *board)
{
    int i, j;
    t_node *node;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            node = board+COL*i+j;
            if(node->num==-1) {
                putchar('0');
                putchar(' ');
            } else {
                putchar('x');
                putchar(' ');
            }
        }
        putchar('\n');
    }
    putchar('\n');
}

/*get_queen: do we have more queen?*/
bool get_queen(t_queen *queens, t_queen **queen_pp)
{
    int i;
    for(i=0; i<NUM; i++) {
        if(((queens+i)->x)<0) {
            *queen_pp = queens+i;
            return true;
        }
    }
    return false;
}

void update_board(t_node *board, t_node *node, t_queen *queen, bool stat)
{
    int i, j;
    t_node *node_int;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            node_int = board+COL*i+j;
            if((node_int->x==node->x) ||
               (node_int->y==node->y) ||
               ((node_int->x-node_int->y)==
               (node->x-node->y)) ||
               ((node_int->x+node_int->y)==
               (node->x+node->y))) {
                if(stat) {
                    node_int->stat += 1;
                } else {
                    node_int->stat -= 1;
                }
            }
        }
    }
    node_int = board+COL*(node->x)+node->y;
    if(stat) {
        node_int->num = queen->num;
    } else {
        node_int->num = -1;
    }
}

void update_queen(t_queen *queen, t_node *node, bool stat)
{
    if(stat) {
        queen->x = node->x;
        queen->y = node->y;
    } else {
        queen->x = -1;
        queen->y = -1;
    }
}

void put_queen(t_node *board, t_queen *queens, int row, int col)
{
    int i, j;
    t_queen *queen;
    t_node *node;
    if(!get_queen(queens, &queen)) {
        print_board(board);
        total++;
        return;
    }
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            node = board+COL*i+j;
            if((node->stat==0) &&
               ((i>row) )) {
                update_board(board, node, queen, true);
                update_queen(queen, node, true);
                put_queen(board, queens, node->x, node->y);
                update_board(board, node, queen, false);
                update_queen(queen, node, false);
            }
        }
    }
}

int main(int argc, char **argv)
{
    t_queen *queens = (t_queen *) malloc(NUM*sizeof(t_queen));
    t_node *board = (t_node *) malloc(ROW*COL*sizeof(t_node));
    queens_init(queens);
    board_init(board);

    put_queen(board, queens, -1, 0);

    free(queens);
    free(board);
    printf("total %d\n", total);
    return 0;
}


