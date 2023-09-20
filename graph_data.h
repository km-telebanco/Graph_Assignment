#define VERTEX 5 

char nodeNames[VERTEX][20] = {
  "A",
  "B",
  "C",
  "D",
  "E",
};

int graph[VERTEX][VERTEX] = {
  {0,4,0,0,0},
  {0,0,3,5,0},
  {0,0,0,0,3},
  {0,0,2,0,4},
  {0,0,0,0,0},
};