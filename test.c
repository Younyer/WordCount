#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<io.h> 

int getChar(FILE *fp);
int getWord(FILE *fp);
int getLine(FILE *fp);
int getnull_line(FILE *fp);
int getcomplex_data(FILE *fp,int &annotion_line,int &code_line);
int getother_line(FILE *fp);
int handle_file();

int main(int argc,char*argv[]){
	FILE *fp;
	int number;
	char string;

    if(argc==3){
    	
    	//读取文件的内�?		fp = fopen(argv[2],"r");
		
		//打开失败 
		if(fp == NULL){
			printf("错误：无法打开%s\n",argv[2]);
			exit(1);
		} 
			//对参数进行匹�?
		    if(!strcmp(argv[1],"-c")){//统计字符�?
		        number = getChar(fp);
		     	printf("字符数为%d\n",number);
		    }
		
		    else if(!strcmp(argv[1],"-w")){//统计单词�?
			    number = getWord(fp);
			    printf("单词数为%d\n",number); 
		   }
		
		   
			else if(!strcmp(argv[1],"-s")){
			     handle_file();
			}
	}
	
	else {
		printf("错误：参数输入错误，请重新输入\n");
	}
	
} 

//统计字符�?
int getChar(FILE *fp){
	char ch;
	int number=0;
	while((ch=fgetc(fp))!=EOF){//当函数fgetc返回的ASCII值不�?EOF，表示还可以继续�?
		if((ch!='\n')&&(ch!=' ')&&(ch!='\t')){
			number++;
		}
	}
	rewind(fp);
	return number;
}

//统计单词�?
int getWord(FILE *fp){
	int flag=0;
	int number=0;
	char ch;
	while(!feof(fp))
    {
        ch = fgetc(fp);
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            flag = 0;
        else if(flag == 0 && (ch != '-' && ch != '/'&& ch != '\'')) //如果进入这个循环，代表不符合上面的循环，即返回的不是字母或者数�?
        {
            number++;
            flag = 1;
        }
    }
    rewind(fp);
    return number;
}



//处理目录下符合条件的文件
int handle_file(){   
    struct _finddata_t fileinfo;    //文件存储信息结构�?
    long file_handle;   //保存的文件句�?    file_handle = _findfirst("*.txt",&fileinfo);    //查找当前目录下的txt文件
    FILE *fp;
    int a,b;
    if(file_handle==-1)
        printf( "当前目录下没有txt文件\n");
    else 
        do{//先找第一个再找下一�?
            fp=fopen(fileinfo.name,"r");
            printf("找到文件%s\n",fileinfo.name);
            printf("字符数为%d\n",getChar(fp));
            printf("词数�?d\n",getWord(fp));
          
        }while(_findnext(file_handle,&fileinfo)==0);//找到下一�?
        _findclose(file_handle);    //关闭文件链接 
}





