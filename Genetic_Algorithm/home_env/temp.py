#총 거리 리턴
def get_totalcost(chrm):
    cost=0
    last_city=chrm[0]
    for current_city in chrm:
        cost+=cost_matrix[last_city][current_city]
        last_city=current_city
    return cost

import random,copy
random.seed(0) #테스트 할 때 일정한 값 나오게

population_size=5 #해집단의 크기
# pc=3 #교차율
# pm=3 #변이율

#도시별 거리
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

#염색체 집합
sample_chrm = list(range(10)) # a feasible solution
init_population = [] # an empty list

for i in range(population_size):
    new_chrm=copy.copy(sample_chrm)
    random.shuffle(new_chrm)
    init_population.append(new_chrm)
print(init_population)



#확률
import operator
from functools import reduce
fitness_list = [6.0, 9.0, 4.0, 3.0, 5.0, 8.0, 3.0, 6.0, 3.0, 3.0] #적응도
fitness_sum = reduce( operator.add, fitness_list) #적응도 누적
prob_list = map( (lambda x: x/fitness_sum), fitness_list) #적응도 확률 리스트
cum_value = 0
cum_prob_list = [] #누적 확률 리스트
for prob in prob_list:
    cum_prob_list.append( cum_value + prob )
    cum_value += prob
cum_prob_list[-1] = 1.0
cum_prob_list

#개체 선택
import random
selected = []
size = 100 # 개체 사이즈
for i in range(size):
    rn = random.random()
    for j, cum_prob in enumerate(cum_prob_list): #j는 0부터 순서대로, cum_prob는 cum_prob_list에 있는거 순차적으로
        if rn<= cum_prob:
            selected.append(j)
            break 
selected

select_sum=[0,0,0,0,0,0,0,0,0,0]
for i in selected:
    select_sum[i%10]+=1
select_sum

#교차
#list 2개를 교차 하는 함수
pt1 = 2 # crossover point 1
pt2 = 5 # crossover point 2
parent1 = [4, 1, 5, 6, 9, 2, 3, 7, 8]
parent2 = [3, 1, 8, 6, 2, 4, 7, 9, 5]
latter_length = len(parent1) - pt2
prt1_mid = parent1[pt1:pt2]
prt2_mid = parent2[pt1:pt2]
prt1_reordered = parent1[pt2:] + parent1[:pt2]
prt2_reordered = parent2[pt2:] + parent2[:pt2]
prt1_reord_filtered = list(filter( lambda x: x not in prt2_mid,prt1_reordered ))
prt2_reord_filtered = list(filter( lambda x: x not in prt1_mid,prt2_reordered ))
offspring1 = prt2_reord_filtered[-pt1:] + prt1_mid +prt2_reord_filtered[:latter_length]
offspring2 = prt1_reord_filtered[-pt1:] + prt2_mid +prt1_reord_filtered[:latter_length] 

#돌연변이
#돌연변이 구하는 함수
#position1과 position2가 동일하지 않도록 하는 조건 추가
import random
chrm = [4, 1, 5, 6, 9, 2, 3, 7, 8]
element_position = random.randint(0, len(chrm)-1 )
insert_position = random.randint(0, len(chrm)-2 )
element_value = chrm[element_position]
del chrm[element_position]
chrm.insert( insert_position, element_value ) 


