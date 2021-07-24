#include "aes_main.h"


void AES_main::Erreur(char* fonction)
{
    fprintf(stderr, "Erreur %s 0x%x\n", fonction, GetLastError());
}

void AES_main::Message(char* message)
{
    fprintf(stdout, "%s", message);
    //ui->field->setText("") ;
   // ui->field->setText(message) ;
}

void AES_main::Initialiser()
{
    // Initialisation SERVICES DE CRYPTOGRAPHIE schannel
    //supporte les algorith;es de cryptograp aes128  , 3des
    Message("\n[Initialisation]\n");

    Message("CryptAcquireContext...\n");//different de non null
    if(!CryptAcquireContext(&cryptographicServiceProvider,
                            NULL, //taile de con
                            NULL,
                            PROV_RSA_AES,
                            CRYPT_VERIFYCONTEXT))
        Erreur("CryptAcquireContext");
}

void AES_main::Nettoyer()
{
    // Nettoyage ( apres utilisation de la clé on supprime la clé)
   // Message("\n[Nettoyage]\n");

    if (this->clef)
    {
        Message("CryptDestroyKey...\n");
        CryptDestroyKey(this->clef);
        this->clef = 0;
    }

    if (cryptographicServiceProvider)
    {
        Message("CryptReleaseContext...\n");
        CryptReleaseContext(cryptographicServiceProvider, 0);
        cryptographicServiceProvider = 0;
    }
}

void AES_main::GenererClef()
{
    DWORD modeChiffrement = CRYPT_MODE_CBC;

    Message("\n[Generation de la clef]\n");

    Message("CryptGenKey...\n");
    if(!CryptGenKey(cryptographicServiceProvider,
                    CALG_AES_256,
                    CRYPT_EXPORTABLE,
                    &this->clef))
        Erreur("CryptGenKey");

    CryptSetKeyParam(this->clef, KP_MODE,(BYTE*)&modeChiffrement, NULL);
}


void AES_main::ExporterClef(char* nomFichier) // de binaire à chaine( quitte de la memoire pour écrire dans le fichier)
{
    // Déclaration des variables locales
    DWORD longueurClefFormatTexte = 0;
    LPBYTE clefFormatTexte = 0;
    HANDLE fichier = 0;
    DWORD nombreOctetsEcrits = 0;

    // Premiere partie du Traitement
    Message("\n[Formatage de la clef]\n");// donner un formatage chaine

    // Obtenir la taille de la clef
    Message("CryptExportKey...\n");
    if (!CryptExportKey(this->clef, NULL, PLAINTEXTKEYBLOB, 0, NULL, &longueurClefFormatTexte))
        Erreur("CryptExportKey");

    // Creer une zone tampon de la taille récupérée
    Message("malloc...\n");
    if (!(clefFormatTexte = (BYTE *)malloc(longueurClefFormatTexte)))
        Erreur("malloc");

    // Récupérer la clef//ca m'envoyer la clé
    Message("CryptExportKey...\n");
    if (!CryptExportKey(this->clef, NULL, PLAINTEXTKEYBLOB, 0, clefFormatTexte, &longueurClefFormatTexte))
        Erreur("CryptExportKey");

    // Seconde partie du traitement
    Message("\n[Exportation de la clef]\n");

    // Créér le fichier qui va stocker la clef
    Message("CreateFile...\n");
    if ((fichier = CreateFileA(nomFichier,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL)) == INVALID_HANDLE_VALUE)
        Erreur("CreateFile");


    // Ecrire la clef dans le fichier
    Message("WriteFile...\n");
    if (!WriteFile(fichier, (LPCVOID)clefFormatTexte, longueurClefFormatTexte, &nombreOctetsEcrits, NULL))
        Erreur("WriteFile");

    // Derniere partie du traitement.
    Message("\n[Exportation de la clef terminee]\n");

    // Fermer le fichier
    if (fichier)
    {
        Message("CloseHandle...\n");
        CloseHandle(fichier);
    }

    // Libérer le tampon stockant la clef sous forme de texte
    if (clefFormatTexte)
    {
        Message("free...\n");
        free(clefFormatTexte);
    }
}


