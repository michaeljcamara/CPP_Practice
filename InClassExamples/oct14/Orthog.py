# Bob Roos
#
# To run this program, just type "python Orthog.py".
#
# "Orthogonality" (section 6.1.2, page 228 and section 7.1.5, page 301
# in Scott) means that language features "can be used in any combination."
# (Yes, this is vague!) 
#
# Most often we talk about DEGRES of orthogonality rather than an absolute 
# "yes, this language is orthogonal/no, this language isn't orthogoal" 
# categorization.
#
# In Python there is evidence of some orthogonality. Function "orth"
# takes its parameter and attempts to use various Python operations on
# it: printing, computing length, comparing (to int, string, list),
# converting (to int, string, list), and the 'in' operator (see if
# something is "in" x).


def orth(x):
   """ Test the input parameter for compatibility with a
    variety of functions and operations.
   """
   try:
     print "---------\nx =",x
   except:
     print "  *** not compatible with print"
   try:
     print "length x =",len(x)
   except:
     print "  *** not compatible with len(...)"
   try:
     print "type of x =",type(x)
   except:
     print "  *** not compatible with type(...)"
   try:
     print "comparing x to integer:",(x == 10)
   except:
     print "  *** not compatible with == int"
   try:
     print "comparing x to string:",(x == "hello")
   except: 
     print "  *** not compatible with == string"
   try:
     print "comparing x to list:",(x == [1,2,3])
   except:
     print "  *** not compatible with == list"
   try:
     print "converting x to int:",int(x)
   except:
     print "  *** not compatible with int(...)"
   try:
     print "converting x to string:",str(x)
   except:
     print "  *** not compatible with str(...)"
   try:
     print "converting x to list:",list(x)
   except:
     print "  *** not compatible with list(...)"
   try:
     print "testing 'in':",(10 in x)
   except:
     print "  *** not compatible with in"
     

orth(10)                  # testing int
orth(3.14)                # testing float
orth(True)                # testing boolean
orth("hello")             # testing string
orth([1,2,3])             # testing list
orth({10,20,30})          # testing set
orth({"a":10,"b":"hi"})   # testing dict
orth(('a','b','c'))       # testing tuple
orth(orth)                # testing function 

class MyClass:
  """ simple user-defined class for testing with 'orth' """
  def __init__(self,i):
    self.x = 10*i
    self.y = 20*i

a = MyClass(3)   # an object of class MyClass

orth(a)                   # testing class object
orth(MyClass)             # testing class
