#include <pthread.h>
#include <stdio.h>
#include <linux/types.h>

int value = 22;

void *runner(void *param); /* the thread */

int main(int argc, char *argv[])
{
  pid_t pid;
  pthread_t tid;
  pthread_attr_t attr;
  pid = fork();
  if (pid == 0) {
    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,runner,NULL);
    pthread_join(tid,NULL);
    printf("CHILD: value = %d\n",value);
  }
  else if (pid > 0) { /* parent process */
    wait(NULL);
    printf("PARENT: value = %d\n",value); /* LINE P */
  }
}

void *runner(void *param) {
  value = 16;
  pthread_exit(0);
}
