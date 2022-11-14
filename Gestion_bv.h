#ifndef GESTION_BV_H_INCLUDED
#define GESTION_BV_H_INCLUDED



typedef struct
{
int id;
int cap_electeur;
int cap_observateur;
int salle;
char adresse [20];
int id_agent;
}Gestion_bv;


int ajouter(Gestion_bv p , char filename []);

int modifier(int id, Gestion_bv nouv, char * filename);
int supprimer(int id, char * filename);
Gestion_bv chercher(int id, char * filename);
#endif // POINT_H_INCLUDED

