#pragma once
class IGUIConfigurator{
public:
	virtual void ConfigureGUI() = 0;
private:
	// TODO: in case of using std:function-std::bind logic. 
	// virtual void SetBindFunctions();
};