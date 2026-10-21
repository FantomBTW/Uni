#set page(
  paper: "a4",
  margin: (
    left: 15mm,
    right: 15mm,
    top: 18mm,
    bottom: 18mm,
  ),
)
#set text(
  font: "Liberation Serif",
  size: 14pt,
  lang: "ru"
)

#let title(number: "") = [


  #align(center)[
    МИНИСТЕРСТВО ТРАНСПОРТА РОССИЙСКОЙ ФЕДЕРАЦИИ \
    ФЕДЕРАЛЬНОЕ АГЕНТСТВО ЖЕЛЕЗНОДОРОЖНОГО ТРАНСПОРТА \

    #text(size:12pt)[
      Государственное бюджетное образовательное учреждение \
      высшего образования \
    ]
    #text(size:14pt, weight:"bold")[
      «ПЕТЕРБУРГСКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ 
      ПУТЕЙ СООБЩЕНИЯ ИМПЕРАТОРА АЛЕКСАНДРА I»
    ]

  ]

  #line(length: 100%)
  #align(center)[
    Кафедра «Информационные и Вычислительные Системы» #linebreak()
    Дисциплина «Схемотехника»
  ]

  #v(120pt)

  #align(center)[
    #text(size: 20pt, weight: "bold")[
      О Т Ч Ё Т
    ] #linebreak()
    *по лабораторной работе №#number*
  ]

  #v(120pt)

  #grid(
    columns: (1fr, 1fr),
    align: (left, right),
    [
      Выполнил студент \
      Факультета АИТ \
      Группы ИВБ-515
    ],
    [
      Нартов С.А.
    ],
  )

  #v(1fr)
  #align(center)[
    Санкт-Петербург \
    2026
  ]
  #pagebreak()
]
