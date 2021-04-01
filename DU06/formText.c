# include <stdio.h>
# include <string.h>

int main(void){
  char text[40] = "one  two  \n\n  three \n ";
  char texto[40];
  char output[20];
  int count, flag = 0, newline = 0;
  int width = 5;
  int widthMine = width;
  int when  = 0;
  char * pointer = text;

  //sscanf(pointer, "%s %n", text, &count);
  //printf("%s\n", pointer);
  //printf("%s\n", pointer+3);
  printf("%ld\n", strlen(pointer));
  while (strlen(pointer)){
      if ((sscanf(pointer, "%s%n ", output, &count))!=1)
        break;
      if (strlen(output)>widthMine)
        newline = 1;
      if (count>(strlen(output)+1)){
        for (int i = 0; i < (count-strlen(output)); i++ ){
          if (text[when+i]=='\n')
            flag++;
          if (flag == 2){
            if ((strlen(output)<=width)){
              strcat(texto, "\n\n");
              strcat(texto, output);
              newline = 0;
              widthMine=width;
              widthMine-=strlen(output);
            }
            else{
              printf("return NULL\n");
            }
            break;
          }
        }
        if (flag!=2){

          if (newline == 1){
            if (strlen(output)<=width){
              strcat(texto, "\n");
              strcat(texto, output);
              widthMine=width;
              widthMine-=strlen(output);
              newline = 0;
            }
            else{
              printf("return NULL\n");
            }

          }

          else{
            strcat(texto, " ");
            strcat(texto, output);
            widthMine -= strlen(output)+1;

            }
          }
        }
      else{

        if (newline == 1){
          if (strlen(output)<=width){
            strcat(texto, "\n");
            strcat(texto, output);
            widthMine=width;
            widthMine-=strlen(output);
            newline = 0;
          }
          else{
            printf("return NULL\n");
          }
        }
        else{
          strcat(texto, " ");
          strcat(texto, output);
          widthMine -= strlen(output)+1;

        }



        /*if (newline == 1)
          strcat(texto, output);
        else{
          strcat(texto, " ");
          strcat(texto, output);
        }
        newline = 0;*/

      }
      //printf("here %s\n", output);
    //  printf("this is srllen -> %ld\n", strlen(output));
      when += count;
      flag = 0;
      pointer += count;
    //  printf("%ld\n", strlen(pointer));
  }

  printf("%s\n", texto);
  return 0;
}
