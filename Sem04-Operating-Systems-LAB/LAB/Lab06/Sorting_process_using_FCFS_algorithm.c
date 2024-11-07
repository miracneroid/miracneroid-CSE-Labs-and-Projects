/*Question ->
struct process{
int pid, arival _time, burst _time, waiting_time, turnaround_time;
The above structure is used to store the details of a process.
Write a program to implement Non preemptive FCFS Algorithim.
Write the code in the function read_process_values) to input the process id, arival time and burst time of each process.
Write the code in the function fcfs) to calculate waiting time and turnaround time of each process. And also display a gant chart.
*/

#include <stdio.h>

#define MAX_PROCESSES 10

struct process {
    int pid, arrival_time, burst_time, waiting_time, turnaround_time;
};

void read_process_values(struct process proc[], int n) {
    printf("Enter process details:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Enter process ID: ");
        scanf("%d", &proc[i].pid);
        printf("Enter arrival time: ");
        scanf("%d", &proc[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &proc[i].burst_time);
    }
}

void fcfs(struct process proc[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;

    printf("\nGantt Chart:\n");
    printf("|");
    for (int i = 0; i < n; i++) {
        printf(" P%d |", proc[i].pid);
        current_time += proc[i].burst_time;
        proc[i].turnaround_time = current_time - proc[i].arrival_time;
        proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }
    printf("\n");

    printf("\nProcess Details:\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival_time,
               proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    struct process proc[MAX_PROCESSES];
    int num_processes;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    read_process_values(proc, num_processes);
    fcfs(proc, num_processes);

    return 0;
}
