from models.matrix import Matrix

class CompressedImageService:
    def __init__(self):    
        pass
    # @staticmethod
    # def compress_matrix_by_2(target_matrix):
    #     '''Will create the 4:2:0 compression. Return the given matrices'''
    #     tmp_matrix = Matrix(target_matrix.width/2, target_matrix.height/2)
    #     for i in range(target_matrix.height, 2):
    #         for j in range(target_matrix.width, 2):
    #             sum = target_matrix.m[i][j] + target_matrix.m[i][j + 1] + \
    #                 target_matrix.m[i +1][j] + target_matrix.m[i + 1][j + 1]
    #             sum = sum / 4
    #             tmp_matrix.m[i / 2][j /2] = sum
    #     return tmp_matrix
