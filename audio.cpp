#include "Audio.h"

Audio::Audio()
{
    buffer_all_clear.loadFromFile("../../Resources/Audio/all_clear.ogg");
    sfx_all_clear.setBuffer(buffer_all_clear);

    buffer_clear_four_lines.loadFromFile("../../Resources/Audio/clear_four_lines.ogg");
    sfx_clear_four_lines.setBuffer(buffer_clear_four_lines);

    buffer_clear_four_lines_combo.loadFromFile("../../Resources/Audio/clear_four_lines_combo.ogg");
    sfx_clear_four_lines_combo.setBuffer(buffer_clear_four_lines_combo);

    buffer_clear_four_lines_combo_broken.loadFromFile("../../Resources/Audio/clear_four_lines_combo_broken.ogg");
    sfx_clear_four_lines_combo_broken.setBuffer(buffer_clear_four_lines_combo_broken);

    buffer_clear_line.loadFromFile("../../Resources/Audio/clear_line.ogg");
    sfx_clear_line.setBuffer(buffer_clear_line);

    buffer_clear_t_spin.loadFromFile("../../Resources/Audio/clear_t_spin.ogg");
    sfx_clear_t_spin.setBuffer(buffer_clear_t_spin);

    buffer_combo_1.loadFromFile("../../Resources/Audio/combo_1.ogg");
    sfx_combo_1.setBuffer(buffer_combo_1);

    buffer_combo_2.loadFromFile("../../Resources/Audio/combo_2.ogg");
    sfx_combo_2.setBuffer(buffer_combo_2);

    buffer_combo_3.loadFromFile("../../Resources/Audio/combo_3.ogg");
    sfx_combo_3.setBuffer(buffer_combo_3);

    buffer_combo_4.loadFromFile("../../Resources/Audio/combo_4.ogg");
    sfx_combo_4.setBuffer(buffer_combo_4);

    buffer_combo_5.loadFromFile("../../Resources/Audio/combo_5.ogg");
    sfx_combo_5.setBuffer(buffer_combo_5);

    buffer_combo_6.loadFromFile("../../Resources/Audio/combo_6.ogg");
    sfx_combo_6.setBuffer(buffer_combo_6);

    buffer_combo_7.loadFromFile("../../Resources/Audio/combo_7.ogg");
    sfx_combo_7.setBuffer(buffer_combo_7);

    buffer_combo_8.loadFromFile("../../Resources/Audio/combo_8.ogg");
    sfx_combo_8.setBuffer(buffer_combo_8);

    buffer_combo_9.loadFromFile("../../Resources/Audio/combo_9.ogg");
    sfx_combo_9.setBuffer(buffer_combo_9);

    buffer_combo_10.loadFromFile("../../Resources/Audio/combo_10.ogg");
    sfx_combo_10.setBuffer(buffer_combo_10);

    buffer_combo_11.loadFromFile("../../Resources/Audio/combo_11.ogg");
    sfx_combo_11.setBuffer(buffer_combo_11);

    buffer_combo_12.loadFromFile("../../Resources/Audio/combo_12.ogg");
    sfx_combo_12.setBuffer(buffer_combo_12);

    buffer_combo_13.loadFromFile("../../Resources/Audio/combo_13.ogg");
    sfx_combo_13.setBuffer(buffer_combo_13);

    buffer_combo_14.loadFromFile("../../Resources/Audio/combo_14.ogg");
    sfx_combo_14.setBuffer(buffer_combo_14);

    buffer_combo_15.loadFromFile("../../Resources/Audio/combo_15.ogg");
    sfx_combo_15.setBuffer(buffer_combo_15);

    buffer_combo_16.loadFromFile("../../Resources/Audio/combo_16.ogg");
    sfx_combo_16.setBuffer(buffer_combo_16);

    buffer_combo_1_power.loadFromFile("../../Resources/Audio/combo_1_power.ogg");
    sfx_combo_1_power.setBuffer(buffer_combo_1_power);

    buffer_combo_2_power.loadFromFile("../../Resources/Audio/combo_2_power.ogg");
    sfx_combo_2_power.setBuffer(buffer_combo_2_power);

    buffer_combo_3_power.loadFromFile("../../Resources/Audio/combo_3_power.ogg");
    sfx_combo_3_power.setBuffer(buffer_combo_3_power);

    buffer_combo_4_power.loadFromFile("../../Resources/Audio/combo_4_power.ogg");
    sfx_combo_4_power.setBuffer(buffer_combo_4_power);

    buffer_combo_5_power.loadFromFile("../../Resources/Audio/combo_5_power.ogg");
    sfx_combo_5_power.setBuffer(buffer_combo_5_power);

    buffer_combo_6_power.loadFromFile("../../Resources/Audio/combo_6_power.ogg");
    sfx_combo_6_power.setBuffer(buffer_combo_6_power);

    buffer_combo_7_power.loadFromFile("../../Resources/Audio/combo_7_power.ogg");
    sfx_combo_7_power.setBuffer(buffer_combo_7_power);

    buffer_combo_8_power.loadFromFile("../../Resources/Audio/combo_8_power.ogg");
    sfx_combo_8_power.setBuffer(buffer_combo_8_power);

    buffer_combo_9_power.loadFromFile("../../Resources/Audio/combo_9_power.ogg");
    sfx_combo_9_power.setBuffer(buffer_combo_9_power);

    buffer_combo_10_power.loadFromFile("../../Resources/Audio/combo_10_power.ogg");
    sfx_combo_10_power.setBuffer(buffer_combo_10_power);

    buffer_combo_11_power.loadFromFile("../../Resources/Audio/combo_11_power.ogg");
    sfx_combo_11_power.setBuffer(buffer_combo_11_power);

    buffer_combo_12_power.loadFromFile("../../Resources/Audio/combo_12_power.ogg");
    sfx_combo_12_power.setBuffer(buffer_combo_12_power);

    buffer_combo_13_power.loadFromFile("../../Resources/Audio/combo_13_power.ogg");
    sfx_combo_13_power.setBuffer(buffer_combo_13_power);

    buffer_combo_14_power.loadFromFile("../../Resources/Audio/combo_14_power.ogg");
    sfx_combo_14_power.setBuffer(buffer_combo_14_power);

    buffer_combo_15_power.loadFromFile("../../Resources/Audio/combo_15_power.ogg");
    sfx_combo_15_power.setBuffer(buffer_combo_15_power);

    buffer_combo_16_power.loadFromFile("../../Resources/Audio/combo_16_power.ogg");
    sfx_combo_16_power.setBuffer(buffer_combo_16_power);

    buffer_combobreak.loadFromFile("../../Resources/Audio/combo_break.ogg");
    sfx_combo_break.setBuffer(buffer_combobreak);

    buffer_final_t_spin.loadFromFile("../../Resources/Audio/final_t_spin.ogg");
    sfx_final_t_spin.setBuffer(buffer_final_t_spin);

    buffer_floor.loadFromFile("../../Resources/Audio/floor.ogg");
    sfx_floor.setBuffer(buffer_floor);

    buffer_hard_drop.loadFromFile("../../Resources/Audio/hard_drop.ogg");
    sfx_hard_drop.setBuffer(buffer_hard_drop);

    buffer_hit.loadFromFile("../../Resources/Audio/hit.ogg");
    sfx_hit.setBuffer(buffer_hit);

    buffer_hold.loadFromFile("../../Resources/Audio/hold.ogg");
    sfx_hold.setBuffer(buffer_hold);

    buffer_move.loadFromFile("../../Resources/Audio/move.ogg");
    sfx_move.setBuffer(buffer_move);

    buffer_rotate.loadFromFile("../../Resources/Audio/rotate.ogg");
    sfx_rotate.setBuffer(buffer_rotate);

    buffer_side_hit.loadFromFile("../../Resources/Audio/side_hit.ogg");
    sfx_side_hit.setBuffer(buffer_side_hit);

    buffer_tetris_theme_song.loadFromFile("../../Resources/Audio/tetris_theme_song.ogg");
    sfx_tetris_theme_song.setBuffer(buffer_tetris_theme_song);
}

