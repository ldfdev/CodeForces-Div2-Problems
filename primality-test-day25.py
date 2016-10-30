#Miller Rabin Primality Test

#Erathostene Sieve
import sys,time
def isprime(n):
    now_t=time.time()
    var = True
    n_limit=n//2
    lissy=[True]*(n_limit)
    for i in range(2,n_limit):
        if lissy[i]==True:
            for j in range(i*i,n_limit,i):
                lissy[j]=False
            if(n%i == 0):
                var=False
                print("---Execution(sec): %s" % (time.time()-now_t))
                break
    if var==True:
        return 'Prime'
    else:
        return 'Not prime'
    return ''
T = int(input())
for i in range(T):
    x=int(input().strip())
    now_t=time.time()
    print(isprime(x))
    print("---Execution(sec): %s" % (time.time()-now_t))
