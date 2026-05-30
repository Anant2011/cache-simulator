# Cache Simulator & Cache-Aware Matrix Optimization

A computer architecture project implemented in C that models cache behavior through simulation and applies cache-aware optimization techniques to improve memory-system performance.

---

## Overview

This project consists of two major components:

### 1. Cache Simulator

Implemented a configurable cache simulator supporting:

* Load (`L`)
* Store (`S`)
* Modify (`M`) operations
* Configurable cache parameters (`s`, `E`, `b`)
* LRU replacement policy

The simulator processes memory traces and reports:

* Cache hits
* Cache misses
* Evictions

---

### 2. Cache-Aware Matrix Transpose

Implemented specialized matrix transpose kernels for:

* 32×32 matrices
* 64×64 matrices
* 61×67 matrices

The optimizations focus on:

* Blocking / tiling
* Spatial locality
* Temporal locality
* Conflict miss reduction
* Cache-aware memory access patterns

By restructuring memory accesses and exploiting locality, the transpose kernels significantly reduce cache misses and improve memory-system performance.

---

## Cache Architecture

A memory address is decomposed into:

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

The simulator models cache behavior using configurable set index bits (`s`), associativity (`E`), and block size (`b`).

---

## LRU Replacement Policy

The simulator maintains recency information for each cache line and evicts the least recently used block when a set becomes full.

This models realistic cache behavior and enables accurate hit/miss/eviction analysis across different cache configurations.

---

## Performance Results

### 32×32 Matrix

* Achieved fewer than **300 cache misses**

### 64×64 Matrix

* Achieved fewer than **1300 cache misses**
* Reduced conflict misses through optimized block traversal and temporary buffering

### 61×67 Matrix

* Achieved fewer than **2000 cache misses**
* Used non-square blocking strategies to improve cache locality

---

## Key Concepts Explored

* Cache organization
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
│
├── csim.c
├── trans.c
├── cachelab.h
├── Makefile
├── README.md
├── .gitignore
│
└── examples/
    ├── 1.trace
    ├── long.trace
    └── trans.trace
```

---

## Learning Outcomes

Through this project I gained practical experience with:

* Cache simulation and analysis
* Address decomposition and cache organization
* LRU replacement strategies
* Memory hierarchy behavior
* Locality-driven optimization
* Performance-oriented systems programming
* Cache-aware algorithm design

---

## References

* Computer Systems: A Programmer's Perspective (CS:APP)
* Cache Lab (CMU)
* Linux Manual Pages
