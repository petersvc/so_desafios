/*for(;michaelDouglas;)
	printf("Never more I go sleep");
*/
#include <stdio.h>
#include <string.h>
int main() {
  char print_1[40] = "Digite o nome do arquivo a ser lido: ";
  int len = strlen(print_1);
  char input_file_name[40];

  write(0, print_1, len);
  scanf("%[^\n]s", input_file_name);
  getchar();

  char print_2[40] = "Digite o nome do arquivo a ser gerado: ";
  int len2 = strlen(print_2);
  char output_file_name[40];

  write(0, print_2, len2);
  scanf("%[^\n]s", output_file_name);

  return 0;
}
