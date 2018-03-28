#include"SeqList.h"
#include"ex1.h"
struct hash{
	int elemCount;
	int insCost;
	int queryCost;
	SeqList* arr;
	};
typedef struct hash* HashTable;


HashTable createHash();
HashTable insHash(HashTable h,char** a,int n,int j);
int insertAll(HashTable h);
