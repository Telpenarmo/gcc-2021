#!/bin/python3

import os
import sys


def theHackathon(n, m, a, b, f, s, t):
    
    empls = {}
    for i in range(n):
        inp = input().split(" ")
        if inp[0] in empls and empls[inp[0]] == inp[1]:
            continue
        empls[inp[0]] = inp[1]
    sorted_names = sorted(empls)
    n = len(empls)
    
    trees = []
    deps = []
    for i in range(n):
        name = sorted_names[i]
        dep = empls[name]
        dep = int(dep)-1
        empls[name] = i
        deps.append(dep)
        data = [0, 0, 0, 1]
        data[dep] = 1
        trees.append(data)
    max = 0
    for i in range(m):
        req = input().split()
        l_name = req[0]
        li = empls[l_name]
        r_name = req[1]
        ri = empls[r_name]

        path = []
        while isinstance(trees[li], int):
            path.append(li)
            li = trees[li]
        for i in path:
            trees[i] = li

        path = []
        while isinstance(trees[ri], int):
            path.append(ri)
            ri = trees[ri]
        for i in path:
            trees[i] = ri

        ld = trees[li]
        rd = trees[ri]
        (bigger, smaller) = (ri, li) if ld[3] < rd[3] else (li, ri)
        new_data = [ld[0]+rd[0], ld[1]+rd[1], ld[2]+rd[2], ld[3]+rd[3]]
        if new_data[3] <= b and new_data[0] <= f and new_data[1] <= s and new_data[2] <= t:
            if new_data[3] > max:
                max = new_data[3]
            trees[smaller] = bigger
            trees[bigger] = new_data

    if max < a:
        #print("no groups")
        return
    for i in range(n):
        j = i
        while isinstance(trees[j], int):
            j = trees[j]
        if trees[j][3] == max:
            print(sorted_names[i])


if __name__ == '__main__':
    inputdata = input().split()

    n = int(inputdata[0])

    m = int(inputdata[1])

    a = int(inputdata[2])

    b = int(inputdata[3])

    f = int(inputdata[4])

    s = int(inputdata[5])

    t = int(inputdata[6])

    theHackathon(n, m, a, b, f, s, t)
