#include <stdlib.h>
#include <stdio.h>

#include <Graph.h>

typedef struct AdjListNode {
    void *value;
    AdjListNode *next;
} AdjListNode;


typedef struct Graph {
    int V; //size, number of verticies 
    AdjListNode **array; 
} Graph; 

AdjListNode *newAdjListNode(void *value){
    AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int V, void **vertexValues){
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->V = V;
    newGraph->array = (AdjListNode **)malloc(V*sizeof(AdjListNode *));
    for (int i = 0; i < V; i++){
        newGraph->array[i] = newAdjListNode(vertexValues[i]);
        // newGraph->array[i] = NULL;
        // newGraph->array[i]->value = vertexValues[i];
    }
    return newGraph;
}

//add edge to undirected graph
void addDirectedEdge(Graph *graph, void *src, void *dest){    
    AdjListNode *newNode = newAdjListNode(dest);
    AdjListNode *srcNode;
    for (int i = 0; i < graph->V; i++){
        if (graph->array[i]->value == src){
            srcNode = graph->array[i];
        }
    }
    //add src node to dest  
    newNode->next = srcNode->next;
    srcNode->next = newNode;
}

void addUndirectedEdge(Graph *graph, void *src, void *dest){
    addDirectedEdge(graph, src, dest);
    addDirectedEdge(graph, dest, src);
}

void printGraph(Graph *graph, char *(*stringer)(void *)){
    for (int i = 0; i < graph->V; i++){
        AdjListNode *currNode = graph->array[i];
        printf("%s: ", (*stringer)(currNode->value));
        currNode = currNode->next;
        while(currNode != NULL){
            printf("%s ", (*stringer)(currNode->value));
            currNode = currNode->next;
        }
        printf("\n");
    }
}

