# PLtasks
Tasks for Perfomance Lab

task1
Напишите программу, которая рассчитывает и подает в стандартный вывод следующие значения:
 - 90 перцентиль
 - медиана
 - максимальное значение
 - минимальное значение
 - среднее значение
 
Входные данные:

Данные для расчетов считываются из файла, путь к которому подается в виде аргумента.
Числа в файле целые в пределах от -32 768 до 32 767.
Каждое число с новой строки.
В файле не более 1000 строк.

Вывод:
Вывод значений в указанной последовательности, каждое значение заканчивается символом новой
строки.
Все значения с точностью до сотых: 2.50 2.00 0.03.

Пример
Входные данные:
5
8
0
0
1
5
5
5
10
6

Вывод:
8.20
5.00
10.00
0.00
4.50

task2
Напишите программу, которая определяет положение точки относительно выпуклого
четырехугольника в двумерном пространстве.
Координаты фигуры считываются из файла No1. Это вершины четырехугольника, которые
располагаются в порядке обхода фигуры по часовой стрелке. 

Пример:
0 0
0 5.5
5.5 5.5
5.5 0

Координаты точек считываются из файла No2. 
Пример:
1.3 1.23
10 9
0 3
5.5 5.5
0 -1

Файлы передаются программе в качестве аргументов:
Файл с координатами четырехугольника - 1 аргумент;
Файл с координатами точек - 2 аргумент.
Количество точек от 1 до 100.
Координаты четырехугольника и точек – в диапазоне float.
Вывод каждого положения точки заканчивается символом новой строки.
Соответствия ответов:
0 - точка на одной из вершин
1 - точка на одной из сторон
2 - точка внутри
3 - точка снаружи
