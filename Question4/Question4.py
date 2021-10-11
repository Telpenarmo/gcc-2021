def totalPairs(n, values):
    # Participants code will be here
    result = n-1
    greater = [None] * n
    for i in range(n):
        greater[i] = [None] * n
        for j in range(n):
            greater[i][j] = values[i] > values[j]

    for left in range(n-2):
        for right in range(left+2, n):
            ok = True
            for mid in range(left+1, right):
                if greater[mid][left] or greater[mid][right]:
                    ok = False
                    break
            if ok:
                result += 1
    return result


if __name__ == "__main__":
    n = int(input())
    values = list(map(int, input().split()))
    answer = totalPairs(n, values)
    print(answer)
