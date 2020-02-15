#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"string.h"
#include"time.h"
#include"windows.h"
#define LEN 10
void gotoxy(int x, int y);                                        //��궨λ��������
int manage(struct room *head,struct ID *p,struct ID *head1);      //����Ա������������
void menu(struct ID *head1);									  //����Ա�����˵���������
struct room *read();										      //���ļ��еķ�����Ϣ��ȡ�������к�������
void write(struct room * head);                                   //���ļ��еķ�����Ϣд�������к�������
struct room *add(struct room *head);							  //��������Ϣ��������
void look(struct room *head,struct ID *head1);					  //���������Ϣ��������
void change(struct room *head);									  //�޸ķ�����Ϣ����������
void cMenu();													  //�޸ķ�����Ϣ�˵���������
struct room *amend(struct room *head);							  //�޸ı�����������
void cNum(struct room *head);									  //�޸ķ���ź�������
void cType(struct room *head);									  //�޸ķ��ͺ�������
void cSite(struct room *head);                                    //�޸ķ���λ�ú�������
void cCheckIn(struct room *head);                                 //�޸ķ�����ס��Ϣ��������
void cCost(struct room *head);                                    //�޸ķ���۸�������
void cName(struct room *head);                                    //�޸�ס��������������
void dispose(struct room *head);                                  //����ס�����뺯������
struct room *del(struct room *head,struct ID *head1);             //ɾ��������Ϣ��������
void finds(struct room *head,struct ID *head1);                   //��ѯ������Ϣ��������
void fMenu();                                                     //��ѯ���˵���������
void fNum(struct room *head,struct ID *head1);                    //�����֤������в�ѯ��������
void fType(struct room *head,struct ID *head1);                   //�����ͽ��в�ѯ��������
void fSite(struct room *head,struct ID *head1);                   //��λ�ò�ѯ��������
void fStatus(struct room *head,struct ID *head1);                 //��״̬��ѯ��������
void fInputTime(struct room *head,struct ID *head1);              //������ʱ���ѯ��������
void fDays(struct room *head,struct ID *head1);                   //������������ѯ��������
void fCost(struct room *head,struct ID *head1);                   //��ÿ����ò�ѯ��������
void fName(struct room *head,struct ID *head1);                   //��������ѯ��������
void fTel(struct room *head,struct ID *head1);                    //���绰�����ѯ��������
void signFind(struct ID *head);                  //�����һغ�������
struct ID *logout(struct ID *head);              //����ע����������
struct ID *accountName(struct ID *head);         //�û��˺�ע�ắ������
struct ID *sign(struct ID *head);                //�û���¼��������
struct ID *loginRead();                          //�û����ݶ��뺯������
void loginWrite(struct ID *head);                //���û�����д���ļ��к�������
void loginMenu();                                //��¼����˵���������
struct ID *login();                              //�û���¼ϵͳ������
void changePassword(struct ID *head);            //�����޸ĺ�������
char *randStr(char str[], int n);                //��֤�����ɺ�������
int user(struct room *head,struct ID *p,struct ID *head1);        //�û�������������
void umenu(struct ID *p);                        //�û������˵���������
void reserve(struct room *head,struct ID *p,struct ID *head1);    //�û���Ԥ���Ƶ꺯������
void out(struct room *head,struct ID *p,struct ID *head1);        //�û����˾Ƶ꺯������
void userLook(struct room *head,struct ID *p,struct ID *head1);
void userChange(struct room *head,struct ID *p,struct ID *head1);
void userChangeMenu();
struct ID *userAmend(struct room *head,struct ID *p,struct ID *head1);
void cInputTime(struct room *head,struct ID *p,struct ID *head1);
void cInputName(struct room *head,struct ID *p,struct ID *head1);
void cUserTel(struct room *head,struct ID *p,struct ID *head1);
int scanfPlus(char *st,int m,int n,int x);       //�Ľ������뺯������
void visitor();                                  //�οͶ˺�������
void viewMenu();                                 //�οͶ˲˵�
void viewLook();                                 //�οͶ˲鿴
void load();                                     //����������
void HideCursor();                               //���ع��
void form(int x,int n);                          //��˵����������
void form2(int n);                               //�򷿼�������Ϣ���������
void form3(struct room *p1,int i);               //�򷿼�������Ϣ����е����ݺ�������
int form4(int n,struct room *head);              //�򷿼䲿����Ϣ�������ݺ�������
struct ID *tranday(struct ID *p);                //����ת����������
void status(struct room *p1,struct ID *x1);      //״̬���ĺ�������
BOOL SetConsoleColor(WORD wAttributes);          //�����ַ���ǰ��ɫ�ͺ�ɫ��������
void reset(struct room *head);                   //������Ϣ��������
int arrows(int x,char min,char max);             //�����ָ��������
void blue();                                     //��ɫ���庯������
void red();                                      //��ɫ���庯������
int cColor(int y,int x,int judge);               //��ͷ�ƶ���Ϣͬ���仯��������
void inversion(int *i,int y,int *x,int a,int b,char *s);//��ͷ�����ú�������
void remind(struct ID *p,struct ID *head1);       //���Ѻ�������
void ShowCursor();                               //��ʾ�ر�
//int choice;                                    //ѡ��ȫ�ֱ�����������
                   /***********����������Ϣ������***********/
struct room
{
	char num[10];                        //�����
	char type[11];                       //����
	char site[10];                       //λ��
	char status[10];                     //״̬
	char check[10];                      //��ס
	char checkOut[10];                   //�˷�
	char inputTime[14];                  //����ʱ��
	int year;                            //�������
	int mon;                             //��
	int day;                             //��
	int days;                            //����
	char cost[10];                       //����
	char name[10];                       //����
	char tel[12];                        //�绰
	char idnum[20];                      //���֤��
	struct room *next;                   //��һ������ַ
};
                 /************�����û���Ϣ������**********/
struct ID
{
	char power[10];                      //Ȩ��(����Աor��ͨ�û�)
	char account[20];                    //�˺�
	char key[20];                        //����
	char keyProtect[20];                 //�ܱ�
	char check[10];                      //��ס
	char checkOut[10];                   //�˷�
	char name[10];                       //����
	char idnum[20];                      //���֤��
	char num[10];                        //�����
	char sex[3];                         //�Ա�
	char inputName[10];                  //��סʱ��
	char inputTel[12];                   //��ס�绰
	int year;                            //��סʱ����
	int mon;                             //��סʱ����
	int day;                             //��סʱ����
	int years;                           //�뿪ʱ����
	int month;                           //�뿪ʱ����
	int days;                            //�뿪ʱ����
	int numDay;                          //Ԥ������
	int daymax;                          //�뿪���ڵ�����
	int daymin;                          //��ס���ڵ�����
	int cost;                            //����ÿ�յļ۸�
	char information[100];               //��Ϣ
	struct ID * next;                    //��һ������ַ
};
                                 /************������***************/
int main(void)
{

	system("color F1");
//	load();
	struct ID *p,*head1;
	struct room *head = NULL;
	gotoxy(80,14);
	head = read();                   //������Ϣ����������
	head1 = loginRead();
	p = login();               //��¼�󷵻ظ��û���Ϣ��
	while(1)
	{
		if (strcmp(p->power,"����Ա") == 0)   //�ж��û���ݲ�ѡ�������Ӧ�˿�
		{
			if(manage(head,p,head1) == 0)          //�ж��û������˳���¼
				p = login();
		}
		else
		   if(user(head,p,head1) == 0)
			   p = login();
	}
	return 0;
}
                              /************�����ַ���ǰ��ɫ�ͱ���ɫ**********/
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;
	return SetConsoleTextAttribute(hConsole,wAttributes);
}
                                     /**************��궨λ*************/
void gotoxy(int x, int y)
{
        COORD coord = {x,y};            //�ڿ���̨��Ļ�ϵ�����

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  //��ȡ���(���ͣ��λ�õ���Ϣ)
}
                                                 /*****�����������******/
int manage(struct room *head,struct ID *p,struct ID *head1)
{
	int x,i;
	char t;
	system("cls");
	gotoxy(80,14);
	if (strcmp(p->sex,"��") == 0)
		printf("�𾴵�%s����Ա������ӭ����¼�Ƶ����϶���ϵͳ\n",p->name);
	else
		printf("�𾴵�%s����ԱŮʿ��ӭ����¼�Ƶ����϶���ϵͳ\n",p->name);
	gotoxy(80,15);
	system("pause");
	head = read();
    A:system("cls");
	write(head);
	head = read();
	head1 = loginRead();
    menu(head1);
	x = 8;
	i = 0;
	while (1)
	{
		t = arrows(x,'0','7');
		switch(t)
		{
		    case 72:
				     if (i > 0)
					 {
						 x = cColor(89,x,0);
					     if (x == 8)
							 puts("1.��ӷ�����Ϣ");
						 else if (x == 10)
							 puts("2.�鿴������Ϣ");
						 else if (x == 12)
							 puts("3.�޸ķ�����Ϣ");
						 else if (x == 14)
	                         puts("4.����ͻ�����");
						 else if (x == 16)
	                         puts("5.ɾ��������Ϣ");
						 else if (x == 18)
	                         puts("6.���ҷ�����Ϣ");
						 else
							 puts("7.�˳���¼");
					     i--;
					 }
					 else
						 inversion(&i,89,&x,7,22,"0.�˳�ϵͳ");
					 break;

			case 80:
				     if (i < 7)
					 {
						 x = cColor(89,x,1);
	                     if (x == 10)
							 puts("2.�鿴������Ϣ");
						 else if (x == 12)
							 puts("3.�޸ķ�����Ϣ");
						 else if (x == 14)
						     puts("4.����ͻ�����");
						 else if (x == 16)
						     puts("5.ɾ��������Ϣ");
						 else if (x == 18)
							 puts("6.���ҷ�����Ϣ");
						 else if (x == 20)
							 puts("7.�˳���¼");
						 else
							 puts("0.�˳�ϵͳ");
						 i++;
					 }
					 else
						 inversion(&i,89,&x,0,8,"1.��ӷ�����Ϣ");
					 break;
			case 13: system("cls");
				     if (x == 8)
						 head = add(head);
					 else if (x == 10)
						 look(head,head1);
					 else if (x == 12)
						 change(head);
					 else if (x == 14)
						 dispose(head);
					 else if (x == 16)
						 head = del(head,head1);
					 else if (x == 18)
						 finds(head,head1);
					 else if (x == 20)
						 return 0;
					 else
						 exit(0);
					 goto A;

			case 49: system("cls");ShowCursor();head = add(head); goto A;
			case 50: system("cls");ShowCursor();look(head,head1); goto A;
			case 51: system("cls");ShowCursor();change(head); goto A;
			case 52: system("cls");ShowCursor();dispose(head); goto A;
			case 53: system("cls");ShowCursor();head = del(head,head1); goto A;
			case 54: system("cls");ShowCursor();finds(head,head1);goto A;
			case 55: return 0;
			case 48: exit(0);
		}
	}
}
                      /************������Ϣ��˳���С����˳���ȡ*********/
struct room *read()
{
   struct room *head = NULL,*p1,*p2,*p;
   FILE *fp;
   if ((fp=fopen("������Ϣ","rb"))==NULL)
      return head;
   B:p=(struct room *)malloc(sizeof(struct room));     //����ռ�
   fread(p,sizeof(struct room),1,fp);                 //���ļ��еķ�����Ϣ��ȡ��������
   if (feof(fp))                                        //�ж��Ƿ�����ļ���β
   {
	   fclose(fp);
	   return head;
   }
   if (head==NULL)                                           //���ڿ�����������Ե�����ȡ��һ��������Ϣ
   {
      head=p;
	  p->next=NULL;
	  goto B;
   }
   p1=head;
   if (p1->next==NULL)                       //�ж�����֮���Ƿ�ֻ��һ��ͷ���
   {
     if (strcmp(p->num,p1->num)<=0)          //�Ƚϸ÷�����ͷ��㷿�ŵĴ�С�жϴ˷�����Ϣд��ͷ���֮ǰ����֮��
	 {
        head=p;
	    p->next=p1;
	 }
     else
	 {
         p1->next=p;
         p->next=NULL;
	 }
     goto B;
   }
   p2=p1;
   while(p2!=NULL)
   {
      if (strcmp(p->num,p2->num)<0)
	  {
	     if (p2==head)
		 {
		    head=p;
		    p->next=p2;
		    goto B;
		 }
		 else
		 {
		   p1->next=p;
		   p->next=p2;
	       goto B;
		 }
	  }
	  else
	  {
	     p1=p2;
		 p2=p2->next;
	  }
   }
   p1->next=p;
   p->next=NULL;
   goto B;
}
                                 /***********������Ϣд��****************/
