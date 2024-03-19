int userList() {
    User currentUser;
    FILE* fptr = fopen("users.txt", "r");
    if(fptr == NULL){
        return -1;
    }
	printf("\nKullanici No\tisim\t   \t Soy isim\tDogum Tarihi\n");
	printf("-----------\t------ \t   \t ----------\t--------------\n");
	while (fscanf(fptr, "%d", &currentUser.ID) == 1) {
        fgets(currentUser.name, sizeof(currentUser.name), fptr);

        fgets(currentUser.surname, sizeof(currentUser.surname), fptr);

        fscanf(fptr, "%d %d %d", &currentUser.birthdate.day, &currentUser.birthdate.month, &currentUser.birthdate.year);

        printf("%d\t\t", currentUser.ID);
        printf("%s", currentUser.name);
        printf("%s\t", currentUser.surname);
        printf("%02d %02d %04d\n", currentUser.birthdate.day, currentUser.birthdate.month, currentUser.birthdate.year);


	}
    fclose(fptr);
    return 0;
}
