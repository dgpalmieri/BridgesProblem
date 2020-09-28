# CS411 Homework 2 - The Bridges Problem
The objective of this homework is to find an optimal solution to the given
problem, utilizing exhaustive search and recursive backtracking.

## Description (from the assignment)
A river flows from north to south. There are cities on the west bank and cities
on the east bank. We wish to build bridges across the river. Each bridge will
join a west-bank city with an east-bank city. We wish to choose the bridges we
build in such a way as to maximize the tolls we collect from people crossing
them. There are two restrictions on the bridges we build. First, no city can
have more than one bridge reaching it. Second, no two bridges can cross each
other.
Concerning the second condition: the cities on each bank are numbered. There 
are *w* cities on the west bank, numbered 0, 1, ..., *w* - 1 (starting at zero,
because we’re computer scientists), and there are *e* cities on the east bank,
numbered 0, 1, ..., *e* - 1. Suppose one bridge joins city a on the west to city
b on the east. Another bridge joins city c on the west to city d on the east. If
a\<c and b\>d, then these two bridges cross each other, and we are not allowed
to build both. For each pair of cities we might build a bridge between, we know
the toll we will collect from it. Building a bridge never affects the toll
collected from another bridge.

## Specifications
* All data will be represented as ints
* Bridges will be stored as vectors of ints, each with size 3
    * These items are: index of the western city, index of the eastern city,
the toll collected on the bridge.
* the bridge function will be prototyped as follows: int build(int w, int e, 
const vector<Bridge> & bridges)
* The function will return the maximum possible toll that can be collected given
a predefined set of bridges.
