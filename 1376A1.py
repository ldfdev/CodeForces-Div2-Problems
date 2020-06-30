if __name__=='__main__':
    _ = int(input())
    numbers = list(map(int, input().split()))
    numbers.sort()
    numbers=map(str, numbers)
    print(' '.join(numbers))