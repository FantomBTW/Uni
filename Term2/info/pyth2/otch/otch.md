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

### по лабораторной работе № 2

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

<div align="center">
  Санкт-Петербург<br>  
  2026<br>
</div>

# *Задача 1*
Дан массив целых чисел nums и целое число target, вернуться индексы двух чисел, так что в сумме они составляют target.

Листинг
```python
def twoSum(nums, target):
    prev_map = {}
    
    for i, n in enumerate(nums):
        diff = target - n
        
        if diff in prev_map:
            return [prev_map[diff], i]
        
        prev_map[n] = i
    
    return []

def main():
    nums = [2, 7, 11, 15]
    target = 9
    print(f"indexes: {twoSum(nums, target)}")

if __name__ == "__main__":
    main()
```

# *Задача 2*
Напишите функцию для поиска самой длинной общей строки префикса среди массива строк.
Если общего префикса нет, верните пустую строку "".

Листинг
```python
def maxprefix(massive):
    i = 0
    stroka = []
    while 1:
        symbol = massive[0][i]
        if all(massive[x][i] == symbol for x in range(len(massive))):
            stroka.append(symbol)
        else:
            return ''.join(stroka)
        i += 1


def main():
    print(maxprefix(["flight", "flower", "flow"]))
    print(maxprefix(["flight", "flower", "sun"]))


if __name__ == "__main__":
    main()
```

# *Задача 3*
Дан целочисленный массив nums отсортировано в неубывающий порядок, удалить дубликаты на месте таким образом, что каждый уникальный элемент появляется только один раз. The относительный порядок элементы должны быть сохранены такой же.

Листинг
```python
def uniquelize(massive):
    uniqueNums = set()
    for i in range(len(massive)):
        if massive[i] in uniqueNums:
            massive[i] = '_'
        else:
            uniqueNums.add(massive[i])
    retmassive = [x for x in uniqueNums]
    while len(retmassive) < len(uniqueNums):
        retmassive.append('_')

    return len(uniqueNums), retmassive

    massive.sort()
    return len(uniqueNums), massive


def main():
    print(uniquelize([1, 1, 2, 2, 2, 2, 3, 6, 7]))


if __name__ == "__main__":
    main()
```

# *Задача 4*
Дан целочисленный массив nums и целое число val, удалить все вхождения val в nums на месте. Порядок элементов может быть изменен. Затем вернуться количество элементов в nums которые не равны val.
Рассмотрим количество элементов в nums которые не равны val быть k, чтобы вас приняли, вам необходимо сделать следующее:
	Изменить массив nums такой, что первый k элементы nums содержат элементы, которые не равны val. Остальные элементы nums не важны, как и размер nums.
	Возвращаться k.

Листинг
```python
def delElem(massive, deletable):
    k = 0
    i = 0
    while deletable in massive:
        if massive[i] == deletable:
            massive.remove(massive[i])
            k += 1
        else:
            i += 1
    return massive, k


def main():
    print(delElem([1, 2, 3, 4, 6, 6, 6], 6))
    return 0


if __name__ == "__main__":
    main()
```
