

if __name__=='__main__':
    pages = int(input())
    misteries = [0] + list(map(lambda t: int(t), input().split()))
    days = 0
    now = 1
    while now <= pages:
        days += 1
        # print('In day %d read from %d to ' % (days, now), end='')
        read_up_to = misteries[now]
        while now < read_up_to:
            now += 1
            if misteries[now] > read_up_to:
                read_up_to = misteries[now]
        # print('%d' % (now))
        now += 1
        
    print(days)