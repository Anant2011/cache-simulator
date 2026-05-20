# Cache Lab – Cache Simulator & Cache-Optimized Matrix Transpose

A systems programming project implemented in C focused on understanding cache behavior, memory hierarchy, and performance optimization techniques.

## Overview

This project consists of:

- A configurable cache simulator implementing LRU replacement policy
- Cache-efficient matrix transpose optimizations using locality-aware techniques

The project explores key computer systems concepts such as:
- Spatial locality
- Temporal locality
- Conflict misses
- Blocking / tiling
- Direct-mapped cache behavior

---

## Features

### Cache Simulator
Implemented a configurable cache simulator supporting:
- Load (`L`)
- Store (`S`)
- Modify (`M`) operations
- LRU eviction policy
- Configurable cache parameters (`s`, `E`, `b`)

The simulator analyzes:
- Cache hits
- Cache misses
- Evictions

using memory trace files.

---

### Cache-Optimized Matrix Transpose
Optimized matrix transpose kernels for improved cache performance by:
- Using blocking techniques
- Reducing conflict misses
- Improving spatial and temporal locality
- Minimizing cache misses for direct-mapped caches

### Performance
- Achieved fewer than **300 cache misses** for the 32×32 transpose benchmark.

---

## Files

```text
csim.c        -> Cache simulator implementation
trans.c       -> Cache-optimized transpose implementations
cachelab.h    -> Header file
Makefile      -> Build instructions
traces/       -> Sample memory traces
