# LBYARCHMCO2
## Background
This Github Project aims to explore how to integrate assembly language using C. Additionally, the difference of execution times in C and assembly are explored, both in debug and release mode.

## Setup
An empty Visual Studio project was created for the testing of assembly and C programs and comparison of their execution times. 
Both programs must adhere to the following specifications:

![Project Specifications](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/cb099b04-d020-47fc-93b7-1058a4c46a6f)

## Debug Mode Results

### Case 1: Set is 2^20

C Trials Results:

![C20](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/4f8f01d4-420c-4892-8f28-7ed057e6bbff)

Assembly Trials Results:

![A20](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/2c68db78-0219-4c29-98f3-652bd10862b3)

### Case 2: Set is 2^24

C Trials Results:

![C24](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/279cc2a1-17f2-445d-8325-bed468e8a5dd)

Assembly Trials Results:

![A24](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/b94fccfe-b87a-4350-95a9-3c4307e36b05)

### Case 3: Set is 2^29

C Trials Results:

![C29](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/1f272826-3467-4375-8333-e4686c54267b)

Assembly Trials Results:

![A29](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/b9f14aba-d0ca-4924-932b-2947a58a7baa)

### Debug Mode Summary:

![Summary](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/766fff74-4aa6-4f25-acb5-e63b82865186)

## Release Mode Results

### Case 1: Set is 2^20

C Trials Results:

![C20](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/a7fc8665-9714-4ebe-9a42-df2dc24b9e41)

Assembly Trials Results:

![A20](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/c8d3f9f8-5074-4910-9952-6ca663c3a7ac)

### Case 2: Set is 2^24

C Trials Results:

![C24](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/a7c68549-7ebe-483f-ba2e-c9eb8ffae495)

Assembly Trials Results:

![A24](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/879355ea-7cc6-435c-9873-a93c6595e43f)

### Case 3: Set is 2^29

C Trials Results:

![C29](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/b874cf03-3d42-457e-b773-373f73066c05)

Assembly Trials Results:

![A29](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/a8b19a9e-6ab7-46f8-aa1d-1b3f7d7fb5f1)

### Release Mode Summary:

![Summary](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/4ade42c8-63cc-40b8-b23f-a1af7c2299c2)

## Correctness of kernels
The values, as seen in the end of each trial result, shows that both kernels gave the correct answer, which can be found at the start of each trial.

Below is the code that is used for validation of correctness
![image](https://github.com/ADichoso/LBYARCHMCO2/assets/39649018/162bc85b-847d-4c4e-9924-e64e41ea6767)

## Analysis of Results

As observed from the results, the implementation of the project specifications generally performs better when the project is set in debug mode.
This may be attributed to the need of the kernel written in the C programming language to first pass through a compiler, while the kernel written in assembly language not needing to.

However, in release mode, both implementations of the project generally perform similarly to each other, with the C kernel slightly outperforming the assembly kernel.
These results may be attributed to the optimization techniques performed on the C kernel in release mode, thus lessening the gap in performance between the two kernels.

