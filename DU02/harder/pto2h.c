#include <stdio.h>
#define VALUESTRING 256

void usefulLoop(long long int hi, long long int lo, int r, int what){
  long long int bef = 0, aft = 0;
  long long int seque = 0;
  long long int maxseque = 0;
  long long int zerco = 0;
  int flag;
  for (long long int num = hi; num >= lo; num --){
    bef = num+1;
    flag = 0;
    while (bef != 0){
      if (flag == 0){flag = 1; bef--;}
      aft = bef % r;
      bef = bef / r;
      if (aft == 0){
        zerco+=1;
        seque+=1;
        (seque > maxseque)?(maxseque = seque):(maxseque=maxseque);
      }
      else{
        seque = 0;
      }
    }
  }
  (what == 1) ? (printf("Sekvence: %lld\n", maxseque)) : (printf("Nul: %lld\n", zerco));
}

void willFindDigits(long long int hi, long long int lo, int r){
  long long int suma = 0;
  long long int nob = 1;
  long long int max = -1;
  long long int i = 0;
  int flag = 0, flagEnd = 0;
  while (i <= lo){ // Tento cyklus nachazi nejblizsi mocninu dvou a dopocita pocet cifer do ni
    i = i*r;
    if (flag == 0){
      i = r;
      flag = 1;}
      if (lo < i && i <= hi){
        suma+= (i - lo)*nob;
        max = i;}
      else if ( lo < i && i > hi){
        suma+= (hi - lo + 1)*nob;
        max = i;
        flagEnd = 1;}
      nob += 1;}
      while (max*r <= hi){ // Tento cyklus vypocitava pocet cifer mezi minimem a maximem
        suma+= (max*r - max)*nob;
        max *= r;
        nob += 1;}
      if (flagEnd == 0){ // Pokud jsou cifry do maxima jiz spocitane, tak ignoruj a pokracuj
        suma+= (hi-max + 1)*nob;}
   printf("Cifer: %lld\n", suma);
}
void willFindSequence (long long int hi, long long int lo, int r){
  long long int i;
  long long int count = 1;
  i = r;
  if (hi >= r){
  while(i*r <= hi){
      i=i*r;
      count += 1;
    }
    if(i < lo){
      usefulLoop(hi, lo, r, 1);
    }
    else {
      printf("Sekvence: %lld\n", count);
    }
  }
  else {(lo == 0)?(printf("Sekvence: %d\n", 1)):(printf("Sekvence: %d\n", 0));}
}
int inputCorector( int what ){
  long long int hi, lo;
  int r = 10;
  char inputos[VALUESTRING];
  char a;
  int flag = 2, out = 0;
  char inpu[VALUESTRING];
  int i = 0;

  while(out==0){
    if ((scanf("%c", &a))==EOF){
      return 1;
    }
    if ((a!=' ')&&(a!='\t')&&(a!='\n')&&(a!='\r')){
      inpu[i]=a;
      i++;
      flag++;
    }
    if (a == '>'){
      flag = 0;
    }
    if (flag == 1){
      out = 1;
    }
  }
  if ( what == 0 ){
    if((sscanf(inpu,"%d %c %c %lld %c %lld %c %c",
      &r, &inputos[0], &inputos[1], &lo, &inputos[2], &hi, &inputos[3], &inputos[4])!=8)){
        return 1;
      }
    if ((inputos[0] != ':') || (inputos[1] != '<') || (r<2)||(r>36)){
      return 1;
    }
  }
  else{

    if((sscanf(inpu, "%lld %c %lld %c %c",
      &lo, &inputos[2], &hi, &inputos[3], &inputos[4])!=5)){
        return 1;
      }
  }
  if ((inputos[2] != ';') || (inputos[3] != '>') || ((inputos[4] != 'l')&&(inputos[4] != 's')&&(inputos[4] != 'z'))){
    return 1;
  }
  if ((hi < lo)||(hi < 0)||(lo < 0)){return 1;}
  switch (inputos[4]){
    case 's':
            willFindSequence(hi, lo, r);
            break;
    case 'z':
            usefulLoop(hi, lo, r, 0);
            break;
    case 'l':
            willFindDigits(hi, lo, r);
            break;
  }
  return 0;
}
int main ( void ) {
  int i = 0;
  char a;
  printf("Zadejte intervaly:\n");
  while ( scanf("%c", &a) != EOF ){
    if (a == 'r' ){
       i = inputCorector(0);
       if (i == 1){printf("Nespravny vstup.\n");return 1;}
    }
    else if (a=='<') {
      i = inputCorector(1);
      if (i == 1){printf("Nespravny vstup.\n");return 1;}
    }
    else if ((a != ' ' && a != '\n' && a != '\t')|| i == 1){
      printf("Nespravny vstup.\n");
      return 1;
    }
  }
  return 0;
}
