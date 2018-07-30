# coding: utf-8
__author__ = 'ce39906'
'''
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
'''
def isValidSudoku(board):
        used1 = [[0]*9 for i in range(9)]
        used2 = [[0]*9 for i in range(9)]
        used3 = [[0]*9 for i in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    num = int(board[i][j])-1
                    k=i/3*3+j/3 #the index for the nine small board
                    if used1[i][num] or used2[j][num] or used3[k][num]:
                        return False
                    used1[i][num]=1
                    used2[j][num]=1
                    used3[k][num]=1
        return True