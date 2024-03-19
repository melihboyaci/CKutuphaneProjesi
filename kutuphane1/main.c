#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "header.h"
#include "bookadd.h"
#include "getID.h"
#include "bookList.h"
#include "bookUpdate.h"
#include "bookSearch.h"
#include "userAdd.h"
#include "userList.h"
#include "userUpdate.h"
#include "userSearch.h"
#include "userBorrow.h"
#include "borrowBack.h"
#include "borrowList.h"
#include "bookRemove.h"
#include "userRemove.h"

int main() {

    int choice = 0;
    menu();
    do{
        printf("\nSeciminizi giriniz: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: kitapIslemleri();
                break;
            case 2: kullaniciIslemleri();
                break;
            case 3: oduncIslemleri();
                break;
            case 4: printf("\nCikis yapiliyor...\n");
                return 0;
                break;
            default:printf("Lutfen 1-4 arasinde secim yapiniz.\n");
        }

    }while(choice!=4);

    return 0;
}

