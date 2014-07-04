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

void print_mem() //��ӡ�ڴ�״̬
{
	MEM_STATE *mem_pointer=mem_head_pointer;
    
	printf("----------------------------------------------------\n");
	while(mem_pointer!=NULL)
	{
		printf("��ʼ��ַ:%2d ����:%2d ״̬:%2s ռ�ý���:%2s\n",
			mem_pointer->start_addr,mem_pointer->length,strcmp(mem_pointer->pid,"")!=0?"ռ��":"����",strcmp(mem_pointer->pid,"")!=0?mem_pointer->pid:"");

		mem_pointer=mem_pointer->next;
	
	}
	
	printf("\n");
}

void first_fit_assign(PCB *proc_x_pointer) //��������Ӧ��Ϊһ�����̷��� �� �����ڴ�
{
	MEM_STATE *mem_pointer=mem_head_pointer,*temp=mem_head_pointer; //temp��ʼ��Ϊͷָ�룬���汣��mem_pointer��ǰһ��ָ��

	while(mem_pointer!=NULL)
	{
		//�������������� 
		if(proc_x_pointer->ask==1 && strcmp(mem_pointer->pid,"")==0 && proc_x_pointer->ask_mem<=mem_pointer->length)
		{
			temp=(MEM_STATE *)malloc(sizeof(MEM_STATE)); //��Ƭ
			strcpy(temp->pid,"");
			temp->start_addr=mem_pointer->start_addr + proc_x_pointer->ask_mem;
			temp->length=mem_pointer->length - proc_x_pointer->ask_mem;
			temp->next=NULL;

			strcpy(mem_pointer->pid,proc_x_pointer->id); //ռ����
			mem_pointer->length=proc_x_pointer->ask_mem;

			temp->next=mem_pointer->next; //����Ƭ���뵽 ռ���� �� ��һ����Ԫ ֮��
			mem_pointer->next=temp;
			
			break; 
		}
	    //��������������
		else if(proc_x_pointer->ask==-1 && strcmp(mem_pointer->pid,proc_x_pointer->id)==0)
		{
		
			strcpy(mem_pointer->pid,""); //�������Ԫ���Ϊ������

			if((temp==mem_head_pointer || strcmp(temp->pid,"")==0) 				//ǰ�����ʱ,���м���ǰ��ͬʱ�ϲ�
				&& mem_pointer->next!=NULL && strcmp(mem_pointer->next->pid,"")==0)
			{				
				if(temp!=mem_pointer)
					temp->length += mem_pointer->length + mem_pointer->next->length;
				else temp->length += mem_pointer->next->length;
				
				temp->next=mem_pointer->next->next;

				free(mem_pointer->next);
				if(temp!=mem_pointer)
					free(mem_pointer);

			}else if((temp==mem_head_pointer || strcmp(temp->pid,"")==0) 		//ǰ�����,����ռ��ʱ,���м���ǰ��ϲ�
				&& mem_pointer->next!=NULL && strcmp(mem_pointer->next->pid,"")!=0)
			{
				if(temp!=mem_pointer)
					temp->length += mem_pointer->length;
				
				temp->next=mem_pointer->next;
				
				if(temp!=mem_pointer)
					free(mem_pointer);			
			}else if((temp==mem_head_pointer || strcmp(temp->pid,"")!=0) 		//ǰ��ռ��,�������ʱ,���м������ϲ�
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

void best_fit_assign(PCB *proc_x_pointer) //�������Ӧ��Ϊһ�����̷��� �� �����ڴ�
{
	MEM_STATE *min_len_mem_pointer;
	MEM_STATE *mem_pointer=mem_head_pointer,*temp=mem_head_pointer;

	int min_len=MEM_NUM+1;  //let max( min_len ) = MEM_NUM+1
	while(mem_pointer!=NULL) //Ѱ��һ�����г�����С,ͬʱ�ɽ��з������Ƭ
	{
		if(strcmp(mem_pointer->pid,"")==0 && mem_pointer->length<min_len 
			&& proc_x_pointer->ask_mem<=mem_pointer->length)
		{min_len_mem_pointer=mem_pointer; min_len=mem_pointer->length; }
		
		mem_pointer=mem_pointer->next;
	}

	//printf("%s,%d,%d\n",max_len_mem_pointer->pid,max_len_mem_pointer->start_addr,max_len_mem_pointer->length);
	
    mem_pointer=mem_head_pointer;

	while(mem_pointer!=NULL) //����ɨ��,�ҵ� ���ʵĵ�ַ ���з��� ���� ����
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

void worst_fit_assign(PCB *proc_x_pointer) //�����Ӧ��Ϊһ�����̷��� �� �����ڴ�
{
	MEM_STATE *max_len_mem_pointer;
	MEM_STATE *mem_pointer=mem_head_pointer,*temp=mem_head_pointer;

	int max_len=0; // let min( max_len )=0
	while(mem_pointer!=NULL) //Ѱ��һ�����г������,ͬʱ�ɽ��з������Ƭ
	{
		if(strcmp(mem_pointer->pid,"")==0 && mem_pointer->length>max_len 
			&& proc_x_pointer->ask_mem<=mem_pointer->length)
		{max_len_mem_pointer=mem_pointer; max_len=mem_pointer->length; }
		
		mem_pointer=mem_pointer->next;
	}

	//printf("%s,%d,%d\n",max_len_mem_pointer->pid,max_len_mem_pointer->start_addr,max_len_mem_pointer->length);
	
    mem_pointer=mem_head_pointer;

	while(mem_pointer!=NULL) //����ɨ��,�ҵ� ���ʵĵ�ַ ���з��� ���� ����
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

void clear_mem() //��մ洢��Ԫ
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

	printf("1.������Ӧ�� 2.�����Ӧ�� 3.���Ӧ��\n"); 
	printf("������:"); scanf("%d",&cho_num); printf("\n" );

	printf("����ʱ����:"); scanf("%d",&n); printf("\n" );
	printf("����ÿ������id�����󣨷���1������-1��������ռ䣨xx��-1����\n\n");

	mem_head_pointer=(MEM_STATE *)malloc(sizeof(MEM_STATE));
	strcpy(mem_head_pointer->pid,"");
	mem_head_pointer->start_addr=0;
	mem_head_pointer->length=MEM_NUM;
	mem_head_pointer->next=NULL;

	printf("t=0: ���ڴ��ʼ״̬��\n");
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
