#include "TextToSpeech.h"

TextToSpeech::TextToSpeech() {
	if (FAILED(::CoInitialize(NULL)))
		std::cout << "Failed to Initialize voice" << std::endl;
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&this->pVoice);
	if (SUCCEEDED(hr))
	{
		std::cout << "Voice initialize successfull!";
	}
	::CoUninitialize();
}

void TextToSpeech::speak(wchar_t const * text) {
	this->pVoice->Speak(text, 0, NULL);
	this->pVoice->Release();
}