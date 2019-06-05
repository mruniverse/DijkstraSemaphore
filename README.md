DijkstraSemaphore

A operação up incrementa o valor de um determinado
semáforo. Se um ou mais processos estiverem dormindo naquele semáforo, incapaz de completar uma operação down anterior, um deles é escolhido pelo sistema
(por exemplo, ao acaso) e é autorizado a completar seu
down. Desse modo, após um up com processos dormindo em um semáforo, ele ainda estará em 0, mas haverá
menos processos dormindo nele. A operação de incrementar o semáforo e despertar um processo também é
indivisível. Nenhum processo é bloqueado realizando
um up, assim como nenhum processo é bloqueado realizando um wakeup no modelo anterior

A operação down em
um semáforo confere para ver se o valor é maior do que 0.
Se for, ele decrementará o valor (isto é, gasta um sinal de
acordar armazenado) e apenas continua. Se o valor for 0,
o processo é colocado para dormir sem completar o down
para o momento. Conferir o valor, modificá-lo e possivelmente dormir são feitos como uma única ação atômica
indivisível. É garantido que uma vez que a operação de
semáforo tenha começado, nenhum outro processo pode
acessar o semáforo até que a operação tenha sido concluída ou bloqueada. Essa atomicidade é absolutamente essencial para solucionar problemas de sincronização e evitar
condições de corrida. Ações atômicas, nas quais um grupo
de operações relacionadas são todas realizadas sem interrupção ou não são executadas em absoluto, são extremamente importantes em muitas outras áreas da ciência de
computação também. 
