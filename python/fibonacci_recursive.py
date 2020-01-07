def fibonacci(n):
    if n == 0:
        return 0
    else:
        if n == 1:
            return 1;
        else:
            return fibonacci(n - 1) + fibonacci(n - 2)

if __name__ == "__main__":
    result = fibonacci(1000)
    print(result)