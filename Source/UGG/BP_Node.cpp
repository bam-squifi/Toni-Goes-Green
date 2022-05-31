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

		UStaticMeshComponent* TopArrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TopArrow"));
		UStaticMeshComponent* RightArrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightArrow"));
		UStaticMeshComponent* BottomArrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BottomArrow"));
		UStaticMeshComponent* LeftArrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftArrow"));

		static ConstructorHelpers::FObjectFinder<UStaticMesh> ArrowPlane(TEXT("/Game/MobileStarterContent/Shapes/Shape_Plane.Shape_Plane"));
		static ConstructorHelpers::FObjectFinder<UMaterial> ArrowMaterial(TEXT("Material'/Game/Materials/M_Arrow.M_Arrow'"));

		if(ArrowPlane.Succeeded() && ArrowMaterial.Succeeded())
		{
			TopArrow->SetupAttachment(Node);
			RightArrow->SetupAttachment(Node);
			BottomArrow->SetupAttachment(Node);
			LeftArrow->SetupAttachment(Node);

			TopArrow->SetStaticMesh(ArrowPlane.Object);
			RightArrow->SetStaticMesh(ArrowPlane.Object);
			BottomArrow->SetStaticMesh(ArrowPlane.Object);
			LeftArrow->SetStaticMesh(ArrowPlane.Object);

			TopArrow->SetMaterial(0, ArrowMaterial.Object);
			RightArrow->SetMaterial(0, ArrowMaterial.Object);
			BottomArrow->SetMaterial(0, ArrowMaterial.Object);
			LeftArrow->SetMaterial(0, ArrowMaterial.Object);

			TopArrow->SetWorldScale3D(FVector(.42f, .42f, 1.f));
			RightArrow->SetWorldScale3D(FVector(.42f, .42f, 1.f));
			BottomArrow->SetWorldScale3D(FVector(.42f, .42f, 1.f));
			LeftArrow->SetWorldScale3D(FVector(.42f, .42f, 1.f));

			TopArrow->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
			TopArrow->SetRelativeLocation(FVector(0.0f, -42.f, 0.0f));

			RightArrow->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
			RightArrow->SetRelativeLocation(FVector(42.0f, 0.f, 0.0f));

			BottomArrow->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
			BottomArrow->SetRelativeLocation(FVector(0.0f, 42.f, 0.0f));

			LeftArrow->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
			LeftArrow->SetRelativeLocation(FVector(-42.0f, 0.f, 0.0f));
		}
		
	}

	if (!StartNode) {
		StartNode = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StartNode"));
		StartNode->SetupAttachment(Node);

		if(isStart)
		{
			static ConstructorHelpers::FObjectFinder<UStaticMesh> StartNodeVisualAsset(TEXT("/Game/MobileStarterContent/Shapes/Shape_Plane.Shape_Plane"));

			if(StartNodeVisualAsset.Succeeded())
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
