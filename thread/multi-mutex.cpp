// g++ -pthread ...
// This file introduce mutex and condition

extern "C" {
  #include <pthread.h>
}
#include <iostream>

using namespace std;

pthread_mutex_t count_var_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

void *func1(void *args);
void *func2(void *args);

int count_var = 0;
const int COUNT_DONE = 10;

int main() {
  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, &func1, NULL);
  pthread_create(&thread2, NULL, &func2, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}

void *func1(void *args) {
  while (true) {
    pthread_mutex_lock(&count_var_mutex);

    pthread_cond_wait(&condition_var, &count_var_mutex);

    cout << "function1 looks at count_var (" << count_var << ") and just adds 1 to it." << endl;
    count_var++;

    pthread_mutex_unlock(&count_var_mutex);

    if (count_var > COUNT_DONE) pthread_exit(NULL);
  }
}

void *func2(void *args) {
  while (true) {
    pthread_mutex_lock(&count_var_mutex);
    
    if (count_var & 1) {
      cout << "function2 detected count_var (" << count_var << ") is odd, so it adds 1 to it." << endl;
      count_var++;
    } else {
      pthread_cond_signal(&condition_var);
    }
    pthread_mutex_unlock(&count_var_mutex);

    if (count_var > COUNT_DONE) pthread_exit(NULL);
  }
}
