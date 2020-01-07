

def fibonacci(n):
    fib_table = []

    fib_table.append(0)
    fib_table.append(1)

    [fib_table.append(fib_table[i - 1] + fib_table[i - 2]) for i in range(2, n + 1)]

    return fib_table

if __name__ == "__main__":
    print(fibonacci(50))

if __name__ == "__debug__":
    print("Debug")