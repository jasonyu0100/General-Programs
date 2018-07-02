palindrome = input('Enter a palindrome: ')
while palindrome:
    palindrome = palindrome.lower()
    reverse = []
    original = []
    for a in palindrome:
        if a == '.' or a == '?' or a == '!' or a == ':' or a == ';' or a == '"' or a == '@' or a == '#' or a == '=' or a == ',' or a == ' ':
            pass
        else:
            reverse.append(a)
            original.append(a)
    reverse.reverse()
    reverse = ''.join(reverse)
    original = ''.join(original)
    if reverse == original:
        print("True")
    else:
        print("False")
    palindrome = input('Enter a palindrome: ')
