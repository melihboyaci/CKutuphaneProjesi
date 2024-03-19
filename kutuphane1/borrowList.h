
int borrowList () {
    Borrow currentBorrow;
    Book borrowBook;

    FILE* ptrBooks = fopen("books.txt", "r");
    FILE* ptrUsers = fopen("users.txt", "r");
    FILE* ptrBorrows = fopen("borrows.txt", "r");
    if(ptrBooks == NULL || ptrUsers == NULL || ptrBorrows == NULL){
        printf("\nDosya aciminda bir hata meydana geldi!\n");
        fclose(ptrBooks);
        fclose(ptrUsers);
        fclose(ptrBorrows);
        return -1;
    }
    printf("Isim\t\t  Soy isim\tKitap ismi\t\t Baslangic Tarihi\tBitis Tarihi\n");
    printf("----\t\t  --------\t----------\t\t ----------------\t------------\n");

    //borrows.txt dosyasýný okuyoruz
    while(fscanf(ptrBorrows, "%d %d", &currentBorrow.userID, &currentBorrow.bookID)==2){
        fscanf(ptrBorrows, "%d %d %d", &currentBorrow.date.startDay, &currentBorrow.date.startMonth, &currentBorrow.date.startYear);
        fscanf(ptrBorrows, "%d %d %d", &currentBorrow.date.endDay, &currentBorrow.date.endMonth, &currentBorrow.date.endYear);

            char* userName = getNamebyID(currentBorrow.userID);
            char* surName = getsurNamebyID(currentBorrow.userID);
            char* bookName = getbookNamebyID(currentBorrow.bookID);
            //char* surName =
            printf("%s  %s %s %02d  %02d  %4d\t\t%02d  %02d  %4d\n",userName,surName,bookName,
                    currentBorrow.date.startDay,currentBorrow.date.startMonth,currentBorrow.date.startYear,
                    currentBorrow.date.endDay,currentBorrow.date.endMonth,currentBorrow.date.endYear);

            free(surName);
            free(userName);
            free(bookName);

    }




    fclose(ptrBooks);
    fclose(ptrUsers);
    fclose(ptrBorrows);
    return 0;
}
