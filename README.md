# Программа — калькулятор.
## Часть 1. Построение постфиксной записи выражения (с использованием стека)
В стек записывается ( и выражение просматривается слева направо.
- Если встречается **операнд – число** – он сразу выводится на печать.
- Если встречается **(**, то она заносится в стек.
- Если встречается **)**, то из стека извлекаются находящиеся там знаки операций до ближайшей открывающей скобки, которая также удаляется из стека. Все эти знаки в порядке их извлечения печатаются.
- Когда встречается **знак бинарной операции**, то из стека извлекаются (до ближайшей открывающей скобки, которая сохраняется в стеке) знаки операций, старшинство которых больше либо равно старшинству данной операции, и они печатаются, после чего рассматриваемая операция заносится в стек.
- Когда встречается **знак унарной операции**, то рассматриваемая операция заносится в стек.
- Когда **ввод выражения закончен**, выполняются те же действия, которые выполнились бы, если встретилась ).

В постфиксной записи операнды и операции должны отделяться друг от друга как минимум одним знаком "пробел".

При вводе выражения признаком конца выражения считать '=' ,' \n' или конец файла на стандартном вводе. При чтении некорректного выражения программа должна печатать сообщение в поток stderr
## Часть 2. Интерпретация постфиксной записи (с использованием стека).
Выражение просматривается слева направо. Считается, что в постфиксной записи операнды и операции должны отделяться друг от друга как минимум одним знаком "пробел". (Остальные выражения считать некорректными и сообщать об этом в поток stderr).

Если встречается операнд (число) – его значение заносится в стек, а если встречается знак операции, то из стека извлекаются ее операнды (два – если операция двуместная, один – если одноместная) и над ним(и) выполняется операция. Результат ее выполнения заносится в стек. В конце вычисления выражения в стеке останется только одно число – результат, его нужно напечатать.
## Требования к заданию
1. Работа со стеком должна быть реализована в отдельном файле (функции push, pop, empty ...), этот файл будет компилироваться отдельно
2. Для него должен быть заголовочный файл (stack.h), который будет включаться в программы, использующие стек.
3. Заголовочный файл должен быть защищен от повторного включения
4. Должен быть написан makefile для сборки программы
5. При задании неверных входных данных программа должна выдавать сообщение об ошибке.
## Варианты записи выражений
1. Выражение содержит операции +, * , /, -(унарный), -(бинарный). В записи выражения допускаются скобки. Операнды – целые числа (int). Если в результате вычислений получено число не помещающееся в тип int, выдавать сообщение в поток ошибок, но вычисления продолжать.
2. Выражение содержит операции &&, || , !. В записи выражения допускаются скобки. Операнды – True, false (записанные как заглавными, так и строчными буквами).
3. Выражение содержит операции &&, ||, !. В записи выражения допускаются скобки. Операнды – целые числа (int). Результат логических операций получается таким же, как при их выполнении в языке Си.
4. Выражение содержит операции +, * , /, -(унарный), -(бинарный). В записи выражения допускаются скобки. Операнды – вещественные числа вида (double) c.d (c-целая часть, d – дробная часть, одна из них может быть пустой)
5. (\*) Выражение содержит операции +, * , -(унарный), -(бинарный). В записи выражения допускаются скобки. Операнды – целые числа произвольной длины (представлять их как строки).