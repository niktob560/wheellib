#include "platform.h"
#include "platformRegs.h"
#include "wheelRegs.h"

#include <avr/io.h>						//include for base avr funcs
#define F_CPU 16000000       		   	//define with freq
#include <util/delay.h>					//include for delay func
#include <avr/interrupt.h>   		   	//include interrupt funcs
#include <stdlib.h>
#include "errorCodes.h"
#include "avr-api/USART.h"

Platform::Platform(uint8_t templ)
{
	setTemplate(templ);
}

void Platform::setNumOfWheels(uint8_t num)
{
	this->numOfWheels = num;
	if(wheels != 0)
		free(wheels);
	wheels = (Wheel**)malloc(sizeof(Wheel*) * num);
	if(num > 0)
	{
		if(wheels == 0)
		{
			wheels = (Wheel**)malloc(sizeof(Wheel*) * num);
		}
		else
		{
			wheels = (Wheel**)realloc(wheels, sizeof(Wheel*) * num);
		}
		if(wheels == 0)
			error = ERROR_BAD_ALLOC;
		else
			error = ERROR_OK;
	}
	else
	{
		if(wheels != 0)
		{
			for(uint8_t i = 0; i < numOfWheels; i++)
			{
				free(wheels[i]);
			}
			free(wheels);
		}
		error = ERROR_OK;
	}
}

void Platform::setTemplate(uint8_t templ)
{
	error = ERROR_OK;
	this->templ = templ;
	switch(templ)
	{
		case TEMPLATE_2WH_ALONG:
		case TEMPLATE_2WH_PERP:
		{
			setNumOfWheels(2);
			break;
		}
		case TEMPLATE_3WH_120DEG:
		case TEMPLATE_3WH_2ALONG_1PERP:
		{
			setNumOfWheels(3);
			break;
		}
		case TEMPLATE_4WH_2ALONG_2PERP:
		case TEMPLATE_4WH_ALONG_OMNI:
		{
			setNumOfWheels(4);
			break;
		}
		case TEMPLATE_CUSTOM:
		default:
		{
			this->error = ERROR_BAD_WHEEL;
			break;
		}
	}	
}

void Platform::setStatus(uint8_t status)
{
	this->status = status;
	error = ERROR_OK;
	switch(status)
	{
		default:
		{
			error = ERROR_BAD_STATUS;
			break;
		}
	}
}

uint8_t Platform::addWheel(Wheel* wh)
{
	if(wheels != 0 && wheelAdded < numOfWheels)
	{
		wheels[wheelAdded++] = wh;
		return wheelAdded - 1;
	}
	else
	{
		error = ERROR_BAD_INIT;
		return 0xFF;
	}
}

void Platform::stop()
{
	if(wheels != 0)
	{
		for(uint8_t i = 0; i < numOfWheels; i++)
		{
			if(wheels[i] != 0)
			{
				wheels[i]->stop();
				error = ERROR_OK;
			}
			else
			{
				error = ERROR_BAD_WHEEL;
			}
		}
	}
	else
	{
		error = ERROR_BAD_INIT ;
	}
}

void Platform::runForward()
{
	if(wheels != 0)
	{
							//USART0Println("A");
		if(templ != TEMPLATE_CUSTOM && templ != TEMPLATE_3WH_120DEG)
		{
							//USART0Println("A");
			for(uint8_t i = 0; i < numOfWheels; i++)
			{
							//USART0Println("A");
				switch(templ)
				{
					case TEMPLATE_4WH_2ALONG_2PERP:
					{
						//USART0Println("A");
						if(wheels[i] != 0)
						{
							//USART0Println("A");
							if(wheels[i]->getPlacement() == PLACEMENT_SIDE_ALONG_RIGHT)
							{
								wheels[i]->runCW();
							}
							else if(wheels[i]->getPlacement() == PLACEMENT_SIDE_ALONG_LEFT)
							{
								wheels[i]->runACW();
							}
							else
							{
								wheels[i]->stop();
							}
						}
						else
						{
							error = ERROR_BAD_WHEEL;
							this->stop();
							return;
						}
						break;
					}
				}
			}
		}
		else if(templ != TEMPLATE_3WH_120DEG)
		{

		}
	}
	else
	{
		error = ERROR_BAD_INIT;
	}
}

