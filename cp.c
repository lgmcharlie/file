   #include<sys/types.h>                                                                                                                                                             
   #include<sys/stat.h>
   #include <stdlib.h>
   #include<fcntl.h>
   #include<unistd.h>
   #include<stdio.h>
   int main(int argc,char* argv[])
   {
           //打开源文件，获取读打权限，拷贝
          //打开目标文件，如果文件不存在，开启读写创建权限
          //读源文件的数据存储到一个数组中
          //将数组中的内容写到目标文件中
         //判断是否复制完毕
          //关闭文件
          int sourcefd;//源文件的文件描述符
          int targetfd;//  目标文件的文件描述符
         sourcefd=open(argv[1],O_RDONLY);
          targetfd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666);
          if(argc!=3)
          {
                  printf("无法打开文件\n");
                  return -1;
          }
          if(sourcefd<0)//如果源文件的文件描述符小于零，说明文件不存在
          {
                  printf(" 无法获取 %s 的文件状态(stat): 没有那个文件或目录\n",argv[1]);
                  return -2;
          }
          char buf[256];//文件存储缓冲区
         int rescount;//读取数据的长度
          while(1)
          {
                   rescount=read(sourcefd,buf,sizeof(buf));//获得读数据的长度
                  write(targetfd,buf,rescount);   //写数据
                   if(rescount<256)
                           break;
          }
          close(sourcefd);
          close(targetfd);
          return 0;
  }
