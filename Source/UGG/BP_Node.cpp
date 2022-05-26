// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Node.h"
#include "Components/SceneComponent.h"

// Sets default values
ABP_Node::ABP_Node()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	for (FName tag : Tags)
	{
		FString blockable = TEXT("blockable");
		if (tag.ToString() == blockable) {
			UE_LOG(LogTemp, Warning, TEXT("found blockable Tag"));
		}
	}

	if (!RootComponent) {
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	}

	if (!Node) {
		Node = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NodeComponent"));
		Node->SetupAttachment(RootComponent);
		Node->bUseDefaultCollision = false;
	}

	if (!StartNode) {
		StartNode = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StartNode"));
		StartNode->SetupAttachment(RootComponent);
	}

	if (!EndNode) {
		EndNode = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EndNode"));
		EndNode->SetupAttachment(RootComponent);
	}

	if (!BlockedNode) {
		BlockedNode = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockedNode"));
		BlockedNode->SetupAttachment(RootComponent);
	}

}

bool ABP_Node::IsBlockable()
{
	return false;
}

// Called when the game starts or when spawned
void ABP_Node::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_Node::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

