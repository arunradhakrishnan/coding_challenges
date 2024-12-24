#include <iostream>
#include <semaphore.h>
#include <unistd.h>   // for fork() and sleep()
#include <sys/wait.h> // for wait()
#include <fcntl.h>    // for O_CREAT, O_EXCL

using namespace std
// Function that simulates work done by each process
void worker(sem_t *semaphore, int process_id) {
    cout << "Process " << process_id << " is waiting to acquire the semaphore...\n";
    sem_wait(semaphore);  // Acquire the semaphore (decrements the value)
    cout << "Process " << process_id << " has acquired the semaphore.\n";
    
    sleep(2);  // Simulate work
    
    cout << "Process " << process_id << " is releasing the semaphore.\n";
    sem_post(semaphore);  // Release the semaphore (increments the value)
}

int main() {
    // Create a named semaphore with an initial value of 1 (only one process can hold it at a time)
    sem_t *semaphore = sem_open("/my_semaphore", O_CREAT, 0644, 5);

    if (semaphore == SEM_FAILED) {
        cerr << "Failed to create semaphore.\n";
        return 1;
    }
    const int NUM_PROCESSES = 5;
    pid_t pids[NUM_PROCESSES];  // Array to store process IDs

    // Create multiple processes
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        pid_t pid = fork();
        if (pid < 0) {
            std::cerr << "Fork failed.\n";
            return 1;
        } else if (pid == 0) {
            // Child process
            worker(semaphore, i + 1);
            return 0;  // Child process exits after finishing its work
        } else {
            // Parent process stores the child PID
            pids[i] = pid;
        }
    }



    // Close and unlink the semaphore
    sem_close(semaphore);
    sem_unlink("/my_semaphore");  // Remove the semaphore from the system

    return 0;
}
