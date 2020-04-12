def lastDigit(m):
    return m - 10 * (m // 10)

q = int(input().strip())

for _ in range(q):
    [n, m] = [int(x) for x in input().strip().split(' ')]
    if n < m:
        print("0")
    else:
        lastDigitM = lastDigit(m)
        digits = list()
        for i in range(1, 11):
            if len(digits) == 0:
                digits.append(lastDigit(lastDigitM * i))
            elif digits[0] == lastDigit(lastDigitM * i):
                break
            else:
                digits.append(lastDigit(lastDigitM * i))   
        # for digit in digits:
        #     print (digit, end=' ')
        # print()
        cycleLength = digits.__len__()

        times = n // (m * cycleLength)
        # print ("whole cycles ", times)
        remainder = (n - m * cycleLength * times) // m
        # print ("partial cycles [ < {0}] {1}".format(cycleLength, remainder))
        partialSums = [0] * cycleLength
        partialSums[0] = digits[0]
        for i in range(1, cycleLength):
            partialSums[i] = partialSums[i - 1] + digits[i]
        s = times * partialSums[-1]
        if (remainder > 0):
            s = s + partialSums[remainder - 1] # because array in Python is indexed from 0
        # index = 0
        # for _ in range(remainder):
        #     s += digits[index]
        #     index = index + 1
        #     if index >= len(digits):
        #         index = 0
        print(s)