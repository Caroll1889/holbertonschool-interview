#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """Function that rotates a matrix 90
       degrees clockwise
    """

    matrix_length = len(matrix)

    for i in range(matrix_length):
        for j in range(i):
            aux = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = aux

    for i in range(matrix_length):
        for j in range(matrix_length // 2):
            temporal = matrix[i][j]
            matrix[i][j] = matrix[i][matrix_length - j - 1]
            matrix[i][matrix_length - j - 1] = temporal
