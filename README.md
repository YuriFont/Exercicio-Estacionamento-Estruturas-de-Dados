# Exercicio-Estacionamento-Estruturas-de-Dados
Exercício proposto em uma das aulas de Estruturas de Dados

Um estacionamento contém uma única alameda que guarda até 5 carros. Existe apenas uma
entrada/saída no estacionamento, em uma extremidade da alameda.
Se chegar um cliente para retirar um carro que não seja o mais próximo da saída, todos os carros
bloqueando seu caminho sairão do estacionamento, o carro do cliente será manobrado para fora do
estacionamento, e os outros carros voltarão a ocupar a mesma sequência inicial.
Escreva um programa que processe um grupo de linhas de entrada. Cada linha de entrada contém um
'E', de entrada, ou um 'S', de saída, e o número da placa do carro. Presume-se que os carros cheguem e
partam na ordem especificada pela entrada.
O programa deve imprimir uma mensagem sempre que um carro chegar ou sair. Quando um carro
chegar, a mensagem deve especificar se existe ou não vaga para o carro no estacionamento. Se não houver
vaga, o carro partirá sem entrar no estacionamento. Quando um carro sair do estacionamento, a mensagem
deverá incluir o número de vezes em que o carro foi manobrado para fora do estacionamento para permitir
que outros carros saíssem.
Assumir que a placa de um carro possui 7 letras/dígitos.

A resolução veio por meio da estrutura de dados do tipo Pilha ou LIFO(First In, Last Out).
