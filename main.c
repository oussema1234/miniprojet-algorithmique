#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct process
{
int PID;

int TE;
int priority;
}process;

//remplir
void remplir( process *proc,int nb) {



   for(int i=0;i<nb;i++)
   {
   proc[i].PID=i+1;
     proc[i].TE = (1 + rand()%20);
      proc[i].priority = (1 + rand()%20);
    //printf("%d %d %d",proc[i].priority,proc[i].TE);

   }
}

//tri fusion
void fusion(process *tableau,int deb1,int fin1,int fin2)
        {
        process *table1;
        int deb2=fin1+1;
        int compt1=deb1;
        int compt2=deb2;
        int i;

        table1=malloc((fin1-deb1+1)*sizeof(int));

        //on recopie les éléments du début du tableau
        for(i=deb1;i<=fin1;i++)
            {
            table1[i-deb1]=tableau[i];
            }

        for(i=deb1;i<=fin2;i++)
            {
            if (compt1==deb2) //c'est que tous les éléments du premier tableau ont été utilisés
                {
                break; //tous les éléments ont donc été classés
                }
            else if (compt2==(fin2+1)) //c'est que tous les éléments du second tableau ont été utilisés
                {
                tableau[i]=table1[compt1-deb1]; //on ajoute les éléments restants du premier tableau
                compt1++;
                }
            else if (table1[compt1-deb1].priority/table1[compt1-deb1].TE<tableau[compt2].priority/tableau[compt2].TE)
                {
                tableau[i]=table1[compt1-deb1]; //on ajoute un élément du premier tableau
                compt1++;
                }
            else
                {
                tableau[i]=tableau[compt2]; //on ajoute un élément du second tableau
                compt2++;
                }
            }

        }


void tri_fusion_bis(process *tableau,int deb,int fin)
        {
        if (deb!=fin)
            {
            int milieu=(fin+deb)/2;
            tri_fusion_bis(tableau,deb,milieu);
            tri_fusion_bis(tableau,milieu+1,fin);
            fusion(tableau,deb,milieu,fin);
            }
        }

void tri_fusion(process *tableau,int longueur)
     {
     if (longueur>0)
            {
            tri_fusion_bis(tableau,0,longueur-1);
            }
     }
//tri bulle

void bulle(process *proc, int nb){
process permut;

for(int j=1;j<=nb;j++)
for(int i=0;i<nb-1;i++)
{
if (proc[i].priority/proc[i].TE<proc[i+1].priority/proc[i+1].TE)
{
permut=proc[i];
proc[i]=proc[i+1];
proc[i+1]=permut;
}

}
}


//tri selection
void selection(process *proc, int nb){

process permut;
for(int i=0;i<nb+1;i++)
for(int j=i+1;j<nb;j++)
{
if (((proc[i].priority)/(proc[i].TE))<((proc[j].priority)/(proc[j].TE)))
{
permut=proc[i];
proc[i]=proc[j];
proc[j]=permut;
}

}

}


//tri shell
void tri_shell(process *tableau,int longueur)
     {
     int n, i, j;
     process valeur;

     n=0;

     while(n<longueur)
         {
         n=3*n+1;
         }

     while(n!=0)
         {
         n=n/3;
         for (i=n;i<longueur;i++)
             {
             valeur=tableau[i];
             j=i;

             while((j>(n-1)) && (tableau[j-n].priority/tableau[j-n].TE <valeur.priority/valeur.TE))
                 {
                 tableau[j]=tableau[j-n];
                 j=j-n;
                 }
             tableau[j]=valeur;
             }
         }
     }

//tri insertion
void insertion(process *proc, int nb)
{
process element;
int cpt;
for (int i = 1; i < nb ; i++)
    {
        element = proc[i];
        cpt = i - 1;
        while ((cpt >= 0) && ((proc[cpt].priority/proc[cpt].TE) < (element.priority/element.TE)))
        {
           proc[cpt + 1] = proc[cpt];
           cpt--;
        }
        proc[cpt + 1] = element;
    }


printf("\n");
}

void afficher(process *proc, int nb)
{
/*Afficher l'ordonnancement choisi*/
printf("Ordonnancement\n'");


/*Afficher la date d'arrivee, le temps d'execution et la priorité de chaque processus*/
printf("PID\t TE\t priorite\t \n ");
for ( int i=0;i<nb;i++)
{
printf("%d\t %dms \t %d \t  \n ",proc[i].PID,proc[i].TE,proc[i].priority);
}

}

int main(){
int nb;
process *proc;

printf ("entrer le nombre de tache\n");
scanf("%d",&nb);

proc=( process *)malloc(sizeof( process )*nb);

remplir(proc,nb);
bulle(proc,nb);
afficher(proc,nb);
insertion(proc,nb);
afficher(proc,nb);
selection(proc,nb);
afficher(proc,nb);
tri_fusion(proc,nb);
afficher(proc,nb);
tri_shell(proc,nb);
afficher(proc,nb);
}
