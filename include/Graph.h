#ifndef GRAPH_H_
#define GRAPH_H_

typedef struct AdjListNode AdjListNode;

typedef struct Graph Graph; 

AdjListNode *newAdjListNode(void *value);

Graph *createGraph(int V, void **vertexValues);

//add edge to undirected graph
void addDirectedEdge(Graph *graph, void *src, void *dest);

void addUndirectedEdge(Graph *graph, void *src, void *dest);

void printGraph(Graph *graph, char *(*stringer)(void *));


#endif 