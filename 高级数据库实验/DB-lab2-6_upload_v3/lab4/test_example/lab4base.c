
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[12];
};
static const struct sqlcxp sqlfpn =
{
    11,
    "lab4base.pc"
};


static unsigned int sqlctx = 143251;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

 static const char *sq0007 = 
"select p.part_number ,p.part_name ,pa.emp_num ,pa.pa_name  from part p ,resp\
onsible r ,pa_agent pa where (pa.emp_num=r.emp_num and p.part_number=r.part_nu\
mber)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4146,1,0,0,
5,0,0,1,0,0,30,57,0,0,0,0,0,1,0,
20,0,0,2,0,0,32,80,0,0,0,0,0,1,0,
35,0,0,0,0,0,27,93,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
66,0,0,4,0,0,29,115,0,0,0,0,0,1,0,
81,0,0,5,141,0,6,122,0,0,3,3,0,1,0,2,97,0,0,1,3,0,0,2,3,0,0,
108,0,0,6,0,0,29,145,0,0,0,0,0,1,0,
123,0,0,7,170,0,9,166,0,0,0,0,0,1,0,
138,0,0,7,0,0,13,173,0,0,4,0,0,1,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
169,0,0,7,0,0,15,179,0,0,0,0,0,1,0,
184,0,0,8,0,0,29,180,0,0,0,0,0,1,0,
199,0,0,9,244,0,6,204,0,0,2,2,0,1,0,1,3,0,0,2,3,0,0,
222,0,0,10,186,0,6,249,0,0,2,2,0,1,0,1,3,0,0,2,3,0,0,
};


/*
*       Author:         Paul Girard Ph.D., UQAC
*       Date:           March 2008 
*       Objective:      Program using Pro*C/C++ and gcc to show how to use 
*                       different type of PL/SQL blocks & SQL in a C PGM
*
*       Step 1: Precompilation with Pro*C/C++
* proc INAME=lab4base.pc CODE=ANSI_C SQLCHECK=semantics MODE=oracle DBMS=v8 USERID=user/password CHAR_MAP=charz
*
*       Step 2: Compilation with gcc    
* gcc lab4base.c -o lab4base -include /$ORACLE_HOME/precomp/public/sqlca.h -lclntsh -L$ORACLE_HOME/lib/ -B$ORACLE_HOME/lib
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void sql_error();
void do_connect();
void lispart();
void respon();
void modstat();
void deletion();
int print_menu();

int main()
{ 
        /* EXEC SQL WHENEVER SQLERROR do sql_error("Error at connect"); */ 
 
        
        do_connect();           /* connection to Oracle instance */

/*      Display the program menu
*       and execution of the transaction 
*/
        
        while (1)       /* infinite loop */
        {
         switch (print_menu())
         {
          case 1: lispart();
                  break;
          case 2: respon();
                  break;
          case 3: modstat();
                  break;
          case 4: deletion();
                  break;
          case 5: print_menu();
                  break;
                 case 6: puts("\nAu revoir Sayonara Bye bye, Ni Hao"); 
                exit(0);
          default: puts("\n =====> Enter a digit from the menu please ?");
                   break;
         }
        }
        
        /* EXEC SQL COMMIT WORK RELEASE; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 0;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("Error at connect");
}

           /* libère les verroux et déconnecte */
                                        
        exit(0); 
}                       /* end of main() program */

/* ******************************************************************************************
*       Function to display the original error Oracle message 
*  ******************************************************************************************
*/

void sql_error(char *msg)
{
        char ora_msg[16];                      /* buffer for Oracle error message */
        int buf_len, msg_len;
        
        /* EXEC SQL WHENEVER SQLERROR continue; */ 
    /* Prevent an infinite loop */
        
        printf("\n%s\n",msg);                   /* print the local program message */
        buf_len=sizeof(ora_msg);
        
        sqlglm(ora_msg,&buf_len, &msg_len);     /* read the Oracle error message */
        printf("\n%.*s\n",msg_len, ora_msg);    /* print this message */
        
        /* EXEC SQL ROLLBACK RELEASE; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 0;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )20;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

              /* free locks */
        exit(1);
}               /*      fin de sql_error */

