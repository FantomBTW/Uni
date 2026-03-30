import pandas as pd
import head19 as hd

def main():
    data = pd.read_csv('titanic.csv', \
            index_col = 'PassengerId', \
            encoding='cp1251', \
            sep=';')

    
    maleCnt = hd.getCntSex(data, 'male')
    femaleCnt = hd.getCntSex(data, 'female')
    print("1.", femaleCnt, maleCnt)

    print("2.",hd.getCntSurvived(data))

    print("3.", hd.getCntRich(data))

    print("4.", hd.getAgeStat(data))

    print("5.", hd.corr(data))


if __name__ == "__main__":
    main()
