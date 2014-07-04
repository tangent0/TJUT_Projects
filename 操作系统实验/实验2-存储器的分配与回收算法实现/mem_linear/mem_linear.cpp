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

void print_mem() //打印内存状态
{
	int i=0,j=0;
    
	printf("----------------------------------------------------\n");
	while(i<MEM_NUM)
	{
		char flag[10];
		strcpy(flag,mem[i].pid);
		j=i;
		while(j<MEM_NUM && strcmp(mem[j].pid,flag)==0)j++;

		printf("起始地址:%2d 长度:%2d 状态:%2s 占用进程:%2s\n",i,j-i,strcmp(mem[i].pid,"")!=0?"占用":"空闲",strcmp(flag,"")!=0?flag:"");
		i=j--;

	}
	printf("\n");
}

void first_fit_assign(PCB proc_x) //用最先适应法为一个进程分配 或 回收内存
{
	int i=0,j=0,k=0;

	while(i<MEM_NUM)
	{
		char flag[10];
		strcpy(flag,mem[i].pid);

		j=i; while(j<MEM_NUM && strcmp(mem[j].pid,flag)==0)j++;

		//如果进程请求分配 
		if(proc_x.ask==1 && strcmp(flag,"")==0 && proc_x.ask_mem<=j-i)
		{
			for(k=i; k<i+proc_x.ask_mem; k++)strcpy(mem[k].pid,proc_x.id); break; 
		}
        //如果进程请求回收
		else if(proc_x.ask==-1 && strcmp(flag,proc_x.id)==0)
		{
			for(k=i; k<j; k++)strcpy(mem[k].pid,""); break;
		}
		//

		i=j--;

	}
}


void best_fit_assign(PCB proc_x) //用最佳适应法为一个进程分配 或 回收内存
{
	int i=0,j=0,k=0;
	int min_len=MEM_NUM+1,i_key=0,j_key=0;

	while(i<MEM_NUM)
	{
		char flag[10];
		strcpy(flag,mem[i].pid);

		j=i; while(j<MEM_NUM && strcmp(mem[j].pid,flag)==0)j++;

		//寻找一个空闲长度最小,同时可进行分配的碎片
		if(proc_x.ask==1 && strcmp(flag,"")==0 && proc_x.ask_mem<=j-i && j-i<min_len  ){min_len=j-i; i_key=i; j_key=j;}	
        
		//回收
		if(proc_x.ask==-1 && strcmp(flag,proc_x.id)==0)
		{
			for(k=i; k<j; k++)strcpy(mem[k].pid,""); break;
		}
		//

		i=j--;
	}

	//分配
	if(proc_x.ask==1)
	{
		for(k=i_key; k<i_key+proc_x.ask_mem; k++)strcpy(mem[k].pid,proc_x.id);
	}
}

void worst_fit_assign(PCB proc_x) //用最坏适应法为一个进程分配 或 回收内存
{
	int i=0,j=0,k=0;
	int max_len=0,i_key=0,j_key=0;

	while(i<MEM_NUM)
	{
		char flag[10];
		strcpy(flag,mem[i].pid);

		j=i; while(j<MEM_NUM && strcmp(mem[j].pid,flag)==0)j++;
        
		//寻找一个空闲长度最大,同时可进行分配的碎片
		if(proc_x.ask==1 && strcmp(flag,"")==0 && proc_x.ask_mem<=j-i && j-i>max_len){max_len=j-i; i_key=i; j_key=j;}
  		//回收      
		if(proc_x.ask==-1 && strcmp(flag,proc_x.id)==0)
		{
			for(k=i; k<j; k++)strcpy(mem[k].pid,""); break;
		}
		//

		i=j--;
	}

	//分配
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

	printf("1.最先适应法 2.最佳适应法 3.最坏适应法\n"); 
	printf("请输入:"); scanf("%d",&cho_num); printf("\n" );
	
	printf("输入时间数:"); scanf("%d",&n); printf("\n" );
	
	printf("依次输入每个进程id，请求（分配1，回收-1），请求空间（xx，-1）：\n\n");

	printf("t=0: （内存初始状态）\n");
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
