#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure Produit
typedef struct{
    char code[20];
    char nom[20];
    int Qte;
    float prixHT,prixTTC;
}Produit;

// Declaration variable global visible dans tout le bloc
 int choix;
 int i=0;
 int nbrPdt;
 int ID=0;
 int Q;
 Produit P[100];


void Ajouter_un_produit();
void Ajouter_plusieur_produits();
void Affichage_croissant_nom();
void Affichage_decroissant_prix();
void Acheter_un_produit();
void Etat_du_stock();
void Alimenter_le_stock();
void Supression_du_produit();
void Statistiques();
void Liste();
void Recherche();
void Recherche_par_code();
void Recherche_par_quantite();

// Debut
int main(){

    int feed;

    printf("\n================ Application de Gestion de pharmacie ================\n\n");
    do{
        printf("\n:::::::::::::::::::::::::: Menu Principale ::::::::::::::::::::::::::\n\n");
        printf("\t 1  -  Ajouter un nouveau produit \n");
        printf("\t 2  -  Ajouter plusieurs nouveaux produits \n");
        printf("\t 3  -  Lister tous les produits \n");
        printf("\t 4  -  Acheter un produit \n");
        printf("\t 5  -  Rechercher un produit \n");
        printf("\t 6  -  Etat du stock \n");
        printf("\t 7  -  Alimenter le stock \n");
        printf("\t 8  -  Supprimer un produit \n");
        printf("\t 9  -  Statistique de vente \n");
        printf("\t 10 -  Quitter L'\application\n\n");
        printf("Entrer votre choix : ");
        scanf("%d",&choix);

        switch(choix){
            case 1:
                Debut1 :
                system("cls");
                Ajouter_un_produit();
                printf("\n1 - Reajouter un autre produit\n2 - Retour au menu\nEntrer votre choix : ");
                scanf("%d",&feed);
                system("cls");
                if(feed==1)
                    goto Debut1;
                break;
            case 2:
                Debut2 :
                system("cls");
                Ajouter_plusieur_produits();
                printf("\n1 - Reajouter d'autre produits\n2 - Retour au menu\nEntrer votre choix : ");
                scanf("%d",&feed);
                system("cls");
                if(feed==1)
                    goto Debut2;
                    break;
            case 3:
                system("cls");
                Liste();
                break;
            case 4:
                system("cls");
                Acheter_un_produit();
                break;
            case 5:
                system("cls");
                Recherche();
                break;
            case 6:
                system("cls");
                Etat_du_stock();
                break;
            case 7:
                system("cls");
                Alimenter_le_stock();
                break;
            case 8:
                system("cls");
                Supression_du_produit();
                break;
            case 9:
                //Statistiques();
                break;
            case 10:
                system("cls");
                printf("\n:::::::::::::::::::::::::::   GOOD BYE   :::::::::::::::::::::::::::\n\n");
                sleep(1);
                exit(0);
                break;
            default:
                system("cls");
                printf("\nVotre Choix doit etre compris entre 1 et 10 \n");
                break;

        }
    }while(choix!=10);

    return 0;
 }
 // Fin

 void Liste(){
    do{
        printf("\n::::::::::::::::::::::::\tListe  \t::::::::::::::::::::::::\n\n");
        printf("\t1 - Par Ordre alphabetique croissant du nom \n");
        printf("\t2 - Par ordre decroissant du prix\n");
        printf("\t3 - retour a menu\n\n");
        printf("Veuillez choisir un Choix: ");
        scanf("%d",&choix);;
        switch(choix){
            case 1:
                system("cls");
                Affichage_croissant_nom();
                break;
            case 2:
                system("cls");
                Affichage_decroissant_prix();
                break;
            case 3:
                system("cls");
                break;
            default :
                printf("Votre Choix doit etre compris entre 1 et 3 \n");
                break;
        }
    }while(choix!=3);
 }

 void Recherche(){
    do{
        printf("\n:::::::::::::::::::::::::::   Recherche   :::::::::::::::::::::::::::\n\n");
        printf("\t1 - Par Code\n");
        printf("\t2 - Par Quantite\n");
        printf("\t3 - Retour a menu\n\n");
        printf("Veuillez choisir un Choix: ");
        scanf("%d",&choix);
        switch(choix){
            case 1:
                system("cls");
                Recherche_par_code();
                break;
            case 2:
                system("cls");
                Recherche_par_quantite();
                break;
            case 3:
                system("cls");
                break;
            default :
                printf("Votre Choix doit etre compris entre 1 et 3 \n");
                break;
        }
    }while(choix!=3);
 }

//Definition des procedures

