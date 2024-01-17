class LowerTriangular:
    def __init__(self, A: list ,n: int):
        self.A = A
        self.n = n

    def set(self, i, j, x):
        if i >= j:
            self.A[i * (i-1) // 2 + j -1] = x

    def get(self,i , j):
        if i >= j:
            return self.A[i * (i-1) // 2 + j - 1]
        return 0
    
    def Display(self):
        for i in range(self.n):
            for j in range(self.n):
                if i >= j:
                    print (self.A[i*(i-1) // 2 + j-1], end=" ")
                else:
                    print("0", end=" ")
            print()


#example usage
            
n = 3
A = [0] * (n * (n + 1) // 2)  # Initialize a 1D list to represent the lower triangular matrix
lt = LowerTriangular(A, n)

# Set
lt.set(0, 0, 1)
lt.set(1, 1, 2)
lt.set(2, 2, 3)
lt.set(1, 0, 4)
lt.set(2, 1, 5)
lt.set(2, 0, 6)

# Display 
lt.Display()
    