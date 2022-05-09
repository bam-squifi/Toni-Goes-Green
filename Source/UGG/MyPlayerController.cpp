// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
	// Set this to call Tick() every Frame
	PrimaryActorTick.bCanEverTick = true;
	

	FVector2D TempLocation;
	bool bIsPressed;

	this->bEnableTouchEvents = true;
	this->GetInputTouchState(ETouchIndex::Touch1, TempLocation.X, TempLocation.Y, bIsPressed);

	EndTouchLocation = TempLocation;
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

