#include <stdio.h>
#include <string.h>

#define NUM 5

typedef struct PCB
{
	char id[10]; //process id
	int time; //service time
	int pty; //priority
	bool is_end; //state
}PCB;

void main()
{
	PCB temp,proc[NUM]; //PCB array
	int i=0,j=0,RunTime=0,QLen=NUM; //QueLength

	//memset
	memset(proc,0,sizeof(proc));

	//input each PCB
	for(i=0;i<NUM;i++)
	{
		printf("输入第%d个进程号的ID，时间和优先级，用空格隔开\n",i+1);
		scanf("%s %d %d",proc[i].id, &proc[i].time, &proc[i].pty);
		//
		if(proc[i].time>0)proc[i].is_end=false; //未结束
		else { proc[i].is_end=true; QLen--; }
	}
	getchar();

	//冒泡排序（按优先数排序）
	for(i=0;i<NUM;i++)
		for(j=i+1;j<NUM;j++)
			if(proc[i].pty<proc[j].pty)
			{
				temp=proc[i]; proc[i]=proc[j]; proc[j]=temp;
			}

	printf("\n时间片分配过程:\n\n");

	while(1)
	{	
		printf("RunTime %d\n",QLen>0 ? ++RunTime : RunTime);
		for(i=0;i<NUM;i++)
		{
			printf("ProcID:%s RestTime:%d RestPty:%d Finished: %s\n",
				proc[i].id,proc[i].time,proc[i].pty,proc[i].is_end?"Y":"N");
		}
		printf("----------------------------------------------------------------\n");
		
		if(QLen<=0)break;

		if(proc[0].time>1 && proc[0].is_end==false)
		{			
			printf("选中进程ID: %s 并执行\n",proc[0].id);
			proc[0].time--; proc[0].pty--;

			//按优先数调整顺序
			temp=proc[0];
		    for(i=1; i<NUM; i++)
			if(proc[i].pty>=temp.pty && proc[i].is_end==false)
				proc[i-1]=proc[i];
			else break;
			proc[i-1]=temp;

		}
		else if(proc[0].time<=1 && proc[0].is_end==false)
		{
			printf("选中进程ID: %s 并执行\n",proc[0].id);
			printf("进程ID: %s 已结束，退出队列\n",proc[0].id);
			proc[0].time--; proc[0].pty--;
			proc[0].is_end=true;

			//按优先数调整顺序
			temp=proc[0];
		    for(i=1; i<NUM; i++)
			if(proc[i].pty>=temp.pty && proc[i].is_end==false)
				proc[i-1]=proc[i];
			else break;
			proc[i-1]=temp;

			QLen--;
		}
			
		//press enter
		//getchar();

	}

	printf("程序运行结束，所有进程时间为0，运行次数：%d\n",RunTime);
}
