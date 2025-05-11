#include <stdio.h>
#define N 4
int board[N];
int isSafe(int row, int col) {
for (int i = 0; i < row; i++) {
if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
return 0;
}
return 1;
}
int solve(int row) {
if (row == N) {
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
if (board[i] == j) printf("Q ");
else printf("- ");
}
printf("\n");
}
printf("\n");
return 1;
}
for (int col = 0; col < N; col++) {
if (isSafe(row, col)) {
board[row] = col;
if (solve(row + 1))
return 1;
board[row] = -1;
}
}
return 0;
}
int main() {
if (!solve(0)) {
printf("No solution exists for N = %d\n", N);
}
return 0;
}
