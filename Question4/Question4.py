def totalPairs(n, values):
    # Participants code will be here
    result = 0
    max = 0

    for left in range(n-1):
        end = n if max == left else max+1
        max = left+1
        result += 1
        for right in range(left+2, end):
            if values[right-1] > values[left]:
                break
            if values[right] > values[max]:
                max = right
                result += 1

    return result

if __name__ == "__main__":
    n = int(input())
    values = list(map(int, input().split()))
    answer = totalPairs(n, values)
    print(answer)