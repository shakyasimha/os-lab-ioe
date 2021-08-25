#include <stdio.h>
#include <stdlib.h>

// SJF Scheduling

struct sjf {
    int process;
    int burst;
    int arrival;
    int turnaround;
    int waiting;
};

typedef struct sjf SJF;

// Selection sort
void sort(SJF arr[], int n) {
    int min_idx;
    SJF temp;

    for(int i = 0; i < n-1; ++i) {
        min_idx = i;
        
        for(int j = i+1; j < n; ++j) {
            if(arr[j].arrival < arr[min_idx].arrival) {
                min_idx = j;
            }
        }

        // Swapping
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}  

int main() {
    int i, j, n, TCT, count_process = 0, count = 0, minBurst, pos;
    float AvTAT = 0.0, AvWT = 0.0;
    SJF *arr;

    printf ("Enter the number of processes: ");
    scanf ("%d", &n);

    arr = (SJF*)malloc(n*sizeof(SJF));

    // Entering data of the processes
    printf ("Enter the data of processes\n");
    for (i = 0; i < n; i++)
    {
        arr[i].process = i + 1;
        printf("Enter the burst time of process %d: ", arr[i].process);
        scanf ("%d", &(arr[i].burst));
        printf ("Enter the arrival time of process %d: ", arr[i].process);
        scanf ("%d", &(arr[i].arrival));
    }

    // SJF Algorithm starts here
    sort (arr, n);

    printf ("PROCESS\tARRIVAL TIME\tBURST TIME\n");
    for(int i = 0; i < n; i++) {
        printf (
            "%3d\t%5d\t\t%5d\n", 
            arr[i].process, arr[i].arrival, arr[i].burst
        );
    }

    TCT = arr[0].turnaround = arr[0].burst;
    arr[0].waiting = arr[0].turnaround - arr[0].burst;
    arr[0].arrival = -1;

    sort(arr, n);
    count_process = 1;

    while(count_process < n) {
        minBurst = 999;
        count = 0;
        i = count_process;

        while(TCT >= arr[i].arrival && i < n) {
            ++count;
            ++i;
        }

        for(j = i - count; count != 0 && j < n; ++j, --count) {
            if(arr[j].burst < minBurst) {
                minBurst = arr[j].burst;
                pos = j;
            }
        }

        TCT = TCT + arr[pos].burst;
        arr[pos].turnaround = TCT - arr[pos].arrival;
        arr[pos].waiting = arr[pos].turnaround - arr[pos].burst;
        arr[pos].arrival = -1;
        sort(arr, n);
        ++count_process;
    }

    printf("Process\tTAT\tWT\n");
    for(i = 0; i < n; ++i) {
        printf(
            "%2d\t%2d\t%2d\n",
            arr[i].process, arr[i].turnaround, arr[i].waiting
        );
    }

    for(i = 0; i < n; ++i) {
        AvTAT = AvTAT + arr[i].turnaround;
        AvWT = AvWT + arr[i].waiting;
    }

    printf(
        "Average TAT: %.2f\nAverage WT: %.2f\n",
        AvTAT / n, AvWT / n
    );
    
    free(arr);
    return 0;
}