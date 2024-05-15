#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4


typedef struct {
    int puzzle[N][N];
    int x, y; 
} State;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


bool isGoalState(State state) {
    int value = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (state.puzzle[i][j] != value && !(i == N - 1 && j == N - 1))
                return false;
            value++;
        }
    }
    return true;
}


void solvePuzzle(State startState) {
    
    State queue[N * N * N * N];
    int front = 0, rear = 0;
    queue[rear++] = startState;

    
    while (front < rear) {
        
        State currentState = queue[front++];
        
        if (isGoalState(currentState)) {
            printf("Solution found:\n");
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    printf("%d ", currentState.puzzle[i][j]);
                }
                printf("\n");
            }
            return;
        }
        
        int x = currentState.x, y = currentState.y;
        
        if (x > 0) {
            State newState = currentState;
            swap(&newState.puzzle[x][y], &newState.puzzle[x - 1][y]);
            newState.x = x - 1;
            queue[rear++] = newState;
        }
        if (x < N - 1) {
            State newState = currentState;
            swap(&newState.puzzle[x][y], &newState.puzzle[x + 1][y]);
            newState.x = x + 1;
            queue[rear++] = newState;
        }
        if (y > 0) {
            State newState = currentState;
            swap(&newState.puzzle[x][y], &newState.puzzle[x][y - 1]);
            newState.y = y - 1;
            queue[rear++] = newState;
        }
        if (y < N - 1) {
            State newState = currentState;
            swap(&newState.puzzle[x][y], &newState.puzzle[x][y + 1]);
            newState.y = y + 1;
            queue[rear++] = newState;
        }
    }

    printf("No solution found.\n");
}

int main() {
    
    State startState = {
        {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 0, 10, 12},
         {13, 14, 11, 15}},
        2, 1
    };

    
    solvePuzzle(startState);

    return 0;
}
