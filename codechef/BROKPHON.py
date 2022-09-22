t = int(input(""))
b = []
def check(t):
    i = 0
    while (i < t):
        players = int(input(""))
        a = [int(i) for i in input().split()]
        flag = False
        count = 0
        k =1
        diff = []
        while (k<players):
            diff.append(a[k]-a[k-1])
            k+=1
        #print(diff)
        
        for j in diff:
            if j:
                if flag:
                    count +=1
                else:
                    count += 2
                    flag = True
            else:
                flag = False
        
        b.append(count)
        i += 1
    for l in b:
        print(l)
check(t)