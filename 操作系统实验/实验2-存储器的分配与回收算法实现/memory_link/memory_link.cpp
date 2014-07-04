#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEM_NUM 32

struct PCB
{
	char id[10];
	int ask;     //assign for 1,dispose for -1
	int ask_mem;  //ask memory
}*pcb_pointer;

struct MEM_STATE
{
	char pid[10]; //process id that occupied Memory
	int start_addr; //starting address
	int length;     //length for pid
	MEM_STATE *next;
}*mem_head_pointer;

void print_mem() //打印内存状态
{
	MEM_STATE *mem_pointer=mem_head_pointer;
    
	printf("----------------------------------------------------\n");
	while(mem_pointer!=NULL)
	{
		printf("起始地址:%2d 长度:%2d 状态:%2s 占用进程:%2s\n",
			mem_pointer->start_addr,mem_pointer->length,strcmp(mem_pointer->pid,"")!=0?"占用":"空闲",strcmp(mem_pointer->pid,"")!=0?mem_pointer->pid:"");

		mem_pointer=mem_pointer->next;
	
	}
	
	printf("\n");
}

void first_fit_assign(PCB *proc_x_pointer) //用最先适应法为一个进程分配 或 回收内存
{
	MEM_STATE *mem_pointer=mem_head_pointer,*temp=mem_head_pointer; //temp初始化为头指针，下面保存mem_pointer的前一个指针

	while(mem_pointer!=NULL)
	{
		//如果进程请求分配 
		if(proc_x_pointer->ask==1 && strcmp(mem_pointer->pid,"")==0 && proc_x_pointer->ask_mem<=mem_pointer->length)
		{
			temp=(MEM_STATE *)malloc(sizeof(MEM_STATE)); //碎片
			strcpy(temp->pid,"");
			temp->start_addr=mem_pointer->start_addr + proc_x_pointer->ask_mem;
			temp->length=mem_pointer->length - proc_x_pointer->ask_mem;
			temp->next=NULL;

			strcpy(mem_pointer->pid,proc_x_pointer->id); //占用区
			mem_pointer->length=proc_x_pointer->ask_mem;

			temp->next=mem_pointer->next; //将碎片插入到 占用区 和 下一个单元 之间
			mem_pointer->next=temp;
			
			break; 
		}
	    //如果进程请求回收
		else if(proc_x_pointer->ask==-1 && strcmp(mem_pointer->pid,proc_x_pointer->id)==0)
		{
		
			strcpy(mem_pointer->pid,""); //将这个单元标记为空闲区

			if((temp==mem_head_pointer || strcmp(temp->pid,"")==0) 				//前后空闲时,将中间与前后同时合并
				&& mem_pointer->next!=NULL && strcmp(mem_pointer->next->pid,"")==0)
			{				
				if(temp!=mem_pointer)
					temp->length += mem_pointer->length + mem_pointer->next->length;
				else temp->length += mem_pointer->next->length;
				
				temp->next=mem_pointer->next->next;

				free(mem_pointer->next);
				if(temp!=mem_pointer)
					free(mem_pointer);

			}else if((temp==mem_head_pointer || strcmp(temp->pid,"")==0) 		//前面空闲,后面占用时,将中间与前面合并
				&& mem_pointer->next!=NULL && strcmp(mem_pointer->next->pid,"")!=0)
			{
				if(temp!=mem_pointer)
					temp->length += mem_pointer->length;
				
				temp->next=mem_pointer->next;
				
				if(temp!=mem_pointer)
					free(mem_pointer);			
			}else if((temp==mem_head_pointer || strcmp(temp->pid,"")!=0) 		//前面占用,后面空闲时,将中间与后面合并
				&& mem_pointer->next!=NULL && strcmp(mem_pointer->next->pid,"")==0)
			{
				if(temp!=mem_pointer)
					mem_pointer->length += mem_pointer->next->length;
				
				mem_pointer->next=mem_pointer->next->next;

				free(mem_pointer->next);			
			}

			break;
			
		}
		//
		
		temp=mem_pointer;
		mem_pointer=mem_pointer->next;
	}

}