void AES_main::ImporterClef(char* nomFichier)//de chaine en binaire stockée en mémoire ( la clé)
{
    // Déclaration des variables locales
    DWORD longueurClefFormatTexte = 0;
    LPBYTE clefFormatTexte = 0;
    HANDLE fichier = 0;

    // Premiere partie du Traitement
    Message("\n[Formatage de la clef]\n");

    // Ouvrir le fichier contenant la clef
    Message("CreateFile...\n");
    if ((fichier = CreateFileA(nomFichier, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL)) == INVALID_HANDLE_VALUE)
        Erreur("CreateFile");

    // Obtenir la taille du fichier
    Message("GetFileSize...\n");
    if ((longueurClefFormatTexte = GetFileSize(fichier, NULL)) == INVALID_FILE_SIZE)
        Erreur("GetFileSize");

    // Creer une zone tampon pour stocker la clef
    Message("malloc...\n");
    if (!(clefFormatTexte = (BYTE *)malloc(longueurClefFormatTexte)))
        Erreur("malloc");

    // Lire la clef à partir du fichier
    Message("ReadFile...\n");
    if (!ReadFile(fichier, clefFormatTexte, longueurClefFormatTexte, &longueurClefFormatTexte, NULL))
        Erreur("ReadFile");

    // Seconde partie du Traitement
    Message("\n[Importation de la clef]\n");

    // Importer la clef dans le CSP
    Message("CryptImportKey...\n");
    if (!CryptImportKey(cryptographicServiceProvider, clefFormatTexte, longueurClefFormatTexte, 0, 0, &clef))
        Erreur("CryptImportKey");

    // Derniere partie du traitement.
    Message("\n[Importation de la clef terminee]\n");

    // Fermer le fichier
    if (fichier)
    {
        Message("CloseHandle...\n");
        CloseHandle(fichier);
    }

    // Libérer le tampon stockant la clef sous forme de texte
    if (clefFormatTexte)
    {
        Message("free...\n");
        free(clefFormatTexte);
    }

}

void AES_main::Chiffrer(char* nomFichierClair, char* nomFichierChiffre)
{
    // Déclaration des variables locales
    HANDLE fichierClair = 0;
    HANDLE fichierChiffre = 0;
    LPBYTE texteClair = 0;
    LPBYTE texteChiffre = 0;
    DWORD longueurTexteClair = 0;
    DWORD longueurBlocTexte = 0;
    DWORD longueurTexteChiffre = 0;
    DWORD nombreOctetsEcrits = 0;

    // Ouvrir le fichier clair
    Message("CreateFile...\n");
    if ((fichierClair = CreateFileA(nomFichierClair, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL)) == INVALID_HANDLE_VALUE)
        Erreur("CreateFile");

    //Obtenir la taille du fichier
    Message("GetFileSize...\n");
    if ((longueurTexteClair = GetFileSize(fichierClair, NULL)) == INVALID_FILE_SIZE)//
        Erreur("GetFileSize");

    // Creer une zone tampon pour stocker le texte clair//le tampon est comme un brouillon
    Message("malloc...\n");
    if (!(texteClair = (BYTE *)malloc(longueurTexteClair)))
        Erreur("malloc");

    // Lire le texte à partir du fichier
    Message("ReadFile...\n");
    if (!ReadFile(fichierClair, texteClair, longueurTexteClair, &longueurTexteClair, NULL))
        Erreur("ReadFile");

    // Obtenir la taille d'un bloc de texte chiffré//on rassemble plusieurs blocs de texte pour former un texte
    Message("CryptEncrypt...\n");
    if (!CryptEncrypt(this->clef, NULL, TRUE, 0, NULL, &longueurBlocTexte, 0))
        Erreur("CryptEncrypt");

    // Déterminer la taille du tampon de sortie selon la règle suivante:
    //		Si la clé est une clé de chiffrement par bloc, les données sont complétées par un multiple de la
// taille de bloc du chiffrement. Si la longueur des données est égale à la taille de bloc du
// chiffrement, un bloc de remplissage supplémentaire est ajouté aux données.
    double longueurTemp = (static_cast <double> (longueurTexteClair)) / (static_cast <double> (longueurBlocTexte));
    longueurTexteChiffre = longueurBlocTexte + (longueurBlocTexte * (static_cast <unsigned int> (floor(longueurTemp))));

    // Allouer l'espace mémoire pour le tampon de sortie
    Message("malloc...\n");
    if (!(texteChiffre = (BYTE *) malloc(longueurTexteChiffre)))//byte* casté en adresse byte
        Erreur("malloc");///textechiffre contient le texte qui va etre chiffré

    // Initialiser tampon de sortie
    DWORD longueurDonnees = longueurTexteClair;
    memset(texteChiffre, ' ', longueurTexteChiffre);// a l'adresse texte chiffre je charge '' jusqu'a ..
    memcpy(texteChiffre, texteClair, longueurDonnees);

    // Chiffrer le texte
    Message("CryptEncrypt...\n");
    if (!CryptEncrypt(this->clef,0,TRUE,0,texteChiffre,&longueurDonnees,longueurTexteChiffre))
        Erreur("CryptEncrypt");

    // Fermer le fichier d'origine
    if (fichierClair)
    {
        Message("CloseHandle...\n");
        CloseHandle(fichierClair);
    }

    // Creer un fichier où seront sauvegardées les données chiffrées
    Message("CreateFile...\n");
    if ((fichierChiffre = CreateFileA(nomFichierChiffre, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)) == INVALID_HANDLE_VALUE)
        Erreur("CreateFile");

    // Ecrire les données chiffrées dans le fichier
    Message("WriteFile...\n");
    if (!WriteFile(fichierChiffre, (LPCVOID)texteChiffre, longueurDonnees, &nombreOctetsEcrits, NULL))
        Erreur("WriteFile");

    // Fermer le fichier de destination
    if (fichierChiffre)
    {
        Message("CloseHandle...\n");
        CloseHandle(fichierChiffre);
    }



    // Libérer le tampon stockant le bloc de texte
    if (texteChiffre)
    {
        Message("free...\n");
        free(texteChiffre);
    }

    // Libérer le tampon stockant le texte
    if (texteClair)
    {
        Message("free...\n");
        free(texteClair);
    }
}

