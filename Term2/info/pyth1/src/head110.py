import matplotlib.pyplot as plt

def graphTask(x,y, color, title, xlbl, ylbl, grid, tyl):
    # Построение графика
    plt.plot(x, y, label="Линия данных", color="green", linestyle=tyl)
    plt.xlabel(xlbl)         
    plt.ylabel(ylbl)         
    plt.title(title)  # Заголовок
    plt.grid(grid)              
    plt.legend()                
    plt.savefig('myGraph.png')

def taskOne():
    x = [0,1,2,3,4]
    y = [q**2 for q in x]
    color = "blue"
    title = "Function y=x^2"
    xlbl = "x"
    ylbl = "x^2"
    grid = True
    tyle = "--"
    graphTask(x,y, color, title, xlbl, ylbl, grid, tyle)

    plt.close()

def taskTwo():
    categories = ["Яблоки", "Бананы", "Апельсины"]
    quantities = [45, 30, 55]

    plt.bar(categories, quantities, color="red", edgecolor='black', linewidth=1.5)
    
    plt.title("Продажи фруктов за неделю")
    plt.xlabel("Фрукты")         
    plt.ylabel("Продажи (кг)")         
    plt.grid(True)
    
    plt.savefig('diagram.png')
    plt.close()
    #Захардкодить реально проще...

def taskThree():
    x = [1, 2, 3]
    y_graph = [2, 3, 5]
    y_bar = [3, 2, 4]
    
    plt.plot(x, y_graph, color='purple', label='Линейный график')
    plt.scatter(x, y_bar, color='orange', marker='o', label='Точечный график')
    
    # Подписи и заголовок
    plt.xlabel('X')
    plt.ylabel('Y')
    
    # Легенда и сетка
    plt.legend()
    plt.grid(True)
    
    plt.savefig('compare.png')
    plt.close()
