# Binary Search Tree (BST) Implementation

This document describes the development of a Binary Search Tree (BST) with the following functionality:
- Add and remove data in the Binary Search Tree
- Show data in the Binary Search Tree using different traversal methods:
  - Breadth-First Traversal
  - Preorder Traversal
  - Inorder Traversal
  - Postorder Traversal

## Commands

The program supports the following commands:

| Command | Description                                 |
| ------- | ------------------------------------------- |
| `a 10`  | Add `10` into the BST                       |
| `d 5`   | Remove `5` from the BST                     |
| `b`     | Show data in the BST (Breadth-First)        |
| `i`     | Show data in the BST (Inorder)              |
| `p`     | Show data in the BST (Preorder)             |
| `t`     | Show data in the BST (Postorder)            |
| `x`     | Exit                                        |

## Example

Below is an example of using the BST program:

### Input and Output

| Input      | Output                                      |
|------------|---------------------------------------------|
| `a 10`     |                                             |
| `a 7`      |                                             |
| `a 13`     |                                             |
| `a 2`      |                                             |
| `a 9`      |                                             |
| `a 20`     |                                             |
| `a 11`     |                                             |
| `b`        | `10,\7,13,\2,9,11,20,\`                     |
| `i`        | `2,7,9,10,11,13,20,`                        |
| `p`        | `10,7,2,9,13,11,20,`                        |
| `t`        | `2,9,7,11,20,13,10,`                        |
| `d 10`     |                                             |
| `b`        | `11,\7,13,\2,9,20,\`                        |
| `d 9`      |                                             |
| `b`        |  `11,\7,13,\2,20,\`                         |
| `x`        |                                             |

Each traversal method (`b`, `i`, `p`, `t`) displays the current structure of the BST, and removing nodes updates the tree accordingly.
