#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct chunk
{
	char data;
	int size;
	struct chunk *chunknext;
//	mem *chunk_start_add;
};
typedef struct chunk PCHUNK;
struct pool
{
	int total_size;
	PCHUNK *head;
	struct pool *poolnext;
	int available;
	char *start_add;
};
typedef struct pool P_POOL;
//  P_POOL *first;
P_POOL* Allocate_MemPool(int npool,int poolsize,P_POOL* first,char *);

enum retu {Confignotfound=-1,failure=0,success};
int main(int argc,char *argv[])
{
	P_POOL *first;
	int i,npool=5,poolsize=100,nlog,logsize;
	
	int ret=0;
	char *info;
	if(argc==3)
		first=Allocate_MemPool(npool,poolsize,first,info);
	else 
		ret=Get_Info(&npool,&poolsize,"NPOOL","POOLSIZE");

//	if(ret==-1)
	 ret=Get_Info(&nlog,&logsize,"NLOG","LOGSIZE");

		printf("config file not found");

	for(i=0;i<12;i++)
	{
		
	Manage_LogFile("sa",5,8);
	}
}
int Get_Info(int *number,int *size,char *str_given,char *str_given1)
{
	int num,ret;
	char str[20];
	FILE *fp;
	fp=fopen("config.txt","r");
	if(fp==NULL)
		return -1;
	while((fscanf(fp,"%s %d",&str,&num))!=EOF)
	{
		ret=compare_str(str,str_given);
		if(ret==1)
			*number=num;
		ret=compare_str(str,str_given1);
		if(ret==1)
			*size=num;
	}
	printf("%d   %d",*size,*number);
	
	return 1;	
}
int compare_str(char* str1,char* str2)
{
        int i=0;
        while((*(str1+i)!='\0') && (*(str2+i)!='\0'))
        {
                if((*(str1+i))==(*(str2+i)))
                {
                        i++;
                        continue;
                }
                else
                        return 0;
        }
        if(((*(str1+i))=='\0')&&((*(str2+i))=='\0'))
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int Manage_LogFile(char *str,int nlog,int logsize)
{
	static int var=1,var2=1,filesize=0;
	static char prev_name[30];
	char name[20];
	int i=1;
	FILE *fp;
	if(var == 1)
	{
		printf("\n\n%d\n\n",strlen(str));	
		snprintf(name,20,"%s%d","log",i);
		var++;
		fp=fopen(name,"w");
	}

	if((filesize+strlen(str)<=logsize)&&(var2<nlog))
	{
	//if(compare_str(Prev_name,name)==1)
	//{
	//	printf("\nin %d,fle size %d\n",strlen(str),filesize);	
		printf("\nin filei %d\n",var2);
		fp=fopen(name,"a");
		filesize=filesize+strlen(str);
		fputs(str,fp);
		//printf("\nin %d,fle size %d\n",strlen(str),filesize);	
	}
	else
	{
	
		printf("\nin file %d\n",var2);
		filesize=0;
		//printf("\nin %d,fle size %d\n",strlen(str),filesize);
		//printf("\nsecond%d\n",strlen(str));	
		//printf("\nin different file\n");
		i=var2%nlog;
		snprintf(name,20,"%s%d","log",i+1);
//		filesize=0;
		filesize=filesize+strlen(str);
		fp=fopen(name,"w");
		printf("\nin %d,fle size %d\n",strlen(str),filesize);
		fputs(str,fp);
		var2++;
	}
}
		

	







        
      







  
    



P_POOL* Allocate_MemPool(int npool,int poolsize,P_POOL* first,char *info)
{
	int i=0;
//	mem *p1=(struct ele*)malloc(sizeof(struct pool));
	
	while(i<=npool)
	{
		P_POOL *temp=(struct pool*)malloc(sizeof(struct pool));
		info=(char*)malloc(sizeof(char)*poolsize);
		temp->start_add=info;
		i++;
	}
	//	for(i=0;i<20;i++)
			//*(p1->info)+i='a';		

//		P_POOL *temp1=(struct pool*)malloc(sizeof(struct pool));
               	// (p1+1).info=(char*)malloc(sizeof(char)*poolsize);
               	// temp1->start_add=(p1+1);



//	}
printf("%d",sizeof(info));
printf("%d",sizeof(info+2));
printf("%d",sizeof(info+3));
printf("%d",sizeof(info+4));
//printf("%d",sizeof(info+i));

//printf("%u\n",info);
//printf("%u\n\n",temp->start_add);		
//printf("%u\n\n",&p1);
//return temp;
}
		
		

		