void write(struct room * head)
{
	FILE *fp;
	struct room *p1;
	p1 = head;
	fp = fopen("������Ϣ","wb");
	while (p1 != NULL)            //���������е���Ϣд���ļ���
	{
		fwrite(p1,sizeof(struct room),1,fp);
		p1 = p1->next;
	}
	fclose(fp);
}
                                     /**************��������˵�*******/
void menu(struct ID *head1)
{
	struct ID *x1;
	int i = 0;
	x1 = head1;
	while (x1 != NULL)            //���������������
	{
		if (strcmp(x1->checkOut,"��") == 0)
			++i;
		x1 = x1->next;
	}
	if (i>0)
		printf("����%d����������˷�����\n\n\a",i);
	//system("pause");
	form(5,8);
	gotoxy(92,6);
	puts("�쳾��ջ");
	gotoxy(89,10);
	puts("2.�鿴������Ϣ");
	gotoxy(89,12);
	puts("3.�޸ķ�����Ϣ");
	gotoxy(89,14);
	puts("4.����ͻ�����");
	gotoxy(89,16);
	puts("5.ɾ��������Ϣ");
	gotoxy(89,18);
	puts("6.���ҷ�����Ϣ");
	gotoxy(89,20);
	puts("7.�˳���¼");
	gotoxy(89,22);
	puts("0.�˳�ϵͳ");
	red();
	gotoxy(89,8);
	puts("1.��ӷ�����Ϣ");

}
                                              /********��ӷ�����Ϣ*********/
struct room *add(struct room *head)
{
	struct room *p1,*p2;
	p1 = (struct room *)malloc(sizeof(struct room));
    A:p2 = head;
	gotoxy(80,1);
	puts("��ӷ�����Ϣ");
	puts("��������ӷ�����Ϣ:");
	gotoxy(81,4);
	printf("�����:");
	gotoxy(88,4);
    if (scanfPlus(p1->num,1,9,0) == 1) //��ESC��ִ�з��ز���if�ж��Ƿ�ִ�з��ز���
		return head;
	while (p2 != NULL)
	{

		if (strcmp(p2->num,p1->num) == 0)
		{
			MessageBox(NULL,"���뷿����ظ����������룡","����",MB_ICONHAND);
			system("cls");
			goto A;
		}
		p2 = p2->next;
	}
	gotoxy(81,5);
	printf("����:");
	gotoxy(86,5);
	if (scanfPlus(p1->type,1,10,0) == 1)
		return head;
	gotoxy(81,6);
	printf("λ��:");
	gotoxy(86,6);
	if (scanfPlus(p1->site,1,9,0) == 1)
		return head;
	gotoxy(81,7);
	printf("����(ÿ��):");
	gotoxy(92,7);
	if (scanfPlus(p1->cost,1,9,0) == 1)
		return head;
    strcpy(p1->status,"����");
	strcpy(p1->check,"δ��ס");
	p1->year = 1;
	p1->days = 0;
	strcpy(p1->name,"��");
	strcpy(p1->tel,"��");
	if (head == NULL)
	{
		head = p1;
		p1->next = NULL;
		return head;
	}
	p2 = head;
	while (p2->next != NULL)
		p2 = p2->next;
	p2->next = p1;
	p1->next = NULL;
	MessageBox(NULL,"��ӳɹ���","��ʾ",MB_ICONASTERISK);
	return head;
}
                                     /**********���������Ϣ********/
void look(struct room *head,struct ID *head1)
{
	int i,n = 0;
	int s = time(0);
	int d = s/86400 - 10956;
	struct ID *x1;
	struct room *p2;
	if (head == NULL)
	{
		MessageBox(NULL,"���κη�����Ϣ��","����",MB_ICONHAND);
		return;
	}
	gotoxy(80,1);
	printf("���������Ϣ");
	p2 = head;
	while (p2 != NULL)
	{
		x1 = head1;
		while (x1 != NULL)
		{
			if (x1->daymin <= d && x1->daymax > d && strcmp(x1->num,p2->num) == 0)
			{

				strcpy(p2->status,"�ѱ�Ԥ��");
				strcpy(p2->name,x1->inputName);
				strcpy(p2->tel,x1->inputTel);
				p2->year = x1->year;
				p2->mon = x1->mon;
				p2->day = x1->day;
				p2->days = x1->numDay;
				break;
			}
			x1 = x1->next;
		}
		n++;
		p2 = p2->next;
	}
	form2(n);
	p2 = head;
	i = 0;
	while (p2 != NULL)
	{
		form3(p2,i);
		p2 = p2->next;
		i++;
	}
    gotoxy(13,10+2*i);
	reset(head);
	system("pause");
}
                                       /*************�޸ķ�����Ϣ************/
void change(struct room *head)
{
	int x,i;
	char t;
    A:system("cls");
	write(head);
	x = 8;
	i = 0;
	cMenu();
	while (1)
	{
		t = arrows(x,'0','5');
		switch(t)
		{
		    case 72:
				     if (i>0)
					 {
						 x = cColor(90,x,0);
					     if (x == 8)
							 puts("1.�����");
						 else if (x == 10)
							 puts("2.����");
						 else if (x == 12)
							 puts("3.λ��");
						 else if (x == 14)
							 puts("4.��ס");
						 else
							 puts("5.����");
					     i--;
					 }
					 else
						 inversion(&i,90,&x,5,18,"0.������һ������");
					 break;
			case 80:
				     if (i<5)
					 {
						 x = cColor(90,x,1);
	                     if (x == 10)
							 puts("2.����");
						 else if (x == 12)
							 puts("3.λ��");
						 else if (x == 14)
							 puts("4.��ס");
						 else if (x == 16)
							 puts("5.����");
						 else
							 puts("0.������һ������");
						 i++;
					 }
					 else
						 inversion(&i,90,&x,0,8,"1.�����");
					 break;
			case 13: system("cls");
				     if (x == 8)
						 cNum(head);
					 else if (x == 10)
						 cType(head);
					 else if (x == 12)
						 cSite(head);
					 else if (x == 14)
						 cCheckIn(head);
					 else if (x == 16)
						 cCost(head);
					 else
						 return;
					 goto A;
			case 49: system("cls");ShowCursor();cNum(head);goto A;
			case 50: system("cls");ShowCursor();cType(head);goto A;
			case 51: system("cls");ShowCursor();cSite(head);goto A;
			case 52: system("cls");ShowCursor();cCheckIn(head);goto A;
			case 53: system("cls");ShowCursor();cCost(head);goto A;
			case 48: return;
		}
	}
}
                                 /******������Ϣ�޸�********/
void cMenu()
{
	form(5,6);
	gotoxy(87,6);
	puts("��ջ������Ϣ����");
	gotoxy(90,10);
	puts("2.����");
	gotoxy(90,12);
	puts("3.λ��");
	gotoxy(90,14);
	puts("4.��ס");
	gotoxy(90,16);
	puts("5.����");
	gotoxy(90,18);
	puts("0.������һ������");
	red();
	gotoxy(90,8);
	puts("1.�����");
}
                                /**********������Ϣ�޸�ͨʽ********/
struct room *amend(struct room *head)
{
	struct room *p1;
	char amendNum[20];
    A:printf("������Ҫ�޸ķ�����Ϣ�ķ����:");
    if (scanfPlus(amendNum,1,9,0) == 1)
		return NULL;
	p1 = head;
	while(p1 != NULL)                    //��������ֱ��������Ҫ�޸ĵķ�����Ϣ��λ��
	{
		if (strcmp(p1->num,amendNum) == 0)
		{
			printf("�÷�����Ϣ����:\n\n");
			gotoxy(63,5);
	        puts("���������������������������������Щ��������������������������������Щ������������������������������Щ������������������������������Щ�������������������������������");
	        gotoxy(63,6);
	        puts("��               ��                ��               ��               ��               ��");
		    gotoxy(63,7);
		    puts("���������������������������������੤�������������������������������੤�����������������������������੤�����������������������������੤������������������������������");
		    gotoxy(63,8);
		    puts("��               ��                ��               ��               ��               ��");
            gotoxy(63,9);
	        puts("���������������������������������ة��������������������������������ة������������������������������ة������������������������������ة�������������������������������");
	        gotoxy(69,6);
	        printf("�����");
	        gotoxy(86,6);
	        printf("����");
	        gotoxy(103,6);
	        printf("λ��");
	        gotoxy(117,6);
	        printf("��ס");
	        gotoxy(135,6);
	        printf("����(��)");
			gotoxy(70,8);
		    printf("%s",p1->num);
		    gotoxy(85,8);
			printf("%s",p1->type);
			gotoxy(103,8);
			printf("%s",p1->site);
			gotoxy(117,8);
			printf("%s",p1->check);
			gotoxy(135,8);
			printf("%s",p1->cost);
			return p1;
		}
		p1 = p1->next;
	}
	MessageBox(NULL,"δ�鵽�˷��������������!","����",MB_ICONHAND);
	system("cls");
	goto A;
}
                             /****�޸ķ����******/
void cNum(struct room *head)
{
	struct room *p1,*p2;
    if ((p1 = amend(head)) == NULL)
		return;
	gotoxy(13,10);
    A:printf("�������޸ĺ�ķ����:");
	if (scanfPlus(p1->num,1,9,0) == 1)
		return;
	p2 = head;
	while (p2 != NULL)
	{
		if (strcmp(p1->num,p2->num) == 0 && p1 != p2)  //�жϷ�����Ƿ��ظ�
		{
			MessageBox(NULL,"�˷�����Ѵ�������������","����",MB_ICONHAND);
			system("cls");
			goto A;
		}
		p2 = p2->next;
	}
	MessageBox(NULL,"�޸ĳɹ���","��ʾ",MB_ICONASTERISK);
}
                                  /**************�޸ķ���**************/
void cType(struct room *head)
{
	struct room *p1;
	if ((p1 = amend(head)) == NULL)
		return;
	gotoxy(13,10);
	printf("�������޸ĺ�ķ���:");
	if (scanfPlus(p1->type,1,19,0) == 1)
		return;
	MessageBox(NULL,"�޸ĳɹ���","��ʾ",MB_ICONASTERISK);
}
                                   /*****�޸ķ���λ��******/
void cSite(struct room *head)
{
	struct room *p1;
	if ((p1 = amend(head)) == NULL)
		return;
	gotoxy(13,10);
	printf("�������޸ĺ��λ��:");
	if (scanfPlus(p1->site,1,9,0) == 1)
		return;
	MessageBox(NULL,"�޸ĳɹ���","��ʾ",MB_ICONASTERISK);
}
                                    /*************�޸ķ�����ס���***********/
void cCheckIn(struct room *head)
{
	struct room *p1;
    if ((p1 = amend(head)) == NULL)
		return;
	gotoxy(13,10);
	A:printf("�������޸ĺ����ס���:");
    if (scanfPlus(p1->check,1,9,0) == 1)
		return;
	if (strcmp(p1->check,"����ס") != 0 && strcmp(p1->check,"δ��ס") != 0)
	{
		MessageBox(NULL,"�Ƿ���������������!","����",MB_ICONHAND);
		system("cls");
		goto A;
	}
	MessageBox(NULL,"�޸ĳɹ���","��ʾ",MB_ICONASTERISK);
}
                                       /*************�޸�һ��ķ���*******************/
void cCost(struct room *head)
{
	struct room *p1;
	if ((p1 = amend(head)) == NULL)
		return;
	gotoxy(13,10);
	printf("�������޸ĺ�ķ���(ÿ��):");
	if (scanfPlus(p1->cost,1,15,0) == 1)
		return;
	MessageBox(NULL,"�޸ĳɹ���","��ʾ",MB_ICONASTERISK);
}
                                        /*******************����˶�������д���******************/
