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
		System.out.printf("�����%d�����̺ŵ�ID��ʱ������ȼ����ÿո����\n",i+1);
		Scanner reader=new Scanner(System.in);
		//
		proc[i]=new PCB();
		proc[i].id=reader.next();
		proc[i].time=reader.nextInt();
		proc[i].pty=reader.nextInt();
		//
		if(proc[i].time>0)proc[i].is_end=false; //δ����
		else { proc[i].is_end=true; QLen--; }
	}

	//ð�����򣨰�����������
	for(i=0;i<NUM;i++)
		for(j=i+1;j<NUM;j++)
			if(proc[i].pty<proc[j].pty)
			{
				temp=proc[i]; proc[i]=proc[j]; proc[j]=temp;
			}

	System.out.printf("\nʱ��Ƭ�������:\n\n");

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
			System.out.printf("ѡ�н���ID: %s ��ִ��\n",proc[0].id);
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
			System.out.printf("ѡ�н���ID: %s ��ִ��\n",proc[0].id);
			System.out.printf("����ID: %s �ѽ������˳�����\n",proc[0].id);
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
		//try{System.in.read(); System.in.skip(1);} 
		//catch(IOException e) {e.printStackTrace();}

	}

	System.out.printf("�������н��������н���ʱ��Ϊ0�����д�����%d\n",RunTime);
}
}