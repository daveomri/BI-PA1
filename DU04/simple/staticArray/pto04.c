# include <stdio.h>
# include <string.h>
# define LEN_ARRAY 1000000
int readInput (long long int * len, long long int * array){
  char inMine[LEN_ARRAY] = "", temp, *data = inMine;
  long long int offset, offsetcount = 0, som, flag = 0, i = 0, comma = 0;
  printf("Mozna umisteni:\n");
  if((scanf("%lld", len))!=1)
    return 0;
  if (*len <= 0)
    return 0;
  do{
    if((scanf("%c", &temp)) == EOF)
      return 0; // I'm using 0 as notification for ending program
  } while ((temp == '\n')||(temp == '\t')||(temp == '\r')||(temp == ' '));
  if ( temp != ':' )
    return 0;
  do {
    if ((scanf("%c", &temp))==EOF)
      return 0;
    if ((temp != '\n')&&(temp != '\t')&&(temp != '\r')&&(temp != ' ')){
      inMine[i] = temp;
      ((temp == ',')||(temp=='{'))?(comma+=1):(comma=comma);
      i++;}
  }while (temp != '}');
  i = 0;
  while (offsetcount != (long long int)strlen(inMine)-1){
    if ((sscanf(data, "%lld%lln", &som, &offset))!=1){// When it is a number count how many digits it has, that's why there is '%n', I work with array, and because of it, I have to know, when to stop reading input
        offset = 1;
        flag +=1;}
    else{
      flag = 0;
      if ((som < 1)||(som >= *len ))
        return 0;
      array[i] = som;
      i++;}
    if ( flag == 2 )
      return 0;
    data+=offset;
    offsetcount+=offset;}
  if((i)==comma)
    return i;
  return 0;
}
int workWithMe(long long int *len, long long int * array, long long int *i){
  long long int arrayLen = *i-1, dist = 0, bilboard = 0, tmp = 0, flag = 0, countIt = 0, k;
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
    if((sscanf(saveHere, "%lld", &dist)!=1))
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
    (flag==3)?(printf("N/A\n")):(printf("Billboardu: %lld\n", bilboard));
  }
  return 0;
}
int main (void){
  long long int len, i, array[LEN_ARRAY] = {0};
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
