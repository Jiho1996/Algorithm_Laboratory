
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<time.h>
int heapsize;
int swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;
    double sorted[21000];
   
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // 남아 있는 값들을 일괄 복사
    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    // 남아 있는 값들을 일괄 복사
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }

    // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}

void selectionSort(int arr[], int size) {
    int minIndex;
    int i, j;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(&arr[i], &arr[minIndex]);
    }
}
void bubblesort(int arr[], int count){ 
    int temp;
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count - 1; j++){ // 요소 개수 -1 만큼 반복
            if (arr[j] > arr[j + 1])  
            {                                 
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;           
            }
        }
    }
}

void insertionSort(int arr[], int size) {
    int i, j;
    double temp;
    //인덱스 0은 이미 정렬된 것으로 본다.
    for (i = 1; i < size; i++) {
        temp = arr[i];
        
        for (j = i-1; j>=0&&arr[j]>temp;j--){
            arr[j + 1] = arr[j]; // 오른쪽으로 이동
        }
        arr[j + 1] = temp;
    }
}
void merge_sort(int list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 
        merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬
        merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 
        merge(list, left, mid, right); // 결합
    }
}

void QuickSort(int arr[], int left, int right) {
    int L = left, R = right;
    int temp;
    int pivot = arr[(left + right) / 2]; //피봇 위치(중앙)의 값

    while (L <= R) {

      
        while (arr[L] < pivot) 
            L++;
        while (arr[R] > pivot) 
            R--;
        //L, R 모두 최대 pivot 위치까지 이동.

        if (L <= R) { 
            if (L != R) { 
                temp = arr[L];
                arr[L] = arr[R];
                arr[R] = temp;
            } 
            L++; R--; 
        }
    }
    if (left < R)
        QuickSort(arr, left, R);
    if (L < right)
        QuickSort(arr, L, right);
}

void printArr(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void heapSort(int data[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int c = i;       
        do
        {
            
            int parent = (c - 1) / 2;
            //만약 부모 노드보다 자식 노드가 더 크다면 값을 바꿔준다.
            if (data[parent] < data[c])
            {
                int temp = data[parent];
                data[parent] = data[c];
                data[c] = temp;
            }
            
            c = parent;
        } while (c != 0);
    }
   
    //크기를 줄여가며 반복적으로 힙을 구성
    for (int i = size - 1; i >= 0; i--)
    {
        //가장 큰 값을 맨 뒤로 보낸다
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        int parent = 0;
        int c = 1;
      
        do
        {
            c = parent * 2 + 1;
          
            if (data[c] < data[c + 1] && c < i - 1)
            {
                c++;    
            }
            //부모보다 자식이 더 크다면 교환한다
            if (data[parent] < data[c] && c < i)
            {
                temp = data[parent];
                data[parent] = data[c];
                data[c] = temp;
            }
            parent = c;    
        } while (c < i);   
    }
}
int main() {
    LARGE_INTEGER beginTime, endTime, Frequency;
    double SelectionSort_Time, BubbleSort_Time,
        InsertionSort_Time, MergeSort_Time,
        QuickSort_Time, HeapSort_Time;
    srand(time(NULL));

    int N[20] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000,
        9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000,
        17000, 18000, 19000, 20000 };

    for (int i = 0;i < 20;i++) {
        double* Arr_set = malloc(sizeof(double) * N[i]);

        Arr_set[i] = (double)(rand() % 2001 - 1000) / 1000;

        printf("====================================================\n");
        printf("배열의 크기가 %d 일때 \n\n", N[i]);

        QueryPerformanceFrequency(&Frequency);
        QueryPerformanceCounter(&beginTime);
        selectionSort(Arr_set, N[i]);
        QueryPerformanceCounter(&endTime);
        SelectionSort_Time = (double)(endTime.QuadPart - beginTime.QuadPart) / (Frequency.QuadPart / 1000);
        printf("selection sort :%5fms\n", SelectionSort_Time);

        QueryPerformanceFrequency(&Frequency);
        QueryPerformanceCounter(&beginTime);
        bubblesort(Arr_set, N[i]);
        QueryPerformanceCounter(&endTime);
        BubbleSort_Time = (double)(endTime.QuadPart - beginTime.QuadPart) / (Frequency.QuadPart / 1000);
        printf("bubble sort :%5fms\n", BubbleSort_Time);

        QueryPerformanceFrequency(&Frequency);
        QueryPerformanceCounter(&beginTime);
        insertionSort(Arr_set, N[i]);
        QueryPerformanceCounter(&endTime);
        InsertionSort_Time = (double)(endTime.QuadPart - beginTime.QuadPart) / (Frequency.QuadPart / 1000);
        printf("Insertion sort :%5fms\n", InsertionSort_Time);

        QueryPerformanceFrequency(&Frequency);
        QueryPerformanceCounter(&beginTime);
        merge_sort(Arr_set, 0, N[i]);
        QueryPerformanceCounter(&endTime);
        MergeSort_Time = (double)(endTime.QuadPart - beginTime.QuadPart) / (Frequency.QuadPart / 1000);
        printf("merge sort :%5fms\n", MergeSort_Time);

        QueryPerformanceFrequency(&Frequency);
        QueryPerformanceCounter(&beginTime);
        QuickSort(Arr_set, 0, N[i]);
        QueryPerformanceCounter(&endTime);
        QuickSort_Time = (double)(endTime.QuadPart - beginTime.QuadPart) / (Frequency.QuadPart / 1000);
        printf("quick sort :%5fms\n", QuickSort_Time);

        QueryPerformanceFrequency(&Frequency);
        QueryPerformanceCounter(&beginTime);
        heapSort(Arr_set, N[i]);
        QueryPerformanceCounter(&endTime);
        HeapSort_Time = (double)(endTime.QuadPart - beginTime.QuadPart) / (Frequency.QuadPart / 1000);
        printf("heap sort :%5fms\n", HeapSort_Time);

    }
 

        
    int arr1[] = { 12, 70, 30, 20, 55, 25, 40, 50 };
    int arr2[] = { 12, 70, 30, 20, 55, 25, 40, 50 };
    int arr3[] = { 12, 70, 30, 20, 55, 25, 40, 50 };
    int arr4[] = { 12, 70, 30, 20, 55, 25, 40, 50 };
    int arr5[] = { 12, 70, 30, 20, 55, 25, 40, 50 };
    int arr6[] = { 12, 70, 30, 20, 55, 25, 40, 50 };
    int size = 8;

    printf("\n선택정렬 : \n");
    printArr(arr1, size);
    selectionSort(arr1, size);
    printArr(arr1, size);
    printf("\n");

    printf("\n버블정렬 : \n");
    printArr(arr2, size);
    bubblesort(arr2, size);
    printArr(arr2, size);
    printf("\n");

    printf("\n삽입정렬 : \n");
    printArr(arr3, size);
    insertionSort(arr3, size);
    printArr(arr3, size);
    printf("\n");

    printf("\n병합정렬 : \n");
    printArr(arr4, size);
    merge_sort(arr4, 0, 7);
    printArr(arr4, size);
    printf("\n");

    printf("\n퀵정렬 : \n");
    printArr(arr5, size);
    QuickSort(arr5, 0, 7);
    printArr(arr5, size);
    printf("\n");


    printf("\n힙정렬 : \n");
    printArr(arr6, size);
    heapSort(arr6, size);
    printArr(arr6, size);
    printf("\n");

   

    return 0;


}