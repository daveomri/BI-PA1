#ifndef __PROGTEST__
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */

void switchThese (int what, unsigned int *c1, unsigned *c2, unsigned int n, unsigned long long int oneThis){
  if (what == 1){
    *c1 = oneThis;
    *c2 = n;
  }
  else {
    *c1 = n;
    *c2 = oneThis;
  }
}
unsigned long long int hyperloop                           ( unsigned long long int length,
                                                             unsigned int        s1,
                                                             unsigned int        s2,
                                                             unsigned int        bulkhead,
                                                             unsigned int      * c1,
                                                             unsigned int      * c2 )
{
  unsigned long long int number = 0; // Number of combinations
  unsigned long long int helpMe = 0; // Helpful variable
  int flag = 0;                      // Flag for indicating switching variables
  if (((long long int)(length - bulkhead)) <= (long long int)(bulkhead) )
      return 0;
  else
      length-=bulkhead;
  s1+=bulkhead;
  s2+=bulkhead;
  if (s1 == s2){
    if (length%s1 == 0){
      (bulkhead == (length+bulkhead))?(*c1 = 0):(*c1 = length/s1);
      *c2 = 0;
      return 1;
    }
    else
      return 0;
  }
  if (s1<s2){
    flag = 1;
    helpMe = s1;
    s1 = s2;
    s2 = helpMe;
  }
  if ((s2-bulkhead) == 0){
    if (length%s1 == 0){
      switchThese(flag, &*c1, &*c2, length/s1, 0);
      return 1;
    }
    else
      return 0;
  }
  helpMe = length/s1;
  for (unsigned long long int n = 0; n <= helpMe; n++){ // Function for finding all combinations
    if ((length-n*s1)%s2 == 0){                         // If combinations of these two numbers give length
      number+=1;
      switchThese(flag, &*c1, &*c2, n, (length-n*s1)/s2);
    }
  }
  return number;
}
#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  unsigned int c1, c2;
  printf("%llu\n",  hyperloop(29403, 179, 14, 14, &c1, &c2 ));
  assert ( hyperloop ( 100, 4, 7, 0, &c1, &c2 ) == 4
           && 4 * c1 + 7 * c2 + 0 * (c1 + c2 + 1) == 100 );
  assert ( hyperloop ( 123456, 8, 3, 3, &c1, &c2 ) == 1871
           && 8 * c1 + 3 * c2 + 3 * (c1 + c2 + 1) == 123456 );
  assert ( hyperloop ( 127, 12, 8, 0, &c1, &c2 ) == 0 );
  assert ( hyperloop ( 127, 12, 4, 3, &c1, &c2 ) == 1
           && 12 * c1 + 4 * c2 + 3 * (c1 + c2 + 1) == 127 );
  assert ( hyperloop ( 100, 35, 0, 10, &c1, &c2 ) == 1
           && c2 == 0
           && 35 * c1 + 10 * (c1 + 1) == 100 );
  assert ( hyperloop ( 110, 30, 30, 5, &c1, &c2 ) == 1
           && 30 * c1 + 30 * c2 + 5 * (c1 + c2 + 1) == 110 );
  assert  ( hyperloop ( 40, 10, 10, 0, &c1, &c2 ) == 1 );
  c1 = 2;
  c2 = 7;
  assert ( hyperloop ( 110, 30, 30, 0, &c1, &c2 ) == 0 && c1 == 2 && c2 == 7 );
  c1 = 4;
  c2 = 8;
  assert ( hyperloop ( 9, 1, 2, 10, &c1, &c2 ) == 0 && c1 == 4 && c2 == 8 );
  return 0;
}
#endif /* __PROGTEST__ */
