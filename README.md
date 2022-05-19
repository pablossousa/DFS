# DFS

O nosso objetivo é descobrir quantas iterações um algoritmo de busca em profundidade (DFS - Deep First Search) necessita para chegar no final de uma matriz
# Lógica
Foi-se feito um programa com a seguinte lógica:    
Existe uma pilha dinâmica **p** de posições (int i, int j) (Baseado de : [vide git](https://github.com/mpiress/dynamic_stack))

1) Ao entrar no programa encontra-se uma rotina que abre um arquivo "Log.txt" onde iremos registrar o conteúdo da pilha de cada iteração em cada linha;

2) A primeira função encontrada é *FPVazia()* (Baseado de : [vide git](https://github.com/mpiress/dynamic_stack)):

>Função responsável por criar um espaço de memória para ser a cabeça da pilha. Para tanto, é utilizado a chamada de função nativa do C/C++ malloc, na qual qual recebe como referência o espaço a ser reservado por meio da diretriz sizeof. Nesse primeiro momento, o casting (i.e., conversão de um tipo void criado pelo malloc para um tipo específico) se torna opcional, sendo utilizado na codificação apenas para manter um único padrão de definição de função. Como pode ser observado no código disponibilizado, o endereço produzido pela execução do malloc é copiado para o ponteiro primeiro e último, mantendo ambos no mesmo endereço. O que significará que a pilha se encontra vazia. Por fim, apontamos o prox de ambos os ponteiros para NULL. 

3) A segunda função encontrada é *preencheMatrix()*, que tem o objetivo de alocar e preencher uma matriz dinâmica "matrix" de forma a parecer um labirinto, sendo 0 caminho livre e 1 barreira. Informações de arquivos de formato:
>T -- tamanho da matriz quadrática     
>i<sub>1</sub>,j<sub>1</sub>       
>i<sub>2</sub>,j<sub>2</sub>          
>i<sub>3</sub>,j<sub>3</sub>       
>...       
>i<sub>n</sub>,j<sub>n</sub>      
>        
>onde *i* é a linha de uma barreira n, e *j* a coluna de uma barreira n  


4) A terceira função printMatrix() mostra a matriz obtida após extração de arquivo;

5) A seguir a função *DFS(&p)* retorna as iterações da seguinte maneira:   
- Coloca-se a posição {0,0} na pilha;      
- Enquanto a posição verificada não for {T-1,T-1} e enquanto a pilha não estiver vazia:       
  1- Iguala a posição verificada ao primeiro item da pilha, e desenpilha o mesmo;        
  2- Verifica-se os vizinhos da posição e os adiciona na pilha:       
    - Para cada adjacente, baixo, direita, cima, esquerda, verifica se a linha e coluna deles estão no intervalo de [{0,0},{T-1,T-1}], se não é uma barreira (1) e se já não foi passado (2);
   
  3- Adiciona um à váriavel *iteracoes* que será retornada;      
- Imprime se conseguiu chegar no final ou não;     
- Retorna as iterações.

6) Repete-se *printMatrix()* mostrando a matriz com o caminho percorrido 1=barreira, 0=caminho não percorrido, 2=caminho percorrido.

Obs.:    
- O arquivo deve ser dado na mesma maneira que o apresentado.
# Exemplo de execução
Arquivo:
>7<br>
>0,4<br>
>1,4<br>
>2,2<br>
>2,5<br>
>4,1<br>
>4,4<br>
>5,5<br>
>6,1<br>
>6,3<br>

Execução:
</p>
<p align="center">
	<img src="imgs/exec.png"/> 
</p> 

Log.txt:
</p>
<p align="center">
	<img src="imgs/logtxt.png"/> 
</p>

# Referências

Utilizou-se como base de código o repositório de pilha dinâmica: [mpiress/dynamic_stack](https://github.com/mpiress/dynamic_stack)<br>
E também o material sobre "DFS on 2d array": [DFS](https://www.geeksforgeeks.org/depth-first-traversal-dfs-on-a-2d-array/)

# Compilação e Execução

O programa possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
