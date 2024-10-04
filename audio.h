#pragma once
#include <SFML/Audio.hpp>

class AudioCombo
{
private:
	sf::SoundBuffer bufferCombo_1;
	sf::SoundBuffer bufferCombo_2;
	sf::SoundBuffer bufferCombo_3;
	sf::SoundBuffer bufferCombo_4;
	sf::SoundBuffer bufferCombo_5;
	sf::SoundBuffer bufferCombo_6;
	sf::SoundBuffer bufferCombo_7;
	sf::SoundBuffer bufferCombo_8;
	sf::SoundBuffer bufferCombo_9;
	sf::SoundBuffer bufferCombo_10;
	sf::SoundBuffer bufferCombo_11;
	sf::SoundBuffer bufferCombo_12;
	sf::SoundBuffer bufferCombo_13;
	sf::SoundBuffer bufferCombo_14;
	sf::SoundBuffer bufferCombo_15;
	sf::SoundBuffer bufferCombo_16;
	sf::SoundBuffer bufferComboBreak;

	sf::Sound sfxCombo_1;
	sf::Sound sfxCombo_2;
	sf::Sound sfxCombo_3;
	sf::Sound sfxCombo_4;
	sf::Sound sfxCombo_5;
	sf::Sound sfxCombo_6;
	sf::Sound sfxCombo_7;
	sf::Sound sfxCombo_8;
	sf::Sound sfxCombo_9;
	sf::Sound sfxCombo_10;
	sf::Sound sfxCombo_11;
	sf::Sound sfxCombo_12;
	sf::Sound sfxCombo_13;
	sf::Sound sfxCombo_14;
	sf::Sound sfxCombo_15;
	sf::Sound sfxCombo_16;
	sf::Sound sfxComboBreak;

public:
	AudioCombo();

	sf::Sound& getSfxCombo_1();
	sf::Sound& getSfxCombo_2();
	sf::Sound& getSfxCombo_3();
	sf::Sound& getSfxCombo_4();
	sf::Sound& getSfxCombo_5();
	sf::Sound& getSfxCombo_6();
	sf::Sound& getSfxCombo_7();
	sf::Sound& getSfxCombo_8();
	sf::Sound& getSfxCombo_9();
	sf::Sound& getSfxCombo_10();
	sf::Sound& getSfxCombo_11();
	sf::Sound& getSfxCombo_12();
	sf::Sound& getSfxCombo_13();
	sf::Sound& getSfxCombo_14();
	sf::Sound& getSfxCombo_15();
	sf::Sound& getSfxCombo_16();
	sf::Sound& getSfxComboBreak();
};

class AudioMovement
{
private:
	sf::SoundBuffer bufferFloor;
	sf::SoundBuffer bufferHardDrop;
	sf::SoundBuffer bufferHold;
	sf::SoundBuffer bufferMove;
	sf::SoundBuffer bufferRotate;

	sf::Sound sfxFloor;
	sf::Sound sfxHardDrop;
	sf::Sound sfxHold;
	sf::Sound sfxMove;
	sf::Sound sfxRotate;

public:
	AudioMovement();

	sf::Sound& getSfxFloor();
	sf::Sound& getSfxHardDrop();
	sf::Sound& getSfxHold();
	sf::Sound& getSfxMove();
	sf::Sound& getSfxRotate();
};

class AudioBoard
{
private:
	sf::SoundBuffer bufferClearLine;
	sf::SoundBuffer bufferClearFourLines;
	sf::SoundBuffer bufferAllClear;

	sf::Sound sfxClearLine;
	sf::Sound sfxClearFourLines;
	sf::Sound sfxAllClear;

public:
	AudioBoard();

	sf::Sound& getSfxClearLine();
	sf::Sound& getSfxClearFourLines();
	sf::Sound& getSfxAllClear();
};

class AudioThemeSong
{
private:
	sf::SoundBuffer bufferTetrisThemeSong;
	sf::Sound sfxTetrisThemeSong;

public:
	AudioThemeSong();

	sf::Sound& getSfxTetrisThemeSong();
};