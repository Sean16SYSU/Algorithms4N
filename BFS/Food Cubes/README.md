# 1114. Food Cubes

## Constraints

Time Limit: 10 secs, Memory Limit: 32 MB

## Description

The spacemen in the space shuttle are waiting for the next escape window to return to the mother land Earth, where they are expected to fall somewhere in the deep blue waters of the Persian Gulf. Bored of waiting with nothing to do, they decide to play a game with their unit size food cubes. In the zero gravity environment of their spaceship, anything can stay motionless where it is placed. One spaceman places several food cubes in space such that there may be holes between cubes. Others, given the coordinates of the food cubes, should find the number of holes. A hole is a continuous empty space surrounded by food cubes in all six directions. You are to write a program to read the coordinates of each food cube and compute the number of holes.

## Input

The first line of the input contains a single integer t (1 <= t <= 20) which is the number of test cases in the input. Each test case starts with an integer M, the number of food cubes. Each line i (1 <= i <= M) of the M following lines contains integers xi, yi and zi, all between 1 and 100 inclusive, indicating the three coordinates of a food cube in the 3D space.

## Output

For each test case, there is one line containing the number of holes.

## Sample Input

```
2
26
1 1 1
1 2 1
1 3 1
2 1 1
2 2 1
2 3 1
3 1 1
3 2 1
3 3 1
1 1 2
1 2 2
1 3 2
2 1 2
2 3 2
3 1 2
3 2 2
3 3 2
1 1 3
1 2 3
1 3 3
2 1 3
2 2 3
2 3 3
3 1 3
3 2 3
3 3 3
7
1 1 1
1 1 2
1 2 1
1 2 2
2 1 1
2 1 2
2 2 1
```

## Sample Output

```c
1
0
```