void Ajouter_un_produit(){
    char codeAjout[20];
    Debut:
    printf("\n- Code : ");
    scanf("%s",&codeAjout);
    for (i=0;i<ID;i++){
        if (strcmp(codeAjout,P[i].code)==0){
            printf("\nCe produit deja existe\nEntrer un nouveau code\n");
            goto Debut;
        }
    }
    strcpy(P[ID].code,codeAjout);
    printf("- Nom : ");
    scanf("%s",P[ID].nom);
    printf("- Quantite : ");
    DO:
    scanf("%d",&P[ID].Qte);
    printf("- Prix HT : ");
    scanf("%f",&P[ID].prixHT);
    P[ID].prixTTC = P[ID].prixHT + 0.15 * P[ID].prixHT;
    ID++;
    printf("------------------------------------------");
    printf("\nFelicitation, produit ajouter avec succee\n");
    printf("------------------------------------------\n");
    ;
}

void Ajouter_plusieur_produits(){

    printf("\nDonner le nombre de produit : ");
    scanf("%d",&nbrPdt);
    if(nbrPdt<= 0){
        printf("Error !!! \n");
    }
    while(nbrPdt>i){
        Ajouter_un_produit();
        i++;
       }
}

void Affichage_croissant_nom(){
        for(i=0;i<ID-1;i++){
            if(strcmp(P[i].nom,P[i+1].nom)>0){
                Produit tmp;
                tmp=P[i+1];
                P[i+1]=P[i];
                P[i]=tmp;
            }
        }
    printf("\n*** Affichage des produits selon l'ordre alphabetique croissant du nom  ***\n\n");
    for(i=0;i<ID;i++){
        printf("----------------------------------------------------------------------------------------------------\n");
        printf("Code : %s   |   Nom : %s    |   Quantite : %d Piece   |   PrixHT : %.2fDH   |   PrixTTC : %.2fDH\n",P[i].code,P[i].nom,P[i].Qte,P[i].prixHT,P[i].prixTTC);
        printf("----------------------------------------------------------------------------------------------------\n");
    }
}

void Affichage_decroissant_prix(){
        for(i=0;i<ID-1;i++){
            if(P[i].prixTTC<P[i+1].prixTTC){
                Produit tmp;
                tmp=P[i+1];
                P[i+1]=P[i];
                P[i]=tmp;
            }
        }
    printf("\n*** Affichage des produits selon l'ordre decroissant du prix ***\n\n");
    for(i=0;i<ID;i++){
        printf("----------------------------------------------------------------------------------------------------\n");
        printf("Code : %s   |   Nom : %s    |   Quantite : %d Piece   |   PrixHT : %.2fDH   |   PrixTTC : %.2fDH\n",P[i].code,P[i].nom,P[i].Qte,P[i].prixHT,P[i].prixTTC);
        printf("----------------------------------------------------------------------------------------------------\n");
    }
}

void Acheter_un_produit(){
    printf("\n:::::::::::::::::::::::    Acheter un produit   :::::::::::::::::::::::\n\n");
    int reponse;
    bool exist = false;
    char codeAchat[20];
    Affichage_croissant_nom();
    printf("\nEntrer le code du produit souhaiter acheter: ");
    scanf("%s",codeAchat);
    for(i=0;i<ID;i++){
        if (strcmp(P[i].code,codeAchat)==0){
            printf("\n''Existe''\n");
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("Code : %s   |   Nom : %s    |   Quantite : %d Pieces   |   PrixHT : %.2fDH   |   PrixTTC : %.2fDH\n",P[i].code,P[i].nom,P[i].Qte,P[i].prixHT,P[i].prixTTC);
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("Entrer la quantite voulu : ");
            DO:
            scanf("%d",&Q);
            if (Q<0){
                printf("Entrer une quantite positif : ");
                goto DO;
            }
            if(Q<=P[i].Qte){
                printf("\n  =========================");
                printf("\n      Achat avec succe !");
                printf("\n  =========================\n\n");
                P[i].Qte -=Q;
                printf("----------------------------------------------------------------------------------------------------\n");
                printf("Code : %s   |   Nom : %s    |   Quantite : %d Pieces   |   PrixHT : %.2fDH   |   PrixTTC : %.2fDH\n",P[i].code,P[i].nom,P[i].Qte,P[i].prixHT,P[i].prixTTC);
                printf("----------------------------------------------------------------------------------------------------\n");
                exist = true;
                break;
            }
            else{
                printf("La quantite disponible est %d Pieces \n\n",P[i].Qte);
            }
        }
    }if(exist == false) printf("Ce produit n'existe pas \n\n");
    printf("1 : Veuiller effectuer un autre achat :\n");
    printf("2 : Retour au menu : \n");
    printf("Entrer votre choix : ");
    scanf("%d",&reponse);
    system("cls");
    if(reponse==1) Acheter_un_produit();
}

