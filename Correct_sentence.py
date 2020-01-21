def correct_sentence(text: str) -> str:
 
    textnew=list(text)
    
    if ord(textnew[0])>=97:
        textnew[0]=chr(ord(textnew[0])-32)
    if (textnew[len(textnew)-1]) != '.':
         textnew.append('.')
    return "".join(textnew) 


if __name__ == '__main__':
    print("Example:")
    print(correct_sentence("greetings, friends"))
    
    # These "asserts" are used for self-checking and not for an auto-testing
    assert correct_sentence("greetings, friends") == "Greetings, friends."
    assert correct_sentence("Greetings, friends") == "Greetings, friends."
    assert correct_sentence("Greetings, friends.") == "Greetings, friends."
    assert correct_sentence("hi") == "Hi."
    assert correct_sentence("welcome to New York") == "Welcome to New York."
    
    print("Coding complete? Click 'Check' to earn cool rewards!")
