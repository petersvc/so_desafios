//#include <stdio.h> // opcional pra usar printf e saber a qtde de dados no final.
#include <stdlib.h> // Biblioteca da função exit().
#include <unistd.h> // Biblioteca das funções write() E read().
#include <sys/types.h> // open().
#include <sys/stat.h> // open().
#include <fcntl.h> // open().

void main(){

  char source[50], destination[50], buffer[64]; // Respectivamente guardam: nome do arquivo de origem; ...destino; conteúdo da "source".
  int fd, fd2, size, size2; // "fd" abre arquivo, size delimita o tamanho do buffer de leitura e escrita.

  write(1, "Digite o nome do arquivo fonte: ", 33); // "1" = argumento para escrever na tela; "33" = tamanho da frase
  size = read(0, source, 50); // lendo o conteudo do teclado ("0" = teclado), jogando isso em "source", ler no maximo "50" dados de entrada.
  source[size - 1] = '\0'; // "\0" encerra a string limpando o lixo pego na read, caso o digitado tenha sido mero que o buffer ("50").

  write(1, "Digite o nome do arquivo de destino: ", 38); // ...
  size = read(0, destination, 50); // ...
  destination[size - 1] = '\0'; // ...

  fd = open(source, O_RDONLY); // abre ("O_ = open") o arquivo ("source") com permissáo de apenas leitura ("RD = read; ONLY...").

  if(fd < 0){ // Testa se houve erro na abertura de "source". Quando a "open" falha, ela retorna "-1".
    write(0, "\nPrograma abortado: o arquivo não existe.", 42);
    exit(1); // Encerra o programa.
  } else{
      /*
        "fd2" abre "destination" com permissao de leitura e escrita ("RDWR" = read and write) ou o cria ("O_CREAT");
        Se destination ja existe, "O_EXCL" impede que ele seja aberto ou criado;
        "0777" da permissao de leitura, escrita e execução para o arquivo aberto/criado ("destination").
      */
      fd2 = open(destination, O_RDWR | O_CREAT | O_EXCL, 0777);
      if(fd2 < 0){ // Testa se houve erro..."destination"...
        write(0, "\nPrograma abortado: o arquivo já existe", 41);
        exit(1);
      }
  }

  do{ // Loop de leitura e escrita.
    size = read(fd, buffer, 64); // Lê o conteúdo da var "fd" e o guarda na "buffer", "64" bytes a cada loop.
    size2 = write(fd2, buffer, size); // Escreve o conteúdo da "buffer" na "fd2". A qtde de dados escritos = "size" = retorno da read() = "64".
  } while(size > 0); // Enquanto size é maior que zero, ha dados a serem copiados, quando não ha, "size" = 0 ou -1.

  size = lseek(fd, SEEK_SET, SEEK_END); // Percorre todas as posiçoes do arquivo e retorna o numero de bytes dele.
  size2 = lseek(fd2, SEEK_SET, SEEK_END); // "SEEK_SET" = começa da primeira posição; "SEEK_END" = até a ultima posição.

  if(size == size2){ // Testa se a qtde de bytes dos dois arquivos é a mesma.
    write(1, "\nA copia foi bem sucedida!\n", 26); // Caso sim, eles sao identicos e ocorreu tudo bem
  } else{
    write(1, "\nA copia foi mal sucedida!\n\n", 26);
    }

  //printf("\n\nArquivo fonte = %d bytes\nArquivo de destino = %d bytes", size, size2); // ver a qtd de bytes dos arquivos.

  close(fd); // fecha o arquivo "source".
  close(fd2); // fecha o arquivo "destination".

}
