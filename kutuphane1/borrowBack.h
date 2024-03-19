int borrowBack () {

    Borrow currentBorrow;

    currentBorrow.date.endDay = 0;
    currentBorrow.date.endMonth = 0;
    currentBorrow.date.endYear = 0;

    Book currentBook;

    FILE* tempBooks = fopen("tempBooks.txt", "w");
    FILE* ptrBooks = fopen("books.txt", "r");
    FILE* ptrBorrow = fopen("borrows.txt", "r");
    FILE *tempBorrow = fopen("tempBorrows.txt", "w");
    if (ptrBorrow == NULL || tempBorrow == NULL || tempBooks == NULL || ptrBooks == NULL){
        printf("\n**Dosya acarken bir hata meydana geldi!\n");
        fclose(ptrBorrow);
        fclose(tempBorrow);
        return -1;
    }

    int control = 0;
    int userID;
    int bookID;
    userList();
    printf("\nKitabi getiren kullanicinin No'sunu giriniz: ");
    scanf("%d", &userID);
    bookList();
    printf("\nKitabin No'sunu giriniz: ");
    scanf("%d", &bookID);

    while(fscanf(ptrBooks, "%d", &currentBook.ID) == 1){
        fscanf(ptrBooks, " ");
        fgets(currentBook.name, sizeof(currentBook.name), ptrBooks);

        fscanf(ptrBooks, " ");
        fgets(currentBook.writer, sizeof(currentBook.writer), ptrBooks);
        fscanf(ptrBooks, " ");
        fscanf(ptrBooks, "%d", &currentBook.page);
        fscanf(ptrBooks, "%d", &currentBook.status);

        if(currentBook.ID == bookID){
            if (currentBook.status == 0) {
                printf("\n**Kitap zaten geri alinmis!\n");
                fclose(tempBooks);
                fclose(ptrBooks);
                fclose(ptrBorrow);
                fclose(tempBorrow);
                remove("tempBooks.txt");
                remove("tempBorrows.txt");
                return 1;
                }
            else {
            currentBook.status = 0;
            fprintf(tempBooks, "%d %-25s %-20s %-5d %d\n", currentBook.ID, currentBook.name, currentBook.writer, currentBook.page, currentBook.status);
                }
        }else {
            fprintf(tempBooks, "%d %-25s %-20s %-5d %d\n", currentBook.ID, currentBook.name, currentBook.writer, currentBook.page, currentBook.status);
        }
    }

    while(fscanf(ptrBorrow, "%d %d", &currentBorrow.userID, &currentBorrow.bookID) == 2){
        fscanf(ptrBorrow, "%d %d %d", &currentBorrow.date.startDay, &currentBorrow.date.startMonth, &currentBorrow.date.startYear);
        fscanf(ptrBorrow, "%d %d %d", &currentBorrow.date.endDay, &currentBorrow.date.endMonth, &currentBorrow.date.endYear);

        if(currentBorrow.userID == userID && currentBorrow.bookID == bookID){
            control = 1;
            printf("\nKayit Bulundu!\n");
            printf("Bitis tarihini giriniz(gun ay yil): ");
            scanf("%d %d %d", &currentBorrow.date.endDay, &currentBorrow.date.endMonth, &currentBorrow.date.endYear);
        fprintf(tempBorrow, "%d %d %d %d %d %d %d %d\n", currentBorrow.userID, currentBorrow.bookID, currentBorrow.date.startDay, currentBorrow.date.startMonth, currentBorrow.date.startYear, currentBorrow.date.endDay, currentBorrow.date.endMonth, currentBorrow.date.endYear);
        }else {
        fprintf(tempBorrow, "%d %d %d %d %d %d %d %d\n", currentBorrow.userID, currentBorrow.bookID, currentBorrow.date.startDay, currentBorrow.date.startMonth, currentBorrow.date.startYear, currentBorrow.date.endDay, currentBorrow.date.endMonth, currentBorrow.date.endYear);
        }
    }




    if(control == 0){
        printf("\nKayit bulunamadi!");
        fclose(tempBooks);
        fclose(ptrBooks);
        fclose(ptrBorrow);
        fclose(tempBorrow);
        remove("tempBooks.txt");
        remove("tempBorrows.txt");
        return -1;
    }
    fclose(tempBooks);
    fclose(ptrBooks);
    fclose(ptrBorrow);
    fclose(tempBorrow);
    remove("borrows.txt");
    rename("tempBorrows.txt", "borrows.txt");
    remove("books.txt");
    rename("tempBooks.txt", "books.txt");


    return 0;
}
