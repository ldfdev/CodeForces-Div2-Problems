

def ascending(num):
    digit_count = len(list(d for d in str(num)))
    ref_digit = str(num)[0]
    return num >= int(''.join(ref_digit * digit_count))

def wholes_fun(num):
    return len([ch for ch in str(num)]) - 1

def solve():
    n = int(input())
    # 9 ordinary numbers between 1 and 10
    # 9 ordinary numbers between 11 and 100
    # 9 ordinary numbers between 101 and 1000
    wholes = wholes_fun(n)
    ordinary_numbers = 9 * wholes
    
    more = int(str(n)[0])
    if not ascending(n):
        more -= 1
    ordinary_numbers += more
    return ordinary_numbers
    
if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())