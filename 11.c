#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int l,int m,int r){
int n1=m-l+1,n2=r-m,L[n1],R[n2];
for(int i=0;i<n1;i++)L[i]=a[l+i];
for(int j=0;j<n2;j++)R[j]=a[m+1+j];
int i=0,j=0,k=l;
while(i<n1&&j<n2)a[k++]=(L[i]<=R[j])?L[i++]:R[j++];
while(i<n1)a[k++]=L[i++];
while(j<n2)a[k++]=R[j++];
}
void mergeSort(int a[],int l,int r){
if(l<r){
int m=(l+r)/2;
mergeSort(a,l,m);
mergeSort(a,m+1,r);
merge(a,l,m,r);
}
}
int getRandom(){return rand()%1000;}
int main(){
int n=6000,*a=malloc(n*sizeof(int));
srand(time(NULL));
printf("Random numbers for n=%d:\n",n);
for(int i=0;i<n;i++){a[i]=getRandom();printf("%d ",a[i]);}
clock_t start=clock();
mergeSort(a,0,n-1);
clock_t end=clock();
double time=(double)(end-start)/CLOCKS_PER_SEC;
printf("\n\nTimetaken tosort forn=%d: %lfseconds\n\n",n,time);
printf("Sorted numbers for n=%d:\n",n);
for(int i=0;i<n;i++)printf("%d",a[i]);
printf("\n\n");
free(a);
return 0;
}
