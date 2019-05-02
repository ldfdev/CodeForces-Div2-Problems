


def reduceTrailing0(n, counter):
    while (n == (10 * (n // 10))):
        # counter = counter + 1 # new local variable counter is created
        # counter += 1 # augmented assigment operator
        n //= 10
        # print ("n= ", n)
    return n;

def foundSecondTime(n):
    if ((foundSecondTime.boolean == True) and (n == foundSecondTime.num)):
        return False
    if n == foundSecondTime.num:
        foundSecondTime.boolean = True
    return True
foundSecondTime.boolean = False


if __name__ == '__main__':
    counter = 0 # even though n is self reachable, we start at 0 because the first n smaller than 10 is counted twice by this algorithm
    n = int(input())
    foundSecondTime.num = n
    reduceTrailing0(n, counter);
    boolValue = True
    while (foundSecondTime(n) == True):
        if ((n < 10) and (boolValue == True)):
            boolValue = False
            foundSecondTime.num = n
        counter += 1
        n = n + 1
        n = reduceTrailing0(n, counter);
        # print("n= ", n)
    print(counter)
