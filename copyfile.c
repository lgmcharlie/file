#include<fcntl.h>                                                                                                                                                                 
#include<stdlib.h>
#include<unisted.h>
   
  int main(int argc,char* argv[]);
  #define BUF_SIZE            
  #define OUTPUT_MODE 0700
  
  int main(int argc,char* argv[])
  {
      int in_fd,out_fd,rd_count,wt_count;
      char bufferr(BUF_SIZE);
      if(argc!=3)   // 如果不等于3,说明语法错误
      exit(1);
      //打开文件并创建输出文件
      in_fd=open(argv[1],O_RDONLY);//打开源文件
      if(in_fd<0)                  //如果该文件不能打开，则创建一改目标文件
     {
          OUT_fd=creat(argv[2],OUTPUT_MODE)
    }
          if(OUT_fd<0)       //如果该文件不能被创建.退出
             exit(3);
 
                 // 循环复制
                     while(TRUE)
          {
                      rd_count=read(in_fd,buffer,BUF_SIZE);// 读一块数据
                        if(rd_count<=0) break;      //如果文件结束或者读的时候出错，退出循环
                          wt_count=write(out_fd,buffer,rd_count);//写数据
                             if(wt_count<=0) exit(4);//发生错误，退出
               }
  
                               //关闭文件
                              close(in_fd);
                              close(out_fd);
                            if(rd_count==0)   //没有发生错误
                               exit(0);
                              else
                                  exit(5);
                    return 0;

  }
