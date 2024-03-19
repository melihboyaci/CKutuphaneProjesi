int bookRemove () {
    int bookID;
    Book currentBook;

    FILE* fptr = fopen("books.txt", "r");
    FILE* tempPtr = fopen("newBooks.txt", "w");
    if(fptr == NULL || tempPtr == NULL){
        printf("\nDosya aciminda bir hata olustu!");
        fclose(fptr);
        fclose(tempPtr);
        return -1;
    }

    int bookControl = 0;
    bookList();
    printf("Silmek istediginiz kitabin No'sunu giriniz: ");
    scanf("%d", &bookID);
    while(fscanf(fptr, "%d", &currentBook.ID)==1){
        fscanf(fptr, " ");
        fgets(currentBook.name, sizeof(currentBook.name), fptr);
        fscanf(fptr, " ");
        fgets(currentBook.writer, sizeof(currentBook.writer), fptr);
        fscanf(fptr, "%d %d", &currentBook.page, &currentBook.status);

        if(currentBook.ID == bookID){
            bookControl = 1;
            if(currentBook.status == 0){
                printf("\nKitap basariyla silindi\n");
            }else{
                printf("\nKitap odunc alindigi icin silinemedi\n");
                fprintf(tempPtr, "%d %-25s %-20s %-5d %d\n", currentBook.ID, currentBook.name, currentBook.writer, currentBook.page, currentBook.status);
            }
        }else {
            fprintf(tempPtr, "%d %-25s %-20s %-5d %d\n", currentBook.ID, currentBook.name, currentBook.writer, currentBook.page, currentBook.status);
        }
    }

    if(bookControl==0){
        printf("\nKitap bulunamadi");
        return -1;
    }



    fclose(fptr);
    fclose(tempPtr);
    remove("books.txt");
    rename("newBooks.txt", "books.txt");
    return 0;
}
