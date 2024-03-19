int userRemove () {
    int userID;
    User currentUser;

    FILE* fptr = fopen("users.txt", "r");
    FILE* tempPtr = fopen("newUsers.txt", "w");
    if(fptr == NULL || tempPtr == NULL){
        printf("\nDosya aciminda bir hata olustu!");
        fclose(fptr);
        fclose(tempPtr);
        return -1;
    }

    int userControl = 0;
    userList();
    printf("Silmek istediginiz kullanicinin No'sunu giriniz: ");
    scanf("%d", &userID);
    while(fscanf(fptr, "%d", &currentUser.ID)==1){
        fgets(currentUser.name, sizeof(currentUser.name), fptr);
        fgets(currentUser.surname, sizeof(currentUser.surname), fptr);
        fscanf(fptr, "%d %d %d", &currentUser.birthdate.day, &currentUser.birthdate.month, &currentUser.birthdate.year);

        if(currentUser.ID == userID){
            userControl = 1;
            printf("Kullanici basariyla silindi!\n");

            }else{
                fprintf(tempPtr, "%d%-15s %-15s %-2d %-2d %-4d\n", currentUser.ID, currentUser.name, currentUser.surname, currentUser.birthdate.day, currentUser.birthdate.month, currentUser.birthdate.year);
            }
        }

    if(userControl==0){
        printf("\nKullanici bulunamadi");
        return -1;
    }


    fclose(fptr);
    fclose(tempPtr);
    remove("users.txt");
    rename("newUsers.txt", "users.txt");
    return 0;
}
