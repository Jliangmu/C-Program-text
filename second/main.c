#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct personnelArchiveInfo{
    char num[15];
    char name[10];
    char sex[5];
    int age;
    char job[10];
    char post[10];
    char politic[10];
    char edu_level[10];
    char period[10];
    char start_time[10];
}PAInfo;
struct link{
    PAInfo data;
    struct link *next;
};

/*下面是主函数中的各个函数*/
void password();//欢迎语句，输入密码。
struct link *selectMe(int i,struct link *head,int *padd );//循环调用函数
void hello();//开始界面

/*下面是菜单内的八个函数*/
struct link *Inputdata(struct link *head,int *padd );//数据输入模块
struct link *ReadandInput(struct link *head,int *padd );//数据添加模块
struct link *DeleteData(struct link *head,int *padd );//数据删除模块
void InquiryData(struct link *head);//数据查询模块
struct link *ReviseData(struct link *head);//数据修改模块
void DisplayNode(struct link *head,int *padd);//显示文件中的数据
struct link *SelectSort(struct link *head);//数据排序模块
void CountData(struct link *head);//统计各类总数

struct link *AppendNode(struct link *head);//添加一条数据
void DisplyNode(struct link *head);//打印链表各个节点的数据
void DeleteMemory(struct link *head);//释放内存
void WritetoFile(struct link *head,int i);//将链表写入文件
void PrintScore(struct link *head);//打印数据

int main()
{
    int add;
    int se;
    int a;
    int *padd = &add;
    struct link *head = NULL;
    password();
    for(;;){
    hello();
    printf("请输入序号\n");
    a = scanf("%d",&se);
    while(getchar()!='\n');
    while(a!=1){
    printf("请输入正确的序号！\n");
    a = scanf("%d",&se);
    }
    head = selectMe(se,head,padd);
    system("pause");
    system("cls");
    }
    return 0;
}

void password(){//欢迎语句，输入密码。
    printf("Hello!\n");
    printf("welcome to use the personal management system!\n");
    char password[11] = {"jiangkaida"};
    char s[11];
    int flag = 0;
    int n = 3;
    int m;
    do{
        printf("please input your password:\n");
        for(m = 0;m < 10;m++){
            s[m] = getch();
            putchar('*');
        }
        s[m] = '\0';
        printf("\n");
        if((!strcmp(s,password))){
            printf("land successfully!\n");
            flag = 1;
            break;

        }
        else{
            printf("error!please input again!\n");
            n--;
        }
    }while(n>0);
    if(!flag){
        printf("Input error more than three times!");
        exit(0);
    }
}

void hello(){//开始界面
    printf("* * * * * * * * * * * * * * * * * * * \n");
    printf("*      欢迎使用人事管理系统！       * \n");
    printf("*     请输入功能序号进行使用！      * \n");
    printf("*\t1.新建员工信息              * \n");
    printf("*\t2.添加员工信息              * \n");
    printf("*\t3.删除员工信息              * \n");
    printf("*\t4.查询员工信息              * \n");
    printf("*\t5.修改员工信息              * \n");
    printf("*\t6.显示员工信息              * \n");
    printf("*\t7.对信息进行排序            * \n");
    printf("*\t8.统计员工信息              * \n");
    printf("*\t9.退出管理系统              * \n");
    printf("* * * * * * * * * * * * * * * * * * * \n");
}

struct link *selectMe(int i,struct link *head,int *padd){//循环调用函数
    if(i == 1){
        head = Inputdata(head,padd);
    }
    else if(i == 2){
        head = ReadandInput(head,padd);
    }
    else if(i == 3){
        head = DeleteData(head,padd);
    }
    else if(i == 4){
        InquiryData(head);
    }
    else if(i == 5){
        head = ReviseData(head);
    }
    else if(i == 6){
        DisplayNode(head,padd);
    }
    else if(i == 7){
        head = SelectSort(head);
    }
    else if(i == 8){
         CountData(head);
    }
    else if(i == 9){
        printf("谢谢您的使用！\n");
        exit(0);
    }
    else{
        printf("请输入正确的选项！\n");
    }
    return head;
}

