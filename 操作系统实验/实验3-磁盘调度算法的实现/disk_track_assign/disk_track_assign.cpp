#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <time.h>
#include <math.h>

#define TRACK_MAX 200
#define TRACK_NUM 9

int track_start
//=100
    ;

int rand_track[TRACK_NUM]
//={55,58,39,18,90,160,150,38,184}
    ;

#define NStepSCAN_N 5 //�ٶ�NStep_SCAN�㷨�Ĳ���Ϊ5

int a[TRACK_NUM];

void init() //�����������ŵ���
{
	int i;

	printf("����ŵ���ʼλ��:\n");
	scanf("%d",&track_start);
	printf("\n");

	srand((int)time(0)); //�������������
	for(i=0; i<TRACK_NUM; i++)
		rand_track[i]=rand()%TRACK_MAX;
	/*	*/
	
	printf("�����������Ҫ���ʵĴŵ���Ϊ:\n");
	for(i=0; i<TRACK_NUM; i++)printf(" %d",rand_track[i]);
	printf("\n");

}

void sort(int a[]) //ð�����򣬴�С����
{
	int i,j,temp;
	for(i=0; i<TRACK_NUM; i++)
	{     
		for(j=i+1; j<TRACK_NUM; j++) 
			if(a[i] > a[j])
			{
  		     	temp=a[i]; a[i]=a[j]; a[j]=temp;
			}
	}

}

void show(int a[])
{
	int i;
	for(i=0; i<TRACK_NUM; i++)printf(" %d",a[i]); printf("\n");
}

float FCFS(int rand_track[]) //�����ȷ���
{
	int i;
	int head_track=track_start;

	int total_move=0,move[TRACK_NUM];
	float avg_track_seeking_len;

	printf("\nFCFS�㷨\n");
	printf("--------------------------------------------------------\n");
	printf("��%d�Ŵŵ���ʼ\n",track_start);

	//ֵ����
	for(i=0; i<TRACK_NUM; i++)a[i]=rand_track[i];
	//show(a);

	for (i=0; i<TRACK_NUM; i++)
	{

		move[i]=abs(head_track-a[i]);
		head_track=a[i]; //�ƶ���ͷ
		total_move += move[i];

		printf("���ʴŵ���:%3d �ƶ�����:%3d\n",a[i],move[i]);
	}
	
	printf("�ƶ��ŵ�������%d\n", total_move);
	avg_track_seeking_len=float(total_move) / TRACK_NUM;
	printf("ƽ��Ѱ������: %3.2f\n", avg_track_seeking_len);
	return avg_track_seeking_len;
}

float SSTF(int rand_track[]) //���Ѱ��ʱ������
{
	int i,j,min,j_key,temp;
	int head_track=track_start;

	int total_move=0,move[TRACK_NUM];
	float avg_track_seeking_len;

	printf("\nSSTF�㷨\n");
	printf("--------------------------------------------------------\n");
	printf("��%d�Ŵŵ���ʼ\n",track_start);

	//ֵ����
	for(i=0; i<TRACK_NUM; i++)a[i]=rand_track[i];
	//show(a);

	for (i=0; i<TRACK_NUM; i++)
	{
		min=abs(a[i]-head_track); j_key=i;

		for(j=i+1; j<TRACK_NUM; j++)
		{
			if(abs(a[j]-head_track)<min)
			{
				min=abs(a[j]-head_track); j_key=j;
			}

		}

		temp=a[i]; a[i]=a[j_key]; a[j_key]=temp;

		move[i]=min;
		head_track=a[i]; //�ƶ���ͷ
		total_move += move[i];

		printf("���ʴŵ���:%3d �ƶ�����:%3d\n",a[i],move[i]);
	}
	
	printf("�ƶ��ŵ�������%d\n", total_move);
	avg_track_seeking_len=float(total_move) / TRACK_NUM;
	printf("ƽ��Ѱ������: %3.2f\n", avg_track_seeking_len);
	return avg_track_seeking_len;
}


float SCAN(int rand_track[]) //ɨ��
{
	int i,min,i_key;
	int head_track=track_start;

	int total_move=0,move[TRACK_NUM];
	float avg_track_seeking_len;

	printf("\nSCAN�㷨\n");
	printf("--------------------------------------------------------\n");
	printf("��%d�Ŵŵ���ʼ\n",track_start);

	//ֵ����
	for(i=0; i<TRACK_NUM; i++)a[i]=rand_track[i];
	//show(a);

	sort(a);
	//show(a);

	i_key=-1;
	for(i=0; i<=TRACK_NUM; i++)if(i==TRACK_NUM || a[i]>head_track){i_key=i; break;}
	
	for (i=i_key; i<TRACK_NUM; i++)
	{
		min=abs(a[i]-head_track);

		move[i]=min;
		head_track=a[i]; //�ƶ���ͷ
		total_move += move[i];

		printf("���ʴŵ���:%3d �ƶ�����:%3d\n",a[i],move[i]);
	}

	for (i=i_key-1; i>=0; i--)
	{
		min=abs(a[i]-head_track);

		move[i]=min;
		head_track=a[i]; //�ƶ���ͷ
		total_move += move[i];

		printf("���ʴŵ���:%3d �ƶ�����:%3d\n",a[i],move[i]);
	}

	printf("�ƶ��ŵ�������%d\n", total_move);
	avg_track_seeking_len=float(total_move) / TRACK_NUM;
	printf("ƽ��Ѱ������: %3.2f\n", avg_track_seeking_len);
	return avg_track_seeking_len;

}


