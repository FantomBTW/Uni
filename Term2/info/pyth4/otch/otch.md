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

### по лабораторной работе № 4

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
Дана целочисленная матрица matrix размером m x n, обладающая следующими двумя свойствами:
Каждая строка отсортирована в неубывающем порядке.␍
Первое целое число каждой строки больше последнего целого числа предыдущей строки.
Дано целое число target. Верните true, если target присутствует в матрице, или false в противном случае.

# Листинг
import sys;

def searchMatrix(matrix, target):
    m = len(matrix)
    n = len(matrix[0])
    
    """
    left, right = 0, m * n - 1

    while left <= right:
        mid = (left + right) // 2

        # Преобразуем индекс mid в координаты строки и столбца
        row = mid // n
        col = mid % n

        mid_element = matrix[row][col]

        if mid_element == target:
            return True
        elif mid_element < target:
            left = mid + 1
        else:
            right = mid - 1

    return False
    """

def main():
    matrix = [
        [1,  3,  5,  7],
        [10, 11, 16, 20],
        [23, 30, 34, 60]
    ]
    searchMatrix(matrix, sys.argv[1]);
    print(searchMatrix(matrix, 3))  # Вывод: True
    print(searchMatrix(matrix, 13)) # Вывод: False

if __name__ == "__main__":
    main()
```

# *Задача 2*
Дана целочисленная матрица matrix размером m x n, обладающая следующими двумя свойствами:
Каждая строка отсортирована в неубывающем порядке.
Первое целое число каждой строки больше последнего целого числа предыдущей строки.
Дано целое число target. Верните true, если target присутствует в матрице, или false в противном случае.

# Листинг
```python
import sys


def exist(board, word):
    def dfs(r, c, index):
        # in func for vars
        if index == len(word):
            return True

        if (r < 0 or r >= rows or c < 0 or c >= cols or 
            board[r][c] != word[index]):
            return False

        # attended
        temp = board[r][c]
        board[r][c] = '#'
    
        found = (dfs(r + 1, c, index + 1) or
                dfs(r - 1, c, index + 1) or
                dfs(r, c + 1, index + 1) or
                dfs(r, c - 1, index + 1))

        # restoring
        board[r][c] = temp

        return found

    rows, cols = len(board), len(board[0])
    

    # looking in every cell
    for i in range(rows):
        for j in range(cols):
            if dfs(i, j, 0):
                return True
                
    return False


def main(word):
    board = [
                ["a", "b", "c", "e"],
                ["s", "f", "c", "s"],
                ["a", "d", "e", "e"],
            ]
    print(exist(board, word));


if __name__ == "__main__":
    main(sys.argv[1])
```
