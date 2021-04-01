#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct TCar
{
  struct TCar              * m_Next;
  char                     * m_Model;
} TCAR;

typedef struct TEmployee
{
  struct TEmployee         * m_Next;
  struct TCar              * m_Car;
  char                     * m_Name;
} TEMPLOYEE;

typedef struct TOffice
{
  TEMPLOYEE                * m_Emp;
  TCAR                     * m_Car;
} TOFFICE;

#endif /* __PROGTEST__ */

TOFFICE          * initOffice   ()
{
  TOFFICE *newborn  = (TOFFICE *) malloc (sizeof(*newborn));
  newborn->m_Car = NULL;
  newborn->m_Emp = NULL;
  return newborn;
}

void renameMe(char **dest, const char *sour){
  *dest = (char*)malloc(strlen(sour)*sizeof(char)+1);
  *dest[0] = '\0';
  strcat(*dest, (char*)sour);
}

void               addEmployee  ( TOFFICE         * office,
                                  const char      * name )
{
  TEMPLOYEE *littleStar = (TEMPLOYEE *)malloc(sizeof(*littleStar));
  renameMe(&(littleStar->m_Name), name);
  littleStar->m_Next = office->m_Emp;
  office->m_Emp = littleStar;
  littleStar->m_Car = NULL;

}
void               addCar       ( TOFFICE         * office,
                                  const char      * model )
{
  TCAR *planet = (TCAR *)malloc(sizeof(*planet));
  renameMe(&(planet->m_Model), model);
  planet->m_Next = office->m_Car;
  office->m_Car = planet;
}

// This is function for copying previous structure's car into a new one
void copyCar(TOFFICE *ds, TOFFICE *sr){
  if (sr->m_Car){
    TCAR *carSr = sr->m_Car, *carDs = (TCAR*)malloc(sizeof(*carDs)), *prev = NULL;
    renameMe(&(carDs->m_Model), carSr->m_Model );
    ds->m_Car = carDs;
    carDs->m_Next = NULL;
    if (carSr->m_Next){
      do{
        carSr = carSr->m_Next;
        prev = (TCAR*)malloc(sizeof(*prev));
        carDs->m_Next = prev;
        carDs = prev;
        renameMe(&(carDs->m_Model),carSr->m_Model );
        carDs->m_Next = NULL;
      }while(carSr->m_Next);
    }
  }
}
// End of copying of car to new structure

// Beginning of function for returning a position of car in old structure
int findCar(TCAR * car, TCAR * mov){
  int i = 1;
  while(car != mov){
    car = car->m_Next;
    i++;
  }
  return i;
}
// End of function I mentioned few lines above

TCAR * returnCar(TCAR *car, int number){
  for (int i = 1; i<number; i++)
    car = car->m_Next;
  return car;
}

void copyEmp(TOFFICE * ds, TOFFICE * sr){

  if (sr->m_Emp){
    int leCar = 0;
    TEMPLOYEE * newOne = (TEMPLOYEE*)malloc(sizeof(* newOne)) , * oldOne = sr->m_Emp, * tmpOne = NULL;
    ds->m_Emp = newOne;
    renameMe(&(newOne->m_Name),oldOne->m_Name );
    newOne->m_Next = NULL;
    if (oldOne->m_Car){
      leCar = findCar(sr->m_Car, oldOne->m_Car);
      newOne->m_Car = returnCar(ds->m_Car, leCar);
    }
    else
      newOne->m_Car = NULL;
    if (oldOne->m_Next){
      do{
        oldOne = oldOne->m_Next;
        tmpOne = (TEMPLOYEE*)malloc(sizeof(*tmpOne));
        newOne->m_Next = tmpOne;
        newOne = tmpOne;
        renameMe(&(newOne->m_Name),oldOne->m_Name );
        newOne->m_Next = NULL;
        if (oldOne->m_Car){
          leCar = findCar(sr->m_Car, oldOne->m_Car);
          newOne->m_Car = returnCar(ds->m_Car, leCar);
        }
        else
          newOne->m_Car = NULL;
      }while(oldOne->m_Next);
    }
  }
}

TOFFICE          * cloneOffice  ( TOFFICE         * office )
{
  TOFFICE *b = initOffice();
  copyCar(b, office);
  copyEmp(b, office);
  return b;
}

void freeEmp(TEMPLOYEE * employee){
  TEMPLOYEE *help;
  while(employee){
    help = employee->m_Next;
    free(employee->m_Name);
    free(employee);
    employee = help;
  }
}

void freeCar(TCAR * car){
  TCAR *help;
  while(car){
    help = car->m_Next;
    free(car->m_Model);
    free(car);
    car = help;
  }
}

