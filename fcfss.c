#include <stdio.h>
void findWaitingTime(int bt[], int wt[], int numProcesses) {
    wt[0] = 0;
    for (int i = 1; i < numProcesses; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}
void findTurnAroundTime(int bt[], int wt[], int tat[], int numProcesses) {
    for (int i = 0; i < numProcesses; i++) {
        tat[i] = bt[i] + wt[i];
    }
}
void findAvgTime(int bt[], int numProcesses) {
    int wt[numProcesses], tat[numProcesses];
    int total_wt = 0, total_tat = 0;
    findWaitingTime(bt, wt, numProcesses);
    findTurnAroundTime(bt, wt, tat, numProcesses);
    printf("Process Burst Time Waiting Time Turnaround Time\n");
    for (int i = 0; i < numProcesses; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" %d    %d    %d    %d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    float avg_wt = (float)total_wt / numProcesses;
    float avg_tat = (float)total_tat / numProcesses;
    printf("Average Waiting Time = %f\n", avg_wt);
    printf("Average Turnaround Time = %f\n", avg_tat);
}
int main() {
    int bt[] = {10, 5, 8};
    int numProcesses = sizeof(bt) / sizeof(bt[0]);
    findAvgTime(bt, numProcesses);
    return 0;
}