float CSCAN(int rand_track[]) //ѭ��ɨ��
{
	int i,min,i_key;
	int head_track=track_start;

	int total_move=0,move[TRACK_NUM];
	float avg_track_seeking_len;

	printf("\nCSCAN�㷨\n");
	printf("--------------------------------------------------------\n");
	printf("��%d�Ŵŵ���ʼ\n",track_start);
	
	//ֵ����
	for(i=0; i<TRACK_NUM; i++)a[i]=rand_track[i];
	//show(a);

	sort(a);
	//show(a);

	i_key=-1;
	for(i=0; i<=TRACK_NUM; i++)
		if(i==TRACK_NUM || a[i]>head_track){i_key=i; break;}
	
	for (i=i_key; i<TRACK_NUM; i++)
	{
		min=abs(a[i]-head_track);

		move[i]=min;
		head_track=a[i]; //�ƶ���ͷ
		total_move += move[i];

		printf("���ʴŵ���:%3d �ƶ�����:%3d\n",a[i],move[i]);
	}

	for (i=0; i<i_key; i++)
	{
		min=abs(a[i]-head_track);

		move[i]=min;
		head_track=a[i]; //�ƶ���ͷ
		total_move += move[i];

		printf("���ʴŵ���:%3d �ƶ�����:%3d\n",a[i],move[i]);
	}

	printf("�ƶ��ŵ�������%d\n", total_move);
	avg_track_seeking_len=float(total_move) / TRACK_NUM;
	printf("ƽ��Ѱ������: %3.2f\n", avg_track_seeking_len);
	return avg_track_seeking_len;
}


float NStepSCAN(int rand_track[]) // n��ɨ��
{

	int i,j,k,min,i_key,temp;
	//
	int queue_number;
	int head_track=track_start;

	int total_move=0,move[TRACK_NUM];
	float avg_track_seeking_len;

	printf("\nNStepSCAN�㷨\n");
	printf("--------------------------------------------------------\n");
	printf("��%d�Ŵŵ���ʼ\n",track_start);
	
	//ֵ����
	for(i=0; i<TRACK_NUM; i++)a[i]=rand_track[i];
	//show(a);

    if(TRACK_NUM % NStepSCAN_N==0)
		queue_number=TRACK_NUM / NStepSCAN_N;
	else 
		queue_number=TRACK_NUM / NStepSCAN_N + 1;

	for(k=0; k<queue_number; k++)
	{
		for(i=k*NStepSCAN_N; i<TRACK_NUM && i<(k+1)*NStepSCAN_N; i++)
		{     
			for(j=i+1; j<TRACK_NUM && j<(k+1)*NStepSCAN_N; j++) 
				if(a[i]>a[j])
				{
					temp=a[i]; a[i]=a[j]; a[j]=temp;
				}
		}
	}

	//show(a);

	for(k=0; k< queue_number; k++)
	{
		i_key=-1;
		for(i=k*NStepSCAN_N; i<=(k+1)*NStepSCAN_N; i++)
			if(i==(k+1)*NStepSCAN_N || i==TRACK_NUM || a[i]>head_track){i_key=i; break;}
		
		for (i=i_key; i<TRACK_NUM && i<(k+1)*NStepSCAN_N; i++)
		{
			min=abs(a[i]-head_track);
			move[i]=min;
			head_track=a[i]; //�ƶ���ͷ
			total_move += move[i];
			printf("���ʴŵ���:%3d �ƶ�����:%3d\n",a[i],move[i]);
		}
		
		for (i=i_key-1; i>=k*NStepSCAN_N; i--)
		{
			min=abs(a[i]-head_track);
			move[i]=min;
			head_track=a[i]; //�ƶ���ͷ
			total_move += move[i];
			printf("���ʴŵ���:%3d �ƶ�����:%3d\n",a[i],move[i]);
		}

	}

	printf("�ƶ��ŵ�������%d\n", total_move);
	avg_track_seeking_len=float(total_move) / TRACK_NUM;
	printf("ƽ��Ѱ������: %3.2f\n", avg_track_seeking_len);
	return avg_track_seeking_len;
}

int main(void)
{
	int i,j;

	struct METHOD_INFO
	{
		char str[10];
		float avg_len;
	}method_info[5],temp;

	//memset
	memset(method_info,0,sizeof(method_info));

	init();

	//��ʼ�� method_info ����
	strcpy(method_info[0].str,"FCFS"); method_info[0].avg_len = FCFS(rand_track);
	strcpy(method_info[1].str,"SSTF"); method_info[1].avg_len = SSTF(rand_track);
	strcpy(method_info[2].str,"SCAN"); method_info[2].avg_len = SCAN(rand_track);
	strcpy(method_info[3].str,"CSCAN");method_info[3].avg_len = CSCAN(rand_track);
	strcpy(method_info[4].str,"NStepSCAN"); method_info[4].avg_len = NStepSCAN(rand_track);

	printf("\n�㷨Ч�ʱȽ�\n");
	printf("--------------------------------------------------------\n");
	printf("ƽ��Ѱ������:\n");
	for(i=0; i<5; i++)
		printf("%10s %3.2f\n",method_info[i].str, method_info[i].avg_len);
	printf("\n");

	for(i=0; i<5; i++)
	{     
		for(j=i+1; j<5; j++) 
			if(method_info[i].avg_len > method_info[j].avg_len)
			{
  		     	temp=method_info[i]; method_info[i]=method_info[j]; method_info[j]=temp;
			}
	}

	printf("��Ч�ʸߵͽ�������:\n");
	for(i=0; i<5; i++)
		printf("%10s %3.2f\n",method_info[i].str, method_info[i].avg_len);
	printf("\n");

	system("PAUSE");
	return 0;
}
