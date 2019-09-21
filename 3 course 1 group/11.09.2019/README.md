## Основы программирования на C#

- [Основы программирования на С#](https://metanit.com/sharp/tutorial/1.5.php)
- [Видеокурс по языку программирования C# 7.0 и .NET Framework](https://www.youtube.com/playlist?list=PLL-k0Ff5RfqXGhAooRkUpzMLd6_Fpr13I)
- [ Введение в C# (видео)](https://stepik.org/lesson/59952/step/1?unit=37389)


### Лабораторная работа № 1. Работа с одномерными массивами.

- *Обязательным требованием для любой выполняемой задачи является соответствие кода [Settings.StyleCop](https://blog.submain.com/stylecop-detailed-guide/).*
- *Обязательным требованием для любой выполняемой задачи является наличие [XML-комментариев](https://docs.microsoft.com/ru-ru/dotnet/csharp/programming-guide/xmldoc/)  во всех библиотеках классов в коде.*
- *Обязательным требованием для любой выполняемой задачи является помещение логики решения задачи в проект типа  Class Library.*

- Реализовать [методы](https://visualgo.net/en/sorting?slide=1) пузырьковой, быстрой и сортировки слиянием для целочисленного массива (методы поместить в статический класс ArrayExtension, тип проекта Class Library).            
   
   Одномерный массив считать упорядоченным, если отношение порядка выполняется для элементов, индексы которых удовлетворяют заданному условию,  а само отношение порядка определяется некоторой функцией-ключем.       
   
   В качестве функции-ключа использовать:   
	a) модуль целочисленного значения элемента массива;  
	b) количество вхождений заданного символа c в p-ичном представлении элемента массива;   
	c) общее количество символов в p-ичном представлении элемента массива.   
   
   В качестве условия для индексов использовать:   
        a) четность;   
	b) нечетность;   
	c) кратность заданной цифре d.  
- Протестировать работу методов с использованием тестового фреймворка NUnit (MS Tests). Рассмотреть вариант тестирования массивов большой размерности, элементы которых генерируются случайным образом.    
- Используя [Sandcastle - Documentation Compiler for Managed Class Libraries](https://archive.codeplex.com/?p=sandcastle) создать техническую документацию в стиле MSDN по данной сборке. 

#### Варианты заданий.

| №	| Функция-ключ |	Условие для индекса	| Основание системы счисления p |	 Значение символа c | Значение цифры d |
| -------- | -------- | --------| --------|  -------- |  -------- |   
| 1. | a | c | - | - |	3 |
| 2. | a | a	| -	 | - |	- |
| 3.|	a | b	| - |	- |	- |
| 4. |	b | a	| 8 |	6 |	- |
| 5. |	b | b	| 2 |	0 |	- |
| 6. |	 b	| b	 |2 |	1 |	- |
| 7. |	b |	a |	16 |	A |	-|
| 8. |	b |	b |	16 |	F|	-|
| 9. |	b |	 a	 | 16 |	B  |	 -|
| 10. | b |	 b | 16|	 C	| - |
| 11. |	 b|	 c|	- |	D |	4 |
| 12.	| b	| c|	- |	 E|	 6|
|  13.| 	 c|	a|	8 |	7 	|- |
| 14.	| c	| b|	16| 	A |	 -|
|  15.| 	 c |	 c|	16	|D 	|3 |
| 16.|	 c	| c |	16 |	E	| 4|
| 17. |	 c|	 b|	8	|6 	||- |
|18. |	b 	| c|	8|	7| 	5 |