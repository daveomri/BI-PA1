#include <stdio.h>
int main ( void ){
  int vstup;
  printf("ml' nob:\n");
  scanf("%d", &vstup);
  if (vstup == 1){
    printf("Qapla'\nnoH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.\n");
  }
  else if (vstup == 2 ) {
    printf("Qapla'\nQu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.\n");
  }
  else if (vstup == 3 ) {
    printf("Qapla'\nqaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.\n");
  }
  else if (vstup == 4 ) {
    printf("Qapla'\nHa'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.\n");
  }
  else if (vstup == 5 ) {
    printf("Qapla'\nleghlaHchu'be'chugh mIn lo'laHbe' taj jej.\n");
  }
  else
    printf("luj\n");
  return 0;
}
