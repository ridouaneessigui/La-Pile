#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<math.h>
#include<conio.h>

void gotoxy(int x, int y)
{
   HANDLE hConsoleOutput;
   COORD dwCursorPosition;
   //cout.flush();
   dwCursorPosition.X = x;
   dwCursorPosition.Y = y;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
typedef struct pile pile;
struct pile
{
    int x;
    int y;
};
pile emp[20];
pile desemp[20];
int sommet_emp = 0;
int sommet_desemp = 0;
int Grille = 0;
int Ligne = 0 , Colonne = 0;
void MenuPrincipal()
{
     int choix = 0;
        do
        {
        system("cls");
        Color(14,0);
        printf("              -------------------------------------------\n");
        printf("             |               ");
        Color(7,0);
        printf("JEU D'AFFICHAGE");
        Color(14,0);
        printf("             |\n");
        printf("              -------------------------------------------\n");
        printf("             |                                           |\n");
        printf("             |    (1):");
        if(Grille == 0)
        {
            Color(7,0);
            printf("Creation de la grille              ");
        }
        else
        {
            Color(7,0);
            printf("Afficher la grille                 ");
        }
        Color(14,0);
        printf("|\n");
        printf("             |    (2):");
        Color(7,0);
        printf("Ajouter un point sur la grille     ");
        Color(14,0);
        printf("|\n");
        printf("             |    (3):");
        Color(7,0);
        printf("Supprimer le dernier point         ");
        Color(14,0);
        printf("|\n");
        printf("             |    (4):");
        Color(7,0);
        printf("Afficher la pile utilisee          ");
        Color(14,0);
        printf("|\n");
        printf("             |    (5):");
        Color(7,0);
        printf("Suppresion physique                ");
        Color(14,0);
        printf("|\n");
        printf("             |    (6):");
        Color(7,0);
        printf("Quitter                            ");
        Color(14,0);
        printf("|\n");
        printf("             |                                           |\n");
        printf("              -------------------------------------------\n");
        printf("\n");
        printf("                                                Choix: ");
        scanf("%d",&choix);
        Color(7,0);
        }while(choix < 1 || choix > 6);
        if(choix == 1 && Grille == 0) { CreationGrille(); MenuPrincipal();}
        else if(choix == 1 && Grille == 1) {AffichageGrille();MenuPrincipal();}
        else if(choix == 2 && Grille == 1) {AjoutPoint();MenuPrincipal();}
        else if(choix == 2 && Grille == 0)
            {
                Color(12,0);
                printf("\n\n\t Veuillez creer votre grille ");
                printf("\n\t pour que vous puissiez ajouter un point ");
                Sleep(3000);
                MenuPrincipal();
            }
        else if(choix == 3) {supprimer_dernier_tache();MenuPrincipal();}
        else if(choix == 4) {affichage_pile();MenuPrincipal();}
        else if(choix == 5) {supprimer_physiquement();MenuPrincipal();}
        else exit(0);
    return 0;
}
void CreationGrille()
{
    int test = 0;

    if(Grille == 0)
    {
        do
        {
        system("CLS");
        Color(14,0);
        printf(" \t ----------------------------------------\n");
        printf("\t|                                        |\n");
        printf("\t|     ");
        Color(7,0);
        printf("Creation de la grille              ");
        Color(14,0);
        printf("|\n");
        printf("\t|                                        |\n");
        printf("\t ----------------------------------------\n\n");
        Color(7,0);
        printf(" \t Saisir le nombre de  ligne : ");
        Color(14,0);
        scanf("%d",&Ligne);
        Color(7,0);
        printf(" \n\t Saisir le nombre de colonne : ");
        Color(14,0);
        scanf("%d",&Colonne);

        if(Ligne < 2 || Ligne > 20 || Colonne < 2 || Colonne > 20)
        {
            Color(12,0);
            printf("\n\t Erreur !");
        }
        if(Ligne < 2 || Ligne > 20 )
        {
            printf("\n\n\tle nombre de  ligne doit etre compris entre 2 et 20 ");
            test = 1;
            Sleep(2000);
        }
        if(Colonne < 2 || Colonne > 20)
        {
            printf("\n\n\tle nombre de  Colonne doit etre compris entre 2 et 20 ");
            test = 1;
            Sleep(2000);
        }
        if(test == 1)
        {
            Color(7,0);
            printf("\n\n\tVeuillez resaisir de nouveau \n");
            Sleep(2000);
        }
        test = 0;
        }while(Ligne < 2 || Ligne > 20 || Colonne < 2 || Colonne > 20  );
        Grille = 1;
    }


}
void AjoutPoint()
{
    int x  , y   , test = 0;

    if(sommet_emp < Ligne*Colonne)
    {
        do
    {
        system("CLS");
        Color(7,0);
        printf("\n\n\n\t\tVeuillez Saisir X :  ");
        Color(14,0);
        scanf("%d",&x);
        Color(7,0);
        printf("\n\n\t\tVeuillez Saisir Y :  ");
        Color(14,0);
        scanf("%d",&y);
        if(x < 1 || x > Colonne || y < 1 || y > Ligne)
        {
            Color(12,0);
            printf("\n\t Erreur !");
        }
        if(x < 1 || x > Ligne)
        {
            Color(12,0);
            printf("\n\n\tla ligne doit etre compris entre 1 et %d ",Ligne);
            test = 1;
            Sleep(2000);
        }
        if(y < 1 || y > Colonne)
        {
            Color(12,0);
            printf("\n\n\tla colonne doit etre compris entre 1 et %d ",Colonne);
            test = 1;
            Sleep(2000);
        }
        if(test == 1)
        {
            system("CLS");
            Color(7,0);
            printf("\n\n\tVeuillez resaisir les cordonnees  de nouveau \n");
            Sleep(2000);
        }
        test = 0;
    }while(x < 1 || x > Colonne || y < 1 || y > Ligne);
    emp[sommet_emp].x = x;
    emp[sommet_emp].y = y;
    sommet_emp++;
          Color(2,0);
          printf("\n\n\t Operation effectuee avec succes ");
          Sleep(2000);

    }
}
void supprimer_dernier_tache()
{
    if(sommet_emp > 0)
    {
    desemp[sommet_desemp].x = emp[sommet_emp-1].x;
    desemp[sommet_desemp].y = emp[sommet_emp-1].y;
    sommet_emp--;
    sommet_desemp++;

           system("CLS");
           printf("\n\n\t Veuillez patienter s'il vous plait ");
           printf(".");
           Sleep(800);
           printf(".");
           Sleep(800);
           printf(".");
           Sleep(800);
           system("CLS");
           Color(2,0);
           printf("\n\n\t Operation effectuee avec succes ");
           Sleep(2000);
    }
    else
    {
        if(Grille == 1)

        {
            system("CLS");
            Color(12,0);
            printf("\n\n\t Erreur !");
            printf("\n\t La grille est vide !");
            Sleep(3000);
        }
        else
        {
            system("CLS");
            Color(12,0);
            printf("\n\n\t Erreur !");
            printf("\n\t La grille n'est pas encore cree ");
            Sleep(3000);
        }
    }
}
void affichage_pile()
{
    int i;

      if(sommet_emp > 0)
      {
      system("CLS");
      Color(7,0);
      printf("\n\n\t\tX     Y");
      for(i = 0 ; i < sommet_emp ;i++)
      {
          Color(2,0);
          printf("\n\n\t\t%d     %d ",emp[i].x,emp[i].y);
      }
      printf("\n\n");
      Color(7,0);
      system("PAUSE");
      }
}
void supprimer_physiquement()
{
    int i;
    if(sommet_desemp > 0)
   {

    for(i = 0 ; i < sommet_desemp-1 ; i++)
    {
        desemp[i].x = desemp[i+1].x;
        desemp[i].y = desemp[i+1].y;
    }
     sommet_desemp--;
   }
}
void AffichageGrille()
{
    system("CLS");

    int i , j = 0 , l = 1, c;


    for(i = 0 ; i <= Colonne ; i++)
        {
            gotoxy(10+j,10);
            printf("%d",i);
            j = j +8;
        }
    for(j = 0,i = 0 ; i <= Ligne ; i++)
        {
            gotoxy(10,10+j);
            printf("%d",i);
            j = j +5;
        }
     for(j = 0 ; j <= Ligne; j++)
     {
         for(i = 0 ; i < Colonne ; i++)
       {
            gotoxy(11+i*8,11+j*5);
            printf("--------");
       }
     }
     for(j = 0 ; j <= Colonne; j++)
     {
         for(i = 0 ; i <= Ligne*5 ; i++)
       {
            gotoxy(11+j*8,11+i);
            printf("|");
       }
     }



                    for(i = (sommet_emp)-1 ; i >= 0 ; i--)
                    {
                        Color(2,0);
                        gotoxy(10+emp[i].x*8,10+emp[i].y*5);
                        printf("*");
                    }
                    for(i = (sommet_desemp)-1 ; i >= 0 ; i--)
                    {
                        Color(12,0);
                        gotoxy(10+desemp[i].x*8,10+desemp[i].y*5);
                        printf("*");
                    }



        gotoxy(10,60);
        Color(2,0);
        printf("   * ");
        Color(7,0);
        printf(": trace d'un point existant \n");
        gotoxy(10,62);
        Color(12,0);
        printf("   * ");
        Color(7,0);
        printf(": trace d'un point supprime \n");

        gotoxy(10,65);
        system("PAUSE");

}
int main()
{
    MenuPrincipal();
    return 0;
}
