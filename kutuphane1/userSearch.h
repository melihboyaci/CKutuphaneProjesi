int userSearch (char* ptr) {
    User currentUser;
    int results = 0;
    FILE* fptr = fopen("users.txt", "r");
    if(fptr == NULL){
        return -1;
    }
	while (fscanf(fptr, "%d", &currentUser.ID) == 1) {
        fscanf(fptr, " ");
        fgets(currentUser.name, sizeof(currentUser.name), fptr);
        fscanf(fptr, " ");
        fgets(currentUser.surname, sizeof(currentUser.surname), fptr);
        fscanf(fptr, "%d %d %d", &currentUser.birthdate.day, &currentUser.birthdate.month, &currentUser.birthdate.year);

        if(strstr(currentUser.name, ptr)){
            printf("% d\t\t", currentUser.ID);
            printf("%s ", currentUser.name);
            printf("%s\t", currentUser.surname);
            printf("%-2d %-2d %-4d\n", currentUser.birthdate.day, currentUser.birthdate.month, currentUser.birthdate.year);
            results++;
        }
        else if(strstr(currentUser.surname, ptr)){
            printf("% d\t\t", currentUser.ID);
            printf("%s ", currentUser.name);
            printf("%s\t", currentUser.surname);
            printf("%-2d %-2d %-4d\n", currentUser.birthdate.day, currentUser.birthdate.month, currentUser.birthdate.year);
            results++;
        }
}
    fclose(fptr);
    return results;
}
