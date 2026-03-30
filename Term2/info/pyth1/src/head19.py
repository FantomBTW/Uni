import pandas as pd

def getCntSex(data, sex):
    return (data['Sex'] == sex).sum()


def getCntSurvived(data):
    return round((data['Survived'].value_counts(normalize=True))*100, 2)


def getCntRich(data):
    classes = data["Pclass"].value_counts(normalize=True)
    fstClass = classes[1]
    
    return round(fstClass,2)


def ageToNum(age):
    if pd.isna(age):return None

    try:
        age = str(age).strip()
        if not age:return None
        age = age.replace(",",".")
        return float(age)
    except:
        return None


def getAgeStat(data):
    ages = data['Age'].apply(ageToNum) 
    avAge = round(ages.mean(), 2)
    medianAge = round(ages.median(), 2)
    return float(avAge), float(medianAge)

def corr(data):
    sibsp = pd.to_numeric(data['SibSp'], errors='coerce')
    parch = pd.to_numeric(data['Parch'], errors='coerce')
    return round(sibsp.corr(parch, method='pearson'), 2)
