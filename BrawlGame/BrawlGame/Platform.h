/**********************************************************************************
// Platform (Arquivo de Cabeçalho)
// 
// Criação:     21 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_PLATFORM_H_
#define _GRAVITYGUY_PLATFORM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos específicos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites

// ---------------------------------------------------------------------------------

enum PLATTYPES { SMALL, MEDIUM, LARGE, FINISH };

// ---------------------------------------------------------------------------------

class Platform : public Object
{
public:
    Platform(float x1, float x2, float y1, float y2);                   // construtor    
    ~Platform();                            // destrutor

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
    void OnCollision(Object* obj);
}; 

// ---------------------------------------------------------------------------------
#endif