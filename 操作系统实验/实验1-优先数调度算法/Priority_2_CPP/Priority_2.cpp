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
		printf("�����%d�����̺ŵ�ID��ʱ������ȼ����ÿո����\n",i+1);
		scanf("%s %d %d",proc[i].id, &proc[i].time, &proc[i].pty);
		//
		if(proc[i].time>0)proc[i].is_end=false; //δ����
		else { proc[i].is_end=true; QLen--; }
	}
	getchar();

	//ð�����򣨰�����������
	for(i=0;i<NUM;i++)
		for(j=i+1;j<NUM;j++)
			if(proc[i].pty<proc[j].pty)
			{
				temp=proc[i]; proc[i]=proc[j]; proc[j]=temp;
			}

	printf("\nʱ��Ƭ�������:\n\n");

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
			printf("ѡ�н���ID: %s ��ִ��\n",proc[0].id);
			proc[0].time--; proc[0].pty--;

			//������������˳��
			temp=proc[0];
		    for(i=1; i<NUM; i++)
			if(proc[i].pty>=temp.pty && proc[i].is_end==false)
				proc[i-1]=proc[i];
			else break;
			proc[i-1]=temp;

		}
		else if(proc[0].time<=1 && proc[0].is_end==false)
		{
			printf("ѡ�н���ID: %s ��ִ��\n",proc[0].id);
			printf("����ID: %s �ѽ������˳�����\n",proc[0].id);
			proc[0].time--; proc[0].pty--;
			proc[0].is_end=true;

			//������������˳��
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

	printf("�������н��������н���ʱ��Ϊ0�����д�����%d\n",RunTime);
}