void Platform::runBackward()
{
	if(wheels != 0)
	{
		if(templ != TEMPLATE_CUSTOM && templ != TEMPLATE_3WH_120DEG)
		{
			for(uint8_t i = 0; i < numOfWheels; i++)
			{
				switch(templ)
				{
					case TEMPLATE_4WH_2ALONG_2PERP:
					{
						if(wheels[i] != 0)
						{
							if(wheels[i]->getPlacement() == PLACEMENT_SIDE_ALONG_RIGHT)
							{
								wheels[i]->runACW();
							}
							else if(wheels[i]->getPlacement() == PLACEMENT_SIDE_ALONG_LEFT)
							{
								wheels[i]->runCW();
							}
							else
							{
								wheels[i]->stop();
							}
						}
						else
						{
							error = ERROR_BAD_WHEEL;
							this->stop();
							return;
						}
						break;
					}
				}
			}
		}
		else if(templ != TEMPLATE_3WH_120DEG)
		{

		}
	}
	else
	{
		error = ERROR_BAD_INIT;
	}
}

void Platform::runRight()
{
	if(templ == TEMPLATE_4WH_2ALONG_2PERP
		|| templ == TEMPLATE_4WH_ALONG_OMNI
		|| templ == TEMPLATE_3WH_120DEG
		|| templ == TEMPLATE_3WH_2ALONG_1PERP
		|| templ == TEMPLATE_2WH_PERP)
	{
		if(wheels != 0)
		{
			switch(templ)
			{
				case TEMPLATE_4WH_2ALONG_2PERP:
				{
					for(uint8_t i = 0; i < numOfWheels; i++)
					{
						//USART0Print("WHEEL ");
						//USART0Println(i);
						if(wheels[i] != 0)
						{
							//USART0Print("PLACEMENT: ");
							//USART0Println(wheels[i]->getPlacement());
							if(wheels[i]->getPlacement() == PLACEMENT_SIDE_PERP_FRONT)
							{
								wheels[i]->runACW();
							}
							else if(wheels[i]->getPlacement() == PLACEMENT_SIDE_PERP_BACK)
							{
								wheels[i]->runCW();
							}
							else
							{
								wheels[i]->stop();
							}
						}
						else
						{
							error = ERROR_BAD_WHEEL;
							this->stop();
							return;
						}
					}
					break;
				}
				default:
				{
					error = ERROR_BAD_CALL;
					break;
				}
			}
		}
		else
		{
			error = ERROR_BAD_INIT;
		}
	}
	else
	{
		error = ERROR_BAD_CALL;
	}
}

void Platform::runLeft()
{
	if(templ == TEMPLATE_4WH_2ALONG_2PERP
		|| templ == TEMPLATE_4WH_ALONG_OMNI
		|| templ == TEMPLATE_3WH_120DEG
		|| templ == TEMPLATE_3WH_2ALONG_1PERP
		|| templ == TEMPLATE_2WH_PERP)
	{
		if(wheels != 0)
		{
			switch(templ)
			{
				case TEMPLATE_4WH_2ALONG_2PERP:
				{
					for(uint8_t i = 0; i < numOfWheels; i++)
					{
						if(wheels[i] != 0)
						{
							if(wheels[i]->getPlacement() == PLACEMENT_SIDE_PERP_FRONT)
							{
								wheels[i]->runCW();
							}
							else if(wheels[i]->getPlacement() == PLACEMENT_SIDE_PERP_BACK)
							{
								wheels[i]->runACW();
							}
							else
							{
								wheels[i]->stop();
							}
						}
						else
						{
							error = ERROR_BAD_WHEEL;
							this->stop();
							return;
						}
					}
					break;
				}
				default:
				{
					error = ERROR_BAD_CALL;
					break;
				}
			}
		}
		else
		{
			error = ERROR_BAD_INIT;
		}
	}
	else
	{
		error = ERROR_BAD_CALL;
	}
}

/*
void Platform::turnLeft()
{
	if(wheels != 0)
	{
		for(uint8_t i = 0; i < numOfWheels; i++)
		{
			if(wheels[i] != 0)
			{

			}
			else
			{
				error = ERROR_BAD_WHEEL;
				this->stop();
				return;
			}
		}
	}
	else
	{
		error = ERROR_BAD_INIT;
	}
}
*/

Wheel* Platform::getWheel(uint8_t _i)
{
	return wheels[_i];
}

uint16_t Platform::getError()
{
	return error;
}


void Platform::turnCW()
{
	if(wheels != 0)
	{
		for(uint8_t i = 0; i < numOfWheels; i++)
		{
			if(wheels[i] != 0)
			{
				wheels[i]->runACW();
			}
			else
			{
				error = ERROR_BAD_WHEEL;
				this->stop();
				return;
			}
		}
	}
	else
	{
		error = ERROR_BAD_INIT;
	}
}
void Platform::turnACW()
{
	if(wheels != 0)
	{
		for(uint8_t i = 0; i < numOfWheels; i++)
		{
			if(wheels[i] != 0)
			{
				wheels[i]->runCW();
			}
			else
			{
				error = ERROR_BAD_WHEEL;
				this->stop();
				return;
			}
		}
	}
	else
	{
		error = ERROR_BAD_INIT;
	}
}