void               freeOffice   ( TOFFICE         * office )
{
  freeEmp(office->m_Emp);
  office->m_Emp = NULL;
  freeCar(office->m_Car);
  office->m_Car = NULL;
  free(office);
  office = NULL;
}
#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  TOFFICE * a, *b;
   char tmp[100];
   assert ( sizeof ( TOFFICE ) == 2 * sizeof ( void * ) );
   assert ( sizeof ( TEMPLOYEE ) == 3 * sizeof ( void * ) );
   assert ( sizeof ( TCAR ) == 2 * sizeof ( void * ) );
   a = initOffice ();
   addEmployee ( a, "Peter" );
   addEmployee ( a, "John" );
   addEmployee ( a, "Joe" );
   addEmployee ( a, "Maria" );
   addCar ( a, "Skoda Octavia" );
   addCar ( a, "VW Golf" );
   a -> m_Emp -> m_Car = a -> m_Car;
   a -> m_Emp -> m_Next -> m_Next -> m_Car = a -> m_Car -> m_Next;
   a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Car = a -> m_Car;
   assert ( a -> m_Emp
            && ! strcmp ( a -> m_Emp -> m_Name, "Maria" )
            && a -> m_Emp -> m_Car == a -> m_Car );
   assert ( a -> m_Emp -> m_Next
            && ! strcmp ( a -> m_Emp -> m_Next -> m_Name, "Joe" )
            && a -> m_Emp -> m_Next -> m_Car == NULL );
   assert ( a -> m_Emp -> m_Next -> m_Next
            && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Name, "John" )
            && a -> m_Emp -> m_Next -> m_Next -> m_Car == a -> m_Car -> m_Next );
   assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next
            && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
            && a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Car == a -> m_Car );
   assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
   assert ( a -> m_Car
            && ! strcmp ( a -> m_Car -> m_Model, "VW Golf" ) );
   assert ( a -> m_Car -> m_Next
            && ! strcmp ( a -> m_Car -> m_Next -> m_Model, "Skoda Octavia" ) );
   assert ( a -> m_Car -> m_Next -> m_Next == NULL );
   b = cloneOffice ( a );
   strncpy ( tmp, "Moe", sizeof ( tmp ) );
   addEmployee ( a, tmp );
   strncpy ( tmp, "Victoria", sizeof ( tmp ) );
   addEmployee ( a, tmp );
   strncpy ( tmp, "Peter", sizeof ( tmp ) );
   addEmployee ( a, tmp );
   strncpy ( tmp, "Citroen C4", sizeof ( tmp ) );
   addCar ( a, tmp );
   b -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Car = b -> m_Car -> m_Next -> m_Next;
   assert ( a -> m_Emp
            && ! strcmp ( a -> m_Emp -> m_Name, "Peter" )
            && a -> m_Emp -> m_Car == NULL );
   assert ( a -> m_Emp -> m_Next
            && ! strcmp ( a -> m_Emp -> m_Next -> m_Name, "Victoria" )
            && a -> m_Emp -> m_Next -> m_Car == NULL );
   assert ( a -> m_Emp -> m_Next -> m_Next
            && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Name, "Moe" )
            && a -> m_Emp -> m_Next -> m_Next -> m_Car == NULL );
   assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next
            && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Name, "Maria" )
            && a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Car == a -> m_Car -> m_Next );
   assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next
            && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "Joe" )
            && a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Car == NULL );
   assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
            && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "John" )
            && a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Car == a -> m_Car -> m_Next -> m_Next );
   assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
            && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
            && a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Car == a -> m_Car -> m_Next );
   assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
   assert ( a -> m_Car
            && ! strcmp ( a -> m_Car -> m_Model, "Citroen C4" ) );
   assert ( a -> m_Car -> m_Next
            && ! strcmp ( a -> m_Car -> m_Next -> m_Model, "VW Golf" ) );
   assert ( a -> m_Car -> m_Next -> m_Next
            && ! strcmp ( a -> m_Car -> m_Next -> m_Next -> m_Model, "Skoda Octavia" ) );
   assert ( a -> m_Car -> m_Next -> m_Next -> m_Next == NULL );
   assert ( b -> m_Emp
            && ! strcmp ( b -> m_Emp -> m_Name, "Maria" )
            && b -> m_Emp -> m_Car == b -> m_Car );
   assert ( b -> m_Emp -> m_Next
            && ! strcmp ( b -> m_Emp -> m_Next -> m_Name, "Joe" )
            && b -> m_Emp -> m_Next -> m_Car == NULL );
   assert ( b -> m_Emp -> m_Next -> m_Next
            && ! strcmp ( b -> m_Emp -> m_Next -> m_Next -> m_Name, "John" )
            && b -> m_Emp -> m_Next -> m_Next -> m_Car == b -> m_Car -> m_Next );
   assert ( b -> m_Emp -> m_Next -> m_Next -> m_Next
            && ! strcmp ( b -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
            && b -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Car == NULL );
   assert ( b -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
   assert ( b -> m_Car
            && ! strcmp ( b -> m_Car -> m_Model, "VW Golf" ) );
   assert ( b -> m_Car -> m_Next
            && ! strcmp ( b -> m_Car -> m_Next -> m_Model, "Skoda Octavia" ) );
   assert ( b -> m_Car -> m_Next -> m_Next == NULL );
   freeOffice ( a );
   freeOffice ( b );
   return 0;
}
#endif /* __PROGTEST__ */
