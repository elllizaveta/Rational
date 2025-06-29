# Rational

`В C++ существует множество встроенных типов данных для работы с целочисленной арифметикой и арифметикой над числами с плавающей точкой. Однако при вычислениях над последними возможны ошибки округления, которые могут накапливаться при сложных (состоящих из множества операций) вычислениях. Если при работе с иррациональными числами округлений избежать не получится, то в программах, требующих манипуляций только с рациональными числами, все вычисления можно свести к точной целочисленной арифметике. Именно это вам и предстоит проделать в данном задании.`

## Детали реализации
Класс для работы с рациональными числами Rational.

Рациональное число представляется двумя взаимно простыми целыми числами — числителем и положительным знаменателем. Этот инвариант необходимо поддерживать при выполнении любых операций над объектами класса Rational.

## Публичный интерфейс класса включает:

- Конструктор по умолчанию, который инициализирует число нулем;
- Неявный конструктор преобразования от целых чисел (должен работать следующий код Rational x = 5;). Не забудьте добавить комментарий // NOLINT (см. замечания);
- Конструктор от двух целых чисел (числитель и знаменатель). При этом не гарантируется, что числа взаимно простые и ненулевые (об этом далее);
- Методы GetNumerator() и GetDenominator(), возвращающие числитель и знаменатель соответственно;
- Методы SetNumerator(int) и SetDenominator(int), устанавливающие числитель и знаменатель в требуемые значения;
- Бинарные арифметические операции (+, -, /, *) и их присваивающие версии (+=, -=, /=, *=);
- Унарные операции (+, -), а также префиксные и постфиксные инкременты и декременты (++, --);
- Операции сравнения;
- Операции ввода из потока и вывода в поток (>>, <<);

При выводе числа в поток выводим его в виде несократимой дроби в формате `<числитель>/<знаменатель>` либо `<числитель>`, если знаменатель равен 1. Ввод осуществляется в том же формате (но дробь на входе необязательно несократима).

## Деление на 0

При делении на 0 (в операции деления или при установке знаменателя в 0) программа должна сообщать об ошибке. Для этих целей в C++ есть механизм исключений. Исключение — это объект некоторого класса, который унаследован от стандартного класса ошибки библиотеки C++.
