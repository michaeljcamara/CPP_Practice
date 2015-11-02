C Bob Roos
C
C bycols.for -- process elements of a 2-dimensional array by columns.
C Part of an experiment to compare speed of row vs column operations;
C the other part is in program "byrows.for".
C
C To compile and run (with timing information) using the standard 
C "a.out" executable name:
C     f95 bycols.for
C     time  ./a.out
C
C To use some other name for the executable file:
C     f95 bycols.for -o someothername
C     time  ./someothername
C

C Create array a with 1000 rows and 1000 columns:
      integer,dimension(1000,1000) :: a
      integer r,c,k

C     Outer loop just repeats things 1000 times to magnify timing results
      do, k = 1,1000

C       Fill a, one column at a time:
        do, c = 1,1000
          do, r = 1,1000
            a(r,c) = r+c
          enddo
        enddo

      enddo
      stop
      end
