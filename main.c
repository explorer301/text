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
struct student stud[N];//����һ��ȫ�ֽṹ�����飬�ͱ����˴��ݽṹ�����飨�鷳��
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
        printf("                       ѧ���ɼ�����ϵͳ\n");
        printf("     -----------------------------------------------------\n");
        printf("                       1---ѧ���ɼ�����\n");
        printf("                       2---ѧ���ɼ�ͳ��\n");
        printf("                       3---ѧ���ɼ�����\n");
        printf("                       4---ѧ���ɼ���ѯ(�ļ�)\n");
        printf("                       5---����д���ļ�\n");
        printf("                       6---���ļ�������\n");
        printf("                       7---ѧ���ɼ��޸�\n");
        printf("                       8---ѧ���ɼ�ɾ��(���������ļ�)\n");
        printf("                       0---�˳�ϵͳ\n");
        printf("     -----------------------------------------------------\n");
        printf("                       ��ѡ��0~8��");
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
        case 0:printf("�˳�ϵͳ!\n");exit(0);
        default:printf("�˵�ѡ�����\n");
        }
        printf("�����������...");
        getch();
    }
    return  0;
}

int cjsr(struct student stu[],int rec)//��������ѧ���ɼ�����
{
    void cjxs(struct student stu[],int rec);
    struct student *p=stu+rec;//p������ָ�����µ�ѧ�����ݣ����ֱ����stu�ﲻ������Ч��
    int ch;
    system("cls");
    do
    {
        printf("                       ��¼��ѧ���ɼ�\n");
        printf("     -----------------------------------------------------\n");
        printf("                       ��%dλѧ�����ݣ�\n",rec+1);
        printf("��ѧ��IDΪ(ѧ��С�ڵ���0ֹͣ����)��");
        scanf("%d",&p->id);
        if(p->id<=0)break;
        rec++;
        printf("\n��ѧ������Ϊ��");
        getchar();
        scanf("%s",p->name);
        printf("\n��ѧ��Ӣ��ɼ�Ϊ��");
        scanf("%f",&p->score[0]);
        printf("\n��ѧ�������ɼ�Ϊ��");
        scanf("%f",&p->score[1]);
        printf("\n��ѧ��C���Գɼ�Ϊ��");
        scanf("%f",&p->score[2]);
        p->score[3]=p->score[0]+p->score[1]+p->score[2];
        printf("\n��ѧ���ܳɼ�Ϊ��%f\n",p->score[3]);
        p++;
    }while(1);
    cjxs(stu,rec);
    return  rec;
}

void cjxs(struct student stu[],int rec)//��ʾ����
{
    struct student *p=stu;
    system("cls");
    printf("��%d����¼��\n",rec);
    printf("ѧ��      ����          Ӣ��        ��ѧ         C����        �ܳɼ�    \n");
    printf("----------------------------------------------------------------------------\n");
    for(p=stu;p<stu+rec;p++)
        printf("%d        %s         %f            %f              %f             %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
    printf("----------------------------------------------------------------------------\n");
        getch();
}

void cipx(struct student stu[],int rec)//������
{
    system("cls");
    int ch;
    printf("                 ------------------------------------------\n");
    printf("                       1---��ID����\n");
    printf("                       2---����������\n");
    printf("                       3---��Ӣ��ɼ�����\n");
    printf("                       4---�������ɼ�����\n");
    printf("                       5---��C���Գɼ�����\n");
    printf("                       6---���ܳɼ�����\n");
    printf("                       0---�˳�����\n");
    printf("                  ------------------------------------------\n");
    printf("��ѡ��0~6��");
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
        case 0:printf("�˳�����\n");return;
        default:printf("�˵�ѡ�����\n");
    }
        getch();
}

void idpx(struct student stu[],int rec)//id����
{
    struct student temp;//������ָ��
    for(int i=0;i<rec-1;i++)//ð����ѭ��
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

void namepx(struct student stu[],int rec)//��������
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

void scorepx(struct student stu[],int rec,int n)//��������
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

void write(struct student stu[],int rec)//ѧ������д���ļ�
{
        system("cls");
        int ch;
        void writefile2(struct student stu[],int rec);
        void writefiletxt(struct student stu[],int rec);
        printf("     -----------------------------------------------------\n");
        printf("                       1---�Զ����Ʒ�ʽд��\n");
        printf("                       2---���ı���ʽд��\n");
        printf("                       0---�����ϼ��˵�\n");
        printf("     -----------------------------------------------------\n");
        printf("                       ��ѡ��0~2��");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:writefile2(stu,rec);break;
            case 2:writefiletxt(stu,rec);break;
            case 0:return;
        }
    getch();
}

