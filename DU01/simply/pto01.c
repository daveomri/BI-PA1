#include <stdio.h>
#include <math.h>
#define DBL_EPSILON 2.2204460492503131e-16

int main (void) {
  double troj1Ax, troj1Ay, troj1Bx, troj1By, troj1Cx, troj1Cy;
  double troj2Ax, troj2Ay, troj2Bx, troj2By, troj2Cx, troj2Cy;
  double t1a, t1b, t1c, t2a, t2b, t2c;
  double hilfe1;

  /* Souradnice pro prvni trojuhelnik */
  printf("Trojuhelnik #1:\n");
  printf("Bod A:\n");
  if ((scanf("%lf %lf", &troj1Ax, &troj1Ay))!=2){
    printf("Nespravny vstup.\n");
    return 1;
  }
  printf("Bod B:\n");
  if ((scanf("%lf %lf", &troj1Bx, &troj1By))!=2){
    printf("Nespravny vstup.\n");
    return 1;
  }
  printf("Bod C:\n");
  if ((scanf("%lf %lf", &troj1Cx, &troj1Cy))!=2){
    printf("Nespravny vstup.\n");
    return 1;
  }
      /* Kontrola spravnosti trojuhelniku */
      /* Vypocet delek stran */
      t1a = sqrt((troj1Ax - troj1Bx)*(troj1Ax - troj1Bx) + (troj1Ay - troj1By)*(troj1Ay - troj1By));
      t1b = sqrt((troj1Ax - troj1Cx)*(troj1Ax - troj1Cx) + (troj1Ay - troj1Cy)*(troj1Ay - troj1Cy));
      t1c = sqrt((troj1Cx - troj1Bx)*(troj1Cx - troj1Bx) + (troj1Cy - troj1By)*(troj1Cy - troj1By));
      /* konec vypoctu delek stran */
      /* Porovnadi delek stran */
      (t1a > t1b) ? (hilfe1 = t1a, t1a = t1b, t1b = hilfe1) : (t1a=t1a);
      (t1b > t1c) ? (hilfe1 = t1b, t1b = t1c, t1c = hilfe1) : (t1b=t1b);
      /* konec porovnani delek stran */

      if ((t1a+t1b) <= t1c || fabs((t1a+t1b)-t1c) <= 128*DBL_EPSILON * t1a ){
          (printf("Body netvori trojuhelnik.\n"));
          return 1;
      }
      /* Konec kontroly spravnosti trojuhelniku */
  /* konec souradnic pro prvni trojuhelnik */

  /* Souradnice pro druhy trojuhelnik */
  printf("Trojuhelnik #2:\n");
  printf("Bod A:\n");
  if ((scanf("%lf %lf", &troj2Ax, &troj2Ay))!=2){
    printf("Nespravny vstup.\n");
    return 1;
  }
  printf("Bod B:\n");
  if ((scanf("%lf %lf", &troj2Bx, &troj2By))!=2){
    printf("Nespravny vstup.\n");
    return 1;
  }
  printf("Bod C:\n");
  if ((scanf("%lf %lf", &troj2Cx, &troj2Cy))!=2){
    printf("Nespravny vstup.\n");
    return 1;
  }
      /* Kontrola spravnosti trojuhelniku */
      /* Vypocet delek stran */
      t2a = sqrt((troj2Ax - troj2Bx)*(troj2Ax - troj2Bx) + (troj2Ay - troj2By)*(troj2Ay - troj2By));
      t2b = sqrt((troj2Ax - troj2Cx)*(troj2Ax - troj2Cx) + (troj2Ay - troj2Cy)*(troj2Ay - troj2Cy));
      t2c = sqrt((troj2Cx - troj2Bx)*(troj2Cx - troj2Bx) + (troj2Cy - troj2By)*(troj2Cy - troj2By));
      /* konec vypoctu delek stran */
      /* Porovnadi delek stran */
      (t2a > t2b) ? (hilfe1 = t2a, t2a = t2b, t2b = hilfe1) : (t2a=t2a);
      (t2b > t2c) ? (hilfe1 = t2b, t2b = t2c, t2c = hilfe1) : (t2b=t2b);
      /* konec porovnani delek stran */

      if ((t2a+t2b) <= t2c || fabs((t2a+t2b)-t2c) <= 128*DBL_EPSILON * t2a ){
          (printf("Body netvori trojuhelnik.\n"));
          return 1;
      }
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
