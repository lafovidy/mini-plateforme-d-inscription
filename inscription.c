/*VARIABLES:
    i:entiers
    noms[50]:chaine de caractere
    prenoms[50]:chaine de caractere
    age:entiers
    addresse[50]:chaine de caractere
    niveau[3]:chaine de caractere
    naissance[50]:chaine de caractere
  DEBUT
    structure info
    {
      noms[50]
      prenoms[50]
      age
      addresse[50]
      niveau
      naissance[50]
    }
    DEF recup(*no:chaine de caractere,*p:chaine de caractere,*a:entiers,*ad:chaine de caractere,*ni:chaine de caractere,*na:chaine de caractere)
      AFFICHER("Entrez votre Noms: ")
      LIRE(no)
      AFFICHER("Entrez votre prenoms: ")
      LIRE(basep)
      AFFICHER("Entrez votre age: ")
      LIRE(a)
      AFFICHER("Entrez votre addresse: ")
      LIRE(ad)
      AFFICHER("Entrez votre niveau d'étude :")
      LIRE(ni)
      AFFICHER("Entrez votre date de naissance: ")
      LIRE(na)
    FINDEF
    DEF envoi(*no:chaine de caractere,*p:chaine de caractere,*a:entiers,*ad:chaine de caractere,*ni:chaine de caractere,*na:chaine de caractere)
      base1:fichier
      base2:fichier
      base3:fichier
      basem1:fichier
      basem2:fichier
      SI(base1=NULL)ALORS
        AFFICHER("ERREUR!")
        QUITTER
      SINON
        OUVRIR("base1","a")
      FINSI
      SI(base2=NULL)ALORS
        AFFICHER("ERREUR!")
        QUITTER
      SINON
        OUVRIR("base2","a")
      FINSI
      SI(base3=NULL)ALORS
        AFFICHER("ERREUR!")
        QUITTER
      SINON
        OUVRIR("base3","a")
      FINSI
      SI(basem1=NULL)ALORS
        AFFICHER("ERREUR!")
        QUITTER
      SINON
        OUVRIR("basem1","a")
      FINSI
      SI(basem2=NULL)ALORS
        AFFICHER("ERREUR!")
        QUITTER
      SINON
        OUVRIR("basem2","a")
      FINSI
      SI(n[i]="L1")ALORS
        FAFFICHER(base1,structure info,noms,prenoms,age,addresse,niveau,naissance)
        FFERMER(base1)
      SINON SI(ni[1]='L2')ALORS
        FAFFICHER(base2,structure info,noms,prenoms,age,addresse,niveau,naissance)
        FFERMER(base2)
      SINON SI(ni[1]='L3')ALORS
        FAFFICHER(base3,structure info,noms,prenoms,age,addresse,niveau,naissance)
        FFERMER(base3)
      SINON SI(ni[1]='M1')ALORS
        FAFFICHER(basem1,structure info,noms,prenoms,age,addresse,niveau,naissance)
        FFERMER(basem1)
      SINON SI(ni[1]='M2')ALORS
        FAFFICHER(base1,structure info,noms,prenoms,age,addresse,niveau,naissance)
        FFERMER(basem2)
      FINSI
    FINDEF
    DEF menu()
      recherche[50]:chaine de caractere
      reponse[11]:chaine de caractere
      AFFICHER("Voulez vous rechercher par nom ou par prénoms ou par addresse ou par date de naissance)
      LIRE(reponse)
      SI(reponse='nom')ALORS
        AFFICHER("Entrez le nom: ")
        LIRE(recherche)
      SINON SI(reponse='prénoms')ALORS
        AFFICHER("Entrez le prénom: ")
        LIRE(recherche)
      SINON SI(reponse='addresse')ALORS
        AFFICHER("Entrez l'addresse: ")
        LIRE(recherche)
      SINON SI(reponse='date de naissance')ALORS
        AFFICHER("Entrez la date de naissance: ")
        LIRE(recherche)
      FINSI
    RETOURNER(recherche)
    DEF affichage() 
      test=0
      TANTQUE(NON EOF(L1),structure info)
        FLIRE(L1,structure info)
        SI(r=structure info.nom)ALORS
          AFFICHER(strucure info)
          test=1
        SINON SI(r=structure info.prenom)ALORS
          AFFICHER(structure info)
          test=1
        SINON SI(r=structure info.addresse)ALORS
          AFFICHER(structure info)
          test=1
        SINON SI(r=structure info.naissance)ALORS
          AFFICHER(structure info)
          test=1
        FINSI
      FINPOUR
        SI(test=0)ALORS
          AFFICHER("Désolé mais on n'a pas trouvé un tel étudiant")
        FINSI
    FINDEF
  FIN*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Info info;
struct Info
{
  char noms[50];
  char prenoms[50];
  int age;
  char addresse[100];
  char niveau[3];
  char naissance[20];
};
void recup(char *no,char *pr,int *ag,char *ad,char *ni,char *na);
void envoi(char *no,char *pr,int *ag,char *ad,char *ni,char *na);
int comparaison(const char *s1,const char *s2);
void tri(const char *nomFichier);
void tri_base();
void menu(char *recherche);
void affichage(char *recherche);
void recup(char *no,char *pr,int *ag,char *ad,char *ni,char *na)
{
  printf("Entrez votre noms: ");
  fgets(no,50,stdin);
  printf("Entrez votre prénoms:");
  fgets(pr,50,stdin);
  printf("Entrez votre date de naissance(exemple:12/3/2008):");
  scanf("%s",na);
  printf("Entrez votre age: ");
  scanf("%d",ag);
  getchar();
  printf("Entrez votre addresse: ");
  fgets(ad,100,stdin);
  printf("Entrez votre niveau d'étude: ");
  scanf("%s",ni);
  getchar();
}
void envoi(char *no,char *pr,int *ag,char *ad,char *ni,char *na)
{
  FILE *base1;
  FILE *base2;
  FILE *base3;
  FILE *basem1;
  FILE *basem2;
  base1=fopen("base1","a");
  base2=fopen("base2","a");
  base3=fopen("base3","a");
  basem1=fopen("basem1","a");
  basem2=fopen("basem2","a");
  if(base1==NULL||base2==NULL||base3==NULL||basem1==NULL||basem2==NULL)
  {
    printf("ERREUR!");
    exit(0);
  }
  if(ni[0]=='L'&&ni[1]=='1')
  {
    fprintf(base1,"%s;%s;%d;%s;%s;%s\n",no,pr,*ag,ad,ni,na);
    fclose(base1);
  }
  if(ni[0]=='L'&&ni[1]=='2')
  {
    fprintf(base2,"%s;%s;%d;%s;%s;%s\n",no,pr,*ag,ad,ni,na);
    fclose(base2);
  }
  if(ni[0]=='L'&&ni[1]=='3')
  {
    fprintf(base3,"%s;%s;%d;%s;%s;%s\n",no,pr,*ag,ad,ni,na);
    fclose(base3);
  }
  if(ni[0]=='M'&&ni[1]=='1')
  {
    fprintf(basem1,"%s;%s;%d;%s;%s;%s\n",no,pr,*ag,ad,ni,na);
    fclose(basem1);
  }
  if(ni[0]=='M'&&ni[1]=='2')
  {
    fprintf(basem2,"%s;%s;%d;%s;%s;%s\n",no,pr,*ag,ad,ni,na);
    fclose(basem2);
  }
}
int comparaison(const char *s1,const char *s2)
{
  int i=0;
  while(s1[i]!='\0'&&s2[i]!='\0')
  {
    char c1=s1[i];
    char c2=s2[i];
    if(c1>='A'&&c1<='Z')
    {
      c1+=32;
    }
    if(c2>='A'&&c2<='Z')
    {
      c2+=32;
    }
    if(c1!=c2)
    {
      return(c1-c2);
    }
    i+=1;
  }
  char c1=s1[i];
  char c2=s2[i];
  if(c1>='A'&&c1<='Z')
  {
    c1+=32;
  }
  if(c2>='A'&&c2<='Z')
  {
    c2+=32;
  }
  return(c1-c2);
}
void tri(const char *nomFichier)
{
  FILE *fichier=fopen(nomFichier,"r");
   int i,j;
   info temp;
  if(fichier==NULL)
  {
    printf("ERREUR!");
    exit(0);
  }
  info tableau[500];
  int taille=0;
  while(fscanf(fichier,"%[^;];%[^;];%d;%[^;];%[^;];%[^\n]\n",tableau[taille].noms,tableau[taille].prenoms,&tableau[taille].age,tableau[taille].addresse,tableau[taille].niveau,tableau[taille].naissance)==6)
  {
    taille+=1;
    if(taille>=500)
    {
      break;
    }
  }
  fclose(fichier);
  if(taille<=1)
  {
    exit(0);
  }
  for(i=0;i<taille-1;i+=1)
  {
    for(j=0;j<taille-i-1;j+=1)
    {
      if(comparaison(tableau[j].noms,tableau[j+1].noms)>0)
      {
        temp=tableau[j];
        tableau[j]=tableau[j+1];
        tableau[j+1]=temp;
      }
    }
  }
  fichier=fopen(nomFichier,"w");
  if(fichier==NULL)
  {
    printf("ERREUR!");
    exit(0);
  }
  for(i=0;i<taille;i+=1)
  {
    fprintf(fichier,"%s;%s;%d;%s;%s;%s",tableau[i].noms,tableau[i].prenoms,tableau[i].age,tableau[i].addresse,tableau[i].niveau,tableau[i].naissance);
  }
  fclose(fichier);
}
void tri_base()
{
  tri("base1");
  tri("base2");
  tri("base3");
  tri("basem1");
  tri("basem2");
}
void menu(char *recherche)
{
  char reponse[50];
  printf("Voulez vous faire une recherche par noms ou par prenoms ou par adresse ou par date de naissance: ");
  fgets(reponse,sizeof(reponse),stdin);
  reponse[strcspn(reponse,"\n")]='\0';
  if(strcmp(reponse,"noms")==0)
  {
    printf("Entrez le noms: ");
    scanf("%s",recherche);
  }
  else if(strcmp(reponse,"prenoms")==0)
  {
    printf("Entrez le prenoms: ");
    scanf("%s",recherche);
  }
  else if(strcmp(reponse,"addresse")==0)
  {
    printf("Entrez l'addresse: ");
    scanf("%s",recherche);
  }
  else if(strcmp(reponse,"date de naissance")==0)
  {
    printf("Entrez la date de naissance: ");
    scanf("%s",recherche);
  }
  else if(strcmp(reponse,"non")==0)
  {
    printf("OK\n");
  }
  getchar();
}
void affichage(char *recherche)
{
  int i,j,test;
  char *fichiers[]={"base1","base2","base3","basem1","basem2"};
  info temp;
  int trouve=0;
  for(j=0;j<5;j+=1)
  {
    FILE *fichier=fopen(fichiers[j],"r");
    if(fichier==NULL) continue;
    while(fscanf(fichier,"%[^;];%[^;];%d;%[^;];%[^;];%s\n",temp.noms,temp.prenoms,&temp.age,temp.addresse,temp.niveau,temp.naissance)==6)
    {
      i=0;
      test=1;
      while(temp.noms[i]!='\0'&&recherche[i]!='\0')
      {
        if(temp.noms[i]!=recherche[i])
        test=0;
        break;
      i+=1;
     }
      if (test==1)
      {
        printf("Etudiant trouvée dans %s :\n",fichiers[j]);
        printf("Noms: %s | Prenoms: %s | age: %d | addresse: %s | niveau: %s | date de naissance: %s\n ",temp.noms,temp.prenoms,temp.age,temp.addresse,temp.niveau,temp.naissance);
        trouve=1;
      }
    }
    fclose(fichier);
    if(trouve==0)
    {
      printf("Désolé mais cette personne n'est pas enconre inscrit\n");
    }
  }
}
int main()
{
  info tab_info[100];
  char recherche[50];
  int i=0;
  int continuer=1;
  while(continuer==1&&i<100)
  {
    recup( tab_info[i].noms,tab_info[i].prenoms,&tab_info[i].age,tab_info[i].addresse,tab_info[i].niveau,tab_info[i].naissance);
    envoi(tab_info[i].noms,tab_info[i].prenoms,&tab_info[i].age,tab_info[i].addresse,tab_info[i].niveau,tab_info[i].naissance);
    i+=1;
    printf("Voulez vous continuer ?(1 pour oui ,0 pour non: ");
    scanf("%d",&continuer);
    getchar();
  }
  tri_base();
  menu(recherche);
  affichage(recherche);
  return(0);
}
