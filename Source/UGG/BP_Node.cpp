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
		// USceneComponent from: https://docs.unrealengine.com/5.0/en-US/API/Runtime/Engine/Components/USceneComponent/
		// A SceneComponent has a transform and supports attachment, but has no renderin or collision capabilities.
		// Useful as a 'dummy' component in the hierarchy to offset others.
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	}

	if (!Node) {
		Node = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NodeComponent"));
		Node->SetupAttachment(RootComponent);

		UStaticMeshComponent* NodeVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NodeVisual"));
		NodeVisual->SetupAttachment(Node);
		static ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneVisualAsset(TEXT("StaticMesh'/Game/MobileStarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
		static ConstructorHelpers::FObjectFinder<UMaterial> SphereVisualAssetMaterial(TEXT("Material'/Game/MobileStarterContent/Materials/M_Wood_Floor_Walnut_Polished.M_Wood_Floor_Walnut_Polished'"));
		
		if(PlaneVisualAsset.Succeeded() && SphereVisualAssetMaterial.Succeeded())
		{
			NodeVisual->SetStaticMesh(PlaneVisualAsset.Object);
			NodeVisual->SetRelativeLocation(FVector(0.0f));
			NodeVisual->SetMaterial(0,SphereVisualAssetMaterial.Object);	
			NodeVisual->SetWorldScale3D(FVector(.5f, .5f, 0.01f));
		}

		USphereComponent* CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("NodeCollision"));
		CollisionComponent->SetupAttachment(Node);
		CollisionComponent->InitSphereRadius(50.f);
		CollisionComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		CollisionComponent->SetGenerateOverlapEvents(true);
	}

	if (!StartNode) {
		StartNode = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StartNode"));
		StartNode->SetupAttachment(Node);

		if(isStart)
		{
			static ConstructorHelpers::FObjectFinder<UStaticMesh> StartNodeVisualAsset(TEXT("/Game/MobileStarterContent/Shapes/Shape_Plane.Shape_Plane"));
			static ConstructorHelpers::FClassFinder<UMaterial> StartNodeVisualMaterial(TEXT("Material'/Game/Materials/SM_Circle2.SM_Circle2'"));

			if(StartNodeVisualAsset.Succeeded() && StartNodeVisualMaterial.Succeeded())
			{
				UE_LOG(LogTemp, Display, TEXT("Loaded succesfully"));
			}
		}
	}

	if (!EndNode) {
		EndNode = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EndNode"));
		EndNode->SetupAttachment(RootComponent);
	}

	if (!BlockedNode) {
		BlockedNode = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockedNode"));
		BlockedNode->SetupAttachment(RootComponent);

		UStaticMeshComponent* BlockedVisualAssist = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Blocked Visual Assist"));
		BlockedVisualAssist->SetupAttachment(BlockedNode);
	}

	if(!RightLine)
	{
		RightLine = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightLineConnector"));
		RightLine->SetupAttachment(RootComponent);

		UStaticMeshComponent* RightLineVisualAssist = CreateDefaultSubobject<UStaticMeshComponent>("RightLineVisualAssist");
		RightLineVisualAssist->SetupAttachment(RightLine);
	}

	if(!TopLine)
	{
		TopLine = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TopLineConnector"));
		TopLine->SetupAttachment(RootComponent);

		UStaticMeshComponent* TopLineVisualAssist = CreateDefaultSubobject<UStaticMeshComponent>("TopLineVisualAssist");
		TopLineVisualAssist->SetupAttachment(TopLine);
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

