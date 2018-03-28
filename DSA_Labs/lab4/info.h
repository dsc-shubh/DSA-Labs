struct node{
long long int cardno;
char bcode[6];
char expdate[8];
char fname[6];
char lname[6];
};
typedef struct node* Record;


struct list{
Record* arr;
int count;
};
typedef struct list* ListRecords;






ListRecords read(FILE* infile);
