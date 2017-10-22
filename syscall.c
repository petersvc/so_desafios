// OPEN libraries

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// CLOSE libraries

#include <unistd.h>

int main() {

  // OPEN
  // APPEND add o conteúdo escrito (WRITE) no final do arquivo
  // APPEND é "que nem" um +=

  int fd = open("test.txt", O_WRONLY | O_APPEND);

  // Testando se o arquivo existe, caso não existe, encerra o comando

  if (fd == -1){
    write(0, "Failed to open.\n", 15);
    exit(1);
  }

  // WRITE
  // fd é o endereço do arquivo onde eu vou escrever
  // "hello world é o que vou escrever"
  // 13 é o tamanho da frase "hello world"
  
  write(fd, "Hello Worbd!\n", 13);

  close(fd);
  return 0;
}
