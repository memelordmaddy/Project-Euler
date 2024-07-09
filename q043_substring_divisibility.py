#find the sum of all 0 to 9 pandigital numbers with the following property: d2d3d4 is divisible by 2, d3d4d5 is divisible by 3, d4d5d6 is divisible by 5, d5d6d7 is divisible by 7, d6d7d8 is divisible by 11, d7d8d9 is divisible by 13, and d8d9d10 is divisible by 17.
import itertools
pandigitals = []
permutations = itertools.permutations(range(10))
for permutation in permutations:
    if permutation[0] != 0:  
        pandigitals.append(''.join(map(str, permutation)))
sum=0
for i in range(1, len(pandigitals)):
    if int(pandigitals[i][1:4]) % 2 == 0 and int(pandigitals[i][2:5]) % 3 == 0 and int(pandigitals[i][3:6]) % 5 == 0 and int(pandigitals[i][4:7]) % 7 == 0 and int(pandigitals[i][5:8]) % 11 == 0 and int(pandigitals[i][6:9]) % 13 == 0 and int(pandigitals[i][7:10]) % 17 == 0:
        sum += int(pandigitals[i])
print(sum)