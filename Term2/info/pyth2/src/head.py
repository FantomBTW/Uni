def findTwo(massive, target):
    seen = [];
    for i in range(len(massive)):
        diff = target - massive[i];
        # print(seen, diff, massive[i]);

        if diff in massive:
            return [i, massive.index(diff)];
        seen.append(diff);


def clearmass(massive):
    for i in range(len(massive)):
        
    

def main():
    print(findTwo([1,2,5,9], 14));


if __name__ == '__main__':main();
