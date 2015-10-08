'''
 Michael Camara
 Honor Code Pledge: This work is mine unless otherwise cited
 Lab 5: 
 Due Date: 10/15/15
'''

###############################################
### Problem 1
###############################################

def count(list1, x):
    # Ensure that the given list object is, indeed, a list
    if not isinstance(list1, list):
        print "The first argument is NOT a list.  Please try again with a valid list"
        return
    
    ## Increment counter when an element in list1 matches x
    counter = 0
    for i in range(len(list1)):
        if list1[i] == x:
            counter += 1
    return counter

## Test cases
print "PROBLEM 1 OUTPUT"
someList = [1, 1, 2, 2, 3, 3, 3, 3, 4, 5, 5, 5]
print "List = ", someList
for i in range(6):
    print "x = ", i, "count = ", count(someList, i)

###############################################
### Problem 2
###############################################

def common(list1, list2):
    # Ensure that the given arguments are lists
    if not isinstance(list1, list) or not isinstance(list2, list):
        print "Both arguments are NOT lists.  Please try again."
        return
    
    # Check list1 for common elements in list2. If found, add to new list
    intersection = []
    for i in range(len(list1)):
        if list1[i] in list2:
            intersection.insert(0, list1[i])
    return intersection

## Test cases        
print "\nPROBLEM 2 OUTPUT"
someList1 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
someList2 = [5, 6, 7, 8, 9, 10, 11, 12, 12, 13]
print "List 1 = ", someList1
print "List 2 = ", someList2
print "Common elements: ", common(someList1, someList2)

###############################################
### Problem 3
###############################################

def unique(list1, list2):
    # Ensure that the given arguments are lists
    if not isinstance(list1, list) or not isinstance(list2, list):
        print "Both arguments are NOT lists.  Please try again."
        return
    
    uniqueList = []
    
    # Check list1 for elements NOT found in list2, add to uniqueList
    for i in range(len(list1)):
        if list1[i] not in list2:
            uniqueList.append(list1[i])
    
    # Check list2 for elements NOT found in list1, add to uniqueList
    for i in range(len(list2)):
        if list2[i] not in list1:
            uniqueList.append(list2[i])
            
    return uniqueList

print "\nPROBLEM 3 OUTPUT"
print "List 1 = ", someList1
print "List 2 = ", someList2
print "Unique elements: ", unique(someList1, someList2)

###############################################
### Problem 4
###############################################

def rotate(list1, k):
    # Ensure that the given list object is, indeed, a list, and k is an integer
    if not isinstance(list1, list) or not isinstance(k, (int, long)):
        print "You have entered invalid arguments. Please enter a list and an integer value"
        return
    
    # Use slices to rotate the list by the indicated amount
    rotatedList = list1[k:] + list1[:k]
    return rotatedList

## Test cases
print "\nPROBLEM 4 OUTPUT"
print "Original List = ", someList1
for i in range(-3, 4):
    print "Rotate amount: ", i, "| Rotated List: ", rotate(someList1, i)