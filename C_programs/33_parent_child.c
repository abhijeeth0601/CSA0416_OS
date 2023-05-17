#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int is_prime(int num) {
    if (num <= 1)
        return 0;
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    
    return 1;
}

void fibonacci(int n) {
    int prev = 0;
    int curr = 1;
    
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", prev);
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    printf("\n");
}

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Failed to fork a child process.\n");
        return 1;
    }

    if (pid == 0) {
        // Child process
        fibonacci(10); // Generate Fibonacci series
    } else {
        // Parent process
        wait(NULL); // Wait for the child process to finish
        
        printf("Prime Numbers: ");
        for (int i = 2; i <= 20; i++) {
            if (is_prime(i))
                printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}


