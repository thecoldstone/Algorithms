def fib_optimized(n):
    a, b, c, i = 0,1,0,2

    if n == 0:
        return a

    for i in range(2, n):
        c = a + b
        a = b
        b = c

    return b

if __name__ == "__main__":
    print(fib_optimized(100))