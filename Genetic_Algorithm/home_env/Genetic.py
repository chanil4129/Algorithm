import random,copy,operator
from functools import reduce

#찾고자 하는 경로와 비용
ans_chrm = []
ans_cost = 9999

#설정
cost_matrix=[]
mating=100 #교배 횟수image.png
population_size=5 #해집단의 크기
cross_probability=0.7 #교차율 0.7
mutation_probability=0.001 #변이율 0.001~0.01

#초기 염색체 집합
def init_chrm(population):
    global population_size
    sample_chrm = list(range(len(cost_matrix[0]))) # a feasible solution
    for i in range(population_size):
        new_chrm=copy.copy(sample_chrm)
        random.shuffle(new_chrm)
        population.append(new_chrm)

#total cost 
def get_totalcost(chrm):
    global cost_matrix
    cost=0
    last_city=chrm[0]
    for current_city in chrm:
        cost+=cost_matrix[last_city][current_city]
        last_city=current_city
    cost+=cost_matrix[last_city][chrm[0]]
    return cost

#선택
def chrm_select(population):
    global population_size
    global cross_probability
    global mutation_probability
    #확률 계산
    fitness_list = list(map(get_totalcost,population)) #적합도 
    fitness_list=list(map(lambda x: 1/x,fitness_list)) #적합도 최종결과(역수 취하면서)
    fitness_sum = reduce(operator.add, fitness_list) #적합도 누적
    prob_list = map( (lambda x: x/fitness_sum), fitness_list) #적합도 확률 리스트
    cum_value = 0
    cum_prob_list = [] #누적 확률 리스트
    for prob in prob_list:
        cum_prob_list.append( cum_value + prob )
        cum_value += prob
    cum_prob_list[-1] = 1.0

    #개체 선택
    selected = []
    size=2*population_size #바뀔 수 있음
    for i in range(size):
        rn = random.random()
        for j, cum_prob in enumerate(cum_prob_list): #j는 0부터 순서대로, cum_prob는 cum_prob_list에 있는거 순차적으로
           if rn<= cum_prob:
                selected.append(j)
                break 

    #개체 및 복제,교차,돌연변이 중 선택
    for i in range(population_size):
        rn=random.random()
        if rn>cross_probability+mutation_probability:
            continue
        elif rn>mutation_probability:
            chrm_cross(population[selected[i]],population[selected[i+population_size]])
            rn=random.random()
            if rn<mutation_probability/4:
                chrm_mutation_change(population[selected[i]])
            elif rn<mutation_probability/2:
                chrm_mutation_change(population[selected[i]])
            elif rn<mutation_probability*3/4:
                chrm_mutation_insert(population[selected[i]])
            else:
                chrm_mutation_insert(population[selected[i]])

    #답 마킹
    for i in range(population_size):
        global ans_cost
        global ans_chrm
        if ans_cost>get_totalcost(population[i]):
            ans_cost=get_totalcost(population[i])
            ans_chrm=population[i]

#교차
def chrm_cross(parent1,parent2):
    length=len(parent1)
    pt1=random.randrange(length)
    pt2=random.randrange(length)
    latter_length = len(parent1) - pt2
    prt1_mid = parent1[pt1:pt2]
    prt2_mid = parent2[pt1:pt2]
    prt1_reordered = parent1[pt2:] + parent1[:pt2]
    prt2_reordered = parent2[pt2:] + parent2[:pt2]
    prt1_reord_filtered = list(filter( lambda x: x not in prt2_mid,prt1_reordered ))
    prt2_reord_filtered = list(filter( lambda x: x not in prt1_mid,prt2_reordered ))
    parent1 = prt2_reord_filtered[-pt1:] + prt1_mid +prt2_reord_filtered[:latter_length]
    parent2 = prt1_reord_filtered[-pt1:] + prt2_mid +prt1_reord_filtered[:latter_length] 

#돌연변이(삽입)
def chrm_mutation_insert(chrm):
    element_position = random.randint(0, len(chrm)-1 )
    insert_position = random.randint(0, len(chrm)-2 )
    while element_position==insert_position: #element_position과 insert_position이 같으면 안됨
        insert_position = random.randint(0, len(chrm)-2 )
    element_value = chrm[element_position]
    del chrm[element_position]
    chrm.insert( insert_position, element_value )

#돌연변이(교환)
def chrm_mutation_change(chrm):
    position1 = random.randint(0, len(chrm)-1 )
    position2 = random.randint(0, len(chrm)-1 )
    while position1==position2:
        position2 = random.randint(0, len(chrm)-1 ) #position1과 position2가 같으면 안됨
    temp=chrm[position1]
    chrm[position1] = chrm[position2]
    chrm[position2]=temp 

#main
def main():
    global ans_cost
    global ans_chrm
    global mating
    T=9999
    #도시별 거리
    cost_matrix.append([0,1,2,3,4,5,6,7,8,9])
    cost_matrix.append([1,0,1,5,6,9,2,3,7,8])
    cost_matrix.append([2,1,0,8,6,2,4,7,9,5])
    cost_matrix.append([3,5,8,0,3,2,7,6,8,9])
    cost_matrix.append([4,6,6,3,0,9,7,4,1,5])
    cost_matrix.append([5,9,2,2,9,0,1,4,7,3])
    cost_matrix.append([6,2,4,7,7,1,0,7,4,1])
    cost_matrix.append([7,3,7,6,4,4,7,0,8,3])
    cost_matrix.append([8,7,9,8,1,7,4,8,0,1])
    cost_matrix.append([9,8,5,9,5,3,1,3,1,0])

    population=[]
    init_chrm(population)
    while True:
        for i in range(mating):
            chrm_select(population)
        if not ans_cost==9999: break

    print("population : "+str(ans_chrm))
    print("cost : "+str(ans_cost))

if __name__=='__main__':
    main()