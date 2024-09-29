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

    bufferPowerCombo_1.loadFromFile("Resources/Audio/combo_1_power.ogg");
    sfxPowerCombo_1.setBuffer(bufferPowerCombo_1);

    bufferPowerCombo_2.loadFromFile("Resources/Audio/combo_2_power.ogg");
    sfxPowerCombo_2.setBuffer(bufferPowerCombo_2);

    bufferPowerCombo_3.loadFromFile("Resources/Audio/combo_3_power.ogg");
    sfxPowerCombo_3.setBuffer(bufferPowerCombo_3);

    bufferPowerCombo_4.loadFromFile("Resources/Audio/combo_4_power.ogg");
    sfxPowerCombo_4.setBuffer(bufferPowerCombo_4);

    bufferPowerCombo_5.loadFromFile("Resources/Audio/combo_5_power.ogg");
    sfxPowerCombo_5.setBuffer(bufferPowerCombo_5);

    bufferPowerCombo_6.loadFromFile("Resources/Audio/combo_6_power.ogg");
    sfxPowerCombo_6.setBuffer(bufferPowerCombo_6);

    bufferPowerCombo_7.loadFromFile("Resources/Audio/combo_7_power.ogg");
    sfxPowerCombo_7.setBuffer(bufferPowerCombo_7);

    bufferPowerCombo_8.loadFromFile("Resources/Audio/combo_8_power.ogg");
    sfxPowerCombo_8.setBuffer(bufferPowerCombo_8);

    bufferPowerCombo_9.loadFromFile("Resources/Audio/combo_9_power.ogg");
    sfxPowerCombo_9.setBuffer(bufferPowerCombo_9);

    bufferPowerCombo_10.loadFromFile("Resources/Audio/combo_10_power.ogg");
    sfxPowerCombo_10.setBuffer(bufferPowerCombo_10);

    bufferPowerCombo_11.loadFromFile("Resources/Audio/combo_11_power.ogg");
    sfxPowerCombo_11.setBuffer(bufferPowerCombo_11);

    bufferPowerCombo_12.loadFromFile("Resources/Audio/combo_12_power.ogg");
    sfxPowerCombo_12.setBuffer(bufferPowerCombo_12);

    bufferPowerCombo_13.loadFromFile("Resources/Audio/combo_13_power.ogg");
    sfxPowerCombo_13.setBuffer(bufferPowerCombo_13);

    bufferPowerCombo_14.loadFromFile("Resources/Audio/combo_14_power.ogg");
    sfxPowerCombo_14.setBuffer(bufferPowerCombo_14);

    bufferPowerCombo_15.loadFromFile("Resources/Audio/combo_15_power.ogg");
    sfxPowerCombo_15.setBuffer(bufferPowerCombo_15);

    bufferPowerCombo_16.loadFromFile("Resources/Audio/combo_16_power.ogg");
    sfxPowerCombo_16.setBuffer(bufferPowerCombo_16);

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

sf::Sound& AudioCombo::getSfxPowerCombo_1()
{
    return sfxPowerCombo_1;
}

sf::Sound& AudioCombo::getSfxPowerCombo_2()
{
    return sfxPowerCombo_2;
}

sf::Sound& AudioCombo::getSfxPowerCombo_3()
{
    return sfxPowerCombo_3;
}

sf::Sound& AudioCombo::getSfxPowerCombo_4()
{
    return sfxPowerCombo_4;
}

sf::Sound& AudioCombo::getSfxPowerCombo_5()
{
    return sfxPowerCombo_5;
}

sf::Sound& AudioCombo::getSfxPowerCombo_6()
{
    return sfxPowerCombo_6;
}

sf::Sound& AudioCombo::getSfxPowerCombo_7()
{
    return sfxPowerCombo_7;
}

sf::Sound& AudioCombo::getSfxPowerCombo_8()
{
    return sfxPowerCombo_8;
}

sf::Sound& AudioCombo::getSfxPowerCombo_9()
{
    return sfxPowerCombo_9;
}

sf::Sound& AudioCombo::getSfxPowerCombo_10()
{
    return sfxPowerCombo_10;
}

sf::Sound& AudioCombo::getSfxPowerCombo_11()
{
    return sfxPowerCombo_11;
}

sf::Sound& AudioCombo::getSfxPowerCombo_12()
{
    return sfxPowerCombo_12;
}

sf::Sound& AudioCombo::getSfxPowerCombo_13()
{
    return sfxPowerCombo_13;
}

sf::Sound& AudioCombo::getSfxPowerCombo_14()
{
    return sfxPowerCombo_14;
}

sf::Sound& AudioCombo::getSfxPowerCombo_15()
{
    return sfxPowerCombo_15;
}

sf::Sound& AudioCombo::getSfxPowerCombo_16()
{
    return sfxPowerCombo_16;
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

    bufferHit.loadFromFile("Resources/Audio/hit.ogg");
    sfxHit.setBuffer(bufferHit);

    bufferHold.loadFromFile("Resources/Audio/hold.ogg");
    sfxHold.setBuffer(bufferHold);

    bufferMove.loadFromFile("Resources/Audio/move.ogg");
    sfxMove.setBuffer(bufferMove);

    bufferRotate.loadFromFile("Resources/Audio/rotate.ogg");
    sfxRotate.setBuffer(bufferRotate);

    bufferSideHit.loadFromFile("Resources/Audio/side_hit.ogg");
    sfxSideHit.setBuffer(bufferSideHit);
}

sf::Sound& AudioMovement::getSfxFloor()
{
    return sfxFloor;
}

sf::Sound& AudioMovement::getSfxHardDrop()
{
    return sfxHardDrop;
}

sf::Sound& AudioMovement::getSfxHit()
{
    return sfxHit;
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

sf::Sound& AudioMovement::getSfxSideHit()
{
    return sfxSideHit;
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
}

sf::Sound& AudioThemeSong::getSfxTetrisThemeSong()
{
    return sfxTetrisThemeSong;
}