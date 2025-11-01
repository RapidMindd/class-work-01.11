
#include <iostream>

void destroy(int ** mtx, size_t created) {
    for (size_t i = 0; i < created; ++i) {
        delete[] mtx[i];
    }
    delete[] mtx;
}

int ** create(size_t rows, size_t cols) {
    size_t created = 0;
    int ** mtx = new int * [rows];
    try {
        for (; created < rows; ++created) {
            mtx[created] = new int[cols];
        }
    } catch (const std::bad_alloc &e) {
        destroy(mtx, created);
        throw;
    }
    return mtx;
}

int ** construct(int ** mtx, int init, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            mtx[i][j] = init;
        }
    }
    return mtx;
}

void input (int ** mtx, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cin >> mtx[i][j];
        }
    }
}

void output (int ** mtx, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        std::cout << mtx[i][0];
        for (size_t j = 1; j < cols; ++j) {
            std::cout << " " << mtx[i][j];
        }
        std::cout << "\n";
    }
}

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows) {
    int ** table = new int * [rows];
    size_t created = 0;
    size_t current = 0;
    try {
        for (size_t i = 0; i < rows; ++i) {
            table[i] = new int[lns[i]];
            created += 1;
            for (size_t j = 0; j < lns[i]; ++j) {
                table[i][j] = t[current];
                current += 1;
            }
        }
    } catch (const std::bad_alloc &e) {
        destroy(table, created);
        throw;
    }
    return table;
}

int main ()
{
    int t[] = {2, 2, 2, 3, 3, 42};
    size_t n = 4;
    size_t lns[] = {3, 2, 1};
    size_t rows = 3;
    int ** result = nullptr;
    try {
        result = convert(t, n, lns, rows);
    } catch (const std::bad_alloc & e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    for (size_t i = 0; i < rows; ++i) {
        std::cout << result[i][0];
        for (size_t j = 1; j < lns[i]; ++j) {
            std::cout << " " << result[i][j];
        }
        std::cout << "\n";
    }
    destroy(result, rows);


    size_t r = 0, c = 0;
    std::cin >> r >> c;
    if (!std::cin) {
        std::cerr << "incorrect input\n";
        return 1;
    }
    int ** matrix = nullptr;
    try {
        matrix = create(r, c);
    } catch (const std::bad_alloc & e) {
        std::cerr << e.what() << "\n";
        return 1; 
    }
    construct(matrix, 0, r, c);
    input (matrix, r, c);
    if (!std::cin) {
        std::cerr << "incorrect input\n";
        destroy(matrix, r);
        return 1;
    }
    output(matrix, r, c);
    destroy(matrix, r);
}