void AES_main::Dechiffrer(char* nomFichierChiffre, char* nomFichierClair)///on prens un texte chiffreé on les decompose en bloc , puis on fait les calculs pour les rendre en texte
{
    // Déclaration des variables locales
    HANDLE fichierClair = 0;
    HANDLE fichierChiffre = 0;
    LPBYTE texteClair = 0;
    LPBYTE texteChiffre = 0;
    DWORD longueurTexteClair = 0;
    DWORD longueurTexteChiffre = 0;
    DWORD nombreOctetsEcrits = 0;

    // Ouvrir le fichier chiffré
    Message("CreateFile...\n");
    if ((fichierChiffre = CreateFileA(nomFichierChiffre, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL)) == INVALID_HANDLE_VALUE)
        Erreur("CreateFile");

    //Obtenir la taille du fichier
    Message("GetFileSize...\n");
    if ((longueurTexteChiffre = GetFileSize(fichierChiffre, NULL)) == INVALID_FILE_SIZE)
        Erreur("GetFileSize");

    // Creer une zone tampon pour stocker le texte chiffré
    Message("malloc...\n");
    if (!(texteChiffre = (BYTE *)malloc(longueurTexteChiffre)))
        Erreur("malloc");

    // Lire le texte à partir du fichier
    Message("ReadFile...\n");
    if (!ReadFile(fichierChiffre, texteChiffre, longueurTexteChiffre, &longueurTexteChiffre, NULL))
        Erreur("ReadFile");

    // Déterminer la taille du tampon de sortie
    longueurTexteClair = longueurTexteChiffre;

    // Allouer l'espace mémoire pour le tampon de sortie
    Message("malloc...\n");
    if (!(texteClair = (BYTE *) malloc(longueurTexteClair)))
        Erreur("malloc");

    // Initialiser tampon de sortie
    DWORD longueurDonnees = longueurTexteClair;
    memset(texteClair, ' ', longueurTexteClair);
    memcpy(texteClair, texteChiffre, longueurDonnees);

    // Déchiffrer les données
    Message("CryptDecrypt...\n");
    if (!CryptDecrypt(this->clef, NULL, TRUE, 0, texteClair, &longueurDonnees))
        Erreur("CryptDecrypt");

    // Fermer le fichier d'origine
    if (fichierChiffre)
    {
        Message("CloseHandle...\n");
        CloseHandle(fichierChiffre);
    }

    // Creer un fichier où seront sauvegardées les données déchiffrées
    Message("CreateFile...\n");
    if ((fichierClair = CreateFileA(nomFichierClair, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)) == INVALID_HANDLE_VALUE)
        Erreur("CreateFile");

    // Ecrire les données déchiffrées dans le fichier
    Message("WriteFile...\n");
    if (!WriteFile(fichierClair, (LPCVOID)texteClair, longueurDonnees, &nombreOctetsEcrits, NULL))
        Erreur("WriteFile");



    // Fermer le fichier de destination
    if (fichierClair)
    {
        Message("CloseHandle...\n");
        CloseHandle(fichierClair);
    }

    // Libérer le tampon stockant le texte
    if (texteClair)
    {
        Message("free...\n");
        free(texteClair);
    }

    // Libérer le tampon stockant le bloc de texte
    if (texteChiffre)
    {
        Message("free...\n");
        free(texteChiffre);
    }
}


AES_main::AES_main()
{

}