struct link *Inputdata(struct link *head,int *padd){//数据输入模块
    char c;
    char a[20];
    int i = 0;
    *padd = 0;
    int x;
    printf("您想要新建一个员工数据吗(Y/N)?");
    scanf(" %c",&c);
    while(c == 'Y' || c == 'y'){
        head = AppendNode(head);
        printf("您想要再新建一个员工数据吗(Y/N)?");
            scanf(" %c",&c);
            i++;
            *padd = *padd + 1;
    }
    printf("您成功新建了 %d 个员工数据,正准备将员工数据写入人事档案文件...\n",i);
    printf("是否需要显示员工数据的详细信息(Y/N)?\n");
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    DisplyNode(head);
    c = 'n';
    }
    WritetoFile(head,i);
    printf("已成功将员工数据写入文件！\n");
    return head;
}

struct link *AppendNode(struct link *head){
    struct link *p = NULL, *pr = head;
    PAInfo data;
    p = (struct link *)malloc(sizeof(struct link));
    if(p == NULL){
        printf("内存不足！");
        exit(0);
    }
    if(head ==NULL){
        head = p;
    }
    else{
        while(pr->next!=NULL){
            pr = pr ->next;
        }
        pr->next = p;
    }
    printf("请输入员工的详细信息\n");
    printf("输入编号：");
    scanf("%s",data.num);
    printf("输入姓名：");
    scanf("%s",data.name);
    printf("输入性别：");
    scanf("%s",data.sex);
    printf("输入年龄：");
    scanf("%d",&data.age);
    printf("输入职务：");
    scanf("%s",data.job);
    printf("输入职称：");
    scanf("%s",data.post);
    printf("输入政治面貌：");
    scanf("%s",data.politic);
    printf("输入最高学历：");
    scanf("%s",data.edu_level);
    printf("输入任职时间：");
    scanf("%s",data.period);
    printf("输入来院时间：");
    scanf("%s",data.start_time);
    p->data = data;
    p->next = NULL;
    return head;
}

void DisplyNode(struct link *head){
    struct link *p = head;
    int j = 1;
    while(p != NULL){
        printf("--------第 %d 个员工信息--------\n",j);
        printf("\t姓名：%s            \n",p->data.name);
        printf("\t编号：%s            \n",p->data.num);
        printf("\t性别：%s            \n",p->data.sex);
        printf("\t年龄：%d            \n",p->data.age);
        printf("\t职务：%s            \n",p->data.job);
        printf("\t职称：%s            \n",p->data.post);
        printf("\t政治面貌：%s\n",p->data.politic);
        printf("\t最高学历：%s\n",p->data.edu_level);
        printf("\t任职时间：%s\n",p->data.period);
        printf("\t来院时间：%s\n",p->data.start_time);
        printf("--------------------------------\n");
        p = p->next;
        j++;
    }
}

void WritetoFile(struct link *head,int n){
    struct link *p = head;
    FILE *fp;
    if((fp = fopen("student.txt","w")) == NULL){
        printf("文档无法创建！");
        exit(0);
    }
    while(p != NULL){
        fwrite(p,sizeof(PAInfo),n,fp);
        p = p->next;
    }
    fclose(fp);
}

struct link *ReadandInput(struct link *head,int *padd){//数据添加模块
    char c;
    int nexti = 0;
    printf("您想要向档案文件中追加一个员工信息吗(Y/N)?");
    scanf(" %c",&c);
    while(c == 'Y' || c == 'y'){
        head = AppendNode(head);
        printf("您想要向档案文件中再追加一个员工信息吗(Y/N)?");
            scanf(" %c",&c);
            nexti++;
    }
    printf("您成功追加了 %d 个员工数据,正准备将员工数据写入人事档案文件...\n",nexti);
    printf("是否需要显示追加后的员工数据的详细信息(Y/N)?\n");
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    DisplyNode(head);
    c = 'n';
    }
    *padd = *padd + nexti;
    WritetoFile(head,*padd);
    printf("已成功将员工数据写入文件！\n");
    return head;
}

