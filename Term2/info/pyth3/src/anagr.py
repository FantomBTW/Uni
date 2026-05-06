import sys;

def sortWord(word):
    return "".join(sorted(word))

def anagr(strs):
    vocabulary = sorted(list(dict.fromkeys(sortWord(s) for s in strs)));
    # print(vocabulary);

    out = [[] for _ in range(len(vocabulary))];

    # print(len(out));

    for word in strs:
        sortedWord = sortWord(word);
        for i in range(len(vocabulary)):
            if sortedWord == vocabulary[i]:
                out[i].append(word);
                break;
    return out;
def main():
    strs = sys.argv[1:];
    print(anagr(strs));


if __name__ == "__main__":
    main()
