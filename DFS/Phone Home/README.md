# 问题描述

深搜，染色问题

## Input

There will be multiple test cases. Input for each test case will consist of two lines: the first line will contain the integer n, indicating the number of towers. The next line will be of the form x1 y1 x2 y2 … xn yn where xi yi are the coordinates of tower i. A pair of towers are considered “near” each other if the distance between them is no more than 20. There will be no more than 12 towers and no tower will have more than 4 towers near it. A value of n = 0 indicates end of input.

## Output

For each test case, you should print one line in the format:

The towers in case n can be covered in f frequencies.

where you determine the value for f. The case numbers, n, will start at 1.

## Sample Input

```c
5
0 0 5 7.5 1 -3 10.75 -20.1 12.01 -22
6
0 1 19 0 38 1 38 21 19 22 0 21
0
```

## Sample Output

```c
The towers in case 1 can be covered in 3 frequencies.
The towers in case 2 can be covered in 2 frequencies.
```
