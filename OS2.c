#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <fcntl.h>
int main() { 
  char buffer[100]; 
  int result; 
  int wresult; 
  int written_bytes; 
  int fd = open("a.txt", O_RDONLY); 
  if(fd<0) { 
      perror("open"); 
            return 1; 
  } 
  while(result=read(fd, buffer, 100)) { 
    if(result<0)  { 
      perror("read"); 
      return 2; } 
    written_bytes = 0; 
    while(written_bytes<result) {
      wresult = write(STDOUT_FILENO, buffer+written_bytes, result-written_bytes); 
      if(wresult<0)  { 
        perror("write"); return 3; 
      } 
      written_bytes+=result; }
  } 
  result=close(fd); 
  if(result<0)  { 
    perror("close"); 
    return 4; 
  } 
}
