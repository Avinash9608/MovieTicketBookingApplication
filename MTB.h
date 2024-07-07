#ifndef MTB_H_INCLUDED
#define MTB_H_INCLUDED
#include<time.h>
typedef struct user
{
    char userid[100];
    char username[100];
    char password[100];
    char usertype[100];
    char question_id[100];
    char hint_answer[100];
    char mobile_number[100];
}user;

typedef struct question
{
    char question_id[100];
    char question[100];
}question;

typedef struct
{
    int seat_number;
    int seat_is_booked;
}seat;

typedef struct
{
    char theater_id[100];
    char movie_id[100];
    char movie_name[100];
    int first_block_price;
    int second_block_price;
    int third_block_price;
    struct tm show_date;
    seat seats[100];
}movie;

typedef struct
{
    char theater_id[100];
    char theater_name[100];
    int is_booked;
}theater;

typedef struct
{
    char ticket_id[100];
    char theater_id[100];
    char movie_id[100];
    struct tm show_date;
    int seat_number;
    char user_id[100];
}ticket;

void print_char(char, int, int, int);
void print_title(char*, int, int, int);
void print_title_in_middle(char*, int, int);
void print_basic_screen();
void input_password(user *, int, int);
int is_valid_integer(char *str);
void get_string(char *,  int);
void get_password(char *, unsigned int);
char * get_mobile_number(int, int);
void add_questions();
user * get_user_details(char *);
void create_user(char *);
user * get_credentials(char *);
int check_user_details(user *);
void forget_credentials(user *);
char *get_question_id();
int check_mobile_number_in_records(char *);
user * login(char *);
void get_integer(int *);
void set_master_admin_rec();
int enter_login_choice();
int enter_choice(user *);
//admin choice
void add_theater();
void show_theater();
//deleting theater, movie, booking
int delete_theater();
char * get_theater_id(int); // this function take arg because it will call from 2 places 1.for delete theater we have to pass 0 otherwise 2. for adding movie pass 1
int delete_movie_by_theater_id(char *); //theater id pass
int delete_booking_by_movie_id(char *);

//adding movie
int compare_date(struct tm, struct tm);  // it has date, month, year
int is_leap_year(int );
int is_valid_date(struct tm);
void change_theater_booking_status(char *);
void add_movie();
char * get_theater_name(char *);
void show_movie();
void show_my_profile(user *);
void change_password(user *);
//booking Releted functions
void booking(user *);
movie * get_movie_id_and_show_date(); // movie.bin all data retrive
int * get_seat_numbers(movie*);
void change_seat_booking_status(int seat_number, char *movie_id, struct tm);

void change_security_question(user *);
//cancel booking
ticket *get_ticket_id(user *);
void show_booking_of_user(user *);
int cancel_booking_of_user(user *);
#endif // MTB_H_INCLUDED
