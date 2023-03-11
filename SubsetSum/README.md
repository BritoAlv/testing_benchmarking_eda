# Ejercicio CP:

Dado un conjunto $A$ estamos interesados en calcular la siguiente suma:

$$\sum _{ S \subset A} F(S)$$

$$F(S) = \sum_{s \subset S} g(s)$$

Finalmente: $g(s) = \sum_{x \in s} x$

|    Method |  N |            Mean |       Error |    StdDev |    Time_Complexity | Memory_Complexity | Allocated |
|---------- |--- |----------------:|------------:|----------:|-------------------:|------------------:|----------:|
| SubsetSum | 11 |     6,853,672.7 |     5,545.3 |   4,329.4 | 3.5409729053990597 |                 7 |         7 |
| SubsetSum | 12 |    22,339,311.6 |    48,350.2 |  40,374.6 |  3.496782019703661 |                29 |        29 |
| SubsetSum | 13 |    66,771,733.4 |    83,881.4 |  74,358.7 |  3.222973976077331 |               117 |       117 |
| SubsetSum | 14 |   221,550,195.7 |   172,754.3 | 144,257.6 |  3.309361074381086 |               312 |       312 |
| SubsetSum | 15 |   696,040,023.6 |   797,009.8 | 706,528.4 | 3.2336957790582934 |               936 |       936 |
| SubsetSum | 16 | 2,184,225,209.2 | 1,111,270.8 | 985,112.6 | 3.1942038047450816 |               936 |       936 |

La complejidad de este algoritmo es $3^n*n$. Por eso es que la entrada es pequeña.