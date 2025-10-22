//
//  Knight.h
//  Knights-tour
//
//  Created by noah helweg on 17/10/2025.
//
// this header will include the function for the knights possible moves:

#ifndef Knight_H
#define Knight_H
#define i 8 // board size


// checks if the move is legal
int isValid(int x, int y, int val[i][i]) {
    return (x >= 0 && x < i && y >= 0 && y < i &&
            val[x][y] == -1);
}

// the function that prints the solution matrix

void printmatrix(int val[i][i]) {
    for (int x = 0; x < i; x++) {
        for (int y = 0; y < i; y++)
            printf(" %d ", val[x][y]);
        printf("\n");
    }
}

// function that will build a valid tour for the knight

int solveKnightTour(int x, int y, int move, int valid[i][i], int xmove[i], int ymove[i])
{
    int k;
    int xnext;
    int ynext;
    
    if (move == i * i)
        return 1;
    
    // tries all the possibel moves from the knights current position
    for (k = 0; k < 8; k++) {
        xnext = x + xmove[k];
        ynext = y + ymove[k];
        if (isValid(xnext, ynext, valid)) {
            valid[xnext][ynext] = move;
            if (solveKnightTour(xnext, ynext, move + 1, valid, xmove, ymove) == 1)
                return 1;
            else // takes the knight back when it has run out of moves
                valid[xnext][ynext] = -1;
        }
    }
    return 0;
}

// this function wil be solving the problem using the solveKT function
// it will do so via backtracking
int KnightTour() {
    int valid[i][i];
    
    // sets up a solution
    for (int x = 0; x < i; x++)
        for (int y = 0; y < i; y++)
            valid[x][y] = -1;
    
    // xnext and ynext defines the next moves of the knight
    // xnext is for the x codinats
    // ynext is for the y cordinats
    
    int xMove[8] = {2,1,-1,-2,-2,-1,1,2};
    int yMove[8] = {1,2,2,1,-1,-2,-2,-1};
    
    // declaring the starting position of the knight
    valid[0][0] = 0;
    
    // starting in 0,0 it tries all the moves
    if (solveKnightTour(0,0,1, valid, xMove, yMove) == 0) {
        return 0;
    } else
        printmatrix(valid);
    return 1;
}


#endif
