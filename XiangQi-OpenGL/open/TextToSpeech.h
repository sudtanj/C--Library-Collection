#pragma once
#include <sapi.h>
#include <iostream>

class TextToSpeech{
private:
	ISpVoice * pVoice = NULL;
public:
	TextToSpeech();
	void speak(wchar_t const * text);
}