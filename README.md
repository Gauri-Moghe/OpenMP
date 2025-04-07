
# Cholesky Decomposition Optimization

This project demonstrates how OpenMP (Open Multi-Processing) can significantly accelerate Cholesky Decomposition of large symmetric positive-definite matrices in C++ through multi-threaded parallelization.



## Overview

Cholesky Decomposition is used to factor a symmetric, positive-definite matrix **A** into the product:

```
A = L × Lᵀ
```

Where:
- **L** is a lower triangular matrix
- **Lᵀ** is the transpose of **L**

This repo compares two implementations:
- **Original**: Serial nested loop approach
- **Optimized**: Parallelized using OpenMP (`#pragma omp parallel for`)


## Files

| File              | Description |
|-------------------|-------------|
| `original.cpp`    | Serial Cholesky Decomposition |
| `optimized.cpp`   | OpenMP-accelerated Cholesky Decomposition |
| `OpenMP_report.pdf` | Report detailing algorithm and OpenMP optimization strategy |



## Performance

The OpenMP version achieved a **~4.76× speedup** over the serial version by parallelizing the outer loop with OpenMP.



## Compilation & Execution

### Compile - Original Version

```bash
g++ -O3 -o original original.cpp
./original
```

### Compile OpenMP - Optimized Version

```bash
g++ -fopenmp -O3 -o optimized optimized.cpp
./optimized
```

- `-fopenmp`: Enables OpenMP support
- `-O3`: Enables high-level optimizations



## OpenMP Optimizations Used

- `#include <omp.h>` for multi-threading
- `#pragma omp parallel for` on outer loop
- `omp_set_num_threads(14)` to use 14 threads for maximum parallelism



## Credits

**Developed by**: Gauri Shashank Moghe  
**Algorithm Source**: [Cholesky Decomposition – GeeksForGeeks](https://www.geeksforgeeks.org/cholesky-decomposition-matrix-decomposition)  
**OpenMP Reference**: Intel / GCC documentation



## License

This project is released under the [MIT License](https://opensource.org/licenses/MIT).
