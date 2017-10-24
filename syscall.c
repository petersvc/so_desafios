#include <stdio.h>
#include <string.h>

// OPEN libraries

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// CLOSE libraries

#include <unistd.h>

int main() {

  /*
    Char input e output sao as variáveis que guardarão
    o nome dos arquivos de entrada e saída, respectivamente.
  */

  char input_file_name[128]= "";
  char output_file_name[128]= "";
  char write_file[128]= "";

  /*
    Char write_1 e 2 sao as variáveis que guardam as frases
    que serão printadas com a sycall write() para informar ao
    usuário que ele deve digitar o nome dos arquivos.
  */

  char write_1[50] = "Digite o nome do arquivo que será copiado: ";
  char write_2[70] = "Digite o nome do arquivo que receberá o conteúdo copiado: ";
  char write_3[70] = "Digite a frase a ser escrita no arquivo: ";

  /*
    SYSCALL WRITE()

    A Syscall write() recebe três parâmetros:
    write(onde vai escrever, o que vai escrever, tamanho do que vai escrever).
    Observe a write() abaixo desse comentário.
    O parâmetro "1" indica que vou escrever no dispositivo padrão de saída (a tela).
    o parâmetro "write_1" é a variável que guarda o conteúdo a ser escrito.
    sizeof() retorna a quantidade de caracteres contidos na write_1
    e usa esse numero como parâmetro de tamanho, o ultimo parâmetro dessa syscall, no caso.
  */

  write(1, write_1, sizeof(write_1));

  /*
    SYSCALL READ()

    Recebe três parâmetros:
    Read(onde vai ler, onde vai gravar o que foi lido, tamanho do que vai gravar).
    Observe a read() abaixo desse comentário.
    O parâmetro "0" indica que vou ler do dispositivo padrão de entrada (o teclado).
    O parâmetro "input_file_name" é a variável que guarda o conteúdo a ser lido.
    O Parâmetro "128" indica o tamanho máximo de valores, numeros, caracteres lidos.
  */

  read(0, input_file_name, 128);

  //write(1, write_2, sizeof(write_2));
  //read(0, output_file_name, 128);

  write(1, write_3, sizeof(write_3));
  read(0, write_file, 128);

  /*
    SYSCALL OPEN

    Recebe três parâmetros:
    open(caminho do arquivo, modo de abertura, tipo de permissão).
    Observe a open() abaixo desse comentário.
    O parâmetro "input_file_name" é a variável que guarda o endereço/nome do arquvi a ser aberto.
    Os parâmetros "O_RDWR | O_CREAT" respectivamente são:
    O_ = open, RDWR = read write, logo O_RDWR = abrir, ler e escrever;
    O_CREAT = abrir ou criar, caso o arquivo nao exista.
    S_IWRITE | S_IREAD sao respectivamente: permissão de escrita, permissão de leitura.
  */

  int fd = open(input_file_name, O_RDWR | O_CREAT, S_IWRITE | S_IREAD);

  /*
    Testando se o arquivo existe, caso não existe, encerra o comando.
    Quando a função "open()" falha em abrir o arquivo, ela retorna -1.
  */

  if (fd == -1){
    write(0, "Failed to open.\n", 15);
    exit(1);
  }

  /*
    ESCREVENDO EM UM ARQUIVO

    fd é o endereço do arquivo onde eu vou escrever.
    "hello world é o que vou escrever".
    13 é o tamanho da frase "hello world".
  */
  int size = sizeof(write_file);
  printf("%s", write_file);

  close(fd);
  return 0;

}
