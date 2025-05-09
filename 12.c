#include <stdio.h>
#include <stdbool.h>
#define N 4
void printSolution(char board[N][N]) {
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
printf("%c ", board[i][j]);
}
printf("\n");
}
}
bool isSafe(char board[N][N], int row, int col) {
for (int i = 0; i < row; i++) {
if (board[i][col] == 'Q')
return false;
}
for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
if (board[i][j] == 'Q')
return false;
}
for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
if (board[i][j] == 'Q')
return false;
}
return true;
}
bool solveNQUtil(char board[N][N], int row) {
if (row == N)
return true;
for (int col = 0; col < N; col++) {
if (isSafe(board, row, col)) {
board[row][col] = 'Q';
if (solveNQUtil(board, row + 1))
return true;
board[row][col] = '-'; 
}
}
return false;
}
void solve4Queens() {
char board[N][N];
for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
board[i][j] = '-';
if (!solveNQUtil(board, 0)) {
printf("Solution does not exist\n");
return;
}
printSolution(board);
}
int main() {
printf("Solution for 4 Queens problem:\n");
solve4Queens();
return 0;
}
