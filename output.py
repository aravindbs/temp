from tabulate import tabulate



f = open("kruskal.txt",'r')
data = f.readlines()

for i in range(0,len(data)):
    data[i]=data[i][23:]

# print(data)

i=0
j=0
data_sparse=[]
data_dense=[]
while(i<5):
    data_sparse.append([])
    data_sparse[i].append("Graph %s"%(str(i)))
    # print(data_sparse)
    for temp in range(0,5):
        data_sparse[i].append(data[j][:-1])
        j+=1
    data_dense.append([])
    data_dense[i].append("Graph %s"%(str(i)))
    for temp in range(0,5):
        data_dense[i].append(data[j][:-1])
        j+=1
    i+=1
# print(data_sparse)
print(tabulate(data_dense, headers=['Duration','Pair 1', 'Pair 2','Pair 3','Pair 4','Pair 5'], tablefmt='orgtbl'))