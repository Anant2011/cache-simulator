# Cache Simulator & Cache-Aware Matrix Optimization

A computer architecture project implemented in C exploring two fundamental aspects of cache performance: **cache simulation** and **cache-aware program optimization**. The project focuses on understanding memory hierarchy behavior and applying locality-driven techniques to improve performance.

---

## Overview

This project consists of two independent components:

### Part A — Cache Simulator

Implemented a configurable cache simulator that models the behavior of a cache memory system under different configurations.

Features:

* Support for load (`L`), store (`S`), and modify (`M`) operations
* Configurable cache parameters:

  * Number of set index bits (`s`)
  * Associativity (`E`)
  * Block offset bits (`b`)
* LRU (Least Recently Used) replacement policy
* Memory trace processing
* Cache hit, miss, and eviction tracking

The simulator provides insight into how cache configuration and memory-access patterns affect performance.

---

### Part B — Cache-Aware Matrix Transpose

Implemented optimized matrix transpose kernels designed to minimize cache misses on a direct-mapped cache.

Optimized for:

* 32×32 matrices
* 64×64 matrices
* 61×67 matrices

Optimization techniques:

* Blocking / tiling
* Spatial locality optimization
* Temporal locality optimization
* Conflict miss reduction
* Cache-aware memory access patterns

The goal was to restructure memory accesses to maximize cache utilization and reduce costly memory operations.

---

## Cache Simulator

### Cache Organization

The simulator models a cache using:

```text
Memory Address
      │
      ▼
+-----+---------+--------+
| Tag | SetIdx  | Offset |
+-----+---------+--------+
      │
      ▼
   Cache Set
      │
      ▼
 Hit / Miss / Eviction
```

Each memory access is decomposed into tag, set index, and block offset fields to determine cache behavior.

---

### LRU Replacement Policy

When a cache set becomes full, the simulator evicts the least recently used block.

This policy is implemented by maintaining recency information for each cache line and updating it after every access.

---

### Output Metrics

For every memory trace, the simulator reports:

* Cache hits
* Cache misses
* Cache evictions

These metrics help analyze the effectiveness of different cache configurations and memory-access patterns.

---

## Cache-Aware Matrix Optimization

The transpose kernels were optimized specifically for cache performance rather than algorithmic complexity.

### 32×32 Matrix

* Used blocking techniques to maximize cache locality
* Achieved fewer than **300 cache misses**

### 64×64 Matrix

* Reduced conflict misses through carefully designed block traversal
* Used temporary storage strategies to avoid cache thrashing
* Achieved fewer than **1300 cache misses**

### 61×67 Matrix

* Applied non-square blocking strategies
* Improved locality across irregular matrix dimensions
* Achieved fewer than **2000 cache misses**

---

## Key Concepts Explored

* Cache organization
* Address decomposition
* Direct-mapped caches
* LRU replacement policy
* Spatial locality
* Temporal locality
* Conflict misses
* Cache-aware programming
* Memory hierarchy optimization
* Performance engineering

---

## Technologies

* C
* Computer Architecture
* Cache Simulation
* Memory Hierarchy
* Performance Optimization

---

## Repository Structure

```text
cache-simulator/
├── README.md
├── Makefile
├── cachelab.h
├── csim.c
├── trans.c
├── .gitignore
└── examples/
    ├── 1.trace
    ├── long.trace
    └── trans.trace
```

---

## Learning Outcomes

Through this project I gained practical experience with:

* Designing and implementing a cache simulator
* Modeling realistic cache behavior
* Implementing LRU replacement policies
* Analyzing memory-access traces
* Understanding memory hierarchy performance
* Applying locality-driven optimization techniques
* Writing cache-efficient code

---

## References

* Computer Systems: A Programmer's Perspective (CS:APP)
* Cache Lab (CMU)
* Linux Manual Pages
