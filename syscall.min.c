#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

  char input_file_name[50] = "";
  char output_file_name[50] = "";
  char fdd[50] = "";
  char write_1[50] = "Digite o nome do arquivo que será copiado: ";
  char write_2[70] = "Digite o nome do arquivo que receberá o conteúdo copiado: ";

  write(1, write_1, 50);
  read(0, input_file_name, sizeof(input_file_name));

  write(1, write_2, 70);
  read(0, output_file_name, sizeof(output_file_name));

  int fd = open(input_file_name, O_RDWR | O_CREAT, 777);
  int fd2 = open(output_file_name, O_RDWR | O_CREAT, 777);

  if (fd == -1 || fd2 == -1){
    write(0, "Failed to open.\n", 15);
    exit(1);
  }


  read(fd, fdd, sizeof(fd));
  int size = lseek(fd, 0, SEEK_END);
  write(*fdd, &fd, size);

  write(fd2, fdd, size);

  close(fd);
  close(fd2);

  return 0;

}
