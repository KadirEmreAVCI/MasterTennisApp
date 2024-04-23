#pragma once
#include "IGUIConfigurator.h"
class GUIConfigurator : public IGUIConfigurator{
public:
	void ConfigureGUI() override final;
private:
	// void SetBindFunctions() override final;
};

