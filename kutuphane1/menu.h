
void menu () {

    printf("\n----------------------------\n\n");
    printf("\tISLEM MENUSU\n\n");
    printf("----------------------------\n");
    printf("1. Kitap Islemleri\n");
    printf("2. Kullanici Islemleri\n");
    printf("3. Odunc Islemleri\n");
    printf("4. Cikis\n");
    printf("----------------------------\n");


}

void kitapIslemleri () {
    printf("\n----------------------------\n\n");
    printf("\tKitap Islemleri\n\n");
    printf("----------------------------\n");
    printf("1. Kitap Ekleme\n");
    printf("2. Kitap Listeleme\n");
    printf("3. Kitap Guncelleme\n");
    printf("4. Kitap Silme\n");
    printf("5. Kitap Arama\n");
    printf("6. Geri\n");
    printf("----------------------------\n");
    int choice;
    char searchName[20];
    int searchResult = 0;
    do{
        printf("\n*Kitap Islemlerindesiniz\n->Seciminizi giriniz: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(bookAdd() == 0){
                    printf("Kitap basarili bir sekilde eklendi\n");
                }else{
                    printf("Kitap eklenirken bir hata olustu\n");
            }
                break;
            case 2:
                if(bookList() == 0){
                    printf("\nKitaplar basarili bir sekilde listelendi!\n");
                 }else{
                    printf("\nKitaplar listelenirken bir hata meydana geldi!");
                 }
                break;
            case 3:
                if(bookUpdate() != 0)
                    printf("\nBir hata meydana geldi!\n");
                break;
            case 4:
                if(bookRemove() != 0)
                    printf("\nKitap silme isleminde bir hata olustu!");
                break;
            case 5:
                printf("\nAramak istediginiz kelimeyi giriniz(buyuk-kucuk harf duyarli): ");
                scanf("%s", searchName);
                printf("\n");
                searchResult = bookSearch(searchName);
                if(searchResult == 0)
                    printf("\nAranilan Kelime Bulunamadi\n");
                else
                    printf("---------------------------");
                    printf("\nToplam %d kitap bulundu\n", searchResult);
                break;
            case 6: menu();
                break;
            default:printf("Lutfen 1-6 arasinde secim yapiniz.\n");
        }

    }while(choice!=6);
}

void kullaniciIslemleri () {
    printf("\n----------------------------\n\n");
    printf("     Kullanici Islemleri\n\n");
    printf("----------------------------\n");
    printf("1. Kullanici Ekleme\n");
    printf("2. Kullanici Listeleme\n");
    printf("3. Kullanici Guncelleme\n");
    printf("4. Kullanici Silme\n");
    printf("5. Kullanici Arama\n");
    printf("6. Geri\n");
    printf("----------------------------\n");
    int searchResult = 0;
    char searchName[20];
    int choice;
    do{
        printf("\n*Kullanici Islemlerindesiniz\n->Seciminizi giriniz: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(userAdd() == 0)
                    printf("\nKullanici basarili bir sekilde eklendi\n");
                else
                    printf("\nKullanici eklerken bir hata olustu\n");
                break;
            case 2:
                if(userList() == 0){
                    printf("\nKullanicilar basarili bir sekilde listelendi!\n");
                 }else{
                    printf("\nKullanicilar listelenirken bir hata meydana geldi!");
                 }
                break;
            case 3:
                if(userUpdate() != 0)
                    printf("\nBir hata meydana geldi!\n");
                break;
            case 4:
                if(userRemove()!= 0)
                    printf("\nKullanici silerken bir hata olustu!");
                break;
            case 5:
                printf("\nAramak istediginiz kelimeyi giriniz: ");
                scanf("%s", searchName);
                printf("\n");
                searchResult = userSearch(searchName);
                if(searchResult == 0)
                    printf("\nAranilan Kelime Bulunamadi\n");
                else
                    printf("\nToplam %d kullanici bulundu\n", searchResult);
                break;
            case 6: menu();
                return 0;
                break;
            default:printf("Lutfen 1-6 arasinde secim yapiniz.\n");
        }
    }while(choice!=6);
}

void oduncIslemleri () {
    printf("\n----------------------------\n\n");
    printf("     Odunc Alma Islemleri\n\n");
    printf("----------------------------\n");
    printf("1. Odunc Alma\n");
    printf("2. Kitabi Geri Getirme\n");
    printf("3. Odunc Listeleme\n");
    printf("4. Geri\n");
    printf("----------------------------\n");
    int choice;
    do{
        printf("\n*Odunc Islemlerindesiniz\n->Seciminizi giriniz: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(userBorrow() == 0)
                    printf("\nOdunc alma islemi basariyla gerceklesti!\n");
                else
                    printf("\nOdunc alma isleminde bir hata meydana geldi\n");
                break;
            case 2:
                if(borrowBack() == 0)
                    printf("\nKitap basariyla geri alindi!\n");
                else
                    printf("\nKitabi geri getirme isleminde bir hata olustu!\n");
                break;
            case 3:
                if (borrowList() == 0)
                    printf("\nOduncler basariyla listelendi!\n");
                else
                    printf("Oduncler listelenirken bir hata meydana geldi!\n");
                break;
            case 4: menu();
                break;
            default:printf("Lutfen 1-4 arasinde secim yapiniz.\n");
        }

    }while(choice!=4);
}
