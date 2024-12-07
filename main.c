#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define N 100
struct student
{
    int id;
    char name[10];
    float score[4];
};
struct student stud[N];//定义一个全局结构体数组，就避免了传递结构体数组（麻烦）
struct student stude[N];
int main()
{
    struct student stu[N];
    int cjsr(struct student stu[],int rec);
    void cjxs(struct student stu[],int rec);
    void cipx(struct student stu[],int rec);
    void write(struct student stu[],int rec);
    void readfile(struct student stu[],int rec);
    void cjcx(struct student stu[],int rec);
    void cjxg(struct student stu[],int rec);
    int cjsc(struct student stu[],int rec);
    int rec=0,ch;
    while(1)
    {
        system("cls");
        printf("                       学生成绩管理系统\n");
        printf("     -----------------------------------------------------\n");
        printf("                       1---学生成绩输入\n");
        printf("                       2---学生成绩统计\n");
        printf("                       3---学生成绩排序\n");
        printf("                       4---学生成绩查询(文件)\n");
        printf("                       5---数据写入文件\n");
        printf("                       6---从文件读数据\n");
        printf("                       7---学生成绩修改\n");
        printf("                       8---学生成绩删除(缓存区或文件)\n");
        printf("                       0---退出系统\n");
        printf("     -----------------------------------------------------\n");
        printf("                       请选择0~8：");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: rec=cjsr(stu,rec);break;
        case 2: cjxs(stu,rec);break;
        case 3: cipx(stu,rec);break;
        case 4:cjcx(stu,rec);break;
        case 5: write(stu,rec);break;
        case 6: readfile(stu,rec);break;
        case 7:cjxg(stu,rec);break;
        case 8:rec=cjsc(stu,rec);break;
        case 0:printf("退出系统!\n");exit(0);
        default:printf("菜单选择错误！\n");
        }
        printf("按任意键继续...");
        getch();
    }
    return  0;
}

int cjsr(struct student stu[],int rec)//键盘输入学生成绩数据
{
    void cjxs(struct student stu[],int rec);
    struct student *p=stu+rec;//p总是能指向最新的学生数据，如果直接用stu达不到这种效果
    int ch;
    system("cls");
    do
    {
        printf("                       请录入学生成绩\n");
        printf("     -----------------------------------------------------\n");
        printf("                       第%d位学生数据：\n",rec+1);
        printf("该学生ID为(学号小于等于0停止输入)：");
        scanf("%d",&p->id);
        if(p->id<=0)break;
        rec++;
        printf("\n该学生姓名为：");
        getchar();
        scanf("%s",p->name);
        printf("\n该学生英语成绩为：");
        scanf("%f",&p->score[0]);
        printf("\n该学生高数成绩为：");
        scanf("%f",&p->score[1]);
        printf("\n该学生C语言成绩为：");
        scanf("%f",&p->score[2]);
        p->score[3]=p->score[0]+p->score[1]+p->score[2];
        printf("\n该学生总成绩为：%f\n",p->score[3]);
        p++;
    }while(1);
    cjxs(stu,rec);
    return  rec;
}

