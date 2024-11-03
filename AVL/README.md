# AVL Tree Implementation

This document describes the development of an AVL Tree with the following functionality:
- Add and remove data in the AVL Tree
- Show data in the AVL Tree using Pre-order Traversal

## Commands

The program supports the following commands:

| Command | Description                           |
| ------- | ------------------------------------- |
| `a 10`  | Add `10` into the AVL Tree            |
| `d 20`  | Remove `20` from the AVL Tree         |
| `p`     | Show data in the AVL Tree (Pre-order) |
| `x`     | Exit                                  |

## Example

Below is an example of using the AVL Tree program:

### Input and Output

| Input        | Output                        |
|--------------|-------------------------------|
| `a 10`       |                               |
| `a 20`       |                               |
| `p`          | `10 20`                       |
| `a 30`       |                               |
| `p`          | `20 10 30`                    |
| `a 40`       |                               |
| `p`          | `20 10 30 40`                 |
| `a 50`       |                               |
| `p`          | `20 10 40 30 50`              |
| `a 60`       |                               |
| `p`          | `40 20 10 30 50 60`           |
| `a 70`       |                               |
| `p`          | `40 20 10 30 60 50 70`        |
| `d 40`       |                               |
| `p`          | `50 20 10 30 60 70`           |
| `d 50`       |                               |
| `p`          | `60 20 10 30 70`              |
| `d 60`       |                               |
| `p`          | `20 10 70 30`                 |
| `x`          |                               |

This table provides a clear example of how the AVL Tree maintains balance through additions and deletions, with each `p` command showing the tree’s current structure in Pre-order Traversal.
