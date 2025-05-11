#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int* a,int* b){int t=*a;*a=*b;*b=t;}
int partition(int a[],int l,int h){
int p=a[h],i=l-1;
for(int j=l;j<h;j++)if(a[j]<p)swap(&a[++i],&a[j]);
swap(&a[i+1],&a[h]);
return i+1;
}
void quickSort(int a[],int l,int h){
if(l<h){
int pi=partition(a,l,h);
quickSort(a,l,pi-1);
quickSort(a,pi+1,h);
}
}
int getRandom(){return rand()%1000;}
int main(){
int n=6000,*a=malloc(n*sizeof(int));
srand(time(NULL));
printf("Random numbers for n=%d:\n",n);
for(int i=0;i<n;i++){a[i]=getRandom();printf("%d ",a[i]);}
clock_t s=clock();
quickSort(a,0,n-1);
clock_t e=clock();
double t=(double)(e-s)/CLOCKS_PER_SEC;
printf("\n\nTime taken to sort for n=%d: %lf seconds\n\n",n,t);
printf("Sorted numbers for n=%d:\n",n);
for(int i=0;i<n;i++)printf("%d",a[i]);
printf("\n\n");
free(a);
return 0;
}
