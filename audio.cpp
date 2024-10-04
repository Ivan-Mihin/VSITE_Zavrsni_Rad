#include "Audio.h"

AudioCombo::AudioCombo()
{
    bufferCombo_1.loadFromFile("Resources/Audio/combo_1.ogg");
    sfxCombo_1.setBuffer(bufferCombo_1);

    bufferCombo_2.loadFromFile("Resources/Audio/combo_2.ogg");
    sfxCombo_2.setBuffer(bufferCombo_2);

    bufferCombo_3.loadFromFile("Resources/Audio/combo_3.ogg");
    sfxCombo_3.setBuffer(bufferCombo_3);

    bufferCombo_4.loadFromFile("Resources/Audio/combo_4.ogg");
    sfxCombo_4.setBuffer(bufferCombo_4);

    bufferCombo_5.loadFromFile("Resources/Audio/combo_5.ogg");
    sfxCombo_5.setBuffer(bufferCombo_5);

    bufferCombo_6.loadFromFile("Resources/Audio/combo_6.ogg");
    sfxCombo_6.setBuffer(bufferCombo_6);

    bufferCombo_7.loadFromFile("Resources/Audio/combo_7.ogg");
    sfxCombo_7.setBuffer(bufferCombo_7);

    bufferCombo_8.loadFromFile("Resources/Audio/combo_8.ogg");
    sfxCombo_8.setBuffer(bufferCombo_8);

    bufferCombo_9.loadFromFile("Resources/Audio/combo_9.ogg");
    sfxCombo_9.setBuffer(bufferCombo_9);

    bufferCombo_10.loadFromFile("Resources/Audio/combo_10.ogg");
    sfxCombo_10.setBuffer(bufferCombo_10);

    bufferCombo_11.loadFromFile("Resources/Audio/combo_11.ogg");
    sfxCombo_11.setBuffer(bufferCombo_11);

    bufferCombo_12.loadFromFile("Resources/Audio/combo_12.ogg");
    sfxCombo_12.setBuffer(bufferCombo_12);

    bufferCombo_13.loadFromFile("Resources/Audio/combo_13.ogg");
    sfxCombo_13.setBuffer(bufferCombo_13);

    bufferCombo_14.loadFromFile("Resources/Audio/combo_14.ogg");
    sfxCombo_14.setBuffer(bufferCombo_14);

    bufferCombo_15.loadFromFile("Resources/Audio/combo_15.ogg");
    sfxCombo_15.setBuffer(bufferCombo_15);

    bufferCombo_16.loadFromFile("Resources/Audio/combo_16.ogg");
    sfxCombo_16.setBuffer(bufferCombo_16);

    bufferComboBreak.loadFromFile("Resources/Audio/combo_break.ogg");
    sfxComboBreak.setBuffer(bufferComboBreak);
}

sf::Sound& AudioCombo::getSfxCombo_1()
{
    return sfxCombo_1;
}

sf::Sound& AudioCombo::getSfxCombo_2()
{
    return sfxCombo_2;
}

sf::Sound& AudioCombo::getSfxCombo_3()
{
    return sfxCombo_3;
}

sf::Sound& AudioCombo::getSfxCombo_4()
{
    return sfxCombo_4;
}

sf::Sound& AudioCombo::getSfxCombo_5()
{
    return sfxCombo_5;
}

sf::Sound& AudioCombo::getSfxCombo_6()
{
    return sfxCombo_6;
}

sf::Sound& AudioCombo::getSfxCombo_7()
{
    return sfxCombo_7;
}

sf::Sound& AudioCombo::getSfxCombo_8()
{
    return sfxCombo_8;
}

sf::Sound& AudioCombo::getSfxCombo_9()
{
    return sfxCombo_9;
}

sf::Sound& AudioCombo::getSfxCombo_10()
{
    return sfxCombo_10;
}

sf::Sound& AudioCombo::getSfxCombo_11()
{
    return sfxCombo_11;
}

sf::Sound& AudioCombo::getSfxCombo_12()
{
    return sfxCombo_12;
}

sf::Sound& AudioCombo::getSfxCombo_13()
{
    return sfxCombo_13;
}

sf::Sound& AudioCombo::getSfxCombo_14()
{
    return sfxCombo_14;
}

sf::Sound& AudioCombo::getSfxCombo_15()
{
    return sfxCombo_15;
}

sf::Sound& AudioCombo::getSfxCombo_16()
{
    return sfxCombo_16;
}

sf::Sound& AudioCombo::getSfxComboBreak()
{
    return sfxComboBreak;
}

AudioMovement::AudioMovement()
{
    bufferFloor.loadFromFile("Resources/Audio/floor.ogg");
    sfxFloor.setBuffer(bufferFloor);

    bufferHardDrop.loadFromFile("Resources/Audio/hard_drop.ogg");
    sfxHardDrop.setBuffer(bufferHardDrop);

    bufferHold.loadFromFile("Resources/Audio/hold.ogg");
    sfxHold.setBuffer(bufferHold);

    bufferMove.loadFromFile("Resources/Audio/move.ogg");
    sfxMove.setBuffer(bufferMove);

    bufferRotate.loadFromFile("Resources/Audio/rotate.ogg");
    sfxRotate.setBuffer(bufferRotate);
}

sf::Sound& AudioMovement::getSfxFloor()
{
    return sfxFloor;
}

sf::Sound& AudioMovement::getSfxHardDrop()
{
    return sfxHardDrop;
}

sf::Sound& AudioMovement::getSfxHold()
{
    return sfxHold;
}

sf::Sound& AudioMovement::getSfxMove()
{
    return sfxMove;
}

sf::Sound& AudioMovement::getSfxRotate()
{
    return sfxRotate;
}

AudioBoard::AudioBoard()
{
    bufferClearLine.loadFromFile("Resources/Audio/clear_line.ogg");
    sfxClearLine.setBuffer(bufferClearLine);

    bufferClearFourLines.loadFromFile("Resources/Audio/clear_four_lines.ogg");
    sfxClearFourLines.setBuffer(bufferClearFourLines);

    bufferAllClear.loadFromFile("Resources/Audio/all_clear.ogg");
    sfxAllClear.setBuffer(bufferAllClear);
}

sf::Sound& AudioBoard::getSfxAllClear()
{
    return sfxAllClear;
}

sf::Sound& AudioBoard::getSfxClearLine()
{
    return sfxClearLine;
}

sf::Sound& AudioBoard::getSfxClearFourLines()
{
    return sfxClearFourLines;
}

AudioThemeSong::AudioThemeSong()
{
    bufferTetrisThemeSong.loadFromFile("Resources/Audio/tetris_theme_song.ogg");
    sfxTetrisThemeSong.setBuffer(bufferTetrisThemeSong);
    sfxTetrisThemeSong.setLoop(true);
    sfxTetrisThemeSong.setVolume(15);
}

sf::Sound& AudioThemeSong::getSfxTetrisThemeSong()
{
    return sfxTetrisThemeSong;
}