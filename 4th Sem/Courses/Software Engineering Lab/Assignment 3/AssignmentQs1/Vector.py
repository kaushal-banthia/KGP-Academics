# In this python file, only the definitions for the magic functions and the basic operations
# for the question segments are provided. There may be the need to add new functions or overload 
# existing ones as per the question requirements.

class Vector:
        
    def __init__(self, *args): 

        # if arg is an int(dimension)
        if isinstance(args[0], int): 
            self._coords = [0]*args[0]
        
        else:
            self._coords = args[0]      

    def __len__(self):
        # return the dimension of the vector
        return len(self._coords)

    def __getitem__(self, j):
        # return the jth coordinate of the vector

        if j >= len(self) or j < 0:
            return 'Index of out bounds'
        else:
            return self._coords[j]

    def __setitem__(self, j, val):
        # set the jth coordinate of vector to val
        if j >= len(self) or j < 0:
            return 'Index of out bounds'
        else:
            self._coords[j] = val

    def __add__(self, other):
        # u + v
        if len(self) == len(other):
            vec = Vector([i + j for (i, j) in zip(self._coords, other)])
            return vec
        else:
            return 'Not of equal lengths'
            
    def __eq__(self, other):
        # return True if vector has same coordinates as other
        return (self._coords == other)
    
    def __ne__(self, other):
        # return True if vector differs from other
        return not (self._coords == other)
    
    def __str__(self):
        # return the string representation of a vector within <>
        return '<' + ', '.join([str(i) for i in self._coords]) + '>'

    def __sub__(self, other):
        # Soln for Qs. 2
        if len(self) == len(other):
            vec = Vector([i - j for (i, j) in zip(self._coords, other)])
            return vec
        else:
            return 'Not of equal lengths'
    
    def __neg__(self):
        # Soln for Qs. 3
        vec = Vector([-i for i in self._coords])
        return vec
    
    def __rmul__(self, value):
        return (self * value) 
    
    def __mul__(self, other):
        # Soln for Qs. 4, 5 and 6
        if type(other) == int:
            vec = Vector([other * i for i in self._coords])
            return vec
        
        if len(self) == len(other):
            return sum([i * j for (i, j) in zip(self._coords, other)])
        else:
            return 'Not of equal lengths'

    
def main():
    v1 = Vector(5)
    v2 = Vector (7)
    v3 = Vector([1,2,3,4,5])
    v4 = Vector([10,20,30,40,50])

    
    # Add suitable print statements to display the results
    # of the different question segments

    # len function
    print('__len__ Function Testing')
    print('Length of ' + str(v1) + ' is ' + str(len(v1)))
    print('Length of ' + str(v2) + ' is ' + str(len(v2)))
    print('Length of ' + str(v3) + ' is ' + str(len(v3)))
    print('Length of ' + str(v4) + ' is ' + str(len(v4)))

    # get item function
    print()
    print('__getitem__ Function Testing')
    print('4th element of ' + str(v1) + ' is ' + str(v1[3]))
    print('5th element of ' + str(v3) + ' is ' + str(v3[4]))
    print('11nd element of ' + str(v4) + ' is ' + str(v4[10]))

    # set item function
    print()
    print('__setitem__ Function Testing')
    v1[3] = 10
    print('4th element of ' + str(v1) + ' after changing is ' + str(v1[3]))
    v3[4] = 10
    print('5th element of ' + str(v3) + ' after changing is ' + str(v3[4]))
    v4[10] = 10
    print('11nd element of ' + str(v4) + ' after changing is ' + str(v4[10]))

    # add function
    print()
    print('__add__ Function Testing')
    print(str(v1) + ' + ' + str(v3) + ' = ' + str((v1 + v3)))
    print(str(v3) + ' + ' + str(v4) + ' = ' + str((v3 + v4)))
    print(str(v2) + ' + ' + str(v4) + ' = ' + str((v2 + v4)))

    # equality function
    print()
    print('__eq__ Function Testing')
    print(str(v1) + ' == ' + str(v2) + ' : ' + str(v1 == v2))
    print(str(v2) + ' == ' + str(Vector(7)) + ' : ' + str(v2 == Vector(7)))
    print(str(v1) + ' == ' + str(v3) + ' : ' + str(v1 == v3))

    # inequality function
    print()
    print('__ne__ Function Testing')
    print(str(v1) + ' != ' + str(v2) + ' : ' + str(v1 != v2))
    print(str(v2) + ' != ' + str(Vector(7)) + ' : ' + str(v2 != Vector(7)))
    print(str(v1) + ' != ' + str(v3) + ' : ' + str(v1 != v3))

    # subtract function
    print()
    print('__sub__ Function Testing')
    print(str(v1) + ' - ' + str(v2) + ' = ' + str((v1 - v2)))
    print(str(v1) + ' - ' + str(v3) + ' = ' + str((v1 - v3)))
    print(str(v4) + ' - ' + str(v3) + ' = ' + str((v4 - v3)))

    # negation function
    print()
    print('__neg__ Function Testing')
    print('Negation of ' + str(v2) + ' gives: ' + str(-v2))
    print('Negation of ' + str(v3) + ' gives: ' + str(-v3))

    # mul function
    print()
    print('__mul__ and __rmul__ Function Testing')
    print('5 * ' + str(v1) + ' = ' + str(5 * v1))
    print('5 * ' + str(v2) + ' = ' + str(5 * v2))
    print('5 * ' + str(v3) + ' = ' + str(5 * v3))
    print('5 * ' + str(v4) + ' = ' + str(5 * v4))
    print(str(v1) + ' * 5 = ' + str(v1 * 5))
    print(str(v2) + ' * 5 = ' + str(v2 * 5))
    print(str(v3) + ' * 5 = ' + str(v3 * 5))
    print(str(v4) + ' * 5 = ' + str(v4 * 5))

    print()
    print('__mul__ Function Testing for Dot Product')
    print('Dot Product of ' + str(v1) + ' and ' + str(v2) + ' = ' + str(v1 * v2))
    print('Dot Product of ' + str(v1) + ' and ' + str(v3) + ' = ' + str(v1 * v3))
    print('Dot Product of ' + str(v3) + ' and ' + str(v4) + ' = ' + str(v3 * v4))
if __name__ == '__main__':
    main()