void cjxs(struct student stu[],int rec)//显示函数
{
    struct student *p=stu;
    system("cls");
    printf("共%d条记录：\n",rec);
    printf("学号      姓名          英语        数学         C语言        总成绩    \n");
    printf("----------------------------------------------------------------------------\n");
    for(p=stu;p<stu+rec;p++)
        printf("%d        %s         %f            %f              %f             %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
    printf("----------------------------------------------------------------------------\n");
        getch();
}

void cipx(struct student stu[],int rec)//排序函数
{
    system("cls");
    int ch;
    printf("                 ------------------------------------------\n");
    printf("                       1---按ID排序：\n");
    printf("                       2---按姓名排序：\n");
    printf("                       3---按英语成绩排序：\n");
    printf("                       4---按高数成绩排序：\n");
    printf("                       5---按C语言成绩排序：\n");
    printf("                       6---按总成绩排序：\n");
    printf("                       0---退出排序：\n");
    printf("                  ------------------------------------------\n");
    printf("请选择0~6：");
    scanf("%d",&ch);
    void idpx(struct student stu[],int rec);
    void namepx(struct student stu[],int rec);
    void scorepx(struct student stu[],int rec,int n);
    switch(ch)
    {
        case 1:idpx(stu,rec);break;
        case 2:namepx(stu,rec);break;
        case 3:scorepx(stu,rec,0);break;
        case 4:scorepx(stu,rec,1);break;
        case 5:scorepx(stu,rec,2);break;
        case 6:scorepx(stu,rec,3);break;
        case 0:printf("退出排序！\n");return;
        default:printf("菜单选择错误！\n");
    }
        getch();
}

void idpx(struct student stu[],int rec)//id排序
{
    struct student temp;//不能用指针
    for(int i=0;i<rec-1;i++)//冒泡外循环
        for(int j=0;j<rec-1-i;j++)
    {
        if(stu[j].id>stu[j+1].id)
            {
                temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
            }
    }
    cjxs(stu,rec);
}

void namepx(struct student stu[],int rec)//姓名排序
{
    struct student temp;
    for(int i=0;i<rec-1;i++)
        for(int j=0;j<rec-1-i;j++)
    {
        if(strcmp(stu[j].name,stu[j+1].name)>0)
        {
            temp=stu[j];
            stu[j]=stu[j+1];
            stu[j+1]=temp;
        }
    }
    cjxs(stu,rec);
}

void scorepx(struct student stu[],int rec,int n)//分数排序
{
    struct student temp;
    switch (n)
    {
        case 0:
            {
             for(int i=0;i<rec-1;i++)
                for(int j=0;j<rec-1-i;j++)
            {
                if(stu[j].score[0]>stu[j+1].score[0])
                    {
                        temp=stu[j];
                        stu[j]=stu[j+1];
                        stu[j+1]=temp;
                    }
            }
            cjxs(stu,rec);
            }break;
        case 1:
            {
             for(int i=0;i<rec-1;i++)
                for(int j=0;j<rec-1-i;j++)
            {
                if(stu[j].score[1]>stu[j+1].score[1])
                    {
                        temp=stu[j];
                        stu[j]=stu[j+1];
                        stu[j+1]=temp;
                    }
            }
            cjxs(stu,rec);
            }break;
        case 2:
            {
             for(int i=0;i<rec-1;i++)
                for(int j=0;j<rec-1-i;j++)
            {
                if(stu[j].score[2]>stu[j+1].score[2])
                    {
                        temp=stu[j];
                        stu[j]=stu[j+1];
                        stu[j+1]=temp;
                    }
            }
            cjxs(stu,rec);
            }break;
            case 3:
            {
             for(int i=0;i<rec-1;i++)
                for(int j=0;j<rec-1-i;j++)
            {
                if(stu[j].score[3]>stu[j+1].score[3])
                    {
                        temp=stu[j];
                        stu[j]=stu[j+1];
                        stu[j+1]=temp;
                    }
            }
            cjxs(stu,rec);
            }break;
    }
}

void write(struct student stu[],int rec)//学生数据写入文件
{
        system("cls");
        int ch;
        void writefile2(struct student stu[],int rec);
        void writefiletxt(struct student stu[],int rec);
        printf("     -----------------------------------------------------\n");
        printf("                       1---以二进制方式写入\n");
        printf("                       2---以文本方式写入\n");
        printf("                       0---返回上级菜单\n");
        printf("     -----------------------------------------------------\n");
        printf("                       请选择0~2：");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:writefile2(stu,rec);break;
            case 2:writefiletxt(stu,rec);break;
            case 0:return;
        }
    getch();
}

void writefile2(struct student stu[],int rec)//将学生数据以ab方式写入
{
    char f1[20];
    system("cls");
    FILE *fp;
    printf("请输入文件名:\n");
    scanf("%s",f1);
    fp=fopen(f1,"ab");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    for(int i=0;i<rec;i++)
    fwrite(&stu[i],sizeof(struct student),1,fp);
    printf("写入成功!\n");
    fclose(fp);
    return;
}

void writefiletxt(struct student stu[],int rec)//将学生数据以文本方式写入
{
    char f1[20];
    system("cls");
    FILE *fp;
    printf("请输入文件名:\n");
    scanf("%s",f1);
    fp=fopen(f1,"a");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    for(int i=0;i<rec;i++)
    fprintf(fp,"%d\n%s\n%f\n%f\n%f\n%f\n",stu[i].id,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3]);
    printf("写入成功!\n");
    fclose(fp);
    return;
}

