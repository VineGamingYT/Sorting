#include <stdio.h>

int partition(int arr[], int st, int end){
    int idx, pivot, temp;
    idx = st-1;
    pivot = arr[end];
    for(int j=st; j<end; j++){
        if(arr[j] < pivot){
            idx++;
            temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;
        }
    }
    idx++;
    temp = arr[end];
    arr[end] = arr[idx];
    arr[idx] = temp;

    return idx;
}

void quickSort(int arr[], int st, int end){
    int pvtIdx;
    if(st < end){
        pvtIdx = partition(arr, st, end);
        quickSort(arr, st, pvtIdx-1);
        quickSort(arr, pvtIdx+1, end);
    }
}

void insertionSort(int arr[], int n){
    int curr, prev;
    for(int i=1; i<n; i++){
        curr = arr[i];
        prev = i - 1;
        while(prev>=0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void selectionSort(int arr[], int n){
    int min, temp;
    for(int i=0; i<n-1; i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubbleSort(int arr[], int n){
    int flag, temp;
    for(int i=0; i<n-1; i++){
        flag = 1;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 0;
            }
        }
        if(flag == 1){
            break;
        }
    }
}

void display(int arr[], int n){
    printf("Sorted List:\n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[20], n;

    printf("Enter size of array: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("Enter %d element: ",i+1);
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n);
    display(arr, n);


    return 0;
}