# include <stdio.h>
# include <string.h>
# define LENAR 500000

int absol(int num){
  if (num < 0)
    return num*(-1);
  return num;}
int loadTheInput(int *array){
  char temp;
  // int offset, offsetcount = 0, som, flag = 0,
  int i = 0;
  printf("Mozna umisteni:\n");

  while (temp!='{')
    if((scanf(" %c", &temp))==EOF)
      return 0;

  while (temp!='}'){
    if((scanf("%d %c", &array[i], &temp)!=2))
      return 0;
    if (temp != '}' && temp!=',')
      return 0;
    i++;
  }

/*
  do {
    if ((scanf("%c", &temp))==EOF){
      return 0;
    }
    inMine[i] = temp;
    ((temp == ',')||(temp=='{'))?(comma+=1):(comma=comma);
    i++;
  }while (temp != '}');
  i = 0;
  while (offsetcount != (int)strlen(inMine)-1){
    if ((sscanf(data, "%d%n", &som, &offset))!=1){
        offset = 1;
        flag +=1;}
    else{
      flag = 0;
      if (som < 0)
        return 0;
      array[i] = som;
      i++;}
    if ( flag == 2 )
      return 0;
    data+=offset;
    offsetcount+=offset;}
  printf("%d %d\n", i, comma);
  if((i-1)==comma)

*/
  return i;
}
int workingMode(int *array, int len){
  int woray[LENAR], arra[LENAR], number, n = 0, i, p, arrayLen = len-1, tmp;
  char stringInput[32];
  while (arrayLen != 0){
    for (int k = 0; k < (arrayLen); k++){
      if (array[k] > array[k+1]){
        tmp = array[k];
        array[k] = array[k+1];
        array[k+1] = tmp;}
    }
    arrayLen -= 1;}
  printf("Pocet billboardu:\n");
  while((scanf("%s", stringInput))!=EOF){
    for(i = 0; i<(len-1); i++){
      woray[i] = absol(array[i]-array[i+1]);
      //printf("abs - %d | %d and %d\n", woray[i], array[i], array[i+1]);
    }
    if ((sscanf(stringInput, "%d", &number))!=1)
      return 1;
  if ((number == 1)||(number == 0))
    printf("Vzdalenost: inf\n");
  else if (number > len)
    printf("N/A\n");
  else{
    for (int q = len; q >= number; q--){
      n = 0;
      for(p = 0; p<i; p++){
        if (woray[p]>=0){
          arra[n] = p;
          n++;}
      }
      tmp = 0;
      //printf("\nthis was %d and %d\n",number, q );

      if (q < (number){
        for (p = 0; p < n; p++)
          ((woray[arra[p]]<woray[arra[tmp]])&&(woray[arra[p]]>=0))?(tmp=p):(tmp=tmp);
        p = tmp;
        if (n!=1){
          if (p==0)
            woray[arra[p+1]] = woray[arra[p]]+woray[arra[p+1]];
          else if (p == (n-1))
            woray[arra[p-1]] = woray[arra[p]]+woray[arra[p-1]];
          else{
            if(woray[arra[p-1]]<=woray[arra[p+1]])
              woray[arra[p-1]] = woray[arra[p]]+woray[arra[p-1]];
            else
              woray[arra[p+1]]=woray[arra[p]]+woray[arra[p+1]];
          }
        }
        tmp = woray[arra[p]];
        woray[arra[p]] = -1;
        }
      else{
        for (p = 0; p < n; p++){
          if ((p!=0)&&(p!=(n-1))){
            if ((tmp!=0)&&(tmp!=(n-1))){
              if ((woray[arra[p]]<=woray[arra[tmp]])&&(woray[arra[p]]>=0)){

                if (woray[arra[p]]==woray[arra[tmp]]){
                  if(((woray[arra[p-1]]>=woray[arra[tmp-1]])&&(woray[arra[p-1]]>=woray[arra[tmp+1]]))||((woray[arra[p+1]]>=woray[arra[tmp-1]])&&(woray[arra[p+1]]>=woray[arra[tmp-1]])))
                    tmp = p;
                  else
                    tmp = tmp;
                }
                else{
                  ((woray[arra[p]]<woray[arra[tmp]])&&(woray[arra[p]]>=0))?(tmp=p):(tmp=tmp);
                }
              }
            }
            else if (tmp==0){
              if ((woray[arra[p]]<=woray[arra[tmp]])&&(woray[arra[p]]>=0)){
                if (woray[arra[p]]==woray[arra[tmp]]){
                  if(((woray[arra[p-1]]>=woray[arra[tmp+1]]))||((woray[arra[p+1]]>=woray[arra[tmp+1]])))
                    tmp = p;
                  else
                    tmp =tmp;
                }
                else{
                  ((woray[arra[p]]<woray[arra[tmp]])&&(woray[arra[p]]>=0))?(tmp=p):(tmp=tmp);
                }
              }
            }
            else if (tmp == (n-1)){
              if ((woray[arra[p]]<=woray[arra[tmp]])&&(woray[arra[p]]>=0)){
                if (woray[arra[p]]==woray[arra[tmp]]){
                  if(((woray[arra[p-1]]>=woray[arra[tmp-1]]))||((woray[arra[p+1]]>=woray[arra[tmp-1]])))
                    tmp = p;
                }
                else{
                  ((woray[arra[p]]<woray[arra[tmp]])&&(woray[arra[p]]>=0))?(tmp=p):(tmp=tmp);
                }
              }
            }
          }

          else{
              ((woray[arra[p]]<woray[arra[tmp]])&&(woray[arra[p]]>=0))?(tmp=p):(tmp=tmp);
          }
        //  printf("%d and %d\n", woray[arra[p]], woray[arra[tmp]]);
        }

        p = tmp;
        if (n!=1){
          if (p==0)
            woray[arra[p+1]] = woray[arra[p]]+woray[arra[p+1]];
          else if (p == (n-1))
            woray[arra[p-1]] = woray[arra[p]]+woray[arra[p-1]];
          else{
            if(woray[arra[p-1]]>=woray[arra[p+1]])
              woray[arra[p-1]] = woray[arra[p]]+woray[arra[p-1]];
            else
              woray[arra[p+1]]=woray[arra[p]]+woray[arra[p+1]];
          }
        }
        tmp = woray[arra[p]];
        woray[arra[p]] = -1;
        }



      }

    printf("Vzdalenost: %d\n", tmp);
    }
  }
  return 0;
}
int main (void){
  int inputArray[LENAR], i;
  i = loadTheInput(inputArray);
  if (i == 0){
    printf("Nespravny vstup.\n");
    return 1;
  }
  i = workingMode(inputArray, i);
  if (i == 1){
    printf("Nespravny vstup.\n");
    return 1;
  }
  return 0;
}
