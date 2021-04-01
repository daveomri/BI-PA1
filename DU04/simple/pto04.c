# include <stdio.h>
# include <string.h>
# define LEN_ARRAY 1000000
int readInput (int * len, int * array){
  char temp;
  int som, i = 0;
  printf("Mozna umisteni:\n");
  if((scanf("%d", len))!=1)
    return 0;
  if (*len <= 0)
    return 0;
  do{
    if((scanf(" %c", &temp)) == EOF)
      return 0; // I'm using 0 as notification for ending program
  } while ((temp == '\n')||(temp == '\t')||(temp == '\r')||(temp == ' '));
  if ( temp != ':' )
    return 0;
  do{
    if((scanf(" %c", &temp)) == EOF)
      return 0; // I'm using 0 as notification for ending program
  } while ((temp == '\n')||(temp == '\t')||(temp == '\r')||(temp == ' '));
  if ( temp != '{' )
    return 0;
  do {
    if((scanf("%d %c",&som, &temp)) != 2)
      return 0;
    if ((temp!=',')&&(temp != '}'))
      return 0;
    if ((som < 1)||(som >= *len ))
      return 0;
    array[i] = som;
    i++;
  }while (temp != '}');
  return i;
}
int workWithMe(int *len, int * array, int *i){
  int arrayLen = *i-1, dist = 0, bilboard = 0, tmp = 0, flag = 0, countIt = 0, k;
  char saveHere[LEN_ARRAY];
  while (arrayLen != 0){// Firstly I have to sort the array, I will use bubble sort for it
    for (k = 0; k < (arrayLen); k++){
      if (array[k] > array[k+1]){
        tmp = array[k];
        array[k] = array[k+1];
        array[k+1] = tmp;}
    }
    arrayLen -= 1;}// end of bubble sort
  printf("Vzdalenosti:\n");
  while (scanf("%s", saveHere)!=EOF){
    bilboard = 0;
    flag = 0;
    countIt = 0;
    if((sscanf(saveHere, "%d", &dist)!=1))
      return 1;
    if (dist <= 0)
      return 1;
    tmp = dist;
    for(k = 0; k < *i; k++){
      if ((array[k]<=tmp)&&(flag!=3)){
        if (flag == 0){
          countIt = 1;
          flag = 1;}
        else
          if (array[k] != array[k-1])
            countIt = 1;
      }
      else if(flag==1){
        if ((countIt = 1)&&((array[k-1]+dist) >= array[k])){
          ((array[k-1]+dist) >= *len)?(flag=2):(flag=1);
          bilboard++;
          tmp = dist + array[k-1];}
        else
          flag = 3;
      }
      else
        flag = 3;
    }
    if ((flag == 1)&&(tmp<*len)&&(dist<*len)){
      if ((countIt = 1)&&((array[k-1]+dist) >= *len))
        bilboard++;
      else
        flag = 3;
    }
    (flag==3)?(printf("N/A\n")):(printf("Billboardu: %d\n", bilboard));
  }
  return 0;
}
int main (void){
  int len, i, array[LEN_ARRAY] = {0};
  i = readInput(&len, array);
  if (i == 0){
    printf("Nespravny vstup.\n");
    return 1;}
  i = workWithMe(&len, array, &i);
  if (i == 1){
    printf("Nespravny vstup.\n");
    return 1;}
  return 0;
}
