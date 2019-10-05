# 1090. Highways

## Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

## Description

The island nation of Flatopia is perfectly flat. Unfortunately, Flatopia has no public highways. So the traffic is difficult in Flatopia. The Flatopian government is aware of this problem. They're planning to build some highways so that it will be possible to drive between any pair of towns without leaving the highway system.

Flatopian towns are numbered from 1 to N. Each highway connects exactly two towns. All highways follow straight lines. All highways can be used in both directions. Highways can freely cross each other, but a driver can only switch between highways at a town that is located at the end of both highways.

The Flatopian government wants to minimize the length of the longest highway to be built. However, they want to guarantee that every town is highway-reachable from every other town.

## Input

The first line is an integer N (3 <= N <= 500), which is the number of villages. Then come N lines, the i-th of which contains N integers, and the j-th of these N integers is the distance (the distance should be an integer within [1, 65536]) between village i and village j.

## Output

You should output a line contains an integer, which is the length of the longest road to be built such that all the villages are connected, and this value is minimum.
This problem contains multiple test cases!
The first line of a multiple input is an integer T, then a blank line followed by T input blocks. Each input block is in the format indicated in the problem description. There is a blank line between input blocks.
The output format consists of T output blocks. There is a blank line between output blocks.

## Sample Input

1 3 0 990 692 990 0 179 692 179 0

## Sample Output

692
