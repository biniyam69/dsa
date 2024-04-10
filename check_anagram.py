def is_anagram(word_1: str, word_2: str) -> bool:
    """Returns True if the given words are anagrams."""

    h = [0] * 26

    for c in word_1:
        h[ord(c) - ord('a')] += 1

    for c in word_2:
        h[ord(c) - ord('a')] -= 1

    for i in h:
        if i != 0:
            return False
        
    return True