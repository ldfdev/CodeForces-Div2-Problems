def pretty_p(w):
    return ''.join(('a' * w[1],
                    'b' * w[2],
                    'c' * w[3],
                    'd' * w[4],
                    'e' * w[5]))


words = []
def five_uple(word):
    uple = [0] * 6
    # it is guaranteed that w is in "abcde"
    for w in word:
        uple[ord(w) - ord('a') + 1] += 1
    uple[0] = len(word)
    return uple

def solve():
    global words

    n = int(input())
    words = [five_uple(input()) for _ in range(n)]
    words_in_interesting_story = 0
    for index in range(1, 6):
        # try form an interesting story considering letter index as the dominant one
        words_in_this_story = 0
        total_letters = 0
        total_index_letter = 0
        # counting only the ocurences of letter index doesn't wor
        # counting the ration of letter index over length of word doesn't work
        sorter = lambda x: 2 * x[index] - x[0]
        words.sort(key=sorter, reverse=True)
        for i in range(n):
            total_letters += words[i][0] # total letters in words[i]
            total_index_letter += words[i][index] # index letter is in turn: a, b, c, d, e    
            if 2 * total_index_letter <= total_letters:
                break
            words_in_this_story += 1
        words_in_interesting_story = \
            max(words_in_interesting_story,
                 words_in_this_story)
    return words_in_interesting_story


if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())