import java.util.Scanner;
import java.io.IOException;

class PCB
{
	String id; //process id
	int time; //service time
	int pty; //priority
	boolean is_end; //state
}

public class Priority_2
{
public static void main(String args[])
{
	final int NUM=5;
	PCB temp,proc[]; //PCB array
	int i=0,j=0,RunTime=0,QLen=NUM; //QueLength

	//memset
	proc=new PCB[5];

	//input each PCB
	for(i=0;i<NUM;i++)
	{
		System.out.printf("输入第%d个进程号的ID，时间和优先级，用空格隔开\n",i+1);
		Scanner reader=new Scanner(System.in);
		//
		proc[i]=new PCB();
		proc[i].id=reader.next();
		proc[i].time=reader.nextInt();
		proc[i].pty=reader.nextInt();
		//
		if(proc[i].time>0)proc[i].is_end=false; //未结束
		else { proc[i].is_end=true; QLen--; }
	}

	//冒泡排序（按优先数排序）
	for(i=0;i<NUM;i++)
		for(j=i+1;j<NUM;j++)
			if(proc[i].pty<proc[j].pty)
			{
				temp=proc[i]; proc[i]=proc[j]; proc[j]=temp;
			}

	System.out.printf("\n时间片分配过程:\n\n");

	while(true)
	{	
		System.out.printf("RunTime %d\n",QLen>0 ? ++RunTime : RunTime);
		for(i=0;i<NUM;i++)
		{
			System.out.printf("ProcID:%s RestTime:%d RestPty:%d Finished: %s\n",
				proc[i].id,proc[i].time,proc[i].pty,proc[i].is_end?"Y":"N");
		}
		System.out.printf("----------------------------------------------------------------\n");
		
		if(QLen<=0)break;

		if(proc[0].time>1 && proc[0].is_end==false)
		{			
			System.out.printf("选中进程ID: %s 并执行\n",proc[0].id);
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
			System.out.printf("选中进程ID: %s 并执行\n",proc[0].id);
			System.out.printf("进程ID: %s 已结束，退出队列\n",proc[0].id);
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
		//try{System.in.read(); System.in.skip(1);} 
		//catch(IOException e) {e.printStackTrace();}

	}

	System.out.printf("程序运行结束，所有进程时间为0，运行次数：%d\n",RunTime);
}
}