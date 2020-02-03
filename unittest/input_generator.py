from random import randint

def main():
    numbers = [randint(-1,100) for _ in range(10)]
    print(*numbers)

if __name__ == '__main__':
  main()

