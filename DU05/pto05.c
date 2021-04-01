# include <stdio.h>
# include <stdlib.h>
# define ARSI  1024
struct ROAD{
  long long int miles;
  long double array[26];
};

struct COUNT{
  long double arrayCn[26];
  long long int lenght;
  long int endAr;
  long int arraySize;
};

int makeLarger(struct ROAD ** array, int size){
  struct ROAD *newstruc = NULL;
  newstruc = (struct ROAD*)realloc(*array, (size * ARSI * sizeof(struct ROAD)));
  if (newstruc == NULL){
    return 1;
  }
  *array = newstruc;
  newstruc = NULL;
  return 0;
}

void swaNu(long long int *a, long long int *b){
  long long int tmp = 0;
  tmp = *a;
  *a = *b;
  *b = tmp;}

int readInput(struct ROAD ** road, struct COUNT * count){
  char tmpstr = ' ';
  int i=0, flag = 0, erme=0, flai=0, needSize = ARSI;;
  long long int  saveithere = 0;
  long double arrayMn[26] = {0};

  printf("Myto:\n");
  while(tmpstr != '{'){
    if ((scanf("%c", &tmpstr))==EOF)
      return 1;}

  while(tmpstr!='}'){
    if (i+2 >= needSize){
      needSize+=ARSI;
      erme = makeLarger(road, ++count->arraySize);
      if (erme == 1)
        return 1;
    }

    if ((scanf(" %c", &tmpstr))==EOF)
      return 1;

    if(tmpstr=='['){
      if (flag!=0)
        return 1;
      flag++;

      if(((scanf("%lld", &((*road)[i].miles) ))!=1)||(*road)[i].miles<=0)
        return 1;
      count->lenght += (*road)[i].miles;
    }

    else if (tmpstr==','){
      if (flag != 3)
        return 1;
      else
        flag = 0;
    }
    else if (tmpstr == ':'){
      if (flag!=1)
        return 1;
      flag++;
    }
    else if((tmpstr!='}')&&(tmpstr!=' ')&&(tmpstr!='\n')&&(tmpstr!='\t')&&(tmpstr!='\r')){

      if(((int)tmpstr<65)||((int)tmpstr>90))
        return 1;
      saveithere = (int)tmpstr-65;
      while(tmpstr!='='){
        if((scanf(" %c", &tmpstr))==EOF)
          return 1;
        if ((tmpstr!=' ')&&(tmpstr!='\n')&&(tmpstr!='\t')&&(tmpstr!='\r')&&(tmpstr!='='))
          return 1;
        }
      if (((scanf("%Lf %c", &arrayMn[saveithere], &tmpstr))!=2) || arrayMn[saveithere]<0 || (tmpstr!=',' && tmpstr!=']'))
        return 1;
      if (tmpstr == ',')
        flai = 1;
      else
        flai = 0;
    }
    else if(tmpstr=='}'){
      if (flag!=3)
        return 1;
    }
    if (tmpstr==']'){
      if (flag!=2 || flai == 1)
        return 1;
      for (int k = 0; k < 26; k++){
        (*road)[i].array[k] = arrayMn[k];
        count->arrayCn[k]+=(*road)[i].miles*(arrayMn[k]);}
      count->endAr = i;
      i++;
      flag++;
    }
  }
  return 0;
}
int doWork(struct ROAD ** road, const struct COUNT * count){
  long long int min = 0, max=0, maxcount=0, mincount=0;
  long long int len = 0;
  int flag=0, endOP=0, i=0, maxi=0, mini=0;
  long double arrCn[26] = {0};

  printf("Hledani:\n");
  while ((endOP = scanf("%lld %lld", &min, &max)) != EOF){
    if(endOP != 2)
      return 1;
    if (min < 0 || max < 0 || min > count->lenght || max > count->lenght || min == max)
      return 1;
    if (max<min){
      swaNu(&min, &max);
      endOP = 1;
    }
    len = 0;
    flag = 0;
    i = 0;
    for (int k = 0; k < 26; k++)
        arrCn[k] = count->arrayCn[k];
    while ( flag == 0 ){  // this block of code find the beginnig of the road
      len += (*road)[i].miles;
      if (min <= len){
        flag = 1;
        mini = i;
        mincount = len-(*road)[i].miles;
      }
      else
        for(int k = 0; k<26; k++)
          if ((*road)[i].array[k] > 0){
            arrCn[k]-=(*road)[i].miles*(*road)[i].array[k];}
      i++;
    } // end of finding beginning
    flag = 0;
    len = count->lenght;
    i = count->endAr;
    while ( flag == 0 ){ // this block of code find the ending of the road
      len -= (long long int)(*road)[i].miles;
      if (max > len){
        flag = 1;
        maxi = i;
        maxcount = len+(*road)[i].miles;
      }
      else{
        for(int k = 0; k<26; k++){
          if ((*road)[i].array[k] > 0){
            arrCn[k]-=(*road)[i].miles*(*road)[i].array[k];
          }
        }
        i--;
      }
    } // end of finding the end
    if (mini == maxi){ // testing if min and max are in the same segment
      for(int k = 0; k<26; k++){
        arrCn[k]=(max-min)*(*road)[mini].array[k];
      }
    }
    else{
      for(int k = 0; k<26; k++){
        arrCn[k]-=(min-mincount)*(*road)[mini].array[k];
        arrCn[k]-=(maxcount - max)*(*road)[maxi].array[k];
      }
    }
    flag = 0;
    if (endOP==1)
      swaNu(&min, &max);
    printf("%lld - %lld:", min, max); // printing the output
    for (int k = 0; k < 26; k++){
      if (arrCn[k] !=  0){
        if(flag==1)
          printf(", ");
        else
          printf(" ");
        printf("%c=%Lf", (char)(k+65), arrCn[k]);
        flag = 1;
      }
    }
    printf("\n");
  }
  return 0;
}

int main (void){
  struct ROAD *road = (struct ROAD*)malloc(ARSI * sizeof(struct ROAD));
  struct COUNT count;
  int i = 0;
  count.arraySize = 1;
  count.lenght = 0;

  for (int k = 0; k < 26; k++)
    count.arrayCn[k]=0;

  i = readInput(&road, &count);
  if (i == 1){
    printf("Nespravny vstup.\n");
    free(road);
    return 1;}

  i = doWork(&road, &count);
  if (i == 1){
    printf("Nespravny vstup.\n");
    free(road);
    return 1;}
  free(road);
  return 0;
}
