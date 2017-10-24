// OPEN libraries

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// CLOSE libraries

#include <unistd.h>

int main() {

  char input_file_name[128]= "";
  char output_file_name[128]= "";
  char write_1[50] = "Digite o nome do arquivo que será copiado: ";
  char write_2[70] = "Digite o nome do arquivo que receberá o conteúdo copiado: ";

  write(1, write_1, sizeof(write_1));
  read(0, input_file_name, 128);

  write(1, write_2, sizeof(write_2));
  read(0, output_file_name, 128);

  // OPEN
  // APPEND add o conteúdo escrito (WRITE) no final do arquivo
  // APPEND é "que nem" um +=

  int fd = open(input_file_name, O_RDWR | O_CREAT | O_APPEND, S_IWRITE | S_IREAD);

  // Testando se o arquivo existe, caso não existe, encerra o comando

  if (fd == -1){
    write(0, "Failed to open.\n", 15);
    exit(1);
  }

  // WRITE
  // fd é o endereço do arquivo onde eu vou escrever
  // "hello world é o que vou escrever"
  // 13 é o tamanho da frase "hello world"

  write(fd, "Hello World!\n", 13);

  close(fd);
  return 0;

}
