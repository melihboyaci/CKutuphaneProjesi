

int bookUpdate() {
    bookList();
    printf("\nGuncellemek istediginiz kitabin No'sunu giriniz: ");
    int bookID;
    scanf("%d", &bookID);
    Book currentBook; //Kitaplara ulasmak icin


    FILE* fptr = fopen("books.txt", "r");
    if(fptr == NULL){
        return -1;
    }

    FILE* tempPtr = fopen("temp.txt", "w");
    if(tempPtr == NULL)
        return -1;

    while (fscanf(fptr, "%d", &currentBook.ID) == 1) {
        fscanf(fptr, " ");
        fgets(currentBook.name, sizeof(currentBook.name), fptr);

        fscanf(fptr, " ");
        fgets(currentBook.writer, sizeof(currentBook.writer), fptr);

        fscanf(fptr, "%d", &currentBook.page);
        fscanf(fptr, "%d", &currentBook.status);

        if (currentBook.ID == bookID){
            clearInputBuffer();
            printf("---------------------------------------------------\n");
            printf("Kitabin yeni ismini giriniz: ");
            fgets(currentBook.name, sizeof(currentBook.name), stdin);
            currentBook.name[strcspn(currentBook.name, "\n")] = '\0';

            printf("Kitabin yazarini giriniz:  ");
            fgets(currentBook.writer, sizeof(currentBook.writer), stdin);
            currentBook.writer[strcspn(currentBook.writer, "\n")] = '\0';

            printf("Kitabin sayfa sayisini giriniz: ");
            char pageStr[10];
            fgets(pageStr, sizeof(pageStr), stdin);
            if (sscanf(pageStr, "%d", &currentBook.page) != 1) {
                printf("Gecersiz sayfa sayisi!\n");
                fclose(fptr);
                return -1;
            }

            fprintf(tempPtr, "%d %-25s %-20s %-5d %d\n", currentBook.ID, currentBook.name, currentBook.writer, currentBook.page, currentBook.status);
            printf("\n\nGuncelleme islemi basariyla tamamlandi!\n");
            }else {//Esit degilse yine yazdiracak cunku bizim yeni dosyamýz o olacak
                fprintf(tempPtr, "%d %-25s %-20s %-5d %d\n", currentBook.ID, currentBook.name, currentBook.writer, currentBook.page, currentBook.status);
        }

    }
    fclose(fptr);
    fclose(tempPtr);

    remove("books.txt");
    rename("temp.txt", "books.txt");
    return 0;
}