void dispose(struct room *head)
{
	struct ID *head1,*x1;
	struct room *p1;
	char judge[3],name[20];
	head1 = loginRead();
	x1 = head1;
	while (x1 != NULL)              //�����ͻ���Ϣ��������
	{
		if (strcmp(x1->checkOut,"��") == 0)
		{
			p1 = head;
			while (p1 != NULL)          //�������ÿͻ����˵ķ���
			{
				if (strcmp(p1->num,x1->num) == 0)
					break;
				p1 = p1->next;
			}
			strcpy(p1->status,"��Ԥ��");
			strcpy(name,x1->name);
			strcpy(p1->name,x1->inputName);
			strcpy(p1->tel,x1->inputTel);
			p1->year = x1->year;
			p1->mon = x1->mon;
			p1->day = x1->day;
			p1->days = x1->numDay;
            A:form2(1);
			form3(p1,0);
			gotoxy(13,14);
			if(MessageBox(NULL,"�Ƿ�ͬ��ÿͻ����˷�����","ѯ��",MB_ICONASTERISK|MB_OKCANCEL) != IDCANCEL)
			{
				strcpy(x1->checkOut,"���˷�");
				strcpy(x1->num,"��");
			//	x1->daymax = 0;
				p1->days = 0;
				p1->year = 1;
				strcpy(p1->tel,"��");
				strcpy(p1->idnum,"��");
				strcpy(p1->status,"����");
				strcpy(p1->check,"δ��ס");
				strcpy(p1->name,"��");
				MessageBox(NULL,"����ɹ���","��ʾ",MB_ICONASTERISK);
				loginWrite(head1);
				return;
			}
			strcpy(x1->checkOut,"�˷�ʧ��");
			gotoxy(13,15);
			printf("������ܾ����˷���ԭ��:");
			if  (scanfPlus(x1->information,1,99,0) == 1)
				return;
			MessageBox(NULL,"����ɹ���","��ʾ",MB_ICONASTERISK);
			loginWrite(head1);
			return;
		}
		x1 = x1->next;
	}
	MessageBox(NULL,"�޴����������!","����",MB_ICONHAND);
}
                                      /********ɾ��������Ϣ***********/
struct room *del(struct room *head,struct ID *head1)
{
	struct room *p2,*p3;
	struct ID *x1;
	char delnum[20];
	if (head == NULL)
	{
		MessageBox(NULL,"���κη�����Ϣ!","��ʾ",MB_ICONASTERISK);
		return head;
	}
	printf("������Ҫɾ��������Ϣ�ķ����:");
	if (scanfPlus(delnum,1,9,0) == 1)
		return head;
	x1 = head1;
	while (x1 != NULL)
	{
		if (strcmp(x1->num,delnum) == 0)
		{
			MessageBox(NULL,"�÷�������Ԥ������ɾ��","����", MB_ICONEXCLAMATION );
			return head;
		}
		x1 = x1->next;
	}
	p2 = head;
	while (p2 != NULL)
	{
		if (strcmp(delnum,p2->num) == 0)
		{
            A:system("cls");
			form2(1);
			form3(p2,0);
			gotoxy(13,10);
			if(MessageBox(NULL,"�Ƿ�ɾ���÷�����Ϣ","ѯ��",MB_ICONASTERISK|MB_OKCANCEL)!=IDCANCEL)
			{
				if (p2 == head)
				{
					head = p2->next;
				    free(p2);
				    MessageBox(NULL,"ɾ���ɹ�!","��ʾ",MB_ICONASTERISK);
				    return head;
				}
			    else
				{
				    p3->next = p2->next;
				    free(p2);
				    MessageBox(NULL,"ɾ���ɹ�!","��ʾ",MB_ICONASTERISK);
				    return head;
				}
			}
			MessageBox(NULL,"��ȡ��ɾ����","��ʾ",MB_ICONASTERISK);
			return head;

		}
		p3 = p2;
		p2 = p2->next;
	}
	MessageBox(NULL,"���޴˷�����Ϣ!","��ʾ",MB_ICONASTERISK);
	return head;
}
                                /**************���ݷ�����Ϣ���в���*************/
void finds(struct room *head,struct ID *head1)
{
	int x,i;
	char t;
    A:system("cls");
	x = 6;
	i = 0;
	fMenu();
	while (1)
	{
		t = arrows(x,'0','9');
		switch(t)
		{
		    case 72:
				     if (i>0)
					 {
						 x = cColor(92,x,0);
					     if (x == 6)
							 puts("1.�����");
						 else if (x == 8)
							 puts("2.����");
						 else if (x == 10)
							 puts("3.λ��");
						 else if (x == 12)
							 puts("4.����״̬");
						 else if (x == 14)
							 puts("5.��סʱ��");
						 else if (x == 16)
							 puts("6.����");
						 else if (x == 18)
							 puts("7.����");
						 else if (x == 20)
							 puts("8.��ס�ͻ�����");
						 else if (x == 22)
							 puts("9.�绰");
					     i--;
					 }
					 else
						 inversion(&i,92,&x,9,24,"0.������һ������");
					 break;
			case 80:
				     if (i<9)
					 {
						 x = cColor(92,x,1);
						 if (x == 8)
							 puts("2.����");
						 else if (x == 10)
							 puts("3.λ��");
						 else if (x == 12)
							 puts("4.����״̬");
						 else if (x == 14)
							 puts("5.��סʱ��");
						 else if (x == 16)
							 puts("6.����");
						 else if (x == 18)
							 puts("7.����");
						 else if (x == 20)
							 puts("8.��ס�ͻ�����");
						 else if (x == 22)
							 puts("9.�绰");
						 else
							 puts("0.������һ������");
						 i++;
					 }
					 else
						 inversion(&i,92,&x,0,6,"1.�����");
					 break;
			case 13: system("cls");
				     if (x == 6)
						 fNum(head,head1);
					 else if (x == 8)
						 fType(head,head1);
					 else if (x == 10)
						 fSite(head,head1);
					 else if (x == 12)
						 fStatus(head,head1);
					 else if (x == 14)
						 fInputTime(head,head1);
					 else if (x == 16)
						 fDays(head,head1);
				     else if (x == 18)
						 fCost(head,head1);
					 else if (x == 20)
						 fName(head,head1);
					 else if (x == 22)
						 fTel(head,head1);
					 else
						 return;
					 goto A;
			case 49: system("cls");ShowCursor();fNum(head,head1);goto A;
			case 50: system("cls");ShowCursor();fType(head,head1);goto A;
			case 51: system("cls");ShowCursor();fSite(head,head1);goto A;
			case 52: system("cls");ShowCursor();fStatus(head,head1);goto A;
			case 53: system("cls");ShowCursor();fInputTime(head,head1);goto A;
			case 54: system("cls");ShowCursor();fDays(head,head1);goto A;
			case 55: system("cls");ShowCursor();fCost(head,head1);goto A;
			case 56: system("cls");ShowCursor();fName(head,head1);goto A;
			case 57: system("cls");ShowCursor();fTel(head,head1);goto A;
			case 48: return;
		}
	}
}
                                                 /***********���ݲ�ͬ�ֲ�������Ϣ���ҵĲ˵�**************/
void fMenu()
{
	form(3,10);
	gotoxy(88,4);
	puts("��ѯ��ջ������Ϣ");
	gotoxy(92,8);
	puts("2.����");
	gotoxy(92,10);
	puts("3.λ��");
	gotoxy(92,12);
	puts("4.����״̬");
	gotoxy(92,14);
	puts("5.��סʱ��");
	gotoxy(92,16);
	puts("6.����");
	gotoxy(92,18);
	puts("7.����");
	gotoxy(92,20);
	puts("8.��ס�ͻ�����");
	gotoxy(92,22);
	puts("9.�绰");
	gotoxy(92,24);
	puts("0.������һ���˵�");
	gotoxy(92,6);
	red();
	puts("1.�����");


}
                                                    /***************���ݷ���Ž��в���********************/
void fNum(struct room *head,struct ID *head1)
{
	struct room *p1;
	struct ID *x1;
	char rNum[10];
	int flag = 0,i,n = 0;
	printf("����������ҷ���ķ����:");
	if (scanfPlus(rNum,1,9,0) == 1)
		return;
	p1 = head;
	while(p1 != NULL)
	{
		if (strstr(p1->num,rNum) != 0)
			n++;
		p1 = p1->next;
	}
	if (n == 0)
	{
		MessageBox(NULL,"δ�鵽�˷�����Ϣ!","��ʾ",MB_ICONASTERISK);
		return;
	}
	do
	{
		if (flag == 1)
			form2(i);
		p1 = head;
		i = 0;
		while (p1 != NULL)
		{
			if (strstr(p1->num,rNum) != 0)
			{
				x1 = head1;
				while (x1 != NULL)
				{
					if (strcmp(p1->num,x1->num) == 0)
					{
						status(p1,x1);
						form3(p1,i);
						i++;
					}
					x1 = x1->next;
				}
				if (strcmp(p1->status,"����") == 0)
				{
					form3(p1,i);
					i++;
				}
			}
			p1 = p1->next;
		}
		flag++;
	}
	while (flag == 1);
	gotoxy(13,10+2*i);
	system("pause");
}
                                              /************���ݷ��ͽ��в���*************/
void fType(struct room *head,struct ID *head1)
{
	struct room *p1;
	struct ID *x1;
	char rType[10];
	int flag = 0,i,n = 0;
	printf("����������ҷ���ķ���:");
	if (scanfPlus(rType,1,9,0) == 1)
		return;
	p1 = head;
	while(p1 != NULL)
	{
		if (strstr(p1->type,rType) != 0)
			n++;
		p1 = p1->next;
	}
	if (n == 0)
	{
	    MessageBox(NULL,"δ�鵽�˷�����Ϣ!","��ʾ",MB_ICONASTERISK);
		return;
	}
	do
	{
		if (flag == 1)
			form2(i);
		p1 = head;
		i = 0;
		while (p1 != NULL)
		{
			if (strstr(p1->type,rType) != 0)
			{
				x1 = head1;
				while (x1 != NULL)
				{
					if (strcmp(p1->num,x1->num) == 0)
					{
						status(p1,x1);
						form3(p1,i);
						i++;
					}
					x1 = x1->next;
				}
				if (strcmp(p1->status,"����") == 0)
				{
					form3(p1,i);
					i++;
				}
			}
			p1 = p1->next;
		}
		flag++;
	}
	while (flag == 1);
	gotoxy(13,10+2*i);
	system("pause");
}
                                            /**************���ݷ���λ�ý��в���*************/
void fSite(struct room *head,struct ID *head1)
{
	struct room *p1;
	struct ID *x1;
	char rSite[10];
	int flag = 0,i,n = 0;
	printf("����������ҷ����λ��:");
	if (scanfPlus(rSite,1,9,0) == 1)
		return;
	p1 = head;
	while(p1 != NULL)
	{
		if (strstr(p1->site,rSite) != 0)
			n++;
		p1 = p1->next;
	}
	if (n == 0)
	{
	    MessageBox(NULL,"δ�鵽�˷�����Ϣ!","��ʾ",MB_ICONASTERISK);
		return;
	}
	do
	{
		if (flag == 1)
			form2(i);
		p1 = head;
		i = 0;
		while (p1 != NULL)
		{
			if (strstr(p1->site,rSite) != 0)
			{
				x1 = head1;
				while (x1 != NULL)
				{
					if (strcmp(p1->num,x1->num) == 0)
					{
						status(p1,x1);
						form3(p1,i);
						i++;
					}
					x1 = x1->next;
				}
				if (strcmp(p1->status,"����") == 0)
				{
					form3(p1,i);
					i++;
				}
			}
			p1 = p1->next;
		}
		flag++;
	}
	while (flag == 1);
	gotoxy(13,10+2*i);
	system("pause");
}
                                                /****************���ݷ���״̬���в���************/
