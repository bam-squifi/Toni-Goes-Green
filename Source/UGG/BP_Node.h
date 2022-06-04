// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "BP_Node.generated.h"

UCLASS()
class UGG_API ABP_Node : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABP_Node();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Neighbours")
	ABP_Node* Left;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Neighbours")
	ABP_Node* Right;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Neighbours")
	ABP_Node* Up;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Neighbours")
	ABP_Node* Down;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="State")
	bool isBlocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="State")
	bool isStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool isEnd;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Connectors")
	UStaticMeshComponent* TopLine;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Connectors")
	UStaticMeshComponent* RightLine;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Node")
	UStaticMeshComponent* Node;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Node")
	UStaticMeshComponent* StartNode;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Node")
	UStaticMeshComponent* EndNode;

	// called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "State")
	bool IsBlockable();
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="State")
	UStaticMeshComponent* TopArrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TopArrow"));
	UPROPERTY(BlueprintReadWrite, Category="State")
	UStaticMeshComponent* RightArrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightArrow"));
	UPROPERTY(BlueprintReadWrite, Category="State")
	UStaticMeshComponent* BottomArrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BottomArrow"));
	UPROPERTY(BlueprintReadWrite, Category="State")
	UStaticMeshComponent* LeftArrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftArrow"));

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	void ToggleArrows() const;
};