/* ******************************************************************************************
*       Function to do a connection to an Oracle user schema
*  ******************************************************************************************
*/

void do_connect()
{
   char *uid="ora00176/RFy7qP";

        /* EXEC SQL CONNECT :uid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )10;
        sqlstm.offset = (unsigned int  )35;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)uid;
        sqlstm.sqhstl[0] = (unsigned long )0;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlstm.sqlcmax = (unsigned int )100;
        sqlstm.sqlcmin = (unsigned int )2;
        sqlstm.sqlcincr = (unsigned int )1;
        sqlstm.sqlctimeout = (unsigned int )0;
        sqlstm.sqlcnowait = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

 
        printf("Connected to Oracle schema\n");
}

/* ******************************************************************************************
*       Function to display the contents of a given part
*  ******************************************************************************************
*/

void lispart()
{
char    description[16];     /* C needs 1 more octet than Oracle for binary 0 
                                at the end of a C character type */
int     my_part_number, none=1;
        for (;;)                /* infinite loop until user enter a 0 */
        {
                printf("Number of the part (0 to quit )? ");
                scanf("%d",&my_part_number);         

                printf("Part Number : %d\n",my_part_number);
                if (my_part_number == 0) 
                { 
                        /* EXEC SQL COMMIT; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 4;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )66;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

 
                        printf("End of this transaction\n"); 
                        break; 
                } 

/*-------------- Beginning the PL/SQL block -----------------*/ 

        /* EXEC SQL EXECUTE
        BEGIN 
                SELECT part_name INTO :description      /o note: description needs 1 octet more o/
                FROM part WHERE part_number = :my_part_number;
                EXCEPTION
                        WHEN NO_DATA_FOUND THEN 
                        :none:=0;
        END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin SELECT part_name INTO :description FROM part WH\
ERE part_number = :my_part_number ; EXCEPTION WHEN NO_DATA_FOUND THEN :none :=\
 0 ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )81;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)description;
        sqlstm.sqhstl[0] = (unsigned long )16;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&my_part_number;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&none;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



/*-------------- end of PL/SQL block -----------------*/ 

        if (none==0)  
           {
                printf("Record not found \n");
                none=1;
           }
        else
            {
                printf("Name of the part\n"); 
                printf("---------------\n"); 
                printf("%s\n",description); 
            }
        /* EXEC SQL COMMIT; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )108;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        }                               /* end of infinite loop */
        return; 
}

/* *************************************************************
*       Function to display each part with the responsible agent
*  *************************************************************
*/

void respon()
{
int     my_emp_num, my_part_number;
char    description[100];        /* 1 more octet for the binary 0 */
char    my_pa_name[100];         /* 1 more octet for the binary 0 */
                        
        /* EXEC SQL declare c1 cursor for
                select p.part_number, p.part_name, pa.emp_num, pa.pa_name 
                from part p, responsible r, pa_agent pa 
                where pa.emp_num=r.emp_num and p.part_number=r.part_number; */ 

        
        /* EXEC SQL open c1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0007;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )123;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        /* EXEC SQL WHENEVER NOT FOUND do break; */ 

        
        printf("\tPart ID\tName of Part\t\tEmp Number\tAgent\n");       
        for (;;)
        {
                /* EXEC SQL fetch c1 into :my_part_number, :description, :my_emp_num, :my_pa_name ; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )138;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&my_part_number;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)description;
                sqlstm.sqhstl[1] = (unsigned long )100;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)0;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&my_emp_num;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)0;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)my_pa_name;
                sqlstm.sqhstl[3] = (unsigned long )100;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)0;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqphsv = sqlstm.sqhstv;
                sqlstm.sqphsl = sqlstm.sqhstl;
                sqlstm.sqphss = sqlstm.sqhsts;
                sqlstm.sqpind = sqlstm.sqindv;
                sqlstm.sqpins = sqlstm.sqinds;
                sqlstm.sqparm = sqlstm.sqharm;
                sqlstm.sqparc = sqlstm.sqharc;
                sqlstm.sqpadto = sqlstm.sqadto;
                sqlstm.sqptdso = sqlstm.sqtdso;
                sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
                if (sqlca.sqlcode == 1403) break;
}



                printf("\t%4d\t%s\t\t%4d\t%s\n",my_part_number, description,my_emp_num,my_pa_name);
        }
        
        printf("End of this transaction\n");
        /* EXEC SQL close c1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )169;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

                      
        /* EXEC SQL COMMIT; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )184;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

                /* free locks and keep the connection */
        return;
}

/* ******************************************************************************************
*       Function modifying the status of a part
*  ******************************************************************************************
*/

void modstat()
{
int     num, status;    
        for (;;)
        {
                printf("Enter the part id to change its status (0 to exit)? ");
                scanf("%d",&num);
                if (num == 0) 
                {
                        printf("End of this transaction\n"); 
                        return; 
                } 

/*-------------- beginning of PL/SQL block with local procedure  -----------------*/ 

                /* EXEC SQL EXECUTE
                DECLARE         
                procedure mod_status(no IN integer, stat OUT integer) is
                BEGIN
                        stat := 1;
                        update part2 set status='I' where part_number = no;
                        if SQL%NOTFOUND then stat:=0; 
                        end if;                                                 
                END; 
                BEGIN           -- execution part       
                        mod_status(:num, :status);                      
                        commit;                                 
                END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "declare procedure mod_status ( no IN integer \
, stat OUT integer ) is BEGIN stat := 1 ; update part2 set status = 'I' where \
part_number = no ; if SQL % NOTFOUND then stat := 0 ; end if ; END ; BEGIN mod\
_status ( :num , :status ) ; commit ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )199;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&num;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&status;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)0;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqphsv = sqlstm.sqhstv;
                sqlstm.sqphsl = sqlstm.sqhstl;
                sqlstm.sqphss = sqlstm.sqhsts;
                sqlstm.sqpind = sqlstm.sqindv;
                sqlstm.sqpins = sqlstm.sqinds;
                sqlstm.sqparm = sqlstm.sqharm;
                sqlstm.sqparc = sqlstm.sqharc;
                sqlstm.sqpadto = sqlstm.sqadto;
                sqlstm.sqptdso = sqlstm.sqtdso;
                sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
                if (sqlca.sqlcode == 1403) break;
}



/*-------------- end of PL/SQL block -----------------*/ 

        if (status==0)  
           {
                printf("Record not found \n");  
           }
        else    printf("Modification done\n"); 
        }
        return;
}

/* *******************************************************************************
*       Function to delete a part from the table part2 ; the stocked procedure
*       must be created before this block
*  *******************************************************************************
*/

void deletion()
{
int     num, stat=1;    
        for (;;)
        {
        printf("\nEnter the number of the part in part2 to be deleted (0 to quit)? ");
        scanf("%d",&num);
        if (num == 0) 
        {
                printf("End of this transaction\n"); 
                return; 
        }

        /* EXEC SQL EXECUTE
	declare
	procedure del_part2(no number) is
        begin
	  delete from part2 where part_number = no;
        end;
        
        BEGIN
                del_part2(:num);
                if SQL%NOTFOUND then :stat:=0;
                end if;
                commit;
        END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "declare procedure del_part2 ( no number ) is begin de\
lete from part2 where part_number = no ; end ; BEGIN del_part2 ( :num ) ; if S\
QL % NOTFOUND then :stat := 0 ; end if ; commit ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )222;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&num;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&stat;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
}


        
	if (stat==0)  
        {
         printf("part not found \n");   
        }
        else    printf("Part deleted\n");
        }
        return;
}

/* ************************************************************
*       Function print the menu and choose the transaction
*  ************************************************************
*/

int print_menu()
{
   int choice;                          /* id of menu */
        printf("\n\t Choose a transaction by entering a number \n");
        printf("\t *****************************************\n");
        printf("\t (1) LISPART\n");
        printf("\t (2) RESPON\n");
        printf("\t (3) MODSTAT\n");
        printf("\t (4) DELETION\n");
        printf("\t (5) DISPLAY MENU\n");
        printf("\t (6) QUIT\n");
        printf("Enter your choice ? "); 
        scanf("%d",&choice);            /* read the choice */
        return choice;
}
