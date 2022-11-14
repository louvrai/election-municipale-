#include "Gestion_bv.h"
#include<stdio.h>
int ajouter(Gestion_bv p  , char filename [])
{
FILE * f=fopen(filename, "a");
if(f!=NULL)
{
fprintf(f,"%d %d %d %d %s%d\n",p.id,p.cap_electeur,p.cap_observateur,p.salle,p.adresse,p.id_agent);
fclose(f);
return 1;
}
else 
return 0;
}

int modifier(int id, Gestion_bv nouv, char * filename)

{
Gestion_bv p;
FILE * f=fopen(filename, "r");
FILE * f2 =fopen("aux.txt", "w");
if(f==NULL || f2==NULL)
return 0;
else
{
while(fscanf(f,"%d %d %d %d %s%d\n",p.id,p.cap_electeur,p.cap_observateur,p.salle,p.adresse,p.id_agent)!=EOF)
{
if(p.id!=id)
fprintf(f2,"%d %d %d %d %s%d\n",p.id,p.cap_electeur,p.cap_observateur,p.salle,p.adresse,p.id_agent);
else
fprintf(f2,"%d %d %d %d %s%d\n",nouv.id,nouv.cap_electeur,nouv.cap_observateur,nouv.salle,nouv.adresse,nouv.id_agent);
}
fclose(f);
fclose(f2);
remove(filename);
rename("aux.txt", filename);
return 1;
}
}


int supprimer(int id, char * filename)

{
Gestion_bv p;
FILE * f=fopen(filename, "r");
FILE * f2 =fopen("aux.txt", "w");
if(f==NULL || f2==NULL)
return 0;
else
{
while(fscanf(f,"%d %d %d %d %s%d\n",p.id,p.cap_electeur,p.cap_observateur,p.salle,p.adresse,p.id_agent)!=EOF)
{
if(p.id!=id)
fprintf(f2,"%d %d %d %d %s%d\n",p.id,p.cap_electeur,p.cap_observateur,p.salle,p.adresse,p.id_agent);

}
fclose(f);
fclose(f2);
remove(filename);
rename("aux.txt", filename);
return 1;
}
}
Gestion_bv chercher(int id, char * filename)
{
Gestion_bv p; 
int tr=0;
FILE * f=fopen(filename, "r");
if(f!=NULL )
{
while(fscanf(f,"%d %d %d %d            %s%d\n",p.id,p.cap_electeur,p.cap_observateur,p.salle,p.adresse,p.id_agent)!=EOF &&tr==0)
{
if(id==p.id)
tr=1;
}
}
if(tr==0)
p.id=-1;
return p;
}
