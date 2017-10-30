#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main(){

  char source[50], destination[50], buffer[64];
  int fd, fd2, size, size2;

  write(1, "Digite o nome do arquivo fonte: ", 33);
  size = read(0, source, 50);
  source[size - 1] = '\0';

  write(1, "Digite o nome do arquivo de destino: ", 38);
  size = read(0, destination, 50);
  destination[size - 1] = '\0';

  fd = open(source, O_RDONLY);

  if(fd < 0){
    write(0, "\nPrograma abortado: o arquivo não existe.", 42);
    exit(1);
  } else{
      fd2 = open(destination, O_RDWR | O_CREAT | O_EXCL, 0777);
      if(fd2 < 0){
        write(0, "\nPrograma abortado: o arquivo já existe", 41);
        exit(1);
      }
  }

  do{
    size = read(fd, buffer, 64);
    size2 = write(fd2, buffer, size);
  } while(size > 0);

  size = lseek(fd, SEEK_SET, SEEK_END);
  size2 = lseek(fd2, SEEK_SET, SEEK_END);

  if(size == size2){
    write(1, "\nA copia foi bem sucedida!\n", 26);
  } else{
    write(1, "\nA copia foi mal sucedida!\n", 26);
    }

  close(fd);
  close(fd2);
  
}
