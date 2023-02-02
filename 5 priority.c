#include <stdio.h>

#define MAX_PROCESSES 100

struct Process {
  int pid;
  int burst_time;
  int priority;
};

int main() {
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);
  
  struct Process processes[MAX_PROCESSES];
  
  for (int i = 0; i < n; i++) {
    printf("Enter burst time for process %d: ", i + 1);
    scanf("%d", &processes[i].burst_time);
    printf("Enter priority for process %d: ", i + 1);
    scanf("%d", &processes[i].priority);
    processes[i].pid = i + 1;
  }
  
  int total_waiting_time = 0;
  
  printf("\nProcess\tBurst Time\tPriority\tWaiting Time\n");
  for (int i = 0; i < n; i++) {
    int waiting_time = 0;
    int highest_priority_index = i;
    for (int j = i; j < n; j++) {
      if (processes[j].priority < processes[highest_priority_index].priority) {
        highest_priority_index = j;
      }
    }
    struct Process temp = processes[i];
    processes[i] = processes[highest_priority_index];
    processes[highest_priority_index] = temp;
    
    for (int j = 0; j < i; j++) {
      waiting_time += processes[j].burst_time;
    }
    total_waiting_time += waiting_time;
    printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, waiting_time);
  }
  
  printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
  
  return 0;
}
