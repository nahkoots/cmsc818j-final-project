#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <inttypes.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include "graph.c"
#include "align.c"

int main () {
    
    int numNodes, numEdges;
    
    struct SeqNode *nodes = generateGraphFromGFA("chr1_HG001_002_003_004_005_006_007_v3.3.2.gfa", &numNodes, &numEdges);
    
    printf("%d nodes and %d edges\n", numNodes, numEdges);
    char test[11] = "hi there!";
    printf("strlen test: %d\n", strlen(test));
    
    bitalign_aligner(nodes, "AAGG", 0, 0, 500, 41, 0, 5, 200, 0, 1, 1, 1, 1);
    printf("okay\n");
    //bitalign_aligner(nodes, "AAGGCAGAAATCAAGAAAATTCATTGAAACTAATGAGAATAAAGGGAGAGCATACCAGAATCTCTGGGACACAGCCAAAGCAGTGTTTAGAGGGAAGATT", 0, 0, 1638577, 41, 1, 5, 200, 0, 1, 1, 1, 1);
    
    deleteGraph(nodes, numNodes);
     
    return(0);
    
    
}
