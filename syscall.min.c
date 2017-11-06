#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main(){

  char source[50], destination[50], buffer[64];
  int fd, fd2, size_read, size_written;

  write(1, "Digite o nome do arquivo fonte: ", 33);
  size_read = read(0, source, 50);
  source[size_read - 1] = '\0';

  write(1, "Digite o nome do arquivo de destino: ", 38);
  size_read = read(0, destination, 50);
  destination[size_read - 1] = '\0';

  fd = open(source, O_RDONLY);

  if(fd < 0){
    write(1, "\nPrograma abortado: o arquivo não existe.", 42);
    exit(1);
  } else{
      fd2 = open(destination, O_RDWR | O_CREAT | O_EXCL, 0777);
      if(fd2 < 0){
        write(0, "\nPrograma abortado: o arquivo já existe", 41);
        exit(1);
      }
  }

  do{
    size_read = read(fd, buffer, 64);
    size_written = write(fd2, buffer, size_read);
  } while(size > 0);

  size_read = lseek(fd, SEEK_SET, SEEK_END);
  size_written = lseek(fd2, SEEK_SET, SEEK_END);

  if(size_read == size_written){
    write(1, "\nA copia foi bem sucedida!\n", 26);
  } else{
    write(1, "\nA copia foi mal sucedida!\n", 26);
    }

  close(fd);
  close(fd2);
  
}
