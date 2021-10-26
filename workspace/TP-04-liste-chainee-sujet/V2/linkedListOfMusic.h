#pragma once

#include <stdbool.h>
#include "linkedList.h"

// ============
// Types
// ============

typedef struct {
    char* name;
    char* artist;
    char* album;
    char* genre;
    int disk_num;
    int track_num;
    int year;
} Music;

// ============
// External Functions
// ============

void afficheElement(Element e);
void detruireElement(Element e);
bool equalsElement(Element e1, Element e2);

//Transmettre les données d'une ligne du fichier .txt, correspondant à une musique, dans un element Music
Music* readMusicLine();