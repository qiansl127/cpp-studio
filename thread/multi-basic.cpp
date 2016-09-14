// g++ -pthread ...

extern "C" {
  #include <pthread.h>
  #include <unistd.h>
}
#include <iostream>

using namespace std;

pthread_mutex_t mutex_for_some_value = PTHREAD_MUTEX_INITIALIZER;

void *func(void *arg);

int main() {
  pthread_t t1, t2;
  string msg1("Hello");
  string msg2("World");
  pthread_create(&t1, NULL, func, static_cast<void*>(&msg1));
  pthread_create(&t2, NULL, func, static_cast<void*>(&msg2));

  // pthread_exit(NULL);
  // Prevent termination of the program until all threads are terminated

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  // join differs from exit, it keeps main alive

  return 0;
}

void *func(void *arg) {
  pthread_mutex_lock(&mutex_for_some_value);
  cout << *(static_cast<string*>(arg)) << endl;
  pthread_mutex_unlock(&mutex_for_some_value);
  sleep(2);
  return 0;
}

