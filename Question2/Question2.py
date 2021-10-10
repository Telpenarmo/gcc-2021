

def securitiesBuying(z, security_value):
    def makePair(x, y):
        return (x, y)

    def pairKey(pair):
        return pair[0]

    z = int(z[0])
    no_of_stocks=0
    pairs = []
    index = 1
    for item in security_value:
        pairs.append((int(item), index))
        index += 1
       
    pairs.sort(key=pairKey)

    sum = 0
    for pair in pairs:
        for _ in range(pair[1]):
            sum += pair[0]
            if sum > z: return no_of_stocks
            no_of_stocks += 1
           
    return no_of_stocks;


def main():
    z= input().split()
    security_value = []
    security_value = input().split()
    no_of_stocks_purchased=securitiesBuying(z,security_value)
    print(no_of_stocks_purchased)




if __name__ == '__main__':
    main()