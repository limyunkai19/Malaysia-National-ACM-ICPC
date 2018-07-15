# python2 solution, O(1), derive formular

tc = int(raw_input())

for _ in range(tc):
    n = int(raw_input())
    print ((n*(n+1)*(n+2))//6)**2