void fStatus(struct room *head,struct ID *head1)
{
	struct room *p1;
	struct ID *x1;
	char rStatus[10];
	int flag = 0,flag2 = 0,i,n = 0;
	printf("����������ҷ����״̬:");
	if (scanfPlus(rStatus,1,9,0) == 1)
		return;
	p1 = head;
	while (p1 != NULL)
	{
		x1 = head1;
		while (x1 != NULL)
		{
			if (strcmp(p1->num,x1->num) == 0)
				strcpy(p1->status,"��Ԥ��");
			x1 = x1->next;
		}
		p1 = p1->next;
	}
	p1 = head;
	while(p1 != NULL)
	{
		if (strstr(p1->status,rStatus) != 0)
			n++;
		p1 = p1->next;
	}
	if (n == 0)
	{
	    MessageBox(NULL,"δ�鵽�˷�����Ϣ!","��ʾ",MB_ICONASTERISK);
		return;
	}
	do
	{
		if (flag == 1)
			form2(i);
		p1 = head;
		i = 0;
		while (p1 != NULL)
		{
			if (strstr(p1->status,rStatus) != 0)
			{
				x1 = head1;
				while (x1 != NULL)
				{
					if (strcmp(p1->num,x1->num) == 0)
					{
						status(p1,x1);
						form3(p1,i);
						i++;
						flag2 = 1;
					}
					x1 = x1->next;

				}
				if (flag2 == 0)
				{
					    form3(p1,i);
					    i++;
				}
				flag2 = 0;
			}
			p1 = p1->next;
		}
		flag++;
	}
	while (flag == 1);
	gotoxy(13,10+2*i);
	system("pause");
}
                                                /************������סʱ����в���***********/
void fInputTime(struct room *head,struct ID *head1)
{
	struct room *p1;
	struct ID *x1;
	int i,n=0;
	char tran[5];
	int year,mon,day;
	printf("��������鷿��ͻ�����סʱ��:");
	gotoxy(34,0);
	printf("��");
	gotoxy(41,0);
	printf("��");
	gotoxy(46,0);
	printf("��");
	gotoxy(30,0);
	if (scanfPlus(tran,1,4,0) == 1)
		return;
	year = atoi(tran);
	gotoxy(38,0);
	if (scanfPlus(tran,1,2,0) == 1)
		return;
	mon = atoi(tran);
	gotoxy(43,0);
	if (scanfPlus(tran,1,2,0) == 1)
		return;
	day = atoi(tran);
	x1 = head1;
	while (x1 != NULL)
	{
		if (x1->year == year && x1->mon == mon && x1->day == day)
			n++;
		x1 = x1->next;
	}
	if (n == 0)
	{
	    MessageBox(NULL,"δ�鵽�˷�����Ϣ!","��ʾ",MB_ICONASTERISK);
		return;
	}
	form2(n);
	p1 = head;
	i = 0;
	while (p1 != NULL)
	{
		x1 = head1;
		while (x1 != NULL)
		{
			if (strcmp(p1->num,x1->num) == 0)
			{
				if (x1->year == year && x1->mon == mon && x1->day == day)
				{
					status(p1,x1);
					form3(p1,i);
					i++;
				}
			}
			x1 = x1->next;
		}
		p1 = p1->next;
	}
	gotoxy(13,10+2*i);
	system("pause");
}
                                                       /*****************������ס�������в���**************/
void fDays(struct room *head,struct ID *head1)
{
	struct room *p1;
	struct ID *x1;
	char tran[10];
	int rDays;
	int i,n=0;
	printf("��������鷿��ͻ���ס������:");
	if (scanfPlus(tran,1,9,0) == 1)
		return;
	rDays = atoi(tran);
	x1 = head1;
	while (x1 != NULL)
	{
		if (x1->numDay == rDays)
			n++;
		x1 = x1->next;
	}
	if (n == 0)
	{
	    MessageBox(NULL,"δ�鵽�˷�����Ϣ!","��ʾ",MB_ICONASTERISK);
		return;
	}
	form2(n);
	p1 = head;
	i = 0;
    while (p1 != NULL)
	{
		x1 = head1;
		while (x1 != NULL)
		{
			if (strcmp(p1->num,x1->num) == 0)
			{
				if (x1->numDay == rDays)
				{
					status(p1,x1);
					form3(p1,i);
					i++;
				}
			}
			x1 = x1->next;
		}
		p1 = p1->next;
	}
	gotoxy(13,10+2*i);
	system("pause");
}
                                                                  /****************����סһ��ķ�����ý��в���**********/
void fCost(struct room *head,struct ID *head1)
{
	struct room *p1;
	struct ID *x1;
	char rCost[10];
	int flag = 0,i,n = 0;
	printf("����������ҷ���ÿ��ķ���:");
	if (scanfPlus(rCost,1,9,0) == 1)
		return;
	p1 = head;
	while(p1 != NULL)
	{
		if (strstr(p1->cost,rCost) != 0)
			n++;
		p1 = p1->next;
	}
	if (n == 0)
	{
	    MessageBox(NULL,"δ�鵽�˷�����Ϣ!","��ʾ",MB_ICONASTERISK);
		return;
	}
	do
	{
		if (flag == 1)
			form2(i);
		p1 = head;
		i = 0;
		while (p1 != NULL)
		{
			if (strstr(p1->cost,rCost) != 0)
			{
				x1 = head1;
				while (x1 != NULL)
				{
					if (strcmp(p1->num,x1->num) == 0)
					{
						status(p1,x1);
						form3(p1,i);
						i++;
					}
					x1 = x1->next;
				}
				if (strcmp(p1->status,"����") == 0)
				{
					form3(p1,i);
					i++;
				}
			}
			p1 = p1->next;
		}
		flag++;
	}
	while (flag == 1);
	gotoxy(13,10+2*i);
	system("pause");
}
                                                      /***********������ס�ͻ��������в���************/
void fName(struct room *head,struct ID *head1)
{
	struct room *p1;
	struct ID *x1;
	char rName[20];
	int i,n = 0;
	printf("������Ҫ���ҵķ�����Ϣ����ס�ͻ���:");
	if (scanfPlus(rName,1,9,0) == 1)
		return;
	x1 = head1;
	while (x1 != NULL)
	{
		if (strstr(x1->inputName,rName) != 0)
			n++;
		x1 = x1->next;
	}
	if (n == 0)
	{
	    MessageBox(NULL,"δ�鵽�˷�����Ϣ!","��ʾ",MB_ICONASTERISK);
		return;
	}
	form2(n);
	p1 = head;
	i = 0;
	while (p1 != NULL)
	{
		x1 = head1;
		while (x1 != NULL)
		{
			if (strcmp(p1->num,x1->num) == 0)
			{
				if (strstr(x1->inputName,rName) != 0)
				{
					status(p1,x1);
					form3(p1,i);
					i++;
				}
			}
			x1 = x1->next;
		}
		p1 = p1->next;
	}
	gotoxy(13,10+2*i);
	system("pause");
}
                                                     /**********���ݵ绰������в���*********/
void fTel(struct room *head,struct ID *head1)
{
	struct room *p1;
	struct ID *x1;
	char rTel[12];
	int i,n = 0;
	printf("������Ҫ���ҵķ�����Ϣ�ĵ绰:");
	if (scanfPlus(rTel,1,11,3) == 1)
		return;
	x1 = head1;
	while (x1 != NULL)
	{
		if (strstr(x1->inputTel,rTel) != 0)
			n++;
		x1 = x1->next;
	}
	if (n == 0)
	{
	    MessageBox(NULL,"δ�鵽�˷�����Ϣ!","��ʾ",MB_ICONASTERISK);
		return;
	}
	form2(n);
	p1 = head;
	i = 0;
	while (p1 != NULL)
	{
		x1 = head1;
		while (x1 != NULL)
		{
			if (strcmp(p1->num,x1->num) == 0)
			{
				if (strstr(x1->inputTel,rTel) != 0)
				{
					status(p1,x1);
					form3(p1,i);
					i++;
				}
			}
			x1 = x1->next;
		}
		p1 = p1->next;
	}
	gotoxy(13,10+2*i);
	system("pause");
}
                                                     /************��¼������*****************/
struct ID *login()
{
	struct ID *head = NULL,*p;
	head = loginRead();
	int x,i;
	char t;
    A:system("cls");
	loginWrite(head);
    loginMenu();
	x = 9;
	i = 0;
	while (1)
	{
		t = arrows(x,'0','6');
		switch(t)
		{
		    case 72:
				     if (i > 0)
					 {
						 x = cColor(93,x,0);
					     if (x == 9)
							 puts("1.��¼");
						 else if (x == 11)
							 puts("2.ע��");
						 else if (x == 13)
							 puts("3.ע��");
						 else if (x == 15)
	                         puts("4.�����һ�");
						 else if (x == 17)
	                         puts("5.�޸�����");
						 else if (x == 19)
	                         puts("6.�ο͵�¼");
					     i--;
					 }
					 else
					 {
						 inversion(&i,93,&x,6,21,"0.�˳�");
					 }
					 break;
			case 80:
				     if (i < 6)
					 {
						 x = cColor(93,x,1);
	                     if (x == 11)
							 puts("2.ע��");
						 else if (x == 13)
							 puts("3.ע��");
						 else if (x == 15)
						     puts("4.�����һ�");
						 else if (x == 17)
						     puts("5.�޸�����");
						 else if (x == 19)
							 puts("6.�ο͵�¼");
						 else
							 puts("0.�˳�");
						 i++;
					 }
					 else
					 {
						 inversion(&i,93,&x,0,9,"1.��¼");
					 }
					 break;
			case 13: system("cls");
				     if (x == 9)
					 {
						 if ((p = sign(head)))
							 return p;            //��¼�󷵻ظ��˺ŵĻ�����Ϣ
					 }
					 if (x == 11)
						 head = accountName(head);
					 if (x == 13)
						 head = logout(head);
					 if (x == 15)
						 signFind(head);
					 if (x == 17)
						 changePassword(head);
					 if (x == 19)
						 visitor();
					 if (x == 21)
						 exit(0);
					 goto A;
			case 49:
				    system("cls");
					ShowCursor();
					if ((p = sign(head)))
						return p;
					goto A;
			case 50: system("cls");ShowCursor();head = accountName(head); goto A;
			case 51: system("cls");ShowCursor();head = logout(head); goto A;
			case 52: system("cls");ShowCursor();signFind(head); goto A;
			case 53: system("cls");ShowCursor();changePassword(head); goto A;
			case 54: system("cls");ShowCursor();visitor(); goto A;
			case 48: exit(0);
		}
	}
}
                                      /******��¼����˵�********/
void loginMenu()
{
	system("cls");
	form(6,7);
	gotoxy(92,7);
	puts("�쳾��ջ");
	gotoxy(93,11);
	puts("2.ע��");
	gotoxy(93,13);
	puts("3.ע��");
	gotoxy(93,15);
	puts("4.�����һ�");
	gotoxy(93,17);
	puts("5.�޸�����");
	gotoxy(93,19);
	puts("6.�ο͵�¼");
	gotoxy(93,21);
	puts("0.�˳�");
	gotoxy(70,23);
	puts("ע��:��¼�����ݵĹ����а�ESC����ֱ��ȡ��¼�뷵����һ��");
	gotoxy(93,9);
	red();
	puts("1.��¼");

}
                     /************���˻���Ϣд���ļ�*********/
void loginWrite(struct ID *head)
{
	FILE *fp;
	struct ID *p1;
	fp = fopen("�û�","wb");
	if (head == NULL)
		return;
	p1 = head;

	while (p1 != NULL)           //�����������ν��˻���Ϣд���ļ���
	{
		fwrite(p1,sizeof(struct ID),1,fp);
		p1 = p1->next;
	}
	fclose(fp);
}
                    /***************���ļ��е��˻���Ϣ����************/
struct ID *loginRead()
{
	FILE *fp;
	char ch;
	struct ID *head = NULL,*p1,*p2;          //��ͷָ���ʼ��Ϊ��
	if ((fp = fopen("�û�","rb")) == NULL)
		return head;
    A:p1 = (struct ID *)malloc(sizeof(struct ID));
	fread(p1,sizeof(struct ID),1,fp);
	if(feof(fp))          //�ж��ļ��Ƿ�Ϊ��
	{
		fclose(fp);
		return head;
	}

	if (head == NULL)                   //������������ԣ�ͷ����赥����ȡ
	{
		head = p1;
		p1->next = NULL;
		p2 = p1;
		goto A;
	}
	p2->next = p1;                       //�����������δ��ļ��ж�ȡ���ݵ�����
	p1->next = NULL;
	p2 = p1;
	goto A;
}
                               /***********��¼**********/
