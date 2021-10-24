"""
cipher.py

Caesar Cipher in Python

"""

def first_index_of (char , string) :
    """
    signature: str , str -> int
    precondition: len (char) == 1
    returns the non-negative index of the fist occurrence of char in string,
    if it doesn't occur, returns -1.
    """
    index = 0
    while index < len (string) :
        if string [index] == char :
            return index
        index += 1
    return -1

alphabet = 'abcdefghijklmnopqrstuvwxyz'

def alphabet_index (letter) :
    """
    signature : str -> int
    precondition: len (letter) == 1 and letter . lower () in alphabet
    returns the index of the letter in the alphabet (case insensitive).
    e.g. 'a' |-> 0 , 'A' |-> 0 , 'z' |-> 25 , 'Z' |-> 25
    """
    return first_index_of (letter.lower () , alphabet)

def shift_letter (letter , shift) :
    """
    signature: str , int -> str
    precondition: len (letter) == 1 and letter . lower () in alphabet
    returns the letter shift places to the right of the argument letter in the alphabet,
    preserving case and wrapping around from 'z' back to 'a' if necessary.
    If shift is negative, then shifts to the left instead.
    """
    shifted_letter = alphabet [(alphabet_index (letter) + shift) % len (alphabet)]
    if letter.isupper () :
        return shifted_letter.upper ()
    else :
        return shifted_letter

def encode (message , key) :
    """
    signature: str , int -> str
    returns the caeser cipher encoded version of message, in which
    each alphabetic character has been right-shifted by key many places.
    """
    acc = ''
    for char in message :
        if char.lower () in alphabet :
            acc += shift_letter (char , key)
        else :
            acc += char
    return acc

def decode (message , key) :
    """
    signature: str , int -> str
    returns the caeser cipher decoded version of message, in which
    each alphabetic character has been left-shifted by key many places.
    """
    return encode (message , - key)
