#include<stdio.h>

struct process {
  int pid; 
  int priority; 
  int burst_time; 
};

void sort_by_priority(struct process *p, int n) {
  int i, j;
  struct process temp;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (p[j].priority > p[j+1].priority) {
        temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;
      }
    }
  }
}

int main() {
  int i, n, tot_burst_time = 0;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  struct process p[n];
  for (i = 0; i < n; i++) {
    p[i].pid = i+1;
    printf("Enter the priority and burst time of process %d: ", p[i].pid);
    scanf("%d%d", &p[i].priority, &p[i].burst_time);
    tot_burst_time += p[i].burst_time;
  }
  sort_by_priority(p, n);
  printf("\nProcess ID\tPriority\tBurst Time\n");
  for (i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\n", p[i].pid, p[i].priority, p[i].burst_time);
  }
  return 0;
}
