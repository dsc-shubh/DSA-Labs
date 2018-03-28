struct Node{
	char name[11];
	float cgpa;
	};
typedef struct Node* Element;



void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
void recMergeSort(Element Ls[],int st,int en);
void iterMergeSort(Element Ls[],int size);
void readByK(int k);
