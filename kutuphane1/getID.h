int getID () {
    FILE* fptr = fopen("books.txt", "r");
    if (fptr == NULL) //Dosyaya ulaþamýyorsak birinci kitaba 1 atýyor.
        return 1;

    int maxID = 0;
    int currentID;
    Book currentBook;
    while(fscanf(fptr, "%d", &currentID)==1){
        fgets(currentBook.name, sizeof(currentBook.name), fptr);
        fgets(currentBook.writer, sizeof(currentBook.writer), fptr);
        fscanf(fptr, "%d", &currentBook.page);
        fscanf(fptr, "%d", &currentBook.status);
        if(currentID > maxID)
            maxID = currentID;
        }
        fclose(fptr);
        return maxID+1;
}




int getUserID() {
    FILE* fptr = fopen("users.txt", "r");
    if (fptr == NULL) {
        return 0; // Dosya açýlamazsa, baþlangýç ID'si 0 olarak döndürülür.
    }

    int maxID = 0;
    User currentUser;

    while (fscanf(fptr, "%d", &currentUser.ID) == 1) {
        int copdeger3;
        int copDeger4;
        int copDeger5;
        fgets(currentUser.name, sizeof(currentUser.name), fptr);
        fgets(currentUser.surname, sizeof(currentUser.surname), fptr);
        fscanf(fptr, "%d %d %d", &copdeger3, &copDeger4, &copDeger5);

        if (currentUser.ID > maxID) {
            maxID = currentUser.ID;
        }
    }

    fclose(fptr);
    return maxID+1;
}

char* getNamebyID (int userID){
    User currentUser;
    FILE* fptr = fopen("users.txt", "r");
    if(fptr == NULL){
        printf("\nDosya acma hatasi!");
    }
    else{
        while(fscanf(fptr, "%d", &currentUser.ID)==1){
            fgets(currentUser.name, sizeof(currentUser.name), fptr);
            fgets(currentUser.surname, sizeof(currentUser.surname), fptr);
            fscanf(fptr, "%d %d %d", &currentUser.birthdate.day, &currentUser.birthdate.month, &currentUser.birthdate.year);
            if(currentUser.ID == userID){
                char* nameCopy = strdup(currentUser.name);
                if (nameCopy == NULL) {
                printf("\nBellek ayirma hatasi!");
                fclose(fptr);
                return NULL;
                }

                fclose(fptr);
                return nameCopy;
            }

        }
    }
    fclose(fptr);
    return NULL;
}
char* getsurNamebyID (int userID){
    User currentUser;
    FILE* fptr = fopen("users.txt", "r");
    if(fptr == NULL){
        printf("\nDosya acma hatasi!");
    }
    else{
        while(fscanf(fptr, "%d", &currentUser.ID)==1){
            fgets(currentUser.name, sizeof(currentUser.name), fptr);
            fgets(currentUser.surname, sizeof(currentUser.surname), fptr);
            fscanf(fptr, "%d %d %d", &currentUser.birthdate.day, &currentUser.birthdate.month, &currentUser.birthdate.year);
            if(currentUser.ID == userID){
                char* surnameCopy = strdup(currentUser.surname);
                if (surnameCopy == NULL) {
                printf("\nBellek ayirma hatasi!");
                fclose(fptr);
                return NULL;
                }

                fclose(fptr);
                return surnameCopy;
            }

        }
    }
    fclose(fptr);
    return NULL;
}

char* getbookNamebyID (int bookID){
    Book currentBook;
    FILE* fptr = fopen("books.txt", "r");
    if(fptr == NULL){
        printf("\nDosya acma hatasi!");
    }
    else{
        while(fscanf(fptr, "%d", &currentBook.ID)==1){
            fgets(currentBook.name, sizeof(currentBook.name), fptr);
            fgets(currentBook.writer, sizeof(currentBook.writer), fptr);
            fscanf(fptr, "%d %d", &currentBook.page, &currentBook.page);
            if(currentBook.ID == bookID){
                char* booknameCopy = strdup(currentBook.name);
                if (booknameCopy == NULL) {
                printf("\nBellek ayirma hatasi!");
                fclose(fptr);
                return NULL;
                }

                fclose(fptr);
                return booknameCopy;
            }

        }
    }
    fclose(fptr);
    return NULL;
}