void readfile(struct student stu[],int rec)//从文件中读出数据
{
        system("cls");
        void readfile2(struct student stu[],int rec);
        void readfiletxt(struct student stu[],int rec);
        int ch;
        printf("     -----------------------------------------------------\n");
        printf("                       1---以二进制方式读出\n");
        printf("                       2---以文本方式读出\n");
        printf("                       0---返回上级菜单\n");
        printf("     -----------------------------------------------------\n");
        printf("                       请选择0~2：");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:readfile2(stu,rec);break;
            case 2:readfiletxt(stu,rec);break;
            case 0:return;
        }
    getch();
}
void readfile2(struct student stu[],int rec)//读出二进制文件中的数据
{
    struct student *p=stu;
    int n=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("请输入文件名:\n");
    scanf("%s",f1);
    fp=fopen(f1,"rb");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    rewind(fp);
    while(!feof(fp))
    {
        fread(p,sizeof(struct student),1,fp);
        p++;
        n++;
    }
    printf("共%d条记录：\n",n-1);
    printf("学号      姓名          英语        数学         C语言        总成绩    \n");
    printf("----------------------------------------------------------------------------\n");
    for(p=stu;p<stu+n-1;p++)
        printf("%d        %s         %f            %f              %f             %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
    printf("----------------------------------------------------------------------------\n");
    getch();
}

void readfiletxt(struct student stu[],int rec)//读出文本文件中的数据
{
    struct student *p=stu;
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("请输入文件名:\n");
    scanf("%s",f1);
    fp=fopen(f1,"r");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    rewind(fp);
    while(!feof(fp))
    {
        fscanf(fp,"%d\n%s\n%f\n%f\n%f\n%f\n",&stu[i].id,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        n++;
        i++;
    }
    printf("共%d条记录：\n",i);
    printf("学号      姓名          英语        数学         C语言        总成绩    \n");
    printf("----------------------------------------------------------------------------\n");
    for(p=stu;p<stu+i;p++)
    printf("%d        %s            %f              %f             %f               %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
    printf("----------------------------------------------------------------------------\n");
    getch();
}

void cjcx(struct student stu[],int rec)//查找数据函数
{
        system("cls");
        int ch;
        void file2(void);
        void filetxt(void);
        void maxcx(struct student stud[],int rec);
        void mincx(struct student stud[],int rec);
        void idcx(struct student stud[],int x);
        printf("     -----------------------------------------------------\n");
        printf("                       1---二进制文件\n");
        printf("                       2---文本文件\n");
        printf("                       0---返回上级菜单\n");
        printf("     -----------------------------------------------------\n");
        printf("                       请选择0~2：");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:file2();break;//先把数据全部提取出来
            case 2:filetxt();break;
            case 0:return;
        }
        getch();

        system("cls");
        printf("                       查找文件中的数据\n");
        printf("                 ------------------------------------------\n");
        printf("                       1---查询最高总分\n");
        printf("                       2---查询最低总分\n");
        printf("                       3---按学号查询\n");
        printf("                       0---退出查询\n");
        printf("                 ------------------------------------------\n");
        int ch1;
        printf("请选择0~3:");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 0:return;
            case 1:maxcx(stud,rec);break;
            case 2:mincx(stud,rec);break;
            case 3:
                {
                system("cls");
                printf("请输入对应学生的学号:");
                int x;
                scanf("%d",&x);
                idcx(stud,x);
                }break;
        }
        getch();
}

void file2(void)//取出
{
    struct student stu[N];
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("请输入文件名:\n");
    scanf("%s",f1);
    fp=fopen(f1,"rb");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    rewind(fp);
    while(!feof(fp))
    {
        fread(&stu[i],sizeof(struct student),1,fp);
        stud[i]=stu[i];
        i++;
    }
    fclose(fp);
}

void filetxt(void)//取出
{
    struct student stu[N];
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("请输入文件名:\n");
    scanf("%s",f1);
    fp=fopen(f1,"r");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    rewind(fp);
    while(!feof(fp))
    {
        fscanf(fp,"%d\n%s\n%f\n%f\n%f\n%f\n",&stu[i].id,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        n++;
        stud[i]=stu[i];
        i++;
    }
    fclose(fp);
}

void maxcx(struct student stud[],int rec)//最高分查询函数
{
    int j;
    struct student temp;
    for(j=0;j<rec-1;j++)
        if(stud[j].score[3]>stud[j+1].score[3])
            temp=stud[j];
    if(stud[j+1].score[3]>temp.score[3])
        temp=stud[j+1];
    printf("学号      姓名          英语        数学         C语言        总成绩    \n");
    printf("----------------------------------------------------------------------------\n");
    printf("%d        %s            %f              %f             %f               %f         \n",temp.id,temp.name,temp.score[0],temp.score[1],temp.score[2],temp.score[3]);
    printf("----------------------------------------------------------------------------\n");
}

void mincx(struct student stud[],int rec)//最低分查询函数
{
    int j;
    struct student temp;
    for(j=0;j<rec-1;j++)
        if(stud[j].score[3]<stud[j+1].score[3])
            temp=stud[j];
    if(stud[j+1].score[3]<temp.score[3])
        temp=stud[j+1];
    printf("学号      姓名          英语        数学         C语言        总成绩    \n");
    printf("----------------------------------------------------------------------------\n");
    printf("%d        %s            %f              %f             %f               %f         \n",temp.id,temp.name,temp.score[0],temp.score[1],temp.score[2],temp.score[3]);
    printf("----------------------------------------------------------------------------\n");
}

void idcx(struct student stud[],int x)//学号查询
{
    struct student *p;
    for(int i=0;;i++)
        if(x==stud[i].id)
    {
        p=&stud[i];
        printf("学号      姓名          英语        数学         C语言        总成绩    \n");
        printf("----------------------------------------------------------------------------\n");
        printf("%d        %s            %f              %f             %f               %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
        printf("----------------------------------------------------------------------------\n");
        break;
    }
    getch();
}

void cjxg(struct student stu[],int rec)//修改学生数据
{
        system("cls");
        printf("                          删除学生数据\n");
        printf("     -----------------------------------------------------\n");
        printf("                       1---修改缓存区的数据\n");
        printf("                       2---修改文件内的数据\n");
        printf("                       0---返回主菜单\n");
        printf("     -----------------------------------------------------\n");
        printf("请选择0~2:");
        int ch,ch1;
        scanf("%d",&ch);
        if(ch==1)
        {
        struct student *p;
        system("cls");
        printf("请输入要修改的学生对应的id:");
        int ch;
        scanf("%d",&ch);
        for(int i=0;i<rec;i++)
            {
            if(ch==stu[i].id)
            {
                    p=&stu[i];
                    printf("学号      姓名          英语        数学         C语言        总成绩    \n");
                    printf("----------------------------------------------------------------------------\n");
                    printf("%d        %s            %f              %f             %f               %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
                    printf("----------------------------------------------------------------------------\n");
                    getch();
                    printf("请输入新的学生数据:\n");
                    printf("该学生ID为：");
                    scanf("%d",&p->id);
                    printf("\n该学生姓名为：");
                    getchar();
                    scanf("%s",p->name);
                    printf("\n该学生英语成绩为：");
                    scanf("%f",&p->score[0]);
                    printf("\n该学生高数成绩为：");
                    scanf("%f",&p->score[1]);
                    printf("\n该学生C语言成绩为：");
                    scanf("%f",&p->score[2]);
                    p->score[3]=p->score[0]+p->score[1]+p->score[2];
                    printf("\n该学生总成绩为：%f\n",p->score[3]);
                    getch();
                    printf("修改成功!\n");
                    printf("新的学生数据为:\n");
                    getch();
                    cjxs(stu,rec);
                    return;
                }
                else
                    printf("查无此人!\n");
                    }
                getch();
        }
       else if(ch==2)
            {
                filexg();
            }
       else  if(ch==0)
            return ;
       else
        {
            printf("选择错误!\n");
            return;
        }
}

void filexg(void)//修改文件中的数据
{
    int ch;
    void filetxtxg(void);
    void file2xg(void);
    system("cls");
    printf("                          请选择文件格式\n");
    printf("     -----------------------------------------------------\n");
    printf("                       1---二进制文件\n");
    printf("                       2---文本文件\n");
    printf("                       0---返回主菜单\n");
    printf("     -----------------------------------------------------\n");
    scanf("%d",&ch);
    if(ch==1)
         file2xg();
    else if(ch==2)
        filetxtxg();
    else if(ch==0)
        return;
    else
    {
        printf("选择错误!\n");
    }
    return;
}

void file2xg(void)//修改二进制文件中的数据
{
    struct student stu[N];
    struct student *p;
    struct student studen;
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("请输入文件名:\n");
    scanf("%s",f1);
    fp=fopen(f1,"rb");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);return;
    }
    rewind(fp);
    while(!feof(fp))
    {
        fread(&stu[i],sizeof(struct student),1,fp);
        i++;
    }
    i--;
    fclose(fp);
    system("cls");
    cjxs(stu,i);//总是会多读一次
    printf("请输入想要修改的学生数据的id:");
    int ch;
    scanf("%d",&ch);
    for(int n=0;n<i;n++)
        if(ch==stu[n].id)
        {
                p=&stu[n];
                printf("学号      姓名          英语        数学         C语言        总成绩    \n");
                printf("----------------------------------------------------------------------------\n");
                printf("%d        %s            %f              %f             %f               %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
                printf("----------------------------------------------------------------------------\n");
                getch();
                printf("请输入新的学生数据:\n");
                printf("该学生ID为：");
                scanf("%d",&p->id);
                printf("\n该学生姓名为：");
                getchar();
                scanf("%s",p->name);
                printf("\n该学生英语成绩为：");
                scanf("%f",&p->score[0]);
                printf("\n该学生高数成绩为：");
                scanf("%f",&p->score[1]);
                printf("\n该学生C语言成绩为：");
                scanf("%f",&p->score[2]);
                p->score[3]=p->score[0]+p->score[1]+p->score[2];
                printf("\n该学生总成绩为：%f\n",p->score[3]);
                getch();
                printf("修改成功!\n");
                printf("文本内新的学生数据为:\n");
                getch();
                cjxs(stu,i);
                fp=fopen(f1,"wb");
                for(int m=0;m<i;m++)
                    fwrite(&stu[m],sizeof(struct student),1,fp);
                fclose(fp);
            break;
        }
}

void filetxtxg(void)//修改文本文件中的数据
{
    struct student stu[N];
    struct student *p;
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("请输入文件名:\n");
    scanf("%s",f1);
    fp=fopen(f1,"r");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);return;
    }
    rewind(fp);
    while(!feof(fp))
    {
         fscanf(fp,"%d\n%s\n%f\n%f\n%f\n%f\n",&stu[i].id,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
            i++;
    }
    fclose(fp);
    system("cls");
    cjxs(stu,i);//总是会多读一次
    printf("请输入想要修改的学生数据的id:");
    int ch;
    scanf("%d",&ch);
    for(int n=0;n<i;n++)
        if(ch==stu[n].id)
        {
                p=&stu[n];
                printf("学号      姓名          英语        数学         C语言        总成绩    \n");
                printf("----------------------------------------------------------------------------\n");
                printf("%d        %s            %f              %f             %f               %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
                printf("----------------------------------------------------------------------------\n");
                getch();
                printf("请输入新的学生数据:\n");
                printf("该学生ID为：");
                scanf("%d",&p->id);
                printf("\n该学生姓名为：");
                getchar();
                scanf("%s",p->name);
                printf("\n该学生英语成绩为：");
                scanf("%f",&p->score[0]);
                printf("\n该学生高数成绩为：");
                scanf("%f",&p->score[1]);
                printf("\n该学生C语言成绩为：");
                scanf("%f",&p->score[2]);
                p->score[3]=p->score[0]+p->score[1]+p->score[2];
                printf("\n该学生总成绩为：%f\n",p->score[3]);
                getch();
                printf("修改成功!\n");
                printf("文本内新的学生数据为:\n");
                getch();
                cjxs(stu,i);
                fp=fopen(f1,"w");
                for(int m=0;m<i;m++)
                    fprintf(fp,"%d\n%s\n%f\n%f\n%f\n%f\n",stu[m].id,stu[m].name,stu[m].score[0],stu[m].score[1],stu[m].score[2],stu[m].score[3]);
                fclose(fp);
            break;
        }
}

int cjsc(struct student stu[],int rec)//删除学生数据两种都有
{
        system("cls");
        printf("                          删除学生数据\n");
        printf("     -----------------------------------------------------\n");
        printf("                       1---删除缓存区的数据\n");
        printf("                       2---删除文件内的数据\n");
        printf("                       0---返回主菜单\n");
        printf("     -----------------------------------------------------\n");
        printf("请选择0~2:");
        int ch,ch1;
        scanf("%d",&ch);
        if(ch==1)
        {
            system("cls");
            if(rec==0)
                {
                    printf("缓存区没有数据存在\n");
                    return;
            }
            cjxs(stu,rec);
            printf("请输入要删除的学生数据的id:");
            scanf("%d",&ch1);
            for(int i=0;i<rec;i++)
                {
                if(ch1==stu[i].id)
                    {
                        if(ch1==stu[rec-1].id)
                        {
                            printf("删除成功!\n");
                            return --rec;
                        }
                        else
                        {
                            for(int j=i;j<rec-1;j++)
                            stu[j]=stu[j+1];
                            printf("删除成功!\n");
                            return --rec;
                        }
                    }
                }
            printf("查无此人!\n");
        }
       else if(ch==2)
        {
            filedelete();
            getch();
        }
       else if(ch==0)
        {
            return;
        }
        else
    {
        printf("选择错误!\n");
        return;
    }
}

void filedelete(void)//将数据提取出来处理后放回去
{
    void file2de(void);
    void filetxtde(void);
        system("cls");
        printf("                       请输入文件类型：\n");
        printf("     -----------------------------------------------------\n");
        printf("                       1---二进制文件\n");
        printf("                       2---文本文件\n");
        printf("                       0---返回上级菜单\n");
        printf("     -----------------------------------------------------\n");
        printf("                       请选择0~2：");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:file2de();break;
            case 2:filetxtde();break;
            case 0:return;
        }
        getch();
}
void file2de(void)
{
    struct student stu[N];
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("请输入文件名:\n");
    scanf("%s",f1);
    fp=fopen(f1,"rb");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);return;
    }
    rewind(fp);
    while(!feof(fp))
    {
        fread(&stu[i],sizeof(struct student),1,fp);
        stude[i]=stu[i];
        i++;
    }
    i--;
    fclose(fp);
    system("cls");
    cjxs(stude,i);//总是会多读一次
    printf("请输入想要删除的学生数据的id:");
    int ch;
    scanf("%d",&ch);
    for(int n=0;n<i;n++)
        if(ch==stude[n].id)
    {
        if(ch==stude[i-1].id)
            i--;
        else
            {
                for(int m=n;m<i-1;m++)
                stude[m]=stude[m+1];
                i--;
            }
    }
    fp=fopen(f1,"wb");
    for(int m=0;m<i;m++)
        fwrite(&stude[m],sizeof(struct student),1,fp);
    fclose(fp);
    printf("此时文本中的数据为:\n");
    cjxs(stude,i);
    printf("删除成功!\n");
}

void filetxtde(void)
{
    struct student stu[N];
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("请输入文件名:\n");
    scanf("%s",f1);
    fp=fopen(f1,"r");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);return;
    }
    rewind(fp);
    while(!feof(fp))
    {
        fscanf(fp,"%d\n%s\n%f\n%f\n%f\n%f\n",&stu[i].id,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        stude[i]=stu[i];
        i++;
    }
    fclose(fp);
    system("cls");
    cjxs(stude,i);//总是会多读一次
    printf("请输入想要删除的学生数据的id:");
    int ch;
    scanf("%d",&ch);
    for(int n=0;n<i;n++)
        if(ch==stude[n].id)
    {
        if(ch==stude[i-1].id)
            i--;
        else
            {
                for(int m=n;m<i-1;m++)
                stude[m]=stude[m+1];
                i--;
            }
    }
    fp=fopen(f1,"w");
    for(int m=0;m<i;m++)
         fprintf(fp,"%d\n%s\n%f\n%f\n%f\n%f\n",stude[m].id,stude[m].name,stude[m].score[0],stude[m].score[1],stude[m].score[2],stude[m].score[3]);
    fclose(fp);
    printf("此时文本中的数据为:\n");
    cjxs(stude,i);
    printf("删除成功!\n");
}
