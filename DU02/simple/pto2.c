#include <stdio.h>
#include <string.h>

long int countDigit(long int lo, long int hi){ // Tato funkce vypocitava celkovy pocet znaku
  long int suma = 0;
  long int nob = 1;
  long int max = 0;
  long int i = -1;
  int flag = 0, flagEnd = 0;
  while (i <= lo){ // Tento cyklus nachazi nejblizsi mocninu dvou a dopocita pocet cifer do ni
    i = i*2;
    if (flag == 0){
      i = 2;
      flag = 1;}
    if (lo < i && i <= hi){
      suma+= (i - lo)*nob;
      max = i;}
    else if ( lo < i && i > hi){
      suma+= (hi - lo + 1)*nob;
      max = i;
      flagEnd = 1;}
    nob += 1;}
    while (max*2 <= hi){ // Tento cyklus vypocitava pocet cifer mezi minimem a maximem
      suma+= (max*2 - max)*nob;
      max *= 2;
      nob += 1;}
    if (flagEnd == 0){ // Pokud jsou cifry do maxima jiz spocitane, tak ignoruj a pokracuj
      suma+= (hi-max + 1)*nob;}
    return suma;}
long int zeroHero(long int num, long int hi, int what){ // Tato funkce vypocitava jednak sekvenci nul a pocet nul
  long int zeroCount = 0;
  long int sequeZero = 0;
  long int maxZero = 0;
  long int i = 1, k = 1;
  long int suman = 1;
  while (i*2 <= num ){
    i = i*2;
  }
  suman = i*2;
  k = i;
  for (; num <= hi; num+=1){
    if (num >= suman){
      k = suman;
      suman = suman * 2;
    }
    i = k;
    while(i>=1){
      if (num & i){
        if(maxZero < sequeZero){ maxZero = sequeZero;}
        sequeZero = 0;
      }
      else{
        zeroCount += 1;
        sequeZero += 1;
      }
      i = i/2;
      }
      if(maxZero < sequeZero){ maxZero = sequeZero;}
    }
  if (what == 0){ // Pokud volam pocet nul
    return zeroCount;
  }
  else{ // Pokud volam nejdelsi sekvenci nul
    return maxZero;
  }
}
int main ( void ){
  long int lo, hi;
  long int output;
  int i = 0, k = 0;
  char input[8];
  char stringMine[128];
  char finalString[128];
  printf("Zadejte interval:\n");
  while ((scanf("%c", &stringMine[i])) != EOF){
    if ((stringMine[i] != ' ') && (stringMine[i] != '\n') && (stringMine[i] != '\t') && (stringMine[i] != '\r')){
        finalString[k] = stringMine[i];
        k++;}
    i++;}
  if ((sscanf(finalString, " %c %ld %c %ld %c %c ", &input[0], &lo, &input[1], &hi, &input[2], &input[3])) != 6) {
    printf("Nespravny vstup.\n");
    return 1;
  }
  else{
    if((input[0] == '<') && (input[1] == ';') && (input[2] == '>') && (lo >= 0) && (hi >= 0) && (lo <= hi)){
      switch (input[3]){
        case 'l':
                output = countDigit(lo, hi);
                printf("Cifer: %ld\n", output);
                break;
        case 's':
                output = zeroHero(lo, hi, 1);
                printf("Sekvence: %ld\n", output);
                break;
        case 'z':
                output = zeroHero(lo, hi, 0);
                printf("Nul: %ld\n", output);
                break;
        default:
                printf("Nespravny vstup.\n");
                return 1;
      }
     }
    else{
        printf("Nespravny vstup.\n");
        return 1;}
  }
  return 0;
}
