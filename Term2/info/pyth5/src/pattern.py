def wordPattern(pattern: str, s: str):
    words = s.split()
    
    if len(pattern) != len(words):
        return False
    
    char_to_word = {}  # map: char -> word
    word_to_char = {}  # map: word -> char
    
    for char, word in zip(pattern, words):
        if char in char_to_word:
            if char_to_word[char] != word:
                return False
        else:
            if word in word_to_char:
                return False
            char_to_word[char] = word
            word_to_char[word] = char
            
    return True;


def main():
    print(wordPattern("abba", "hi oh oh hi"));

if __name__ == "__main__":
    main()
