#ifndef AES_MAIN_H
#define AES_MAIN_H
#include <Windows.h>
#include <Wincrypt.h>
#include <stdio.h>
#include <string.h>
#include <fileapi.h>
#include <math.h>

class AES_main
{
public:
    AES_main();
    HCRYPTPROV	cryptographicServiceProvider = 0;
    HCRYPTKEY	clef = 0;

public:
    void Message(char* message);
    void Erreur(char* fonction);
    void Initialiser();
    void Nettoyer();
    void GenererClef();
    void ExporterClef(char* nomFichier);
    void ImporterClef(char* nomFichier);
    void Chiffrer(char* nomFichierClair, char* nomFichierChiffre);
    void Dechiffrer(char* nomFichierChiffre, char* nomFichierClair);

};

#endif // AES_MAIN_H
