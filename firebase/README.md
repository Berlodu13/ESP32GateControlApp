# Firebase Configuration for ESP32GateControlApp

## ESP32 Configuration
1. Create a Firebase project at https://console.firebase.google.com
2. Enable Firestore Database in test mode.
3. Go to Project Settings > General > Your apps > Add app (select Web or Android).
4. Copy the Firebase config object and paste it into `firebase_config.json`.

## Android Configuration
1. Add Firebase to your Android project using Firebase Assistant in Android Studio.
2. Download `google-services.json` and place it in your app module.
3. Use the same Firebase project as configured for ESP32.

## Firestore Rules
Use the `firestore.rules` file to define access permissions.

## Firestore Structure
Refer to `firestore_structure.json` for an example database structure.
