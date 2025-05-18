#include <stdio.h>
void findindegree(int a[10][10], int indegree[10], int n) {
int i, j, sum;
for (j = 1; j <= n; j++) {
sum = 0;
for (i = 1; i <= n; i++) {
sum += a[i][j];
}
indegree[j] = sum;
}
}
void topological(int n, int a[10][10]) {
int k = 1, top = -1, u, v;
int t[100], stack[20], indegree[20];
findindegree(a, indegree, n);
for (int i = 1; i <= n; i++) {
if (indegree[i] == 0) {
stack[++top] = i;
}
}
while (top != -1) {
u = stack[top--];
t[k++] = u;
for (v = 1; v <= n; v++) {
if (a[u][v] == 1) {
indegree[v]--;
if (indegree[v] == 0) {
stack[++top] = v;
}
}
}
}
printf("\nTopological sequence is\n");
for (int i = 1; i <= n; i++) {
printf("%d\t", t[i]);
}
printf("\n");
}
int main() {
int a[10][10], n;
printf("Enter the number of nodes: ");
scanf("%d", &n);
printf("\nEnter the adjacency matrix\n");
for (int i = 1; i <= n; i++)
for (int j = 1; j <= n; j++)
scanf("%d", &a[i][j]);
printf("\nThe adjacency matrix is:\n");
for (int i = 1; i <= n; i++) {
for (int j = 1; j <= n; j++)
printf("%d\t", a[i][j]);
printf("\n");
}
topological(n, a);
return 0;
}
