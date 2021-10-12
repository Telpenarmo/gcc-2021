
def sol(n: str):
    max = 0
    maxRepeated = False
    current = 0
    for c in n:
        if c == "1":
            if current > max:
                max = current
                maxRepeated = False
            elif current == max:
                maxRepeated = True
            current = 0
        else:
            current += 1
    if current > max:
        max = current
        maxRepeated = False
    elif current == max:
        maxRepeated = True

    if maxRepeated or max % 2 == 0:
        return "B"
    return "A"

# do not edit below code


def main():
    n = input()
    print(sol(n))


if __name__ == '__main__':
    main()
