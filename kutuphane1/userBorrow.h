int userBorrow () {
    Borrow newBorrow;
    User currentUser;
    Book currentBook;
    newBorrow.date.endDay = 0;
    newBorrow.date.endMonth = 0;
    newBorrow.date.endYear = 0;

    FILE* tempBooks = fopen("tempBooks.txt", "w");
    FILE* ptrUser = fopen("users.txt", "r");
    FILE* ptrBook = fopen("books.txt", "r");
    FILE* ptrBorrow = fopen("borrows.txt", "a");
    if(ptrBorrow==NULL || ptrUser==NULL || ptrBook==NULL || tempBooks==NULL){
        printf("\n**Dosya acarken bir hata meydana geldi!\n");
        fclose(tempBooks);
        fclose(ptrBook);
        fclose(ptrUser);
        fclose(ptrBorrow);
        return -1;
    }

    userList();
    int userID;
    printf("\nOdunc alacak kullanicinin No'sunu giriniz: ");
    scanf("%d", &userID);

    int userControl = 0;
    while(fscanf(ptrUser, "%d", &currentUser.ID) == 1){
        //fscanf(ptrUser, " ");
        fgets(currentUser.name, sizeof(currentUser.name), ptrUser);
        //fscanf(ptrUser, " ");
        fgets(currentUser.surname, sizeof(currentUser.surname), ptrUser);
        fscanf(ptrUser, "%d %d %d", &currentUser.birthdate.day, &currentUser.birthdate.month, &currentUser.birthdate.year);

        if(currentUser.ID == userID){
            userControl = 1;
            newBorrow.userID = userID;

        }
    }

    if(userControl != 1){
        printf("\n**Kullanici bulunamadi!\n");
        fclose(tempBooks);
        fclose(ptrBook);
        fclose(ptrUser);
        fclose(ptrBorrow);
        return -1;
    }

    bookList();
    int bookID;
    printf("\nOdunc alinacak kitabin No'sunu giriniz: ");
    scanf("%d", &bookID);

    while(fscanf(ptrBook, "%d", &currentBook.ID) == 1){
        fscanf(ptrBook, " ");
        fgets(currentBook.name, sizeof(currentBook.name), ptrBook);

        fscanf(ptrBook, " ");
        fgets(currentBook.writer, sizeof(currentBook.writer), ptrBook);

        fscanf(ptrBook, "%d", &currentBook.page);
        fscanf(ptrBook, "%d", &currentBook.status);

        if(currentBook.ID == bookID){
            if (currentBook.status == 1) {
                printf("\n**Kitap zaten odunc alinmis!\n");
                fclose(tempBooks);
                fclose(ptrBook);
                fclose(ptrUser);
                fclose(ptrBorrow);
                return -1;
                }
            currentBook.status = 1;
            newBorrow.bookID = bookID;
            fprintf(tempBooks, "%d %-25s %-20s %-5d %d\n", currentBook.ID, currentBook.name, currentBook.writer, currentBook.page, currentBook.status);

        }else {
            fprintf(tempBooks, "%d %-25s %-20s %-5d %d\n", currentBook.ID, currentBook.name, currentBook.writer, currentBook.page, currentBook.status);
        }
    }




    printf("\nBaslangic tarihi giriniz(gun ay yil): ");
    scanf("%d %d %d", &newBorrow.date.startDay, &newBorrow.date.startMonth, &newBorrow.date.startYear);


    fprintf(ptrBorrow, "%d %d %d %d %d %d %d %d\n", newBorrow.userID, newBorrow.bookID, newBorrow.date.startDay, newBorrow.date.startMonth, newBorrow.date.startYear, newBorrow.date.endDay, newBorrow.date.endMonth, newBorrow.date.endYear);

    fclose(tempBooks);
    fclose(ptrBook);
    fclose(ptrUser);
    fclose(ptrBorrow);
    remove("books.txt");
    rename("tempBooks.txt", "books.txt");

    return 0;
}
