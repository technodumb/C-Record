#include<stdio.h>

int array1[100], array2[100], array3[100],n;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[100],int lb,int ub){
    int pivot = array[lb], start=lb, end=ub;
    while(start<end){
        while(array[start]<=pivot)
            start++;
        while(array[end]>pivot)
            end--;
        if(start<end)
            swap(&array[start],&array[end]);
    }
    swap(&array[lb],&array[end]);
    return end;
}

int QuickSort(int array[100],int lb,int ub){
    if(lb<ub){
        int loc = partition(array,lb,ub);
        QuickSort(array,lb,loc-1);
        QuickSort(array,loc+1,ub);
    }
}

void merge(int array[100],int lb,int mid,int ub){
    int temp[100];
    int i,j,k;
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub)
        if(array[i]<array[j])
            temp[k++]=array[i++];
        else
            temp[k++]=array[j++];

    while(i<=mid)
        temp[k++]=array[i++];
    
    while(j<=ub)
        temp[k++]=array[j++];

    for(int i=lb;i<=ub;i++){
        array[i]=temp[i];
    }
}

void mergeSort(int array[100],int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(array,lb,mid);
        mergeSort(array,mid+1,ub);
        merge(array,lb,mid,ub);
    }
}

void heapify(int a[], int n, int i)  
{  
    int largest = i; // Initialize largest as root  
    int left = 2 * i; // left child  
    int right = 2 * i + 1; // right child  
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  
        largest = left;  
    // If right child is larger than root  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        swap(&a[i], &a[largest]);
          
        heapify(a, n, largest);  
    }  
}    
void heapSort(int a[], int n)  
{  
    for (int i = n / 2 + 1; i >= 0; i--)  
        heapify(a, n, i);  
    // One by one extract an element from heap  
    for (int i = n - 1; i >= 0; i--) {  
        swap(&a[0], &a[i]); 
          
        heapify(a, i, 0);  
    }  
}  


void printArr()  
{  
    printf("Array 1:\n\t");
    for (int i = 0; i < n; ++i) {  
        printf("%d", array1[i]);  
        printf(" ");  
    }  

    printf("\n\nArray 2:\n\t");
    for(int i = 0; i < n; ++i) {  
        printf("%d", array2[i]);  
        printf(" ");  
    }

    printf("\n\nArray 3:\n\t");
    for(int i = 0; i < n; ++i) {  
        printf("%d", array3[i]);  
        printf(" ");  
    }
          
}

void main()
{
    int i;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    printf("Enter the numbers: \n");
    for(i=0;i<n;i++) {
        scanf("%d",&array1[i]);
        array3[i] = array2[i] = array1[i];
        // printf(array3[i]);
    }
    printf("\n\nElements of the arrays: \n");
    printArr();
    int choice = 0;
    do {
        printf("\n\n\t\tMENU\n1.Quick Sort\n2.Merge Sort\n3.Heap Sort\n4.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            QuickSort(array1,0,n-1);
            printArr();
            break;
        case 2:
            mergeSort(array2,0,n-1);
            printArr();
            break;
        case 3:
            heapSort(array3,n);
            printArr();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while(choice !=4 );
}