struct ID *sign(struct ID *head)
{
	int i = 2;
	struct ID *p1 = NULL,*p2;
	char accountt[20];
	char key1[20];
	char testGetCode[7];
	char code[7];
	if (head == NULL)
	{
		MessageBox(NULL,"δע���κ��˺���ע�������!","��ʾ",MB_ICONASTERISK);
		return NULL;
	}
    A:form(9,2);
	gotoxy(94,10);
	puts("��¼");
	gotoxy(82,12);
	puts("�˺�:");
	gotoxy(82,14);
	puts("����:");
    gotoxy(88,12);
	if (p1 == NULL)
	{
		if (scanfPlus(accountt,1,18,0) == 1)
			return NULL;
	}
	else
		puts(accountt);
	p1 = head;
	while(1)
	{
		if (strcmp(accountt,p1->account) == 0)
			break;
		p1 = p1->next;
		if (p1 == NULL)
		{
			MessageBox(NULL,"�޴��˺�����������!","����", MB_ICONHAND);
			system("cls");
			goto A;
		}
	}
	gotoxy(88,14);
	if (scanfPlus(key1,1,18,1) == 1)
		  return NULL;
    C:system("cls");
	form(9,2);
	gotoxy(94,10);
	printf("��֤");
    gotoxy(82,12);
	printf("��֤��:%s\n",randStr(testGetCode,4));
	gotoxy(82,14);
	printf("��������֤��(���ִ�Сд):");
	gotoxy(107,14);
	if (scanfPlus(code,1,4,0) == 1)
		return NULL;
	if (strcmp(testGetCode,code) != 0)
	{
		if (i>0)
		{
			system("cls");
			gotoxy(80,14);
			printf("��֤����������㻹��%d�λ�������������!",i);
			i--;
			gotoxy(80,15);
			system("pause");
		}
		else
		{
			MessageBox(NULL,"��֤������������Ѿ�û�л�����!����������һ������","����", MB_ICONHAND);
			system("cls");
			return NULL;
		}
		goto C;
	}
	if (strcmp(key1,p1->key) != 0)
	{
		if (i>0)
		{
			system("cls");
			gotoxy(80,14);
			printf("������������㻹��%d�λ������������룡",i);
			gotoxy(80,15);
			system("pause");
			system("cls");
			i--;
		}
		else
		{
			MessageBox(NULL,"��������������Ѿ�û�л�����!����������һ������","����", MB_ICONHAND);
			system("cls");
			return NULL;
		}
		goto A;
	}
	return p1;
}
                             /*************ע��***********/
struct ID *accountName(struct ID *head)
{
	struct ID *p1,*p2;
	char keyy[20];
	char protect[20];
	char numm[20],code[20];
	p1 = (struct ID *)malloc(sizeof(struct ID));
	printf("������ע���˻��ȼ�(����Աor��ͨ�û�):");
    C: if (scanfPlus(p1->power,1,10,0) == 1)
		   return head;
	if (strcmp(p1->power,"����Ա") != 0 && strcmp(p1->power,"��ͨ�û�") != 0 )
	{
		system("cls");
		printf("�Ƿ����룡����������:");
		goto C;
	}
	if (strcmp(p1->power,"����Ա") == 0)
	{
        G:printf("�����뼤����:");
		if (scanfPlus(code,1,19,3) == 1)
			return head;
		if (strcmp(code,"258711551") != 0)
		{
			MessageBox(NULL,"���뼤�������!����������","����", MB_ICONHAND);
			system("cls");
			goto G;
		}
	}

    B:printf("��������Ҫע����˺�(�˺�Ϊ8~18λ����������λ)��");
    if (scanfPlus(p1->account, 8, 18, 0) == 1)
		return head;
	p2 = head;
	while (1)
	{
		if(p2 == NULL)
			break;
		if(strcmp(p2->account,p1->account) == 0)
		{
			//printf("���˺��ѱ�ע�ᣡ����������");
			MessageBox(NULL,"���˺��ѱ�ע������������!","����", MB_ICONHAND);
			system("cls");
			goto B;
		}
		p2 = p2->next;
	}
	printf("���������֤������:");
	if (scanfPlus(p1->name,1,18,0) == 1)
		return head;
    F:printf("�������Ա�(��orŮ):");
	if (scanfPlus(p1->sex,1,2,0) == 1)
		return head;
	if (strcmp(p1->sex,"��") != 0 && strcmp(p1->sex,"Ů") != 0)
	{
		MessageBox(NULL,"�Ƿ���������������!","����", MB_ICONHAND);
		system("cls");
		goto F;
	}
    E:printf("���������֤��(18λ):");
	if (scanfPlus(p1->idnum,18,18,1) == 1)
		return head;
	p2 = head;
	while (p2 != NULL)
	{
		if (strcmp(p2->idnum,p1->idnum) == 0)
		{
			MessageBox(NULL,"�����֤���ѱ������˺Ű����������룡","����", MB_ICONHAND);
			system("cls");
			goto E;
		}
		p2 = p2->next;
	}
    printf("���ٴ��������֤��:");
    if (scanfPlus(numm,18,18,1) == 1)
		return head;
	if (strcmp(p1->idnum,numm) != 0)
	{
		MessageBox(NULL,"�����������֤�Ų�һ�����������룡","����", MB_ICONHAND);
		system("cls");
		goto E;
	}
    A:printf("����������(8~18λ):");
    if (scanfPlus(p1->key, 8, 18, 1) == 1)
		  return head;
	printf("���ٴ���������:");
	if (scanfPlus(keyy,8,18,1) == 1)
		return head;
	if (strcmp(keyy,p1->key) != 0)
	{
		MessageBox(NULL,"�����������벻һ�����������룡","����", MB_ICONHAND);
		system("cls");
		goto A;
	}
	puts("�ܱ�����:");
	D:printf("����ϲ���Ķ�����ʲô��(�ܱ�Ϊ8~18λ����������λ):");
    if (scanfPlus(p1->keyProtect,1,18,0) == 1)
		  return head;
	printf("���ٴ���������ϲ���Ķ���:");
	if (scanfPlus(protect,1,18,0) == 1)
		return head;
	if (strcmp(p1->keyProtect,protect) != 0)
	{
		system("cls");
		MessageBox(NULL,"���������ܱ���һ�����������룡","����", MB_ICONHAND);
		goto D;
	}
	MessageBox(NULL,"ע��ɹ�!","��ʾ", MB_ICONASTERISK);
	//p1->daymax = 0;
	p2 = head;
	if (head == NULL)
	{
		head = p1;
		p1->next = NULL;
		return head;
	}
	while (p2->next != NULL)
		p2 = p2->next;
	p2->next = p1;
	p1->next = NULL;
	return head;
}
                                /***************ע��**********/
struct ID *logout(struct ID *head)
{
	struct ID *p1,*p2,*p3;
	char delaccount[20];
	char key1[20];
	char protect[20];
	int i = 2;
	if (head == NULL)
	{
		MessageBox(NULL,"û�п�ע�����˻�!","��ʾ", MB_ICONASTERISK);
		return head;
	}
	A:printf("������ע���˻�:");
    if (scanfPlus(delaccount,1,18,0) == 1)
		  return head;
	p2 = head;
	while (p2 != NULL)
	{
		if (strcmp(delaccount,p2->account) == 0)
		{
			if (p2 == head)
			{
				printf("�������˻�����:");
                B:if (scanfPlus(key1,1,18,1) == 1)
					  return head;
				if (strcmp(key1,p2->key) != 0)
				{
					printf("�������!�㻹��%d�λ���:",i);
					if (i == 0)
					{
						MessageBox(NULL,"��������������Ѿ�û�л�����!����������һ���˵�","����", MB_ICONHAND);
						return head;
					}
					i--;
					goto B;
				}
				printf("����ϲ���Ķ�����ʲô:");
                E:if (scanfPlus(protect,1,18,0) == 1)
				  return head;
			    if (strcmp(protect,p2->keyProtect) != 0)
				{
				    printf("�ܱ����������!�㻹��%d�λ������ٴ�����:",i);
				    if (i == 0)
					{
				    	MessageBox(NULL,"�ܱ�����������Ѿ�û�л�����!����������һ���˵�","����", MB_ICONHAND);
					    return head;
					}
				    i--;
				    goto E;
				}
				MessageBox(NULL,"ע���ɹ�!","��ʾ", MB_ICONASTERISK);
				head = p2->next;
				free(p2);
				return head;
			}
			printf("�������˻�����:");
            C:if (scanfPlus(key1,1,18,1) == 1)
				  return head;
			if (strcmp(key1,p2->key) != 0)
			{
				printf("�������!�㻹��%d�λ������ٴ�����:",i);
				if (i == 0)
				{
					MessageBox(NULL,"��������������Ѿ�û�л�����!����������һ���˵�","����", MB_ICONHAND);
					return head;
				}
				i--;
				goto C;
			}
			i = 2;
			printf("����ϲ���Ķ�����ʲô:");
            D:if (scanfPlus(protect,1,18,0) == 1)
				  return head;
			if (strcmp(protect,p2->keyProtect) != 0)
			{
				printf("�ܱ����������!�㻹��%d�λ������ٴ�����:",i);
				if (i == 0)
				{
					MessageBox(NULL,"�ܱ�����������Ѿ�û�л�����!����������һ���˵�","����", MB_ICONHAND);
					return head;
				}
				i--;
				goto D;
			}
			p3->next = p2->next;
			free(p2);
			MessageBox(NULL,"ע���ɹ�!","��ʾ", MB_ICONASTERISK);
			return head;
	 	}
		p3 = p2;
		p2 = p2->next;
	}
	MessageBox(NULL,"ע��ʧ��!Ϊ��ѯ�����˻�����������","����", MB_ICONHAND);
	system("cls");
	goto A;
	return head;
}
                              /**************�����һ�**********/
void signFind(struct ID *head)
{
	struct ID *p1;
	char accountt[20];
	char protect[20],key1[20];
	int i = 2;
	if (head == NULL)
	{
		MessageBox(NULL,"���κ��˺���Ϣ!","��ʾ", MB_ICONASTERISK);
		return;
	}
	printf("��������Ҫ�һ�������˺�:");
	if (scanfPlus(accountt,1,18,0) == 1)
		return;
	p1 = head;
	while (p1 != NULL)
	{
		if(strcmp(accountt,p1->account) == 0)
		{
			puts("�ܱ�����:");
			puts("����ϲ���Ķ�����ʲô?");
			printf("�������:");
            A:if (scanfPlus(protect,1,18,0) == 1)
				return;
			if (strcmp(protect,p1->keyProtect) != 0)
			{
				printf("�ܱ����������!�㻹��%d�λ������ٴ�����:",i);
				if (i == 0)
				{
					MessageBox(NULL,"�ܱ�����������Ѿ�û�л�����!����������һ���˵�","����", MB_ICONHAND);
					return;
				}
				i--;
				goto A;
			}
			B:printf("������������(����8~18λ):");
            if (scanfPlus(p1->key,8,18,1) == 1)
				return;
			printf("���ٴ�����������:");
			if (scanfPlus(key1,8,18,1) == 1)
				return;
			if (strcmp(p1->key,key1) != 0)
			{

				MessageBox(NULL,"�����������벻һ�����������룡","����", MB_ICONHAND);
				system("cls");
				goto B;
			}
			MessageBox(NULL,"ע���ɹ�!","��ʾ", MB_ICONASTERISK);
			return;
		}
		p1 = p1->next;
	}
	MessageBox(NULL,"δ���������˺������Ƿ�������ȷ!","����", MB_ICONHAND);
}
                             /****************�޸�����**********/
