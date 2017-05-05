// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameEngine.h"
#include "CustomGameEngine.generated.h"

/**
*
*/
UCLASS()
class UCustomGameEngine : public UGameEngine
{
	GENERATED_BODY()

		bool InitializeHMDDevice() override;


};
