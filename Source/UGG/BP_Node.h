// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connectors")
	UStaticMeshComponent* TopLine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connectors")
	UStaticMeshComponent* RightLine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Node")
	UStaticMeshComponent* Node;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Node")
	UStaticMeshComponent* StartNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Node")
	UStaticMeshComponent* EndNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Node")
	UStaticMeshComponent* BlockedNode;


	UFUNCTION(BlueprintCallable, Category = "State")
	bool IsBlockable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
