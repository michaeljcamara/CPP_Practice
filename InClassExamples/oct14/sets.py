# Bob Roos
#
# Demonstration of the "set" data type in Python.
#
# To run this program, type "python sets.py".

a = {1,2,3,4,5,6,7,8,9,10}
b = {i*i for i in range(1,5)}

print "a =",a
print "b =",b
print "a union b =",a | b
print "a intersection b =",a & b
print "a minus b =",a - b
print "b minus a =",b - a
print "elements in a^b:",
for x in a^b:
  print x,
print
