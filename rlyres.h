#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
typedef struct train
{
    char train_no[10];
    char from[10];
    char to[10];
    int facfare;
    int sacfare;
}train;
typedef struct passenger
{
    char p_name[10];
    char gender;
    char train_no[10];
    char p_class;
    char address[10];
    int age;
    int ticket_no;
    char mob_no[11];

}passenger;
int enterchoice();
void add_train();
void view_train();
int book_ticket(passenger);
int* get_ticket(char*);
void view_ticket(int);
void view_all_booking();
void view_bookings(char *);
int cancel_ticket(int);
void cancel_train(char*);
passenger* get_passenger_details();
int check_train_no(char *);
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int book_ticket(passenger);
int check_mob_no(char *);
int accept_ticket_no();
char* accept_mob_no();
int* get_ticket_no(char*);
void view_all_tickets(char*,int*);
char* accept_train_no();
void view_booking(char *);
#endif // RLYRES_H_INCLUDED
