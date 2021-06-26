# identical with 1537E1.py

import itertools

def validate_prefix(s, prefix):
    n = len(s)
    source = 0
    for i in range(prefix, n):
        if s[i] > s[source]:
            return prefix
        elif s[i] == s[source]:
            source += 1
            if source == prefix:
                source = 0
            continue
        assert s[i] < s[source]
        prefix = i + 1
        source = 0
    return prefix


def determine_initial_prefix(s):
    prefix = 1
    while True:
        new_prefix = validate_prefix(s, prefix)
        if new_prefix == prefix:
            break
        prefix = new_prefix
    return prefix


def solve():
    n, k = [int(x) for x in input().split()]
    s = list(input())
    pref = determine_initial_prefix(s)
    return ''.join(itertools.islice(itertools.cycle(s[:pref]), k))


if __name__=='__main__':
    print(solve())