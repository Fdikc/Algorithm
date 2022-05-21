#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef struct node
{
    char name[20];
    int prio;
    int round;
    int cputime;
    int needtime;
    char state;
    int count;
    struct node *next;
} PCB;

PCB *ready = NULL, *run = NULL, *finish = NULL;

int num;
void prioCreate();
void priority();
void timeCreate();
void roundRun();

void getFirst();
void output();
void insertPrio(PCB *in);
void insertTime(PCB *in);
void insertFinish(PCB *in);

int main()
{
    char chose;
    printf("请输入要创建的进程数目：\n");
    scanf("%d", &num);
    getchar();
    printf("输入进程的调度方法：（P/R ）\n");
    scanf("%c", &chose);
    switch (chose)
    {
    case 'p':
    case 'P':
        prioCreate();
        priority();
        break;
    case 'r':
    case 'R':
        timeCreate();
        roundRun();
        break;
    default:
        break;
    }
    output();
    system("pause");
    return 0;
}

void getFirst()
{
    run = ready;
    if (ready != NULL)
    {
        run->state = 'R';
        ready = ready->next;
        run->next = NULL;
    }
}

void output()
{
    PCB *p;
    printf("进程名\t优先级\t时间片\tcpu时间\t需要时间\t进程状态\t\n");
    p = ready;
    while (p != NULL)
    {
        printf("%s\t%d\t%d\t%d\t%d\t\t%c\t\n", p->name, p->prio, p->round, p->cputime, p->needtime, p->state);
        p = p->next;
    }
    p = finish;
    while (p != NULL)
    {
        printf("%s\t%d\t%d\t%d\t%d\t\t%c\t\n", p->name, p->prio, p->round, p->cputime, p->needtime, p->state);
        p = p->next;
    }
    p = run;
    while (p != NULL)
    {
        printf("%s\t%d\t%d\t%d\t%d\t\t%c\t\n", p->name, p->prio, p->round, p->cputime, p->needtime, p->state);
        p = p->next;
    }
}

void insertPrio(PCB *in)
{
    PCB *fst, *nxt;
    fst = nxt = ready;
    if (ready == NULL)
    {
        in->next = ready;
        ready = in;
    }
    else
    {
        if (in->prio > fst->prio)
        {
            in->next = ready;
            ready = in;
        }
        else
        {
            while (fst->next != NULL)
            {
                nxt = fst;
                fst = fst->next;
                if (in->prio > fst->prio)
                    break;
            }
            if (fst->prio > in->prio)
            {
                in->next = fst->next;
                fst->next = in;
            }
            else
            {
                nxt->next = in;
                in->next = fst;
            }
        }
    }
}

void insertTime(PCB *in)
{
    PCB *fst;
    fst = ready;
    if (ready == NULL)
    {
        in->next = ready;
        ready = in;
    }
    else
    {
        while (fst->next != NULL)
        {
            fst = fst->next;
        }
        in->next = fst->next;
        fst->next = in;
    }
}

void insertFinish(PCB *in)
{
    PCB *fst;
    fst = finish;
    if (finish == NULL)
    {
        in->next = finish;
        finish = in;
    }
    else
    {
        while (fst->next != NULL)
        {
            fst = fst->next;
        }
        in->next = fst->next;
        fst->next = in;
    }
}

void prioCreate()
{
    PCB *tmp;
    int i;
    printf("请输入进程名字和进程所需时间：\n");
    for (i = 0; i < num; i++)
    {
        if ((tmp = (PCB *)malloc(sizeof(PCB))) == NULL)
        {
            perror("malloc");
            exit(0);
        }
        scanf("%s", tmp->name);
        getchar();
        scanf("%d", &(tmp->needtime));
        tmp->cputime = 0;
        tmp->state = 'W';
        tmp->prio = 60 - tmp->needtime;
        tmp->round = 0;
        tmp->count = 0;
        insertPrio(tmp);
    }
}

void timeCreate()
{
    PCB *tmp;
    int i;
    printf("请输入进程名字和进程时间片所需时间：\n");
    for (i = 0; i < num; i++)
    {
        if ((tmp = (PCB *)malloc(sizeof(PCB))) == NULL)
        {
            perror("malloc");
            exit(1);
        }
        scanf("%s", tmp->name);
        getchar();
        scanf("%d", &(tmp->needtime));
        tmp->cputime = 0;
        tmp->state = 'W';
        tmp->prio = 0;
        tmp->round = 2;
        tmp->count = 0;
        insertTime(tmp);
    }
}

void priority()
{
    int flag = 1;
    getFirst();
    while (run != NULL)
    {
        output();
        while (flag)
        {
            run->prio -= 3;
            run->cputime++;
            run->needtime--;
            if (run->needtime == 0)
            {
                run->state = 'F';
                run->count++;
                insertFinish(run);
                flag = 0;
            }
            else
            {
                run->state = 'W';
                run->count++;
                insertPrio(run);
                flag = 0;
            }
        }
        flag = 1;
        getFirst();
    }
}

void roundRun()
{
    int flag = 1;
    getFirst();
    while (run != NULL)
    {
        output();
        while (flag)
        {
            run->count++;
            run->cputime++;
            run->needtime--;
            if (run->needtime == 0)
            {
                run->state = 'F';
                insertFinish(run);
                flag = 0;
            }
            else if (run->count == run->round)
            {
                run->state = 'W';
                run->count = 0;
                insertTime(run);
                flag = 0;
            }
        }
        flag = 1;
        getFirst();
    }
}
