void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (c == EOF) {
        clearerr(stdin);  // EOF durumunu temizle
    }
}

int bookAdd() {
    Book newBook;
    FILE* fptr = fopen("books.txt", "a");
    if(fptr == NULL){
        return -1;
    }

	newBook.ID = getID();

    clearInputBuffer();
    printf("\n");
    printf("Kitabin ismini giriniz: ");
    fgets(newBook.name, sizeof(newBook.name), stdin);
    newBook.name[strcspn(newBook.name, "\n")] = '\0';

    //clearInputBuffer();
    printf("Kitabin yazarini giriniz:  ");
    fgets(newBook.writer, sizeof(newBook.writer), stdin);
    newBook.writer[strcspn(newBook.writer, "\n")] = '\0';

    printf("Kitabin sayfa sayisini giriniz: ");
    char pageStr[10];
    fgets(pageStr, sizeof(pageStr), stdin);
    if (sscanf(pageStr, "%d", &newBook.page) != 1) {
        printf("Gecersiz sayfa sayisi!\n");
        fclose(fptr);
        return -1;
    }
    newBook.status = 0;
    fprintf(fptr, "%d %-25s %-20s %-5d %d\n", newBook.ID,newBook.name, newBook.writer, newBook.page, newBook.status);
    fclose(fptr);
    return 0;
}
