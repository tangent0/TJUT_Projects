/*
*       Program:        client_base.c
*       Author:         Paul Girard Ph.D., DIM, UQAC
*       Date:           Sept 2011
*
*       Objective:      Show how to use a tcp socket
*                       on a client program running on
*                       Sun/ Solaris ; this program transmits
*                       a message to a server and receives
*                       an acknowledge each time.  A delay of
*                       one second is introduced between messages.
*
*       Options to compile on Solaris:          
*       ===>    gcc client_base.c -lsocket -lnsl -o client_base
*       Options to compile on Linux:          
*       ===>    gcc client_base.c -lnsl -o client_base
*
*       Execution: 3 parameters: program_name server_name server port_number
*       =========>  client_base server_machine port_number
*               ex. client_base dimensxcn1.uqac.ca 5001
*
*
*       Files to include
*/
#include <errno.h>         
/* #include <strings.h> */ 
#include <string.h>        
#include <sys/types.h>     
#include <sys/socket.h>    
#include <netinet/in.h>
#include <netdb.h>         
#include <time.h>      
#include <stdio.h>         

#include <stdlib.h>

/*
*       The following functions are used in this program
*
*               socket, gethostbyname, connect, 
*               read, write, close.
*/

#define TRUE 1

#define bufsize 128

main(argc,argv)
        int argc;
        char *argv[];                   /* argv[0] pointer to program name
                                           argv[1] pointer to server name
                                           argv[2] pointer to tcp port number*/
{
        int sock2, msgsock;             /* socket descriptor */
        struct sockaddr_in server2;     /* structure used to assign a name
                                   to a socket sccording internet format*/
        size_t length;                  /* #octets in structure sockadr_in */
        struct hostent *hp,*gethostbyname(); /* structure to associate the
                                        server name and its address */
        struct hostent hpstruct; /* structure to access the server address*/
        char buf[bufsize];         /* message buffer*/ 
        int rval;               /* status code for read */
        int n, i;               /* temporary */
/*
*       1. Validation of the parameters read on the command line
*/
        if (argc != 3)
        {
          printf("Call the program : client_base server_name port_number\n");
          return 0;
        }
/*
*       2. Socket creation parameters:          
*               - AF_INET is the internet format 
*               - SOCK_STREAM specifies a TCP type socket
*               - 0 specifies to use the default protocol.
*/
        sock2 = socket(AF_INET, SOCK_STREAM, 0);
        if (sock2 < 0) 
        {
                perror("Error in creating a TCP socket");
                return 0;
        }
/*
*       3. Get a pointer to the network server address structure.
*          The server name is taken from the command line (argv[1]):
*               ex.  "sunens.uqac.ca"
*/
        server2.sin_family = AF_INET;   /* internet format*/
        hp = gethostbyname(argv[1]);    /* pointer to the network structure
                                        of the server listening on port
                                        argv[1] */
        if (hp == 0)
        {
                fprintf(stderr, "%s: unknown host ===>", argv[1]);
                return 0;
        }
        hpstruct = *hp; /*  save  hostent data */

/*
*       4. Fill in the remote address part
*/
        server2.sin_family = hpstruct.h_addrtype;
        server2.sin_port = htons(atoi(argv[2]));  /* char port # ==>integer port #
                                                     ====> network 16 bits format */
        server2.sin_addr = * ((struct in_addr *) hpstruct.h_addr);

/*      5. Try a connection with the server
*/
        if (connect(sock2, (struct sockaddr *)&server2, sizeof(server2)) < 0)
        {
                perror("Error at connect time");
                return 0;
        }

/*
*       6.  
*       
*/

		FILE *fptr; /*pointer to file descriptor*/
		char filename_local[20],filename_remote[20];
		do
         {
               puts("Enter the name of the local file to transfer:");
               scanf("%s",filename_local);
               if((fptr=fopen(filename_local,"r"))==NULL)
               {
				   perror("error opening this file");
				   exit(0);
               }
               puts("Enter the given name of this file on the remote server:");
               scanf("%s",filename_remote);
           
               if(write(sock2, filename_remote, sizeof (filename_remote)) < 0)
                        perror("Error in the transmission of message");
               else { 
                        /*  read a message from the server */
                        if ((rval = read(sock2, buf, sizeof(buf))) < 0)
                           perror("Error in reading a message");
                        if (rval == 0)
                           printf("End of connection\n");
            
                     }
        } while (buf=="ACK"); 

        struct timespec time1,time2,temp; /*time_t tv_sec; seconds*/  /*long tv_nsec; nanoseconds*/
        double delay;      

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time1); /*read the timer1 nanosec*/
		
		int nline=0,noctets=0;
        while(fgets(buf,sizeof(buf),fptr)) /*read a file record*/
        {		
			              
			   noctets+=strlen(buf);
			   nline++;

               if(write(sock2, buf, sizeof(buf)) < 0)
                        perror("Error in the transmission of message");
			   
			   //printf("%s\n",buf);
               if(feof(fptr))break;

        }
        fclose(fptr);

        close(sock2);

		clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time2); /*read the timer2 nanosec*/ /*Statistics*/
        
		if((time2.tv_nsec-time1.tv_nsec)<0)
        {
            temp.tv_sec=time2.tv_sec-time1.tv_sec-1;
            temp.tv_nsec=1000000000+time2.tv_nsec-time1.tv_nsec;
        }
		else
        {
            temp.tv_sec=time2.tv_sec-time1.tv_sec;
            temp.tv_nsec=time2.tv_nsec-time1.tv_nsec;
        }
       delay=(double)((temp.tv_sec*1000))+(temp.tv_nsec/1000000); //dalay in msec
       
	   printf("File %s had %d lines and a total of %d octets\n",filename_local,nline,noctets);
       printf("Transfer rate: %9.5fKo/sec \t\t Transfer TCP dalay : %9.5f msec\n",(double)(noctets*1000)/(1024*delay),delay);
       
	   puts("End of client program\n");
       return 0;;        /* end of client program */
}