void writefile2(struct student stu[],int rec)//��ѧ��������ab��ʽд��
{
    char f1[20];
    system("cls");
    FILE *fp;
    printf("�������ļ���:\n");
    scanf("%s",f1);
    fp=fopen(f1,"ab");
    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
    for(int i=0;i<rec;i++)
    fwrite(&stu[i],sizeof(struct student),1,fp);
    printf("д��ɹ�!\n");
    fclose(fp);
    return;
}

void writefiletxt(struct student stu[],int rec)//��ѧ���������ı���ʽд��
{
    char f1[20];
    system("cls");
    FILE *fp;
    printf("�������ļ���:\n");
    scanf("%s",f1);
    fp=fopen(f1,"a");
    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
    for(int i=0;i<rec;i++)
    fprintf(fp,"%d\n%s\n%f\n%f\n%f\n%f\n",stu[i].id,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3]);
    printf("д��ɹ�!\n");
    fclose(fp);
    return;
}

void readfile(struct student stu[],int rec)//���ļ��ж�������
{
        system("cls");
        void readfile2(struct student stu[],int rec);
        void readfiletxt(struct student stu[],int rec);
        int ch;
        printf("     -----------------------------------------------------\n");
        printf("                       1---�Զ����Ʒ�ʽ����\n");
        printf("                       2---���ı���ʽ����\n");
        printf("                       0---�����ϼ��˵�\n");
        printf("     -----------------------------------------------------\n");
        printf("                       ��ѡ��0~2��");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:readfile2(stu,rec);break;
            case 2:readfiletxt(stu,rec);break;
            case 0:return;
        }
    getch();
}
void readfile2(struct student stu[],int rec)//�����������ļ��е�����
{
    struct student *p=stu;
    int n=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("�������ļ���:\n");
    scanf("%s",f1);
    fp=fopen(f1,"rb");
    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
    rewind(fp);
    while(!feof(fp))
    {
        fread(p,sizeof(struct student),1,fp);
        p++;
        n++;
    }
    printf("��%d����¼��\n",n-1);
    printf("ѧ��      ����          Ӣ��        ��ѧ         C����        �ܳɼ�    \n");
    printf("----------------------------------------------------------------------------\n");
    for(p=stu;p<stu+n-1;p++)
        printf("%d        %s         %f            %f              %f             %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
    printf("----------------------------------------------------------------------------\n");
    getch();
}

void readfiletxt(struct student stu[],int rec)//�����ı��ļ��е�����
{
    struct student *p=stu;
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("�������ļ���:\n");
    scanf("%s",f1);
    fp=fopen(f1,"r");
    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
    rewind(fp);
    while(!feof(fp))
    {
        fscanf(fp,"%d\n%s\n%f\n%f\n%f\n%f\n",&stu[i].id,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        n++;
        i++;
    }
    printf("��%d����¼��\n",i);
    printf("ѧ��      ����          Ӣ��        ��ѧ         C����        �ܳɼ�    \n");
    printf("----------------------------------------------------------------------------\n");
    for(p=stu;p<stu+i;p++)
    printf("%d        %s            %f              %f             %f               %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
    printf("----------------------------------------------------------------------------\n");
    getch();
}

void cjcx(struct student stu[],int rec)//�������ݺ���
{
        system("cls");
        int ch;
        void file2(void);
        void filetxt(void);
        void maxcx(struct student stud[],int rec);
        void mincx(struct student stud[],int rec);
        void idcx(struct student stud[],int x);
        printf("     -----------------------------------------------------\n");
        printf("                       1---�������ļ�\n");
        printf("                       2---�ı��ļ�\n");
        printf("                       0---�����ϼ��˵�\n");
        printf("     -----------------------------------------------------\n");
        printf("                       ��ѡ��0~2��");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:file2();break;//�Ȱ�����ȫ����ȡ����
            case 2:filetxt();break;
            case 0:return;
        }
        getch();

        system("cls");
        printf("                       �����ļ��е�����\n");
        printf("                 ------------------------------------------\n");
        printf("                       1---��ѯ����ܷ�\n");
        printf("                       2---��ѯ����ܷ�\n");
        printf("                       3---��ѧ�Ų�ѯ\n");
        printf("                       0---�˳���ѯ\n");
        printf("                 ------------------------------------------\n");
        int ch1;
        printf("��ѡ��0~3:");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 0:return;
            case 1:maxcx(stud,rec);break;
            case 2:mincx(stud,rec);break;
            case 3:
                {
                system("cls");
                printf("�������Ӧѧ����ѧ��:");
                int x;
                scanf("%d",&x);
                idcx(stud,x);
                }break;
        }
        getch();
}

void file2(void)//ȡ��
{
    struct student stu[N];
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("�������ļ���:\n");
    scanf("%s",f1);
    fp=fopen(f1,"rb");
    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
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

void filetxt(void)//ȡ��
{
    struct student stu[N];
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("�������ļ���:\n");
    scanf("%s",f1);
    fp=fopen(f1,"r");
    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
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

void maxcx(struct student stud[],int rec)//��߷ֲ�ѯ����
{
    int j;
    struct student temp;
    for(j=0;j<rec-1;j++)
        if(stud[j].score[3]>stud[j+1].score[3])
            temp=stud[j];
    if(stud[j+1].score[3]>temp.score[3])
        temp=stud[j+1];
    printf("ѧ��      ����          Ӣ��        ��ѧ         C����        �ܳɼ�    \n");
    printf("----------------------------------------------------------------------------\n");
    printf("%d        %s            %f              %f             %f               %f         \n",temp.id,temp.name,temp.score[0],temp.score[1],temp.score[2],temp.score[3]);
    printf("----------------------------------------------------------------------------\n");
}

void mincx(struct student stud[],int rec)//��ͷֲ�ѯ����
{
    int j;
    struct student temp;
    for(j=0;j<rec-1;j++)
        if(stud[j].score[3]<stud[j+1].score[3])
            temp=stud[j];
    if(stud[j+1].score[3]<temp.score[3])
        temp=stud[j+1];
    printf("ѧ��      ����          Ӣ��        ��ѧ         C����        �ܳɼ�    \n");
    printf("----------------------------------------------------------------------------\n");
    printf("%d        %s            %f              %f             %f               %f         \n",temp.id,temp.name,temp.score[0],temp.score[1],temp.score[2],temp.score[3]);
    printf("----------------------------------------------------------------------------\n");
}

void idcx(struct student stud[],int x)//ѧ�Ų�ѯ
{
    struct student *p;
    for(int i=0;;i++)
        if(x==stud[i].id)
    {
        p=&stud[i];
        printf("ѧ��      ����          Ӣ��        ��ѧ         C����        �ܳɼ�    \n");
        printf("----------------------------------------------------------------------------\n");
        printf("%d        %s            %f              %f             %f               %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
        printf("----------------------------------------------------------------------------\n");
        break;
    }
    getch();
}

void cjxg(struct student stu[],int rec)//�޸�ѧ������
{
        system("cls");
        printf("                          ɾ��ѧ������\n");
        printf("     -----------------------------------------------------\n");
        printf("                       1---�޸Ļ�����������\n");
        printf("                       2---�޸��ļ��ڵ�����\n");
        printf("                       0---�������˵�\n");
        printf("     -----------------------------------------------------\n");
        printf("��ѡ��0~2:");
        int ch,ch1;
        scanf("%d",&ch);
        if(ch==1)
        {
        struct student *p;
        system("cls");
        printf("������Ҫ�޸ĵ�ѧ����Ӧ��id:");
        int ch;
        scanf("%d",&ch);
        for(int i=0;i<rec;i++)
            {
            if(ch==stu[i].id)
            {
                    p=&stu[i];
                    printf("ѧ��      ����          Ӣ��        ��ѧ         C����        �ܳɼ�    \n");
                    printf("----------------------------------------------------------------------------\n");
                    printf("%d        %s            %f              %f             %f               %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
                    printf("----------------------------------------------------------------------------\n");
                    getch();
                    printf("�������µ�ѧ������:\n");
                    printf("��ѧ��IDΪ��");
                    scanf("%d",&p->id);
                    printf("\n��ѧ������Ϊ��");
                    getchar();
                    scanf("%s",p->name);
                    printf("\n��ѧ��Ӣ��ɼ�Ϊ��");
                    scanf("%f",&p->score[0]);
                    printf("\n��ѧ�������ɼ�Ϊ��");
                    scanf("%f",&p->score[1]);
                    printf("\n��ѧ��C���Գɼ�Ϊ��");
                    scanf("%f",&p->score[2]);
                    p->score[3]=p->score[0]+p->score[1]+p->score[2];
                    printf("\n��ѧ���ܳɼ�Ϊ��%f\n",p->score[3]);
                    getch();
                    printf("�޸ĳɹ�!\n");
                    printf("�µ�ѧ������Ϊ:\n");
                    getch();
                    cjxs(stu,rec);
                    return;
                }
                else
                    printf("���޴���!\n");
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
            printf("ѡ�����!\n");
            return;
        }
}

void filexg(void)//�޸��ļ��е�����
{
    int ch;
    void filetxtxg(void);
    void file2xg(void);
    system("cls");
    printf("                          ��ѡ���ļ���ʽ\n");
    printf("     -----------------------------------------------------\n");
    printf("                       1---�������ļ�\n");
    printf("                       2---�ı��ļ�\n");
    printf("                       0---�������˵�\n");
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
        printf("ѡ�����!\n");
    }
    return;
}

void file2xg(void)//�޸Ķ������ļ��е�����
{
    struct student stu[N];
    struct student *p;
    struct student studen;
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("�������ļ���:\n");
    scanf("%s",f1);
    fp=fopen(f1,"rb");
    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
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
    cjxs(stu,i);//���ǻ���һ��
    printf("��������Ҫ�޸ĵ�ѧ�����ݵ�id:");
    int ch;
    scanf("%d",&ch);
    for(int n=0;n<i;n++)
        if(ch==stu[n].id)
        {
                p=&stu[n];
                printf("ѧ��      ����          Ӣ��        ��ѧ         C����        �ܳɼ�    \n");
                printf("----------------------------------------------------------------------------\n");
                printf("%d        %s            %f              %f             %f               %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
                printf("----------------------------------------------------------------------------\n");
                getch();
                printf("�������µ�ѧ������:\n");
                printf("��ѧ��IDΪ��");
                scanf("%d",&p->id);
                printf("\n��ѧ������Ϊ��");
                getchar();
                scanf("%s",p->name);
                printf("\n��ѧ��Ӣ��ɼ�Ϊ��");
                scanf("%f",&p->score[0]);
                printf("\n��ѧ�������ɼ�Ϊ��");
                scanf("%f",&p->score[1]);
                printf("\n��ѧ��C���Գɼ�Ϊ��");
                scanf("%f",&p->score[2]);
                p->score[3]=p->score[0]+p->score[1]+p->score[2];
                printf("\n��ѧ���ܳɼ�Ϊ��%f\n",p->score[3]);
                getch();
                printf("�޸ĳɹ�!\n");
                printf("�ı����µ�ѧ������Ϊ:\n");
                getch();
                cjxs(stu,i);
                fp=fopen(f1,"wb");
                for(int m=0;m<i;m++)
                    fwrite(&stu[m],sizeof(struct student),1,fp);
                fclose(fp);
            break;
        }
}

void filetxtxg(void)//�޸��ı��ļ��е�����
{
    struct student stu[N];
    struct student *p;
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("�������ļ���:\n");
    scanf("%s",f1);
    fp=fopen(f1,"r");
    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
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
    cjxs(stu,i);//���ǻ���һ��
    printf("��������Ҫ�޸ĵ�ѧ�����ݵ�id:");
    int ch;
    scanf("%d",&ch);
    for(int n=0;n<i;n++)
        if(ch==stu[n].id)
        {
                p=&stu[n];
                printf("ѧ��      ����          Ӣ��        ��ѧ         C����        �ܳɼ�    \n");
                printf("----------------------------------------------------------------------------\n");
                printf("%d        %s            %f              %f             %f               %f         \n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->score[3]);
                printf("----------------------------------------------------------------------------\n");
                getch();
                printf("�������µ�ѧ������:\n");
                printf("��ѧ��IDΪ��");
                scanf("%d",&p->id);
                printf("\n��ѧ������Ϊ��");
                getchar();
                scanf("%s",p->name);
                printf("\n��ѧ��Ӣ��ɼ�Ϊ��");
                scanf("%f",&p->score[0]);
                printf("\n��ѧ�������ɼ�Ϊ��");
                scanf("%f",&p->score[1]);
                printf("\n��ѧ��C���Գɼ�Ϊ��");
                scanf("%f",&p->score[2]);
                p->score[3]=p->score[0]+p->score[1]+p->score[2];
                printf("\n��ѧ���ܳɼ�Ϊ��%f\n",p->score[3]);
                getch();
                printf("�޸ĳɹ�!\n");
                printf("�ı����µ�ѧ������Ϊ:\n");
                getch();
                cjxs(stu,i);
                fp=fopen(f1,"w");
                for(int m=0;m<i;m++)
                    fprintf(fp,"%d\n%s\n%f\n%f\n%f\n%f\n",stu[m].id,stu[m].name,stu[m].score[0],stu[m].score[1],stu[m].score[2],stu[m].score[3]);
                fclose(fp);
            break;
        }
}

int cjsc(struct student stu[],int rec)//ɾ��ѧ���������ֶ���
{
        system("cls");
        printf("                          ɾ��ѧ������\n");
        printf("     -----------------------------------------------------\n");
        printf("                       1---ɾ��������������\n");
        printf("                       2---ɾ���ļ��ڵ�����\n");
        printf("                       0---�������˵�\n");
        printf("     -----------------------------------------------------\n");
        printf("��ѡ��0~2:");
        int ch,ch1;
        scanf("%d",&ch);
        if(ch==1)
        {
            system("cls");
            if(rec==0)
                {
                    printf("������û�����ݴ���\n");
                    return;
            }
            cjxs(stu,rec);
            printf("������Ҫɾ����ѧ�����ݵ�id:");
            scanf("%d",&ch1);
            for(int i=0;i<rec;i++)
                {
                if(ch1==stu[i].id)
                    {
                        if(ch1==stu[rec-1].id)
                        {
                            printf("ɾ���ɹ�!\n");
                            return --rec;
                        }
                        else
                        {
                            for(int j=i;j<rec-1;j++)
                            stu[j]=stu[j+1];
                            printf("ɾ���ɹ�!\n");
                            return --rec;
                        }
                    }
                }
            printf("���޴���!\n");
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
        printf("ѡ�����!\n");
        return;
    }
}

void filedelete(void)//��������ȡ���������Ż�ȥ
{
    void file2de(void);
    void filetxtde(void);
        system("cls");
        printf("                       �������ļ����ͣ�\n");
        printf("     -----------------------------------------------------\n");
        printf("                       1---�������ļ�\n");
        printf("                       2---�ı��ļ�\n");
        printf("                       0---�����ϼ��˵�\n");
        printf("     -----------------------------------------------------\n");
        printf("                       ��ѡ��0~2��");
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
    printf("�������ļ���:\n");
    scanf("%s",f1);
    fp=fopen(f1,"rb");
    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
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
    cjxs(stude,i);//���ǻ���һ��
    printf("��������Ҫɾ����ѧ�����ݵ�id:");
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
    printf("��ʱ�ı��е�����Ϊ:\n");
    cjxs(stude,i);
    printf("ɾ���ɹ�!\n");
}

void filetxtde(void)
{
    struct student stu[N];
    int n=0,i=0;
    char f1[20];
    system("cls");
    FILE *fp;
    printf("�������ļ���:\n");
    scanf("%s",f1);
    fp=fopen(f1,"r");
    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
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
    cjxs(stude,i);//���ǻ���һ��
    printf("��������Ҫɾ����ѧ�����ݵ�id:");
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
    printf("��ʱ�ı��е�����Ϊ:\n");
    cjxs(stude,i);
    printf("ɾ���ɹ�!\n");
}
