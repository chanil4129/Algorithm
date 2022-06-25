

import random,copy
random.seed(0) #테스트 할 때 일정한 값 나오게

population_size=5 #해집단의 크기
pc=3 #교차율
pm=3 #변이율

cost_matrix=[]
cost_matrix.append([0,0,0,0,0,0,0,0,0,0])
cost_matrix.append([0,0,1,5,6,9,2,3,7,8])
cost_matrix.append([0,1,0,8,6,2,4,7,9,5])
cost_matrix.append([0,5,8,0,3,2,7,6,8,9])
cost_matrix.append([0,6,6,3,0,9,7,4,1,5])
cost_matrix.append([0,9,2,2,9,0,1,4,7,3])
cost_matrix.append([0,2,4,7,7,1,0,7,4,1])
cost_matrix.append([0,3,7,6,4,4,7,0,8,3])
cost_matrix.append([0,7,9,8,1,7,4,8,0,1])
cost_matrix.append([0,8,5,9,5,3,1,3,1,0]) 

for i in range(population_size):
    new_chrm=copy.copy(sample_chrm)
    random.shuffle(new_chrm)
    init_population.append(new_chrm)


