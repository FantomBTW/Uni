def skobki(cnt):
    posl = ['('];

    while True:
        new = [];
        for i in range(len(posl)):
            if posl[i].count("(") != cnt:
                if posl[i].count("(") == posl[i].count(")"):
                    new.append(posl[i]+"(");
                else:
                    new.append(posl[i]+")"); new.append(posl[i]+"(");
            else:
                new.append(posl[i]+")");
        posl = new;
        if posl[0].count('(') + posl[0].count(')') == cnt*2:
            break;
    return posl;


def main():
    print(skobki(7));


if __name__ == "__main__":
    main()
