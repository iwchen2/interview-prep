
def isUnique(word):
    # mydict = {}
    # for letter in word:
        # if(letter in mydict):
            # return False
        # else:
            # mydict[letter] = 1
    # return True
    for i in range(len(word)):
        for j in range(i+1,len(word)):
            if(word[i] == word[j]):
                return False
    return True

def checkPermutation(word1, word2):
    # str1_dict = {}
    # for letter in word1:
        # if(letter in str1_dict):
            # str1_dict[letter] += 1
        # else:
            # str1_dict[letter] = 1

    # str2_dict = {}
    # for letter in word2:
        # if(letter in str2_dict):
            # str2_dict[letter] += 1
        # else:
            # str2_dict[letter] = 1

    # for key1 in str1_dict.keys():
        # if(key1 not in str2_dict or str1_dict[key1] != str2_dict[key1]):
            # return False
    # return True

    if(len(word1) != len(word2)):
        return False

    sort_word1 = sorted(word1)
    sort_word2 = sorted(word2)

    for i in range(len(sort_word1)):
        if(sort_word1[i] != sort_word2[i]):
            return False

    return True

def main():
    # print(isUnique('mommy'))
    # print(isUnique('test'))
    # print(isUnique('Test'))
    print(checkPermutation('asdfghjlk','lkjhgfdsa'))
    print(checkPermutation('qwerty','rtyqwe'))
    print(checkPermutation('listen','silent'))
    print(checkPermutation('hello','world'))

if __name__ == "__main__":
    main()

