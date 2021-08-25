#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// FCFS Algorithm

struct fcfs {
    int process;
    int burst;
    int arrival;
    int turnaround;
    int waiting;
};

typedef struct fcfs FCFS;

// Selection sort
void sort(FCFS arr[], int n) {
    int i, j, min_idx;
    FCFS temp;

    for(i = 0; i < n - 1; ++i) {
        min_idx = i;

        for(j = i+1; j < n; ++j) {
            if(arr[j].arrival < arr[min_idx].arrival)
                min_idx = j;
        }

        // Swapping
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
} 

int main() {
    int n, temp = 0, AvTAT = 0, AvWT = 0;
    int *tct;
    FCFS *arr;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Creating arrays
    arr = (FCFS*)malloc(n * sizeof(FCFS));
    tct = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; ++i) {
        arr[i].process = i;
        printf("Enter the process %d data\n", arr[i].process);
        printf("Enter CPU Burst: ");
        scanf("%d", &(arr[i].burst));
        printf("Enter the arrival time: ");
        scanf("%d", &(arr[i].arrival));
    }

    // Sorting processes based on arrival time
    sort(arr, n);

    // Calculation of turnaround time, waiting time and completion time
    printf ("Process\t\tBurst Time\tArrival Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for(int i = 0; i < n; ++i) {
        if(i >= 1 && arr[i].arrival > tct[i-1]) {
            tct[i] = temp + arr[i].burst + (arr[i].arrival - tct[i-1]);
            temp = tct[i];
        }
        else {
            tct[i] = temp + arr[i].burst;
            temp = tct[i];
        }

        arr[i].turnaround = tct[i] - arr[i].arrival;
        arr[i].waiting = arr[i].turnaround - arr[i].burst;

        AvTAT = AvTAT + arr[i].turnaround;
        AvWT = AvWT + arr[i].waiting;

        printf ("%5d\t%15d\t\t%9d\t%12d\t%12d\t%12d\n", 
            arr[i].process, arr[i].burst, arr[i].arrival, tct[i], arr[i].turnaround, arr[i].waiting
        );
    }

    printf ("Average Turn Around Time: %f ms\nAverage Waiting Time: %f ms\n", (float)AvTAT / n, (float)AvWT / n);
    
    free(arr);
    free(tct);
    return 0;
}