void changePassword(struct ID *head)
{
	int i = 2;
	char accountt[20];
	char key1[20];
	struct ID *p1;
	printf("�������˺�:");
	if (scanfPlus(accountt,8,18,0) == 1)
		return;
	if (head == NULL)
	{
		MessageBox(NULL,"���κ��˺���Ϣ","��ʾ", MB_ICONASTERISK);
		return;
	}
	p1 = head;
	while (p1 != NULL)
	{
		if (strcmp(accountt,p1->account) == 0)
		{
			printf("��������˺�����:");
            A:if (scanfPlus(key1,8,18,1) == 1)
				  return;
			if (strcmp(key1,p1->key) != 0)
			{
				printf("�������!�㻹��%d�λ������ٴ�����:",i);
				if (i == 0)
				{
					MessageBox(NULL,"��������������Ѿ�û�л�����!����������һ���˵�","����", MB_ICONHAND);
					return;
				}
				i--;
				goto A;
			}
			printf("������������(����Ϊ8~18λ):");
            B:if (scanfPlus(p1->key,8,18,1) == 1)
				return;
			printf("���ٴ�����������:");
			if (scanfPlus(key1,8,18,1) == 1)
				return;
			if (strcmp(p1->key,key1) != 0)
			{
				MessageBox(NULL,"�����������벻һ�����������룡","����", MB_ICONHAND);
				system("cls");
				goto B;
			}
			return;
		}
		p1 = p1->next;
	}
	MessageBox(NULL,"δ���������˺������Ƿ�������ȷ!","����", MB_ICONHAND);
}
char *randStr(char str[], int n)
{
    int i,random;
    char strArray[59] = "abcdefghijkmnpqrstuvwxyzABCDEFGHIJKLMNPQRSTUVWXYZ123456789";
	srand(time(0)); //�ӵ�ǰʱ���������������
    for (i = 0; i < n; i++)
    {

        random = rand()%58;
        str[i] = strArray[random];     //�Ӵ��������������ȡ��
    }
    str[n] = '\0';
    return str;                          //���������׵�ַ
}
                                                  /******************�û���*****************/
int user(struct room *head,struct ID *p,struct ID *head1)
{
	struct room *p1;
	int x,i = 0;
	char t;
	system("cls");
	gotoxy(80,14);
	if (strcmp(p->sex,"��") == 0)
		printf("�𾴵�%s������ӭ�����ٺ쳾��ջ\n",p->name);
	else
		printf("�𾴵�%sŮʿ��ӭ�����ٺ쳾��ջ\n",p->name);
	gotoxy(80,15);
	system("pause");
	system("cls");
	p1 = head;
	while (p1 != NULL)
	{
		if (strcmp(p1->num,p->num) == 0)
		{
			remind(p,head1);
			break;
		}
		p1 = p1->next;
	}

    A:system("cls");
	//write(head);
	umenu(p);
	head = read();
	head1 = loginRead();
	x = 12;
	while (1)
	{
		t = arrows(x,'0','5');
		switch(t)
		{
		    case 72:
				     if (i > 0)
					 {
						 x = cColor(91,x,0);
					     if (x == 12)
							 puts("1.����");
						 else if (x == 14)
							 puts("2.�˷�");
						 else if (x == 16)
							 puts("3.�鿴�Լ��Ķ�����Ϣ");
						 else if (x == 18)
	                         puts("4.�޸��Լ��Ķ�����Ϣ");
						 else
							 puts("5.�˳���¼");
					     i--;
					 }
					 else
					 {
						 inversion(&i,91,&x,5,22,"0.�˳�ϵͳ");
					 }
					 break;

			case 80:
				     if (i < 5)
					 {
						 x = cColor(91,x,1);
	                     if (x == 14)
							 puts("2.�˷�");
						 else if (x == 16)
							 puts("3.�鿴�Լ��Ķ�����Ϣ");
						 else if (x == 18)
						     puts("4.�޸��Լ��Ķ�����Ϣ");
						 else if (x == 20)
						     puts("5.�˳���¼");
						 else
							 puts("0.�˳�ϵͳ");
						 i++;
					 }
					 else
					 {
						 inversion(&i,91,&x,0,12,"1.����");
					 }
					 break;
			case 13: system("cls");
				     if (x == 12)
						 reserve(head,p,head1);
					 else if (x == 14)
					 {
						 out(head,p,head1);
						 loginWrite(head1);
					 }
					 else if (x == 16)
						 userLook(head,p,head1);
					 else if (x == 18)
						 userChange(head,p,head1);
					 else if (x == 20)
						 return 0;
					 else
						 exit(0);
					 goto A;

			case 49: system("cls");reserve(head,p,head1); goto A;
			case 50: system("cls");out(head,p,head1);loginWrite(head1); goto A;
			case 51: system("cls");userLook(head,p,head1); goto A;
			case 52: system("cls");userChange(head,p,head1); goto A;
			case 53: return 0;
			case 48: exit(0);
		}
	}

}
                         /******************�û��˲˵�**************************/
void umenu(struct ID *p)
{
	struct ID *head,*p1;
	char name[10];
	head = loginRead();
	p1 = head;
	while (p1 != NULL)
	{
		if (strcmp(p->account,p1->account) == 0)
			break;
		p1 = p1->next;
	}
	if (strcmp(p1->checkOut,"���˷�") == 0)
	{
		/*gotoxy(80,14);
		printf("���ύ���˷�������ͨ������ӭ���ٴ���齱��Ƶ�\n\n");*/
		MessageBox(NULL,"���ύ���˷�������ͨ��!��ӭ���ٴ���齱���ջ","��ʾ", MB_ICONASTERISK);
		strcpy(p1->checkOut,"��");
		loginWrite(head);
		/*gotoxy(80,15);
		system("pause");*/
		system("cls");
	}
	if (strcmp(p1->checkOut,"�˷�ʧ��") == 0)
	{
		gotoxy(80,14);
		puts("����˷����뱻������ԭ������:");
		gotoxy(80,15);
		puts(p1->information);
		gotoxy(80,19);
		printf("���б�Ҫ����ϵ����Ա�������������Ա�绰Ϊ:xxxxxxxxxxx\n\n");
		strcpy(p1->checkOut,"��");
		loginWrite(head);
		gotoxy(80,20);
		system("pause");
		system("cls");
	}
	form(9,6);
	gotoxy(92,10);
	puts("�쳾��ջ");

	gotoxy(91,14);
	puts("2.�˷�");
	gotoxy(91,16);
	puts("3.�鿴�Լ��Ķ�����Ϣ");
	gotoxy(91,18);
	puts("4.�޸��Լ��Ķ�����Ϣ");
	gotoxy(91,20);
	puts("5.�˳���¼");
	gotoxy(91,22);
	puts("0.�˳�ϵͳ");
	red();
	gotoxy(91,12);
	puts("1.����");
}
                                               /****************�û�Ԥ������***************/
