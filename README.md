# Библиотека объектно-ориентированного программирования MyMatrix: Набор инструментов для операций с матрицами на C++

Этот репозиторий содержит исходный код библиотеки объектно-ориентированного программирования MyMatrix, библиотеки на C++, предназначенной для упрощения различных операций с матрицами.

## Описание проекта

Библиотека объектно-ориентированного программирования MyMatrix предоставляет объектно-ориентированный подход к работе с матрицами на языке C++. Она позволяет пользователям создавать объекты матриц, выполнять различные операции над ними (такие как сложение, вычитание, умножение, транспонирование и т. д.) и легко получать доступ к отдельным элементам.

## Используемые технологии

- **C++17:** Библиотека реализована с использованием современных функций языка C++ для повышения эффективности и безопасности.
- **Google Test:** Библиотека использует фреймворк Google Test для модульного тестирования, обеспечивая корректность и надежность реализованных функциональностей.
- **lcov и genhtml:** Эти инструменты используются для анализа покрытия кода, предоставляя информацию о полноте процесса тестирования.

## Функциональные возможности

- **Создание матриц:** Создание матриц разных размеров и их инициализация значениями.
- **Основные операции:** Выполнение операций сложения, вычитания, умножения (с использованием как матриц, так и скаляров) и транспонирования.
- **Расширенные операции:** Вычисление определителей, обратных матриц и дополнений матриц.
- **Доступ к элементам:** Доступ и модификация отдельных элементов матрицы с использованием интуитивного оператора индексации (i, j).
- **Перегрузка операторов:** Использование перегруженных операторов для краткого и читаемого кода при выполнении операций с матрицами.
- **Обработка ошибок:** Библиотека генерирует исключения для обработки некорректного ввода и обеспечения надежности.

## Инструкции по использованию библиотеки

1. Клонируйте репозиторий:

```bash
git clone https://github.com/your-username/MyMatrix_OOP.git
```

2. Постройте библиотеку:

```bash
cd MyMatrix_OOP/src
make
```

Это сгенерирует статический файл библиотеки `my_matrix_oop.a`.

3. Включите заголовочный файл в ваш проект на C++:

```cpp
#include "my_matrix_oop.h"
```

4. Создайте объекты матриц и выполняйте операции:

```cpp
// Создайте матрицу 2x2
MYMatrix matrix(2, 2);

// Задайте значения элементов
matrix(0, 0) = 1.0;
matrix(0, 1) = 2.0;
matrix(1, 0) = 3.0;
matrix(1, 1) = 4.0;

// Вычислите определитель
double determinant = matrix.Determinant();

// Обратите матрицу
MYMatrix inverse = matrix.InverseMatrix();

// Сложите две матрицы
MYMatrix sum = matrix + inverse;

// ... и многое другое!
```

5. Обратитесь к файлу `my_matrix_test.cc` для подробных примеров использования библиотеки.