Audio::~Audio() {}

sf::Sound& Audio::getSfxAllClear()
{
    return sfx_all_clear;
}

sf::Sound& Audio::getSfxClearFourLines()
{
    return sfx_clear_four_lines;
}

sf::Sound& Audio::getSfxClearFourLinesCombo()
{
    return sfx_clear_four_lines_combo;
}

sf::Sound& Audio::getSfxClearFourLinesComboBroken()
{
    return sfx_clear_four_lines_combo_broken;
}

sf::Sound& Audio::getSfxClearLine()
{
    return sfx_clear_line;
}

sf::Sound& Audio::getSfxClearTSpin()
{
    return sfx_clear_t_spin;
}

sf::Sound& Audio::getSfxCombo_1()
{
    return sfx_combo_1;
}

sf::Sound& Audio::getSfxCombo_2()
{
    return sfx_combo_2;
}

sf::Sound& Audio::getSfxCombo_3()
{
    return sfx_combo_3;
}

sf::Sound& Audio::getSfxCombo_4()
{
    return sfx_combo_4;
}

sf::Sound& Audio::getSfxCombo_5()
{
    return sfx_combo_5;
}

sf::Sound& Audio::getSfxCombo_6()
{
    return sfx_combo_6;
}

sf::Sound& Audio::getSfxCombo_7()
{
    return sfx_combo_7;
}

