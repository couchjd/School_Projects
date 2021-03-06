#define STDIN 0
#define STDOUT 1

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

char swapCase(char);
char encode(char);
void encoder(char*);
char* getString();

int main(){
  encoder(NULL);
  encoder("Am Dx\n");
  encoder("wxYZ\n");
  encoder("Hello World\n");
  return 0;
}

char* getString(){
  char *string;
  size_t bufsize = 256;

  printf("Enter a character sequence: ");
  string = (char *) malloc (bufsize*sizeof(char));
  getline(&string, &bufsize, stdin);
  printf("\n");
  return string;
}

void encoder(char* argv){
  int fd1[2];
  int fd2[2];
  int nbytes;
  int counter;
  char readbuffer[256];
  char* string; 

  if(argv == NULL){
    string = getString();
  }
  else{
    string = argv;
  }

  pid_t childpid;

  pipe(fd1);
  pipe(fd2);

  if((childpid = fork()) == -1){
    perror("fork");
    exit(1);
  }

  //child process
  if(childpid == 0){
    close(fd1[STDOUT]); //close extra child output pipe
    close(fd2[STDIN]);  //close extra child input pipe
    write(fd2[STDOUT], string, (strlen(string)+1)); //send message to parent process
    read(fd1[STDIN], readbuffer, sizeof(readbuffer)); //receive encoded message from parent
    printf("Encoded message: \t%s\n", readbuffer);
    exit(0);
  }

  //parent process
  else{
    close(fd2[STDOUT]); //close parent output pipe
    close(fd1[STDIN]);  //close parent input pipe
    nbytes = read(fd2[STDIN], readbuffer, sizeof(readbuffer)); //read original message from child 
    printf("Original message: \t%s", readbuffer);
    
    //encode message
    for(counter = 0; counter < nbytes - 1; counter++){
      readbuffer[counter] = swapCase(encode(readbuffer[counter]));
    }
    
    write(fd1[STDOUT], readbuffer, (strlen(readbuffer)+1)); //send message back to child
  }
}

char swapCase(char charIn){
  if(charIn >= 'A' && charIn <= 'Z'){
    charIn += 32;
  }
  else if(charIn >= 'a' && charIn <= 'z'){
    charIn -= 32;
  }
  else{
    return charIn;
  }
  return charIn;
}

char encode(char charIn){
  if(charIn == 'Z' || charIn == 'z'){
    return charIn;
  }
  if(!((charIn >= 'A' && charIn <= 'Z')||(charIn >= 'a' && charIn <= 'z'))){
    return charIn;
  }
  else{
    return charIn + 1;
  }
}
