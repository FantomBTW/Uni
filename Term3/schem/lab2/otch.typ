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


#import "../smth.typ": title

#title(number: "2")

//--- отчёт ---

//--- 1 ---
#text(weight:"bold")[ 1.RS-триггер ] \

#image("./scrs/1rsdiag.png")

#text(weight:"bold")[ Пояснения: ] \
Как видно из диаграммы, S=0 всегда устанавливает значение на 1, а R=0 сбрасывает на 0.
Если оба значения равны 0, то Q=nQ, что логическая ошибка, поэтому R=0 и S=0 - запрещённое состояние.


//--- 2 ---
#text(weight:"bold")[ 2.D-триггер ] \

#image("./scrs/2ddiag.png")

#text(weight:"bold")[ Пояснения: ] \
Во всех дальнейших схемах выходные значения меняются только после сигнала clock.\
В D триггере при подаче clock сигнал начинает соответствовать сигналу на входе D.

#pagebreak()

//--- 3 ---
#text(weight:"bold")[ 3.JK-триггер ] \

#image("./scrs/3jkdiag.png")

#text(weight:"bold")[ Пояснения: ] \
Поведение JK триггера аналогично поведению RS триггера. При подаче сигнала J, Q становится 1. 
При подаче K, Q становится 0. При обоих нулях состояние сохраняется, а при обоих единицах - инвертируется.


//--- 4 ---
#text(weight:"bold")[ 4.D-триггер на основе JK ] \

#image("./scrs/4jkddiag.png")

#text(weight:"bold")[ Пояснения: ]
Поведение полностью идентично поведению обычного D триггера.


#pagebreak()


//--- 5 ---
#text(weight:"bold")[ 5.T-триггер на основе D ] \

#image("./scrs/5dtdiag.png")

#text(weight:"bold")[ Пояснения: ]
При подаче сигнала на T и clock, сигнал инвертируется.



//--- 6 ---
#text(weight:"bold")[ 6.T-триггер на основе JK ] \

#image("./scrs/6jktdiag.png")

#text(weight:"bold")[ Пояснения: ]
поведение полностью идентично поведению T триггера на основе D триггера.


#pagebreak()


= Вывод

Я, с помощью программы logisim evolution изучил поведение триггеров в реальном времени.
