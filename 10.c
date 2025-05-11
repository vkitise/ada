#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionSort(int a[],int n){
int i,j,min,t;
for(i=0;i<n-1;i++){
min=i;
for(j=i+1;j<n;j++)
if(a[j]<a[min])min=j;
t=a[min];a[min]=a[i];a[i]=t;
}
}
int getRandom(){return rand()%1000;}
int main(){
int n=6000,*a=malloc(n*sizeof(int));
srand(time(NULL));
printf("Random numbers for n=%d:\n",n);
for(int i=0;i<n;i++){a[i]=getRandom();printf("%d ",a[i]);}
clock_t s=clock();
selectionSort(a,n);
clock_t e=clock();
double t=(double)(e-s)/CLOCKS_PER_SEC;
printf("\n\nTime taken to sort for n=%d: %lf seconds\n\n",n,t);
printf("Sorted numbers for n=%d:\n",n);
for(int i=0;i<n;i++)printf("%d",a[i]);
printf("\n\n");
free(a);
return 0;
}
