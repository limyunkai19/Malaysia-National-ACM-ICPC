# python2 solution, O(n) fibonacci sequence

fib = [0]*500
fib[0] = fib[1] = fib[2] = 1
for i in range(3, 500):
    fib[i] = fib[i-1]+fib[i-2]

n = int(raw_input())
while n != -1:
    print "Hour {}: {} cow(s) affected".format(n, fib[n])

    n = int(raw_input())
