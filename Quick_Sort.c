#include<stdio.h>

void quick(int [], int, int);
int partition(int [], int, int);

int main()
{
	int n, i;

	printf("\n How many elements want to insert : ");
        scanf("%d",&n);
        int arr[n];
        printf("\n Enter array elements : ");
        for(i=0;i<n;i++)
        {       scanf("%d",&arr[i]);    }
        
        quick(arr,0,n-1);
        
        for(i=0;i<n;i++)
        {       printf("%d",arr[i]);    }
 
        return 0;       
}

int partition(int arr[], int left, int right)
        {
                int pivotpt = (left+right)/2;
                int pivot = arr[pivotpt];
                
                swap(&arr[pivotpt], &arr[right]);
                pivotpt = right;
                
                int i = left;
                int j = right-1;
                
                while(i<j)
                {
                        while(i< right-1 && arr[i]<pivot)
                                i++;
                        
                        while(j > 0 && arr[j]>pivot)
                                j--;
                        
                        if(i<j)
                                swap(&arr[i++], &arr[j--]);
                }
                if(i==j && arr[i] < arr[pivotpt])
                        i++;

                swap(&arr[i], &arr[pivotpt]);
                
                return i;
}        

void swap(int *a,int *b)
{
        int t;
        t=*a;
        *a=*b;
        *b=t;
}


void quick(int arr[], int left, int right)
{
        int p;
        
        if(left<right)
        {
                p=partition(arr, left, right);
                quick(arr, left, p-1);
                quick(arr, p+1, right);
        }
}
