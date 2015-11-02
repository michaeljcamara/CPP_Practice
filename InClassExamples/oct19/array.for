C Bob Roos
C  Demonstration of column-major order in Fortran (specifically, Fortran 95)
C
C To compile and run using the standard "a.out" executable name:
C     f95 array.for
C     ./a.out
C
C To use some other name for the executable file:
C     f95 array.for -o someothername
C     ./someothername
C
C Just for fun, I've included some other things in this program that
C illustrate things like the "implicit" statement, an example of an
C "implied do-loop" (in the first "write" statement), and (throughout)
C a demonstration of the fact that Fortran is a "CASE INSENSITIVE"
C language. I have also adopted a number of old-fashioned Fortran
C usages (but this is more due to my age--I remember Fortran IV) that
C have been superseded by more "modern" constructs.

C Create a 4-by-2 array and a linear array of size 8, then "union" them
C (i.e., make them share the same memory). ("Equivalence" is like the
C "union" structure in C)

      IMPlIciT iNteGER (a-z)
      integer,dIMenSiOn(4,2) :: i1
      INtegEr,dimension(8) :: I2
      eQUiVaLENce (I1,i2)

C Fill and print the linear array:
      do 10 j = 1,8
10      i2(j) = 10*j

      print *,"Elements of i2:"
      write(*,'(8i3)')(i2(j),j=1,8)

C Now print the elements of the two-dimensional array that shares space:
      PrinT *,"Elements of i1 by rows:"

      dO 30 j = 1,4
        do 20 k = 1,2
20        WriTe(*,'(i3)',advance='no'),i1(j,k)
30      print *
      stop
      end
