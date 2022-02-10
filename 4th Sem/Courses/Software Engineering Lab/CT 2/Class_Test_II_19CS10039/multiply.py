def multiply(*argv):  
    mult = 1
    for arg in argv:  
        mult *= arg
    print(mult)
    
if __name__ == '__main__':
    multiply(3, 4)
    multiply(3, 4, 5)
    multiply(3, 4, 5, 6)