# find the last ten digits of sum of n^n from 1 to 1000
m=10000000000
s=0
for i in range(1,1001):
    s=(i**i +s)%m
print(s)