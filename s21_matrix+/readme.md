### Класс матрицы

```cpp
class S21Matrix {
    private:
        // Attributes
        int _rows, _cols;         // Rows and columns
        double **_matrix;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();              // Default constructor
        ~S21Matrix();             // Destructor

        void sum_matrix(const S21Matrix& other); 
        // Other methods..
}
```

### Напоминание основных положений о матрице

Матрица - прямоугольная таблица чисел, расположенных в m стрках и n столбцах

```
    1 2 3
A = 4 5 6
    7 8 9
```

```
     1  2  3  4
В =  5  6  7  8
     9 10 11 12
```

Получить нужный элемент можно при помощи индексов, так
A[1,1] = 1, где первый индекс - номер строки, второй - номер столбца.

Порядок матрицы — это число ее строк или столбцов. \
Главная диагональ квадратной матрицы — это диагональ, идущая из левого верхнего в правый нижний угол. \
Прямоугольная матрица (В) — это матрица, у которой число строк не равно числу столбцов. \
Квадратная матрица (А) — это матрица у которой число строк равно числу столбцов.

### Операции над матрицами

| Операция    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `bool eq_matrix(const S21Matrix& other)` | Проверяет матрицы на равенство между собой |  |
| `void sum_matrix(const S21Matrix& other)` | Прибавляет вторую матрицы к текущей | различная размерность матриц |
| `void sub_matrix(const S21Matrix& other)` | Вычитает из текущей матрицы другую | различная размерность матриц |
| `void mul_number(const double num)` | Умножает текущую матрицу на число |  |
| `void mul_matrix(const S21Matrix& other)` | Умножает текущую матрицу на вторую | число столбцов первой матрицы не равно числу строк второй матрицы |
| `S21Matrix transpose()` | Создает новую транспонированную матрицу из текущей и возвращает ее |  |
| `S21Matrix calc_complements()` | Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее | матрица не является квадратной |
| `double determinant()` | Вычисляет и возвращает определитель текущей матрицы | матрица не является квадратной |
| `S21Matrix inverse_matrix()` | Вычисляет и возвращает обратную матрицу | определитель матрицы равен 0 |

| Метод    | Описание   |
| ----------- | ----------- |
| `S21Matrix()` | Базовый конструктор, инициализирующий матрицу некоторой заранее заданной размерностью |  
| `S21Matrix(int rows, int cols)` | Параметризированный конструктор с количеством строк и столбцов | 
| `S21Matrix(const S21Matrix& other)` | Конструктор копирования |
| `S21Matrix(S21Matrix&& other)` | Конструктор переноса |
| `~S21Matrix()` | Деструктор |

| Оператор    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `+`      | Сложение двух матриц  | различная размерность матриц |
| `-`   | Вычитание одной матрицы из другой | различная размерность матриц |
| `*`  | Умножение матриц и умножение матрицы на число | число столбцов первой матрицы не равно числу строк второй матрицы |
| `==`  | Проверка на равенство матриц (`eq_matrix`) | |
| `=`  | Присвоение матрице значений другой матрицы | |
| `+=`  | Присвоение сложения (`sum_matrix`)   | различная размерность матриц |
| `-=`  | Присвоение разности (`sub_matrix`) | различная размерность матриц |
| `*=`  | Присвоение умножения (`mul_matrix`/`mul_number`) | число столбцов первой матрицы не равно числу строк второй матрицы |
| `(int i, int j)`  | Индексация по элементам матрицы (строка, колонка) | индекс за пределами матрицы |