C Bob Roos
C  Demonstration of user-defined index ranges in Fortran
C
C To compile and run using the standard "a.out" executable name:
C     f95 array2.for
C     ./a.out
C
C To compile and run using some other executable name
C     f95 array2.for -o someothername
C     ./someothername


C The array x has 11 rows and 11 columns, but the actual row numbers
C are -10, -9, ..., 0 and the column numbers are 50, 51, ..., 60:
      real,dimension(-10:0,50:60):: x
      integer row, col,r,c

      do, row = -10,0
        do, col = 50,60
          x(row,col) = sqrt(real(col+row))
        enddo
      enddo

      print *,"  Values of sqrt(r+c) for r = -10..0, c = 50..60:"
      write (*,'("    ",11I6)',advance='no')(c,c=50,60)
      print *
      write (*,'(i4,11f6.2)',advance='no')(r,(x(r,c),c=50,60),r=-10,0)
      print *
      stop
      end
