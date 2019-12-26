def checkio(array):
   w = 0;
   m = 0;
   if len(array) == 0:     
     return 0
   else:
       # for m in array :
       count = 0;
       while count<(len(array)):
        #if m < len(array):
           if count%2 == 0:
                w+=int(array[count])
       # if m > len(array):
           count+=1;
       return w*int(array[-1])
    


#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    print('Example:')
    print(checkio([0, 1, 2, 3, 4, 5]))
    
    assert checkio([0, 1, 2, 3, 4, 5]) == 30, "(0+2+4)*5=30"
    assert checkio([1, 3, 5]) == 30, "(1+5)*5=30"
    assert checkio([6]) == 36, "(6)*6=36"
    assert checkio([]) == 0, "An empty array = 0"
    print("Coding complete? Click 'Check' to review your tests and earn cool rewards!")
