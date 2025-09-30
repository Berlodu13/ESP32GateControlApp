
# ESP32GateControlApp

**ESP32GateControlApp** est une solution complète de contrôle d’accès pour portail motorisé, basée sur un microcontrôleur **ESP32**.  
Elle intègre des modules **RF**, **SIM800L**, **caméras**, **relais**, **capteurs PIR**, **enregistrement sur carte SD**, **commande vocale**, et une **application Android** connectée à **Firebase**.

Ce projet est conçu pour être **modulaire**, **sécurisé**, **connecté à distance**, et **facile à installer**.

## 🚀 Fonctionnalités principales

- Ouverture/fermeture du portail via :
  - Télécommande RF
  - Application Android
  - Appel téléphonique (SIM800L)
  - Détection de mouvement (PIR)
  - Commande vocale locale
- Notifications Firebase Cloud Messaging
- Enregistrement vidéo/image sur carte SD
- Interface Android avec journal d’accès
- Authentification Firebase (email/mot de passe)
- Mode maintenance avec désactivation des capteurs



## 🔧 Matériel requis

ComposantRéférenceLien/QR CodeESP32 DevKitESP32-WROOM-32✅ Inclus
Module RF433MHz Receiver✅ Inclus
Module relais2-Channel Relay✅ Inclus
Module SIMSIM800L✅ Inclus
CaméraOV2640 (ESP32-CAM)✅ Inclus
Carte microSD16Go Class 10✅ Inclus
Capteur PIRHC-SR501✅ Inclus
 Alimentation      | 5V 2A + régulateur AMS | ✅ Inclus     |



## 📐 Schémas et câblage

- Schéma fonctionnel : `Schematics/Schematics.png`
- Plan de câblage : inclus dans le guide PDF
- Tableau du matériel : `Hardware_Table.xlsx`

Chaque composant est identifié avec un QR code pour l’achat rapide.


## 🛠️ Guide d'installation

Le guide complet est disponible dans `Installation_Guide/Installation_Guide.pdf`.

Il contient :
- Étapes de câblage
- Configuration de l’ESP32
- Flash du firmware
- Connexion Firebase
- Déploiement de l’application Android


## ☁️ Intégration Firebase

- Authentification : Email/Mot de passe
- Firestore : Journal d’accès, utilisateurs, logs
- Cloud Messaging : Notifications push
- Stockage : (optionnel) pour les images

Le fichier `google-services.json` est à placer dans :
- `/ESP32/credentials/` pour l’ESP32
- `/AndroidApp/app/` pour l’application Android






## 📁 Structure du dépôt




ESP32GateControlApp/
├── ESP32_Code/              # Code source ESP32 (RF, SIM, relais, caméras, SD, etc.)
├── Schematics/              # Schémas fonctionnels et de câblage
├── AndroidApp/              # Projet Android Studio
├── Installation_Guide/      # Guide PDF d’installation
├── Hardware_Table/          # Tableau Excel du matériel avec QR codes
├── Firebase_Config/         # Structure Firestore et Auth
├── README.md                # Documentation du projet