void Recherche_par_code(){
    char codeRech[20];
    int count = 0;
    printf("\nEntrer le code du produit rechercher :");
    scanf("%s",&codeRech);
    for(i=0;i<ID;i++){
        if (strcmp(P[i].code,codeRech)==0){
            printf("Existe\n");
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("Code : %s   |   Nom : %s    |   Quantite : %d Pieces   |   PrixHT : %.2fDH   |   PrixTTC : %.2fDH\n",P[i].code,P[i].nom,P[i].Qte,P[i].prixHT,P[i].prixTTC);
            printf("----------------------------------------------------------------------------------------------------\n");
            count++;
        }
    }if(count==0)printf("Ce produit n'existe pas ");
}

void Recherche_par_quantite(){
    int qteRech;
    int count = 0;
    printf("\nEntrer la quantite rechercher :");
    scanf("%d",&qteRech);
    for(i=0;i<ID;i++){
        if (P[i].Qte==qteRech){
            printf("Existe\n");
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("Code : %s   |   Nom : %s    |   Quantite : %d Pieces   |   PrixHT : %.2fDH   |   PrixTTC : %.2fDH\n",P[i].code,P[i].nom,P[i].Qte,P[i].prixHT,P[i].prixTTC);
            printf("----------------------------------------------------------------------------------------------------\n");
            count++;
        }
    }if(count==0)printf("Cette quantite n'existe pas ");
}

void Etat_du_stock(){
    int count = 0;
    printf("\n:::::::::::::::::::::::::::     Etat du stock     :::::::::::::::::::::::::::\n");
    printf("\n***  Les produits dont la quantite est inferieur a 3  ***\n\n");
    for(i=0;i<ID;i++){
        if (P[i].Qte<3){
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("Code : %s   |   Nom : %s    |   Quantite : %d Pieces   |   PrixHT : %.2fDH   |   PrixTTC : %.2fDH\n",P[i].code,P[i].nom,P[i].Qte,P[i].prixHT,P[i].prixTTC);
            printf("----------------------------------------------------------------------------------------------------\n");
            count++;
        }
    }if(count==0)printf("Aucun produits n'a une quantite inferieur a 3 \n");
}

void Alimenter_le_stock(){
    printf("\n::::::::::::::::::::    Alimenter le stock   ::::::::::::::::::::\n\n");
    int reponse;
    int count = 0;
    char codeAlim[20];
    Affichage_croissant_nom();
    printf("\nEntrer le code du produit souhaiter alimenter: ");
    scanf("%s",codeAlim);
    for(i=0;i<ID;i++){
        if (strcmp(P[i].code,codeAlim)==0){
            printf("\n''Existe''\n");
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("Code : %s   |   Nom : %s    |   Quantite : %d Pieces   |   PrixHT : %.2fDH   |   PrixTTC : %.2fDH\n",P[i].code,P[i].nom,P[i].Qte,P[i].prixHT,P[i].prixTTC);
            printf("----------------------------------------------------------------------------------------------------\n");

                printf("Entrer la quantite a ajouter : ");
                DO:
                scanf("%d",&Q);
                if (Q<0){
                    printf("Entrer une quantite positif stp: ");
                    goto DO;
                }
                else{
                    printf("\n   ==============================");
                    printf("\n      Alimentation avec succe !");
                    printf("\n   ==============================\n\n");
                    P[i].Qte +=Q;
                    printf("----------------------------------------------------------------------------------------------------\n");
                    printf("Code : %s   |   Nom : %s    |   Quantite : %d Pieces   |   PrixHT : %.2fDH   |   PrixTTC : %.2fDH\n",P[i].code,P[i].nom,P[i].Qte,P[i].prixHT,P[i].prixTTC);
                    printf("----------------------------------------------------------------------------------------------------\n");
                    count++;
                    break;
                }

        }
    }if(count==0) printf("Ce produit n'existe pas \n\n");
    printf("1 : Veuiller effectuer un autre ajout :\n");
    printf("2 : Retour au menu : \n");
    printf("Entrer votre choix : ");
    scanf("%d",&reponse);
    system("cls");
    if(reponse==1) Alimenter_le_stock();
}

void Supression_du_produit(){
    printf("\n:::::::::::::::::::::::    Supprimer un produit   :::::::::::::::::::::::\n\n");
    int reponse;
    bool exist = false;
    char codeSupp[20];
    Affichage_croissant_nom();
    printf("\nEntrer le code du produit souhaiter supprimer: ");
    scanf("%s",codeSupp);
    for(i=0;i<ID;i++){
        if (strcmp(P[i].code,codeSupp)==0){
            printf("\n  ===============================");
            printf("\n      Suppression avec succe !");
            printf("\n  ===============================\n\n");
            exist = true;
            ID--;
        }

    }if(exist == false) printf("Ce produit n'existe pas \n\n");
    printf("1 : Veuiller effectuer une autre suppression :\n");
    printf("2 : Retour au menu : \n");
    printf("Entrer votre choix : ");
    scanf("%d",&reponse);
    system("cls");
    if(reponse==1) Supression_du_produit();
}
