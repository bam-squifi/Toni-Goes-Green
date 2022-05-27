// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Node.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"

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

		UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
		SphereVisual->SetupAttachment(Node);
		static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/MobileStarterContent/Shapes/Shape_Plane.Shape_Plane"));
		static ConstructorHelpers::FObjectFinder<UMaterial> SphereVisualAssetMaterial(TEXT("Material'/Game/Materials/SM_Circle2.SM_Circle2'"));
		
		if(SphereVisualAsset.Succeeded() && SphereVisualAssetMaterial.Succeeded())
		{
			SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
			SphereVisual->SetRelativeLocation(FVector(0.0f,0.0f, 20.0f));
			SphereVisual->SetMaterial(0,SphereVisualAssetMaterial.Object);	
			SphereVisual->SetWorldScale3D(FVector(.8f));
			SphereVisual->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}

	if (!StartNode) {
		StartNode = CreateDefaultSubobject<USphereComponent>(TEXT("StartNode"));
		StartNode->SetupAttachment(RootComponent);
	}

	if (!EndNode) {
		EndNode = CreateDefaultSubobject<USphereComponent>(TEXT("EndNode"));
		EndNode->SetupAttachment(RootComponent);
	}

	if (!BlockedNode) {
		BlockedNode = CreateDefaultSubobject<USphereComponent>(TEXT("BlockedNode"));
		BlockedNode->SetupAttachment(RootComponent);
	}

	if(!RightLine)
	{
		RightLine = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightLineConnector"));
		RightLine->SetupAttachment(RootComponent);
	}

	if(!TopLine)
	{
		TopLine = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TopLineConnector"));
		TopLine->SetupAttachment(RootComponent);
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