struct link *DeleteData(struct link *head,int *padd){
    char node[15];
    char c;
    struct link *p =head,*pr = head;
    printf("请输入要删除人员的编号：\n");
    scanf("%s",node);
    if(head == NULL){
        printf("没有员工数据！\n");
        return(head);
    }
    while (strcmp(node,p->data.num)!=0 && p->next != NULL){
        pr = p;
        p = p->next;
    }
    if(strcmp(node,p->data.num) == 0){
        if(p == head){
            head = p->next;
        }
        else{
            pr->next = p->next;
        }
        free(p);
        *padd = *padd-1;
    }
    else{
        printf("该档案文件中没有此编号！\n");
    }
    printf("是否需要显示删除后的员工数据的详细信息(Y/N)?\n");
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    DisplyNode(head);
    c = 'n';
    }
    return head;
}

void InquiryData(struct link *head){
    char node[15];
    char name[15];
    struct link *p =head,*pr = head;
    printf("请输入要查询的人员编号：\n");
    scanf("%s",node);
    printf("请输入要查询的人员姓名：\n");
    scanf("%s",name);
    if(head == NULL){
        printf("未查询到员工档案！\n");
        return(head);
    }
    while (strcmp(node,p->data.num)!=0 && strcmp(name,p->data.name)!=0 && p->next != NULL){
        pr = p;
        p = p->next;
    }
    if(strcmp(node,p->data.num) == 0 && strcmp(name,p->data.name) == 0){
        printf("--------此员工的详细信息：--------\n");
        printf("\t姓名：%s            \n",p->data.name);
        printf("\t编号：%s            \n",p->data.num);
        printf("\t性别：%s            \n",p->data.sex);
        printf("\t年龄：%d            \n",p->data.age);
        printf("\t职务：%s            \n",p->data.job);
        printf("\t职称：%s            \n",p->data.post);
        printf("\t政治面貌：%s\n",p->data.politic);
        printf("\t最高学历：%s\n",p->data.edu_level);
        printf("\t任职时间：%s\n",p->data.period);
        printf("\t来院时间：%s\n",p->data.start_time);
        printf("---------------------------------\n");
    }
    else{
        printf("该档案文件中没有对应的人员！\n");
    }
}

struct link *ReviseData(struct link *head){
    char node[15];
    char temp[15];
    char c;
    int j ;
    struct link *p =head,*pr = head;
    printf("请输入被修改员工的编号：\n");
    scanf("%s",node);
    printf("请输入您想要修改的数据类别前的数字：\n");
    printf("1:编号   2:姓名   3:性别   4:年龄\n");
    printf("5:职务   6:职称   7:政治面貌 \n");
    printf("8:最高学历    9:任职时间    10: 来院时间\n");
    scanf("%d",&j);
    if(j>10||j<0){
        for(;;){
        printf("必须输入1~10之间的数字！\n");
        scanf("%d",&j);
            if(j>=1&&j<=10){
                break;
            }
        }
    }
    printf("请输入您修改后的数据：\n");
    scanf("%s",temp);
    if(head == NULL){
        printf("没有员工数据！\n");
        return(head);
    }
    while (strcmp(node,p->data.num)!=0 && p->next != NULL){
        pr = p;
        p = p->next;
    }
    if(strcmp(node,p->data.num) == 0){
        if(j == 1 ){
            strcpy(p->data.num,temp);
        }
        else if(j == 2 ){
            strcpy(p->data.name,temp);
        }
        else if(j == 3 ){
            strcpy(p->data.sex,temp);
        }
        else if(j == 4 ){
            strcpy(p->data.age,temp);
        }
        else if(j == 5 ){
            strcpy(p->data.job,temp);
        }
        else if(j == 6 ){
            strcpy(p->data.post,temp);
        }
        else if(j == 7 ){
            strcpy(p->data.politic,temp);
        }
        else if(j == 8 ){
            strcpy(p->data.edu_level,temp);
        }
        else if(j == 9 ){
            strcpy(p->data.period,temp);
        }
        else if(j == 10 ){
            strcpy(p->data.start_time,temp);
        }
        else{
            printf("请输入正确的数字！");
        }

    }
    else{
        printf("该档案文件中没有此编号！\n");
    }
    printf("您成功修改了员工数据,正准备将员工数据写入人事档案文件...\n");
    printf("是否需要显示修改后的员工数据的详细信息(Y/N)?\n");
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    DisplyNode(head);
    c = 'n';
    }

    printf("已成功将员工数据写入文件！\n");
    return head;
}