void best_fit_assign(PCB *proc_x_pointer) //用最佳适应法为一个进程分配 或 回收内存
{
	MEM_STATE *min_len_mem_pointer;
	MEM_STATE *mem_pointer=mem_head_pointer,*temp=mem_head_pointer;

	int min_len=MEM_NUM+1;  //let max( min_len ) = MEM_NUM+1
	while(mem_pointer!=NULL) //寻找一个空闲长度最小,同时可进行分配的碎片
	{
		if(strcmp(mem_pointer->pid,"")==0 && mem_pointer->length<min_len 
			&& proc_x_pointer->ask_mem<=mem_pointer->length)
		{min_len_mem_pointer=mem_pointer; min_len=mem_pointer->length; }
		
		mem_pointer=mem_pointer->next;
	}

	//printf("%s,%d,%d\n",max_len_mem_pointer->pid,max_len_mem_pointer->start_addr,max_len_mem_pointer->length);
	
    mem_pointer=mem_head_pointer;

	while(mem_pointer!=NULL) //重新扫描,找到 合适的地址 进行分配 或者 回收
	{
		//
		if(proc_x_pointer->ask==1 && mem_pointer==min_len_mem_pointer && proc_x_pointer->ask_mem<=mem_pointer->length)
		{
			temp=(MEM_STATE *)malloc(sizeof(MEM_STATE));
			strcpy(temp->pid,"");
			temp->start_addr=mem_pointer->start_addr + proc_x_pointer->ask_mem;
			temp->length=mem_pointer->length - proc_x_pointer->ask_mem;
			temp->next=NULL;

			strcpy(mem_pointer->pid,proc_x_pointer->id);
			mem_pointer->length=proc_x_pointer->ask_mem;

			temp->next=mem_pointer->next;
			mem_pointer->next=temp;
			
			break; 
		}
		else if(proc_x_pointer->ask==-1 && strcmp(mem_pointer->pid,proc_x_pointer->id)==0)
		{
		
			strcpy(mem_pointer->pid,"");

			if((temp==mem_head_pointer || strcmp(temp->pid,"")==0) 
				&& mem_pointer->next!=NULL && strcmp(mem_pointer->next->pid,"")==0)
			{				
				if(temp!=mem_pointer)
					temp->length += mem_pointer->length + mem_pointer->next->length;
				else temp->length += mem_pointer->next->length;
				//
				temp->next=mem_pointer->next->next;
				
				free(mem_pointer->next);	
				if(temp!=mem_pointer)
					free(mem_pointer);

			}else if((temp==mem_head_pointer || strcmp(temp->pid,"")==0) 
				&& mem_pointer->next!=NULL && strcmp(mem_pointer->next->pid,"")!=0)
			{
				if(temp!=mem_pointer)
					temp->length += mem_pointer->length;
				//
				temp->next=mem_pointer->next;

				if(temp!=mem_pointer)
					free(mem_pointer);			
			}else if((temp==mem_head_pointer || strcmp(temp->pid,"")!=0) 
				&& mem_pointer->next!=NULL && strcmp(mem_pointer->next->pid,"")==0)
			{
				if(temp!=mem_pointer)
					mem_pointer->length += mem_pointer->next->length;
				//
				mem_pointer->next=mem_pointer->next->next;

				free(mem_pointer->next);			
			}

			break;
			
		}
		//
		
		temp=mem_pointer;
		mem_pointer=mem_pointer->next;
	}

}

