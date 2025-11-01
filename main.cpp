
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

int main ()
{
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
