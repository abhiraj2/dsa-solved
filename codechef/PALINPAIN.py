# cook your dish here
t = int(input())
while t:
    t= t-1
    x, y = [int(i) for i in input().split()]
    
    if (x%2 and y%2) or (x==1 or y==1):
        print(-1)
    else:
        s1 = 'a'*(x//2) + 'b'*(y//2) + 'a'*(x-2*(x//2)) + 'b'*(y-2*(y//2)) + 'b'*(y//2) + 'a'*(x//2)
        s2 = 'b'+'a'*(x//2) + 'b'*((y-2)//2) + 'a'*(x-2*(x//2)) + 'b'*(y-2*(y//2)) + 'b'*((y-2)//2) + 'a'*(x//2) + 'b'
        print(s1)
        print(s2)