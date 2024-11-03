# Directed Graph Implementation

This document describes the development of a directed graph with the following functionality:
- Add vertices based on user input
- Add edges between selected vertices and assign weights
- Display the graph using traversal methods:
  - Depth First Traversal
  - Breadth First Traversal

## Commands

The program supports the following commands:

| Command         | Description                                                                 |
|-----------------|-----------------------------------------------------------------------------|
| `5`             | Add 5 vertices to the graph                                                |
| `e 0 2 1`       | Add an edge from vertex `0` to vertex `2` with a weight of `1`             |
| `s`             | Start traversal functions (No other commands can be used after this)       |
| `d 2`           | Perform Depth First Traversal starting from vertex `2`                     |
| `b 1`           | Perform Breadth First Traversal starting from vertex `1`                   |
| `q`             | Exit                                                                       |

## Example

Below is an example of using the directed graph program:

### Input and Output

| Input       | Output                  |
|-------------|--------------------------|
| `6`         |                          |
| `e 0 1 1`   |                          |
| `e 1 0 1`   |                          |
| `e 0 2 1`   |                          |
| `e 2 0 1`   |                          |
| `e 1 2 1`   |                          |
| `e 2 1 1`   |                          |
| `e 2 5 1`   |                          |
| `e 5 2 1`   |                          |
| `e 2 4 1`   |                          |
| `e 4 2 1`   |                          |
| `e 2 3 1`   |                          |
| `e 3 2 1`   |                          |
| `d 2`       | `2 0 1 3 4 5`           |
| `d 0`       | `0 1 2 3 4 5`           |
| `d 5`       | `5 2 0 1 3 4`           |
| `d 3`       | `3 2 0 1 4 5`           |
| `b 1`       | `1 0 2 3 4 5`           |
| `b 0`       | `0 1 2 3 4 5`           |
| `b 5`       | `5 2 4 0 1 3`           |
| `e 3 4 1`   |                          |
| `e 4 3 1`   |                          |
| `e 5 4 1`   |                          |
| `e 4 5 1`   |                          |
| `s`         |                          |
| `d 2`       |                          |
| `d 0`       |                          |
| `d 5`       |                          |
| `d 3`       |                          |
| `b 1`       |                          |
| `b 0`       |                          |
| `b 5`       |                          |
| `q`         |                          |

This example demonstrates adding vertices and edges, performing depth-first and breadth-first traversals, and controlling the execution flow.
