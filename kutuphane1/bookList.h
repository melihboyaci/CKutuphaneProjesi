int bookList () {
    Book currentBook;
    FILE* fptr = fopen("books.txt", "r");
    if(fptr == NULL){
        return -1;
    }
	printf("\nKitap No\t Kitap Ismi\t\t   Kitap Yazari         Sayfa Sayisi\tDurum\n");
	printf("-----------\t -------------\t\t   ---------------      -------------  \t---------\n");
	while (fscanf(fptr, "%d", &currentBook.ID) == 1) {
        fgets(currentBook.name, sizeof(currentBook.name), fptr);

        fgets(currentBook.writer, sizeof(currentBook.writer), fptr);

        fscanf(fptr, "%d", &currentBook.page);

        fscanf(fptr, "%d", &currentBook.status);

        printf("%d\t\t", currentBook.ID);
        printf("%s", currentBook.name);
        printf("%s\t", currentBook.writer);
        printf("%d\t", currentBook.page);
        printf("\t%s\n", (currentBook.status == 1) ? "Alinmis" : "Alinmamis" );


	}
    fclose(fptr);
    return 0;
}
