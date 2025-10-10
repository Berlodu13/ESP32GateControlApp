# MySQL Setup for ESP32GateControlApp

Ce dossier contient les fichiers nécessaires pour configurer une base de données MySQL pour gérer les accès du portail via ESP32.

## Fichiers inclus :
- `schema.sql` : script de création de la base et des tables.
- `data.sql` : insertion de données de test.
- `db_connect.php` : script de connexion à la base MySQL.
- `api_gate.php` : exemple d'API PHP pour interagir avec la base.

## Instructions :
1. Importer `schema.sql` dans votre serveur MySQL.
2. Exécuter `data.sql` pour insérer des données de test.
3. Configurer les identifiants dans `db_connect.php`.
4. Déployer `api_gate.php` sur votre serveur web PHP.
