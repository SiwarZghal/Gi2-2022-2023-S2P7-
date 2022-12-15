// définition des broches

#define capteurGauche D0 //GPIO 16
#define capteurDroite D8 //GPIO 5

#define pinAvanceDroite D2 // GPIO 4 // Premier moteur
#define pinReculeDroite D3 // GPIO 0 // Premier moteur
#define pinVitesseDroite D4 // GPIO 2 //broche enable du L298N pour le premier moteur
#define pinAvanceGauche D5 // GPIO 14 //Deuxième moteur
#define pinReculeGauche D6 // GPIO 12  //Deuxième moteur
#define pinVitesseGauche D7 //  GPIO 13 //broche enable du L298N pour le deuxième moteur

//const int sensibilite = 50; // écart admissible par rapport à la valeur initiale

int initialDroite; // état initial du capteur de droite
int initialGauche; // état initial du capteur de gauche

int vitesse = 70; // 0 à 1023 PWM qui contrôle la vitesse des moteurs

void setup() {

  // réglage des sorties
  pinMode(pinAvanceDroite, OUTPUT);
  pinMode(pinReculeDroite, OUTPUT);
  pinMode(pinVitesseDroite, OUTPUT);
  pinMode(pinAvanceGauche, OUTPUT);
  pinMode(pinReculeGauche, OUTPUT);
  pinMode(pinVitesseGauche, OUTPUT);
  //réglage des entrées
   pinMode(capteurGauche, INPUT);
   pinMode(capteurDroite, INPUT);
 // on demeure immobile pour l'instant
  digitalWrite(pinVitesseDroite, 0);
  digitalWrite(pinVitesseGauche, 0);
  


}

void loop() {
  int valeurDroite, valeurGauche;

  valeurDroite = digitalRead(capteurDroite);
  valeurGauche = digitalRead(capteurGauche);

   if (valeurGauche!=0) {
    // on tourne à gauche
    avancerDroite(80);
    avancerGauche(vitesse);
  }

  else if (valeurDroite!=0) {
    // on tourne à droite
    avancerGauche(80);
    avancerDroite(vitesse);
  }


  else {
    // on s'arrête
     avancerDroite(vitesse);
     avancerGauche(vitesse);
  }

/*

if (capteurD){
tourner droite
}else if( capteurGauche)à{
tourner gauche
}else{
avanver}

*/

  delay(100);
}
     // Procédure avance Droite
void avancerDroite(int vitesse){
  digitalWrite(pinAvanceDroite,1);
  digitalWrite(pinReculeDroite,0);
  analogWrite(pinVitesseDroite,vitesse);}

   // Procédure avance Gauche
void avancerGauche(int vitesse){
  digitalWrite(pinAvanceGauche,1);
  digitalWrite(pinReculeGauche,0);
  analogWrite(pinVitesseGauche,vitesse);}

   // Procédure recule Gauche
void reculeGauche(int vitesse){
  digitalWrite(pinAvanceGauche,0);
  digitalWrite(pinReculeGauche,1);
  analogWrite(pinVitesseGauche,vitesse);}

   // Procédure recule Droite
void reculeDroite(int vitesse){
  digitalWrite(pinAvanceDroite,0);
  digitalWrite(pinReculeDroite,1);
  analogWrite(pinVitesseDroite,vitesse);}



  
