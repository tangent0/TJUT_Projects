
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
           char  filnam[15];
};
static const struct sqlcxp sqlfpn =
{
    14,
    "lab4base_pa.pc"
};


static unsigned int sqlctx = 1147971;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4146,1,0,0,
5,0,0,1,0,0,30,67,0,0,0,0,0,1,0,
20,0,0,2,0,0,32,90,0,0,0,0,0,1,0,
35,0,0,0,0,0,27,103,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
66,0,0,4,0,0,29,125,0,0,0,0,0,1,0,
81,0,0,5,147,0,6,132,0,0,3,3,0,1,0,2,97,0,0,1,3,0,0,2,3,0,0,
108,0,0,6,0,0,29,155,0,0,0,0,0,1,0,
123,0,0,7,63,0,3,179,0,0,7,7,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
97,0,0,1,3,0,0,
166,0,0,8,0,0,29,180,0,0,0,0,0,1,0,
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
*		
*		modified by ora00176 in may,2013
*/

#include <stdio.h>
#include <stdlib.h>
 
void sql_error();
void do_connect();
void lispart();
//
void crepart();
void cresupp();
void creprod();
void low_part();
void pot_supp();
void cre_po();
//
int print_menu();

int main()
{ 
	/* EXEC SQL WHENEVER SQLERROR do sql_error("Error at connect"); */ 
 
	
	do_connect();		/* connection to Oracle instance */

/*	Display the program menu
*	and execution of the transaction 
*/
	
	while (1)	/* infinite loop */
	{
	 switch (print_menu())
	 {
	  case 1: lispart();
		  break;
	  case 2: crepart();
		  break;
	  case 3: cresupp();
	  	  break;
	  case 4: creprod();
	  	  break;
	  case 5: low_part();
	  	  break;
	  case 6: pot_supp();
		  break;
	  case 7: cre_po();
		  break;
          case 8: puts("\nBye!"); 
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
}			/* end of main() program */

/* ******************************************************************************************
*	Function to display the original error Oracle message 
*  ******************************************************************************************
*/

void sql_error(char *msg)
{
 	char ora_msg[512];			/* buffer for Oracle error message */
 	int buf_len, msg_len;
 	
  	/* EXEC SQL WHENEVER SQLERROR continue; */ 
	/* Prevent an infinite loop */
  	
  	printf("\n%s\n",msg);			/* print the local program message */
 	buf_len=sizeof(ora_msg);
 	
 	sqlglm(ora_msg,&buf_len, &msg_len);	/* read the Oracle error message */
 	printf("\n%.*s\n",msg_len, ora_msg);	/* print this message */
 	
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
}		/*	fin de sql_error */

/* ******************************************************************************************
*	Function to do a connection to an Oracle user schema
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
*	Function to display the contents of a given part
*  ******************************************************************************************
*/

void lispart()
{
char	description[16];     /* C needs 1 more octet than Oracle for binary 0 
				at the end of a C character type */
int 	my_partid, none=1;
   	for (;;) 		/* infinite loop until user enter a 0 */
	{
   		printf("Number of the part (0 to quit )? ");
		scanf("%d",&my_partid);		

		printf("Part Number : %d\n",my_partid);
		if (my_partid == 0) 
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
		SELECT part_name INTO :description 	/o note: description needs 1 octet more o/
		FROM ora00176.part WHERE part_number = :my_partid;
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
 sqlstm.stmt = "begin SELECT part_name INTO :description FROM ora00176 . par\
t WHERE part_number = :my_partid ; EXCEPTION WHEN NO_DATA_FOUND THEN :none := \
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
 sqlstm.sqhstv[1] = (unsigned char  *)&my_partid;
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


	}				/* end of infinite loop */
	return;	
}


void crepart()
{
	int num;
	char name[16];
	int stock;
	int min;
	int ordered;
	char unit[16];
	int price;
	
	printf("part_number: "); scanf("%d",&num);
	printf("part_name: ");   scanf("%s",&name);	
	printf("qty_in_stock: ");scanf("%d",&stock);	
	printf("qty_minimum: "); scanf("%d",&min);	
	printf("qty_ordered: "); scanf("%d",&ordered);	
	printf("unit: ");        scanf("%s",&unit);	
	printf("unit_price: ");  scanf("%d",&price);	
	
	/* EXEC SQL insert into ora00176.part values(:num,:name,:stock,:min,:ordered,:unit,:price); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into ora00176.part  values (:b0,:b1,:b2,:b3,:b4,:b5,:\
b6)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )123;
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
 sqlstm.sqhstv[1] = (unsigned char  *)name;
 sqlstm.sqhstl[1] = (unsigned long )16;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&stock;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&min;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&ordered;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)unit;
 sqlstm.sqhstl[5] = (unsigned long )16;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&price;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
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


	/* EXEC SQL COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )166;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	
	printf("The creation has been completed!");
	return;
}

void cresupp()
{
	printf("This function has not been completed...");
	return;
}

void creprod()
{
	printf("This function has not been completed...");
	return;
}

void low_part()
{
	printf("This function has not been completed...");
	return;
}

void pot_supp()
{
	printf("This function has not been completed...");
	return;
}

/* *************************************************************
*	Function to display each part with the responsible agent
*  *************************************************************
*/

void cre_po()
{
	printf("This function has not been completed...");
	return;
}

/* ************************************************************
*	Function print the menu and choose the transaction
*  ************************************************************
*/

int print_menu()
{
   int choice;				/* id of menu */
	printf("\n\t Choose a transaction by entering a number \n");
	printf("\t *****************************************\n");
	
	printf("\t (1) LIST PART\n");
	printf("\t (2) CREATE PART\n");
	printf("\t (3) CREATE SUPPLIER\n");
	printf("\t (4) CREATE PRODUCT\n");
	printf("\t (5) LOW PART\n");
	printf("\t (6) POTENTIAL SUPPLIER\n");
	printf("\t (7) CREATE PURCHASE ORDER\n");
	printf("\t (8) QUIT\n");
	
	printf("Enter your choice ? ");	
	scanf("%d",&choice);		/* read the choice */
	return choice;
}
