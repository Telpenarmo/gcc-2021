#!/bin/python3

import math
import os
import random
import re
import sys
from typing import List


def portfolio_profit_maximisation(maxSum: int, a: List[int], b: List[int]):
    a_prefixes: List[int] = [0]
    b_prefixes: List[int] = [0]
    sum = 0
    for item in a:
        sum += item
        if sum > maxSum:
            break
        a_prefixes.append(sum)
    sum = 0
    for item in b:
        sum += item
        if sum > maxSum:
            break
        b_prefixes.append(sum)

    result = 0
    j = 0
    i = 0
    j = len(b_prefixes) - 1
    for i in range(len(a_prefixes)):
        while j >= 0:
            temp = a_prefixes[i] + b_prefixes[j]
            pos = i+j
            if temp <= maxSum:
                if pos > result:
                    result = pos
                break
            j -= 1
    return result
    
if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    maxSum = int(first_multiple_input[2])

    a = list(map(int, input().rstrip().split()))

    b = list(map(int, input().rstrip().split()))

    result = portfolio_profit_maximisation(maxSum, a, b)

    print(result)
