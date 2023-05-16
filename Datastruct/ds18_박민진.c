#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct {
    int weight;
    int vertex1;
    int vertex2;
} Edge;



void quickSort(Edge arr[], int L, int R) {
    int left = L, right = R;
    int pivot = arr[(L + R) / 2].weight;    // pivot ���� (���) 
    Edge temp;
    do
    {
        while (arr[left].weight < pivot)    // left�� pivot���� ū ���� �����ų� pivot�� ���� ������ 
            left++;
        while (arr[right].weight > pivot)    // right�� pivot���� ���� ���� �����ų� pivot�� ���� ������ 
            right--;
        if (left <= right)    // left�� right���� ���ʿ� �ִٸ� ��ȯ 
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            /*left ���������� ��ĭ, right �������� ��ĭ �̵�*/
            left++;
            right--;
        }
    } while (left <= right);    // left�� right ���� �����ʿ� ���� ������ �ݺ� 

  /* recursion */
    if (L < right)
        quickSort(arr, L, right);    // ���� �迭 ��������� �ݺ� 

    if (left < R)
        quickSort(arr, left, R);    // ������ �迭 ��������� �ݺ� 
}

void merge(Edge initList[], Edge mergedList[], int i, int m, int n)
{ /* the sorted lists initList[i:m] and initList[m+l:n] are merged to obtain
the sorted list mergedList[i:n] */
    int j, k, t;
    j = m + 1; /* index for the second sublist */
    k = i; /* index for the merged list */
    while (i <= m && j <= n) {
        if (initList[i].weight <= initList[j].weight)
            mergedList[k++] = initList[i++];
        else
            mergedList[k++] = initList[j++];
    }
    if (i > m) /* mergedList[k:n] = initList[j:n] */
        for (t = j; t <= n; t++)
            mergedList[t] = initList[t];
    else /* mergedList[k:n] = initList[i:m] */
        for (t = i; t <= m; t++)
            mergedList[k + t - i] = initList[t];
}
void mergePass(Edge initLIst[],Edge mergedList[], int n, int s)
{
    int i, j;
    for (i = 0; i <= n - 2 * s + 1; i += 2 * s)
        merge(initLIst, mergedList, i, i + s - 1, i + 2 * s - 1);
    if (i + s - 1 < n)
        merge(initLIst, mergedList, i, i + s - 1, n);
    else
        for (j = i; j <= n; j++)
            mergedList[j] = initLIst[j];
}

void mergeSort(Edge a[], int n) {
    int s = 1;
    Edge extra[MAX_SIZE];

    while (s < n) {
        mergePass(a, extra, n, s);
        s *= 2;
        mergePass(extra, a, n, s);
        s *= 2;
    }
}

void p1(Edge edges[],int numEdges ) {
    quickSort(edges,0, numEdges-1);
    printf("���� 1\n");
    for (int i = 0; i < numEdges; i++) {
        printf("%d (%d,%d)\n", edges[i].weight, edges[i].vertex1, edges[i].vertex2);
    }
}

void p2(Edge edges[], int numEdges) {
    mergeSort(edges,numEdges - 1);
    printf("���� 2\n");
    for (int i = 0; i < numEdges; i++) {
        printf("%d (%d,%d)\n", edges[i].weight, edges[i].vertex1, edges[i].vertex2);
    }
}


int main() {
    FILE* file = fopen("in2.txt", "r");
    if (file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    int n;
    fscanf_s(file, "%d", &n);

    int adjacencyMatrix[MAX_SIZE][MAX_SIZE] = { 0 };
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            fscanf_s(file, "%d", &adjacencyMatrix[i][j]);
        }
    }

    fclose(file);

    //�Է� ��

    Edge edges[MAX_SIZE * MAX_SIZE];
    int numEdges = 0;

    for (i = 1; i <= n; i++) {
        for (j = i ; j <= n; j++) {
            if (adjacencyMatrix[i][j] != 0) {
                edges[numEdges].weight = adjacencyMatrix[i][j];
                edges[numEdges].vertex1 = i;
                edges[numEdges].vertex2 = j;
                numEdges++;
            }
        }
    }
  
   

    printf("��ǻ���к� 202217119 �ڹ���\n");
     p1(edges, numEdges);
     printf("\n\n");
     p2(edges, numEdges);
    return 0;
}
