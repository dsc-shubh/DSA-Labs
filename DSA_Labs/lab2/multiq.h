#include"que.h"

struct multi
{
	int count;
	Queue* arr;
};
typedef struct multi* MultiQ;


MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
int isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, int prio);
Queue getQueueFromMQ(MultiQ mq, int prio);
