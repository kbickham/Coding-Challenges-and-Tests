def checkio(number: int) -> int:
#begin solution
    prod=1
    wordnum = str(number)
    for i in str(number):
        n = int(i)
        if n!=0:
            prod*=n       
    return prod
#end solution

if __name__ == '__main__':
    print('Example:')
    print(checkio(123405))
    
    # These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio(123405) == 120
    assert checkio(999) == 729
    assert checkio(1000) == 1
    assert checkio(1111) == 1
    print("Coding complete? Click 'Check' to review your tests and earn cool rewards!")
