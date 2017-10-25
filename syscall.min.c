#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main() {

  char source[50], destination[50], buffer[1];
  int fd, fd2, size;

  write(1, "Digite o nome do arquivo fonte: ", 33);
  size = read(0, source, 50);
  source[size - 1] = '\0';

  write(1, "Digite o nome do arquivo de destino: ", 38);
  size = read(0, destination, 50);
  destination[size - 1] = '\0';

  fd = open(source, O_RDONLY);

  if (fd < 0){
    write(0, "\nPrograma abortado: o arquivo não existe.", 42);
    exit(1);
  }

  fd2 = open(destination, O_RDWR | O_CREAT | O_EXCL, S_IREAD | S_IWRITE);

  if (fd2 < 0){
    write(0, "\nPrograma abortado: o arquivo já existe", 41);
    exit(1);
  }

  size = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, SEEK_SET);

  buffer[size];

  read(fd, buffer, size);

  int buffer_written = write(fd2, buffer, size);
  int fd2_buffer = lseek(fd2, 0, SEEK_END);

  if (buffer_written == fd2_buffer) {
    write(1, "\nA copia foi bem sucedida!\n", 26);
  }
  else {
    write(1, "\nA copia foi mal sucedida!\n", 26);
  }

  close(fd);
  close(fd2);

}