void PrintScore(struct link *head){
    struct link *p = head;
    int j = 1;
    while(p != NULL){
        printf("--------第%d个员工信息--------\n",j);
        printf("\t姓名：%s            \n",p->data.name);
        printf("\t编号：%s            \n",p->data.num);
        printf("\t性别：%s            \n",p->data.sex);
        printf("\t年龄：%d            \n",p->data.age);
        printf("\t职务：%s            \n",p->data.job);
        printf("\t职称：%s            \n",p->data.post);
        printf("\t政治面貌：%s\n",p->data.politic);
        printf("\t最高学历：%s\n",p->data.edu_level);
        printf("\t任职时间：%s\n",p->data.period);
        printf("\t来院时间：%s\n",p->data.start_time);
        printf("--------------------------------\n");
        p = p->next;
        j++;
    }

}

void DisplayNode(struct link *head,int *padd){
    char c;
    printf("您是否想要读取并显示该档案文件的人员信息（Y/N）？\n");
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    PrintScore(head);
    c = 'n';
    }
}

struct link *SelectSort(struct link *head){
    struct link *endpt;
    struct link *u;
    struct link *v;
    struct link *p;
    int j;
    u = (struct link *)malloc(sizeof(struct link));
    u->next = head;
    head = u;
    printf("请选择排序方式：\n");
    printf("1:按年龄降序\n");
    printf("2:按来院时间降序\n");
    scanf("%d",&j);
    if(j == 1){
        for(endpt = NULL;endpt!=head;endpt = p){
            for(p = u = head;u->next->next!=endpt;u = u->next){
                if(u->next->data.age < u->next->next->data.age){
                    v=u->next->next;
                    u->next->next=v->next;
                    v->next=u->next;
                    u->next=v;
                    p=u->next->next;
                }
            }
        }
        u = head;
        head = head->next;
        printf("已完成排序！\n");
        return head;
    }
    else if(j == 2){
        for(endpt = NULL;endpt!=head;endpt = p){
            for(p = u = head;u->next->next!=endpt;u = u->next){
                if(strcmp(u->next->data.start_time,u->next->next->data.start_time)<0){
                    v=u->next->next;
                    u->next->next=v->next;
                    v->next=u->next;
                    u->next=v;
                    p=u->next->next;
                }
            }
        }
        u = head;
        head = head->next;
        printf("已完成排序！\n");
        return head;
    }
}

void CountData(struct link *head){
    int j = 0;
    int a;
    struct link *p =head,*pr = head;
    printf("请输入您要统计的类别后的数字：\n");
    printf("1:党员人数    2:女工人数  \n");
    printf("3:高学历人数  4:高职称人数 \n");
    scanf("%d",&a);
    if(j>4||j<0){
        for(;;){
        printf("必须输入1~4之间的数字！\n");
        scanf("%d",&j);
            if(j>=1&&j<=4){
                break;
            }
        }
    }
    if(a == 1){
        while(p!=NULL){
            if(strcmp("党员",p->data.politic) == 0){
                j = j + 1;
            }
            p = p->next;
        }
        printf("该档案文件中共有%d名党员。\n",j);
    }
    else if(a == 2){
        while(p!=NULL){
            if(strcmp("女",p->data.sex) == 0){
                j = j + 1;
            }
            p = p->next;
        }
        printf("该档案文件中共有%d名女工。\n",j);
    }
    else if(a == 3){
        while(p!=NULL){
            if(strcmp("本科",p->data.edu_level) == 0){
                j = j + 1;
            }
            p = p->next;
        }
        printf("该档案文件中共有%d名本科员工。\n",j);
    }
    else if(a == 4){
        while(p!=NULL){
            if(strcmp("教授",p->data.post) == 0){
                j = j + 1;
            }
            p = p->next;
        }
        printf("该档案文件中共有%d名教授。\n",j);
    }
}
