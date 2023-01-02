# Knight's Tour Problem Visual Solver

## Two functional programs that calculate an open tour of a knight on a chess board

This project was something I built out of curiosity after I stumbled upon the Knight's Tour problem. The scripts
provided, each in their own way find a valid path for an open tour for a knight chess piece. Provided are a 
bruteforce approach and a more heuristic solution using [Warnsdorff's rule](https://en.wikipedia.org/wiki/Knight%27s_tour). 
that take input for the following:

* Dimensions of the abstract "chess board" (m x n)
* The starting position of the knight in number coordinates
    * This is done because not all chess boards have letter indications
    * (0, 0) is the the top left corner, y increases going down the board, and x increases going right

## Visuals
![5x5_Board](five_by_five.png)
![8x8_Board](eight_by_eight.png)

## Here are some resources I found interesting!
 * [Numberphile Video](https://www.youtube.com/watch?v=ab_dY3dZFHM) about interesting patterns in the knight's tour
 * [Article](https://www.sciencedirect.com/science/article/pii/S0166218X04003488) on an optimized solution