Originally, the matrix multiplication was implemented using Pthreads, 

but in pthreads we have to create threads manually and look for IDs, and divide using the chunking method. This code is complex and not good; instead, we use the OpenMP library to implement the same problem using (#pragma omp parallel for) to let the compiler and the OpenMP manage the details of thread scheduling and synchronization. 

This resulted in less code and better synchronization. The implementation logic is the same in both codes, but in OpenMP, it is easier for the user to care about thread creation..
