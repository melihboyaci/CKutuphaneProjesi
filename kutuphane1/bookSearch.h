int bookSearch (char* ptr) {
    Book currentBook;
    int results = 0;
    FILE* fptr = fopen("books.txt", "r");
    if(fptr == NULL){
        return -1;
    }
	while (fscanf(fptr, "%d", &currentBook.ID) == 1) {
        //fscanf(fptr, " ");
        fgets(currentBook.name, sizeof(currentBook.name), fptr);
        //fscanf(fptr, " ");
        fgets(currentBook.writer, sizeof(currentBook.writer), fptr);
        fscanf(fptr, "%d", &currentBook.page);
        fscanf(fptr, "%d", &currentBook.status);

        if(strstr(currentBook.name, ptr)){
            printf("%d\t", currentBook.ID);
            printf("%s", currentBook.name);
            printf("%s\t", currentBook.writer);
            printf("%d\t", currentBook.page);
            printf("%s\n", (currentBook.status == 1) ? "Alinmis" : "Alinmamis");
            results++;
        }
        else if(strstr(currentBook.writer, ptr)){
            printf("%d\t", currentBook.ID);
            printf("%s", currentBook.name);
            printf("%s\t", currentBook.writer);
            printf("%d\t", currentBook.page);
            printf("%s\n", (currentBook.status == 1) ? "Alinmis" : "Alinmamis");
            results++;
        }
}
    fclose(fptr);
    return results;
}
