#badger
a1:str="hello world! ///\n\\\\\\"
b1:str=a1.split('\n')
a2:str=['']*len(b1)

for a in range(len(b1)):
        a2[a]=b1[a][::-1]
        print(a2[a])

        for b in range(len(a2[a])):
                if a2[a][b]=='/':
                        a2[a]=a2[a][:b]+'\\'+a2[a][b:]
                elif a2[a][b]=='\\':
                        a2[a]=a2[a][:b]+'/'+a2[a][b:]

        print(a2[a])
