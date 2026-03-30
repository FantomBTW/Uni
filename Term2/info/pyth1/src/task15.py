import sys

def main():
    colors = ["red", "green", "blue"]
    print(colors[1])
    colors[-1] = "yellow"
    print(colors[::-1])

main()

