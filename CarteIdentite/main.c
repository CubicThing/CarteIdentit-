#include <stdio.h>
#include <stdlib.h>

typedef struct ddn{

    int j;
    int m;
    int a;

}ddn;

typedef struct cid{

    char *nom[100];
    char *prenom[100];
    char sexe;
    ddn naissance;
    char *ville[100];

}cid;


int main()
{

    int input = 0;
    int cardinput = 0;
    cid carte;
    char number[6];
    FILE * openedfile;
    char ch;
    char textcarte[1000];
    int nbDeCartes;

    printf("Voulez vous ouvrir ou créer une nouvelle carte?");
    do{
       scanf("%i",&input);
    }while ((input < 1) || (input > 2));

    if(input == 1){

        openedfile = fopen("ci","r");

        fseek(openedfile, 0, SEEK_END);
        nbDeCartes = (ftell(openedfile) / sizeof(cid));
        fseek(openedfile, 0, SEEK_SET);

        printf("Il y a %d cartes dans le fichier. Laquele voulez vous lire?",nbDeCartes);
        do{
            scanf("%d",&cardinput);
        } while ((cardinput < 0 ) || (cardinput > nbDeCartes));

        fseek(openedfile, ((cardinput-1) * sizeof(cid) ), SEEK_SET);

        fread(&carte,sizeof(cid),1,openedfile);

        printf("Sexe : %c ",carte.sexe);
        printf("Jour : %d ",carte.naissance.j);
        printf("Mois : %d ",carte.naissance.m);
        printf("Annee : %d ",carte.naissance.a);
        printf("Nom : %s ",carte.nom);
        printf("Prenom : %s ",carte.prenom);

    }

    if(input == 2){

    openedfile = fopen("ci","a");


    printf("Entrez votre nom :  ");
    scanf("%s",&carte.nom);

    printf("Entrez votre nom :  ");
    scanf("%s",&carte.prenom);

    printf("Entrez le sexe (H/F) :  ");
    do{
       scanf("%c",&carte.sexe);
    }while ((carte.sexe != 'H') && (carte.sexe != 'F'));

    printf("Entrez votre date de naissance (JJ/MM/AAAA)");
    scanf("%d",&carte.naissance.j);
    scanf("%d",&carte.naissance.m);
    scanf("%d",&carte.naissance.a);

    printf("Entrez la ville d'autorite :   ");
    scanf("%s",&carte.ville);

    fwrite(&carte,sizeof(cid),1,openedfile);
    return 0;
    }

}