void worst_fit_assign(PCB *proc_x_pointer) //用最坏适应法为一个进程分配 或 回收内存
{
	MEM_STATE *max_len_mem_pointer;
	MEM_STATE *mem_pointer=mem_head_pointer,*temp=mem_head_pointer;

	int max_len=0; // let min( max_len )=0
	while(mem_pointer!=NULL) //寻找一个空闲长度最大,同时可进行分配的碎片
	{
		if(strcmp(mem_pointer->pid,"")==0 && mem_pointer->length>max_len 
			&& proc_x_pointer->ask_mem<=mem_pointer->length)
		{max_len_mem_pointer=mem_pointer; max_len=mem_pointer->length; }
		
		mem_pointer=mem_pointer->next;
	}

	//printf("%s,%d,%d\n",max_len_mem_pointer->pid,max_len_mem_pointer->start_addr,max_len_mem_pointer->length);
	
    mem_pointer=mem_head_pointer;

	while(mem_pointer!=NULL) //重新扫描,找到 合适的地址 进行分配 或者 回收
	{
		//
		if(proc_x_pointer->ask==1 && mem_pointer==max_len_mem_pointer && proc_x_pointer->ask_mem<=mem_pointer->length)
		{
			temp=(MEM_STATE *)malloc(sizeof(MEM_STATE));
			strcpy(temp->pid,"");
			temp->start_addr=mem_pointer->start_addr + proc_x_pointer->ask_mem;
			temp->length=mem_pointer->length - proc_x_pointer->ask_mem;
			temp->next=NULL;

			strcpy(mem_pointer->pid,proc_x_pointer->id);
			mem_pointer->length=proc_x_pointer->ask_mem;

			temp->next=mem_pointer->next;
			mem_pointer->next=temp;
			
			break; 
		}
		else if(proc_x_pointer->ask==-1 && strcmp(mem_pointer->pid,proc_x_pointer->id)==0)
		{
		
			strcpy(mem_pointer->pid,"");

			if((temp==mem_head_pointer || strcmp(temp->pid,"")==0) 
				&& mem_pointer->next!=NULL && strcmp(mem_pointer->next->pid,"")==0)
			{				
				if(temp!=mem_pointer)
					temp->length += mem_pointer->length + mem_pointer->next->length;
				else temp->length += mem_pointer->next->length;
				//
				temp->next=mem_pointer->next->next;

				free(mem_pointer->next);
				if(temp!=mem_pointer)
					free(mem_pointer);

			}else if((temp==mem_head_pointer || strcmp(temp->pid,"")==0) 
				&& mem_pointer->next!=NULL && strcmp(mem_pointer->next->pid,"")!=0)
			{
				if(temp!=mem_pointer)
					temp->length += mem_pointer->length;
				//
				temp->next=mem_pointer->next;
				
				if(temp!=mem_pointer)
					free(mem_pointer);			
			}else if((temp==mem_head_pointer || strcmp(temp->pid,"")!=0) 
				&& mem_pointer->next!=NULL && strcmp(mem_pointer->next->pid,"")==0)
			{
				if(temp!=mem_pointer)
					mem_pointer->length += mem_pointer->next->length;
				//
				mem_pointer->next=mem_pointer->next->next;
				
				free(mem_pointer->next);			
			}

			break;
			
		}
		//
		
		temp=mem_pointer;
		mem_pointer=mem_pointer->next;
	}

}

void clear_mem() //清空存储单元
{
	MEM_STATE *mem_pointer=mem_head_pointer,*temp;

	while(mem_pointer!=NULL)
	{
		temp=mem_pointer;
		mem_pointer=mem_pointer->next;
		free(temp);
	}
}

int main(void)
{
	int i,n,cho_num;

	printf("1.最先适应法 2.最佳适应法 3.最坏适应法\n"); 
	printf("请输入:"); scanf("%d",&cho_num); printf("\n" );

	printf("输入时间数:"); scanf("%d",&n); printf("\n" );
	printf("输入每个进程id，请求（分配1，回收-1），请求空间（xx，-1）：\n\n");

	mem_head_pointer=(MEM_STATE *)malloc(sizeof(MEM_STATE));
	strcpy(mem_head_pointer->pid,"");
	mem_head_pointer->start_addr=0;
	mem_head_pointer->length=MEM_NUM;
	mem_head_pointer->next=NULL;

	printf("t=0: （内存初始状态）\n");
	print_mem();

	pcb_pointer=(PCB *)malloc(sizeof(PCB));
	//memset
	memset(pcb_pointer,0,sizeof(pcb_pointer));

	for(i=0;i<n;i++)
	{
	  printf("t=%d: ",i+1);
	  scanf("%s %d %d",pcb_pointer->id, &(pcb_pointer->ask), &(pcb_pointer->ask_mem)); 

	  switch(cho_num){
	  case 1: first_fit_assign(pcb_pointer); break;
	  case 2: best_fit_assign(pcb_pointer); break;
	  case 3: worst_fit_assign(pcb_pointer); break;
	  default : exit(0);
	  }
	  
	  print_mem();
	}

	clear_mem();
	if(pcb_pointer)free(pcb_pointer);

	system("PAUSE");
	return 0;
}
