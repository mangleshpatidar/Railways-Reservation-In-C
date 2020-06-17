#include<stdio.h>
#include<stdlib.h>
#include"rlyres.h"
#include"conio2.h"
#include<ctype.h>
int main()
{
    int choice;
add_train();
     while(1)
     {
choice=enterchoice();
if(choice==9)
{exit(1);}
int result;
int ticket_no;
char* pmob_no;
int* pticket_no;
passenger *ps;
char * ptrain_no;
        switch(choice)
   {
case 1:
    clrscr();
    view_train();
textcolor(BLUE);
    printf("\npress any key to go back to the main screen:");
    getch();
   clrscr();

        break;
        case 2:
           ps=get_passenger_details();
            if(ps!=NULL)
            {
                int ticket_no;
                ticket_no=book_ticket(*ps);
           if(ticket_no==-1)
           {
           textcolor(BLUE);
           gotoxy(1,15);
            printf("booking failed");
            printf("\t\t\t\t\t\t");
            }
            else{
            textcolor(BLUE);
            printf("\n\nyour TICKET is Booked successfully %d",ticket_no);
            }}
            textcolor(WHITE);
            printf("\npress any key to go to main screen:");
            getch();
            clrscr();
        break;
        case 3:
            clrscr();
          ticket_no=accept_ticket_no();
if(ticket_no!=0)
{
    view_ticket(ticket_no);
    textcolor(WHITE);
    printf("PRess any key to go main screen:");
    getch();
    clrscr();
    break;
}

        break;
        case 4:
            clrscr();
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
                pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);

            }
            clrscr();
        break;
        case 5:
            clrscr();
             view_all_booking();

            getch();
            clrscr();
        break;
        case 6:
            clrscr();
          ptrain_no=accept_train_no();
          if(ptrain_no!=NULL)
          {
              view_booking(ptrain_no);
          }
          clrscr();
        break;
        case 7:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            {
                result=cancel_ticket(ticket_no);
                if(result==0)
                {
                    textcolor(RED);
                    printf("Sorry! No tickets booked against ticket no %d",ticket_no);
                }
                else if(result==1)
                {
                    textcolor(GREEN);
                    printf("Ticket no %d successfully cancelled!",ticket_no);

                }
                textcolor(WHITE);
                printf("\n\n\n\nPress any key to go back to the main screen");
            }
            getch();
            clrscr();

        break;
        case 8:
            clrscr();
 ptrain_no=accept_train_no();
  if(ptrain_no!=NULL)
          {
             cancel_train(ptrain_no);
          }
          textcolor(WHITE);
                printf("\n\n\n\nPress any key to go back to the main screen");

            getch();
            textcolor(YELLOW);
          clrscr();
        break;
        default:
            textcolor(RED);
        printf("Wrong choice! Try again\n");
getch();
clrscr();

 }
     }
    getch();
    return 0;
}
