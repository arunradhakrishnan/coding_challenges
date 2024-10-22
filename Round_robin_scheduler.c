#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM  3

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

void roundRobinScheduler(Process processes[], int num_processes) {
    int time = 0;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > TIME_QUANTUM) {
                    time += TIME_QUANTUM;
                    processes[i].remaining_time -= TIME_QUANTUM;
                    printf("Process %d executed for %d units of time. Remaining time: %d\n",
                           processes[i].id, TIME_QUANTUM, processes[i].remaining_time);
                } else {
                    time += processes[i].remaining_time;
                    printf("Process %d executed for %d units of time and completed.\n",
                           processes[i].id, processes[i].remaining_time);
                    processes[i].remaining_time = 0;
                    completed_processes++;
                }
            }
        }
    }
    printf("All processes have been scheduled and completed by time %d.\n", time);
}

main() {
    Process processes[MAX_PROCESSES];
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    roundRobinScheduler(processes, num_processes);

    return 0;
}
