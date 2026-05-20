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
Переверните биты заданного 32-битного целого числа со знаком.

# Листинг
```python
import sys

def reverseBits(n):
    q = f"{n:032b}";
    qnew = q[::-1]
    return int(qnew, 2);

def main(n):
    print(reverseBits(int(n)));

if __name__ == "__main__":
    main(sys.argv[1])
```

# *Задача 2*
Даны шаблон pattern и строка s. Определите, соответствует ли s тому же шаблону.
Здесь «соответствует» означает полное совпадение, такое что существует биекция
между буквой в pattern и непустым словом в s. А именно:
● Каждая буква в pattern сопоставляется ровно одному уникальному слову в s.
● Каждое уникальное слово в s сопоставляется ровно одной букве в pattern.
● Никакие две буквы не сопоставляются одному и тому же слову, и никакие два
слова не сопоставляются одной и той же букве.
# Листинг
```python
def wordPattern(pattern: str, s: str):
    words = s.split()
    
    if len(pattern) != len(words):
        return False
    
    char_to_word = {}  # map: char -> word
    word_to_char = {}  # map: word -> char
    
    for char, word in zip(pattern, words):
        if char in char_to_word:
            if char_to_word[char] != word:
                return False
        else:
            if word in word_to_char:
                return False
            char_to_word[char] = word
            word_to_char[word] = char
            
    return True;


def main():
    print(wordPattern("abba", "hi oh oh hi"));

if __name__ == "__main__":
    main()
```
