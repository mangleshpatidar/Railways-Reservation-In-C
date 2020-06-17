#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<string.h>
#include<stdlib.h>
int enterchoice()
{
    int choice,i;
    textcolor(YELLOW);
    gotoxy(24,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1;i<70;i++)
        printf("-");
        printf("\n  Select an option\n");
        printf("1.   View Train\n");
        printf("2.   Book Ticket\n");
        printf("3.   View Ticket\n");
        printf("4.   Search Ticket No\n");
        printf("5.   View All Bookings\n");
        printf("6.   View Train bookings\n");
        printf("7.   Cancel ticket\n");
        printf("8.   Cancel train\n");
        printf("9.   exit\n");
        printf("     enter choice\n");
scanf("%d",&choice);
return choice;
}
int check_mob_no(char *p_mob)
{

    if(strlen(p_mob)!=10)
        return 0;
        while(*p_mob!='\0')
        {
            if(isdigit(*p_mob)==0)
                return 0;
        p_mob++;
  }
return 1;
    }
void add_train()
{
    FILE *fp;
    fp=fopen("E:\\cproject\\alltrains.dat","rb");


if(fp==NULL)
{train alltrains[4]={{"123","BPL","GWA",2100,1500},
    {"546","BPL","DEL",2700,1870},
    {"763","NMH","RTM",1200,800},
    {"873","HBJ","MUM",3000,2000}
    };
    fp=fopen("E:\\cproject\\alltrains.dat","wb");
    fwrite(alltrains,4*sizeof(train),1,fp);
    printf("File saved successfully!");
    getch();
    fclose(fp);
}
else
    {
    printf("file already present");
    fclose(fp);
}}
void view_train()
{
    int i;
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FAIR\tSECOND AC FAIR\n");
    for(i=1;i<=70;i++)
        printf("-");
    FILE *fp=fopen("E:\\cproject\\alltrains.dat","rb");
    train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
       {
    printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.facfare,tr.sacfare);}
    printf("\n\n\n\n");
    fclose(fp);
}
int check_train_no(char *trainno)
{

    FILE *fp;
    fp=fopen("E:\\cproject\\alltrains.dat","rb");
    train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
           {
           fclose(fp);
            return 1;
            }
} fclose(fp);
return 0;
}
passenger* get_passenger_details()
{
    clrscr();
    gotoxy(55,1);
    textcolor(GREEN);
    printf("press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter passenger name:");
    static passenger psn;
    fflush(stdin);
    fgets(psn.p_name,10,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        textcolor(RED);
        gotoxy(1,15);
        printf("Reservation Cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    int valid;
printf("Enter gender(M/F):");
do{
    valid=1;
    fflush(stdin);
    scanf("%c",&psn.gender);
    if(psn.gender=='0')
    {
        textcolor(RED);
gotoxy(1,15);
printf("\t\t\t\t\t");
        gotoxy(1,15);
        printf("Reservation Cancelled!");
        getch();
       textcolor(YELLOW);
        return NULL;
    }

if(psn.gender!='M' && psn.gender!='F')
{

    textcolor(BLUE);
      gotoxy(1,15);
    printf("Error! Gender should be M or F(in uppercase)");
    valid=0;
    getch();
    gotoxy(19,2);
    printf(" \b");
    textcolor(YELLOW);
}
}while(valid==0);
gotoxy(1,15);
printf("\t\t\t\t\t\t");
gotoxy(1,3);
printf("Enter the Trainno:");
do
{
    fflush(stdin);
    scanf("%s",&psn.train_no);
    if(strcmp(psn.train_no,"0")==0)
    {
        textcolor(BLUE);
        gotoxy(1,15);
        printf("\t\t\t\t\t");
        gotoxy(1,15);
        printf("Reservation Cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;

    }
    valid=check_train_no(psn.train_no);
    if(valid==0)
    {
        textcolor(RED);
        gotoxy(1,15);
        printf("Error! Invalid Train No:");
        getch();
        gotoxy(19,3);
        printf("\t\t\t\t\t\t");
        gotoxy(19,3);
        textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,15);
    printf("\t\t\t\t\t\t\t");
gotoxy(1,4);
printf("Enter travelling class (First AC-F,Second AC-S):");
do
{
    valid=1;
    fflush(stdin);
    scanf("%c",&psn.p_class);
    if(psn.p_class=='0')
    {
        textcolor(BLUE);
        gotoxy(1,15);
        printf("\t\t\t\t\t\t");
        gotoxy(1,15);
        printf("Reservation Cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    if(psn.p_class!='F' && psn.p_class!='S')
    {
        textcolor(BLUE);
        gotoxy(1,15);
        printf("Error! Travelling class should be F or S(in uppercase):");
        valid=0;
        getch();
        gotoxy(49,4);
        printf(" \b");
        textcolor(YELLOW);

   } }while(valid==0);
    gotoxy(1,5);
    printf("Enter Address:");
    fflush(stdin);
    fgets(psn.address,20,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        textcolor(BLUE);
        gotoxy(1,15);
        printf("\t\t\t\t\t\t");
        gotoxy(1,15);
        printf("Reservation cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    gotoxy(1,6);
    printf("Enter Age:");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%d",&psn.age);
        if(psn.age==0)
        {
            textcolor(BLUE);
            gotoxy(1,15);
            printf("\t\t\t\t\t\t");
            gotoxy(1,15);
            printf("Reservation CancelLed!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        if(psn.age<0)
        {
            textcolor(BLUE);
            gotoxy(1,15);
            printf("Error! age should be positive:");
            valid=0;
            getch();
            gotoxy(11,6);
            printf("\t\t\t\t");
            gotoxy(11,6);
            textcolor(YELLOW);
        }
        if(psn.age>100)
        {
            textcolor(BLUE);
            gotoxy(1,15);
            printf("Error! age should be less than 100 try again");
            valid=0;
            getch();
            gotoxy(11,6);
            printf("\t\t\t\t");
            gotoxy(11,6);
            textcolor(YELLOW);
        }
        }while(valid==0);
        gotoxy(1,15);
        printf("\t\t\t\t\t\t");
        gotoxy(1,7);
        printf("Enter Mobile Number:");

        do
        {
            fflush(stdin);
            fgets(psn.mob_no,12,stdin);
            pos=strchr(psn.mob_no,'\n');
            if(pos!=NULL)
        *pos='\0';
        if(strcmp(psn.mob_no,"0")==0)
        {
            textcolor(BLUE);
            gotoxy(1,15);
            printf("\t\t\t\t\t");
            gotoxy(1,15);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        valid=check_mob_no(psn.mob_no);
        if(valid==0)
        {
            textcolor(BLUE);
            gotoxy(1,15);
            printf("Error! Invalid Mobile No");
            getch();
            gotoxy(21,7);
            printf("\t\t\t\t\t\t");
            gotoxy(21,7);
            textcolor(YELLOW);
        }
        }while(valid==0);
        return &psn;
        }
int get_booked_ticket_count(char *train_no,char tc)
    {
        FILE *fp;
        passenger pr;
        fp=fopen("E:\\cproject\\allbookings.dat","rb");
if(fp==NULL)
{
    return 0;
}
int count=0;
while(fread(&pr,sizeof(pr),1,fp)==1)
{
    if(strcmp(pr.train_no,train_no)==0 && pr.p_class==tc)
        ++count;
}
fclose(fp);
return count;

    }
    int last_ticket_no()
    {
        FILE *fp;
        passenger pr;
        fp=fopen("E:\\cproject\\allbookings.dat","rb");
if(fp==NULL)
      return 0;
fseek(fp,-1*sizeof(pr),SEEK_END);
fread(&pr,sizeof(pr),1,fp);
fclose(fp);
return pr.ticket_no;

    }

    int book_ticket(passenger p)
    {
        int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
        if(ticket_count==3)
        {
            textcolor(BLUE);
            printf("All seat full in train no %s in %c class!\n",p.train_no,p.p_class);
            return -1;
        }
        int ticket_no=last_ticket_no()+1;
        p.ticket_no=ticket_no;
        FILE *fp=fopen("E:\\cproject\\allbookings.dat","ab");
        if(fp==NULL)
        {

            textcolor(BLUE);
            printf("Sorry file can't be opened");
            return -1;


        }
fwrite(&p,sizeof(p),1,fp);
fclose(fp);
return ticket_no;
    }
    int accept_ticket_no()
    {

        printf("enter a ticket no:");
        int valid;
        int ticket_no;
        do{
            valid=1;
            scanf("%d",&ticket_no);
            if(ticket_no==0)
            {
                textcolor(RED);
                gotoxy(1,15);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,15);
                printf("Cancelling input...!");
                getch();
                textcolor(YELLOW);

            }
            if(ticket_no<0)
            {textcolor(RED);
            gotoxy(1,15);
            printf("\t\t\t\t\t\t");
            gotoxy(1,15);
            printf("invalid ticket no it must be positive:");
            valid=0;
            getch();
            gotoxy(11,1);
            printf("\t\t\t\t\t");
            gotoxy(11,1);
            textcolor(YELLOW);
            }
        }while(valid==0);
        return ticket_no;
    }
    void view_ticket(int ticket_no)
    {

        FILE *fp;
        fp=fopen("E:\\cproject\\allbookings.dat","rb");
        if(fp==NULL)
        {
            textcolor(GREEN);
            printf("No booking done Yet!");
            return;
        }
        passenger pr;
        while(fread(&pr,sizeof(pr),1,fp)==1)
        {
            if(pr.ticket_no==ticket_no)
            {
                printf("\nNAME %s\n GENDER %c\n TRAIN NO %s\n CLASS %c\n ADDRESS %s \n age%d\n MOB NO %s\n TICKET NO %d",
                       pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticket_no);
                       printf("\n\n");
                       fclose(fp);
                       return;
            }
        }
        textcolor(RED);
        printf("\n No Details of ticket no %d found!",ticket_no);
        fclose(fp);
        }
int cancel_ticket(int ticket_no)
{
     passenger pr;
    FILE *fp1;
        fp1=fopen("E:\\cproject\\allbookings.dat","rb");
         if(fp1==NULL)
        {
            textcolor(GREEN);
            printf("No booking done Yet!");
            return -1;
        }
        FILE*fp2;
        fp2=fopen("E:\\cproject\\temp.dat","wb+");
        int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticket_no!=ticket_no)
            fwrite(&pr,sizeof(pr),1,fp2);
        else
            found=1;
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    remove("E:\\cproject\\temp.dat");
    else{
        remove("E:\\cproject\\allbookings.dat");

        rename("E:\\cproject\\temp.dat","E:\\cproject\\allbookings.dat");

}
return found;
}
char* accept_mob_no()
{
    static char mob_no[11];
    int valid;
    char *pos;
    printf("Enter mobile Number:");
    do{
        fflush(stdin);
        fgets(mob_no,11,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
            textcolor(RED);
            gotoxy(1,15);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,15);
            printf("Cancelling Input!");
            getch();
            textcolor(YELLOW);
            return NULL;

        }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
             textcolor(BLUE);
            gotoxy(1,15);
            printf("Error! Invalid Mobile No");
            getch();
            gotoxy(21,1);
            printf("\t\t\t\t\t\t");
            gotoxy(21,1);
            textcolor(YELLOW);
        }
        }while(valid==0);
        clrscr();
        return mob_no;
}
int* get_ticket_no(char *p_mob_no)
{
    int count=0;
    FILE *fp;
    passenger pr;
    fp=fopen("E:\\cproject\\allbookings.dat","rb");
   if(fp==NULL)
    {
        return NULL;
    }
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            ++count;
        }
    }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int *p=(int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            *(p+i)=pr.ticket_no;
            i++;

        }
    }
    *(p+i)=-1;
    fclose(fp);
    return p;
}
void view_all_tickets(char *pmob_no,int *pticket_no)
{
if(pticket_no==NULL)
{
    textcolor(GREEN);
    printf("SORRY ! No tickets booked against mobile no %s",pmob_no);
    textcolor(WHITE);
    printf("\n\n Press any key to go back to the main screen ");
    textcolor(YELLOW);
    getch();
    return;
}
printf("Following are tickets booked for mobile no %s",pmob_no);
int i;
printf("\n\nTICKET NO\n");
printf("--------");
for(i=0;*(pticket_no+i)!=-1;i++)
    printf("\n%d",*(pticket_no+i));
textcolor(WHITE);
printf("\n\nPress any key to go back to the main screen");
textcolor(YELLOW);
free(pticket_no);
getch();
}
char* accept_train_no()
{

int valid;
    static char train_no[10];
    gotoxy(50,1);
    textcolor(GREEN);
    printf("Press 0 to Exit:");
    gotoxy(1,1);
    textcolor(YELLOW);
   printf("Enter the Trainno:");
do
{
     valid=1;
    fflush(stdin);
    scanf("%s",train_no);
    if(strcmp(train_no,"0")==0)
    {
        textcolor(BLUE);
        gotoxy(1,15);
        printf("\t\t\t\t\t");
        gotoxy(1,15);
        printf("Cancelling Input!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    valid=check_train_no(train_no);
    if(valid==0)
    {
        textcolor(RED);
        gotoxy(1,15);
        printf("Error! Invalid Train No:");
        getch();
        gotoxy(20,1);
        printf("\t\t\t\t\t\t");
        gotoxy(20,1);
        textcolor(YELLOW);
        }
    }while(valid==0);
    clrscr();
    return train_no;
}
void view_booking(char* train_no)
{
    int found=0,i;
    FILE *fp=fopen("E:\\cproject\\allbookings.dat","rb");
    passenger pr;
     printf("TICKETNO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
  for(i=1;i<=70;i++)
    printf("-");
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            printf("%d\t\t%c\t%s",pr.ticket_no,pr.p_class,pr.p_name);
            gotoxy(41,row++);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            found=1;
        }
    }
    if(!found)
    {
        clrscr();
        textcolor(RED);
        printf("\nNo details of given train no %s found!",train_no);

    }
textcolor(WHITE);
printf("\n\n Press any key to go to main screen");
textcolor(YELLOW);
getch();
fclose(fp);
}
void view_all_booking()
{
    int i;
  FILE *fp;
  fp=fopen("E:\\cproject\\allbookings.dat","rb");
  if(fp==NULL)
    printf("NO booking done yet:");
    passenger pr;
     printf("TICKETNO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
  for(i=1;i<=70;i++)
    printf("-");
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {

            printf("%d\t\t%c\t%s",pr.ticket_no,pr.p_class,pr.p_name);
            gotoxy(41,row++);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            }
fclose(fp);
 gotoxy(1,15);
              textcolor(WHITE);
                printf("\n\n\n\nPress any key to go back to the main screen");
                textcolor(YELLOW);

}
void cancel_train(char* trainno)
{
    int i,found,flag=0;
    FILE *fp;
    fp=fopen("E:\\cproject\\allbookings.dat","rb");
  if(fp==NULL)
    printf("NO booking done yet:");
    passenger pr;
    printf("Train No %s is cancelled due to some reason\nSORRY FOR INCONVENIENCE:\n",trainno);
     printf("TICKETNO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
  for(i=1;i<=70;i++)
    printf("-");
    int row=5;

    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
if(strcmp(pr.train_no,trainno)==0)
          {
              fclose(fp);
              found=cancel_ticket(pr.ticket_no);
               FILE *fp;
    fp=fopen("E:\\cproject\\allbookings.dat","rb");
                 if(found==0)
                {
                    textcolor(RED);
                    printf("Sorry! No tickets booked against Train No %d",trainno);
                }
                else{
           printf("%d\t\t%c\t%s",pr.ticket_no,pr.p_class,pr.p_name);
            gotoxy(41,row++);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
           flag=1;

       } } }
        fclose(fp);
        if(flag==1)
        {
             textcolor(GREEN);
                    printf("\n\n\n\nall Ticket of TRAIN NO %s successfully cancelled!",trainno);
        }
}
