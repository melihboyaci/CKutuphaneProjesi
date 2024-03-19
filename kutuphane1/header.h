typedef struct{
    int ID;
    char name[26];
    char writer[21];
    int page;
    int status; //0 ödünç alýnmamýþ, 1 ödünç alýnmýþ
}Book;

typedef struct{
    int day;
    int month;
    int year;
}Birth;

typedef struct{
    int ID;
    char name[15];
    char surname[15];
    Birth birthdate;
}User;

typedef struct{
    int startDay;
    int startMonth;
    int startYear;
    int endDay;
    int endMonth;
    int endYear;
}Dates;

typedef struct{
    int userID;
    int bookID;
    Dates date;
}Borrow;





void menu();
int bookAdd(); //1
int bookList(); //2
int bookUpdate(); //3
int bookSearch(); //5
int getID();

int userAdd(); //1
int userList(); //2
int userRemove(); //4
int userUpdate(); //3
int userSearch(); //5

int userBorrow(); //1
int borrowList();
int borrowBack();

