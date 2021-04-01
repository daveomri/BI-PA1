#ifndef __PROGTEST__
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */
void lessMore(unsigned int *a, unsigned int *b, int *one, int *two){
  int helpMe;
  if (*a<*b){
    helpMe = *b;
    *b = *a;
    *a = helpMe;
    helpMe = *one;
    *one = *two;
    *two = helpMe;
  }
}
unsigned long long int hyperloop                           ( unsigned long long int length,
                                                             unsigned int        s1,
                                                             unsigned int        s2,
                                                             unsigned int        s3,
                                                             unsigned int        bulkhead,
                                                             unsigned int      * c1,
                                                             unsigned int      * c2,
                                                             unsigned int      * c3 )
{
  unsigned long long int number = 0;
  unsigned long long int helpMeS1 = 0;
  int myC1 = 1, myC2 = 2, myC3 = 3;
  if ((length < bulkhead)||(length==0))
      return 0;
  else if ((s1==s2)&&(s1==s3)&&(s1==0)&&(length!=bulkhead))
      return 0;
  else if ((length - bulkhead) == 0){
      *c1 = 0;
      *c2 = 0;
      *c3 = 0;
      return 1;
  }
  else
      length-=bulkhead;
  s1+=bulkhead;
  s2+=bulkhead;
  s3+=bulkhead;
  if ((s1 == s2)&&(s1==s3)){
    if (length%s1 == 0){
      (bulkhead == length)?(*c1 = 0):(*c1 = length/s1);
      *c2 = 0;
      *c3 = 0;
      return 1;
    }
    else
      return 0;
  }
  lessMore(&s1, &s2, &myC1, &myC2);
  lessMore(&s1, &s3, &myC1, &myC3);
  lessMore(&s2, &s3, &myC2, &myC3);
  if ((s2==s3)&&((s2-bulkhead)==0)){
    if(length%s1 == 0){
      (myC1 == 1)?(*c1 = length/s1):((myC1==2)?(*c2=length/s1):(*c3=length/s1));
      (myC2 == 1)?(*c1 = 0):((myC2==2)?(*c2=0):(*c3=0));
      (myC3 == 1)?(*c1 = 0):((myC3==2)?(*c2=0):(*c3=0));
      return 1;
    }
    else
      return 0;
  }
  if (((s3-bulkhead) == 0)&&((s1-bulkhead)!=0)&&((s2-bulkhead)!=0)){
    if (s1==s2){
      if (length%s1 == 0){
        (myC1 == 1)?(*c1 = length/s1):((myC1==2)?(*c2=length/s1):(*c3=length/s1));
        (myC2 == 1)?(*c1 = 0):((myC2==2)?(*c2=0):(*c3=0));
        (myC3 == 1)?(*c1 = 0):((myC3==2)?(*c2=0):(*c3=0));
        return 1;
      }
      else {
        return 0;
      }
    }
    else {
      helpMeS1 = length/s1;
      for (unsigned long long int n = 0; n <= helpMeS1; n++){
        if (((length-n*s1)%s2 == 0)&&((s2-bulkhead)!=0)){
          number+=1;
          (myC1 == 1)?(*c1 = n):((myC1==2)?(*c2=n):(*c3=n));
          if ((length-n*s1) == 0)
            (myC2 == 1)?(*c1 = 0):((myC2==2)?(*c2=0):(*c3=0));
          else
            (myC2 == 1)?(*c1 = (length-n*s1)/s2):((myC2==2)?(*c2=(length-n*s1)/s2):(*c3=(length-n*s1)/s2));
          (myC3 == 1)?(*c1 = 0):((myC3==2)?(*c2=0):(*c3=0));
        }
      }
      return number;
    }
  }
  if (s1 == s2){
    helpMeS1 = length/s1;
    for (unsigned long long int n = 0; n <= helpMeS1; n++){
      if ((length-n*s1)%s3 == 0){
        number+=1;
        (myC1 == 1)?(*c1 = n):((myC1==2)?(*c2=n):(*c3=n));
        (myC2 == 1)?(*c1 = 0):((myC2==2)?(*c2=0):(*c3=0));
        if ((length-n*s1) == 0)
          (myC3 == 1)?(*c1 = 0):((myC3==2)?(*c2=0):(*c3=0));
        else
          (myC3 == 1)?(*c1 = (length-n*s1)/s3):((myC3==2)?(*c2=(length-n*s1)/s3):(*c3=(length-n*s1)/s3));
      }
    }
    return number;
  }
  if (s2 == s3){
    helpMeS1 = length/s1;
    for (unsigned long long int n = 0; n <= helpMeS1; n++){
      if (((length-n*s1)%s2 == 0)){
        printf("number is %llu \n", number);
        number+=1;
        (myC1 == 1)?(*c1 = n):((myC1==2)?(*c2=n):(*c3=n));
        if ((length-n*s1)==0)
          (myC2 == 1)?(*c1 = 0):((myC2==2)?(*c2=0):(*c3=0));
        else
          (myC2 == 1)?(*c1 = (length-n*s1)/s2):((myC2==2)?(*c2=(length-n*s1)/s2):(*c3=(length-n*s1)/s2));
        (myC3 == 1)?(*c1 = 0):((myC3==2)?(*c2=0):(*c3=0));
      }
    }
    return number;
  }
  if (((s3-bulkhead) == 0)&&(s2-bulkhead == 0)){
    if (length%s1 == 0){
      (myC1 == 1)?(*c1 = length/s1):((myC1==2)?(*c2=length/s1):(*c3=length/s1));
      (myC2 == 1)?(*c1 = 0):((myC2==2)?(*c2=0):(*c3=0));
      (myC3 == 1)?(*c1 = 0):((myC3==2)?(*c2=0):(*c3=0));
      return 1;
    }
    else
      return 0;
  }
  helpMeS1 = length/s1;
  for (unsigned long long int n = 0; n <= helpMeS1; n++){
    for (unsigned long long int nn = 0; nn <= ((length-n*s1)/s2); nn++){
      if ((length-n*s1-nn*s2)%s3 == 0) {
        number+=1;
        (myC1 == 1)?(*c1 = n):((myC1==2)?(*c2=n):(*c3=n));
        (myC2 == 1)?(*c1 = nn):((myC2==2)?(*c2=nn):(*c3=nn));
        if ((length-n*s1-nn*s2) == 0)
          (myC3 == 1)?(*c1 = 0):((myC3==2)?(*c2=0):(*c3=0));
        else
          (myC3 == 1)?(*c1 = (length-n*s1-nn*s2)/s3):((myC3==2)?(*c2=(length-n*s1-nn*s2)/s3):(*c3=(length-n*s1-nn*s2)/s3));
        }
      }
  }
  return number;
}
#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  unsigned int c1, c2, c3;
// this
assert(hyperloop ( 2307, 769, 1538, 1538, 0, &c1, &c2, &c3 ) == 2);
assert(hyperloop ( 2709, 903, 1806, 1806, 0, &c1, &c2, &c3 ) == 2);
assert (hyperloop(0, 0, 0, 0, 0, &c1, &c2, &c3)==0);
assert ( hyperloop ( 226, 0, 0, 0, 226, &c1, &c2, &c3 ) == 1 && 0 * c1 + 0 * c2 + 0 * c3 + 226 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 226, 0, 0, 0, &c1, &c2, &c3 ) == 1 && 226 * c1 + 0 * c2 + 0 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 0, 226, 0, 0, &c1, &c2, &c3 ) == 1 && 0 * c1 + 226 * c2 + 0 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 0, 0, 226, 0, &c1, &c2, &c3 ) == 1 && 0 * c1 + 0 * c2 + 226 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 0, 226, 226, 0, &c1, &c2, &c3 ) == 1 && 0 * c1 + 226 * c2 + 226 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 226, 0, 226, 0, &c1, &c2, &c3 ) == 1 && 226 * c1 + 0 * c2 + 226 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 226, 226, 226, 0, &c1, &c2, &c3 ) == 1 && 226 * c1 + 226 * c2 + 226 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );
c1 = 42; c2 = 43; c3 = 44;
assert ( hyperloop ( 9, 0, 0, 0, -1, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( -9, 0, 0, 3, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 0, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 0, 0, 3, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 0, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 12, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 0, 12, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 0, 0, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 12, 12, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 0, 12, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 12, 12, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 12, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 0, 12, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 12, 0, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 0, 0, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 0, 0, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 4, 0, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 4, 0, 0, 3, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 0, 0, 0, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 0, 4, 5, 2, 7, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 3, 2, 0, 0, &c1, &c2, &c3 ) == 2 && 3 * c1 + 2 * c2 + 0 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 9 );
assert ( hyperloop ( 9, 3, 2, 14, 0, &c1, &c2, &c3 ) == 2 && 3 * c1 + 2 * c2 + 0 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 9 );
assert ( hyperloop ( 9, 3, 3, 3, 0, &c1, &c2, &c3 ) == 1 && 3 * c1 + 3 * c2 + 3 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 9 );
assert ( hyperloop ( 9, 1, 1, 1, 0, &c1, &c2, &c3 ) == 1 && 1 * c1 + 1 * c2 + 1 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 9 );
assert ( hyperloop ( 99999999, 1, 1, 1, 0, &c1, &c2, &c3 ) == 1 && 1 * c1 + 1 * c2 + 1 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 99999999 );
assert ( hyperloop ( 99999999, 99999997, 0, 0, 1, &c1, &c2, &c3 ) == 1 && 99999997 * c1 + 0 * c2 + 0 * c3 + 1 * ( c1 + c2 + c3 + 1 ) == 99999999 );
assert ( hyperloop ( 1869, 623, 1246, 1246, 0, &c1, &c2, &c3 ) == 2 && 623 * c1 + 1246 * c2 + 1246 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1869 );
assert ( hyperloop ( 1869, 1246, 623, 1246, 0, &c1, &c2, &c3 ) == 2 && 1246 * c1 + 623 * c2 + 1246 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1869 );
assert ( hyperloop ( 1869, 1246, 1246, 623, 0, &c1, &c2, &c3 ) == 2 && 1246 * c1 + 1246 * c2 + 623 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1869 );
// this
  assert (  hyperloop ( 226, 0, 0, 0, 226, &c1, &c2, &c3 ) == 1);
  assert ( hyperloop ( 100, 4, 7, 5, 0, &c1, &c2, &c3 ) == 42
           && 4 * c1 + 7 * c2 + 5 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 100 );
  assert ( hyperloop ( 12345, 8, 3, 11, 3, &c1, &c2, &c3 ) == 82708
           && 8 * c1 + 3 * c2 + 11 * c3 + 3 * ( c1 + c2 + c3 + 1 ) == 12345 );
  c1 = 8;
  c2 = 9;
  c3 = 10;
  assert ( hyperloop ( 127, 12, 8, 10, 0, &c1, &c2, &c3 ) == 0
           && c1 == 8
           && c2 == 9
           && c3 == 10 );
  assert ( hyperloop ( 127, 12, 8, 10, 3, &c1, &c2, &c3 ) == 4
           && 12 * c1 + 8 * c2 + 10 * c3 + 3 * ( c1 + c2 + c3 + 1 ) == 127 );
  assert ( hyperloop ( 100, 35, 0, 0, 10, &c1, &c2, &c3 ) == 1
           && c2 == 0
           && c3 == 0
           && 35 * c1 + 10 * ( c1 + 1 ) == 100 );
  assert ( hyperloop ( 100, 35, 0, 35, 10, &c1, &c2, &c3 ) == 1
           && c2 == 0
           && 35 * c1 + 35 * c3 + 10 * ( c1 + c3 + 1 ) == 100 );
  assert ( hyperloop ( 100, 35, 35, 35, 10, &c1, &c2, &c3 ) == 1
           && 35 * c1 + 35 * c2 + 35 * c3 + 10 * ( c1 + c2 + c3 + 1 ) == 100 );
  c1 = 42;
  c2 = 43;
  c3 = 44;
  assert ( hyperloop ( 9, 1, 2, 3, 10, &c1, &c2, &c3 ) == 0
           && c1 == 42
           && c2 == 43
           && c3 == 44 );
  assert ( hyperloop ( 226, 0, 0, 0, 226, &c1, &c2, &c3 ) == 1);
  return 0;
}
#endif /* __PROGTEST__ */
