#define MINIAUDIO_IMPLEMENTATION
#include "audioManager.h"
#include <iostream>

static ma_engine engine;
static ma_sound crunch;
static ma_sound game;
static ma_sound grass;
static ma_sound menu;
static bool crunchLoaded = false;
static bool gameLoaded = false;
static bool grassLoaded = false;
static bool menuLoaded = false;

bool initAudioEngine()
{
    if (ma_engine_init(NULL, &engine) != MA_SUCCESS) 
    {
        std::cerr << "Kunde inte initiera ljudmotorn.\n";
        return false;
    }
    return true;
}

void uninitAudioEngine()
{
    // Clean up auidos if they are loaded
    if(crunchLoaded) 
    {
        ma_sound_stop(&crunch);
        ma_sound_uninit(&crunch);
        crunchLoaded = false;
    }
    if(gameLoaded) 
    {
        ma_sound_stop(&game);
        ma_sound_uninit(&game);
        gameLoaded = false;
    }
    if(grassLoaded) 
    {
        ma_sound_stop(&grass);
        ma_sound_uninit(&grass);
        grassLoaded = false;
    }
    if(menuLoaded) 
    {
        ma_sound_stop(&menu);
        ma_sound_uninit(&menu);
        menuLoaded = false;
    }

    ma_engine_uninit(&engine);
}

void playCrunch() // Not LOOP
{
    if(crunchLoaded) 
    {
        ma_sound_stop(&crunch);
        ma_sound_uninit(&crunch);
    }
    if(ma_sound_init_from_file(&engine, "audio/crunch.wav", 0, NULL, NULL, &crunch) == MA_SUCCESS) 
    {
        crunchLoaded = true;
        ma_sound_start(&crunch);
    } 
    else 
    {
        std::cerr << "Kunde inte ladda crunch.wav\n";
    }
}

void stopCrunch() 
{
    if (crunchLoaded) {
        ma_sound_stop(&crunch);
        ma_sound_uninit(&crunch);
        crunchLoaded = false;
    }
}

void playGrass() // Not LOOP
{
    if(grassLoaded) 
    {
        ma_sound_stop(&grass);
        ma_sound_uninit(&grass);
    }
    if(ma_sound_init_from_file(&engine, "audio/grass.mp3", 0, NULL, NULL, &grass) == MA_SUCCESS) 
    {
        grassLoaded = true;
        ma_sound_start(&grass);
    } 
    else 
    {
        std::cerr << "Kunde inte ladda grass.mp3\n";
    }
}

void stopGrass() 
{
    if (grassLoaded) {
        ma_sound_stop(&grass);
        ma_sound_uninit(&grass);
        grassLoaded = false;
    }
}

void playGame() // LOOP
{
    if (gameLoaded) {
        ma_sound_stop(&game);
        ma_sound_uninit(&game);
    }
    if (ma_sound_init_from_file(&engine, "audio/game.mp3", 0, NULL, NULL, &game) == MA_SUCCESS) {
        gameLoaded = true;
        ma_sound_set_looping(&game, MA_TRUE);
        ma_sound_start(&game);
    } else {
        std::cerr << "Kunde inte ladda game.mp3\n";
    }
}

void stopGame()
{
    if (gameLoaded) {
        ma_sound_stop(&game);
        ma_sound_uninit(&game);
        gameLoaded = false;
    }
}

void playMenu() // LOOP
{
    if (menuLoaded) {
        ma_sound_stop(&menu);
        ma_sound_uninit(&menu);
    }
    if (ma_sound_init_from_file(&engine, "audio/menu.mp3", 0, NULL, NULL, &menu) == MA_SUCCESS) {
        menuLoaded = true;
        ma_sound_set_looping(&menu, MA_TRUE);
        ma_sound_start(&menu);
    } else {
        std::cerr << "Kunde inte ladda menu.mp3\n";
    }
}

void stopMenu()
{
    if (menuLoaded) {
        ma_sound_stop(&menu);
        ma_sound_uninit(&menu);
        menuLoaded = false;
    }
}
