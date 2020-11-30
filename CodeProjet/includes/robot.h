/* 
 * File:   robot.h
 * Author: Eric
 *
 * Created on 24 juillet 2019
 * Rôle : déclaration du robot et de ses fonctions
 * Historique : 
 *  19/11/2019 Marie-Pierre Pinaud Ajout Commentaires des fonctions + Rôle du fichier
 *  19/11/2019 Marie-Pierre Pinaud Ajout de T au début des noms des types
 *  19/11/2019 Marie-Pierre Pinaud modification du paramètre parcoursTermine
 */
#ifndef FONCTIONS_H
#define	FONCTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define SEUIL_BATTERIE 20 // pourcentage de batterie minimum pour faire l'exploration
#define DISTANCE_A_PARCOURIR 40000 // millimetres, par exemple 10 x longueur + 10 x largeur piscine
#define SEUIL_ACCELERATION_VERTICALE 20 // pourcentage
#define TEMPS_ATTENTE_IMMERSION 5 // secondes

    



/*****************************************************************************
*Type : TRobot                               
* Rôle : Contient les informations d'un robot
******************************************************************************/
typedef struct {
    unsigned char niveauBatterie;
    unsigned int distanceParcourue; // mm
    
} TRobot;
 


/*****************************************************************************
*Nom : initialiserRobot                                
* Rôle : initialise le robot (sa distance parcourue et le type de trajet) 
*        et configure les moteurs et les capteurs du moway                             
*Paramètres d'E/S :   robot qu'il faut initialiser                                   
******************************************************************************/
void initialiserRobot(TRobot* robot);


/*****************************************************************************
*Nom : chargeInsuffisante                                
* Rôle : vérifie s'il y a assez de batterie pour faire l'exploration                        
*Paramètres d'Entrée :   robot dont on vérifie la charge de batterie     
*Valeur de retour :   1 si batterie insuffisante, 0 s'il y a assez de batterie                               
******************************************************************************/
unsigned char chargeInsuffisante(TRobot* robot);


/*****************************************************************************
*Nom : attendreImmersion                                
* Rôle : attend que le robot soit à l'horizontal. Si le temps d'attente 
* d'immersion est dépassé, termine sur état irrécupérable.                                                               
******************************************************************************/
void attendreImmersion();


/*****************************************************************************
*Nom : explorerPiscine                                
* Rôle : gère l'exploration de la piscine                                 
*Paramètres d'E/S :   robot utilisé pour l'exploration                                    
******************************************************************************/
void explorerPiscine(TRobot* robot);


/*****************************************************************************
*Nom : terminerSurBatterieDechargee                                
* Rôle : arrêter le robot et le faire clignoter en rouge lent                                                                   
******************************************************************************/
void terminerSurBatterieDechargee();

/*****************************************************************************
*Nom : terminerSurEtatIrrecuperable                                
* Rôle : arrêter le robot et le faire clignoter en rouge rapide                                                                   
******************************************************************************/
void terminerSurEtatIrrecuperable();

/*****************************************************************************
*Nom : terminerParcours                                
* Rôle : arrêter le robot et le faire clignoter en vert                                                                  
******************************************************************************/
void terminerParcours();


/*****************************************************************************
*Nom : bordAtteint                                
* Rôle : vérifie si un bord de la piscine est atteint  
*Valeur de retour :   1 si un bord est atteint, 0 sinon                               
******************************************************************************/
unsigned char bordAtteint();

/*****************************************************************************
*Nom : parcoursTermine                                
* Rôle : vérifie si le robot a parcouru la distance voulue                            
*Paramètres d'Entrée :   robot utilisé pourl'exploration     
*Valeur de retour :   1 si la distance a été parcourue, 0 sinon                             
******************************************************************************/
unsigned char parcoursTermine(TRobot* robot);



/*****************************************************************************
*Nom :robotRetourne                                
* Rôle : vérifie si le robot est toujours à l(horizontale                            
*Valeur de retour :   1 si le robot est retourné, 0 sinon                             
******************************************************************************/
unsigned char robotRetourne();





#ifdef	__cplusplus
}
#endif

#endif	/* FONCTIONS_H */

