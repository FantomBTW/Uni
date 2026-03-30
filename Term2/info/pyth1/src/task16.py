import sys

def main():
    spis = [5, 10, 15, 20, 25]
    print (spis[1:3])

    for i in range(len(spis)):
        spis[i]+=1
        print(spis[i])

main()