sf::Sound& Audio::getSfxCombo_8()
{
    return sfx_combo_8;
}

sf::Sound& Audio::getSfxCombo_9()
{
    return sfx_combo_9;
}

sf::Sound& Audio::getSfxCombo_10()
{
    return sfx_combo_10;
}

sf::Sound& Audio::getSfxCombo_11()
{
    return sfx_combo_11;
}

sf::Sound& Audio::getSfxCombo_12()
{
    return sfx_combo_12;
}

sf::Sound& Audio::getSfxCombo_13()
{
    return sfx_combo_13;
}

sf::Sound& Audio::getSfxCombo_14()
{
    return sfx_combo_14;
}

sf::Sound& Audio::getSfxCombo_15()
{
    return sfx_combo_15;
}

sf::Sound& Audio::getSfxCombo_16()
{
    return sfx_combo_16;
}

sf::Sound& Audio::getSfxCombo_1_power()
{
    return sfx_combo_1_power;
}

sf::Sound& Audio::getSfxCombo_2_power()
{
    return sfx_combo_2_power;
}

sf::Sound& Audio::getSfxCombo_3_power()
{
    return sfx_combo_3_power;
}

sf::Sound& Audio::getSfxCombo_4_power()
{
    return sfx_combo_4_power;
}

sf::Sound& Audio::getSfxCombo_5_power()
{
    return sfx_combo_5_power;
}

sf::Sound& Audio::getSfxCombo_6_power()
{
    return sfx_combo_6_power;
}

sf::Sound& Audio::getSfxCombo_7_power()
{
    return sfx_combo_7_power;
}

sf::Sound& Audio::getSfxCombo_8_power()
{
    return sfx_combo_8_power;
}

sf::Sound& Audio::getSfxCombo_9_power()
{
    return sfx_combo_9_power;
}

sf::Sound& Audio::getSfxCombo_10_power()
{
    return sfx_combo_10_power;
}

sf::Sound& Audio::getSfxCombo_11_power()
{
    return sfx_combo_11_power;
}

sf::Sound& Audio::getSfxCombo_12_power()
{
    return sfx_combo_12_power;
}

sf::Sound& Audio::getSfxCombo_13_power()
{
    return sfx_combo_13_power;
}

sf::Sound& Audio::getSfxCombo_14_power()
{
    return sfx_combo_14_power;
}

sf::Sound& Audio::getSfxCombo_15_power()
{
    return sfx_combo_15_power;
}

sf::Sound& Audio::getSfxCombo_16_power()
{
    return sfx_combo_16_power;
}

sf::Sound& Audio::getSfxComboBreak()
{
    return sfx_combo_break;
}

sf::Sound& Audio::getSfxFinalTSpin()
{
    return sfx_final_t_spin;
}

sf::Sound& Audio::getSfxFloor()
{
    return sfx_floor;
}

sf::Sound& Audio::getSfxHardDrop()
{
    return sfx_hard_drop;
}

sf::Sound& Audio::getSfxHit()
{
    return sfx_hit;
}

sf::Sound& Audio::getSfxHold()
{
    return sfx_hold;
}

sf::Sound& Audio::getSfxMove()
{
    return sfx_move;
}

sf::Sound& Audio::getSfxRotate()
{
    return sfx_rotate;
}

sf::Sound& Audio::getSfxSideHit()
{
    return sfx_side_hit;
}

sf::Sound& Audio::getSfxTetrisThemeSong()
{
    return sfx_tetris_theme_song;
}