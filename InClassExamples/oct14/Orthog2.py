# Bob Roos
#
# To run this program, just type "python Orthog2.py".
#
# More on orthogonality in Python.
#
# For most arithmetic operators, "chains" of operations are legal, e.g.,
#       a + b * c / d * e + / g - h
#
# The same is true of boolean operators:
#       x && y || z && ! w && v || p
#
# But what about relational operators--is this legal?
#       a < b < c <= d > e != f == g
#
# Yes! (It would not be legal in Java. It is legal in C, but does not behave
# as you would expect.)

a = 10
b = 20
c = 30
d = 30
e = 29
f = 30
g = 30

# This is the same as:
#      "if a < b && b < c && c <= d && d > e && e != f && f == g:"

if a < b < c <= d > e != f == g:
   print "yes"
