# Cache Simulator & Cache-Optimized Matrix Transpose

A systems programming project implemented in C focused on understanding cache behavior, memory hierarchy, and cache-aware performance optimization techniques.

## Overview

This project consists of two major components:

### 1. Cache Simulator
Implemented a configurable cache simulator supporting:
- Load (`L`)
- Store (`S`)
- Modify (`M`) operations
- Configurable cache parameters (`s`, `E`, `b`)
- LRU replacement policy

The simulator processes memory traces and reports:
- Cache hits
- Cache misses
- Evictions

---

### 2. Cache-Optimized Matrix Transpose
Implemented cache-efficient matrix transpose kernels optimized for:
- 32×32 matrices
- 64×64 matrices
- 61×67 matrices

The optimizations focus on:
- Blocking / tiling
- Spatial locality
- Temporal locality
- Conflict miss reduction
- Cache-aware memory access patterns

---

## Performance Results

### 32×32 Matrix
- Achieved fewer than **300 cache misses**

### 64×64 Matrix
- Achieved fewer than **1300 cache misses**
- Reduced conflict misses using optimized block traversal and temporary buffering

### 61×67 Matrix
- Achieved fewer than **2000 cache misses**
- Used non-square blocking strategies to improve cache locality

---

## Concepts Explored

- Cache organization
- Direct-mapped caches
- LRU replacement policy
- Spatial locality
- Temporal locality
- Conflict misses
- Cache-aware programming
- Memory hierarchy optimization

---

## Project Structure

```text
cache/
│
├── csim.c
├── trans.c
├── cachelab.h
├── Makefile
├── README.md
├── .gitignore
│
└── traces/
    ├── yi.trace
    ├── dave.trace
    └── trans.trace
