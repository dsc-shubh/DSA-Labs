#include"que.h"

struct mulq{
	int num;
	Queue* arr;
	};
typedef struct mulq* MultiQ;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Element t);
Element nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
int isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, int prio);
Queue getQueueFromMQ(MultiQ mq, int prio);
