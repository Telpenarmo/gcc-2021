def totalPairs(n, values):
    # Participants code will be here
    result = n-1
    for left in range(n-2):
        for right in range(left+2,n):
            ok = True
            for x in range(left+1,right):
                mid = values[x]
                if mid>values[left] or values[x]>values[right]:
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