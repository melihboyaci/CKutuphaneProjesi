
int userUpdate() {
    userList();
    printf("\nGuncellemek istediginiz kullanicinin No'sunu giriniz: ");
    int userID;
    scanf("%d", &userID);
    User currentUser; //Kullanicilara ulasmak icin


    FILE* fptr = fopen("users.txt", "r");
    if(fptr == NULL){
        return -1;
    }

    FILE* tempPtr = fopen("tempUser.txt", "w");
    if(tempPtr == NULL)
        return -1;

    while (fscanf(fptr, "%d", &currentUser.ID)==1) {

        fscanf(fptr, " ");
        fgets(currentUser.name, sizeof(currentUser.name), fptr);

        fscanf(fptr, " ");
        fgets(currentUser.surname, sizeof(currentUser.surname), fptr);

        fscanf(fptr, "%d %d %d", &currentUser.birthdate.day, &currentUser.birthdate.month, &currentUser.birthdate.year);

        if (currentUser.ID == userID){
            clearInputBuffer();
            printf("---------------------------------------------------\n");
            printf("Kullanicinin yeni ismini giriniz: ");
            fgets(currentUser.name, sizeof(currentUser.name), stdin);
            currentUser.name[strcspn(currentUser.name, "\n")] = '\0';

            printf("Kullanicinin yeni soy ismini giriniz:  ");
            fgets(currentUser.surname, sizeof(currentUser.surname), stdin);
            currentUser.surname[strcspn(currentUser.surname, "\n")] = '\0';
            printf("Yeni dogum tarihini giriniz(gun ay yil): ");
            scanf("%d %d %d", &currentUser.birthdate.day, &currentUser.birthdate.month, &currentUser.birthdate.year);
            clearInputBuffer();
            fprintf(tempPtr, "%d%-15s %-15s %-2d %-2d %-4d\n", currentUser.ID, currentUser.name, currentUser.surname, currentUser.birthdate.day, currentUser.birthdate.month, currentUser.birthdate.year);

            printf("\n\nGuncelleme islemi basariyla tamamlandi!\n");
            }
            else {//Esit degilse yine yazdiracak cunku bizim yeni dosyamýz o olacak
                fprintf(tempPtr, "%d%-15s %-15s %-2d %-2d %-4d\n", currentUser.ID, currentUser.name, currentUser.surname, currentUser.birthdate.day, currentUser.birthdate.month, currentUser.birthdate.year);
        }

    }
    fclose(fptr);
    fclose(tempPtr);
    remove("users.txt");
    rename("tempUser.txt", "users.txt");

    return 0;
}