void reserve(struct room *head,struct ID *p,struct ID *head1)
{
	struct room *p1,*p2;
	struct ID *x1;
	char tran[10];
	char rNum[10];
	int flag = 1,n=0,i,d;
	int times[2][13] =
	{
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
	if (head == NULL)
	{
		MessageBox(NULL,"�ÿ�ջû¼�뷿����Ϣ���Ժ�����!","��ʾ", MB_ICONASTERISK);
		return;
	}
	x1 = head1;
	while (x1 != NULL)
	{
		if (strcmp(x1->account,p->account) == 0)
			break;
		x1 = x1->next;
	}
	p1 = head;
	while (p1 != NULL)
	{
		if (strcmp(p1->num,x1->num) == 0)
		{
			MessageBox(NULL,"���Ѿ�Ԥ���˿�ջ���������ظ�Ԥ��!","��ʾ", MB_ICONASTERISK);
			return;
		}
		n++;
		p1 = p1->next;
	}
	p1 = head;
	while (p1 != NULL)
	{
		if (strcmp(p1->status,"�ѱ�Ԥ��") == 0)
			strcpy(p1->status,"����");
		p1 = p1->next;
	}
	puts("��������Ҫ��ס������:");
	gotoxy(25,0);
	printf("��");
	gotoxy(29,0);
	printf("��");
	gotoxy(33,0);
	printf("��");
	gotoxy(21,0);
	if (scanfPlus(tran,4,4,3) == 1)
		return;
    p->years = p->year = atoi(tran);
	gotoxy(27,0);
	if (scanfPlus(tran,1,2,3) == 1)
		return;
	p->month = p->mon = atoi(tran);
	gotoxy(31,0);
	if (scanfPlus(tran,1,2,3) == 1)
		return;
	d = p->day = atoi(tran);
    B:printf("��������ס����:");
	if (scanfPlus(tran,1,15,3) == 1)
		return;
	p->days = p->numDay = atoi(tran);
	if (p->days == 0)
	{
		MessageBox(NULL,"�Ƿ��������������룡","����", MB_ICONHAND);
		system("cls");
		goto B;
	}
	while (1)
	{
		i = p->years % 4 == 0 && p->years % 100 != 0 || p->years % 400 == 0;
		if (p->days + d > times[i][p->month])
		{
			p->days = p->days + d - times[i][p->month];
			if (p->month != 12)  p->month++;
			else
			{
				p->years++;
				p->month = 1;
			}
			d = 0;
		}
		if (d == 0)
			break;
		else
		{
			p->days = p->days + d;
			break;
		}
	}
	p = tranday(p);
	p1 = head;
	while (p1 != NULL)
	{
		x1 = head1;
		while (x1 != NULL)
		{
			if (strcmp(x1->num,p1->num) == 0)
			{

				if (p->daymin < x1->daymin && p->daymax > x1->daymin)
					strcpy(p1->status,"�ѱ�Ԥ��");
				else if (p->daymin > x1->daymin && p->daymax < x1->daymax)
					strcpy(p1->status,"�ѱ�Ԥ��");
				else if (p->daymin < x1->daymax && p->daymax >x1->daymax)
					strcpy(p1->status,"�ѱ�Ԥ��");
				else if (p->daymin == x1->daymin)
					strcpy(p1->status,"�ѱ�Ԥ��");
			}
			x1 = x1->next;
		}
		p1 = p1->next;
	}
    A:i = form4(n,head);
	gotoxy(63,10+2*i);
	printf("����������Ҫ�Ķ��ķ���ķ����:");
	if (scanfPlus(rNum,1,9,0) == 1)
		return;
	p1 = head;
	while(p1 != NULL)
	{
		if (strcmp(p1->num,rNum) == 0 )
		{
			if (strcmp(p1->status,"����") != 0)
			{
				flag = 2;
				break;
			}
			else
			{
				flag = 0;
				break;
			}

		}
		p1 = p1->next;
	}
	if (flag == 1)
	{
		MessageBox(NULL,"δ�鵽�˷�����Ϣ����������!","��ʾ", MB_ICONASTERISK);
		system("cls");
		goto A;
	}
	if (flag == 2)
	{
		MessageBox(NULL,"�÷����ѱ�Ԥ������������!","��ʾ", MB_ICONASTERISK);
		system("cls");
		goto A;
	}
	x1 = head1;
	while (x1 != NULL)
	{
		if (strcmp(x1->idnum,p->idnum) == 0)
		{
			strcpy(x1->num,p->num);
		    x1->year = p->year;
			x1->years = p->years;
			x1->mon = p->mon;
			x1->month = p->month;
			x1->day = p->day;
			x1->days = p->days;
		    x1->daymin = p->daymin;
			x1->daymax = p->daymax;
			x1->numDay = p->numDay;
			break;
		}
		x1 = x1->next;
	}
	gotoxy(63,12+2*i);
	puts("����д���»�����Ϣ:");
	gotoxy(63,13+2*i);
	printf("����:");
	if (scanfPlus(x1->inputName,1,9,0) == 1)
		return;
	gotoxy(63,14+2*i);
	printf("�绰:");
	if (scanfPlus(x1->inputTel,11,11,3) == 1)
		return;
	MessageBox(NULL,"�����ɹ�!","��ʾ", MB_ICONASTERISK);
	strcpy(x1->num,rNum);
	write(head);
	loginWrite(head1);
}
                                                 /**************�û��˷���*************/
void out(struct room *head,struct ID *p,struct ID *head1)
{
	struct room *p1,*p2;
	struct ID *x1;
	char judge[3];
	int cost;
	int s = time(0);
	int d = s/86400 - 10957;
	if (head == NULL)
	{
		MessageBox(NULL,"����Ա��δ¼���κη�����Ϣ!","��ʾ", MB_ICONASTERISK);
		return;
	}
	x1 = head1;
	while (x1 != NULL)
	{
		if (strcmp(x1->idnum,p->idnum) == 0)
			break;
		x1 = x1->next;
	}
	if (strcmp(x1->checkOut,"��") == 0)
	{
		MessageBox(NULL,"���������˷���ȴ�����Ա���!","��ʾ", MB_ICONASTERISK);
		return;
	}
	p1 = head;
	while (p1 != NULL)
	{
		if (strcmp(p1->num,x1->num) == 0)
		{
			strcpy(p1->name,x1->inputName);
			strcpy(p1->tel,x1->inputTel);
			strcpy(p1->status,"�ѱ�Ԥ��");
			p1->year = x1->year;
			p1->mon = x1->mon;
			p1->day = x1->day;
			p1->days = x1->numDay;
            A:printf("��˶���ķ�����Ϣ�Ƿ���ȷ\n");
			form2(1);
			form3(p1,0);
			gotoxy(13,13);
			s = time(0);
			d = s/86400 - 10956;
			cost = atoi(p1->cost);
			x1->cost = (d - x1->daymin)*cost;
			if (x1->daymax < d)
				printf("���Ѿ����������Ԥ���������ס�޷���Ϊ%dԪ",x1->cost);
			else if (x1->daymax > d)
				printf("���ס��ʱ�仹δ���������˷�ס�޷���Ϊ%dԪ",x1->cost);
			else printf("���ס�޷���Ϊ%dԪ",x1->cost);
			gotoxy(13,14);
			if(MessageBox(NULL,"�Ƿ��˷�","ѯ��",MB_ICONASTERISK|MB_OKCANCEL)!=IDCANCEL)
			{
				strcpy(x1->checkOut,"��");
				MessageBox(NULL,"�������ύ��ȴ�����Ա���!","��ʾ", MB_ICONASTERISK);
				return;
			}
			MessageBox(NULL,"��ȡ���˷�����!","��ʾ", MB_ICONASTERISK);
			return;
		}
		p1 = p1->next;
	}
	MessageBox(NULL,"�㻹δԤ���κη���!","��ʾ", MB_ICONASTERISK);
}
void userLook(struct room *head,struct ID *p,struct ID *head1)
{
	struct ID *x1;
	struct room *p1;
	p1 = head;
	x1 = head1;
	while (x1 != NULL)
	{
		if (strcmp(x1->account,p->account) == 0)
			break;
		x1 = x1->next;
	}
	p1 = head;
	while (p1 != NULL)
	{
		if (strcmp(x1->num,p1->num) == 0)
			break;
		p1 = p1->next;
	}
	if (p1 == NULL)
	{
		MessageBox(NULL,"�㻹δԤ���κη�����Ԥ�����ٲ鿴!","����", MB_ICONEXCLAMATION );
		return;
	}
	status(p1,x1);
	form2(1);
	form3(p1,0);
	gotoxy(13,12);
	system("pause");
}
                                   /******�û���Ϣ����*******/
void userChange(struct room *head,struct ID *p,struct ID *head1)
{
	int x = 11,i = 0;
	char t;
    A:system("cls");
	loginWrite(head1);
	head1 = loginRead();
    userChangeMenu();
	while (1)
	{
		t = arrows(x,'0','3');
		switch(t)
		{
		    case 72:
				     if (i>0)
					 {
						 x = cColor(90,x,0);
					     if (x == 11)
							 puts("1.��סʱ�������");
						 else if (x == 13)
							 puts("2.��ס�ͻ�����");
						 else
							 puts("3.�绰");
					     i--;
					 }
					 else
						 inversion(&i,90,&x,3,17,"0.������һ������");
					 break;
			case 80:
				     if (i<3)
					 {
						 x = cColor(90,x,1);
	                     if (x == 13)
							 puts("2.��ס�ͻ�����");
						 else if (x == 15)
							 puts("3.�绰");
						 else
							 puts("0.������һ������");
						 i++;
					 }
					 else
						 inversion(&i,90,&x,0,11,"1.��סʱ�������");
					 break;
			case 13: system("cls");
				     if (x == 11)
						 cInputTime(head,p,head1);
					 else if (x == 13)
						 cInputName(head,p,head1);
					 else if (x == 15)
						 cUserTel(head,p,head1);
					 else
						 return;
					 goto A;
			case 49: system("cls");ShowCursor();cInputTime(head,p,head1); goto A;
			case 50: system("cls");ShowCursor();cInputName(head,p,head1);goto A;
			case 51: system("cls");ShowCursor();cUserTel(head,p,head1);goto A;
			case 48: return;
		}
	}
}
                                      /*************�û���Ϣ���Ĳ˵�********/
void userChangeMenu()
{
	form(8,4);
	gotoxy(87,9);
	puts("��ջ�ͻ���Ϣ����");
	gotoxy(90,13);
	puts("2.��ס�ͻ�����");
	gotoxy(90,15);
	puts("3.�绰");
	gotoxy(90,17);
	puts("0.������һ������");
	gotoxy(90,11);
	red();
	puts("1.��סʱ�������");
}
struct ID *userAmend(struct room *head,struct ID *p,struct ID *head1)
{
	struct room *p1;
	struct ID *x1;
	int flag = 0;
	x1 = head1;
	while (x1 != NULL)
	{
		if (strcmp(x1->idnum,p->idnum) == 0)
			break;
		x1 = x1->next;
		flag = 1;
	}
	if (flag == 1)
	{
		MessageBox(NULL,"�㻹δԤ���κη���!","����",MB_ICONHAND);
		return NULL;
	}
	p1 = head;
	while (p1 != NULL)
	{
		if (strcmp(p1->num,x1->num) == 0)
		{
			status(p1,x1);
			break;
		}
		p1 = p1->next;
	}
	printf("��Ķ�����Ϣ����");
	form2(1);
	form3(p1,0);
	return x1;
}
                                   /***********�û���סʱ���޸�***********/
void cInputTime(struct room *head,struct ID *p,struct ID *head1)
{
	struct ID *x1,*x2;
	struct room *p1;
	char tran[5];
	int year,mon,day;
	int years,month,days,numDay;
	int daymin = 0,daymax = 0;
	int i;
	int leap;
	int times[2][13] =
	{
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
	if ((x1 = userAmend(head,p,head1)) == NULL)
		return;
	gotoxy(13,11);
	printf("�������޸ĺ����סʱ��:");
	gotoxy(41,11);
	printf("��");
	gotoxy(46,11);
	printf("��");
	gotoxy(50,11);
	printf("��");
	gotoxy(37,11);
	if (scanfPlus(tran,4,4,3) == 1)
		return;
	years = year = atoi(tran);
	gotoxy(43,11);
	if (scanfPlus(tran,1,2,3) == 1)
		return;
	month = mon = atoi(tran);
	gotoxy(48,11);
	if (scanfPlus(tran,1,2,3) == 1)
		return;
	days = day = atoi(tran);
    A:printf("�������޸ĺ�������:");
	if (scanfPlus(tran,1,9,3) == 1)
		return;
	numDay = atoi(tran);
	if (numDay == 0)
	{
		MessageBox(NULL,"�Ƿ��������������룡","����", MB_ICONHAND);
		system("cls");
		goto A;
	}
	while (1)
	{
		i = years % 4 == 0 && years % 100 != 0 || years % 400 == 0;
		if (days + numDay > times[i][p->month])
		{
			days = days + numDay - times[i][p->month];
			if (month != 12)  month++;
			else
			{
				years++;
				month = 1;
			}
			numDay = 0;
		}
		if (numDay == 0)
			break;
		else
		{
			days = days + numDay;
			break;
		}
	}
	for (i = 2000; i < p->year; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			daymin += 366;
		else
		    daymin += 365;
	}
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < mon; i++)
		daymin += times[leap][i];
	daymin += day;
	for (i = 2000; i < years; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			daymax += 366;
		else
			daymax += 365;
	}
	leap = years % 4 == 0 && years % 100 != 0 || years % 400 == 0;
	for (i = 1; i < month; i++)
		daymax += times[leap][i];
	daymax += days;
	p1 = head;
	while (p1 != NULL)
	{
		x2 = head1;
		while (x2 != NULL)
		{
			if (strcmp(x2->num,p1->num) == 0)
			{

				if (daymin < x2->daymin && daymax > x2->daymin && x2->num != x1->num)
				{
					MessageBox(NULL,"�޸�ʧ�ܸ�ʱ��η����ѱ�Ԥ��!","����",MB_ICONHAND);
					return;
				}
				else if (daymin > x1->daymin && daymax < x2->daymax && x2->num != x1->num)
				{
					MessageBox(NULL,"�޸�ʧ�ܸ�ʱ��η����ѱ�Ԥ��!","����",MB_ICONHAND);
					return;
				}
				else if (daymin < x2->daymax && daymax >x2->daymax && x2->num != x1->num)
				{
					MessageBox(NULL,"�޸�ʧ�ܸ�ʱ��η����ѱ�Ԥ��!","����",MB_ICONHAND);
					return;
				}
				else if (daymin == x2->daymin && x2 != p && x2->num != x1->num)
				{
					MessageBox(NULL,"�޸�ʧ�ܸ�ʱ��η����ѱ�Ԥ��!","����",MB_ICONHAND);
					return;
				}

			}
			x2 = x2->next;
		}
		p1 = p1->next;
	}
	x1->year = year;
	x1->mon = mon;
	x1->day = day;
	x1->numDay = numDay;
	x1->daymin = daymin;
	x1->daymax = daymax;
	MessageBox(NULL,"�޸ĳɹ�!","��ʾ",MB_ICONASTERISK);
}
                                              /**********�û���ס�����޸�***********/
void cInputName(struct room *head,struct ID *p,struct ID *head1)
{
	struct ID *x1;
	if ((x1 = userAmend(head,p,head1)) == NULL)
		return;
	gotoxy(13,11);
	printf("�������޸ĺ����ס�ͻ�����:");
	if (scanfPlus(x1->inputName,1,9,0) == 0)
		return;
	MessageBox(NULL,"�޸ĳɹ�!","��ʾ",MB_ICONASTERISK);
}
                                             /**********�û���ס�绰�޸�**************/
void cUserTel(struct room *head,struct ID *p,struct ID *head1)
{
	struct ID *x1;
	if ((x1 = userAmend(head,p,head1)) == NULL)
		return;
	gotoxy(13,11);
	printf("�������޸ĺ�ĵ绰:");
	if (scanfPlus(x1->inputName,1,9,0) == 0)
		return;
	MessageBox(NULL,"�޸ĳɹ�!","��ʾ",MB_ICONASTERISK);
}
                                 /***************�οͶ�*************/
void visitor()
{
	int x,i;
	char t;
    A:system("cls");
	x = 12;
	i = 0;
    viewMenu();
	while (1)
	{
		t = arrows(x,'0','2');
		switch(t)
		{
		    case 72:
				     if (i>0)
					 {
						 x = cColor(89,x,0);
					     if (x == 12)
							 puts("1.�鿴������Ϣ");
						 else
							 puts("2.��¼");
					     i--;
					 }
					 else
						 inversion(&i,89,&x,2,16,"0.�˳�ϵͳ");
					 break;
			case 80:
				     if (i<2)
					 {
						 x = cColor(89,x,1);
	                     if (x == 14)
							 puts("2.��¼");
						 else
							 puts("0.�˳�ϵͳ");
						 i++;
					 }
					 else
						 inversion(&i,89,&x,0,12,"1.�鿴������Ϣ");
					 break;
			case 13: system("cls");
				     if (x == 12)
						 viewLook();
					 else if (x == 14)
						 return;
					 else
						 exit(0);
					 goto A;
			case 49: system("cls");ShowCursor();viewLook(); goto A;
			case 50: return;
			case 48: exit(0);
		}
	}
}
                                    /**************�οͲ˵�***************/
void viewMenu()
{
	system("cls");
	form(9,3);
	gotoxy(86,10);
	puts("�ף���ӭ�������ٱ��Ƶ�");
	gotoxy(89,14);
	puts("2.��¼");
	gotoxy(89,16);
	puts("0.�˳�ϵͳ");
    gotoxy(89,12);
	red();
	puts("1.�鿴������Ϣ");
}
                 /***************�οͶ˷�����Ϣ�鿴******************/
void viewLook()
{
	int i,n = 0;
	int s = time(0);
	int d = s/86400 - 10957;
	struct ID *head1,*x1,*x2;
	struct room *head,*p1,*p2;
	head = read();
	head1 = loginRead();
	if (head == NULL)
	{
		system("cls");
		gotoxy(80,14);
		printf("���κη�����Ϣ!");
		gotoxy(80,15);
		system("pause");
		return;
	}
	gotoxy(100,1);
	printf("���������Ϣ");
	p2 = head;
	while (p2 != NULL)
	{
		x1 = head1;
		while (x1 != NULL)
		{
			if (x1->daymin <= d && x1->daymax > d && strcmp(x1->num,p2->num) == 0)
			{
				strcpy(p2->status,"�ѱ�Ԥ��");
				break;
			}
			x1 = x1->next;
		}
		n++;
		p2 = p2->next;
	}
	i = form4(n,head);
    gotoxy(63,10+2*i);
	p2 = head;
	while (p2 != NULL)
	{
		strcpy(p2->status,"����");
		p2 = p2->next;
	}
	system("pause");
}

                                                     /***********�Ľ������뺯��************/
int scanfPlus(char *st,int m,int n,int x)     //st���ַ�����������m������ַ�����̳��ȣ�n������ַ��������,x������ʲô��ʽ��ʾ�ַ���
{
	int i=0;
	char ch;
	while(1)
	{
		ch = getch();
		if (ch == 27)        // �ж������Ƿ�ΪESC��
			return 1;
		if (ch == 13)         //�ж������Ƿ�Ϊ�س���
		{
			if (i>m-1)
			{
				st[i] = '\0';
				printf("\n");
				return 0;
			}
			continue;
		}
		if (ch == 8)        //�ж������Ƿ�ΪBACKSPACE��
		{
			if (i>0)
			{
				if (st[i-1]< 0)  //�ж�����BACKSPACE��ǰһ�����Ƿ�Ϊ����
				{
					printf("\b\b  \b\b");  //����ռ�����ֽ�
					i = i-2;
				}
				else
				{
					printf("\b \b");
			        i--;
				}
			}
			continue;
		}
		if (ch == -32)
		{
			getch();
			continue;
		}
		if (ch == 9)
			continue;
		if (ch < 0 && x == 1)       //��x=1ʱֻ�������ַ��������뺺��
			continue;
		if (x == 3)                 //��x=3ʱֻ����������
			if (ch < 47 || ch >58)
				continue;
		if (i<n)
		{
			if (x == 0 || x == 3) printf("%c",ch);
			else  printf("*");    //��x=1 ����"*"��ʾ����
			st[i] = ch;
			i++;
		}
		else
			continue;
	}
}
                                 /************���ع��**********/
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;          //Windows.hͷ�ļ����ýṹ��
	cursor.bVisible = FALSE;           //����ʾ���(TRUEΪ��ʾ��FALSEΪ����ʾ)
	cursor.dwSize = sizeof(cursor);      //���ĸ߶ȣ�����̨һ���ַ��ĸ߶�Ϊ100�����ĸ߶�Ϊ1��100
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    //��ȡ��׼���(����̨)���
	SetConsoleCursorInfo(handle, &cursor);            //�ñ�׼���(����̨)���ع��
}
                                /************��ʾ���*********/
