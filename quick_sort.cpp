#include<iostream>
#include<stdlib.h>
using namespace std;
int o=0;
int z=0;
int m=0;
int no;
 int seed;
void swap(int *i,int *j)
{
   int temp=*i;
   *i=*j;
   *j=temp;
}

int swap1(int arr[],int i,int j)
{
    arr[i]=arr[i]^arr[j];
    arr[j]=arr[i]^arr[j];
    arr[i]=arr[i]^arr[j];
}
int partition(int arr[],int l,int h)
{
    o++;
    srand(NULL);
    int r=l+rand()%(h-l);
    int pivot=arr[r];
    cout<<"\nAfter"<<o<<"partition pivot is"<<pivot<<endl;
    int i=l-1;

    for(int j=l;j<=h;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            if(i!=j)
            swap1(arr,i,j);
            else
                swap(&arr[i],&arr[j]);
        }
    }
for(int p=0;p<no-1;p++){
    if(arr[p]==pivot)
    swap(&arr[i+1],&arr[p]);
}
    for(int y=0;y<no;y++)
    cout<<arr[y]<<"\t";

 return i+1;

}

int partition1(int arr[],int l,int h)
{
    z++;
    int pivot=arr[h];
    cout<<"\nAfter"<<z<<"partition pivot is"<<pivot<<endl;
    int i=l-1;

    for(int j=l;j<=h;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            if(i!=j)
            swap1(arr,i,j);
            else
                swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[h]);

    for(int y=0;y<no;y++)
    cout<<arr[y]<<"\t";

 return i+1;

}

void quick_sort(int arr[],int l,int h)
{
 if(l<h){
 int p=partition(arr,l,h);
 quick_sort(arr,l,p-1);
 quick_sort(arr,p+1,h);
 }
}

void quick_sort1(int arr[],int l,int h)
{
 if(l<h){
 int p=partition1(arr,l,h);
 quick_sort1(arr,l,p-1);
 quick_sort1(arr,p+1,h);
 }
}

int partition2(int arr[],int l,int h)
{
    m++;
    int pivot=arr[l];
    cout<<"\nAfter"<<m<<"partition pivot is"<<pivot<<endl;
    int i=l-1;

    for(int j=l+11;j<=h;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            if(i!=j)
            swap1(arr,i,j);
            else
                swap(&arr[i],&arr[j]);
        }
    }
  for(int y=0;y<no;y++){
        if(arr[y]==pivot)
    swap(&arr[i+1],&arr[y]);
  }
    for(int y=0;y<no;y++)
    cout<<arr[y]<<"\t";

 return i+1;


}

void quick_sort2(int arr[],int l,int h)
{
 if(l<h){
 int p=partition2(arr,l,h);
 quick_sort2(arr,l,p-1);
 quick_sort2(arr,p+1,h);
 }
}




int main()
{

    cout<<"Enter the no of elements in an array"<<endl;
    cin>>no;
    int *arr=new int[no];

    cout<<"\nEnter the values of seed"<<endl;
    cin>>seed;
    srand(seed);
    for(int i=0;i<no;i++)
        arr[i]=1+rand()%100;
    cout<<"Array is";
    for(int i=0;i<no;i++)
    cout<<arr[i]<<"\t";
    quick_sort(arr,0,no-1);

    cout<<"\n";
    quick_sort1(arr,0,no-1);
   quick_sort2(arr,0,no-1);

    cout<<"partitions of randomized quick_sort is"<<o<<endl;
    cout<<"partitions of last element pivot in quick_sort is"<<z<<endl;
     cout<<"partitions of first element quick_sort is"<<m<<endl;

    return 0;
}
