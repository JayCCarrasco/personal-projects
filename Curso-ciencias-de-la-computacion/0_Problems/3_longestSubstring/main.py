#Longest substring without repeating

s='ckilbkd'

n = len(s)
s1=''
if s == ' ':
    max = 1
else:
    max = 0
for i in range(n):
    if s[i] in s1:
        if s[i] == s[i-1]:
            s1 = s1.replace(s1, "")
        else:
            s1 = s1.split(s[i],1)[1]
        print('s1 reinicia: ', s1)  
    s1 += s[i]
    print('s1 aumenta: ', s1)
    if len(s1) > max:
            max +=1      

print(max)
