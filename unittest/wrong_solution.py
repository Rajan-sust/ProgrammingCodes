def main():
    numbers = list(map(int,input().split()))
    mn = 0
    for x in numbers:
        mn = min(mn,x)
    print(mn)

if __name__ == '__main__':
    main()
