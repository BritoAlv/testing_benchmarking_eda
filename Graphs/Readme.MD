## Clase Grafo
Los grafos son modelados en este enfoque usando una lista de adyacencia, la cual es mantenida privada.
Como atributo publico se tienen:

el numero de vertices y de aristas, informacion util para cuando se vaya a hacer el analisis de complejidad

Un metodo de BFS q entre sus parametros toma una lista d q almacenara las distancias d cada nodo al nodo donde empieza el BFS. Tal lista d es pasada por referencia inicializada a 0 y el metodo BFS se encarga d rellenarla con los valores correctos

Un metodo DFS que no devuelve ni ejecuta nada mas alla de realizar el recorrido; aunq puede ser extensible por si se desea introducirle el uso de una funcion. Depende de q se le pase un arreglo booleano inicializado a falso con los nodos visitados

Un constructor q genera un grafo conexo a partir del numero de vertices y aristas solicitadas. Buscando que el grafo sea conexo puede ser que el numero de aristas termine siendo mayor a las solicitadas por el usuario.

Una funcion Mostrar que se usa 
para mostrar los datos de la lista de adyacencia, para poder contemplar asi el grafo que fue generado aleatoriamente. Se sugiere solo usar esta funcion Mostrar cuando haya muy poco que mostrar, o sea, el numero de vertices sea manuable, para comprobar el funcionamiento correcto de la clase.

## Main
En la funcion Main se puede testear como se guste ambos metodos, quizas usando la funciones de tiempo q brindan las stl de c++.

Para probar cambiar el numero de vertices y el numero de aristas con las que se prueban los algoritmos bastan asignar los nuevos valores a las variables enteras n_vertex y n_edges y borrar las lineas de codigo q estan desalineadas a proposito y cuyo unico objetivo es mostrar el correcto funcionamiento de la clase.
:)