int main() {

  char input_file_name[128];

  write(0, "Digite o nome do arquivo a ser lido: ", 38);
  read(0, input_file_name, 128);
  getchar();

  char output_file_name[128];

  write(0, "Digite o nome do arquivo a ser gerado: ", 40);
  read(0, input_file_name, 128);

  return 0;
}
