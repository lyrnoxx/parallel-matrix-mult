Parallelized matrix multiplication program using OpenMP primitives. Maximizing the work division among the threads to achieve best (least) time. Comparing the time of the parallel version with the sequential version. 

1. Square matrices 10x10, 50x50, 100x100, 500x500
2. Timings of the parallel version when run using (i) single thread, (ii) two threads, (iii) four threads, and (iv) eight threads.
3. Sequential matrix multiplication considering above (1) sizes.

Test System Info:
  OS: Ubuntu 24.04 LTS
  Processor: AMD Ryzen™ 7 7840HS w/ Radeon™ 780M Graphics × 16

Time given in microseconds:
    Threads     single   two    four   eight    Sequential
    Sizes
      10x10:    21      82      94      124     10
      50x50:    1726    677     370     411     1657
    100x100:    10028   5524    3221    1991    11653
    500x500:    846960  422998  213257  145632  1063833