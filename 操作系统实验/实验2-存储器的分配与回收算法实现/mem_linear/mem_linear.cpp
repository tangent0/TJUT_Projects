#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PROC_NUM 10
#define MEM_NUM 32

struct PCB
{
	char id[10];
	//int arr_time; //arrive time
	//int lea_time; //leave time
	int ask;     //assign for 1,dispose for 0
	int ask_mem;  //ask memory
}proc[PROC_NUM];

struct MEM_STATE
{
	char pid[10]; //process id that occupied Memory
}mem[MEM_NUM];

void print_mem() //��ӡ�ڴ�״̬
{
	int i=0,j=0;
    
	printf("----------------------------------------------------\n");
	while(i<MEM_NUM)
	{
		char flag[10];
		strcpy(flag,mem[i].pid);
		j=i;
		while(j<MEM_NUM && strcmp(mem[j].pid,flag)==0)j++;

		printf("��ʼ��ַ:%2d ����:%2d ״̬:%2s ռ�ý���:%2s\n",i,j-i,strcmp(mem[i].pid,"")!=0?"ռ��":"����",strcmp(flag,"")!=0?flag:"");
		i=j--;

	}
	printf("\n");
}

void first_fit_assign(PCB proc_x) //��������Ӧ��Ϊһ�����̷��� �� �����ڴ�
{
	int i=0,j=0,k=0;

	while(i<MEM_NUM)
	{
		char flag[10];
		strcpy(flag,mem[i].pid);

		j=i; while(j<MEM_NUM && strcmp(mem[j].pid,flag)==0)j++;

		//�������������� 
		if(proc_x.ask==1 && strcmp(flag,"")==0 && proc_x.ask_mem<=j-i)
		{
			for(k=i; k<i+proc_x.ask_mem; k++)strcpy(mem[k].pid,proc_x.id); break; 
		}
        //��������������
		else if(proc_x.ask==-1 && strcmp(flag,proc_x.id)==0)
		{
			for(k=i; k<j; k++)strcpy(mem[k].pid,""); break;
		}
		//

		i=j--;

	}
}


void best_fit_assign(PCB proc_x) //�������Ӧ��Ϊһ�����̷��� �� �����ڴ�
{
	int i=0,j=0,k=0;
	int min_len=MEM_NUM+1,i_key=0,j_key=0;

	while(i<MEM_NUM)
	{
		char flag[10];
		strcpy(flag,mem[i].pid);

		j=i; while(j<MEM_NUM && strcmp(mem[j].pid,flag)==0)j++;

		//Ѱ��һ�����г�����С,ͬʱ�ɽ��з������Ƭ
		if(proc_x.ask==1 && strcmp(flag,"")==0 && proc_x.ask_mem<=j-i && j-i<min_len  ){min_len=j-i; i_key=i; j_key=j;}	
        
		//����
		if(proc_x.ask==-1 && strcmp(flag,proc_x.id)==0)
		{
			for(k=i; k<j; k++)strcpy(mem[k].pid,""); break;
		}
		//

		i=j--;
	}

	//����
	if(proc_x.ask==1)
	{
		for(k=i_key; k<i_key+proc_x.ask_mem; k++)strcpy(mem[k].pid,proc_x.id);
	}
}

void worst_fit_assign(PCB proc_x) //�����Ӧ��Ϊһ�����̷��� �� �����ڴ�
{
	int i=0,j=0,k=0;
	int max_len=0,i_key=0,j_key=0;

	while(i<MEM_NUM)
	{
		char flag[10];
		strcpy(flag,mem[i].pid);

		j=i; while(j<MEM_NUM && strcmp(mem[j].pid,flag)==0)j++;
        
		//Ѱ��һ�����г������,ͬʱ�ɽ��з������Ƭ
		if(proc_x.ask==1 && strcmp(flag,"")==0 && proc_x.ask_mem<=j-i && j-i>max_len){max_len=j-i; i_key=i; j_key=j;}
  		//����      
		if(proc_x.ask==-1 && strcmp(flag,proc_x.id)==0)
		{
			for(k=i; k<j; k++)strcpy(mem[k].pid,""); break;
		}
		//

		i=j--;
	}

	//����
	if(proc_x.ask==1)
	{
		for(k=i_key; k<i_key+proc_x.ask_mem; k++)strcpy(mem[k].pid,proc_x.id);
	}

}

int main(void)
{
	int i,n,cho_num;
    
	//memset
	memset(proc,0,sizeof(proc));
	memset(mem,0,sizeof(mem));

	printf("1.������Ӧ�� 2.�����Ӧ�� 3.���Ӧ��\n"); 
	printf("������:"); scanf("%d",&cho_num); printf("\n" );
	
	printf("����ʱ����:"); scanf("%d",&n); printf("\n" );
	
	printf("��������ÿ������id�����󣨷���1������-1��������ռ䣨xx��-1����\n\n");

	printf("t=0: ���ڴ��ʼ״̬��\n");
	print_mem();
	
	for(i=0;i<n;i++)
	{
	  printf("t=%d: ",i+1);
	  scanf("%s %d %d",proc[i].id, //&proc[i].arr_time, &proc[i].lea_time, 
		  &proc[i].ask, &proc[i].ask_mem); 
	  
	  switch(cho_num){
	  case 1: first_fit_assign(proc[i]); break;
	  case 2: best_fit_assign(proc[i]); break;
	  case 3: worst_fit_assign(proc[i]); break;
	  default : exit(0);
	  }
	  
	  print_mem();
	}

	system("PAUSE");

	return 0;
}
