#include <stdio.h>
#include <math.h>
#define DBL_EPSILON 2.2204460492503131e-16

double lenghtOfSide(double Ax, double Bx, double Ay, double By){
  double result;
  result = sqrt(( Ax - Bx )*( Ax - Bx ) + ( Ay - By )*( Ay - By )); // Funkce pro vypocet delek stran
  return result;}
int main (void) {
  double troj1Ax, troj1Ay, troj1Bx, troj1By, troj1Cx, troj1Cy; // souradnice bodu prvniho trojuhelniku
  double troj2Ax, troj2Ay, troj2Bx, troj2By, troj2Cx, troj2Cy; // souradnice bodu druheho trojuhelniku
  double t1a, t1b, t1c, t2a, t2b, t2c; /* Delky stran trojuhelniku*/
  double hilfe1; // Pomocna pri hledani maxima
  int i = 0, k = 0; // Pomocne promene, pro posouvani v poli
  char knight[128]; // Vstup pro prvni trojuhelnik
  char inputString[128]; // String pouzity pro kontrolu vstupu trojuhelniku 1
  char inputString2[128]; // String pouzity pro kontrolu vstupu trojuhelniku 2
  char knight2[128]; // Vstup pro druhy trojuhelnik
  char tryme[16];
  /* Souradnice pro prvni trojuhelnik */
  printf("Trojuhelnik #1:\n");

        do{
      		if ((scanf("%c", &inputString[i])) == EOF){
            printf("Nespravny vstup.\n");
            return 1;
          }
          else{
          if ((inputString[i] != ' ') && (inputString[i]!='\n') && (inputString[i]!='\t') && (inputString[i]!='\r')){
            knight[k] = inputString[i];
      			k++;}
          i++;}} while(inputString[i-1] != '}');
        //scanf("%*s");
        
        if (knight[1] == '['){
            if((sscanf(knight, "{[%lf;%lf],[%lf;%lf],[%lf;%lf] %c",
            &troj1Ax, &troj1Ay, &troj1Bx, &troj1By, &troj1Cx, &troj1Cy, &tryme[0])) != 7){
              printf("Nespravny vstup.\n");
              return 1;
            }
            else{
              if (tryme[0] == '}'){
                  //  printf(" %f %f %f %f %f %f", troj1Ax, troj1Ay, troj1Bx, troj1By, troj1Cx, troj1Cy);
                  /* Vypocet delek stran */
                  t1a = lenghtOfSide(troj1Ax, troj1Bx, troj1Ay, troj1By);
                  t1b = lenghtOfSide(troj1Ax, troj1Cx, troj1Ay, troj1Cy);
                  t1c = lenghtOfSide(troj1Cx, troj1Bx, troj1Cy, troj1By);
                  /* konec vypoctu delek stran */
              }
              else{
                printf("Nespravny vstup.\n");
                return 1;}
            }
        }
        else{
            if((sscanf(knight, "{%lf,%lf,%lf}",
            &t1a, &t1b, &t1c)) != 3){printf("Nespravny vstup.\n"); return 1;}
            }
        /* Kontrola spravnosti trojuhelniku */
        /* Porovnadi delek stran */
        (t1a > t1b) ? (hilfe1 = t1a, t1a = t1b, t1b = hilfe1) : (t1a=t1a);
        (t1b > t1c) ? (hilfe1 = t1b, t1b = t1c, t1c = hilfe1) : (t1b=t1b);
        /* konec porovnani delek stran */
        if ((t1a+t1b) <= t1c || fabs((t1a+t1b)-t1c) <= 128*DBL_EPSILON * t1a ){
            (printf("Neplatny trojuhelnik.\n"));
            return 1;}
        /* Konec kontroly spravnosti trojuhelniku */
  /* konec souradnic pro prvni trojuhelnik */
//  while ( (getchar()) != '\n' );
  /* Souradnice pro druhy trojuhelnik */
  printf("Trojuhelnik #2:\n");
        i = 0;
        k = 0;
        // Naplneni vstupu do stringu, a soucastne i determinace mezer, tabulatoru a novych radku
        do{
          if ((scanf("%c", &inputString2[i])) == EOF){
            printf("Nespravny vstup.\n");
            return 1;
          }
          else{
              if ((inputString2[i] != ' ') && (inputString2[i]!='\n') && (inputString2[i]!='\t') && (inputString2[i]!='\r')){
              knight2[k] = inputString2[i]; k++;}
              i++;
          }}
        while(inputString2[i-1] != '}');
        // Kontrola vstupu, pokud se jedna o souradnice bodu, tak se vykona nasledujici if
        if (knight2[1] == '['){
            if((sscanf(knight2, "{[%lf;%lf],[%lf;%lf],[%lf;%lf] %c",
            &troj2Ax, &troj2Ay, &troj2Bx, &troj2By, &troj2Cx, &troj2Cy, &tryme[0])) != 7){
              printf("Nespravny vstup.\n");return 1;}
            else{
              /* Vypocet delek stran */
              t2a = lenghtOfSide(troj2Ax, troj2Bx, troj2Ay, troj2By);
              t2b = lenghtOfSide(troj2Ax, troj2Cx, troj2Ay, troj2Cy);
              t2c = lenghtOfSide(troj2Cx, troj2Bx, troj2Cy, troj2By);
              /* konec vypoctu delek stran */}
        }
        else{
            if((sscanf(knight2, "{%lf,%lf,%lf}",
            &t2a, &t2b, &t2c)) != 3){printf("Nespravny vstup.\n"); return 1;}
            }
          /* Kontrola spravnosti trojuhelniku */
          /* Porovnadi delek stran */
          (t2a > t2b) ? (hilfe1 = t2a, t2a = t2b, t2b = hilfe1) : (t2a=t2a);
          (t2b > t2c) ? (hilfe1 = t2b, t2b = t2c, t2c = hilfe1) : (t2b=t2b);
          /* konec porovnani delek stran */
          if ((t2a+t2b) <= t2c || fabs((t2a+t2b)-t2c) <= 128*DBL_EPSILON * t2a ){
              (printf("Neplatny trojuhelnik.\n")); return 1;}
            /* Konec kontroly spravnosti trojuhelniku */
  /* konec souradnic pro druhy trojuhelnik */
  /* Porovnani trojuhelniku */
  ((fabs(t1a-t2a) <=  128*DBL_EPSILON * fabs(t1a))
  &&fabs(t1b-t2b) <=  128*DBL_EPSILON * fabs(t1b)
  &&fabs(t1c-t2c) <=  128*DBL_EPSILON * t1c) ? (printf("Trojuhelniky jsou shodne.\n")) : (
    (fabs(((t1a+t1b+t1c)-(t2a+t2b+t2c))) <= 128*DBL_EPSILON * (t1a+t1b+t1c)) ? (printf("Trojuhelniky nejsou shodne, ale maji stejny obvod.\n")) : (
      ((t1a+t1b+t1c) > (t2a+t2b+t2c)) ? (printf("Trojuhelnik #1 ma vetsi obvod.\n")) : (printf("Trojuhelnik #2 ma vetsi obvod.\n"))
    )
  );
  /* konec porovnani trojuhelniku */
  return 0;
}
