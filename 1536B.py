def solve():
    n = int(input())
    arr = list(input())
    arr1 = set(arr)

    letters = [chr(i) for i in range(97, 97 + 26)]

    for letter in letters:
        if letter not in arr1:
            return letter
    arr1 = set(arr[i] + arr[i + 1] for i in range(n - 1))

    # print(arr1)
    for i in range(97, 97 + 26):
        for j in range(97, 97 + 26):
            word = chr(i) + chr(j)
            if word not in arr1:
                return word
    arr1 = set(arr[i] + arr[i + 1] + arr[i + 2] for i in range(n - 2))
    for i in range(97, 97 + 26):
        for j in range(97, 97 + 12):
            word = 'a' + chr(i) + chr(j)
            if word not in arr1:
                return word


if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())