Принцип работы алгоритма Дийкстры

Есть граф, представляющий собой набор вершин, соединенных друг с другом ребрами с весами, которые обязательно должны быть представлены неотрицательными значениями
Сам алгоритм ищет кратчайший путь от одной вершины ко всем остальным. Это может быть полезно в разработке навигационных систем: алгоритм позволит найти наиболее оптимальный путь от стартовой точки маршрута к конечной
Итак, процесс работы:
1. Выбирается стартовая вершина, длина кратчайшего к ней пути (сумма весов вершин, через которые мы проходим) помечается как 0. Остальные вершины помечаются знаком бесконечности, поскольку к ним кратчайший путь еще не рассчитан. Стартовая вершина помечается как посещенная
2. Проходим к вершинам, которые соединены со стартовой вершиной ребром, отмечаем на них накопленный вес - сумма весов ребер, по которым мы прошли
3. Выбираем следующую, ближайшую вершину, повторяем пункт 2. Однако нам необходимо учитывать вершины, у которых уже есть какой-то накопленный вес. Если этот вес больше нашего накопленного, мы обновляем данные этой вершины: ставим наш вес
4. Повторяем пункт 3, пока все вершины не будут посещены
Результат работы данного алгоритма - список минимальных накопленных весов для каждой вершишны. Данный алгоритм можно усовершенствовать, добавив сохранение оптимальных маршрутов: наборов вершин с наименьшим накопленным весом, через которые мы проходим
