```markdown
<div align="center">

МИНИСТЕРСТВО ТРАНСПОРТА РОССИЙСКОЙ ФЕДЕРАЦИИ  
ФЕДЕРАЛЬНОЕ АГЕНТСТВО ЖЕЛЕЗНОДОРОЖНОГО ТРАНСПОРТА  
Государственное бюджетное образовательное учреждение  
высшего образования  
**«ПЕТЕРБУРГСКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ  
ПУТЕЙ СООБЩЕНИЯ ИМПЕРАТОРА АЛЕКСАНДРА I»**  

Кафедра «ИНФОРМАЦИОННЫЕ И ВЫЧИСЛИТЕЛЬНЫЕ СИСТЕМЫ»  

---

Дисциплина: «Информатика»

<br><br><br>
<br><br><br>

### О Т Ч Е Т

### по лабораторной работе № 3

</div>

<br><br><br>
<br><br><br>

<div align="right">
  <table align="right" style="border: none;">
    <tr>
      <td style="text-align: left; border: none;">
        Выполнил студент<br>
        Факультета АИТ<br>
        Группы ИВБ-515<br>
      </td>
      <td style="text-align: right; border: none; vertical-align: bottom; padding-left: 50px;">
        Нартов С. А.<br>
        <br>
        <br>
      </td>
    </tr>
  </table>
</div>

<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br>

<div align="center">
  Санкт-Петербург<br>  
  2026<br>
</div>

# *Задача 1*
Дано римское число, преобразуйте его в целое число.

Листинг
```python
def rimToNum(s):
    rimNumbers = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
    prev = 0
    total = 0

    for symb in reversed(s):
        value = rimNumbers[symb]
        if prev > value:
            total -= value
        else:
            total += value
        prev = value
    return total
        

def main():
    print(rimToNum("MCMXCIV"))


if __name__ == "__main__":
    main()
```

# *Задача 2*
Дано n пар скобок, напишите функцию, чтобы сгенерировать все комбинации правильно построенных скобочных последовательностей.

Листинг
```python
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
```

# *Задача 3*
Дан массив строк strs, сгруппируйте анаграммы вместе. Вы можете вернуть ответ в любом порядке.

Листинг
```python
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
```
