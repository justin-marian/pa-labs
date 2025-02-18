# Programming Algorithms

A collection of programming assignments covering fundamental topics in **recursion, backtracking, combinatorics, greedy algorithms, dynamic programming (DP), and graph algorithms**.

---

## Structure

The repository is organized into different algorithmic topics, with each **lab containing a separate `build` folder** for compilation:

- **Recursion**: Tower of Hanoi, Subset Generation, etc.
- **Backtracking**: N-Queens, Permutations, Combinations.
- **Combinatorics**: Binomial Coefficients, Subsets.
- **Greedy Algorithms**: Activity Selection, Knapsack.
- **Dynamic Programming (DP)**: Fibonacci, LIS, Knapsack.
- **Graph Algorithms**: BFS, DFS, Dijkstra, Bellman-Ford.

Each **lab folder** contains a `build` directory with a `Makefile` to manage compilation.

---

## Setup & Compilation  

To compile and run programs, navigate to the corresponding **lab's `build/` folder** and use `make`:  

```bash
# Navigate to the build folder of a specific lab (e.g., shortest_path_algorithms)
cd ./src/shortest_path_algorithms/build

# Compile all programs in the lab
make

# Run a specific program (e.g., Dijkstra)
./dijkstra

# Clean binaries
make clean
```
