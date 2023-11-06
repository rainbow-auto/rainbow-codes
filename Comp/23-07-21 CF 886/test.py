import bisect
import sys
from collections import deque
from math import gcd, isqrt
from collections import Counter, defaultdict
import heapq
from functools import reduce
import operator
from functools import lru_cache
 
 
def find_gcd(numbers):
    result = numbers[0]
    for number in numbers[1:]:
        result = gcd(result, number)
    return result
 
 
def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    sqrt_n = isqrt(n)
    for i in range(3, sqrt_n + 1, 2):
        if n % i == 0:
            return False
    return True
 
 
# 最小公倍数
def lcm(a, b):
    return a * b // gcd(a, b)
 
 
def factors(n):
    result = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            result.append(i)
            if n // i != i:  # Avoid duplicates if n is a perfect square
                result.append(n // i)
    return result
 
input = sys.stdin.readline
 
 
def readList():
    return list(map(int, input().split()))
 
 
def readInt():
    return int(input())
 
 
def readInts():
    return map(int, input().split())
 
 
def readStr():
    return input().strip()
 
 
def solve():
    n = readInt()
    counter = Counter(readInts())
 
    answer = 0
    for j in range(1, n + 1):
        res = factors(j)
        tmp = 0
        for num in res:
            if num in counter:
                tmp += counter[num]
        answer = max(answer, tmp)
 
    return answer
 
 
for _ in range(int(input())):
    print(solve())