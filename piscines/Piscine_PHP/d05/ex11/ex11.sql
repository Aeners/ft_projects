SELECT UPPER(fiche_personne.nom) AS NOM, prenom, prix 
FROM `membre` INNER JOIN fiche_personne 
ON membre.id_fiche_perso=fiche_personne.id_perso 
INNER JOIN abonnement ON abonnement.id_abo = membre.id_abo 
WHERE prix > 42 ORDER BY nom, prenom ASC;
