# Station environnementale connectée – ESP32

Ce dépôt contient le **code source complet** associé au projet de **station environnementale connectée** présenté dans l’ouvrage :

> **Concevoir une station environnementale connectée – De l’idée à l’exploitation des données**

Le projet adopte une approche pédagogique et progressive, couvrant l’ensemble du cycle de conception d’un système IoT : choix du matériel, architecture logicielle, gestion du temps, connectivité réseau, structuration des données et exploitation à long terme.

---

## 🎯 Objectifs du projet

- Concevoir une station environnementale simple, fiable et évolutive  
- Mesurer des paramètres environnementaux :
  - température  
  - humidité  
  - pression atmosphérique  
  - qualité de l’air  
- Mettre en place une architecture logicielle claire  
- Structurer les données de manière cohérente  
- Préparer l’envoi et l’exploitation des données  
- Fournir une base solide pour des évolutions futures  

Ce dépôt **complète le livre** en fournissant l’intégralité du code source, maintenu indépendamment de l’ouvrage.

---

## 🧱 Architecture générale

- **Microcontrôleur** : ESP32  
- **Capteurs** :
  - BME280 (température, humidité, pression – bus I²C)
  - MQ-135 (qualité de l’air – entrée analogique)
- **Communication réseau** : Wi-Fi  
- **Environnement de développement** :
  - Arduino IDE
  - ou PlatformIO  

---

## 📁 Organisation du dépôt

La structure du dépôt reflète directement la progression du livre et permet une montée en complexité progressive.


Chaque dossier contient un programme autonome correspondant à une étape précise du projet.

---

## 🚀 Utilisation recommandée

1. Lire le chapitre correspondant dans le livre  
2. Ouvrir le dossier associé dans `firmware/`  
3. Compiler et téléverser le programme sur l’ESP32  
4. Observer le comportement via le moniteur série  
5. Passer à l’étape suivante  

Il est **fortement recommandé** de suivre l’ordre proposé afin de conserver la cohérence pédagogique.

---

## ⚠️ Configuration Wi-Fi

Les exemples Wi-Fi utilisent volontairement des identifiants génériques :

```cpp
const char* ssid = "VOTRE_SSID";
const char* password = "VOTRE_MOT_DE_PASSE";

