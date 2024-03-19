


int userAdd() {
    User newUser;
    FILE* fptr = fopen("users.txt", "a");
    if(fptr == NULL){
        return -1;
    }

	newUser.ID = getUserID();

    clearInputBuffer();
    printf("\n\n");
    printf("Kullanicinin ismini giriniz: ");
    fgets(newUser.name, sizeof(newUser.name), stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0';

    //clearInputBuffer();
    printf("Kullanicinin soy ismini giriniz:  ");
    fgets(newUser.surname, sizeof(newUser.surname), stdin);
    newUser.surname[strcspn(newUser.surname, "\n")] = '\0';

    printf("Kullanicinin dogum tarihini giriniz(gun ay yil): ");
    scanf("%d %d %d", &newUser.birthdate.day, &newUser.birthdate.month, &newUser.birthdate.year);

    fprintf(fptr, "%d%-15s %-15s %-2d %-2d %-4d\n", newUser.ID,newUser.name, newUser.surname, newUser.birthdate.day, newUser.birthdate.month, newUser.birthdate.year);
    fclose(fptr);
    return 0;
}