void ShowCursor()
{
	CONSOLE_CURSOR_INFO cursor;          //Windows.hͷ�ļ����ýṹ��
	cursor.bVisible = TRUE;           //����ʾ���(TUREΪ��ʾ��FALSEΪ����ʾ)
	cursor.dwSize = sizeof(cursor);      //���ĸ߶ȣ�����̨һ���ַ��ĸ߶�Ϊ100�����ĸ߶�Ϊ1��100
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    //��ȡ��׼���(����̨)���
	SetConsoleCursorInfo(handle, &cursor);            //�ñ�׼���(����̨)���ع��
}
                             /****************���ؽ�����**********/
void load()
{
    float p; //�������̶�
    float progLen; //�����ܺ�ʱ
    int i, j;
    progLen = 15.0;
    for (i=1; i<=progLen; i++)
	{
        system ("cls");
        p = (i/progLen)*LEN; //�������ǰ����֮�ڽ������ı���
        gotoxy(80,10);
		for (j=1; j<=(int)(p+0.5); j++) //��ӡ��ִ�п̶�
            printf ("��");
        for (j=1; j<=LEN-(int)(p+0.5); j++) //��ӡ��ִ�п̶�
		{
            printf ("��");
			HideCursor();
		}
        printf (" %.1f%%", (i/progLen)*100); //�������ǰ���ȵİٷֱ�
        Sleep(200);
    }
   // putchar ('\n');
	gotoxy(86,12);
	printf("�������");
	Sleep(150);
   // getch ();
    return;
}
                                   /************�˵�����ӡ**********/
void form(int x,int n)
{
	int i;
    gotoxy(80,x);
	puts("���������������������������������������������������������������� ");
	gotoxy(80,x+1);
	puts("��                              �� ");
	for (i=0 ;i<n ;i++)
	{
	    gotoxy(80,x+2+2*i);
		puts("���������������������������������������������������������������� ");
    	gotoxy(80,x+3+2*i);
	    puts("��                              ��");
	}
	gotoxy(80,x+2+2*i);
	puts("����������������������������������������������������������������");
}
                                      /*********����������Ϣ����ӡ************/
void form2(int n)
{
	int i;
	gotoxy(13,5);
	puts("���������������������������������Щ��������������������������������Щ������������������������������Щ������������������������������Щ������������������������������Щ������������������������������Щ������������������������������Щ������������������������������Щ������������������������������Щ�������������������������������");
	gotoxy(13,6);
	puts("��               ��                ��               ��               ��               ��               ��               ��               ��               ��               ��");
    for (i = 0;i < n ;i++)
	{
		gotoxy(13,7+2*i);
		puts("���������������������������������੤�������������������������������੤�����������������������������੤�����������������������������੤�����������������������������੤�����������������������������੤�����������������������������੤�����������������������������੤�����������������������������੤������������������������������");
		gotoxy(13,8+2*i);
		puts("��               ��                ��               ��               ��               ��               ��               ��               ��               ��               ��");
	}
    gotoxy(13,7+2*i);
	puts("���������������������������������ة��������������������������������ة������������������������������ة������������������������������ة������������������������������ة������������������������������ة������������������������������ة������������������������������ة������������������������������ة�������������������������������");
	gotoxy(19,6);
	printf("�����");
	gotoxy(36,6);
	printf("����");
	gotoxy(53,6);
	printf("λ��");
	gotoxy(67,6);
	printf("����״̬");
	gotoxy(85,6);
	printf("��ס");
	gotoxy(99,6);
	printf("��סʱ��");
	gotoxy(117,6);
	printf("����");
	gotoxy(133,6);
	printf("����(��)");
	gotoxy(147,6);
	printf("��ס�ͻ�");
	gotoxy(165,6);
	printf("�绰");
}
                                    /**************����������Ϣ��ӡ***********/
void form3(struct room *p1,int i)
{
	gotoxy(19,8+2*i);
    printf("%s",p1->num);
	gotoxy(34,8+2*i);
	printf("%s",p1->type);
	gotoxy(52,8+2*i);
	printf("%s",p1->site);
	gotoxy(68,8+2*i);
	printf("%s",p1->status);
	gotoxy(85,8+2*i);
	printf("%s",p1->check);
	gotoxy(96,8+2*i);
	if (p1->year  == 1)
		printf("��");
	else
	{
		printf("%d",p1->year);
		fputs("-",stdout);
		printf("%d",p1->mon);
		fputs("-",stdout);
		printf("%d",p1->day);
	}
	gotoxy(115,8+2*i);
	printf("%d",p1->days);
	gotoxy(133,8+2*i);
	printf("%s",p1->cost);
	gotoxy(147,8+2*i);
	printf("%s",p1->name);
	gotoxy(161,8+2*i);
	printf("%s",p1->tel);
}
                                              /******���䲿����Ϣ������ݴ�ӡ******/
int form4(int n,struct room *head)
{
	struct room *p2;
	int i;
	gotoxy(63,5);
	puts("���������������������������������Щ��������������������������������Щ������������������������������Щ������������������������������Щ�������������������������������");
	gotoxy(63,6);
	puts("��               ��                ��               ��               ��               ��");
    for (i = 0;i < n ;i++)
	{
		gotoxy(63,7+2*i);
		puts("���������������������������������੤�������������������������������੤�����������������������������੤�����������������������������੤������������������������������");
		gotoxy(63,8+2*i);
		puts("��               ��                ��               ��               ��               ��");
	}
    gotoxy(63,7+2*i);
	puts("���������������������������������ة��������������������������������ة������������������������������ة������������������������������ة�������������������������������");
	gotoxy(69,6);
	printf("�����");
	gotoxy(86,6);
	printf("����");
	gotoxy(103,6);
	printf("λ��");
	gotoxy(117,6);
	printf("����״̬");
	gotoxy(135,6);
	printf("����(��)");
	p2 = head;
	i = 0;
	while (p2 != NULL)
	{
		    gotoxy(70,8+2*i);
		    printf("%s",p2->num);
		    gotoxy(85,8+2*i);
			printf("%s",p2->type);
			gotoxy(103,8+2*i);
			printf("%s",p2->site);
			gotoxy(117,8+2*i);
			printf("%s",p2->status);
			gotoxy(135,8+2*i);
			printf("%s",p2->cost);
			p2 = p2->next;
			i++;
	}
	return i;
}
                                             /*************������ת��Ϊ����**********/
struct ID *tranday(struct ID *p)
{
	int i;
	int leap;
	int times[2][13] =
	{
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
	p->daymin = 0;
    p->daymax = 0;
	for (i = 2000; i < p->year; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			p->daymin += 366;
		else
		p->daymin += 365;

	}
	leap = p->year % 4 == 0 && p->year % 100 != 0 || p->year % 400 == 0;
	for (i = 1; i < p->mon; i++)
		p->daymin += times[leap][i];
	p->daymin += p->day;
	for (i = 2000; i < p->years; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			p->daymax += 366;
		else
			p->daymax += 365;

	}
	leap = p->years % 4 == 0 && p->years % 100 != 0 || p->years % 400 == 0;
	for (i = 1; i < p->month; i++)
		p->daymax += times[leap][i];
	p->daymax += p->days;
	return p;
}
                                                   /***********������Ϣ����*************/
void status(struct room *p1,struct ID *x1)
{
	strcpy(p1->status,"�ѱ�Ԥ��");
	strcpy(p1->name,x1->inputName);
	strcpy(p1->tel,x1->inputTel);
	p1->year = x1->year;
	p1->mon = x1->mon;
	p1->day = x1->day;
	p1->days = x1->numDay;
}
                                             /**************���÷�����Ϣ************/
void reset(struct room *head)
{
	struct room *p2;
	p2 = head;
	while (p2 != NULL)
	{
		strcpy(p2->status,"����");
		strcpy(p2->name,"��");
		strcpy(p2->tel,"��");
		strcpy(p2->name,"��");
	    p2->year = 1;
		p2->days = 0;
		p2 = p2->next;
	}
}
                                            /*************��ӡ��ͷ*********/
int arrows(int x,char min,char max)
{
	char t;
	HideCursor();
	gotoxy(84,x);
	blue();
	printf("->");
	while (t = getch())
	{
		if (t >= min && t <= max || t == 72 || t == 80 || t == 13)
			break;

	}

	system("color F1");
	gotoxy(84,x);

	printf("  ");
	return t;
}
                                       /*************���ͷ�仯����ͬ���仯***********/
int cColor(int y,int x,int judge)
{
	if (judge == 0)
		x -= 2;
	else
		x += 2;
	gotoxy(y,x);
	red();
	return x;
}
                                         /*********��ͷ������************/
void inversion(int *i,int y,int *x,int a,int b,char *s)
{
	*i = a;
    *x = b;
	gotoxy(y,*x);
	red();
	puts(s);
}
                                      /****************������ɫ��Ϊ��ɫ*************/
void blue()
{
	SetConsoleColor(FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
}
                                      /****************������ɫ��Ϊ��ɫ*************/
void red()
{
	SetConsoleColor(FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY );
}
                                     /*******************�����û��˷�**************/
void remind(struct ID *p,struct ID *head1)
{
	struct ID *x1;
	int s = time(0);
	int d = s/86400 - 10956;
	x1 = head1;
	while (x1 != NULL)
	{
		if (strcmp(x1->idnum,p->idnum) == 0)
			break;
		x1 = x1->next;
	}
	if (d > x1->daymax)
		MessageBox(NULL,"��Ԥ�����˷�ʱ�䵽��������˷�����������ɲ���Ҫ����ʧ���߳����޸�Ԥ������!","��ʾ",MB_ICONASTERISK);
}
