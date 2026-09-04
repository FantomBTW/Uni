#set page(
  paper: "a4",
  margin: (top: 1.5cm, bottom: 1.2cm, left: 3cm, right: 1.5cm),
)
#set text(font: "Times New Roman", size: 13pt, lang: "ru")
#set par(justify: false, leading: 0.55em)

// ---------- переменные для быстрого редактирования ----------
#let faculty = "Автоматизация и интеллектуальные технологии"
#let department = "Информационные и вычислительные системы"

#let work_type = "ЛАБОРАТОРНАЯ РАБОТА №2"
#let discipline = "Программирование"

#let group = "ИВБ-515"
#let student_name = "С.А. Нартов"

#let city = "Санкт-Петербург"
#let year = "2026г."

// вспомогательная функция: линия для подписи с подписью снизу
#let signline(width: 40%, caption: none) = align(center)[
  #line(length: width, stroke: 0.6pt)
  #if caption != none [
    #v(-0.3em)
    #text(size: 10pt)[#caption]
  ]
]
// --------------------------------------------------------------

#align(center)[
  #text(weight: "bold")[
    ФЕДЕРАЛЬНОЕ АГЕНТСТВО ЖЕЛЕЗНОДОРОЖНОГО \
    ТРАНСПОРТА
  ]
  #v(0.15em)
  Федеральное Государственное Бюджетное Образовательное Учреждение \
  Высшего Образования
  #v(0.15em)
  #text(weight: "bold")[
    «Петербургский Государственный Университет Путей Сообщения \
    Императора Александра I»
  ]
  #v(0.15em)
  #text(weight: "bold")[(ФГБОУ ВО ПГУПС)]
]

#v(0.2em)
#line(length: 100%, stroke: 0.8pt)
#v(0.2em)

Факультет #underline[«#faculty»] \
Кафедра #underline[«#department»]

#v(1.3em)

#align(center)[
  #text(weight: "bold")[#work_type] \
  по дисциплине \
  #text(weight: "bold")[«#discipline»]
]

#v(1.6em)

Выполнил: \
Обучающийся группы #group

#v(0.5em)
#grid(
  columns: (1fr, 1fr),
  signline(width: 70%, caption: "подпись, дата"),
  align(center)[
    #line(length: 70%, stroke: 0.6pt)
    #v(-0.3em)
    #student_name
    #v(-0.3em)
    #text(size: 10pt)[И. О. Фамилия]
  ],
)

#v(1.3em)

Исправить замечания: #box(width: 6cm, line(length: 100%, stroke: 0.6pt))
#v(0.4em)
#line(length: 100%, stroke: 0.6pt)
#v(0.4em)
#line(length: 100%, stroke: 0.6pt)
#v(0.4em)
#grid(
  columns: (1fr, 1fr),
  column-gutter: 1cm,
  [#line(length: 50%, stroke: 0.6pt)],
  signline(width: 70%, caption: "подпись, дата"),
)
#v(0.3em)
#line(length: 100%, stroke: 0.6pt)
#v(0.4em)
#line(length: 100%, stroke: 0.6pt)
#v(0.4em)
#line(length: 100%, stroke: 0.6pt)
#v(0.4em)
#grid(
  columns: (1fr, 1fr),
  column-gutter: 1cm,
  [#line(length: 55%, stroke: 0.6pt)],
  align(center)[
    #line(length: 70%, stroke: 0.6pt)
    #v(-0.3em)
    #text(size: 10pt)[И. О. Фамилия]
  ],
)

#v(1.6em)

Защита: #box(width: 5.5cm, line(length: 100%, stroke: 0.6pt))
#v(0.8em)
#grid(
  columns: (1fr, 1fr, 1fr),
  column-gutter: 1cm,
  signline(width: 90%, caption: "Зачтено/не зачтено"),
  signline(width: 90%, caption: "подпись, дата"),
  signline(width: 70%, caption: "И.О. Фамилия"),
)

#v(1fr)

#align(center)[
  #text(weight: "bold")[
    #city \
    #year
  ]
]
